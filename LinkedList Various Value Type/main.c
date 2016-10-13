//
//  main.c
//  11-4-LinkedList
//
//  Created by Luc-Olivier on 2/21/16.
//  Copyright © 2016 Luc-Olivier. All rights reserved.
//

#include "functions.h"

int main(int argc, const char * argv[]) {
	
	ll_various_t *lld = ll_various_newlist();
	
	ll_various_newitem(lld, "INT", (various_container_t){.cint=1}, cint);
	ll_various_newitem(lld, "LONG", (various_container_t){.clong=1234567890}, clong);
	ll_various_newitem(lld, "FLOAT", (various_container_t){.cfloat=1.12345}, cfloat);
	ll_various_newitem(lld, "DOUBLE", (various_container_t){.cdouble=15.123456789}, cdouble);
	ll_various_newitem(lld, "CHAR", (various_container_t){.cchar='C'}, cchar);
	ll_various_newitem(lld, "STRING", (various_container_t){.cstring="ABCD"}, cstring);
	
	ll_various_printall(lld);
	
	lf();
	
	for (int i=0; i<=lld->status; i++) {
		ll_various_printn(lld,i);
	}
	
	lf();
	
	ll_various_delitem(lld, -2);
	ll_various_printall(lld);
	
	lf();
	
	ll_various_delitem(lld, 2);
	ll_various_printall(lld);
	
	lf();
	
	ll_various_delitem(lld, -1);
	ll_various_printall(lld);
	
	return 0;
}
