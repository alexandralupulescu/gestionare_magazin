#ifndef CLIENT_H
#define CLIENT_H

#include "Comanda.h"

class Client {
private:
    char nume[60];  // Numele clientului
    Comanda comanda; //comanda clientului

public:
    Client();
    Client(const char *nume, const Comanda& comanda);

    void modificare(const int nr, Produs* stoc, char *fisier2);

    friend std::istream& operator>>(std::istream& in, Client& client);
};

#endif
