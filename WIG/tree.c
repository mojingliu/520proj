SERVICE* makeSERVICE(HTMLS* htmls, SCHEMAS* schemas, VARIABLES* variables, FUNCTIONS* functions, SESSIONS* sessions)
{
	SERVICE* s;
	s = NEW(SERVICE);
	s->lineno = lineno;
	s->htmls = htmls;
	s->schemas = schemas;
	s->variables = variables;
	s->functions = functions;
	s->sessions = sessions;
	return s;
}
// html : "const" "html" identifier "=" "<html>" htmlbodies "</html>" ";"
// nextbody can be null, or it can be "nehtmlbodies" which is 1 or more htmlbody
HTML* makeHTML(char* identifier, HTMLBODY* body, HTML* nextbody)
{
	HTML* h;
	h = NEW(HTML);
	h->lineno = lineno;
	h->identifier = identifier;
	h->body = body;
	h->nextbody = nextbody;
	return h;
}

HTMLBODY* makeHTMLBODYTAG(TAG* tag, HTMLBODY* nextbody)
{
	HTMLBODY* h;
	h = NEW(HTMLBODY);
	h->lineno = lineno;
	h->val.tag = tag;
	h->kind = tagK;
	h->nextbody = nextbody;
	return h;
}

HTMLBODY* makeHTMLBODYGAP(GAP* gap, HTMLBODY* nextbody)
{
	HTMLBODY* h;
	h = NEW(HTMLBODY);
	h->lineno = lineno;
	h->val.gap = gap;
	h->kind = gapK;
	h->nextbody = nextbody;
	return h;
}

HTMLBODY* makeHTMLBODYWHATEVER(char* whatever, HTMLBODY* nextbody)
{
	HTMLBODY* h;
	h = NEW(HTMLBODY);
	h->lineno = lineno;
	h->val.whatever = whatever;
	h->kind = whateverK;
	h->nextbody = nextbody;
	return h;
}

HTMLBODY* makeHTMLBODYMETA(HTMLMETA* meta, HTMLBODY* nextbody)
{
	HTMLBODY* h;
	h = NEW(HTMLBODY);
	h->lineno = lineno;
	h->val.meta = meta;
	h->kind = metaK;
	h->nextbody = nextbody;
	return h;
}

HTMLBODY* makeHTMLINPUT(INPUTATTR* inputattr, HTMLBODY* nextbody)
{
	HTMLBODY* h;
	h = NEW(HTMLBODY);
	h->lineno = lineno;
	h->inputattr = inputattr;
	h->nextbody = nextbody;
	return h;
}

HTMLBODY* makeHTMLSELECT(INPUTATTR* inputattr, HTMLBODY* insidebody, HTMLBODY* nextbody)
{
	HTMLBODY* h;
	h = NEW(HTMLBODY);
	h->lineno = lineno;
	h->inputattr = inputattr;
	h->insidebody = insidebody;
	h->nextbody = nextbody;
	return h;
}

// ========================== ATTRs ==========================================
INPUTATTR* makeINPUTATTRname(ATTR* attr, INPUTATTR* nextattr)
{
	INPUTATTR* i;
	i = NEW(INPUTATTR);
	i->lineno = lineno;
	i->kind = nameK;
	i->attr = attr;
	i->nextattr = nextattr;

	return i;
}

INPUTATTR* makeINPUTATTRtype(char* type, INPUTATTR* nextattr)
{
	INPUTATTR* i;
	i = NEW(INPUTATTR);
	i->lineno = lineno;
	i->kind = typeK;
	i->val.type = inputtype;
	i->nextattr = nextattr;

	return i;
}

INPUTATTR* makeINPUTATTRattribute(ATTRIBUTE* attribute, INPUTATTR* nextattr)
{
	INPUTATTR* i;
	i = NEW(INPUTATTR);
	i->lineno = lineno;
	i->kind = otherK;
	i->attribute = attribute;
	i->nextattr = nextattr;

	return i;
}

ATTRIBUTE* makeATTRIBUTEattr(ATTR* attr, ATTRIBUTE* next)
{
	ATTRIBUTE* a;
	a = NEW(ATTRIBUTE);
	a->lineno = lineno;
	a->kind = attributeK;
	a->attr = attr;
	a->nextattr = nextattr;

	return a;
}

ATTRIBUTE* makeATTRIBUTEattreqattr(ATTR* attr1, ATTR* attr2, ATTRIBUTE* next)
{
	ATTRIBUTE* a;
	a = NEW(ATTRIBUTE);
	a->lineno = lineno;
	a->kind = attributeK;
	a->attr1 = attr1;
	a->attr2 = attr2;
	a->nextattr = nextattr;
	return a;
}

ATTR* makeATTRid(ID* id)
{
	ATTR* a;
	a = NEW(ATTR);
	a->lineno = lineno;
	a->kind = attridK;
	a->val.id = id
	return a;
}

ATTR* makeATTRstringconst(char* stringconst)
{
	ATTR* a;
	a = NEW(ATTR);
	a->lineno = lineno;
	a->kind = attrstringconstK;
	a->val.stringconst = stringconst
	return a;
}

// ================================== SCHEMAS =============================

SCHEMA* makeSCHEMA(ID* id, FIELD* field, SCHEMA* next)
{
	SCHEMA* s;
	s = NEW(SCHEMA);
	s->lineno = lineno;
	s->kind= schemaK;
	s->id = id;
	s->field = field;
	s->next = next;
	return s;
}

FIELD* makeFIELD(SIMPLETYPE* simpletype, ID* id, FIELD* next)
{
	FIELD* f;
	f = NEW(FIELD);
	f->lineno = lineno;
	f->kind= fieldK;
	f->id = id;
	f->simpletype = simpletype;
	f->next = next;
	return f;
}

VARIABLE* makeVARIABLE(TYPE* type, ID* id, VARIABLE* next)
{
	VARIABLE* v;
	v = NEW(VARIABLE);
	v->lineno = lineno;
	v->id = id;
	v->type = type;
	v->next = next;
	return v;
}

ID* makeID(char* identifier, ID* next)
{
	ID* i;
	i = NEW(ID);
	i->lineno = lineno;
	i->identifier = identifier;
	i->next = next;
	return i;
}

TYPE* makeTYPEsimpletype(SIMPLETYPE* simpletype)
{
	TYPE* t;
	t = NEW(TYPE);
	t->lineno = lineno;
	t->val.simpletype = simpletype;
	t->kind = simpletypeK;
	return t;
}

TYPE* makeTYPEtupleid(ID* id)
{
	TYPE* t;
	t = NEW(TYPE);
	t->lineno = lineno;
	t->val.id = id;
	t->kind = tupleidK;
	return t;
}

SIMPLETYPE* makeSIMPLETYPEint()
{
	SIMPLETYPE* s;
	s = NEW(SIMPLETYPE);
	s->lineno = lineno;
	s->kind = intK;
	return s;
}

SIMPLETYPE* makeSIMPLETYPEbool()
{
	SIMPLETYPE* s;
	s = NEW(SIMPLETYPE);
	s->lineno = lineno;
	s->kind = boolK;
	return s;
}

SIMPLETYPE* makeSIMPLETYPEstring()
{
	SIMPLETYPE* s;
	s = NEW(SIMPLETYPE);
	s->lineno = lineno;
	s->kind = stringK;
	return s;
}

SIMPLETYPE* makeSIMPLETYPEvoid()
{
	SIMPLETYPE* s;
	s = NEW(SIMPLETYPE);
	s->lineno = lineno;
	s->kind = voidK;
	return s;
}

FUNCTION* makeFUNCTION(TYPE* type, ID* id, ARGUMENT* argument, COMPOUNDSTM* compoundstm, FUNCTION* next)
{
	FUNCTION* f;
	f = NEW(FUNCTION);
	f->lineno = lineno;
	f->type = type;
	f->id = id;
	f->argument = argument;
	f->compoundstm = compoundstm;
	f->next = next;
	return f;
}

ARGUMENT* makeARGUMENT(TYPE* type, ID* id)
{	// TODO: GONNA NEED TO PUT A NEXT IN HERE
	ARGUMENT* a;
	a = NEW(ARGUMENT);
	a->lineno = lineno;
	a->type = type;
	a->id = id;
	a->next = NULL;
	return a;
}



SESSION* makeSESSION(ID* id, COMPOUNDSTM* compoundstm, SESSION* next)
{
	SESSION* s;
	s = NEW(SESSION);
	s->lineno = lineno;
	s->id = id;
	s->compoundstm = compoundstm
	s->next = next;
	return s;
}

STM* makeSTMsemicolon()
{
	STM* s;
	s = NEW(STM);
	s->lineno = lineno;
	s->kind = stmsemicolonK;
	a->next = NULL;
	return s;
}

STM* makeSTMshow(DOCUMENT* doc, RECEIVE* rec)
{
	STM* s;
	s = NEW(STM);
	s->lineno = lineno;
	s->kind = stmshowK;
	s->val.stmShow.doc = doc;
	s->val.stmShow.rec = rec;
	a->next = NULL;
	return s;
}

STM* makeSTMexit(DOCUMENT* doc)
{
	STM* s;
	s = NEW(STM);
	s->lineno = lineno;
	s->kind = stmexitK;
	s->val.doc = doc;
	a->next = NULL;
	return s;
}

STM* makeSTMreturn()
{
	STM* s;
	s = NEW(STM);
	s->lineno = lineno;
	s->kind = stmreturnK;
	a->next = NULL;
	return s;
}

STM* makeSTMreturnexpr(EXP* expr)
{
	STM* s;
	s = NEW(STM);
	s->lineno = lineno;
	s->kind = stmreturnexpK;
	s->expr = expr;
	a->next = NULL;
	return s;
}

STM* makeSTMif(EXP* expr, STM* stm)
{
	STM* s;
	s = NEW(STM);
	s->lineno = lineno;
	s->kind = stmifK;
	s->val.ifSTM.expr = expr;
	s->val.ifSTM.stm = stm;
	a->next = NULL;
	return s;
}

STM* makeSTMifelse(EXP* expr, STM* stm1, STM* stm2)
{
	STM* s;
	s = NEW(STM);
	s->lineno = lineno;
	s->kind = stmifelseK;
	s->val.ifelseSTM.expr = expr;
	s->val.ifelseSTM.stm1 = stm1;
	s->val.ifelseSTM.stm2 = stm2;
	a->next = NULL;
	return s;
}

STM* makeSTMwhile(EXP* expr, STM* stm)
{
	STM* s;
	s = NEW(STM);
	s->lineno = lineno;
	s->kind = stmwhileK;
	s->val.whileSTM.expr = expr;
	s->val.whileSTM.stm = stm;
	a->next = NULL;
	return s;
}

STM* makeSTMcompound(COMPOUNDSTM* compoundstm)
{
	STM* s;
	s = NEW(STM);
	s->lineno = lineno;
	s->kind = compoundstmK;
	s->next = NULL;
	s->compoundstm = compoundstm;
	return s;
}

STM* makeSTMexp(EXP* expr)
{
	STM* s;
	s = NEW(STM);
	s->lineno = lineno;
	s->kind = stmexprK;
	s->expr = expr;
	a->next = NULL;
	return s;
}

COMPOUNDSTM* makeCOMPOUNDSTM(VARIABLE* variable, STM* stm)
{
	COMPOUNDSTM* c;
	c = NEW(COMPOUNDSTM);
	c->lineno = lineno;
	c->variable = variable;
	c->stm = stm;
	return c;
}