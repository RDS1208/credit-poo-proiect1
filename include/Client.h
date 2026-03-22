

#ifndef POO_P1_CLIENT_H
#define POO_P1_CLIENT_H
#include "Credit.h"

// Clasa pentru gestiunea clientilor bancari
class Client {

    // Informatii despre client
    char* numeClient;
    int idClient;
    double venitLunar;
    // Credite aferente clientului
    Credit* credite;
    int numarCredite;

public:
    // Getteri
    const char* getNumeClient() const;
    int getIdClient() const;
    double getVenit() const;
    Credit* getCredite() const;
    int getNumarCredit() const;

    // Setteri
    void setNumeClient(const char* nume);
    void setIdClient(int id);
    void setVenit(double valoareVenit);
    void setCredite(Credit* listaCredite, int numar);

    Client();
    ~Client();
    Client(const Client& client);
    Client& operator=(const Client& client);
    Client(const char* nume, int id, double venit, Credit* listaCredite, int numar);

    // Calcule si operatii cu credite
    double getSumaTotalaCredite();
    // Verifica daca clientul poate lua un credit nou
    // Un client este eligibil daca si numai daca
    // Venitul sau in urmatoarele 24 de luni este mai mare egal
    // decat suma dintre datoriile curente si suma creditului dorit
    bool verificareEligibilitateCredit(double ValoareCreditDorit);
    void adaugaCredit(Credit crd);
    // Efectueaza o plata la creditul de la indexul <index>
    void efectuarePlata(double suma, int index);
    friend std::ostream& operator<<(std::ostream& os, const Client& c);
    // Pargurge array-ul creditelor si pe cele inactive le elimina
    void eliminareCreditePlatite();
    // Calculeaza plata lunara pentru toate creditele
    double getPlataLunara() const;

};
#endif