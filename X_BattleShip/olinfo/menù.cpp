// Creator: GIUSEPPE CHIARENZA
// Created: 27/O5/2024
// Class: 3CIN



#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, b;
    cin >> n >> b;
    vector<int> v(n);
    for (int i=0; i<n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int sum = 0;
    for (int i=0; i<n; i++) {
        if (sum + v[i] <= b) {
            cout << v[i] << endl;
            sum += v[i];
        }
    }
    return 0;
}