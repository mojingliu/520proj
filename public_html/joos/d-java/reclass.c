/*
 * reclass.c
 * Copyright (c) 1996,1997 Shawn Silverman
 *
*/

#include <stdio.h>
#include <stdlib.h>
#include "d-java.h"

static void resetClassFile(ClassFile *);

static int readConstantPool(FILE *, ClassFile *);
static int readFields(FILE *, ClassFile *);
static int readInterfaces(FILE *, ClassFile *);
static int readMethods(FILE *, ClassFile *);
static int readAttributes(FILE *, ClassFile *);
static int readAttribute(FILE *fp, ClassFile *, attribute_info *);
static void freeAttribute(ClassFile *, attribute_info);

static void resetClassFile(ClassFile *cf)
{
    cf->constant_pool_count = 0;
    cf->constant_pool = NULL;
    cf->interfaces_count = 0;
    cf->interfaces = NULL;
    cf->fields_count = 0;
    cf->fields = NULL;
    cf->methods_count = 0;
    cf->methods = NULL;
    cf->attributes_count = 0;
    cf->attributes = NULL;
}

int readClassFile(FILE *fp, ClassFile **cf)
{
    if ((*cf = (ClassFile *)malloc(sizeof(ClassFile))) == NULL)
        return ERR_MEM;

    /* Set all the fields to NULL to ensure freeClassFile doesn't
       screw up */
    resetClassFile(*cf);
    
    /* Get first four bytes and compare to MAGIC */
    CHECK_U4((*cf)->magic);
    if ((*cf)->magic != MAGIC)
	return ERR_NOT_CLASS_FILE;

    CHECK_U2((*cf)->minor_version);
    CHECK_U2((*cf)->major_version);

    CHECK_U2((*cf)->constant_pool_count);
    CHECK_STATUS(readConstantPool(fp, *cf));

    CHECK_U2((*cf)->access_flags);
    CHECK_U2((*cf)->this_class);
    CHECK_U2((*cf)->super_class);

    CHECK_U2((*cf)->interfaces_count);
    if ((*cf)->interfaces_count >= 1) {
	if ((status = readInterfaces(fp, *cf)) != ERR_OK) {
	    freeClassFile(*cf);
	    return status;
	}
    }

    CHECK_U2((*cf)->fields_count);
    if ((*cf)->fields_count >= 1) {
	if ((status = readFields(fp, *cf)) != ERR_OK) {
	    freeClassFile(*cf);
	    return status;
	}
    }

    CHECK_U2((*cf)->methods_count);
    if ((*cf)->methods_count >= 1) {
	if ((status = readMethods(fp, *cf)) != ERR_OK) {
	    freeClassFile(*cf);
	    return status;
	}
    }

    CHECK_U2((*cf)->attributes_count);
    if ((*cf)->attributes_count >= 1) {
	if ((status = readAttributes(fp, *cf)) != ERR_OK) {
	    freeClassFile(*cf);
	    return status;
	}
    }

    return ERR_OK;
}

static int readConstantPool(FILE *fp, ClassFile *cf)
{
    u2 i;
    u4 u4val;

    if ((cf->constant_pool =
        (cp_info *)malloc(cf->constant_pool_count * sizeof(cp_info)))
        == NULL)
        return ERR_MEM;
        
#define cpi	cf->constant_pool[i]
    for (i=1; i<=cf->constant_pool_count-1; i++) {
        CHECK_U1(cpi.tag);
        cpi.fpos = ftell(fp) - 1L;
        switch(cpi.tag) {
            case CONSTANT_Class:
                CHECK_U2(cpi.index1);
                break;
            case CONSTANT_Fieldref:
            case CONSTANT_Methodref:
            case CONSTANT_InterfaceMethodref:
                CHECK_U2(cpi.index1);
                CHECK_U2(cpi.index2);
                break;
            case CONSTANT_String:
                CHECK_U2(cpi.index1);
                break;
            case CONSTANT_Integer:
            case CONSTANT_Float:
                CHECK_U4(u4val);
                cpi.item.i = u4val;
                break;
            case CONSTANT_Long:
            case CONSTANT_Double:
                CHECK_U4(u4val);
                cpi.item.l = (long long)u4val << 32;
                CHECK_U4(u4val);
                cpi.item.l |= u4val;
                i++;
                break;
            case CONSTANT_NameAndType:
                CHECK_U2(cpi.index1);
                CHECK_U2(cpi.index2);
                break;
            case CONSTANT_Utf8:
            case CONSTANT_Unicode:
                CHECK_U2(cpi.length);
                if ((cpi.item.bytes = malloc(cpi.length + 1)) == NULL)
                    return ERR_MEM;
                    /*flags.cp_strings = FALSE; */
                else {
                    /*flags.cp_strings = TRUE; */
                    CHECK_BYTES(cpi.item.bytes, cpi.length);
                    *((char *)cpi.item.bytes + cpi.length) = '\0';
                }
                break;
            default:
                return ERR_UNDEFINED_CONSTANT;
        }
    }
#undef cpi

    return ERR_OK;
}

static int readInterfaces(FILE *fp, ClassFile *cf)
{
    u2 i;
    
    if ((cf->interfaces =
        (u2 *)malloc(cf->interfaces_count * sizeof(u2))) == NULL)
        return ERR_MEM;
    
    for (i=0; i<cf->interfaces_count; i++) {
        CHECK_U2(cf->interfaces[i]);
    }
    
    return ERR_OK;
}

static int readFields(FILE *fp, ClassFile *cf)
{
    u2 i, j;
    
    if ((cf->fields =
        (field_info *)malloc(cf->fields_count * sizeof(field_info)))
        == NULL)
        return ERR_MEM;

    for (i=0; i<cf->fields_count; i++) {
        CHECK_U2(cf->fields[i].access_flags);
        CHECK_U2(cf->fields[i].name_index);
        CHECK_U2(cf->fields[i].descriptor_index);
        CHECK_U2(cf->fields[i].attributes_count);

        if ((cf->fields[i].attributes =
            (attribute_info *)
            malloc(cf->fields[i].attributes_count * sizeof(attribute_info)))
            == NULL)
            return ERR_MEM;

        for (j=0; j<cf->fields[i].attributes_count; j++) {
            readAttribute(fp, cf, &cf->fields[i].attributes[j]);
        }
    }
    
    return ERR_OK;
}

static int readMethods(FILE *fp, ClassFile *cf)
{
    u2 i, j;
    
    if ((cf->methods =
        (method_info *)malloc(cf->methods_count * sizeof(method_info)))
        == NULL)
        return ERR_MEM;

    for (i=0; i<cf->methods_count; i++) {
        CHECK_U2(cf->methods[i].access_flags);
        CHECK_U2(cf->methods[i].name_index);
        CHECK_U2(cf->methods[i].descriptor_index);
        CHECK_U2(cf->methods[i].attributes_count);

        if ((cf->methods[i].attributes =
            (attribute_info *)
            malloc(cf->methods[i].attributes_count * sizeof(attribute_info)))
            == NULL)
            return ERR_MEM;

        for (j=0; j<cf->methods[i].attributes_count; j++) {
            readAttribute(fp, cf, &cf->methods[i].attributes[j]);
        }
    }

    return ERR_OK;
}

static int readAttributes(FILE *fp, ClassFile *cf)
{
    u2 i;
    
    if ((cf->attributes =
        (attribute_info *)
        malloc(cf->attributes_count * sizeof(attribute_info)))
        == NULL)
        return ERR_MEM;
    
    for (i=0; i<cf->attributes_count; i++) {
        readAttribute(fp, cf, &cf->attributes[i]);
    }

    return ERR_OK;
}

static int readAttribute(FILE *fp, ClassFile *cf, attribute_info *ai)
{
    u2 attribute_name, i;
    u4 attribute_length;

    CHECK_U2(attribute_name);
    CHECK_U4(attribute_length);

    /* SourceFile_attribute */
    if (!strcmp((char *)cf->constant_pool[attribute_name].item.bytes,
        "SourceFile")) {
        if ((ai->sf = (SourceFile_attribute *)
            malloc(sizeof(SourceFile_attribute))) == NULL)
            return ERR_MEM;
        ai->sf->attribute_name_index = attribute_name;
        ai->sf->attribute_length = attribute_length;
        CHECK_U2(ai->sf->sourcefile_index);
    }

    /* ConstantValue_attribute */
    else if (!strcmp((char *)cf->constant_pool[attribute_name].item.bytes,
        "ConstantValue")) {
        if ((ai->cv = (ConstantValue_attribute *)
            malloc(sizeof(ConstantValue_attribute))) == NULL)
            return ERR_MEM;
        ai->cv->attribute_name_index = attribute_name;
        ai->cv->attribute_length = attribute_length;
        CHECK_U2(ai->cv->constantvalue_index);
    }

    /* Code_attribute */
    else if (!strcmp((char *)cf->constant_pool[attribute_name].item.bytes,
        "Code")) {
        if ((ai->c = (Code_attribute *)
            malloc(sizeof(Code_attribute))) == NULL)
            return ERR_MEM;
        ai->c->attribute_name_index = attribute_name;
        ai->c->attribute_length = attribute_length;
        CHECK_U2(ai->c->max_stack);
        CHECK_U2(ai->c->max_locals);

        CHECK_U4(ai->c->code_length);
        if ((ai->c->code = (u1 *)malloc(ai->c->code_length)) == NULL)
            return ERR_MEM;
        CHECK_BYTES(ai->c->code, ai->c->code_length);

        CHECK_U2(ai->c->exception_table_length);
        if ((ai->c->exception_table = (exception_table_info *)
            malloc(ai->c->exception_table_length *
            sizeof(exception_table_info))) == NULL)
            return ERR_MEM;
        for (i=0; i<ai->c->exception_table_length; i++) {
            CHECK_U2(ai->c->exception_table[i].start_pc);
            CHECK_U2(ai->c->exception_table[i].end_pc);
            CHECK_U2(ai->c->exception_table[i].handler_pc);
            CHECK_U2(ai->c->exception_table[i].catch_type);
        }

        CHECK_U2(ai->c->attributes_count);
        if ((ai->c->attributes = (attribute_info *)
            malloc(ai->c->attributes_count *
            sizeof(attribute_info))) == NULL)
            return ERR_MEM;
        for (i=0; i<ai->c->attributes_count; i++) {
            CHECK_STATUS(readAttribute(fp, cf, &ai->c->attributes[i]));
        }
    }

    /* Exceptions_attribute */
    else if (!strcmp((char *)cf->constant_pool[attribute_name].item.bytes,
        "Exceptions")) {
        if ((ai->e = (Exceptions_attribute *)
            malloc(sizeof(Exceptions_attribute))) == NULL)
            return ERR_MEM;
        ai->e->attribute_name_index = attribute_name;
        ai->e->attribute_length = attribute_length;
        CHECK_U2(ai->e->number_of_exceptions);
        
        if ((ai->e->exception_index_table = (u2 *)
            malloc(ai->e->number_of_exceptions * sizeof(u2))) == NULL)
            return ERR_MEM;
        for (i=0; i<ai->e->number_of_exceptions; i++) {
            CHECK_U2(ai->e->exception_index_table[i]);
        }
    }

    /* LineNumberTable_attribute */
    else if (!strcmp((char *)cf->constant_pool[attribute_name].item.bytes,
        "LineNumberTable")) {
        if ((ai->lnt = (LineNumberTable_attribute *)
            malloc(sizeof(LineNumberTable_attribute))) == NULL)
            return ERR_MEM;
        ai->lnt->attribute_name_index = attribute_name;
        ai->lnt->attribute_length = attribute_length;

        CHECK_U2(ai->lnt->line_number_table_length);
        if ((ai->lnt->line_number_table = (line_number_table_info *)
            malloc(ai->lnt->line_number_table_length *
            sizeof(line_number_table_info))) == NULL)
            return ERR_MEM;
        for (i=0; i<ai->lnt->line_number_table_length; i++) {
            CHECK_U2(ai->lnt->line_number_table[i].start_pc);
            CHECK_U2(ai->lnt->line_number_table[i].line_number);
        }
    }

    /* LocalVariableTable_attribute */
    else if (!strcmp((char *)cf->constant_pool[attribute_name].item.bytes,
        "LocalVariableTable")) {
        if ((ai->lvt = (LocalVariableTable_attribute *)
            malloc(sizeof(LocalVariableTable_attribute))) == NULL)
            return ERR_MEM;
        ai->lvt->attribute_name_index = attribute_name;
        ai->lvt->attribute_length = attribute_length;

        CHECK_U2(ai->lvt->local_variable_table_length);
        if ((ai->lvt->local_variable_table = (local_variable_table_info *)
            malloc(ai->lvt->local_variable_table_length *
            sizeof(local_variable_table_info))) == NULL)
            return ERR_MEM;
        for (i=0; i<ai->lvt->local_variable_table_length; i++) {
            CHECK_U2(ai->lvt->local_variable_table[i].start_pc);
            CHECK_U2(ai->lvt->local_variable_table[i].length);
            CHECK_U2(ai->lvt->local_variable_table[i].name_index);
            CHECK_U2(ai->lvt->local_variable_table[i].descriptor_index);
            CHECK_U2(ai->lvt->local_variable_table[i].slot);
        }
    }
    
    /* Attribute unknown */
    else {
        if (options.verbose) {
            fprintf(errfile, "Ignoring attribute \"%s\"\n",
                (char *)cf->constant_pool[attribute_name].item.bytes);
        }
        
        if ((ai->ga = (GenericAttribute_info *)
            malloc(sizeof(GenericAttribute_info))) == NULL)
            return ERR_MEM;
        ai->ga->attribute_name = attribute_name;
        ai->ga->attribute_length = attribute_length;
        /*CHECK_BYTES(ai->ga->info, attribute_length);*/
        fseek(fp, attribute_length, SEEK_CUR);
    }

    return ERR_OK;
}

void freeClassFile(ClassFile *cf)
{
    u2 i, j;
    
    if (!cf) return;
    
    /* free attributes */
    for (i=0; i<cf->attributes_count; i++) {
        if (cf->attributes[i].ga) freeAttribute(cf, cf->attributes[i]);
    }
    if (cf->attributes) free(cf->attributes);

    /* free methods */
    for (i=0; i<cf->methods_count; i++) {
        for (j=0; j<cf->methods[i].attributes_count; j++) {
            if (cf->methods[i].attributes[j].ga)
                freeAttribute(cf, cf->methods[i].attributes[j]);
        }
        if (cf->methods[i].attributes) free(cf->methods[i].attributes);
    }
    if (i) free(cf->methods);

    /* free fields */
    for (i=0; i<cf->fields_count; i++) {
        for (j=0; j<cf->fields[i].attributes_count; j++) {
            if (cf->fields[i].attributes[j].ga)
                freeAttribute(cf, cf->fields[i].attributes[j]);
        }
        if (cf->fields[i].attributes) free(cf->fields[i].attributes);
    }
    if (i) free(cf->fields);

    /* free interfaces */
    if (cf->interfaces_count) free(cf->interfaces);
    
#define cp	cf->constant_pool
    for (i=1; i<=cf->constant_pool_count-1; i++) {
        if (cp[i].tag == CONSTANT_Utf8 || cp[i].tag == CONSTANT_Unicode)
            if (cp[i].item.bytes) free(cp[i].item.bytes);
    }
    free(cp);
#undef cp

    free(cf);
}

static void freeAttribute(ClassFile *cf, attribute_info ai)
{
    u2 i;
    
    if (!strcmp((char *)cf->constant_pool[ai.ga->attribute_name].item.bytes,
        "SourceFile")) {
        /*if (ai.sf)*/ free(ai.sf);
    }

    /* ConstantValue_attribute */
    else if (!strcmp((char *)cf->constant_pool[ai.ga->attribute_name].item.bytes,
        "ConstantValue")) {
        /*if (ai.cv)*/ free(ai.cv);
    }

    /* Code_attribute */
    else if (!strcmp((char *)cf->constant_pool[ai.ga->attribute_name].item.bytes,
        "Code")) {
        /*if (ai.c)*/ {
            if (ai.c->attributes) {
                for (i=0; i<ai.c->attributes_count; i++)
                    freeAttribute(cf, ai.c->attributes[i]);
                free(ai.c->attributes);
            }
            if (ai.c->exception_table) free(ai.c->exception_table);
            if (ai.c->code) free(ai.c->code);
            free(ai.c);
        }
    }

    /* Exceptions_attribute */
    else if (!strcmp((char *)cf->constant_pool[ai.ga->attribute_name].item.bytes,
        "Exceptions")) {
        /*if (ai.e)*/ {
            if (ai.e->exception_index_table)
                free(ai.e->exception_index_table);
            free(ai.e);
        }
    }

    /* LineNumberTable_attribute */
    else if (!strcmp((char *)cf->constant_pool[ai.ga->attribute_name].item.bytes,
        "LineNumberTable")) {
        /*if (ai.lnt)*/ {
            if (ai.lnt->line_number_table) free(ai.lnt->line_number_table);
            free(ai.lnt);
        }
    }

    /* LocalVariableTable_attribute */
    else if (!strcmp((char *)cf->constant_pool[ai.ga->attribute_name].item.bytes,
        "LocalVariableTable")) {
        /*if (ai.lvt)*/ {
            if (ai.lvt->local_variable_table)
                free(ai.lvt->local_variable_table);
            free(ai.lvt);
        }
    }
    
    else {
        /*if (ai.ga)*/ {
            free(ai.ga);
        }
    }
}
