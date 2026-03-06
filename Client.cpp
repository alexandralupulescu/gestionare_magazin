#include "Client.h"
#include <string>

Client::Client()
{
    strcpy(nume, "necunoscut");
    comanda=Comanda();
}
Client::Client(const char *nume, const Comanda& comanda)
{
    strcpy(this->nume, nume);
    this->comanda=comanda;
}
std::istream& operator>>(std::istream& in, Client& client)
{
    char prenume[60], num[60];
    in>>prenume>>num;
    strcat(prenume, " ");
    strcat(prenume, num);
    strcpy(client.nume, prenume);

    in>>client.comanda;
    return in;

}
void Client::modificare(const int nr, Produs* stoc, char *fisier2)
{
    std::ifstream fisier_comenzi(fisier2);
    std::ofstream output_comenzi("output_comenzi.txt");
    Client client;
    int nrClienti=0;
    fisier_comenzi>>nrClienti;
    if(nrClienti==0)
        output_comenzi<<"Nu exista clienti in magazin.";
    for(int i=0; i<nrClienti; i++)
    {
        client.comanda.setId(i);
        fisier_comenzi>>client;

        client.comanda.eliminare(client.comanda, nr, stoc);
        if(i!=0)
            output_comenzi<<"\n\n";
        output_comenzi<<"Nume: "<<client.nume<<"\n";
        output_comenzi<<client.comanda;
    }
    output_comenzi.close();
    fisier_comenzi.close();
}
