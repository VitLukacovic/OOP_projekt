#include <iostream>
#include <string>
#include "Product.h"
#include "Automat.h"
#include "ObchodniCentrum.h"

using namespace std;

int main()
{
    ObchodniCentrum* centrum = new ObchodniCentrum("OC Banska");

    KavovyAutomat* kavovy1 = new KavovyAutomat("Kavovy automat K1", 3000, 500, 1000);
    KavovyAutomat* kavovy2 = new KavovyAutomat("Kavovy automat K2", 2000, 300, 700);

    AutomatNaPlechovky* plechovky1 = new AutomatNaPlechovky("Automat na plechovky P1");
    AutomatNaPlechovky* plechovky2 = new AutomatNaPlechovky("Automat na plechovky P2");

    AutomatNaOplatky* oplatky1 = new AutomatNaOplatky("Automat na oplatky O1");
    AutomatNaOplatky* oplatky2 = new AutomatNaOplatky("Automat na oplatky O2");

    centrum->pridejAutomat(kavovy1);
    centrum->pridejAutomat(kavovy2);
    centrum->pridejAutomat(plechovky1);
    centrum->pridejAutomat(plechovky2);
    centrum->pridejAutomat(oplatky1);
    centrum->pridejAutomat(oplatky2);

    kavovy1->pridejProdukt(new KavovyProdukt("Espresso", 35, 50, 15, 0));
    kavovy1->pridejProdukt(new KavovyProdukt("Lungo", 40, 80, 15, 0));

    kavovy2->pridejProdukt(new KavovyProdukt("Cappuccino", 45, 80, 15, 40));
    kavovy2->pridejProdukt(new KavovyProdukt("Latte", 50, 100, 15, 80));

    plechovky1->pridejProdukt(new Plechovka("Cola", 30, 330, true));
    plechovky1->pridejProdukt(new Plechovka("Sprite", 30, 330, true));

    plechovky2->pridejProdukt(new Plechovka("Voda", 25, 500, false));
    plechovky2->pridejProdukt(new Plechovka("Mineralka", 28, 500, true));

    oplatky1->pridejProdukt(new Oplatka("Horalky", 22, 50, "arasidova"));
    oplatky1->pridejProdukt(new Oplatka("Tatranka", 20, 45, "cokoladova"));

    oplatky2->pridejProdukt(new Oplatka("Fidorka", 25, 30, "oriskova"));
    oplatky2->pridejProdukt(new Oplatka("Mila", 24, 50, "smetanova"));

    for(int i = 1; i <= 10; i++)
    {
        kavovy1->pridejProdukt(new KavovyProdukt("Espresso Special " + to_string(i), 35 + i * 2, 50, 15 + i, 0));
        plechovky1->pridejProdukt(new Plechovka("Energeticky napoj " + to_string(i), 40 + i, 250, i % 2));
        oplatky1->pridejProdukt(new Oplatka("Oplatka Special " + to_string(i), 20 + i * 3, 50 + i * 7, "vanilkova"));
    }

    centrum->vypisAutomaty();
    centrum->vypisVsechnyProdukty();

    cout << "\n===== UKAZKA NAKUPU =====\n" << endl;

    kavovy1->vlozPenize(50);
    kavovy1->kupProdukt("Espresso");

    kavovy1->vlozPenize(100);
    kavovy1->kupProdukt("Espresso");

    kavovy2->vlozPenize(50);
    kavovy2->kupProdukt("Cappuccino");

    plechovky1->vlozPenize(40);
    plechovky1->kupProdukt("Cola");

    plechovky2->vlozPenize(10);
    plechovky2->kupProdukt("Voda");

    oplatky1->vlozPenize(30);
    oplatky1->kupProdukt("Tatranka");

    oplatky1->vlozPenize(30);
    oplatky1->kupProdukt("Tatranka");

    oplatky2->vlozPenize(50);
    oplatky2->kupProdukt("Mila");

    cout << "\n===== STATISTIKY AUTOMATU =====\n" << endl;
    //polymorfismus
    // POLYMORFNÍ DATOVÁ STRUKTURA: Pole ukazatelů na bazickou třídu Automat
    Automat** vsechnyAutomaty = new Automat*[6];

    // POLYMORFNÍ PŘIŘAZENÍ 
    vsechnyAutomaty[0] = kavovy1;
    vsechnyAutomaty[1] = kavovy2;
    vsechnyAutomaty[2] = plechovky1;
    vsechnyAutomaty[3] = plechovky2;
    vsechnyAutomaty[4] = oplatky1;
    vsechnyAutomaty[5] = oplatky2;

    int pocetVsechAutomatu = 6;

    for(int i = 0; i < pocetVsechAutomatu; i++)
    {
        // POLYMORFNÍ VOLÁNÍ
        vsechnyAutomaty[i]->vypisStatistikyAutomatu();
    }

    cout << "Celkem existuje produktu: " << Product::getCelkovyPocetProduktu() << "\n" <<endl;

    delete[] vsechnyAutomaty;

    cout << "===== STAV SUROVIN KAVOVYCH AUTOMATU =====\n" << endl;

    kavovy1->vypisSuroviny();
    kavovy2->vypisSuroviny();

    centrum->vypisStatistiky();

    return 0;
}