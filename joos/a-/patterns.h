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
     droplabel(l1);
     copylabel(l2);
     return replace(c,1,makeCODEgoto(l2,NULL));
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
  if(((is_iload(*c, &x) || is_aload(*c, &x)) && (is_istore(next(*c), &y) || is_iload(next(*c), &y))) && (x == y))
    return replace(c, 2, next(next(*c)));
  return 0; 
}


/* 

TODO: LT GT NOT WORKING 

*/
/* 

TODO: LT GT NOT WORKING 

*/
/* 

TODO: LT GT NOT WORKING 

*/
/* 

TODO: LT GT NOT WORKING 

*/
/* 

TODO: LT GT NOT WORKING 

*/

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
int simplify_lt(CODE **c)
{ 
  int l1, l2, l3;
  if (is_if_icmplt(*c,&l1) && 
      is_goto(next(next(*c)),&l2) && 
      is_ifeq(next(destination(l2)),&l3) &&
      l1 > l2 ) {
    droplabel(l1);
    copylabel(l3);
    return replace(c,1,makeCODEif_icmpge(l3,NULL));
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
 * if_cmple l3
 */
int simplify_gt(CODE **c)
{ 
  int l1, l2, l3;
  if (is_if_icmpgt(*c,&l1) && 
      is_goto(next(next(*c)),&l2) && 
      is_ifeq(next(destination(l2)),&l3) &&
      l1 > l2 ) {
    droplabel(l1);
    copylabel(l3);
    return replace(c,1,makeCODEif_icmple(l3,NULL));
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
    ADD_PATTERN(positive_increment_left);
    ADD_PATTERN(negative_increment_right);
    ADD_PATTERN(load_swap);
    ADD_PATTERN(load_pop);
    ADD_PATTERN(remove_load_store);
    ADD_PATTERN(simplify_gt);
    ADD_PATTERN(simplify_lt);
    return 1;
  }
