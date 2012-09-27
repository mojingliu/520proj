#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "eval.h"

void i_hate_c(expre* toR, expre* left, expre* right, char const* connector)
{   /* python : toR = str(left) + c + str(right)
       ::
       c : */
    char* leftword = malloc(sizeof(char) * 20);
    char* rightword = malloc(sizeof(char) * 20);
    toR->which = 1;
    if(left->which == 0)
        sprintf(leftword, "%d", left->value);
    else
        leftword = left->expression;
    if(right->which == 0)
        sprintf(rightword, "%d", right->value);
    else
        rightword = right->expression;
    toR->expression = (char*)malloc(sizeof(char) * (strlen(leftword) + strlen(rightword) + 3));
    sprintf(toR->expression, "(%s%s%s)", leftword, connector, rightword);
}

expre evalEXP(EXP *e)
{
    expre toR = {0, "", 0};  /* Just initialize to something */

    switch (e->kind) {
    case idK:
        toR.which = 1;
        toR.expression = e->val.idE;
	    return(toR);
    case intconstK:
        toR.which = 0;
        toR.value = e->val.intconstE;
	    return(toR);
    case timesK:
    {
        expre left = evalEXP(e->val.timesE.left);
        expre right = evalEXP(e->val.timesE.right);
        if(!left.which && !right.which)
        {
            toR.which = 0;
            toR.value = left.value * right.value;
        }
        else if((!left.which && !left.value) || (!right.which && !right.value))
        {    /* one is 0; I know the answer to this! */
            toR.which = 0;
            toR.value = 0;
        }
        else
            i_hate_c(&toR, &left, &right, "*");
        return toR;
    }
    case divK:
    {
        expre left = evalEXP(e->val.divE.left);
        expre right = evalEXP(e->val.divE.right);
        if(!right.which && !right.value)
        {
            printf("Error - division by 0\n");
            exit(0);
        }
        if(!left.which && !right.which)
        {
            toR.which = 0;
            toR.value = left.value / right.value;
        }
        else if(!right.which && right.value == 1)
            return left;  /* x/1 == x */
        else
            i_hate_c(&toR, &left, &right, "/");
        return toR;
    }
    case plusK:
    {
        expre left = evalEXP(e->val.plusE.left);
        expre right = evalEXP(e->val.plusE.right);
        if(!left.which && !left.value)
            return right; /* 0 + x = x */
        if(!right.which && !right.value)
            return left;  /* x + 0 = x */
        if(!left.which && !right.which)
        {
            toR.which = 0;
            toR.value = left.value + right.value;
        }
        else
            i_hate_c(&toR, &left, &right, "+");
        return toR;
    }
    case minusK:
    {
        expre left = evalEXP(e->val.minusE.left);
        expre right = evalEXP(e->val.minusE.right);
        if(!right.which && !right.value)
            return left;  /* x - 0 = x */
        if(!left.which && !right.which)
        {
            toR.which = 0;
            toR.value = left.value - right.value;
        }
        else
            i_hate_c(&toR, &left, &right, "-");
        return toR;
    }
    case moduloK:
    {
        expre left = evalEXP(e->val.moduloE.left);
        expre right = evalEXP(e->val.moduloE.right);
        if(!right.which && !right.value)   
        {
            printf("Error - modulo by 0\n");
            exit(0);
        }
        if(!right.which && right.value == 1)
        {   /* x % 1 == 0 */
            toR.which = 0;
            toR.value = 0;
        }
        else if(!left.which && !right.which)
        {
            toR.which = 0;
            toR.value = left.value % right.value;
        }
        else
            i_hate_c(&toR, &left, &right, "%");
        return toR;
    }
    case absK:
    {
        expre only = evalEXP(e->val.absE.left);
        if(!only.which)
        {
            toR.which = 0;
            toR.value = abs(only.value);
        }
        else
        {
            toR.which = 1;
            toR.expression = (char*)malloc(sizeof(char) * (strlen(only.expression) + 6));
            sprintf(toR.expression, "abs(%s)", only.expression);
        }
        return toR;
    }
    case exponentK:
    {   /* Can't check 0 ** x because 0 ** 0 == 1 */
        expre left = evalEXP(e->val.exponentE.left);
        expre right = evalEXP(e->val.exponentE.right);
        if(!right.which && !right.value)
        {   /* x ** 0 == 1 */
            toR.which = 0;
            toR.value = 1;
        }
        else if(!right.which && right.value == 1)
            return left;  /* x ** 1 == x */
        else if(!left.which && left.value == 1)
        {   /* 1 ** x == 1 */
            toR.which = 0;
            toR.value = 1;
        }
        else if(!left.which && !right.which)
        {
            toR.which = 0;
            toR.value = pow(left.value, right.value);
        }
        else
            i_hate_c(&toR, &left, &right, "**");
        return toR;
    }
    default: 
	   printf("ERROR: Impossible type for an expression node.");
	   exit(0);
  }
}