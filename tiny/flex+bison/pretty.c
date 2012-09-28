#include <stdio.h>
#include "pretty.h"

/* 1: cst_exp
   2: factor
   3: power
   4: term */
void prettyEXP(EXP *e, int level)
{ switch (e->kind) {
    case idK:
         printf("%s",e->val.idE);
         break;
    case intconstK:
         printf("%i",e->val.intconstE);
         break;
    case timesK:
        if(level > 2)
         printf("(");
         prettyEXP(e->val.timesE.left, 2);
         printf("*");
         prettyEXP(e->val.timesE.right, 3);
        if(level > 2)
         printf(")");
         break;
    case divK:
        if(level > 2)
         printf("(");
         prettyEXP(e->val.divE.left, 2);
         printf("/");
         prettyEXP(e->val.divE.right, 3);
        if(level > 2)
         printf(")");
         break;
    case moduloK:
        if(level > 2)
         printf("(");
         prettyEXP(e->val.moduloE.left, 2);
         printf("%%");
         prettyEXP(e->val.moduloE.right, 3);
        if(level > 2)
         printf(")");
         break;
    case plusK:
        if(level > 1)
         printf("(");
         prettyEXP(e->val.plusE.left, 1);
         printf("+");
         prettyEXP(e->val.plusE.right, 2);
        if(level > 1)
         printf(")");
         break;
    case minusK:
        if(level > 1)
         printf("(");
         prettyEXP(e->val.minusE.left, 1);
         printf("-");
         prettyEXP(e->val.minusE.right, 2);
        if(level > 1)
         printf(")");
         break;
    case absK:
        printf("abs(");
        prettyEXP(e->val.absE.left, 1);
        printf(")");
        break;
    case exponentK:
        if(level > 3)
            printf("(");
        prettyEXP(e->val.exponentE.left, 4);
        printf("**");
        prettyEXP(e->val.exponentE.right, 3);
        if(level > 3)
            printf(")");
  }
}
