#ifndef PRODUS_H
#define PRODUS_H

#include <iostream>
#include <cstring>
#include <fstream>

class Produs {
    const int id;           // Cod unic al produsului
    char denumire[50];      // Denumirea produsului (șir de caractere)
    float pret;             // Prețul produsului
    int cantitate;          // Cantitatea pe stoc a produsului
    static int urm_id;

public:
    Produs();
    Produs(const int& id, const char* denumire, const float& pret, const int& cantitate);
    Produs(const Produs& produs);
    Produs& operator=(const Produs& produs);

    const int getId() const;
    const char *getDenumire() const;
    float getPret() const;
    int getCantitate() const;

    void setDenumire(const char* denumire);
    void setPret(const float& pret);
    void setCantitate(const int& cantitate);

    void creare_stoc(int& nr, Produs* &stoc, char *fisier);

    friend std::istream& operator>>(std::istream& in, Produs& produs);
    friend std::ostream& operator<<(std::ostream& out, const Produs& produs);

    void afisare_stoc(int nr, Produs *stoc);
};

#endif
