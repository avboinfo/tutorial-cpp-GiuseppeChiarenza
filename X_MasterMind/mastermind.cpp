
/**
Mastermind è un gioco di decifrazione di codici per due giocatori.
Un giocatore, il codificatore, crea un codice segreto e l'altro giocatore, il decodificatore, cerca di indovinare il codice.
Il codificatore fornisce al decrittatore un feedback su ogni ipotesi, che il codificatore può utilizzare per perfezionare le proprie ipotesi.
Il gioco termina quando il decodificatore indovina il codice o quando esaurisce le ipotesi.







std::cout << "Benvenuto in MasterMind ti spiegherò in pochi e veloci passaggi:" << std::endl;
std::cout << "Il gioco consiste nel cercare di indovinare una sequenza di 4 colori scelti casualmente dal computer." << std::endl;
std::cout << "I colori disponibili sono: Rosso, Verde, Blu, Giallo, Arancione, Viola." << std::endl;
std::cout << "Ogni volta che inserisci una sequenza di 4 colori il computer ti dirà quanti colori sono corretti e quanti sono al posto giusto." << std::endl;
std::cout << "Buona fortuna!" << std::endl;
**/

#include <iostream>
#include <string>

class mastermind
{
private:
    int numero_mosse;
    std::string ultima_mossa;
    static const int DIM_GIOCATA_VALIDA = 4;
    int mossa_valida[DIM_GIOCATA_VALIDA];
    bool sanifica_input(std::string input)
    {
        if (DIM_GIOCATA_VALIDA != ultima_mossa.size())
        {
            return false;
            for (int i = 0; i < ultima_mossa.size(); i++)
            {
            char c = ultima_mossa[i];
            if (c >= '0' && c <= '9')
            }
                else if (c >= '0' && c <= '9')
            {
                mossa_valida[i] = c - '0';
                else if (c == '-')
                {
                    mossa_valida[i] = -1;
                }
                else
                {
                    return false;
                }

                return true;
            }

        public:
            mastermind(/* args */)
            {
                numero_mosse = 0;
                ultima_mossa = "";
            }
            void nuova_giocata()
            {

                do
                {
                    std::cout << numero_mosse + 1 << ":";
                    std::getline(std::cin, ultima_mossa);
                } while (!sanifica_input());

                std::cout << "Hai inserito: " << ultima_mossa << std::endl;
            }
            void risultato_mossa()
            {
                
            }
        };
