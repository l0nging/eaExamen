#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string>
//#include <windows.h>
#include <unordered_set>
#include <queue>
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

eaNodo* eaInsertarnodo(eaNodo* eaRaiz, int eaCap, char eaGeo, string eaTipo) {

    if (eaRaiz == nullptr) 
    {
        eaRaiz = new eaNodo;
        eaRaiz->eaCap = eaCap;
        *eaRaiz->eaGeo = eaGeo;
        eaRaiz->eaTipo = eaTipo;
        eaRaiz->izquierda = nullptr;
        eaRaiz->derecha = nullptr;
    }
    else if (eaCap < eaRaiz->eaCap) 
    {
        eaRaiz->izquierda = eaInsertarnodo(eaRaiz->izquierda, eaCap, eaGeo, eaTipo);
    }
    else if (eaCap > eaRaiz->eaCap) 
    {
        eaRaiz->derecha = eaInsertarnodo(eaRaiz->derecha, eaCap, eaGeo, eaTipo);
    }
    return eaRaiz;
}

void eaEliminarduplicados(eaNodo* eaRaiz) 
{
    if (eaRaiz == nullptr) {
        return;
    }

    unordered_set<int> visited;
    queue<eaNodo*> q;
    visited.insert(eaRaiz->eaCap);
    q.push(eaRaiz);

    while (!q.empty()) {
        eaNodo* curr = q.front();
        q.pop();

        if (curr->izquierda != nullptr) {
            if (visited.find(curr->izquierda->eaCap) != visited.end()) {
                curr->izquierda = nullptr;
            } else {
                visited.insert(curr->izquierda->eaCap);
                q.push(curr->izquierda);
            }
        }

        if (curr->derecha != nullptr) {
            if (visited.find(curr->derecha->eaCap) != visited.end()) {
                curr->derecha = nullptr;
            } else {
                visited.insert(curr->derecha->eaCap);
                q.push(curr->derecha);
            }
        }
    }
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
    if (eaRaiz == nullptr) 
    {
        return;
    }
    eaMostrarorden(eaRaiz->izquierda);
    cout << eaRaiz->eaCap << " " << eaRaiz->eaGeo << " " << eaRaiz->eaTipo << endl;
    eaMostrarorden(eaRaiz->derecha);
}


void eaMostrar()
{
    ifstream archivo;
    archivo.open("coordenadas.txt");

    if (archivo.is_open()) 
    {
        string linea;
        cout << "Leyendo coordenadas... " << endl;
        while (getline(archivo, linea)) 
        {
            cout << linea << endl;
        }
        archivo.close();
    } 
    else 
    {
        cout << "Error al abrir el archivo" << endl;
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
    //eaMostrar();
    eaNodo* eaRaiz = eaCreararbol("coordenadas.txt");
    eaEliminarduplicados(eaRaiz);
    eaMostrarorden(eaRaiz);



    return 0;
}