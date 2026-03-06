#include <iostream>
#include "Produs.h"
#include <fstream>
#include "Comanda.h"
#include "Client.h"

int main(int argc, char* argv[])
{
    std::cout << argv[1] << std::endl;
    std::cout << argv[2] << std::endl;
    int nr;
    Produs *stoc, p;
    p.creare_stoc(nr, stoc, argv[1]);

    Client client;
    client.modificare(nr, stoc, argv[2]);

    p.afisare_stoc(nr, stoc);

    delete[] stoc;

    return 0;
}
