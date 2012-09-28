#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "eval.h"

EXP* evalEXP(EXP *e)
{
    EXP* toR = malloc(sizeof(EXP));

    switch (e->kind) {
    case idK:
        return e;
    case intconstK:
        return e;
    case timesK:
    {
        EXP* left = evalEXP(e->val.timesE.left);
        EXP* right = evalEXP(e->val.timesE.right);
        if(left->kind == intconstK && right->kind == intconstK)
        {
            toR->kind = intconstK;
            toR->val.intconstE = left->val.intconstE * right->val.intconstE;
        }
        else if((left->kind == intconstK && !left->val.intconstE) ||
            (right->kind == intconstK && !right->val.intconstE))
        {    /* one is 0; I know the answer to this! */
            toR->kind = intconstK;
            toR->val.intconstE = 0;
        }
        else
        {
            e->val.timesE.left = left;
            e->val.timesE.right = right;
            return e;
        }
        return toR;
    }
    case divK:
    {
        EXP* left = evalEXP(e->val.divE.left);
        EXP* right = evalEXP(e->val.divE.right);
        if(right->kind == intconstK && !right->val.intconstE)
        {
            printf("Error - division by 0\n");
            exit(0);
        }
        if(left->kind == intconstK && right->kind == intconstK)
        {
            toR->kind = intconstK;
            toR->val.intconstE = left->val.intconstE / right->val.intconstE;
            return toR;
        }
        else if(right->kind == intconstK && right->val.intconstE == 1)
            return left;  /* x/1 == x */
        e->val.divE.left = left;
        e->val.divE.right = right;
        return e;
    }
    case plusK:
    {
        EXP* left = evalEXP(e->val.plusE.left);
        EXP* right = evalEXP(e->val.plusE.right);
        if(left->kind == intconstK && !left->val.intconstE)
            return right; /* 0 + x = x */
        else if(right->kind == intconstK && !right->val.intconstE)
            return left;  /* x + 0 = x */
        else if(left->kind == intconstK && right->kind == intconstK)
        {
            toR->kind = intconstK;
            toR->val.intconstE = left->val.intconstE + right->val.intconstE;
            return toR;
        }
        e->val.plusE.left = left;
        e->val.plusE.right = right;
        return e;
    }
    case minusK:
    {
        EXP* left = evalEXP(e->val.minusE.left);
        EXP* right = evalEXP(e->val.minusE.right);
        if(right->kind == intconstK && !right->val.intconstE)
            return left;  /* x - 0 = x */
        else if(left->kind == intconstK && right->kind == intconstK)
        {
            toR->kind = intconstK;
            toR->val.intconstE = left->val.intconstE - right->val.intconstE;
            return toR;
        }
        e->val.minusE.left = left;
        e->val.minusE.right = right;
        return e;
    }
    case moduloK:
    {
        EXP* left = evalEXP(e->val.moduloE.left);
        EXP* right = evalEXP(e->val.moduloE.right);
        if(right->kind == intconstK && !right->val.intconstE)   
        {
            printf("Error - modulo by 0\n");
            exit(0);
        }
        else if(right->kind == intconstK && right->val.intconstE == 1)
        {   /* x % 1 == 0 */
            toR->kind = intconstK;
            toR->val.intconstE = 0;
        }
        else if(left->kind == intconstK && right->kind == intconstK)
        {
            toR->kind = intconstK;
            toR->val.intconstE = left->val.intconstE % right->val.intconstE;
        }
        else
        {
            e->val.minusE.left = left;
            e->val.minusE.right = right;
            return e;
        }
        return toR;
    }
    case absK:
    {
        EXP* only = evalEXP(e->val.absE.left);
        if(only->kind == intconstK)
        {
            toR->kind = intconstK;
            toR->val.intconstE = abs(only->val.intconstE);
            return toR;
        }
        e->val.absE.left = only;
        return e;
    }
    case exponentK:
    {   /* Can't check 0 ** x because 0 ** 0 == 1 */
        EXP* left = evalEXP(e->val.exponentE.left);
        EXP* right = evalEXP(e->val.exponentE.right);
        if(right->kind == intconstK && !right->val.intconstE)
        {   /* x ** 0 == 1 */
            toR->kind = intconstK;
            toR->val.intconstE = 1;
        }
        else if(right->kind == intconstK && right->val.intconstE == 1)
            return left;  /* x ** 1 == x */
        else if(left->kind == intconstK && left->val.intconstE == 1)
        {   /* 1 ** x == 1 */
            toR->kind = intconstK;
            toR->val.intconstE = 1;
        }
        else if(left->kind == intconstK && right->kind == intconstK)
        {
            toR->kind = intconstK;
            toR->val.intconstE = pow(left->val.intconstE, right->val.intconstE);
        }
        else
        {
            e->val.exponentE.left = left;
            e->val.exponentE.right = right;
            return e;
        }
        return toR;
    }
    default: 
       printf("ERROR: Impossible type for an expression node.");
       exit(0);
  }
}