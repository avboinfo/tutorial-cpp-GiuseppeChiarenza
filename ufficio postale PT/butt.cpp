#include <iostream>

class poste {
private:
    char serv;
public:
    int numeroClienteTotali = 0;
    int numeroClienteSpedizione = 0;
    int numeroClienteRicezione = 0;
    int numeroClienteFinanziaro = 0;

    void motivoPoste() {
        std::cout << "Benvenuto alle poste di via saliceto" << std::endl;
        std::cout << "Servizi disponibili: " << std::endl;
        std::cout << "[]SPEDIZIONE" << std::endl;
        std::cout << "[]RICEZIONE" << std::endl;
        std::cout << "[]FINANZIARO" << std::endl;
    }

    void servizio() {
        std::cout << std::endl;
        std::cout << "Per prenotare SPEDIZIONE scrivere s" << std::endl;
        std::cout << "Per prenotare RICEZIONE scrivere r" << std::endl;
        std::cout << "Per prenotare FINANZIARO scrivere f" << std::endl;
        std::cout << "PRENOTA: ";
        std::cin >> serv;
    }

    void generaNumeroCliente() {
        if (serv == 's')
            numeroClienteSpedizione++;
        else if (serv == 'r')
            numeroClienteRicezione++;
        else if (serv == 'f')
            numeroClienteFinanziaro++;
        else {
            std::cout << "SERVIZIO INVALIDO" << std::endl;
        }
    }
};

int main() {
    poste prova;
    prova.motivoPoste();
    prova.servizio();
    prova.generaNumeroCliente();
    std::cout << "CLIENTI: " << std::endl;
    std::cout << "SPEDIZIONE--> " << prova.numeroClienteSpedizione << std::endl;
    std::cout << "RICEZIONE--> " << prova.numeroClienteRicezione << std::endl;
    std::cout << "FINANZIARO--> " << prova.numeroClienteFinanziaro << std::endl;

    return 0;
}