/*
 *      Small C+ Compiler
 *
 *      Routines for symbol hashing etc
 *
 *      $Id: sym.c,v 1.3 2004-03-26 22:06:09 denniz Exp $
 */

#include "ccdefs.h"

static void initialise_sym(SYMBOL *ptr, char *sname, enum ident_type id, char typ, enum storage_type storage, int more, int itag);



/* djm
 * Find a local static variable - uses findglb after first kludging the
 * name to a hopefully unique identifier!
 */

SYMBOL *findstc(char* sname)
{
    char sname2[3 * NAMESIZE]; /* Should be enuff! */
    strcpy(sname2, "st_");
    if (currfn)
        strcat(sname2, currfn->name);
    strcat(sname2, "_");
    strcat(sname2, sname);
    return (findglb(sname2));
}

/*
 * find entry in global symbol table,
 * glbptr is set to relevant entry
 * return pointer if match is found,
 * else return zero and glbptr points to empty slot
 */

SYMBOL* findenum(char* sname)
{
    SYMBOL *ptr = findglb(sname);

    if ( ptr != NULL ) {
        if ( ptr->ident == ID_ENUM ) {
            return ptr;
        }
        error(E_ENUMDEF);
    }
    return NULL;
}


SYMBOL* findglb(char* sname)
{
    SYMBOL *ptr;

    HASH_FIND_STR(symtab, sname, ptr);

    return ptr;
}

SYMBOL* findloc(char* sname)
{
    SYMBOL* ptr;

    ptr = STARTLOC;
    while (ptr != locptr) {
        if (strcmp(sname, ptr->name) == 0)
            return ptr;
        ++ptr;
    }
    return 0;
}



SYMBOL* addglb(
    char* sname, enum ident_type id, char typ,
    int value, enum storage_type storage, int more, int itag)
{
    SYMBOL* ptr;
    if ((ptr = findglb(sname))) {
        /*
         * djm, this is not to be abused!!!!
         *
         * This bit of code allows us to overturn extern declaration of stuff,
         * Useful for those programs which extern everything in header files
         * 
         */
        if ((ptr->storage == EXTERNAL && storage != EXTERNAL) ) {
            ptr->storage = storage;
            return (ptr);
        }
        if ((ptr->storage == EXTERNAL && storage == EXTERNAL) ) {
            return (ptr);
        }

        multidef(sname);
        return (ptr);
    }
    ptr = CALLOC(1, sizeof(*ptr));
    initialise_sym(ptr, sname, id, typ, storage, more, itag);
    ptr->offset.i = value;
    HASH_ADD_STR(symtab, name, ptr);   
    ++glbcnt;
    return (ptr);
}

SYMBOL* addloc(
    char* sname,
    enum ident_type id,
    char typ,
    int more,
    int itag)
{
    SYMBOL* cptr;

    if ((cptr = findloc(sname))) {
        multidef(sname);
        return cptr;
    }
    if (locptr >= ENDLOC) {
        error(E_LOCOV);
        return 0;
    }
    cptr = locptr++;
    initialise_sym(cptr, sname, id, typ, STKLOC, more, itag);
    return cptr;
}



/*
 * insert values into symbol table
 */

static void initialise_sym(
    SYMBOL* ptr,
    char* sname,
    enum ident_type id,
    char typ,
    enum storage_type storage,
    int more,
    int itag)
{
    strcpy(ptr->name, sname);
    ptr->ident = id;
    ptr->type = typ;
    ptr->storage = storage;
    ptr->more = more;
    ptr->tag_idx = itag;
    ptr->flags = FLAGS_NONE;
    snprintf(ptr->declared_location, sizeof(ptr->declared_location),"%s:%d", Filename, lineno);
}
