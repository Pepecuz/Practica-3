// Materia: Programación I, Paralelo 1
// Autor: Jose Maria Cruz Llanos
// Fecha creación: 06/09/2023
// Fecha modificación: 07/09/2023
// Número de ejericio: 6
// Problema planteado: Generar una matriz NxN, que se llene con la serie de Fibonacci

#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Ingrese el valor de N (tamaño de la matriz): ";
    cin >> n;

    long long matriz[n][n];

    long long a = 0, b = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matriz[i][j] = a;
            long long temp = a + b;
            a = b;
            b = temp;
        }
    }

    cout << "Matriz generada con la serie de Fibonacci de " << n << "x" << n << ":" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
