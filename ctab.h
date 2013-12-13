#ifndef CTAB_H
#define CTAB_H

#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdarg.h>
#include <stdlib.h>

/* print table */
void printt(const char * t[], int rs, int cs);

/* construct table */
const char ** contab(int rs, const char ** headers, const char * fmt, ...);

#endif
