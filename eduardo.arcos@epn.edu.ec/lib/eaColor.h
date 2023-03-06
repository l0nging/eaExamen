#include <iostream>

//Librería para practicar y entender colores
void eaHw()
{
    std::cout << "\033[1;41;37mHola, mundo!\033[0m" << std::endl; // texto rojo brillante
    std::cout << "\033[1;42;37mHola, mundo!\033[0m" << std::endl; // texto verde brillante
    std::cout << "\033[1;44;37mHola, mundo!\033[0m" << std::endl; // texto azul brillante
    
}

void eaPc()
{
    const char *const verde = "\033[0;40;32m";
    const char *const subrayado_azul_verde = "\033[4;44;32m";
    const char *const normal = "\033[0m";

    std::cout << "Mostrando %scolores%s !!!\n" << verde << normal << std::endl;
    std::cout << "Mostrando %scolores%s !!!\n" << subrayado_azul_verde << normal << std::endl;

}

