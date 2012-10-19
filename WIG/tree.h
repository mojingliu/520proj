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

typedef struct HTML{
	int lineno;
	char* identifier;
	struct HTMLBODY* body;
	struct HTML* next;
} HTML;

typedef struct HTMLBODY {
	int lineno;
	enum{tagK, gapK, whateverK, metaK, inputK, selectK} kind;
	union{
		struct {
			struct ID* id;
			struct ATTRIBUTE* attribute;
		} tagE;

		struct ID* id;
		char* whatever;
		struct HTMLMETA* meta;
		struct INPUTATTR* inputattr;
		struct {
			struct INPUTATTR* inputattr;
			struct HTMLBODY* body;
		} selectE;
	} val;
	struct HTMLBODY* next;
} HTMLBODY;

typedef struct INPUTATTR{
	int lineno;
	enum{nameK, typeK, otheK}
	union{
		struct ATTR* attr;
		char* type;
		struct ATTRIBUTE* attribute;
	} val;

	struct INPUTATTR* next;
} INPUTATTR;


typedef struct ATTRIBUTE{
	int lineno;
	struct ATTR* right;
	struct ATTR* left;
	struct ATTRIBUTE* next;
} ATTRIBUTE;

typedef struct ATTR{
	int lineno;
	enum{attridK, attrstringconstK} kind;
	union{
		struct ID* id;
		char* stringconst;
	} val;
} ATTR;

typedef struct SCHEMA{
	int lineno;
	struct SCHEMA* next;
	struct ID* id;
	struct FIELD* field;
} SCHEMA;

typedef struct FIELD{
	int lineno;
	struct FIELD* next;
	struct ID* id;
	struct SIMPLETYPE* simpletype;
} FIELD;

typedef struct VARIABLE{
	int lineno;
	struct TYPE* type;
	struct ID* id;
	struct VARIABLE* next;
} VARIABLE;

type struct ID{
	int lineno;
	struct ID* identifier;
	struct ID* next;
} ID;

type struct TYPE{
	int lineno;
	enum{tupleidK, simpletypeK} kind;
	union{
		struct SIMPLETYPE* simpletype;
		struct ID* id;
	} val;
} TYPE;

type struct SIMPLETYPE{
	int lineno;
	enum{intK, boolK, stringK, voidK} kind;
} SIMPLETYPE;

type struct FUNCTION{
	int lineno;
	struct TYPE* type;
	struct ID* id;
	struct ARGUMENT* argument;
	struct COMPOUNDSTM* compoundstm;
	struct FUNCTION* next;
} FUNCTION;

type struct ARGUMENT{
	int lineno;
	struct TYPE* type;
	struct ID* id;
	struct ARGUMENT* next;
} ARGUMENT;

type struct SESSION{
	int lineno;
	struct ID* id;
	struct COMPOUNDSTM* compoundstm;
	struct SESSION* next;
} SESSION;

type struct STM{
	int lineno;
	enum{semicolonK, showK, exitK, returnexprK, ifK, ifelseK, whileK, compoundK, exprK} kind;
	union{
		struct{
			struct DOCUMENT* doc;
			struct RECEIVE* rec;
		} showE;

		struct DOCUMENT* doc;
		struct EXP* expr;
		struct{
			struct EXP* expr;
			struct STM* stm;
		} ifE;

		struct{
			struct EXP* expr;
			struct STM* stm1;
			struct STM* stm2;
		} ifelseE;

		struct{
			struct EXP* expr;
			struct STM* stm;
		} whileE;

		struct COMPOUNDSTM* compoundstm;
		struct EXP* expr;
	} val;

	struct STM* next;

} STM;

type struct COMPOUNDSTM{
	int lineno;
	struct VARIABLE* variable;
	struct STM* stm;
} COMPOUNDSTM;

type struct DOCUMENT{
	int lineno;
	enum{idK, plugK}
	union{
		struct ID* id;
		struct {
			struct ID* id;
			struct PLUG* plug;
		} plugE;
	} val;
} DOCUMENT;

type struct RECEIVE{
	int lineno;
	struct INPUT* input;
} RECEIVE;

type struct PLUG{
	int lineno;
	struct ID* id;
	struct EXP* expr;
	struct PLUG* next;
} PLUG;

type struct INPUT{
	int lineno;
	struct LVALUE* lvalue;
	struct ID* id;
	struct INPUT* next;
} INPUT;

type struct LVALUE{
	int lineno;
	struct ID* id1;
	struct ID* id2;
} LVALUE;

type struct FIELDVALUE{
	int lineno;
	struct ID* id;
	struct EXP* expr;
	struct FIELDVALUE next;
} FIELDVALUE;

type struct EXP{
	int lineno;
	enum{lvalueK, assignK, equalsK, notequalsK, ltK, 
		gtK, lteK, gteK, notK, plusK, minusK, multK, 
		divK, modK, andK, orK, joinK, keepK, removeK, 
		callK, intconstK, trueK, falseK, stringconstK, 
		tupleK }kind;

	union{
		struct LVALUE* lvalue;
		struct{
			struct LVALUE* lvalue;
			struct EXP* expr;
		}assignE;

		struct{
			struct EXP* left;
			struct EXP* right;
		}equalsE;

		struct{
			struct EXP* left;
			struct EXP* right;
		}notequalsE;

		struct{
			struct EXP* left;
			struct EXP* right;
		}ltE;

		struct{
			struct EXP* left;
			struct EXP* right;
		}gtE;

		struct{
			struct EXP* left;
			struct EXP* right;
		}lteE;

		struct{
			struct EXP* left;
			struct EXP* right;
		}gteE;

		struct EXP* expr;

		struct{
			struct EXP* left;
			struct EXP* right;
		}plusE;

		struct{
			struct EXP* left;
			struct EXP* right;
		}minusE;

		struct{
			struct EXP* left;
			struct EXP* right;
		}multE;

		struct{
			struct EXP* left;
			struct EXP* right;
		}divE;

		struct{
			struct EXP* left;
			struct EXP* right;
		}modE;

		struct{
			struct EXP* left;
			struct EXP* right;
		}andE;

		struct{
			struct EXP* left;
			struct EXP* right;
		}orE;

		struct{
			struct EXP* left;
			struct EXP* right;
		}joinE;

		struct{
			struct EXP* left;
			struct ID* right;
		}keepE;

		struct{
			struct EXP* left;
			struct ID* right;
		}removeE;

		struct{
			struct EXP* right
			struct ID* left;
		}callE;

		int intconst;
		char* stringconst;
		struct FIELDVALUE* fieldvalue;


	}val;

	struct EXP* next;
} EXP;









#endif /* !TREE_H */