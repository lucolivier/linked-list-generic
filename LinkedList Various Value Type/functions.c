//
//  functions.c
//  11-4-LinkedList
//
//  Created by Luc-Olivier on 2/21/16.
//  Copyright © 2016 Luc-Olivier. All rights reserved.
//

#include "functions.h"

ll_various_t *ll_various_newlist() {
	ll_various_t *llist = malloc(sizeof(ll_various_t));
	if (llist != NULL) {
		llist->item = NULL;
		llist->next = NULL;
		llist->status = -1;
	}
	return llist;
}

int ll_various_additem(ll_various_t *llist, int pos, char *label, various_container_t value, various_types value_type) {
	
	//pos: -1 start, -2 end, x idx
	
	if (pos>llist->status) return 1;
	if (pos==llist->status) pos=-2;
	
	ll_various_t *new = malloc(sizeof(ll_various_t));
	if (new == NULL) return 2;
	
	new->next = NULL;
	
	new->item = malloc(sizeof(various_data_t));
	if (new->item == NULL) return 3;
	
	new->item->label = malloc(128);
	if (new->item->label == NULL) return 4;
	strcpy(new->item->label, label);
	
	new->item->value = malloc(sizeof(various_container_t));
	if (new->item->value == NULL) return 5;
	new->item->type = value_type;
	various_container_t *val = new->item->value;
	
	switch (value_type) {
		case cint:		val->cint =		value.cint;		break;
		case clong:		val->clong =	value.clong;	break;
		case cfloat:	val->cfloat =	value.cfloat;	break;
		case cdouble:	val->cdouble =	value.cdouble;	break;
		case cchar:		val->cchar =	value.cchar;	break;
		case cstring:
			val->cstring = malloc(128);
			if (val->cstring == NULL) return 6;
			strcpy(val->cstring, value.cstring);		break;
		default: break;
	}
	
	ll_various_t *ptr = llist;
	
	if (pos == -2) { // END
		while (ptr->next != NULL) {
			ptr = ptr->next;
		}
		ptr->next = new;
	} else {
		if (pos != -1) {
			for (int i=0; i<=pos; i++) {
				ptr = ptr->next;
			}
		}
		ll_various_t *oldnext = ptr->next;
		ptr->next = new;
		ptr->next->next = oldnext;
	}
	
	llist->status++;
	
	return 0;
}

int ll_various_newitem(ll_various_t *llist, char *label, various_container_t value, various_types type) {
	return ll_various_additem(llist, -2, label, value, type);
}

void ll_various_printall(ll_various_t *llist) {
	ll_various_t *ptr = llist;
	char str[128];
	int cpt=0;
	do {
		ptr = ptr->next;
		ll_various_value2string(str,ptr->item->value, ptr->item->type);
		printf("%i >%s: %s\n", cpt, ptr->item->label, str);
		cpt++;
	} while (ptr->next != NULL);
}

int ll_various_printn(ll_various_t *llist, int idx) {
	if ((llist->status==-1) || (idx > llist->status)) {
		return 1;
	}
	ll_various_t *ptr = llist;
	int cpt=0;
	do {
		ptr = ptr->next;
		if (cpt == idx) {
			char str[128];
			ll_various_value2string(str,ptr->item->value, ptr->item->type);
			printf("%i >%s: %s\n", cpt, ptr->item->label, str);
			return 0;
		}
		cpt++;
	} while (ptr->next != NULL);
	return 1;
}

void ll_various_value2string(char *string, various_container_t *value, various_types type) {
	switch (type) {
		case cint:		sprintf(string, "%i", value->cint);			break;
		case clong:		sprintf(string, "%li", value->clong);		break;
		case cfloat:	sprintf(string, "%.5f", value->cfloat);		break;
		case cdouble:	sprintf(string, "%.10f", value->cdouble);	break;
		case cchar:		sprintf(string, "%c", value->cchar);		break;
		case cstring:	sprintf(string, "%s", value->cstring);		break;
		default: break;
	}
}

int ll_various_delitem(ll_various_t *llist, int pos) {
	
	//pos: -1 start, -2 end, x idx
	
	if (pos == -1) {
		pos = 0;
	} else if (pos == -2) {
		pos = llist->status;
	}
	
	ll_various_t *ptr = llist;
	
	for (int i=0; i<pos; i++) {
		ptr = ptr->next;
	}
	
	ll_various_t *farnext = ptr->next->next;
	free(ptr->next);
	if (pos != llist->status) {
		ptr->next = farnext;
	} else {
		ptr->next = NULL;
	}
	
	llist->status--;
	
	return 0;
}


