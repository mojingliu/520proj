#ifndef EVAL_H
#define EVAL_H

#include "tree.h"

typedef struct 
{
    int value;
    char* expression;
    int which;  /* 0 for int, 1 for expression */
} expre;

expre evalEXP(EXP *e);

#endif /* !EVAL_H */
