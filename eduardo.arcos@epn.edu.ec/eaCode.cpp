#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <windows.h>
#include <./lib/eaColor.h>
using namespace std;

const string EANOMBRE_COMPLETO = "Eduardo Emmanuel Arcos Constante";
const int CEDULA = 1722208525;

struct eaCoordenadas 
{
    int eaCapacidad;
    char eaGeo[4];
    string eaTipo;
};

struct eaNodo 
{
    eaCoordenadas ea_coordenadas;      //se usa ea_coor para diferenciar del eaCoor anterior
    eaNodo* izquierdo;
    eaNodo* derecho;
};

eaNodo* eaInsertarcoordenadas(eaNodo* eaRaiz, eaCoordenadas ea_coordenadas) 
{
    if (eaRaiz == nullptr) 
    {
        return new eaNodo{ea_coordenadas, nullptr, nullptr};
    } 
    else if (ea_coordenadas.eaCapacidad < eaRaiz->ea_coordenadas.eaCapacidad) 
    {
        eaRaiz->izquierdo = eaInsertarcoordenadas(eaRaiz->izquierdo, ea_coordenadas);
    } 
    else 
    {
        eaRaiz->derecho = eaInsertarcoordenadas(eaRaiz->derecho, ea_coordenadas);
    }
    return eaRaiz;
}

int eaLectura()
{
    ifstream archivo("coordenadas.txt");
    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo" << endl;
        return 1;
    }

    // Leer los datos del archivo y crear un vector de ciudades
    vector<eaCoordenadas> eaCoordenadas;
    string eaLinea;
    while (getline(archivo, eaLinea)) 
    {
        stringstream ss(eaLinea);
        int eaCap;
        char eaGeo;
        getline(ss, eaCap, ',');
        ss >> eaGeo;

        // Asignar una categoría a la ciudad
        char categoria = asignarCategoria(poblacion);

        // Crear un objeto Ciudad y agregarlo 
        eaCoordenadas.push_back({eaCapacidad, eaGeo, eaTipo});
    }
}

int eaCarga()
{
    cout << '-' << flush;
    for (;;) {
        Sleep(10);
        cout << "\b\\" << flush;
        Sleep(10);
        cout << "\b|" << flush;
        Sleep(10);
        cout << "\b/" << flush;
        Sleep(10);
        cout << "\b-" << flush;
    }
    return 0;
}



int main(void)
{


}