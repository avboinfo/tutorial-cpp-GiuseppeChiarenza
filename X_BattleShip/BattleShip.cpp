/*
** BattleShip.cpp una classe per giocare alla Battaglia Navale
** Giuseppe Chiarenza - 20/04/2024 3cin
*/

#include <iostream>
#include "BattleField.cpp"

class BattleShip {

private:
    BattleField mappa;
    BattleField campo;

public:
    BattleShip() {
        mappa = BattleField(VOID);
        campo = BattleField(VOID);
        campo.placeHorizontalShip(3);
        campo.placeVerticalShip(4);
        campo.placeVerticalShip(2);
        campo.placeHorizontalShip(5);
    }

    void play() {

        /*
        // lancia 20 bombe a caso
        for (int i=0; i<20; i++) {
            int x = rand() % DIM;
            int y = rand() % DIM;
            if (campo.get(x,y)==HIT) continue;
            if (campo.get(x,y)==SHIP) {
                mappa.put(x,y,HIT);
                campo.put(x,y,HIT);
            } else mappa.put(x,y,MISS);
        }
        */

       while(!isGameOver()) {
            mappa.stampa();

            if (!ask()) {
                break;
            } 

            campo.stampa();
            
        }

    }

    bool ask() {
        std::cout << "Dove vuoi lanciare la bomba? (x y)";
        int x, y;
        std::cin >> x;
        std::cin >> y;

        if (x <= 0 || x >= DIM || y <= 0 || y >= DIM) {
            std::cout << "Coordinate non valide" << std::endl;
            return false;
        } else {
            x--;
            y--;
        }

        if (campo.get(x,y)==SHIP) {
            mappa.put(x,y,HIT);
            campo.put(x,y,HIT);
        } else{
            mappa.put(x,y,MISS);
        }
        return true;
    }

    bool isGameOver() {
        for (int i=0; i<DIM; i++) {
            for (int j=0; j<DIM; j++) {
                if (campo.get(i,j)==SHIP) return false;
            }
        }
        return true;
    }

};