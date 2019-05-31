/*
 * rating.cpp
 *
 *  Created on: May 29, 2019
 *      Author: amassare
 */

#include <iostream>
#include "lista-rating.h"
using namespace std;

void insertRating(rating* &list, int id, int value) {
	if (!list) {
		list = new rating(id, value);
		return;
	}
	insertRating(list->next, id, value);
}

bool changeRating(rating*& list, int id, int value) {
	if (!list)
		return false;
	if (list->id == id)
		list->value = value;
	cout << list->id;
	return changeRating(list->next, id, value);
}
