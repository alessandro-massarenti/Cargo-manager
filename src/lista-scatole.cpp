/*
 * lista-scatole.cpp
 *
 *  Created on: May 29, 2019
 *      Author: amassare
 */

#include <iostream>
#include "lista-scatole.h"
using namespace std;


void insertList(nodo *&list, int altezza, int larghezza, int profondita,int peso) {
	if (!list) {
		list = new nodo(0, altezza, larghezza, profondita, peso);
		return;
	}
	int max_id = 0;
	if (list->id > max_id)
		max_id = list->id;
	if (!list->next) {
		list->next = new nodo(max_id + 1, altezza, larghezza, profondita, peso);
		return;
	}
	insertList(list->next, altezza, larghezza, profondita, peso);

}
// Post : e' stato inserito un elemento a fine lista


void displayBox(nodo *list) {
	if (!list)
		return;
	cout << list->id;
	displayBox(list->next);
}

