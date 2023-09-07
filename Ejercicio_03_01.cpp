// Materia: Programación I, Paralelo 1
// Autor: Jose Maria Cruz Llanos
// Fecha creación: 06/09/2023
// Fecha modificación: 07/09/2023
// Número de ejericio: 1
// Problema planteado: Elabore un programa que lea una matriz de orden n x n y la cambie la fila 1 por la fina n.

#include <iostream>

using namespace std;

const int MAX_FILAS = 100; 

int main() {
    int matriz[MAX_FILAS][MAX_FILAS];
    int n;

    
    cout << "Ingrese el valor de n (tamaño de la matriz): ";
    cin >> n;

    cout << "Ingrese los elementos de la matriz:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matriz[i][j];
        }
    }

    // Intercambiamos la primera fila con la última fila
    for (int j = 0; j < n; j++) {
        int temp = matriz[0][j];
        matriz[0][j] = matriz[n - 1][j];
        matriz[n - 1][j] = temp;
    }

    cout << "Matriz con la primera fila intercambiada por la última fila:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
