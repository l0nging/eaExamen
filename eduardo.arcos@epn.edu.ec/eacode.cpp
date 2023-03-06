#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <string>
//#include <windows.h>
#include "./lib/eaColor.h"
using namespace std;

const string EANOMBRE_COMPLETO = "Eduardo Emmanuel Arcos Constante";
const int CEDULA = 1722208525;

struct eaNodo {
    int eaCap;
    char eaGeo[4];
    string eaTipo;
    eaNodo* izquierda;
    eaNodo* derecha;
};

eaNodo* eaInsertarnodo(eaNodo* eaRaiz, int eaCap, char eaGeo, string eaTipo) 
{
    if (eaRaiz== NULL) {
        eaRaiz = new eaNodo;
        eaRaiz->eaCap = eaCap;
        *eaRaiz->eaGeo = eaGeo;
        eaRaiz->eaTipo = eaTipo;
        eaRaiz->izquierda = NULL;
        eaRaiz->derecha = NULL;
    }
    else if (eaCap < eaRaiz->eaCap) {
        eaRaiz->izquierda = eaInsertarnodo(eaRaiz->izquierda, eaCap, eaGeo, eaTipo);
    }
    // Si el valor del nodo es mayor que la raíz, insertarlo en el subárbol derecho
    else if ( eaCap > eaRaiz->eaCap) {
        eaRaiz->derecha = eaInsertarnodo(eaRaiz->derecha, eaCap, eaGeo, eaTipo);
    }
    // Si el valor del nodo es igual que la raíz, no se inserta (se descarta)
    return eaRaiz;
}

eaNodo* eaCreararbol(string filename) 
{
    ifstream infile(filename);
    if (!infile) 
    {
        cerr << "No se pudo abrir el archivo" << endl;
        exit(1);
    }
    eaNodo* eaRaiz = NULL;
    int num;
    char letra;
    string cadena;
    while (infile >> num >> letra >> cadena) 
    {
        eaRaiz = eaInsertarnodo(eaRaiz, num, letra, cadena);
    }
    infile.close();
    return eaRaiz;
}

void eaMostrarorden(eaNodo* eaRaiz) 
{
    if (eaRaiz != NULL) {
        eaMostrarorden(eaRaiz->izquierda);
        cout << eaRaiz->eaCap << " " << eaRaiz->eaGeo << " " << eaRaiz->eaTipo << endl;
        eaMostrarorden(eaRaiz->derecha);
    }
}

void eaLiberarArbol(eaNodo* eaRaiz) {
    if (eaRaiz != nullptr) {
        eaLiberarArbol(eaRaiz->izquierda);
        eaLiberarArbol(eaRaiz->derecha);
        delete eaRaiz;
    }
}

int main() 
{
    eaNodo* eaRaiz = eaCreararbol("coordenadas.txt");
    eaMostrarorden(eaRaiz);
    

    return 0;
}