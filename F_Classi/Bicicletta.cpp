/*
** Bicicletta.cpp
*/

#include <iostream>
using namespace std;

class Bicicletta {
  public:
    int raggio;
    string colore;
    Bicicletta( int r, string c ) {
        raggio=r;
        colore="c";
    }
     Bicicletta( ) {
        raggio=10;
        colore="nero";
    void presentati() {
        cout << "Buongiorno, sono una bici di colore " << colore << " e con le ruote " << raggio << "!" << endl;
    }
};

int main()
{
    Bicicletta x;
    Bicicletta y(12,"rossa");

    x.presentati();
    y.presentati();

    return 0;
}
