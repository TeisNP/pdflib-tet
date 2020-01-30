#ifndef _GOLANG_H
#define _GOLANG_H

#include "tetlib.h"

void _TET_delete(TET *tet);

int _TET_open_document(TET *tet, const char *filename, int len, const char *optlist);

void _TET_close_document(TET *tet, int doc);

int _TET_open_page( TET *tet, int doc, int pagenumber, const char *optlist);

void _TET_close_page(TET *tet, int page);

void _TET_set_option(TET *tet, const char *optlist);

double _TET_pcos_get_number(TET *tet, int doc, const char *path);

const char * _TET_get_text(TET *tet, int page, int *len);

const char * _TET_get_errmsg(TET *tet);

int _TET_get_errnum(TET *tet);

const char * _TET_get_apiname(TET *tet);


#endif /* _GOLANG_H */