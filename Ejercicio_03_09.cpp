// Materia: Programación I, Paralelo 1
// Autor: Jose Maria Cruz Llanos
// Fecha creación: 06/09/2023
// Fecha modificación: 07/09/2023
// Número de ejericio: 9
// Problema planteado:Traspones una matriz de N x M 

#include <iostream>
using namespace std;

int main() {
    int N, M;

    cout << "Ingrese el número de filas (N): ";
    cin >> N;
    cout << "Ingrese el número de columnas (M): ";
    cin >> M;

    int matriz[N][M];

    cout << "Ingrese los elementos de la matriz original (" << N << "x" << M << "):" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << "matriz[" << i << "][" << j << "]: ";
            cin >> matriz[i][j];
        }
    }

    int transpuesta[M][N];

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            transpuesta[i][j] = matriz[j][i];
        }
    }

    // Mostramos la matriz transpuesta
    cout << "Matriz transpuesta (" << M << "x" << N << "):" << endl;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cout << transpuesta[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}


