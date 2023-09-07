// Materia: Programación I, Paralelo 1
// Autor: Jose Maria Cruz Llanos
// Fecha creación: 06/09/2023
// Fecha modificación: 07/09/2023
// Número de ejericio: 5
// Problema planteado: Generar la matriz para un orden NxN

#include <iostream>
using namespace std;

int main() {
    int n;

   
    cout << "Ingrese el valor de N (tamaño de la matriz): ";
    cin >> n;

    int matriz[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matriz[i][j] = 0;  
        }
    }

    cout << "Matriz generada de " << n << "x" << n << ":" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
