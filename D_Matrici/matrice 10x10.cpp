/**
 Giuseppe Chiarenza 3cin 16/03/24

 Il primo programma svolge il seguente compito: crea una matrice di interi 10x10, 
 la riempe di numeri casuali tra 0 e 99, 
 la stampa a video,
 chiede all'utente un numero a piacere e calcola e stampa quante volte questo numero è presente in una qualsiasi cella 
 della matrice e quante volte è presente una delle celle della diagonale principale. 
 Utilizzare laddove opportuno delle funzioni per svolgere certe parti del programma,
  richiamandole poi dal main.

**/

#include <iostream>

using namespace std;

void riempiMatrice(int matrice[10][10])
{
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
        {
            matrice[i][j] = rand()%100;
        }
    }
}

void stampaMatrice(int matrice[10][10])
{
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
        {
            cout<<matrice[i][j]<<" ";
        }
        cout<<endl;
    }
}

int contaNumero(int matrice[10][10], int numero)
{
    int contatore = 0;
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
        {
            if(matrice[i][j] == numero)
            {
                contatore++;
            }
        }
    }
    return contatore;
}

int contaDiagonale(int matrice[10][10], int numero)
{
    int contatore = 0;
    for(int i=0; i<10; i++)
    {
        if(matrice[i][i] == numero)
        {
            contatore++;
        }
    }
    return contatore;
}




int main()
{
    cout<<"ciao ben venuto nel programma"<<endl;
    cout<<"Scegli un numero a piacere e io ti dirò quante volte e presente nella matrice e nelle sue diagonali  "<<endl;
    int numero;
    cin>>numero;
    int matrice[10][10];
    riempiMatrice(matrice);
    stampaMatrice(matrice);
    cout<<"Il numero "<<numero<<" è presente "<<contaNumero(matrice, numero)<<" volte nella matrice"<<endl;
    cout<<"Il numero "<<numero<<" è presente "<<contaDiagonale(matrice, numero)<<" volte nella diagonale principale"<<endl;

    return 0;
}

