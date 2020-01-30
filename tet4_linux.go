// +build tetlib4
// +build cgo
// +build linux

package tetlib

// #cgo CFLAGS: -Iinclude
// #cgo LDFLAGS: -L${SRCDIR}/lib -ltet4-linux -lm
import "C"
