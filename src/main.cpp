#include <iostream>
#include "credit.h"
#include "Client.h"
#include "Banca.h"

using namespace std;

int main()
{

    // Clasa Credit
    cout << "1. Clasa Credit" << endl;

    // Creare credite
    Credit credit1("Ipotecar", 100000, 24, 0.05, false);
    Credit credit2("Personal", 5000, 12, 0.08, false);
    Credit credit3("Auto", 30000, 36, 0.04, false);

    cout << "Credit 1: " << credit1 << endl << endl;
    cout << "Credit 2: " << credit2 << endl << endl;
    cout << "Credit 3: " << credit3 << endl << endl;

    // Teste getteri
    cout << "Teste Getteri Credit" << endl;
    cout << "Tip credit1: " << credit1.getTipCredit() << endl;
    cout << "Valoare credit1: " << credit1.getValoareCredit() << endl;
    cout << "Durata credit1: " << credit1.getDurataCredit() << " luni" << endl;
    cout << "Dobanda credit1: " << credit1.getDobandaCredit() * 100 << "%" << endl;
    cout << "Cost total credit1: " << credit1.calculCreditTotal() << endl;
    cout << "Platit: " << (credit1.getCreditPlatit() ? "Da" : "Nu") << endl << endl;

    // Teste setteri
    cout << "Teste Setteri Credit" << endl;
    Credit creditTest;
    creditTest.setTipCredit("Edu");
    creditTest.setValoareCredit(15000);
    creditTest.setDurataCredit(18);
    creditTest.setDobandaCredit(0.03);
    creditTest.setCreditPlatit(false);
    cout << "Credit dupa setare: " << creditTest << endl << endl;

    // Copy constructor
    cout << "Constructor De Copiere Credit" << endl;
    Credit creditCopy(credit1);
    cout << "Credit copiat: " << creditCopy << endl << endl;

    // Operator= (atribuire)
    cout << "Operator= Credit" << endl;
    Credit creditAsign = credit2;
    cout << "Credit atribuit: " << creditAsign << endl << endl;


    // Clasa Client
    cout << endl << "2. Clasa Client" << endl;

    // Creare clienti cu credite
    Credit crediteClient1[] = {credit1, credit2};
    Client client1("Ion Popescu", 1, 5000, crediteClient1, 2);

    Credit crediteClient2[] = {credit3};
    Client client2("Maria Ionescu", 2, 3000, crediteClient2, 1);

    cout << "Informatii Clienti" << endl;
    cout << "Client 1: " << client1.getNumeClient() << endl;
    cout << "  ID: " << client1.getIdClient() << endl;
    cout << "  Venit lunar: " << client1.getVenit() << endl;
    cout << "  Numar credite: " << client1.getNumarCredit() << endl;
    cout << "  Suma totala credite: " << client1.getSumaTotalaCredite() << endl;
    cout << "  Plata lunara: " << client1.getPlataLunara() << endl << endl;

    cout << "Client 2: " << client2.getNumeClient() << endl;
    cout << "  ID: " << client2.getIdClient() << endl;
    cout << "  Venit lunar: " << client2.getVenit() << endl;
    cout << "  Numar credite: " << client2.getNumarCredit() << endl;
    cout << "  Suma totala credite: " << client2.getSumaTotalaCredite() << endl;
    cout << "  Plata lunara: " << client2.getPlataLunara() << endl << endl;

    // Verificare eligibilitate credit
    cout << "Verificare Eligibilitate" << endl;
    double creditDorit = 20000;
    bool eligibil1 = client1.verificareEligibilitateCredit(creditDorit);
    bool eligibil2 = client2.verificareEligibilitateCredit(creditDorit);
    cout << client1.getNumeClient() << " eligibil pentru " << creditDorit
         << " lei: " << (eligibil1 ? "Da" : "Nu") << endl;
    cout << client2.getNumeClient() << " eligibil pentru " << creditDorit
         << " lei: " << (eligibil2 ? "Da" : "Nu") << endl << endl;

    // Adaugare credit nou la client
    cout << "Adaugare Credit Nou" << endl;
    cout << "Credite client1 inainte: " << client1.getNumarCredit() << endl;
    Credit creditNou("Cartela", 2000, 6, 0.06, false);
    client1.adaugaCredit(creditNou);
    cout << "Credite client1 dupa: " << client1.getNumarCredit() << endl << endl;

    // Efectuare plata
    cout << "Efectuare Plata" << endl;
    cout << "Valoare credit0 din client1 inainte plata: " << client1.getCredite()[0].getValoareCredit() << endl;
    cout << "Efectuez plata de 5000..." << endl;
    client1.efectuarePlata(5000, 0);
    cout << "Valoare credit0 din client1 dupa plata: " << client1.getCredite()[0].getValoareCredit() << endl << endl;

    // Eliminare credite platite
    cout << "Eliminare Credite Platite" << endl;
    client1.eliminareCreditePlatite();
    cout << "Credite ramase client1: " << client1.getNumarCredit() << endl << endl;

    // Copy constructor Client
    cout << "Constructor De Copiere Client" << endl;
    Client clientCopy(client1);
    cout << "Client copiat: " << clientCopy.getNumeClient() << endl << endl;

    // Operator= Client
    cout << "Operator= Client" << endl;
    Client clientAsign;
    clientAsign = client2;
    cout << "Client atribuit: " << clientAsign.getNumeClient() << endl << endl;


    // Clasa Banca
    cout << endl << "3. Clasa Banca" << endl;

    // Creare banca cu clienti
    Client clientiBanca[] = {client1, client2};
    Banca banca("BancaRomania", clientiBanca, 2, client1.getSumaTotalaCredite() + client2.getSumaTotalaCredite());

    cout << "Informatii Banca" << endl;
    cout << "Nume banca: " << banca.getNumeBanca() << endl;
    cout << "Numar clienti: " << banca.getNrClienti() << endl;
    cout << "Credite acordate total: " << banca.getCrediteAcordateTotal() << endl;
    cout << "Venit lunar total clienti: " << banca.getVenitLunar() << endl << endl;

    // Adaugare client nou in banca
    cout << "Adaugare Client Nou" << endl;
    Client clientNou("Alexandru Georgescu", 3, 4000, NULL, 0);
    banca.adaugaClient(clientNou);
    cout << "Numar clienti dupa: " << banca.getNrClienti() << endl << endl;

    // Afisare clienti
    cout << "Lista Clienti Banca" << endl;
    banca.afiseazaClienti();
    cout << endl;

    // Acordare credit unui client
    cout << "Acorda Credit Clientului Cu ID 3" << endl;
    Credit creditPentruClientNou("Rapid", 7000, 10, 0.07, false);
    banca.acordaCredit(3, creditPentruClientNou);
    banca.afiseazaCrediteClient(3);
    cout << "Credite acordate total recalculat: " << banca.getCrediteAcordateTotal() << endl << endl;

    // Copy constructor Banca
    cout << "Constructor De Copiere Banca" << endl;
    Banca bancaCopy(banca);
    cout << "Banca copiata: " << bancaCopy.getNumeBanca() << " cu "
         << bancaCopy.getNrClienti() << " clienti" << endl << endl;

    // Operator= Banca
    cout << "Operator= Banca" << endl;
    Banca bancaAsign;
    bancaAsign = banca;
    cout << "Banca atribuita: " << bancaAsign.getNumeBanca() << endl << endl;

    return 0;
}

