#ifndef TREE_H
#define TREE_H

typedef struct SERVICE {
	int lineno;
	struct HTML* html;
	struct SCHEMA* schema;
	struct VARIABLE* variable;
	struct FUNCTION* function;
	struct SESSION* session;
} SERVICE;


#endif /* !TREE_H */