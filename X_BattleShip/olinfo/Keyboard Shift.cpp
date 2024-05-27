#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int N;
    string S;

    cin >> N;
    cin >> S;

    for (int i = 0; i < N; i++) {
        switch (S[i]) {
            case 'q':
                S[i] = 'w';
                break;
            case 'i':
                S[i] = 'o';
                break;
            case 'a':
                S[i] = 's';
                break;
            case 'y':
                S[i] = 'u';
                break;
            case 'x':
                S[i] = 'c';
                break;
            case 'g':
                S[i] = 'h';
                break;
            case 'f':
                S[i] = 'g';
                break;
        }
    } 
    cout << S << endl;
  
    return 0;
}
