#include <iostream>
#include "credit.h"
#include <cstring>
double Credit :: getValoareCredit() const{ return valoareCredit; }
double Credit::getDobandaCredit() const { return dobandaCredit; }
unsigned Credit::getDurataCredit() const { return durataCredit; }
const char* Credit::getTipCredit() const {return tipCredit;}
bool Credit::getCreditPlatit() const { return creditPlatit; }

void Credit::setTipCredit(const char* tip){
    delete[] this->tipCredit;

    if (tip == NULL) {
        this->tipCredit = new char[1];
        this->tipCredit[0] = '\0';
        return;
    }

    const size_t lungime = strlen(tip);
    this->tipCredit = new char[lungime + 1];
    strcpy(this->tipCredit, tip);
}

void Credit::setCreditPlatit(bool platit) {
    this->creditPlatit = platit;
}

void Credit::setValoareCredit(double valoare){
    this->valoareCredit = valoare;
}
void Credit::setDurataCredit(unsigned durata) {
    this->durataCredit = durata;
}
void Credit::setDobandaCredit(double dobanda){
    this->dobandaCredit = dobanda;
}
double Credit::calculCreditTotal() const{
    return this->valoareCredit + (this->valoareCredit * this->dobandaCredit);
}
Credit::Credit() {
    tipCredit = new char[1];
    tipCredit[0] = '\0';
    valoareCredit = 0;
    dobandaCredit = 0;
    durataCredit = 0;
    creditPlatit = false;
}
Credit::Credit(const char* tip,double valoare,unsigned durata,double dobanda,bool platit) {
    if (tip == NULL) {
        this->tipCredit = new char[1];
        this->tipCredit[0] = '\0';
    } else {
        const int lungime = strlen(tip);
        this->tipCredit = new char[lungime + 1];
        strcpy(this->tipCredit, tip);
    }

    this->valoareCredit = valoare;
    this->dobandaCredit = dobanda;
    this->durataCredit = durata;
    this->creditPlatit = platit;
}
Credit :: ~Credit() {
    delete[] tipCredit;
}

Credit::Credit(const Credit &c) {
    const int lungime = strlen(c.tipCredit);
    this->tipCredit = new char[lungime + 1];
    strcpy(this->tipCredit, c.tipCredit);
    this->valoareCredit = c.valoareCredit;
    this->dobandaCredit = c.dobandaCredit;
    this->durataCredit = c.durataCredit;
    this->creditPlatit = c.creditPlatit;
}

Credit& Credit::operator=(const Credit &obj) {
    if (this == &obj) {
        return *this;
    }

    delete [] tipCredit;
    tipCredit=new char[(strlen(obj.tipCredit)+1)];
    strcpy(tipCredit,obj.tipCredit);
    valoareCredit=obj.valoareCredit;
    dobandaCredit=obj.dobandaCredit;
    durataCredit=obj.durataCredit;
    creditPlatit=obj.creditPlatit;
    return *this;

}
std::ostream& operator<<(std::ostream& os, const Credit& c){
    os << "Tip Credit: " << c.tipCredit << std::endl;
    os << "Valoare Credit: " << c.valoareCredit << std::endl;
    os << "Durata Credit: " << c.durataCredit << " luni" << std::endl;
    os << "Dobanda Credit: " << c.dobandaCredit * 100 << "%" << std::endl;
    os<< "Credit Platit: " << (c.creditPlatit ? "Da" : "Nu") << std::endl;
    return os;
}

