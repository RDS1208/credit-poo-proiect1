#include "Client.h"

#include <cstring>
#include <iostream>

Client::Client() {
    numeClient = NULL;
    idClient = 0;
    venitLunar = 0;
    credite = NULL;
    numarCredite = 0;
}

Client::~Client() {
    delete[] numeClient;
    delete[] credite;
}

Client::Client(const Client& client) {
    idClient = client.idClient;
    venitLunar = client.venitLunar;
    credite = NULL;
    numarCredite = 0;

    if (client.numeClient == NULL) {
        numeClient = NULL;
    } else {
        numeClient = new char[strlen(client.numeClient) + 1];
        strcpy(numeClient, client.numeClient);
    }

    if (client.credite != NULL && client.numarCredite > 0) {
        numarCredite = client.numarCredite;
        credite = new Credit[numarCredite];
        for (int i = 0; i < numarCredite; i++) {
            credite[i] = client.credite[i];
        }
    }
}

Client& Client::operator=(const Client& client) {
    if (this == &client) {
        return *this;
    }

    delete[] numeClient;
    delete[] credite;

    if (client.numeClient == NULL) {
        numeClient = NULL;
    } else {
        numeClient = new char[strlen(client.numeClient) + 1];
        strcpy(numeClient, client.numeClient);
    }

    idClient = client.idClient;
    venitLunar = client.venitLunar;
    credite = NULL;
    numarCredite = 0;

    if (client.credite != NULL && client.numarCredite > 0) {
        numarCredite = client.numarCredite;
        credite = new Credit[numarCredite];
        for (int i = 0; i < numarCredite; i++) {
            credite[i] = client.credite[i];
        }
    }

    return *this;
}

Client::Client(const char* nume, int id, double venit, Credit* listaCredite, int numar) {
    numeClient = NULL;
    credite = NULL;
    numarCredite = 0;
    setNumeClient(nume);
    idClient = id;
    this->venitLunar = venit;
    if (listaCredite != NULL && numar > 0) {
        numarCredite = numar;
        credite = new Credit[numarCredite];
        for (int i = 0; i < numarCredite; i++) {
            credite[i] = listaCredite[i];
        }
    }
}

const char* Client::getNumeClient() const { return numeClient; }
int Client::getIdClient() const { return idClient; }
double Client::getVenit() const { return venitLunar; }
Credit* Client::getCredite() const { return credite; }
int Client::getNumarCredit() const {return numarCredite;}

void Client::setNumeClient(const char* nume) {
    delete[] this->numeClient;

    if (nume == NULL) {
        this->numeClient = new char[1];
        this->numeClient[0] = '\0';
        return;
    }

    this->numeClient = new char[strlen(nume) + 1];
    strcpy(this->numeClient, nume);
}

void Client::setIdClient(int id) {
    this->idClient = id;
}

void Client::setVenit(double valoareVenit) {
    this->venitLunar = valoareVenit;
}

void Client::setCredite(Credit* listaCredite, int numar) {
    delete[] this->credite;
    this->credite = NULL;
    this->numarCredite = 0;

    if (listaCredite != NULL && numar > 0) {
        this->numarCredite = numar;
        this->credite = new Credit[this->numarCredite];
        for (int i = 0; i < this->numarCredite; i++) {
            this->credite[i] = listaCredite[i];
        }
    }
}

double Client::getSumaTotalaCredite() {
    double suma = 0;

    if (credite == NULL) {
        return suma;
    }

    for (int i = 0; i < numarCredite; i++) {
        suma += credite[i].getValoareCredit();
    }

    return suma;
}

bool Client::verificareEligibilitateCredit(double ValoareCreditDorit) {
    double datoriiCurente = getSumaTotalaCredite();
    if (venitLunar*24 < datoriiCurente + ValoareCreditDorit) {
        return false;
    }
    return true;
}

void Client::adaugaCredit(Credit crd) {
    if (verificareEligibilitateCredit(crd.getValoareCredit()) == false) {
        std::cout << "Limita Creditare depasita" << std::endl;
        return;
    }

    Credit* listaNoua = new Credit[numarCredite + 1];

    if (credite != NULL) {
        for (int i = 0; i < numarCredite; i++) {
            listaNoua[i] = credite[i];
        }
        delete[] credite;
    }

    listaNoua[numarCredite] = crd;
    credite = listaNoua;
    numarCredite++;
}

void Client::eliminareCreditePlatite() {
    if (credite == NULL) {
        return;
    }

    int contorCrediteValide = 0;
    for (int i = 0; i < numarCredite; i++) {
        if (credite[i].getCreditPlatit() == false) {
            contorCrediteValide++;
        }
    }

    if (contorCrediteValide == 0) {
        delete[] credite;
        credite = NULL;
        numarCredite = 0;
        return;
    }

    if (contorCrediteValide == numarCredite) {
        return;
    }

    Credit* listaNoua = new Credit[contorCrediteValide];
    int index = 0;
    for (int i = 0; i < numarCredite; i++) {
        if (credite[i].getCreditPlatit() == false) {
            listaNoua[index] = credite[i];
            index++;
        }
    }

    delete[] credite;
    credite = listaNoua;
    numarCredite = contorCrediteValide;
    std::cout<<"Credite platite eliminate"<<std::endl;
}

void Client::efectuarePlata(double suma, int index) {
    if (index < 0 || index >= numarCredite) {
        std::cout << "Index invalid" << std::endl;
        return;
    }
    Credit& crd=credite[index];
    if (crd.getCreditPlatit() == true) {
        std::cout<<"Credirt deja platit"<<std::endl;
        return;
    }
        if (suma>=crd.getValoareCredit()) {
            crd.setValoareCredit(0);
            crd.setCreditPlatit(true);
        } else {
            crd.setValoareCredit(crd.getValoareCredit() - suma);
        }
    eliminareCreditePlatite();
}

double Client::getPlataLunara() const {
    if (credite == NULL || numarCredite == 0) {
        return 0;
    }

    double plataLunara = 0;

    for (int i = 0; i < numarCredite; i++) {
        if (credite[i].getDurataCredit() > 0) {
            plataLunara += credite[i].calculCreditTotal() / credite[i].getDurataCredit();
        }
    }

    return plataLunara;
}





