#ifndef CARYLL_INCLUDE_VECTOR_H
#define CARYLL_INCLUDE_VECTOR_H

#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "element.h"

// We assume all T have trivial move constructors.
#define caryll_Vector(T)                                                                                               \
	struct {                                                                                                           \
		size_t length;                                                                                                 \
		size_t capacity;                                                                                               \
		T *items;                                                                                                      \
	}
#define caryll_VectorInterfaceTypeName(__TV) const struct __caryll_vectorinterface_##__TV
#define caryll_VectorInterfaceTrait(__TV, __T)                                                                         \
	caryll_RT(__TV);                                                                                                   \
	void (*initN)(MODIFY __TV * arr, size_t n);                                                                        \
	__TV *(*createN)(size_t n);                                                                                        \
	void (*clear)(MODIFY __TV * arr);                                                                                  \
	void (*replace)(MODIFY __TV * dst, MOVE const __TV *src);                                                          \
	void (*push)(MODIFY __TV * arr, MOVE __T obj);                                                                     \
	__T (*pop)(MODIFY __TV * arr);                                                                                     \
	void (*fill)(MODIFY __TV * arr, size_t n);                                                                         \
	void (*disposeItem)(MODIFY __TV * arr, size_t n);                                                                  \
	void (*sort)(MODIFY __TV * arr, int (*fn)(const __T *a, const __T *b));

#define caryll_VectorInterface(__TV, __T)                                                                              \
	caryll_VectorInterfaceTypeName(__TV) {                                                                             \
		caryll_VectorInterfaceTrait(__TV, __T);                                                                        \
	}

#endif
