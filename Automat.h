#pragma once
#include <string>
#include "Product.h"

// Čistě abstraktní třída Automat
class Automat
{
    protected:
        std::string nazev;
        int vlozenePenize;
        int penizeVAutomatu;
        int pocetNakupu;

        Product** produkty;
        int pocetProduktu;
        int kapacitaProduktu;

        void nastavAutomat(std::string nazev, int kapacitaProduktu);
        Product* najdiProdukt(std::string nazevProduktu);
        bool zkontrolujPenize(Product* produkt);
        void dokoncitNakup(Product* produkt);
        void vratZbytek();

    public:
        Automat();
        virtual ~Automat();

        std::string getNazev();
        int getPenizeVAutomatu();
        int getPocetNakupu();

        void pridejProdukt(Product* produkt);
        void vlozPenize(int castka);
        void vypisProdukty();
        void vypisStatistikyAutomatu();

        virtual bool kupProdukt(std::string nazevProduktu) = 0;
};

class KavovyAutomat : public Automat
{
    private:
        int voda;
        int kava;
        int mleko;

    public:
        KavovyAutomat(std::string nazev, int voda, int kava, int mleko, int kapacitaProduktu = 60);
        bool kupProdukt(std::string nazevProduktu) override; //pozdni vazba
        void vypisSuroviny();
};

class AutomatNaPlechovky : public Automat
{
    public:
        AutomatNaPlechovky(std::string nazev, int kapacitaProduktu = 60);
        bool kupProdukt(std::string nazevProduktu) override; //pozdni vazba
};

class AutomatNaOplatky : public Automat
{
    public:
        AutomatNaOplatky(std::string nazev, int kapacitaProduktu = 60);
        bool kupProdukt(std::string nazevProduktu) override; //pozdni vazba
};