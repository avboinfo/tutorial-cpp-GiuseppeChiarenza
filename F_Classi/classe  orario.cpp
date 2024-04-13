/**
 Giuseppe Chiarenza 3cin 16/03/24
 Il secondo programma definisce una classe "Orario" per la gestione di dati di tipo orario nella forma H:M:S 
 (H rappresenta le ore, M i minuti ed S i secondi con 0 ≤ H < 24, 0 ≤ M < 60, 0 ≤ S < 60).
 Oltre a un costruttore adeguato e ai metodi di accesso agli attributi,
 la classe deve prevedere metodi per effettuare le seguenti operazioni:

 -) restituzione di una stringa che rappresenta il valore dell’orario;

 -) restituzione del valore dell’orario in secondi trascorsi dalla mezzanotte;

 -) calcolo della differenza tra due orari espressa in secondi.

 Dimostrare nel main il funzionamento della classe con dati di prova.
**/

#include <iostream>
#include <string>

using namespace std;

class Orario {
public:
    int ore, minuti, secondi;

    Orario(int h, int m, int s) {
        if (h < 0 || h > 23 || m < 0 || m > 59 || s < 0 || s > 59) {
            cout << "Orario non valido" << endl;
            return;
        }
        ore = h;
        minuti = m;
        secondi = s;
    }

    string to_string() {
        return to_string(ore) + ":" + to_string(minuti) + ":" + to_string(secondi);
    }

    int to_secondi() {
        return ore * 3600 + minuti * 60 + secondi;
    }

    int differenza(Orario o) {
        return to_secondi() - o.to_secondi();
    }    

};

int main() {
    Orario o1(12, 30, 0);
    Orario o2(14, 47, 56);

    cout << "Ora 1: " << o1.to_string() << endl;
    cout << "Ora 2: " << o2.to_string() << endl;
    cout << "Secondi trascorsi da mezzanotte per l'orario 1: " << o1.to_secondi() << endl;
    cout << "Secondi trascorsi da mezzanotte per l'orario 2: " << o2.to_secondi() << endl;
    cout << "Differenza tra l'orario 1 e l'orario 2: " << o1.differenza(o2) << " secondi" << endl;

    return 0;
}