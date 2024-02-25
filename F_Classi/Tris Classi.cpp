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
#include <osdtream>
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

using namespace std;

class Tris
{
public:
    int griglia[3][3];

    void reset_tabella()
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                griglia[i][j] = 0;
            }
        }
    }

    void stampa_griglia()
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cout << griglia[i][j] << "\t";
            }
            cout << endl;
        }
    }

    bool giocatore_uno(int x, int y)
    {
        if (x > 2 || x < 0)
            return false;

        if (y > 2 || y < 0)
            return false;

        if (griglia[x][y] == 1 || griglia[x][y] == 2)
            return false;

        griglia[x][y] = 1;
        return true;
    }

    bool giocatore_due(int x, int y)
    {
        if (x > 2 || x < 0)
            return false;

        if (y > 2 || y < 0)
            return false;

        if (griglia[x][y] == 1 || griglia[x][y] == 2)
            return false;

        griglia[x][y] = 2;
        return true;
    }

    int controlla_vincitore()
    {
        int risultato;
        for (int i = 0; i < 3; i++)
        {
            risultato = controlla_collonna(i);
            if (risultato != 0)
                return risultato;

            risultato = controlla_riga(i);
            if (risultato != 0)
                return risultato;
        }

        risultato = controlla_diagonali(); // Controllo le diagonali
        if (risultato != 0)
            return risultato;

        return 0;
    }

private:
    int controlla_collonna(int col)
    {
        int acc_uno = 0;
        int acc_due = 0;
        for (int i = 0; i < 3; i++)
        {
            int cella = griglia[i][col];
            if (cella == 1)
                acc_uno++;
            else if (cella == 2)
                acc_due++;
        }

        if (acc_uno == 3)
            return 1;
        if (acc_due == 3)
            return 2;
        return 0;
    }

    int controlla_riga(int riga)
    {
        int acc_uno = 0;
        int acc_due = 0;
        for (int i = 0; i < 3; i++)
        {
            int cella = griglia[riga][i];
            if (cella == 1)
                acc_uno++;
            else if (cella == 2)
                acc_due++;
        }

        if (acc_uno == 3)
            return 1;
        if (acc_due == 3)
            return 2;
        return 0;
    }

    int controlla_diagonali()
    {
        int acc_uno = 0;
        int acc_due = 0;


        for (int i = 0; i < 3; i++)
        {
            int cella = griglia[i][i];
            if (cella == 1)
                acc_uno++;
            else if (cella == 2)
                acc_due++;
        }

        if (acc_uno == 3)
            return 1;
        if (acc_due == 3)
            return 2;

        acc_uno = 0;
        acc_due = 0;

        for (int i = 0; i < 3; i++)
        {
            int cella = griglia[i][2 - i];
            if (cella == 1)
                acc_uno++;
            else if (cella == 2)
                acc_due++;
        }

        if (acc_uno == 3)
            return 1;
        if (acc_due == 3)
            return 2;

        return 0;
    }
};

int main(int argc, char const *argv[])
{
    Tris myTris;

    myTris.reset_tabella();

    cout << "Stato iniziale!" << endl;
    myTris.stampa_griglia();

    int x, y;
    bool mossa_valida;
    int vincitore = 0;
    int mosse_totali = 0;

    while (mosse_totali < 9)
    {
        do
        {
            cout << "Mossa del giocatore 1." << endl;
            cout << "x: ";
            cin >> x;

            cout << "y: ";
            cin >> y;

            mossa_valida = myTris.giocatore_uno(x, y);
        } while (!mossa_valida);

        myTris.stampa_griglia();

        vincitore = myTris.controlla_vincitore();
        if (vincitore != 0)
            break;

        mosse_totali++;

        if (mosse_totali == 9)
            break; // Controllo per parità

        do
        {
            cout << "Mossa del giocatore 2." << endl;
            cout << "x: ";
            cin >> x;

            cout << "y: ";
            cin >> y;

            mossa_valida = myTris.giocatore_due(x, y);
        } while (!mossa_valida);

        myTris.stampa_griglia();

        vincitore = myTris.controlla_vincitore();
        if (vincitore != 0)
            break;

        mosse_totali++;
    }

    if (vincitore == 1)
        cout << "Vince giocatore 1!" << endl;
    else if (vincitore == 2)
        cout << "Vince giocatore 2!" << endl;
    else
        cout << "Pareggio!" << endl;

    return 0;
}