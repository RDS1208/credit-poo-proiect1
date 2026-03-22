

#ifndef POO_P1_BANCA_H
#define POO_P1_BANCA_H
#include "Client.h"

class Banca {
    Client* clienti;
    int nrClienti;
    char* numeBanca;
    double crediteAcordateTotal;

public:
    Banca();
    ~Banca();
    Banca(const char* nume);
    Banca(const Banca& banca);
    Banca(const char* nume, Client* listaClienti, int numar, double crediteTotal);
    Banca& operator=(const Banca& banca);
    friend std::ostream& operator<<(std::ostream& os, const Banca& b);

    // Getteri
    Client* getClienti() const;
    int getNrClienti() const;
    const char* getNumeBanca() const;
    double getCrediteAcordateTotal() const;

    // Setteri si operatii cu clienti
    void setNumeBanca(const char* nume);
    void adaugaClient(Client cl);
    void afiseazaClienti() const;
    void afiseazaCrediteClient(const int ID);
    void acordaCredit(int id,Credit crd);
    // Calculeaza venit total lunar al bancii bazat pe sumele de bani pe care
    //clientii le platesc
    double getVenitLunar() const;

};
#endif