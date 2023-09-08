// Materia: Programación I, Paralelo 1
// Autor: Jose Maria Cruz Llanos
// Fecha creación: 14/08/2023
// Fecha modificación: 15/08/2023
// Número de ejericio: 15
// Problema planteado: Cubo magico

#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Ingrese el tamanio del cuadrado magico para n impar: ";
    cin >> n;

    if (n % 2 == 0) {
        cout << "El orden del cuadrado magico debe ser impar." << endl;
        return 1;
    }

    int cuadradoMagico[15][15] = {0}; 
    int fila = 0;
    int columna = n / 2;

    for (int numero = 1; numero <= n * n; numero++) {
        cuadradoMagico[fila][columna] = numero;

        fila--;
        columna++;
if (numero % n == 0) {
            fila += 2;
            columna--;
        } else {
            if (fila < 0) {
                fila = n - 1;
            }
            if (columna == n) {
                columna = 0;
            }
        }
    }

    cout << "Cuadrado Mágico de Orden " << n << ":" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << cuadradoMagico[i][j] << "\t";
        }
    }
    return 0;
}