#include "ObchodniCentrum.h"
#include <iostream>

using namespace std;

ObchodniCentrum::ObchodniCentrum(string nazev, int kapacitaKavovychAutomatu, int kapacitaPlechovkovychAutomatu, int kapacitaOplatkovychAutomatu)
{
    this->nazev = nazev;

    this->pocetKavovychAutomatu = 0;
    this->pocetPlechovkovychAutomatu = 0;
    this->pocetOplatkovychAutomatu = 0;

    this->kapacitaKavovychAutomatu = kapacitaKavovychAutomatu;
    this->kapacitaPlechovkovychAutomatu = kapacitaPlechovkovychAutomatu;
    this->kapacitaOplatkovychAutomatu = kapacitaOplatkovychAutomatu;

    this->kavoveAutomaty = new KavovyAutomat*[this->kapacitaKavovychAutomatu];
    this->plechovkoveAutomaty = new AutomatNaPlechovky*[this->kapacitaPlechovkovychAutomatu];
    this->oplatkoveAutomaty = new AutomatNaOplatky*[this->kapacitaOplatkovychAutomatu];

    for(int i = 0; i < this->kapacitaKavovychAutomatu; i++)
    {
        this->kavoveAutomaty[i] = nullptr;
    }

    for(int i = 0; i < this->kapacitaPlechovkovychAutomatu; i++)
    {
        this->plechovkoveAutomaty[i] = nullptr;
    }

    for (int i = 0; i < this->kapacitaOplatkovychAutomatu; i++)
    {
        this->oplatkoveAutomaty[i] = nullptr;
    }
}

ObchodniCentrum::~ObchodniCentrum() {
    for(int i = 0; i < this->pocetKavovychAutomatu; i++)
    {
        delete this->kavoveAutomaty[i];
    }

    for(int i = 0; i < this->pocetPlechovkovychAutomatu; i++)
    {
        delete this->plechovkoveAutomaty[i];
    }

    for(int i = 0; i < this->pocetOplatkovychAutomatu; i++)
    {
        delete this->oplatkoveAutomaty[i];
    }

    delete[] this->kavoveAutomaty;
    delete[] this->plechovkoveAutomaty;
    delete[] this->oplatkoveAutomaty;
}

void ObchodniCentrum::pridejAutomat(KavovyAutomat* automat)
{
    if(this->pocetKavovychAutomatu >= this->kapacitaKavovychAutomatu)
    {
        cout << "Nelze pridat dalsi kavovy automat." << endl;
        delete automat;
        return;
    }
    this->kavoveAutomaty[this->pocetKavovychAutomatu] = automat;
    this->pocetKavovychAutomatu++;
}

void ObchodniCentrum::pridejAutomat(AutomatNaPlechovky* automat)
{
    if(this->pocetPlechovkovychAutomatu >= this->kapacitaPlechovkovychAutomatu)
    {
        cout << "Nelze pridat dalsi automat na plechovky." << endl;
        delete automat;
        return;
    }
    this->plechovkoveAutomaty[this->pocetPlechovkovychAutomatu] = automat;
    this->pocetPlechovkovychAutomatu++;
}

void ObchodniCentrum::pridejAutomat(AutomatNaOplatky* automat)
{
    if(this->pocetOplatkovychAutomatu >= this->kapacitaOplatkovychAutomatu)
    {
        cout << "Nelze pridat dalsi automat na oplatky." << endl;
        delete automat;
        return;
    }
    this->oplatkoveAutomaty[this->pocetOplatkovychAutomatu] = automat;
    this->pocetOplatkovychAutomatu++;
}

KavovyAutomat* ObchodniCentrum::getKavovyAutomat(int index)
{
    if(index < 0 || index >= this->pocetKavovychAutomatu)
    {
        return nullptr;
    }
    return this->kavoveAutomaty[index];
}

AutomatNaPlechovky* ObchodniCentrum::getPlechovkovyAutomat(int index)
{
    if(index < 0 || index >= this->pocetPlechovkovychAutomatu)
    {
        return nullptr;
    }
    return this->plechovkoveAutomaty[index];
}

AutomatNaOplatky* ObchodniCentrum::getOplatkovyAutomat(int index)
{
    if(index < 0 || index >= this->pocetOplatkovychAutomatu)
    {
        return nullptr;
    }
    return this->oplatkoveAutomaty[index];
}

void ObchodniCentrum::vypisAutomaty()
{
    cout << "\n===== OBCHODNI CENTRUM: " << this->nazev << " =====" << endl;

    cout << "\nKavove automaty:" << endl;
    for(int i = 0; i < this->pocetKavovychAutomatu; i++)
    {
        cout << "- " << this->kavoveAutomaty[i]->getNazev() << endl;
    }

    cout << "\nAutomaty na plechovky:" << endl;
    for(int i = 0; i < this->pocetPlechovkovychAutomatu; i++)
    {
        cout << "- " << this->plechovkoveAutomaty[i]->getNazev() << endl;
    }

    cout << "\nAutomaty na oplatky:" << endl;
    for(int i = 0; i < this->pocetOplatkovychAutomatu; i++)
    {
        cout << "- " << this->oplatkoveAutomaty[i]->getNazev() << endl;
    }
}

void ObchodniCentrum::vypisVsechnyProdukty()
{
    cout << "\n===== VYPIS VSECH PRODUKTU =====" << endl;

    for(int i = 0; i < this->pocetKavovychAutomatu; i++)
    {
        this->kavoveAutomaty[i]->vypisProdukty();
    }

    for (int i = 0; i < this->pocetPlechovkovychAutomatu; i++)
    {
        this->plechovkoveAutomaty[i]->vypisProdukty();
    }

    for(int i = 0; i < this->pocetOplatkovychAutomatu; i++)
    {
        this->oplatkoveAutomaty[i]->vypisProdukty();
    }
}

int ObchodniCentrum::spocitejCelkovouTrzbu()
{
    int suma = 0;
    for(int i = 0; i < this->pocetKavovychAutomatu; i++)
    {
        suma += this->kavoveAutomaty[i]->getPenizeVAutomatu();
    }

    for(int i = 0; i < this->pocetPlechovkovychAutomatu; i++)
    {
        suma += this->plechovkoveAutomaty[i]->getPenizeVAutomatu();
    }

    for(int i = 0; i < this->pocetOplatkovychAutomatu; i++)
    {
        suma += this->oplatkoveAutomaty[i]->getPenizeVAutomatu();
    }

    return suma;
}

int ObchodniCentrum::spocitejCelkovyPocetNakupu()
{
    int suma = 0;
    for (int i = 0; i < this->pocetKavovychAutomatu; i++)
    {
        suma += this->kavoveAutomaty[i]->getPocetNakupu();
    }

    for(int i = 0; i < this->pocetPlechovkovychAutomatu; i++)
    {
        suma += this->plechovkoveAutomaty[i]->getPocetNakupu();
    }

    for(int i = 0; i < this->pocetOplatkovychAutomatu; i++)
    {
        suma += this->oplatkoveAutomaty[i]->getPocetNakupu();
    }

    return suma;
}

void ObchodniCentrum::vypisStatistiky()
{
    cout << "\n===== STATISTIKY OBCHODNIHO CENTRA =====\n" << endl;
    cout << "Celkova trzba ze vsech automatu: " << this->spocitejCelkovouTrzbu() << " Kc" << endl;
    cout << "Celkovy pocet uspesnych nakupu: " << this->spocitejCelkovyPocetNakupu() << endl;
}