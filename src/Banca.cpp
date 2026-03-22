#include "Banca.h"
#include <cstring>
#include <iostream>

Banca::Banca() : clienti(NULL), nrClienti(0), numeBanca(NULL), crediteAcordateTotal(0) {
}

Banca::Banca(const char* nume) : clienti(NULL), nrClienti(0), crediteAcordateTotal(0) {
	if (nume == NULL) {
		numeBanca = new char[1];
		numeBanca[0] = '\0';
	} else {
		numeBanca = new char[strlen(nume) + 1];
		strcpy(numeBanca, nume);
	}
}

Banca::Banca(const char* nume, Client* listaClienti, int numar, double crediteTotal) : nrClienti(0), crediteAcordateTotal(crediteTotal) {
	if (nume == NULL) {
		numeBanca = new char[1];
		numeBanca[0] = '\0';
	} else {
		numeBanca = new char[strlen(nume) + 1];
		strcpy(numeBanca, nume);
	}

	if (listaClienti != NULL && numar > 0) {
		nrClienti = numar;
		clienti = new Client[nrClienti];
		for (int i = 0; i < nrClienti; i++) {
			clienti[i] = listaClienti[i];
		}
	}
}

Banca::~Banca() {
    delete[] numeBanca;
    delete[] clienti;
}

Banca::Banca(const Banca& banca) : nrClienti(0), crediteAcordateTotal(banca.crediteAcordateTotal) {
    if (banca.numeBanca == NULL) {
        numeBanca = NULL;
    } else {
        numeBanca = new char[strlen(banca.numeBanca) + 1];
        strcpy(numeBanca, banca.numeBanca);
    }

    clienti = NULL;
    if (banca.clienti != NULL && banca.nrClienti > 0) {
        nrClienti = banca.nrClienti;
        clienti = new Client[nrClienti];
        for (int i = 0; i < nrClienti; i++) {
            clienti[i] = banca.clienti[i];
        }
    }
}

Banca& Banca::operator=(const Banca& banca) {
	if (this == &banca) {
		return *this;
	}

	delete[] numeBanca;
	delete[] clienti;

	if (banca.numeBanca == NULL) {
		numeBanca = NULL;
	} else {
		numeBanca = new char[strlen(banca.numeBanca) + 1];
		strcpy(numeBanca, banca.numeBanca);
	}

	nrClienti = 0;
	clienti = NULL;
	crediteAcordateTotal = banca.crediteAcordateTotal;

	if (banca.clienti != NULL && banca.nrClienti > 0) {
		nrClienti = banca.nrClienti;
		clienti = new Client[nrClienti];
		for (int i = 0; i < nrClienti; i++) {
			clienti[i] = banca.clienti[i];
		}
	}

	return *this;
}

Client* Banca::getClienti() const {
	return clienti;
}

int Banca::getNrClienti() const {
	return nrClienti;
}

const char* Banca::getNumeBanca() const {
  return numeBanca;
}

double Banca::getCrediteAcordateTotal() const {
	// Recalculeaza totalul pentru a ramane sincron cu creditele curente ale clientilor
	double total = 0;
	if (clienti != NULL) {
		for (int i = 0; i < nrClienti; i++) {
			total += clienti[i].getSumaTotalaCredite();
		}
	}
	return total;
}


void Banca::setNumeBanca(const char* nume) {
	delete[] this->numeBanca;

	if (nume == NULL) {
		this->numeBanca = new char[1];
		this->numeBanca[0] = '\0';
		return;
	}

	this->numeBanca = new char[strlen(nume) + 1];
	strcpy(this->numeBanca, nume);
}

void Banca::adaugaClient(Client cl) {
	Client* listaNoua = new Client[nrClienti + 1];

	if (clienti != NULL) {
		for (int i = 0; i < nrClienti; i++) {
			listaNoua[i] = clienti[i];
		}
		delete[] clienti;
	}

	listaNoua[nrClienti] = cl;
	clienti = listaNoua;
	nrClienti++;
	crediteAcordateTotal += cl.getSumaTotalaCredite();
}

void Banca::afiseazaClienti() const {
	if (clienti == NULL || nrClienti == 0) {
		std::cout << "Nu exista clienti" << std::endl;
		return;
	}

	std::cout << "Clienti ai bancii " << numeBanca << ":" << std::endl;
	for (int i = 0; i < nrClienti; i++) {
		std::cout << "Client " << (i + 1) << ": " << clienti[i].getNumeClient() << std::endl;
	}
}
std::ostream& operator<<(std::ostream& os, const Banca& b) {
	os << "Numele bancii: " << b.getNumeBanca() << std::endl;
	os << "Credite total: " << b.getCrediteAcordateTotal() << std::endl;
	os << "Nr clienti: " << b.getNrClienti() << std::endl;
	os << "Lista clienti:" << std::endl;
    Client* lista = b.getClienti();
    for (int i = 0; lista != NULL && i < b.getNrClienti(); i++) {
        os << "  - " << lista[i].getNumeClient() << std::endl;
    }
	return os;
}

void Banca::afiseazaCrediteClient(const int ID) {
	if (clienti == NULL || nrClienti == 0) {
		std::cout << "Nu exista clienti" << std::endl;
		return;
	}

	for (int i = 0; i < nrClienti; i++) {
		if (clienti[i].getIdClient() == ID) {
			Credit* credite = clienti[i].getCredite();
			int numarCredite = clienti[i].getNumarCredit();

			if (credite == NULL || numarCredite == 0) {
				std::cout << "Clientul cu ID " << ID << " nu are credite" << std::endl;
				return;
			}

			std::cout << "Credite pentru clientul cu ID " << ID << ":" << std::endl;
			for (int j = 0; j < numarCredite; j++) {
				std::cout << credite[j] << std::endl;
			}
			return;
		}

	}

	std::cout << "Nu s-a gasit clientul cu ID " << ID << std::endl;
}

void Banca::acordaCredit(int id, Credit crd) {
	if (clienti == NULL || nrClienti == 0) {
		std::cout << "Nu exista clienti" << std::endl;
		return;
	}

	for (int i = 0; i < nrClienti; i++) {
		if (clienti[i].getIdClient() == id) {
			clienti[i].adaugaCredit(crd);
			crediteAcordateTotal += crd.calculCreditTotal();
			std::cout << "Credit acordat clientului cu ID " << id << std::endl;
			return;
		}
	}

	std::cout << "Nu s-a gasit clientul cu ID " << id << std::endl;
}

double Banca::getVenitLunar() const {
	if (clienti==NULL || nrClienti == 0) {
		std::cout << "Nu exista clienti" << std::endl;
		return 0;
	}
	double venitLunar=0;
	for (int i = 0; i < nrClienti; i++) {
		venitLunar += clienti[i].getVenit();
	}
	return venitLunar;


}
