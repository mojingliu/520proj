#ifndef TREE_H
#define TREE_H
 
typedef struct EXP {
  int lineno;
  enum {idK,intconstK,timesK,divK,plusK,minusK, moduloK, absK, exponentK} kind;
  union {
    char *idE;
    int intconstE;
    struct {struct EXP *left; struct EXP *right;} timesE;
    struct {struct EXP *left; struct EXP *right;} divE;
    struct {struct EXP *left; struct EXP *right;} plusE;
    struct {struct EXP *left; struct EXP *right;} minusE;
    struct {struct EXP *left; struct EXP *right;} moduloE;
    struct {struct EXP *left;} absE;
    struct {struct EXP *left; struct EXP *right;} exponentE;
  } val;
} EXP;
 
EXP *makeEXPid(char *id);

EXP *makeEXPintconst(int intconst);

EXP *makeEXPtimes(EXP *left, EXP *right);

EXP *makeEXPdiv(EXP *left, EXP *right);

EXP *makeEXPplus(EXP *left, EXP *right);

EXP *makeEXPminus(EXP *left, EXP *right);

EXP *makeEXPmodulo(EXP *left, EXP *right);

EXP *makeEXPabs(EXP *left);

EXP *makeEXPexponent(EXP *left, EXP *right);

#endif /* !TREE_H */
