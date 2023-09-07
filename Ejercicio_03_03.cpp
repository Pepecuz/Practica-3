// Materia: Programación I, Paralelo 1
// Autor: Jose Maria Cruz Llanos
// Fecha creación: 06/09/2023
// Fecha modificación: 07/09/2023
// Número de ejericio: 3
// Problema planteado: Generar una matriz de N x N con números al azar entre A y B, y determinar:
//• La suma de la última columna
//• El producto total de la última fila
//• Obtener el mayor valor y su posición
//• Obtener la desviación estándar de todos los elementos de la matriz

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>

using namespace std;

const int MAX_FILAS = 100; 

int main() {
    int n, A, B;

    
    cout << "Ingrese el valor de N (tamaño de la matriz): ";
    cin >> n;

   
    cout << "Ingrese el valor de A: ";
    cin >> A;
    cout << "Ingrese el valor de B: ";
    cin >> B;

    int matriz[MAX_FILAS][MAX_FILAS];

    
    srand(time(0)); 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matriz[i][j] = rand() % (B - A + 1) + A;
        }
    }

    // Calcular la suma de la última columna
    int sumaUltimaColumna = 0;
    for (int i = 0; i < n; i++) {
        sumaUltimaColumna += matriz[i][n - 1];
    }

    // Calcular el producto total de la última fila
    int productoUltimaFila = 1;
    for (int j = 0; j < n; j++) {
        productoUltimaFila *= matriz[n - 1][j];
    }

    // Encontrar el mayor valor y su posición
    int mayorValor = matriz[0][0];
    int filaMayor = 0;
    int columnaMayor = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matriz[i][j] > mayorValor) {
                mayorValor = matriz[i][j];
                filaMayor = i;
                columnaMayor = j;
            }
        }
    }

   
    double media = 0.0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            media += matriz[i][j];
        }
    }
    media /= (n * n);

    double desviacionEstandar = 0.0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            desviacionEstandar += pow(matriz[i][j] - media, 2);
        }
    }
    desviacionEstandar = sqrt(desviacionEstandar / (n * n));

   
    cout << "Matriz generada:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Suma de la última columna: " << sumaUltimaColumna << endl;
    cout << "Producto total de la última fila: " << productoUltimaFila << endl;
    cout << "Mayor valor: " << mayorValor << " (Posición: Fila " << filaMayor + 1 << ", Columna " << columnaMayor + 1 << ")" << endl;
    cout << "Desviación estándar de todos los elementos de la matriz: " << desviacionEstandar << endl;

    return 0;
}
