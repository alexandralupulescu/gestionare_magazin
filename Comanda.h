#ifndef COMANDA_H
#define COMANDA_H

#include "Produs.h"

class Comanda {
protected:
    int id;
    int zi, luna, an;             // Data comenzii
    int nrProduse;                // Numarul total de produse din comanda
    Produs* produse;              // Vector alocat dinamic pentru produsele din comanda

public:
    Comanda();
    Comanda(const int& id, const int& zi, const int& luna, const int& an, const int& nrProduse, const Produs *produse);
    ~Comanda();

    int getId() const;
    void setId(const int& id);

    void eliminare(Comanda &comanda, const int nr, Produs* stoc);

    friend std::ostream& operator<<(std::ostream& out, const Comanda &comanda);
    friend std::istream& operator>>(std::istream& in, Comanda& comanda);
};

#endif
