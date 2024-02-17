#include <iostream>

using namespace std;
class Tris{
public:
    int griglia[3][3];

    void reset_tabella(){
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                griglia[i][j]=0;
            }
        }
    }

    void stampa_griglia(){
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                cout << griglia[i][j] << "\t";
            }
            cout << endl;
        }
    }

    bool giocatore_uno(int x, int y){
        if((x > 2 || x < 0 || y > 2 || y < 0)){
            cout << "Mossa non valida!" << endl;
            return false;
        }
        if (griglia[x][y] == 1 || griglia[x][y] == 2){
            cout << "Mossa non valida!" << endl;
            return false;
        }
        griglia[x][y] = 1;
        return true;
    }

    bool giocatore_due(int x, int y){
        if((x > 2 || x < 0 || y > 2 || y < 0)){
            cout << "Mossa non valida!" << endl;
            return false;
        }
        if (griglia[x][y] == 1 || griglia[x][y] == 2){
            cout << "Mossa non valida!" << endl;
            return false;
        }
        griglia[x][y] = 2;
        return true;
        
    }

};

int main(int argc, char const* argv[]){

    Tris myTris;

    myTris.reset_tabella();

    cout << "Stato iniziale!" << endl;
    myTris.stampa_griglia();

    int x, y;
    bool mossa_valida;
    do     {
      cout << "Mossa del giocatore 1." << endl;
      cout << "x: ";
      cin >> x;

      cout << "y: ";
      cin >> y;

      mossa_valida = myTris.giocatore_uno(x, y);
    
    } while (!mossa_valida);

    cout << "Stato attuale!" << endl;
    myTris.stampa_griglia();
        do     {
      cout << "Mossa del giocatore 2." << endl;
      cout << "x: ";
      cin >> x;

      cout << "y: ";
      cin >> y;

      mossa_valida = myTris.giocatore_due(x, y);
    
    } while (!mossa_valida);

    return 0;
}
