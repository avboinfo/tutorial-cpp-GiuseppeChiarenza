// n e m int
// somma di tutti gli interi tra n e m

#include <iostream>

using namespace std;

void sommaNumeri(int n, int m, int &somma) {
    if (n == m) {
        somma = n;
    } else {
        sommaNumeri(n, m - 1, somma);
        somma += m;
    }
}

int main() {
    int n, m, somma = 0;
    cout << "il programma fa la somma di tutti gli interi tra n e m" << endl;
    cout << "n deve essere mi" << endl;
    cout << "Inserisci n: ";
    cin >> n;
    cout << "Inserisci m: ";
    cin >> m;
    sommaNumeri(n, m, somma);
    cout << "La somma dei numeri tra " << n << " e " << m << " è " << somma << endl;
    return 0;
}