#include "Comanda.h"

Comanda::Comanda()
{
    id=0;
    zi=luna=an=nrProduse=0;
    produse=nullptr;
}
Comanda::Comanda(const int& id, const int& zi, const int& luna, const int& an, const int& nrProduse, const Produs *produse)
{
    this->id=id;
    this->zi=zi;
    this->luna=luna;
    this->an=an;
    this->nrProduse=nrProduse;

    this->produse=new Produs[nrProduse];
    for(int i=0; i<nrProduse; i++)
        this->produse[i]=produse[i];
}
Comanda::~Comanda()
{
    delete[] produse;
}
int Comanda::getId() const
{
    return id;
}
void Comanda::setId(const int& id)
{
    this->id=id;
}

void Comanda::eliminare(Comanda &comanda, const int nr, Produs* stoc)
{
    int cantitate;
    for(int i=0; i<comanda.nrProduse; i++)
    {
        for(int j=0; j<nr; j++)
            if(strcmp(comanda.produse[i].getDenumire(), stoc[j].getDenumire())==0)
            {
                cantitate=stoc[j].getCantitate()-comanda.produse[i].getCantitate();
                stoc[j].setCantitate(cantitate);
                comanda.produse[i].setPret(stoc[j].getPret());
                break;
            }
    }
}

std::ostream& operator<<(std::ostream& out, const Comanda &comanda)
{
    out<<"Comanda ID: "<<comanda.id<<"\n";
    out<<"Data comenzii: "<<comanda.zi<<"/"<<comanda.luna<<"/"<<comanda.an<<"\nProduse comandate:\n";
    float s=0;
    for(int i=0; i<comanda.nrProduse; i++)
    {
        out<<comanda.produse[i].getCantitate()<<" X "<<comanda.produse[i].getDenumire()<<" ("<<comanda.produse[i].getPret()<<")\n";
        s=s+comanda.produse[i].getCantitate()*comanda.produse[i].getPret();
    }
    out<<"Total comanda: "<<s<<" RON";
    return out;
}

std::istream& operator>>(std::istream& in, Comanda& comanda)
{
    char denumire[50];
    int cantitate;
    in>>comanda.zi>>comanda.luna>>comanda.an>>comanda.nrProduse;
    comanda.produse=new Produs[comanda.nrProduse];
    for(int i=0; i<comanda.nrProduse; i++)
    {
        in>>denumire>>cantitate;
        comanda.produse[i].setDenumire(denumire);
        comanda.produse[i].setCantitate(cantitate);
    }
    return in;
}
