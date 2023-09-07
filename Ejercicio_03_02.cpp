// Materia: Programación I, Paralelo 1
// Autor: Jose Maria Cruz Llanos
// Fecha creación: 06/09/2023
// Fecha modificación: 07/09/2023
// Número de ejericio: 2
// Problema planteado: Generar la matriz espiral para un orden n : Sea n=3:

#include <iostream>
using namespace std;

const int MAX_FILAS = 100; 
int main() {
    int n;

    // Pedimos al usuario el tamaño de la matriz (n x n)
    cout << "Ingrese el valor de n (tamaño de la matriz espiral): ";
    cin >> n;

    int matriz[MAX_FILAS][MAX_FILAS];
    
    int valor = 1;
    int inicioFila = 0;
    int finFila = n - 1;
    int inicioColumna = 0;
    int finColumna = n - 1;

    while (valor <= n * n) {
        for (int i = inicioColumna; i <= finColumna; i++) {
            matriz[inicioFila][i] = valor++;
        }
        inicioFila++;

        for (int i = inicioFila; i <= finFila; i++) {
            matriz[i][finColumna] = valor++;
        }
        finColumna--;

        for (int i = finColumna; i >= inicioColumna; i--) {
            matriz[finFila][i] = valor++;
        }
        finFila--;

        for (int i = finFila; i >= inicioFila; i--) {
            matriz[i][inicioColumna] = valor++;
        }
        inicioColumna++;
    }

    cout << "Matriz en forma de espiral para n=" << n << ":" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matriz[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}

