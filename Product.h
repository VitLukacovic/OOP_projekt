#pragma once
#include <string>

// Abstraktni trida
class Product
{
    protected:
        std::string nazev;
        int cena;

    public:
        Product();
        Product(std::string nazev, int cena);
        virtual ~Product();

        std::string getNazev();
        int getCena();
        virtual void popis() = 0;
};

class KavovyProdukt : public Product
{
    private:
        int potrebaVody;
        int potrebaKavy;
        int potrebaMleka;

    public:
        KavovyProdukt(std::string nazev, int cena, int potrebaVody, int potrebaKavy, int potrebaMleka);
        int getPotrebaVody();
        int getPotrebaKavy();
        int getPotrebaMleka();
        void popis() override;
};

class Plechovka : public Product
{
    private:
        int objemMl;
        bool perliva;

    public:
        Plechovka(std::string nazev, int cena, int objemMl, bool perliva);
        void popis() override;
};

class Oplatka : public Product
{
    private:
        int hmotnostG;
        std::string prichut;

    public:
        Oplatka(std::string nazev, int cena, int hmotnostG, std::string prichut);
        void popis() override;
};