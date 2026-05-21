#include "Automat.h"
#include <iostream>

using namespace std;

// --- Automat ---
Automat::Automat()
{
    this->nazev = "";
    this->vlozenePenize = 0;
    this->penizeVAutomatu = 0;
    this->pocetNakupu = 0;
    this->produkty = nullptr;
    this->pocetProduktu = 0;
    this->kapacitaProduktu = 0;
}

Automat::~Automat()
{
    for(int i = 0; i < this->pocetProduktu; i++)
    {
        delete this->produkty[i];
    }
    delete[] this->produkty;
}

string Automat::getNazev()
{
    return this->nazev;
}
int Automat::getPenizeVAutomatu()
{
    return this->penizeVAutomatu;
}

int Automat::getPocetNakupu()
{
    return this->pocetNakupu;
}

void Automat::pridejProdukt(Product* produkt)
{
    if(this->pocetProduktu >= this->kapacitaProduktu)
    {
        cout << "Do automatu " << this->nazev << " uz nelze pridat dalsi produkt." << endl;
        delete produkt;
        return;
    }
    this->produkty[this->pocetProduktu] = produkt;
    this->pocetProduktu++;
}

void Automat::vlozPenize(int castka)
{
    if(castka <= 0)
    {
        cout << "Nelze vlozit neplatnou castku." << endl;
        return;
    }
    this->vlozenePenize = this->vlozenePenize + castka;
    cout << "Do automatu " << this->nazev << " bylo vlozeno " << castka << " Kc. Aktualne vlozene penize: " << this->vlozenePenize << " Kc" << endl;
}

void Automat::vypisProdukty()
{
    cout << "\nProdukty v automatu " << this->nazev << ":" << endl;
    if(this->pocetProduktu == 0)
    {
        cout << "Automat nema v nabidce zadne produkty." << endl;
        return;
    }

    for(int i = 0; i < this->pocetProduktu; i++)
    {
        cout << i + 1 << ". ";
        this->produkty[i]->popis();
    }
}

void Automat::vypisStatistikyAutomatu()
{
    cout << "Statistiky automatu: " << this->nazev << endl;
    cout << "Penize v automatu: " << this->penizeVAutomatu << " Kc" << endl;
    cout << "Pocet uspesnych nakupu: " << this->pocetNakupu << "\n" << endl;
}

void Automat::nastavAutomat(string nazev, int kapacitaProduktu)
{
    this->nazev = nazev;
    this->vlozenePenize = 0;
    this->penizeVAutomatu = 0;
    this->pocetNakupu = 0;
    this->pocetProduktu = 0;
    this->kapacitaProduktu = kapacitaProduktu;

    this->produkty = new Product*[this->kapacitaProduktu];
    for
    (int i = 0; i < this->kapacitaProduktu; i++)
    {
        this->produkty[i] = nullptr;
    }
}

Product* Automat::najdiProdukt(string nazevProduktu)
{
    for(int i = 0; i < this->pocetProduktu; i++)
    {
        if(this->produkty[i]->getNazev() == nazevProduktu)
        {
            return this->produkty[i];
        }
    }
    return nullptr;
}

bool Automat::zkontrolujPenize(Product* produkt)
{
    if(this->vlozenePenize < produkt->getCena())
    {
        cout << "Nedostatek penez. Cena produktu je " << produkt->getCena() << " Kc, vlozeno je pouze " << this->vlozenePenize << " Kc." << endl;
        return false;
    }
    return true;
}

void Automat::dokoncitNakup(Product* produkt)
{
    this->vlozenePenize = this->vlozenePenize - produkt->getCena();
    this->penizeVAutomatu = this->penizeVAutomatu + produkt->getCena();
    this->pocetNakupu++;

    cout << "Nakup probehl uspesne: " << produkt->getNazev() << endl;
    this->vratZbytek();
}

void Automat::vratZbytek()
{
    if(this->vlozenePenize > 0)
    {
        cout << "Automat vraci zbytek: " << this->vlozenePenize << " Kc\n" << endl;
    }
    this->vlozenePenize = 0;
}

// --- KavovyAutomat ---
KavovyAutomat::KavovyAutomat(string nazev, int voda, int kava, int mleko, int kapacitaProduktu)
{
    this->nastavAutomat(nazev, kapacitaProduktu);
    this->voda = voda;
    this->kava = kava;
    this->mleko = mleko;
}

bool KavovyAutomat::kupProdukt(string nazevProduktu)
{
    cout << "Pokus o nakup kavy: " << nazevProduktu << endl;
    Product* produkt = this->najdiProdukt(nazevProduktu);

    if(produkt == nullptr)
    {
        cout << "Produkt nebyl nalezen v kavovem automatu." << endl;
        return false;
    }

    KavovyProdukt* kavovyProdukt = dynamic_cast<KavovyProdukt*>(produkt);
    if(kavovyProdukt == nullptr)
    {
        cout << "Tento produkt nepatri do kavoveho automatu." << endl;
        return false;
    }

    if(!this->zkontrolujPenize(produkt))
    {
        return false;
    }

    if(this->voda < kavovyProdukt->getPotrebaVody())
    {
        cout << "Kavovy automat nema dostatek vody." << endl;
        return false;
    }

    if(this->kava < kavovyProdukt->getPotrebaKavy())
    {
        cout << "Kavovy automat nema dostatek kavy." << endl;
        return false;
    }

    if(this->mleko < kavovyProdukt->getPotrebaMleka())
    {
        cout << "Kavovy automat nema dostatek mleka." << endl;
        return false;
    }

    this->voda = this->voda - kavovyProdukt->getPotrebaVody();
    this->kava = this->kava - kavovyProdukt->getPotrebaKavy();
    this->mleko = this->mleko - kavovyProdukt->getPotrebaMleka();

    cout << "Kava byla pripravena." << endl;
    this->dokoncitNakup(produkt);
    return true;
}

void KavovyAutomat::vypisSuroviny()
{
    cout << "Stav surovin v automatu " << this->nazev << ":" << endl;
    cout << "Voda: " << this->voda << endl;
    cout << "Kava: " << this->kava << endl;
    cout << "Mleko: " << this->mleko << "\n" << endl;
}

// --- AutomatNaPlechovky ---
AutomatNaPlechovky::AutomatNaPlechovky(string nazev, int kapacitaProduktu)
{
    this->nastavAutomat(nazev, kapacitaProduktu);
}

bool AutomatNaPlechovky::kupProdukt(string nazevProduktu)
{
    cout << "Pokus o nakup plechovky: " << nazevProduktu << endl;
    Product* produkt = this->najdiProdukt(nazevProduktu);

    if (produkt == nullptr)
    {
        cout << "Produkt nebyl nalezen v automatu na plechovky." << endl;
        return false;
    }

    Plechovka* plechovka = dynamic_cast<Plechovka*>(produkt);
    if (plechovka == nullptr)
    {
        cout << "Tento produkt nepatri do automatu na plechovky." << endl;
        return false;
    }

    if(!this->zkontrolujPenize(produkt))
    {
        return false;
    }

    cout << "Plechovka byla koupena." << endl;
    this->dokoncitNakup(produkt);
    return true;
}

// --- AutomatNaOplatky ---
AutomatNaOplatky::AutomatNaOplatky(string nazev, int kapacitaProduktu)
{
    this->nastavAutomat(nazev, kapacitaProduktu);
}

bool AutomatNaOplatky::kupProdukt(string nazevProduktu)
{
    cout << "Pokus o nakup oplatky: " << nazevProduktu << endl;
    Product* produkt = this->najdiProdukt(nazevProduktu);

    if(produkt == nullptr)
    {
        cout << "Produkt nebyl nalezen v automatu na oplatky." << endl;
        return false;
    }

    Oplatka* oplatka = dynamic_cast<Oplatka*>(produkt);
    if(oplatka == nullptr)
    {
        cout << "Tento produkt nepatri do automatu na oplatky." << endl;
        return false;
    }

    if(!this->zkontrolujPenize(produkt))
    {
        return false;
    }

    cout << "Oplatka byla koupena." << endl;
    this->dokoncitNakup(produkt);
    return true;
}