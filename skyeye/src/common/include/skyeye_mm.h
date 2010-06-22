#ifndef __SKYEYE_MM_H__
#define __SKYEYE_MM_H__
#include <stdlib.h>
void* skyeye_mm(size_t sz);
void* skyeye_mm_zero(size_t sz);
char* skyeye_strdup(const char* s);
void skyeye_free(void *p);
#endif
