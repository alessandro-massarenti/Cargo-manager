/*
 * lista-scatole.cpp
 *
 *  Created on: May 29, 2019
 *      Author: amassare
 */

#include <iostream>
#include "lista-scatole.h"
using namespace std;
int idmax(nodo* list,int max=0){
	    	if(!list)
	    		return max;
	    	if(max<list->id)
	    		max=list->id;
	    	return idmax(list->next,max);
}
void insertList(nodo *&list,int id, int altezza, int larghezza, int profondita, int peso) {
	if(!list)
	list=new nodo(id, altezza, larghezza, profondita, peso);
	else
		insertList(list->next,id,altezza, larghezza, profondita, peso);
}
void displayBox(nodo *list) {
	if (!list)
		return;
	cout << list->id;
	displayBox(list->next);
}

