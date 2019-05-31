/*
 * lista-scatole.h
 *
 *  Created on: May 29, 2019
 *      Author: amassare
 */

#ifndef LISTA_SCATOLE_H_
#define LISTA_SCATOLE_H_


struct nodo {

	int id;
	int altezza;
	int larghezza;
	int profondita;
	int peso;
	long long volume;
	nodo *next;

	nodo(int a = 0, int b = 0, int c = 0, int d = 0, int e = 0, nodo *f = 0) {
		id = a;
		altezza = b;
		larghezza = c;
		profondita = d;
		peso = e;
		volume = a * b * c;
		next = f;
	}

};

int idmax(nodo*);
int altmax(nodo*);
int larmax(nodo*);
int promax(nodo*);
int pesmax(nodo*);
void insertList(nodo*&,int, int, int, int,int);
void displayBox(nodo*);



#endif /* LISTA_SCATOLE_H_ */
