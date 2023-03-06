#include <windows.h>
#include <iostream>

using namespace std;

int main()
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

/*int main()
{
    
    while (true)
    {
        Sleep(1);
        std::cout << "." << std::flush;
        Sleep(1);
        std::cout << "." << std::flush;
        Sleep(1);
        std::cout << "." << std::flush;
        Sleep(1);
        std::cout << "\b\b\b   \b\b\b" << std::flush;
    }

}*/