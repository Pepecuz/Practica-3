// Materia: Programación I, Paralelo 1
// Autor: Jose Maria Cruz Llanos
// Fecha creación: 06/09/2023
// Fecha modificación: 07/09/2023
// Número de ejericio: 7
// Problema planteado:Efectuar la suma de una matriz tridimensional de orden n x n x n

#include <iostream>
using namespace std;

int main() {
    int n;
    
  
    cout << "Ingrese el valor de n (tamaño de la matriz tridimensional): ";
    cin >> n;
    
    int matriz[n][n][n];
    
    cout << "Ingrese los elementos de la matriz tridimensional:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                cout << "matriz[" << i << "][" << j << "][" << k << "]: ";
                cin >> matriz[i][j][k];
            }
        }
    }
    
    int suma = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                suma += matriz[i][j][k];
            }
        }
    }
    
    cout << "La suma de todos los elementos de la matriz tridimensional es: " << suma << endl;
    
    return 0;
}
