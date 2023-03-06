#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string>
#include <windows.h>
#include <unordered_set>
#include <queue>
#include "./lib/eaColor.h"
using namespace std;

const string EANOMBRE_COMPLETO = "Eduardo Emmanuel Arcos Constante";
const int CEDULA = 1722208525;

struct eaNodo {
    int eaCap;
    char eaGeo[3];
    string eaTipo;
    eaNodo* izquierda;
    eaNodo* derecha;
};

eaNodo* eaInsertarnodo(eaNodo* eaRaiz, int eaCap, char eaGeo, string eaTipo) {

    if (eaRaiz == nullptr) 
    {
        eaRaiz = new eaNodo;
        eaRaiz->eaCap = eaCap;
        eaRaiz->eaGeo[0] = eaGeo;
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
    archivo.open("newcoordenadas.txt");

    if (archivo.is_open()) 
    {
        string linea;
        cout << "\033[0;32mLeyendo coordenadas... \033[0m" << endl;
        cout << "\033[1;31m>>Error: Cap, Geo, Tipo Arsenal ->stoi\033[0m" << endl;

        while (getline(archivo, linea)) 
        {
            string eaCharge = "\\|/-";
            for (int i = 0; i < 100; i++)
            {
                cout << eaCharge[i]<<i<<'%'<<"\b\b\b\b";
                Sleep(5);
            }
            cout << "\033[0;32m" << linea << "\033[0m" << endl;
        }
        archivo.close();
    } 
    else 
    {
        cout << "Error al abrir el archivo" << endl;
    }
}

void eliminarDuplicados(string archivoEntrada, string archivoSalida) {
    ifstream infile(archivoEntrada);
    if (!infile) {
        cerr << "No se pudo abrir el archivo de entrada" << endl;
        exit(1);
    }

    ofstream outfile(archivoSalida);
    if (!outfile) {
        cerr << "No se pudo abrir el archivo de salida" << endl;
        exit(1);
    }

    unordered_set<string> lineasUnicas;
    string linea;

    while (getline(infile, linea)) {
        if (lineasUnicas.find(linea) == lineasUnicas.end()) {
            lineasUnicas.insert(linea);
            outfile << linea << endl;
        }
    }

    infile.close();
    outfile.close();

    cout << "Se eliminaron las coordenadas duplicadas " << endl;

}

/*void eaMostrar_dos()
{



}*/

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
    eaEliminarduplicados(eaRaiz);
    eliminarDuplicados("coordenadas.txt", "newcoordenadas.txt");
    eaMostrar();
    //eaMostrar_dos();
    
    return 0;
}

