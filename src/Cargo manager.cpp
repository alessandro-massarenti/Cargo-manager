//============================================================================
// Name        : cargo.cpp
// Author      : Alessandro and Manuele (ma Manuele is better)
// Version     : 1.1.0
// Copyright   : mit
// Description :
//============================================================================

#include <iostream>

#include "lista-rating.h"
#include "lista-scatole.h"

using namespace std;

void insertBox(nodo *&list, int max_a, int max_l, int max_pro, int max_pe) {
	int altezza, larghezza, profondita, peso;
	cout << "\naltezza:";
	cin >> altezza;
	if (altezza == -1) {
		return;                                                                                                                                                                                               00
	}
	string error = " ";
	cout << "\nlarghezza:";
	cin >> larghezza;
	cout << "\nprofondità:";
	cin >> profondita;
	cout << "\npeso:";
	cin >> peso;
	if (altezza <= max_a)
		if (larghezza <= max_l)
			if (profondita <= max_pro)
				if (peso <= max_pe) {
					insertList(list, altezza, larghezza, profondita, peso);

				} else
					error = "peso troppo alto";
			else
				error = "profondita troppo profonda";
		else
			error = " larghezza troppo larga";
	else
		error = "Altezza troppo alta";
	if (error != " ")
		cout << error;
	else
		cout << "scatola inserita";
	insertBox(list, max_a, max_l, max_pro, max_pe);
}


int main() {

	cout << "Ok dammi le dimensioni del cargo che lo riempiamo";
	int altezza, larghezza, profondita, peso;
	cout << "\naltezza:";
	cin >> altezza;
	cout << "\nlarghezza:";
	cin >> larghezza;
	cout << "\nprofondita:";
	cin >> profondita;
	cout << "\npeso:";
	cin >> peso;

	cout << "\nOk ora iniziamo ad inserire i pacchi:" << endl;

	nodo *listascatole = NULL;
	insertBox(listascatole, altezza, larghezza, profondita, peso);
	cout << "ok, hai inserito tutti i pacchi nel sistema";

	if (!listascatole)
		cout << "\nil box era vuoto";
	else
		displayBox(listascatole);
}
