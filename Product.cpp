#include "Product.h"
#include <iostream>

using namespace std;

//Product
Product::Product()
{
    this->nazev = "";
    this->cena = 0;
}

Product::Product(string nazev, int cena)
{
    this->nazev = nazev;
    this->cena = cena;
}

Product::~Product()
{

}

string Product::getNazev()
{
    return this->nazev;
}

int Product::getCena()
{
    return this->cena;
}

//KavovyProdukt
KavovyProdukt::KavovyProdukt(string nazev, int cena, int potrebaVody, int potrebaKavy, int potrebaMleka) : Product(nazev, cena)
{ 
    this->potrebaVody = potrebaVody;
    this->potrebaKavy = potrebaKavy;
    this->potrebaMleka = potrebaMleka;
}

int KavovyProdukt::getPotrebaVody()
{
    return this->potrebaVody;
}

int KavovyProdukt::getPotrebaKavy()
{
    return this->potrebaKavy;
}

int KavovyProdukt::getPotrebaMleka()
{
    return this->potrebaMleka;
}

void KavovyProdukt::popis()
{
    cout << this->nazev << " - " << this->cena << " Kc" << " | voda: " << this->potrebaVody << ", kava: " << this->potrebaKavy << ", mleko: " << this->potrebaMleka << endl;
}

// --- Plechovka ---
Plechovka::Plechovka(string nazev, int cena, int objemMl, bool perliva) : Product(nazev, cena)
{
    this->objemMl = objemMl;
    this->perliva = perliva;
}

void Plechovka::popis()
{
    cout << this->nazev << " - " << this->cena << " Kc" << " | objem: " << this->objemMl << " ml" << " | ";

    if(this->perliva)
    {
        cout <<"perliva" << endl;
    }
    else
    {
        cout << "neperliva" << endl;
    }
    
}

// --- Oplatka ---
Oplatka::Oplatka(string nazev, int cena, int hmotnostG, string prichut) : Product(nazev, cena)
{
    this->hmotnostG = hmotnostG;
    this->prichut = prichut;
}

void Oplatka::popis()
{
    cout << this->nazev << " - " << this->cena << " Kc" << " | hmotnost: " << this->hmotnostG << " g" << " | prichut: " << this->prichut << endl;
}