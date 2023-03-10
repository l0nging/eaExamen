#include <iostream>

#include <unordered_map>

#include <string>

struct Data {

    int cap;

    std::string geo;

    std::string tipo;

};

int main() {

    std::unordered_map<std::string, Data> tabla;

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

    // Ejemplo de uso

    std::string key = "GPS5";

    if (tabla.find(key) != tabla.end()) {

        std::cout << "Encontrado: " << key << std::endl;

        std::cout << "Capacidad: " << tabla[key].cap << std::endl;

        std::cout << "Geolocalización: " << tabla[key].geo << std::endl;

        std::cout << "Tipo de arsenal: " << tabla[key].tipo << std::endl;

    } else {

        std::cout << "No encontrado: " << key << std::endl;

    }

    return 0;

}

