/*
 * JOOS is Copyright (C) 1997 Laurie Hendren & Michael I. Schwartzbach
 *
 * Reproduction of all or part of this software is permitted for
 * educational or research use on condition that this copyright notice is
 * included in any copy. This software comes with no warranty of any
 * kind. In no event will the authors be liable for any damages resulting from
 * use of this software.
 *
 * email: hendren@cs.mcgill.ca, mis@brics.dk
 */

/* aload/iload
 * pop
 * ------>
 */
int load_pop(CODE **c)
{
  int k;
  if ((is_aload(*c, &k) || is_iload(*c, &k)) && is_pop(next(*c)))
  {
    return replace(c, 2, NULL);
  }
  return 0;
}

/* ldc 0          ldc 1          ldc 2
 * imul           imul           imul
 * ------>        ------>        ------>
 * pop                           dup
 * ldc 0                         iadd
 */

int simplify_multiplication_right(CODE **c)
{ int k;
  if (is_ldc_int(*c,&k) && 
      is_imul(next(*c))) {
     if (k==0) return replace(c,2,makeCODEpop(makeCODEldc_int(0,NULL)));
     else if (k==1) return replace(c,2,NULL);
     else if (k==2) return replace(c,2,makeCODEdup(
                                       makeCODEiadd(NULL)));
     return 0;
  }
  return 0;
}

/* ldc 0          ldc 1          ldc 2
 * iload x        iload x        iload x
 * imul           imul           imul
 * ------>        ------>        ------>
 * ldc 0          iload x        iload x
 *                               dup
 *                               iadd
 */

int simplify_multiplication_left(CODE **c)
{
  int x,k;
  if (is_ldc_int(*c, &k) &&
      is_iload(next(*c),&x) && 
      is_imul(next(next(*c)))) {
     if (k==0) return replace(c,3,makeCODEldc_int(0,NULL));
     else if (k==1) return replace(c,3,makeCODEiload(x,NULL));
     else if (k==2) return replace(c,3,makeCODEiload(x,
                                       makeCODEdup(
                                       makeCODEiadd(NULL))));
     return 0;
  }
  return 0;
}

/* iload x
 * ldc 1
 * idiv 
 * ------>
 * iload x
 */
int simplify_division_right(CODE **c)
{
  int x,k;
  if (is_iload(*c,&x) && 
      is_ldc_int(next(*c),&k) && 
      is_idiv(next(next(*c)))) {
     if (k==1) return replace(c,3,makeCODEiload(x,NULL));
     return 0;
  }
  return 0;
}

/* ldc 0
 * iload x
 * idiv 
 * ------>
 * iload x
 */
int simplify_division_left(CODE **c)
{
  int x,k;
  if (is_iload(*c,&x) && 
      is_ldc_int(next(*c),&k) && 
      is_idiv(next(next(*c)))) {
     if (k==0) return replace(c,3,makeCODEldc_int(0,NULL));
     return 0;
  }
  return 0;
}

/*
 * ldc x
 * ldc y
 * iadd / imul / idiv / isub / irem
 * ---------->
 * ldc (x + - * / % y )
 */
int simplify_ints(CODE **c)
{
  int x, y;
  CODE *nextnext = next(next(*c));
  if (is_ldc_int(*c,&x) &&
      is_ldc_int(next(*c),&y)) 
    {
      if(is_idiv(nextnext))
      {
        return replace(c,3,makeCODEldc_int(x/y, NULL));
      }
      else if(is_imul(nextnext))
      {
        return replace(c,3,makeCODEldc_int(x*y, NULL));
      }
      else if(is_iadd(nextnext))
      {
        return replace(c,3,makeCODEldc_int(x+y, NULL));
      }
      else if(is_isub(nextnext))
      {
        return replace(c,3,makeCODEldc_int(x-y, NULL));
      }
      else if(is_irem(nextnext))
      {
        return replace(c,3,makeCODEldc_int(x%y, NULL));
      }
    }
    return 0;
}


/* dup
 * astore x
 * pop
 * -------->
 * astore x
 */
int simplify_astore(CODE **c)
{ int x;
  if (is_dup(*c) &&
      is_astore(next(*c),&x) &&
      is_pop(next(next(*c)))) {
     return replace(c,3,makeCODEastore(x,NULL));
  }
  return 0;
}

/* dup
 * istore x
 * pop
 * -------->
 * istore x
 */
int simplify_istore(CODE **c)
{ int x;
  if (is_dup(*c) &&
      is_istore(next(*c),&x) &&
      is_pop(next(next(*c)))) {
     return replace(c,3,makeCODEistore(x,NULL));
  }
  return 0;
}

/* iload x
 * ldc k   (0<=k<=127)
 * iadd
 * istore x
 * --------->
 * iinc x k
 */ 
int positive_increment_right(CODE **c)
{ int x,y,k;
  if (is_iload(*c,&x) &&
      is_ldc_int(next(*c),&k) &&
      is_iadd(next(next(*c))) &&
      is_istore(next(next(next(*c))),&y) &&
      x==y && -128<=k && k<=127) {
     return replace(c,4,makeCODEiinc(x,k,NULL));
  }
  return 0;
}

/* ldc k   (-128<=k<=127)
 * iload x
 * iadd
 * istore x
 * --------->
 * iinc x k
 */ 
int positive_increment_left(CODE **c)
{ int x,y,k;
  if (is_iload(next(*c),&x) &&
      is_ldc_int(*c,&k) &&
      is_iadd(next(next(*c))) &&
      is_istore(next(next(next(*c))),&y) &&
      x==y && -128<=k && k<=127) {
     return replace(c,4,makeCODEiinc(x,k,NULL));
  }
  return 0;
}


/* iload x
 * ldc k   (-128<=k<=127)
 * isub
 * istore x
 * --------->
 * iinc x k
 */ 
int negative_increment_right(CODE **c)
{ int x,y,k;
  if (is_iload(*c,&x) &&
      is_ldc_int(next(*c),&k) &&
      is_isub(next(next(*c))) &&
      is_istore(next(next(next(*c))),&y) &&
      x==y && -127<=k && k<=128) {
     return replace(c,4,makeCODEiinc(x,-k,NULL));
  }
  return 0;
}

/* iinc x 0
 * -------->
 */
int addition_by_zero(CODE **c)
{
  int x, k;
  if (is_iinc(*c, &x, &k) && !k)
      return replace(c,1,NULL);
  return 0;
}

/* goto L1
 * ...
 * L1:
 * goto L2
 * ...
 * L2:
 * --------->
 * goto L2
 * ...
 * L1:    (reference count reduced by 1)
 * goto L2
 * ...
 * L2:    (reference count increased by 1)  
 */
int simplify_goto_goto(CODE **c)
{ int l1,l2;
  if (is_goto(*c,&l1) && is_goto(next(destination(l1)),&l2) && l1>l2) {
     return replace_modified(c,1,makeCODEgoto(l2,NULL));
  }
  return 0;
}

/*
 * iload/aload/ldc_int/ldc_string x
 * iload/aload/ldc_int/ldc_string y 
 * swap
 * ...
 * ------------------->
 * iload/aload/ldc_int/ldc_string y
 * iload/aload/ldc_int/ldc_string x 
 * ...
 */
int load_swap(CODE **c)
{
  int x, y;
  char *w, *z;
  if(is_swap(next(next(*c))))
  {
    if(is_iload(*c, &x) && is_iload(next(*c), &y))
      return replace(c, 3, makeCODEiload(y, makeCODEiload(x, NULL)));
    if(is_aload(*c, &x) && is_iload(next(*c), &y))
      return replace(c, 3, makeCODEiload(y, makeCODEaload(x, NULL)));
    if(is_iload(*c, &x) && is_aload(next(*c), &y))
      return replace(c, 3, makeCODEaload(y, makeCODEiload(x, NULL)));
    if(is_aload(*c, &x) && is_aload(next(*c), &y))
      return replace(c, 3, makeCODEaload(y, makeCODEaload(x, NULL)));
    if(is_ldc_int(*c, &x) && is_iload(next(*c), &y))
      return replace(c, 3, makeCODEiload(y, makeCODEldc_int(x, NULL)));
    if(is_iload(*c, &x) && is_ldc_int(next(*c), &y))
      return replace(c, 3, makeCODEldc_int(y, makeCODEiload(x, NULL)));
    if(is_ldc_int(*c, &x) && is_aload(next(*c), &y))
      return replace(c, 3, makeCODEaload(y, makeCODEldc_int(x, NULL)));
    if(is_aload(*c, &x) && is_ldc_int(next(*c), &y))
      return replace(c, 3, makeCODEldc_int(y, makeCODEaload(x, NULL)));
    if(is_ldc_int(*c, &x) && is_ldc_int(next(*c), &y))
      return replace(c, 3, makeCODEldc_int(y, makeCODEldc_int(x, NULL)));
    if(is_ldc_string(*c, &w) && is_iload(next(*c), &y))
      return replace(c, 3, makeCODEiload(y, makeCODEldc_string(w, NULL)));
    if(is_iload(*c, &x) && is_ldc_string(next(*c), &w))
      return replace(c, 3, makeCODEldc_string(w, makeCODEiload(x, NULL)));
    if(is_ldc_string(*c, &w) && is_aload(next(*c), &y))
      return replace(c, 3, makeCODEaload(y, makeCODEldc_string(w, NULL)));
    if(is_aload(*c, &x) && is_ldc_string(next(*c), &w))
      return replace(c, 3, makeCODEldc_string(w, makeCODEaload(x, NULL)));
    if(is_ldc_string(*c, &w) && is_ldc_string(next(*c), &z))
      return replace(c, 3, makeCODEldc_string(z, makeCODEldc_string(w, NULL)));
    if(is_ldc_string(*c, &w) && is_ldc_int(next(*c), &y))
      return replace(c, 3, makeCODEldc_int(y, makeCODEldc_string(w, NULL)));
    if(is_ldc_int(*c, &x) && is_ldc_string(next(*c), &w))
      return replace(c, 3, makeCODEldc_string(w, makeCODEldc_int(x, NULL)));  
  }
  return 0;
}

/* aload/iload x
 * astore/istore x
 * ...
 * -------------->
 * ...
 * we can just get rid of this nonsense
 */
int remove_load_store(CODE **c)
{
  int x, y;
  if(is_iload(*c, &x) || is_aload(*c, &x)) 
    if(is_istore(next(*c), &y) || is_astore(next(*c), &y))
      if(x == y)
        return replace(c, 2, NULL);
  return 0; 
}


/* 
TODO: REMOVE LOAD STORE NOT WORKING
*/


/* iload_x
 * dup
 * aload_y
 * swap
 * putfield
 * pop
 * ....
 * --------------->
 * aload_y
 * iload_x
 * putfield
 * .......
*/
int simplify_iload_aload(CODE **c)
{
  int x, y;
  char *temp;
  CODE *nexted = next(*c);
  if(is_iload(*c, &x))
  {
    if(is_dup(nexted))
    {
      nexted = next(nexted);
      if(is_aload(nexted, &y))
      {
        nexted = next(nexted);
        if(is_swap(nexted))
        {
          nexted = next(nexted);
          if(is_putfield(nexted, &temp))
          { 
            nexted = next(nexted);
            if(is_pop(nexted))
            {
              return replace(c, 6, makeCODEaload(y, makeCODEiload(x, makeCODEputfield(temp, NULL))));
              /*return replace(c, 6, makeCODEpop(makeCODEiload(x, makeCODEaload(y, NULL))));*/
            }
          }
        }
      }
    }
  }
  return 0;
}


/* if_icmplt l1
 * iconst_0
 * goto l2
 * l1 :
 * iconst_1
 * l2 :
 * ifeq l3
 * ------>
 * if_cmpge l3
 */
int simplify_icmplt(CODE **c)
{ 
  int l1, l2, l3;
  CODE *nexter = next(*c);
  if(is_if_icmplt(*c, &l1))
  {
    if(is_goto(next(nexter), &l2))
    {
      if(is_ifeq(next(destination(l2)), &l3))
        return replace_modified(c, 7, makeCODEif_icmpge(l3, NULL));
    }
  }
  return 0;
}

/* if_icmple l1
 * iconst_0
 * goto l2
 * l1 :
 * iconst_1
 * l2 :
 * ifeq l3
 * ------>
 * if_icmpgt l3
 */
int simplify_icmple(CODE **c)
{ 
  int l1, l2, l3;
  CODE *nexter = next(*c);
  if(is_if_icmple(*c, &l1))
  {
    if(is_goto(next(nexter), &l2))
    {
      if(is_ifeq(next(destination(l2)), &l3))
        return replace_modified(c, 7, makeCODEif_icmpgt(l3, NULL));
    }
  }
  return 0;
}

/* if_icmpgt l1
 * iconst_0
 * goto l2
 * l1 :
 * iconst_1
 * l2 :
 * ifeq l3
 * ------>
 * if_icmple l3
 */
int simplify_icmpgt(CODE **c)
{ 
  int l1, l2, l3;
  CODE *nexter = next(*c);
  if(is_if_icmpgt(*c, &l1))
  {
    if(is_goto(next(nexter), &l2))
    {
      if(is_ifeq(next(destination(l2)), &l3))
        return replace_modified(c, 7, makeCODEif_icmple(l3, NULL));
    }
  }
  return 0;
}

/* if_icmpge l1
 * iconst_0
 * goto l2
 * l1 :
 * iconst_1
 * l2 :
 * ifeq l3
 * ------>
 * if_icmplt l3
 */
int simplify_icmpge(CODE **c)
{ 
  int l1, l2, l3;
  CODE *nexter = next(*c);
  if(is_if_icmpge(*c, &l1))
  {
    if(is_goto(next(nexter), &l2))
    {
      if(is_ifeq(next(destination(l2)), &l3))
        return replace_modified(c, 7, makeCODEif_icmplt(l3, NULL));
    }
  }
  return 0;
}

/* if_icmpne true_2
 * iconst_0
 * goto stop_3
 * true_2:
 * iconst_1
 * stop_3:
 * ifeq stop_1
 * ...
 * ------------>
 * if_acmpeq stop_1
 * ....
 */
int simplify_icmpne(CODE **c)
{ 
  int l1, l2, l3;
  if(is_if_icmpne(*c, &l1))
  {
    if(is_goto(nextby(*c, 2), &l2))
    {
      if(is_ifeq(next(destination(l2)), &l3))
        return replace_modified(c, 7, makeCODEif_icmpeq(l3, NULL));
    }
  }
  return 0;
}

/* if_icmpeq true_2
 * iconst_0
 * goto stop_3
 * true_2:
 * iconst_1
 * stop_3:
 * ifeq stop_1
 * ...
 * ------------>
 * if_acmpeq stop_1
 * ....
 */
int simplify_icmpeq(CODE **c)
{ 
  int l1, l2, l3;
  if(is_if_icmpeq(*c, &l1))
  {
    if(is_goto(nextby(*c, 2), &l2))
    {
      if(is_ifeq(next(destination(l2)), &l3))
        return replace_modified(c, 7, makeCODEif_icmpne(l3, NULL));
    }
  }
  return 0;
}



/* if_acmpne true_2
 * iconst_0
 * goto stop_3
 * true_2:
 * iconst_1
 * stop_3:
 * ifeq stop_1
 * ...
 * ------------>
 * if_acmpeq stop_1
 * ....
 */
int simplify_acmpne(CODE **c)
{ 
  int l1, l2, l3;
  if(is_if_acmpne(*c, &l1))
  {
    if(is_goto(nextby(*c, 2), &l2))
    {
      if(is_ifeq(next(destination(l2)), &l3))
        return replace_modified(c, 7, makeCODEif_acmpeq(l3, NULL));
    }
  }
  return 0;
}

/* if_acmpeq true_2
 * iconst_0
 * goto stop_3
 * true_2:
 * iconst_1
 * stop_3:
 * ifeq stop_1
 * ...
 * ------------>
 * if_acmpne stop_1
 * ....
 */
int simplify_acmpeq(CODE **c)
{ 
  int l1, l2, l3;
  if(is_if_acmpeq(*c, &l1))
  {
    if(is_goto(nextby(*c, 2), &l2))
    {
      if(is_ifeq(next(destination(l2)), &l3))
        return replace_modified(c, 7, makeCODEif_acmpne(l3, NULL));
    }
  }
  return 0;
}

/* ifnull l1
 * goto l2
 * l1:
 * ...
 * ------------>
 * ifnonnull l2
 * ....
 */
int simplify_ifnull(CODE **c)
{ 
  int l1, l2, l3;
  if(is_ifnull(*c, &l1))
  {
    if(is_goto(next(*c), &l2))
    {
      if(is_label(nextby(*c, 2), &l3) && (l1 == l3))
        return replace_modified(c, 3, makeCODEifnonnull(l2, NULL));
    }
  }
  return 0;
}

/* ifnonnull true_2
 * iconst_0
 * goto stop_3
 * true_2:
 * iconst_1
 * stop_3:
 * ifeq stop_1
 * ...
 * ------------>
 * ifnull stop_1
 * ....
 */
int simplify_ifnonnull(CODE **c)
{ 
  int l1, l2, l3;
  if(is_ifnonnull(*c, &l1))
  {
    if(is_goto(next(*c), &l2))
    {
      if(is_label(nextby(*c, 2), &l3) && (l1 == l3))
        return replace_modified(c, 3, makeCODEifnull(l2, NULL));
    }
  }
  return 0;
}


/*
 * areturn
 * ... (not a label)
 * -------------->
 * areturn
 *
*/ 
int remove_after_return(CODE **c)
{
  int x, k;
  if(is_ireturn(*c))
  {
    if(next(*c) != NULL && !is_label(next(*c), &x))
      return replace(c, 2, makeCODEireturn(NULL));
  }
  else if(is_areturn(*c))
  {
    if(next(*c) != NULL && !is_label(next(*c), &x))
      return replace(c, 2, makeCODEareturn(NULL));
  }
  else if(is_return(*c))
  {
    if(next(*c) != NULL && !is_label(next(*c), &x))
      return replace(c, 2, makeCODEreturn(NULL));
  }
  else if(is_goto(*c, &k))
  {
    if(next(*c) != NULL && !is_label(next(*c), &x))
      return replace(c, 2, makeCODEgoto(k, NULL));
  }
  return 0;
}

/* Too long to write out, but lots of  
 * crazy conditionals for adding strings
 *
 * Now made much simpler
 */

int simplify_string_addition(CODE **c)
{
  int temp;
  char *temp1;
  if(is_ldc_string(*c, &temp1))
  {
    if(is_dup(next(*c)))
    {
      if(is_ifnull(nextby(*c, 2), &temp))
      {  
        return replace(c, 8, makeCODEldc_string(temp1, NULL));
      }
    }
  }
  return 0;
}

/* dup      iload x
 * isub     iload x
 *          isub 
 * ----->   ------->
 * pop      ldc 0
 * ldc 0
 */
int self_subtraction(CODE **c)
{
  int x, y;
  if (is_dup(*c) && is_isub(next(*c)))
  {
    return replace(c, 2, makeCODEpop(makeCODEldc_int(0, NULL)));
  }
  else if (is_iload(*c, &x) && is_iload(next(*c), &y) && (x == y))
  {
    if(is_isub(nextby(*c, 2)))
      return replace(c, 3, makeCODEldc_int(0, NULL));
  }
  return 0;
}

/* iload_x
 * iconst_1
 * iadd
 * dup
 * istore_x
 * iconst_1
 * isub
 * pop
 * ....
 * ------------->
 * iinc x 1
 * ....
 */
int simplify_increment(CODE **c)
{
  int x, y, k;
  if(is_iload(*c, &x))
  {
    if(is_ldc_int(next(*c), &k) && (k == 1))
    {
      if(is_iadd(next(next(*c))))
      {
        if(is_dup(nextby(*c, 3)))
        {
          if(is_istore(nextby(*c, 4), &y) && (x == y))
          {
            if(is_ldc_int(nextby(*c, 5), &k) && (k == 1))
            {
              if(is_isub(nextby(*c, 6)))
              {
                if(is_pop(nextby(*c, 7)))
                  return replace(c, 8, makeCODEiinc(x, 1, NULL));
              }
            }
          }
        }
      }
    }
  }
  return 0;
}


/* iload_x
 * iconst_1
 * iadd
 * dup
 * istore_x
 * iconst_1
 * isub
 * pop
 * ....
 * ------------->
 * iinc x 1
 * ....
 */
int simplify_decrement(CODE **c)
{
  int x, y, k;
  if(is_iload(*c, &x))
  {
    if(is_ldc_int(next(*c), &k) && (k == 1))
    {
      if(is_isub(next(next(*c))))
      {
        if(is_dup(nextby(*c, 3)))
        {
          if(is_istore(nextby(*c, 4), &y) && (x == y))
          {
            if(is_ldc_int(nextby(*c, 5), &k) && (k == 1))
            {
              if(is_iadd(nextby(*c, 6)))
              {
                if(is_pop(nextby(*c, 7)))
                  return replace(c, 8, makeCODEiinc(x, -1, NULL));
              }
            }
          }
        }
      }
    }
  }
  return 0;
}

/*
*  aload_x
*  dup
*  aload_y
*  swap
*  putfield stuff
*  pop
* ....
*  -------->
*  aload_y
*  aload_x
*  putfield stuff
*/
int simplify_aload_swap(CODE **c)
{
  int x, y;
  char *z;
  if(is_aload(*c, &x))
  {
    if(is_dup(next(*c)))
    {
      if(is_aload(nextby(*c, 2), &y))
      {
        if(is_swap(nextby(*c, 3)))
        {
          if(is_putfield(nextby(*c, 4), &z))
          {
            if(is_pop(nextby(*c, 5)))
              return replace(c, 6, makeCODEaload(y, makeCODEaload(x, makeCODEputfield(z, NULL))));
          }
        }
      }
    }
  } 
  return 0;
}


/*
*  iconst_x
*  dup
*  aload_y
*  swap
*  putfield stuff
*  pop
*  ....
*  -------->
*  aload_y
*  iconst_x
*  putfield stuff
*/
int simplify_iconst_swap(CODE **c)
{
  int x, y;
  char *z;
  if(is_ldc_int(*c, &x))
  {
    if(is_dup(next(*c)))
    {
      if(is_aload(nextby(*c, 2), &y))
      {
        if(is_swap(nextby(*c, 3)))
        {
          if(is_putfield(nextby(*c, 4), &z))
          {
            if(is_pop(nextby(*c, 5)))
              return replace(c, 6, makeCODEaload(y, makeCODEldc_int(x, makeCODEputfield(z, NULL))));
          }
        }
      }
    }
  } 
  return 0;
}


/*
*  aconst_x
*  dup
*  aload_y
*  swap
*  putfield stuff
*  pop
*  ....
*  -------->
*  aload_y
*  iconst_x
*  putfield stuff
*/
int simplify_aconst_swap(CODE **c)
{
  int y;
  char *x, *z;
  if(is_ldc_string(*c, &x))
  {
    if(is_dup(next(*c)))
    {
      if(is_aload(nextby(*c, 2), &y))
      {
        if(is_swap(nextby(*c, 3)))
        {
          if(is_putfield(nextby(*c, 4), &z))
          {
            if(is_pop(nextby(*c, 5)))
              return replace(c, 6, makeCODEaload(y, makeCODEldc_string(x, makeCODEputfield(z, NULL))));
          }
        }
      }
    }
  } 
  return 0;
}

/*
*  aconst_null
*  dup
*  aload_y
*  swap
*  putfield stuff
*  pop
*  ....
*  -------->
*  aload_y
*  iconst_x
*  putfield stuff
*/
int simplify_aconst_null_swap(CODE **c)
{
  int y;
  char *z;
  if(is_aconst_null(*c))
  {
    if(is_dup(next(*c)))
    {
      if(is_aload(nextby(*c, 2), &y))
      {
        if(is_swap(nextby(*c, 3)))
        {
          if(is_putfield(nextby(*c, 4), &z))
          {
            if(is_pop(nextby(*c, 5)))
              return replace(c, 6, makeCODEaload(y, makeCODEaconst_null(makeCODEputfield(z, NULL))));
          }
        }
      }
    }
  } 
  return 0;
}

/*
* dup
* aload_x
* swap
* putfield
* pop
* ...
* ------->
* aload_x
* swap
* putfield 
* ....
*/
int simplify_dup_swap_put(CODE **c)
{
  int x;
  char *y;
  if(is_dup(*c))
  {
    if(is_aload(next(*c), &x))
    {
      if(is_swap(nextby(*c, 2)))
      {
        if(is_putfield(nextby(*c, 3), &y))
        {
          if(is_pop(nextby(*c, 4)))
            return replace(c, 5, makeCODEaload(x, makeCODEswap(makeCODEputfield(y, NULL))));
        }
      }
    }
  }
  return 0;
}




/******  Old style - still works, but better to use new style. 
#define OPTS 4

OPTI optimization[OPTS] = {simplify_multiplication_right,
                           simplify_astore,
                           positive_increment,
                           simplify_goto_goto};
********/

/* new style for giving patterns */

int init_patterns()
  { ADD_PATTERN(simplify_multiplication_right);
    ADD_PATTERN(simplify_astore);
    ADD_PATTERN(positive_increment_right);
    ADD_PATTERN(simplify_goto_goto);
    /* we added these */
    ADD_PATTERN(addition_by_zero);
    ADD_PATTERN(simplify_multiplication_left);
    ADD_PATTERN(simplify_ints);
    ADD_PATTERN(simplify_division_left);
    ADD_PATTERN(simplify_division_right);
    ADD_PATTERN(simplify_istore);
    /* works up to here... */
    ADD_PATTERN(positive_increment_left);
    ADD_PATTERN(negative_increment_right);
    ADD_PATTERN(load_swap);
    /* works up to here...*/
    ADD_PATTERN(load_pop);
    /* works up to here...*/
    ADD_PATTERN(simplify_iload_aload);
    ADD_PATTERN(remove_load_store);

    ADD_PATTERN(simplify_icmpne);
    ADD_PATTERN(simplify_icmpgt);
    ADD_PATTERN(simplify_icmpge);
    ADD_PATTERN(simplify_icmplt);    
    ADD_PATTERN(simplify_acmpeq);
    ADD_PATTERN(simplify_acmpne);
    ADD_PATTERN(simplify_icmple);
    ADD_PATTERN(simplify_icmpeq);
    ADD_PATTERN(simplify_ifnonnull);
    ADD_PATTERN(simplify_ifnull);

    ADD_PATTERN(remove_after_return);
    /* works up to here... */
    ADD_PATTERN(simplify_string_addition);
    /* works up to here... */
    ADD_PATTERN(simplify_increment);
    ADD_PATTERN(simplify_decrement);
    ADD_PATTERN(simplify_aload_swap);
    ADD_PATTERN(simplify_iconst_swap);
    ADD_PATTERN(simplify_aconst_swap);
    ADD_PATTERN(simplify_aconst_null_swap);
    ADD_PATTERN(self_subtraction);

    ADD_PATTERN(simplify_dup_swap_put);


    return 1;
  }
