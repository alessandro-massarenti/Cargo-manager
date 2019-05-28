//============================================================================
// Name        : CargoManager
// Author      : Alessandro and Manuele (ma Manuele is better)
// Version     : 1.0
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
    int volume;
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
    cout << max_id;
    cout << "cacca";
    if (!list->next) {
        list->next = new nodo(max_id + 1, altezza, larghezza, profondita, peso);
        return;
    }
    insertList(list->next, altezza, larghezza, profondita, peso);


}
// Post : e' stato inserito un elemento a fine lista



void insertBox(nodo *&list, int max_a, int max_l, int max_pro, int max_pe) {
    int altezza, larghezza, profondita, peso;
    cin >> altezza;
    if (altezza == -1) {
        return;
    }
    string error = " ";
    cin >> larghezza >> profondita >> peso;
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
    /*displayBox(tree->right);
    cout << tree->altezza << endl;
    displayBox(tree->left);*/

}

/*
 *
 * nodo* insertBox(nodo* tree, int id, int altezza, int larghezza, int profondita,
 int peso) {
 if (!tree)
 return new nodo(id, altezza, larghezza, profondita, peso);
 int volume = altezza * larghezza * profondita;
 if (volume < tree->altezza)
 tree->left = insertBox(tree->left, id, altezza, larghezza, profondita,
 peso);
 else
 tree->right = insertBox(tree->right, id, altezza, larghezza, profondita,
 peso);
 return tree;
 }


 nodo* cercaPiuAlto(nodo* tree) {
 nodo* max = 0;
 if (!tree)
 return 0;
 displayBox(tree->right);
 if (cercaPiuAlto(tree) > max){
 max = cercaPiuAlto(tree);
 }


 displayBox(tree->left);
 }

 int insert(nodo* & tree, int a, int b, int c, int d, int id = 0) {
 cout << "Nuova scatola:";
 int altezza;
 cin >> altezza;
 if (altezza != -1) {
 int larghezza, profondita, peso;
 cin >> larghezza >> profondita >> peso;
 if (altezza < a)
 if (larghezza < b)
 if (profondita < c)
 if (peso < d) {
 tree = insertBox(tree, id, altezza, larghezza,
 profondita, peso);

 } else
 cout << "peso eccessivo" << endl;
 else
 cout << "profondita eccessiva" << endl;
 else
 cout << "larghezza eccessiva" << endl;
 else
 cout << "altezza eccessiva" << endl;
 insert(tree, a, b, c, d, id + 1);
 }
 return id;
 }


 */

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

    bool Spazio[altezza][profondita][larghezza];

    cout << "\nOk ora iniziamo ad inserire i pacchi:" << endl;

    nodo *listascatole = NULL;
    insertBox(listascatole, altezza, larghezza, profondita, peso);
    cout << "ok, hai inserito tutti i pacchi nel sistema";

    if (!listascatole)
        cout << "\nil box era vuoto";
    else
        displayBox(listascatole);
}
