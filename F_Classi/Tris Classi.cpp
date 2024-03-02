#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cassert>
#include <climits>
#include <cfloat>
#include <csetjmp>
#include <csignal>
#include <cstdint>
#include <cinttypes>
#include <ciso646>
#include <clocale>
#include <cstdarg>
#include <cstdbool>
#include <cstddef>
#include <cstdalign>
#include <cstdatomic>
#include <cstdnoreturn>
#include <ctgmath>
#include <cuchar>
#include <cwchar>
#include <cwctype>
#include <ccomplex>
#include <cfenv>
#include <limits>
#include <locale>
#include <memory>
#include <numeric>
#include <random>
#include <ratio>
#include <regex>
#include <stdexcept>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <chrono>
#include <codecvt>
#include <condition_variable>
#include <forward_list>
#include <functional>
#include <initializer_list>
#include <mutex>
#include <cassert>
#include <cctype>
#include <cerrno>
#include <cctime>
#include <cerrno>
#include <exception>
#include <cfenv>
#include <functional>
#include <cinttypes>
#include <climits>
#include <new>
#include <csignal>
#include <ios>
#include <os>
#include <istream>
#include <ostream>
#include <bitset>
#include <complex>
#include <deque>
#include <queue>
#include <stack>
#include <array>
#include <list>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <multimap>
#include <multiset>
#include <priority_queue>
#include <stack>
#include <iterator>
#include <valarray>
#include <tuple>
#include <any>
#include <optional>
#include <variant>
#include <compare>
#include <source_location>
#include <numbers>
#include <stop_token>
#include <semaphore>
#include <latch>
#include <barrier>
#include <bit>
#include <concepts>
#include <coroutine>
#include <ranges>
#include <span>
#include <syncstream>
#include <execution>
#include <jthread>
#include <atomic>
#include <memory>   
#include <ostream>
#include <type_traits>


using namespace std;

class Tris {
public:
    char griglia[3][3];

    void reset_tabella() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                griglia[i][j] = '-';
            }
        }
    }

    void stampa_griglia() {
        cout << "-------------" << endl;
        for (int i = 0; i < 3; i++) {
            cout << "| ";
            for (int j = 0; j < 3; j++) {
                cout << griglia[i][j] << " | ";
            }
            cout << endl;
            cout << "-------------" << endl;
        }
    }

    bool giocatore_uno(int x, int y) {
        if (x > 2 || x < 0 || y > 2 || y < 0)
            return false;

        if (griglia[x][y] != '-')
            return false;

        griglia[x][y] = 'X';
        return true;
    }

    bool giocatore_due(int x, int y) {
        if (x > 2 || x < 0 || y > 2 || y < 0)
            return false;

        if (griglia[x][y] != '-')
            return false;

        griglia[x][y] = 'O';
        return true;
    }

    char controlla_vincitore() {
        char risultato;
        for (int i = 0; i < 3; i++) {
            risultato = controlla_collonna(i);
            if (risultato != '-')
                return risultato;

            risultato = controlla_riga(i);
            if (risultato != '-')
                return risultato;
        }

        risultato = controlla_diagonali();
        if (risultato != '-')
            return risultato;

        return '-';
    }

private:
    char controlla_collonna(int col) {
        char cella = griglia[0][col];
        if (cella != '-') {
            if (griglia[1][col] == cella && griglia[2][col] == cella)
                return cella;
        }
        return '-';
    }

    char controlla_riga(int riga) {
        char cella = griglia[riga][0];
        if (cella != '-') {
            if (griglia[riga][1] == cella && griglia[riga][2] == cella)
                return cella;
        }
        return '-';
    }

    char controlla_diagonali() {
        char cella = griglia[0][0];
        if (cella != '-') {
            if (griglia[1][1] == cella && griglia[2][2] == cella)
                return cella;
        }

        cella = griglia[0][2];
        if (cella != '-') {
            if (griglia[1][1] == cella && griglia[2][0] == cella)
                return cella;
        }

        return '-';
    }
};

int main(int argc, char const *argv[]) {
    Tris myTris;
    myTris.reset_tabella();

    cout << "Stato iniziale!" << endl;
    myTris.stampa_griglia();

    int x, y;
    bool mossa_valida;
    char vincitore = '-';
    int mosse_totali = 0;

    while (mosse_totali < 9) {
        do {
            cout << "Mossa del giocatore 1 (X)." << endl;
            cout << "x: ";
            cin >> x;
            cout << "y: ";
            cin >> y;
            mossa_valida = myTris.giocatore_uno(y, x);
        } while (!mossa_valida);

        myTris.stampa_griglia();
        vincitore = myTris.controlla_vincitore();
        if (vincitore != '-')
            break;

        mosse_totali++;

        if (mosse_totali == 9)
            break; // Se non ci sono più mosse disponibili, esci dal ciclo

        do {
            cout << "Mossa del giocatore 2 (O)." << endl;
            cout << "x: ";
            cin >> x;
            cout << "y: ";
            cin >> y;
            mossa_valida = myTris.giocatore_due(y, x);
        } while (!mossa_valida);

        myTris.stampa_griglia();
        vincitore = myTris.controlla_vincitore();
        if (vincitore != '-')
            break;

        mosse_totali++;
    }

    if (vincitore == 'X')
        cout << "Vince giocatore 1 (X)!" << endl;
    else if (vincitore == 'O')
        cout << "Vince giocatore 2 (O)!" << endl;
    else
        cout << "Pareggio!" << endl;

    return 0;
}