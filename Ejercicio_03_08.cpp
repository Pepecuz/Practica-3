// Materia: Programación I, Paralelo 1
// Autor: Jose Maria Cruz Llanos
// Fecha creación: 06/09/2023
// Fecha modificación: 07/09/2023
// Número de ejericio: 8
// Problema planteado:Multiplique dos matrices una de N x M y la otra de M x N

#include <iostream>
using namespace std;

int main() {
    int N, M;

    cout << "Ingrese el número de filas (N) de la primera matriz: ";
    cin >> N;
    cout << "Ingrese el número de columnas (M) de la primera matriz y filas de la segunda matriz: ";
    cin >> M;

    if (N <= 0 || M <= 0) {
        cout << "La multiplicación de matrices no es posible con estas dimensiones." << endl;
        return 1;
    }

    int matriz1[N][M];
    int matriz2[M][N];
    int resultado[N][N];

    cout << "Ingrese los elementos de la primera matriz (" << N << "x" << M << "):" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << "matriz1[" << i << "][" << j << "]: ";
            cin >> matriz1[i][j];
        }
    }

    cout << "Ingrese los elementos de la segunda matriz (" << M << "x" << N << "):" << endl;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cout << "matriz2[" << i << "][" << j << "]: ";
            cin >> matriz2[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            resultado[i][j] = 0;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                resultado[i][j] += matriz1[i][k] * matriz2[k][j];
            }
        }
    }

    cout << "Matriz resultado (" << N << "x" << N << "):" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << resultado[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
