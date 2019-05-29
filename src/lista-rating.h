/*
 * lista-rating.h
 *
 *  Created on: May 29, 2019
 *      Author: amassare
 */

#ifndef LISTA_RATING_H_
#define LISTA_RATING_H_

struct rating {
	int id;
	int value;
	rating* next;
	rating(int a = 0, int b = 0, rating* c = 0) {
		id = a;
		value = b;
		next = c;
	}
};


#endif /* LISTA_RATING_H_ */
