/*
 * lista-scatole.cpp
 *
 *  Created on: May 29, 2019
 *      Author: amassare
 */

#include <iostream>
#include "lista-scatole.h"
using namespace std;

int idmax(nodo* list) {
	if (!list)
		return 0;
	int max = idmax(list->next);
	if (max < list->id)
		max = list->id;
	return max;
}
int altmax(nodo* list) {
	if (!list)
		return 0;
	int max = altmax(list->next);
	if (max < list->altezza)
		max = list->altezza;
	return max;
}
int larmax(nodo* list) {
	if (!list)
		return 0;
	int max = larmax(list->next);
	if (max < list->larghezza)
		max = list->larghezza;
	return max;
}
int promax(nodo* list) {
	if (!list)
		return 0;
	int max = promax(list->next);
	if (max < list->profondita)
		max = list->profondita;
	return max;
}
int pesmax(nodo* list) {
	if (!list)
		return 0;
	int max = pesmax(list->next);
	if (max < list->peso)
		max = list->peso;
	return max;
}

void insertList(nodo *&list, int id, int altezza, int larghezza, int profondita,
		int peso) {
	if (!list)
		list = new nodo(id, altezza, larghezza, profondita, peso);
	else
		insertList(list->next, id, altezza, larghezza, profondita, peso);
}
// Post : e' stato inserito un elemento a fine lista

void displayBox(nodo *list) {
	if (!list)
		return;
	cout << list->id;
	displayBox(list->next);
}
