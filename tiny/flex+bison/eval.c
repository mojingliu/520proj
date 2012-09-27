#include <stdio.h>
#include <string.h>
#include <math.h>
#include "eval.h"

struct 
{
    int value;
    char* expression;
    int which;
} dumbStruct;

typedef struct dumbStruct expr;



expr evalEXP(EXP *e)
{ 
    expr toR = (expr *) malloc(sizeof(expr));

    switch (e->kind) {
    case idK:
        toR->which = 1;
        toR->expression = e->idE;
	    return(toR);
        break;
    case intconstK:
        toR->which = 0;
        toR->value = e->val.intconstE;
	    return(toR);
        break;
    case timesK:
        expr left = evalEXP(e->val.timesE.left)
        expr right = evalEXP(e->val.timesE.right);
        if(left->which == 0 && right->which == 0)
        {
            toR->which = 0;
            toR->value = left->value * right->value;
            return toR;
        }
        else
        {
            char* leftword;
            char* rightword;
            toR->which = 1;
            if(left->which == 0)
                leftword = itoa(left->value);
            else
                leftword = left->expression;
            if(right->which == 0)
                rightword = itoa(right->value);
            else
                rightword = right->expression;
            toR->expression = (char*)malloc(sizeof(char) * (strlen(leftword) + strlen(rightword) + 1));
            strcat(toR->expression, leftword);
            strcat(toR->expression, "*");
            strcat(toR->expression, rightword);
            return toR;
        }
        break;
    case divK:
        if(!evalEXP(e->val.divE.right))
        {
            printf("Error - division by 0\n");
            return(0);
            break;
        }
        return (evalEXP(e->val.divE.left)/
            evalEXP(e->val.divE.right));
        break;
    case plusK:
	    return(evalEXP(e->val.plusE.left) + 
	        evalEXP(e->val.plusE.right));
        break;
    case minusK:
	    return(evalEXP(e->val.minusE.left) -
	       evalEXP(e->val.minusE.right));
        break;  
    case moduloK:
        return(evalEXP(e->val.moduloE.left) %
            evalEXP(e->val.moduloE.right));
        break; 
    case absK:
        return abs(evalEXP(e->val.absE.left));
        break;
    case exponentK:
        return pow(evalEXP(e->val.exponentE.left), 
            evalEXP(e->val.exponentE.right));

    default: 
	   printf("ERROR: Impossible type for an expression node.");
	   return(0);
  }
}