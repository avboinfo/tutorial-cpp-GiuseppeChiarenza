/*
    Main.cpp
    Main file for the BattleShip game
    Giuseppe Chiarenza - 22/04/2024 3cin  
*/

#include <iostream>
#include "BattleShip.cpp"
using namespace std;

int main(){
    cout << "Benvenuto in " << endl;
    BattleShip gioco = BattleShip();
    gioco.play();
    cout << "Fine gioco" << endl;
    return 0;
}