

#ifndef POO_P1_CREDIT_H
#define POO_P1_CREDIT_H
#include <iostream>
class Credit {
    // Informatii principale ale creditului
    char* tipCredit;
    double valoareCredit;
    unsigned durataCredit;
    double dobandaCredit;
    bool creditPlatit;
public:
    Credit();
    ~Credit();

    // Getteri
    const char* getTipCredit() const;
    double getValoareCredit() const;
    unsigned  getDurataCredit() const;
    // Dobanda exprimata ca procent (ex: 0.05 = 5%)
    double getDobandaCredit() const;
    // true daca creditul este platit (devient inactiv, dar se pastreaza pentru istoric)
    bool getCreditPlatit() const;

    // Setteri
    void setTipCredit(const char* tip);
    void setValoareCredit(double valoare);
    void setDurataCredit(unsigned durata);
    void setDobandaCredit(double dobanda);
    void setCreditPlatit(bool creditPlatit);

    // Calculeaza costul total al creditului (valoare + dobanda)
    double calculCreditTotal() const;

    Credit(const char* tip,double valoare,unsigned durata,double dobanda,bool creditPlatit);
    Credit(const Credit& c);

    // Operator de atribuire (assignment operator)
    Credit& operator=(const Credit &obj);
    // Supraincarcarea operatorului de afisare
    friend std::ostream& operator<<(std::ostream& os, const Credit& c);
};
#endif