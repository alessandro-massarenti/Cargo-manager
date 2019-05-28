//============================================================================
// Name        : cargo.cpp
// Author      : Alessandro and Manuele (ma Manuele is better)
// Version     : 1.1.0
// Copyright   : mit
// Description :
//============================================================================

#include <iostream>

using namespace std;

struct nodo {
    int id = 0;
    int altezza;
    int larghezza;
    int profondita;
    int peso;
    long long volume;
    nodo *next;

    nodo(int a, int b, int c, int d, int e, nodo *f = 0) {
        id = a;
        altezza = b;
        larghezza = c;
        profondita = d;
        peso = e;
        volume = a * b * c;
        next = f;
    }

};

void insertList(nodo *&list, int altezza, int larghezza, int profondita, int peso) {
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



void insertBox(nodo *&list, int max_a, int max_l, int max_pro, int max_pe) {
    int altezza, larghezza, profondita, peso;
    cout << "\naltezza:";
    cin >> altezza;
    if (altezza == -1) {
        return;
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
            error = " larghezza ttroppo larga";
    else
        error = "Altezza troppo alta";
    if (error != " ")
        cout << error;
    else
        cout << "scatola inserita";
    insertBox(list, max_a, max_l, max_pro, max_pe);
}

void displayBox(nodo *list) {
    if (!list)
        return;
    cout << list->id;
    displayBox(list->next);
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

    //bool Spazio[altezza][profondita][larghezza];

    cout << "\nOk ora iniziamo ad inserire i pacchi:" << endl;

    nodo *listascatole = NULL;
    insertBox(listascatole, altezza, larghezza, profondita, peso);
    cout << "ok, hai inserito tutti i pacchi nel sistema";

    if (!listascatole)
        cout << "\nil box era vuoto";
    else
        displayBox(listascatole);
}
