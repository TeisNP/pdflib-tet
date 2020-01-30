#include "golang.h"

void _TET_delete(TET *tet) {
    TET_delete(tet);
}

int _TET_open_document(TET *tet, const char *filename, int len, const char *optlist) {
    TET_TRY(tet) { return TET_open_document(tet, filename, len, optlist); } TET_CATCH(tet) {} return -1;
}

void _TET_close_document(TET *tet, int doc) {
    TET_TRY(tet) { TET_close_document(tet, doc); } TET_CATCH(tet) {}
}

int _TET_open_page( TET *tet, int doc, int pagenumber, const char *optlist) {
    TET_TRY(tet) { return TET_open_page(tet, doc, pagenumber, optlist); } TET_CATCH(tet) {} return -1;
}

void _TET_close_page(TET *tet, int page) {
    TET_TRY(tet) { TET_close_page(tet, page); } TET_CATCH(tet) {}
}

void _TET_set_option(TET *tet, const char *optlist) {
    TET_TRY(tet) { TET_set_option(tet, optlist); } TET_CATCH(tet) {}
}

double _TET_pcos_get_number(TET *tet, int doc, const char *path) {
    TET_TRY(tet) { return TET_pcos_get_number(tet, doc, path); } TET_CATCH(tet) {} return -1;
}

const char * _TET_get_text(TET *tet, int page, int *len) {
    TET_TRY(tet) { return TET_get_text(tet, page, len); } TET_CATCH(tet) {} return "";
}

const char * _TET_get_errmsg(TET *tet) {
    TET_TRY(tet) { return TET_get_errmsg(tet); } TET_CATCH(tet) {} return "";
}

int _TET_get_errnum(TET *tet) {
    TET_TRY(tet) { return TET_get_errnum(tet); } TET_CATCH(tet) {} return -1;
}

const char * _TET_get_apiname(TET *tet) {
    TET_TRY(tet) { return TET_get_apiname(tet); } TET_CATCH(tet) {} return "";
}

