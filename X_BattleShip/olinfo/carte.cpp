#include <fstream>
#include <iostream>
#include <vector>

int scarta(int C, std::vector<bool> L, std::vector<bool> D, std::vector<bool> N) {
    int numLaura = 0;
    int numDaria = 0;
    int numNoemi = 0;

    for (int i = 0; i < C; i++) {
        numLaura += L[i] && !D[i] && !N[i];
        numDaria += D[i] && !L[i] && !N[i];
        numNoemi += N[i] && !L[i] && !D[i];
    }

    return std::max(numLaura, std::max(numDaria, numNoemi));
}

int main() {
 

        int C;
        std::cin >> C;

        std::vector<bool> L(C, false), D(C, false), N(C, false);
    for (int i = 0; i < C; i++) {
        int l, d, n;
        std::cin >> l >> d >> n;
        if (l) L[i] = true;
        if (d) D[i] = true;
        if (n) N[i] = true;
    }

    std::cout << scarta(C, L, D, N);

    return 0;
}
