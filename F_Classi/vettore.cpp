/* GIUSEPPE CHIARENZA
   3CIN 04/03/2024
   CLASSE VETTORE 
   Scrivere sul quaderno e portare in classe l'intera classe Vettore (di interi) in C++, completa degli attributi e dei metodi: costruttore, add, remove (elimina e restituisce l'ultimo elemento inserito) e print. 
*/

#include <iostream>

using namespace std;

class Vettore{

    protected:

    int dim, len;
    int * v;

    public:
    
    Vettore (int d){
        dim=d;
        len=0;
        v=new int[dim];
    }

    void  add(int n){
        if(len==dim){cout<<"Vettore pieno"<<endl; return;}
            v[len] = n;
            len++;
        }
    }

    void print(){
        cout<<"Contenuto del Vettore: ";
        for(int i=0; i<v.len; i++){cout<<v[i]<<" ";}
        cout<<endl;
    }

    void remove(){
        int ue=v[len-1];
        v.dim--;
        v.len--;
        cout<<"Elemento eliminato: "<<ue<<endl;

    }
};

int main (int argc, char * argv[]){
    Vettore Vett(10);
    Vett.add(5);
    Vett.print();
    Vett.remove();
    Vett.print();
}