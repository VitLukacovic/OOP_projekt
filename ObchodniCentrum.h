#pragma once
#include <string>
#include "Automat.h"

class ObchodniCentrum
{
    private:
        std::string nazev;

        KavovyAutomat** kavoveAutomaty;
        AutomatNaPlechovky** plechovkoveAutomaty;
        AutomatNaOplatky** oplatkoveAutomaty;

        int pocetKavovychAutomatu;
        int pocetPlechovkovychAutomatu;
        int pocetOplatkovychAutomatu;

        int kapacitaKavovychAutomatu;
        int kapacitaPlechovkovychAutomatu;
        int kapacitaOplatkovychAutomatu;

    public:
        ObchodniCentrum(std::string nazev, int kapacitaKavovychAutomatu = 10, int kapacitaPlechovkovychAutomatu = 10, int kapacitaOplatkovychAutomatu = 10);
        ~ObchodniCentrum();

        void pridejAutomat(KavovyAutomat* automat);
        void pridejAutomat(AutomatNaPlechovky* automat);
        void pridejAutomat(AutomatNaOplatky* automat);

        KavovyAutomat* getKavovyAutomat(int index);
        AutomatNaPlechovky* getPlechovkovyAutomat(int index);
        AutomatNaOplatky* getOplatkovyAutomat(int index);

        void vypisAutomaty();
        void vypisVsechnyProdukty();
        int spocitejCelkovouTrzbu();
        int spocitejCelkovyPocetNakupu();
        void vypisStatistiky();
};