package tetlib

// #include <stdlib.h>
// #include "golang.h"
import "C"
import (
	"errors"
	"unsafe"
)

type TETlib struct {
	val *C.TET
}

func New() *TETlib {
	tetlib := &TETlib{val: C.TET_new()}
	return tetlib
}

func (tet *TETlib) Delete() {
	C._TET_delete(tet.val)
}

func (tet *TETlib) OpenDocument(filename, options string) (int, error) {
	ret := int(C._TET_open_document(tet.val, C.CString(filename), 0, C.CString(options)))
	return ret, tet.catch()
}

func (tet *TETlib) CloseDocument(doc int) error {
	C._TET_close_document(tet.val, C.int(doc))
	return tet.catch()
}

func (tet *TETlib) OpenPage(doc int, pagenumber int, options string) (int, error) {
	ret := int(C._TET_open_page(tet.val, C.int(doc), C.int(pagenumber), C.CString(options)))
	return ret, tet.catch()
}

func (tet *TETlib) ClosePage(page int) error {
	C._TET_close_page(tet.val, C.int(page))
	return tet.catch()
}

func (tet *TETlib) SetOption(options string) error {
	C._TET_set_option(tet.val, C.CString(options))
	return tet.catch()
}

func (tet *TETlib) PcosGetNumber(doc int, path string) (int, error) {
	ret := int(C._TET_pcos_get_number(tet.val, C.int(doc), C.CString(path)))
	return ret, tet.catch()
}

func (tet *TETlib) GetText(page int, len int) (string, error) {
	ret := C.GoString(C._TET_get_text(tet.val, C.int(page), (*C.int)(unsafe.Pointer(&len))))
	return ret, tet.catch()
}

func (tet *TETlib) catch() error {
	if num := C._TET_get_errnum(tet.val); num > 0 {
		return errors.New(C.GoString(C._TET_get_errmsg(tet.val)) + " " + C.GoString(C._TET_get_apiname(tet.val)))
	}
	return nil
}
