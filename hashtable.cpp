#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

struct Data
  {
    int cap;
    string geo;
    string tipo;
  };

string Dato_a_buscar();

int main() 
 {
    unordered_map<string, Data> tabla;
    tabla["GPS0"] = {0, "GPS0", "ab"};
    tabla["GPS1"] = {1, "GPS1", "bc"};
    tabla["GPS2"] = {2, "GPS2", "ac"};
    tabla["GPS3"] = {3, "GPS3", "bcd"};
    tabla["GPS4"] = {4, "GPS4", "acd"};
    tabla["GPS5"] = {5, "GPS5", "bct"};
    tabla["GPS6"] = {6, "GPS6", "act"};
    tabla["GPS7"] = {7, "GPS7", "aaabbct"};
    tabla["GPS8"] = {8, "GPS8", "abbccdt"};
    tabla["GPS9"] = {9, "GPS9", "aaabbcd"};

    string clave = Dato_a_buscar();
    if (tabla.find(clave) != tabla.end()) 
    {
        cout << "Encontrado: " << clave << endl;
        cout << "Capacidad: " << tabla[clave].cap << endl;
        cout << "Geolocalización: " << tabla[clave].geo << endl;
        cout << "Tipo de arsenal: " << tabla[clave].tipo << endl;

    } else 
    {
        cout << "No encontrado: " << clave << endl;
    }

    return 0;
}

string Dato_a_buscar()
 {
    string paso;
    cout << "Ingrese el dato que busca: ";
    cin >> paso;
    return paso;
 }