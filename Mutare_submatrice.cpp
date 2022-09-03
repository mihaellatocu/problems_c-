#include <iostream>
using namespace std;

const int LENGTH_MATRIX = 51;

int main() {
    int n, m[LENGTH_MATRIX + 1][LENGTH_MATRIX + 1];
    int TotalDiagonal = 0;
    int DiagonalaMaxima = -100;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> m[i][j];
        }
    }
    // parcurgem fiecare element de pe prima linie
    for (int j = n; j >= 1; --j) {
        int linie = 1, coloana = j;
        // parcurgem paralela la diagonala partea de deasupra
        TotalDiagonal = 0;
        while (linie <= n && coloana <= n) {
            TotalDiagonal += m[linie][coloana];
            ++linie;
            ++coloana;
        }
        if (DiagonalaMaxima < TotalDiagonal) {
            DiagonalaMaxima = TotalDiagonal;
        }
    }
    for (int i = 2; i <= n; ++i) {
        int linie = i, coloana = 1;
        // parcurgem paralela la diagonala, partea de sub diagonala
        TotalDiagonal = 0;
        while (linie <= n && coloana <= n) {
            TotalDiagonal += m[linie][coloana];
            ++linie;
            ++coloana;
        }
        if (DiagonalaMaxima < TotalDiagonal) {
            DiagonalaMaxima = TotalDiagonal;
        }
    }
    for (int i = 1; i <= n; ++i) {
        int linie = i, coloana = 1;
        // parcurgem paralela la diagonala secundara, partea de sus
        TotalDiagonal = 0;
        while (linie >= 1 && coloana <= n) {
            TotalDiagonal += m[linie][coloana];
            --linie;
            ++coloana;
        }
        if (DiagonalaMaxima < TotalDiagonal) {
            DiagonalaMaxima = TotalDiagonal;
        }
    }
    for (int j = 2; j <= n; ++j) {
        int linie = n, coloana = j;
        // parcurgem paralela la diagonal secundara, partea de jos
        TotalDiagonal = 0;
        while (linie >= 1 && coloana <= n) {
            TotalDiagonal += m[linie][coloana];
            --linie;
            ++coloana;
        }
        if (DiagonalaMaxima < TotalDiagonal) {
            DiagonalaMaxima = TotalDiagonal;
        }
    }
    cout << DiagonalaMaxima;
    return 0;
}
