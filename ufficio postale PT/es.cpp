#include <iostream>
#include "Coda.cpp"

using namespace std;

class poste{
    public:
    int size=9;
    string nome="o";

    Coda r = Coda(size, nome);

    poste(Coda goffredo, int size){
        this->r = goffredo;
        this->size = size;
    }

    void coda(Coda jonny, int size, int numerocliente ){
        jonny.enter(numerocliente);
        jonny.stampa();

    }


};

int main(){
    int size=9;
    int numerocliente=32;
    int numerocliente1=33;
    string nome="o";
    Coda goffredo = Coda(size, nome);
    poste bob = poste(goffredo, size);
    bob.coda(goffredo,size, numerocliente);
    bob.coda(goffredo,size, numerocliente1);


    
}