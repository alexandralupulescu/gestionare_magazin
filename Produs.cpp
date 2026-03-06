#include "Produs.h"
int Produs::urm_id=0; //variabila statica pentru a initializa fiecare id cu un nr unic

Produs::Produs(): id(urm_id++), pret(0.0f), cantitate(0)
{
    strcpy(denumire, "necunoscut");
}
Produs::Produs(const int& id, const char* denumire, const float& pret, const int &cantitate): id(urm_id++)
{
    strcpy(this->denumire, denumire);
    this->pret=pret;
    this->cantitate=cantitate;
}
Produs::Produs(const Produs& produs): id(produs.id)
{
    strcpy(denumire, produs.denumire);
    pret=produs.pret;
    cantitate=produs.cantitate;
}
Produs& Produs::operator=(const Produs& produs)
{
    if(this==&produs)
        return *this;
    strcpy(denumire, produs.denumire);
    pret=produs.pret;
    cantitate=produs.cantitate;
    return *this;
}

const int Produs::getId() const
{
    return id;
}
const char* Produs::getDenumire() const
{
    return denumire;
}
float Produs::getPret() const
{
    return pret;
}
int Produs::getCantitate() const
{
    return cantitate;
}

void Produs::setDenumire(const char* denumire)
{
    strcpy(this->denumire, denumire);
}
void Produs::setPret(const float& pret)
{
    this->pret=pret;
}
void Produs::setCantitate(const int& cantitate)
{
    this->cantitate=cantitate;
}

void Produs::creare_stoc(int& nr, Produs* &stoc, char *fisier)
{
    std::ifstream fisier_produse(fisier);
    nr=0;
    fisier_produse>>nr;
    stoc = new Produs[nr];
    for(int i=0; i<nr; i++)
        fisier_produse>>stoc[i];
    fisier_produse.close();
}

std::istream& operator>>(std::istream& in, Produs& produs)
{
    in>>produs.denumire>>produs.pret>>produs.cantitate;
    return in;
}
std::ostream& operator<<(std::ostream& out, const Produs& produs)
{
	out<<produs.denumire<<": "<<produs.cantitate<<", Pret: "<<produs.pret;
	return out;
}
void Produs::afisare_stoc(int nr, Produs *stoc)
{
    std::ofstream fisier_stoc("output_stoc_ramas.txt");
    fisier_stoc<<"Stoc ramas";
    if(nr!=0)
        fisier_stoc<<"\n";
    for(int i=0; i<nr; i++)
    {
        fisier_stoc<<i<<". "<<stoc[i];
        if(i!=nr-1)
            fisier_stoc<<"\n";
    }
    fisier_stoc.close();
}
