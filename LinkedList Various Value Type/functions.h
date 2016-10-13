//
//  functions.h
//  11-4-LinkedList
//
//  Created by Luc-Olivier on 2/21/16.
//  Copyright © 2016 Luc-Olivier. All rights reserved.
//

#ifndef functions_h
#define functions_h

#define lf() printf("\n")

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#endif /* functions_h */

typedef enum {
	cint,
	clong,
	cfloat,
	cdouble,
	cchar,
	cstring
} various_types;

typedef union various_container {
	int cint;
	long clong;
	float cfloat;
	double cdouble;
	char cchar;
	char *cstring;
} various_container_t;

typedef struct various_data {
	char *label;
	various_container_t *value;
	various_types type;
} various_data_t;

typedef struct ll_various {
	various_data_t *item;
	struct ll_various *next;
	int status;
} ll_various_t;

ll_various_t *ll_various_newlist();

int ll_various_additem(ll_various_t *llist, int pos, char *label, various_container_t value, various_types value_type);

int ll_various_newitem(ll_various_t *llist, char *label, various_container_t value, various_types value_type);

void ll_various_printall(ll_various_t *llist);
void ll_various_value2string(char *string, various_container_t *value, various_types type);
int ll_various_printn(ll_various_t *llist, int idx);
int ll_various_delitem(ll_various_t *llist, int pos);



