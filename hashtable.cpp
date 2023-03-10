#include <iostream>
#include <string>
#include <unordered_map>

struct Arsenal {
    std::string tipo;
};

class GPS {
public:
    std::string cap;
    std::string geo;
    Arsenal arsenal;

    GPS(std::string cap, std::string geo, std::string tipo) {
        this->cap = cap;
        this->geo = geo;
        this->arsenal.tipo = tipo;
    }
};

// Función hash personalizada para la clase GPS
struct GPSHasher {
    std::size_t operator()(const GPS& g) const {
        std::hash<std::string> stringHasher;
        return stringHasher(g.cap + g.geo + g.arsenal.tipo);
    }
};

int main() {
    // Crear la tabla hash
    std::unordered_map<GPS, int, GPSHasher> gpsHash;

    // Poblar la tabla hash con los datos proporcionados
    gpsHash.emplace(GPS("0", "GPS0", "ab"), 0);
    gpsHash.emplace(GPS("1", "GPS1", "bc"), 1);
    gpsHash.emplace(GPS("2", "GPS2", "ac"), 2);
    gpsHash.emplace(GPS("3", "GPS3", "bcd"), 3);
    gpsHash.emplace(GPS("4", "GPS4", "acd"), 4);
    gpsHash.emplace(GPS("5", "GPS5", "bct"), 5);
    gpsHash.emplace(GPS("6", "GPS6", "act"), 6);
    gpsHash.emplace(GPS("7", "GPS7", "aaabbct"), 7);
    gpsHash.emplace(GPS("8", "GPS8", "abbccdt"), 8);
    gpsHash.emplace(GPS("9", "GPS9", "aaabbcd"), 9);

    // Imprimir los valores almacenados en la tabla hash
    for (const auto& p : gpsHash) {
        std::cout << "Key: (" << p.first.cap << ", " << p.first.geo << ", " << p.first.arsenal.tipo << ") ";
        std::cout << "Value: " << p.second << std::endl;
    }

    return 0;
}
