// Materia: Programación I, Paralelo 1
// Autor: Jose Maria Cruz Llanos
// Fecha creación: 06/09/2023
// Fecha modificación: 07/09/2023
// Número de ejericio: 13
// Problema planteado: La farmacia FARMACARP tiene N sucursales, leer sus ventas por mes de un
//año entero de cada sucursal y calcule:
//7a. Total, de ventas
//b. Total, de ventas por sucursal.
//c. Sucursal que más ha vendido.
//d. Sucursal que menos ha vendido.

#include <iostream>
using namespace std;

const int MAX_SUCURSALES = 10;
const int MESES = 12;

int main() {
    int N;

    // Pedimos al usuario el número de sucursales
    cout << "Ingrese el número de sucursales (N): ";
    cin >> N;

    if (N <= 0 || N > MAX_SUCURSALES) {
        cout << "Número de sucursales no válido." << endl;
        return 1;
    }

    int ventas[MAX_SUCURSALES][MESES];
    int totalVentas = 0;
    int sucursalMasVendida = 0;
    int sucursalMenosVendida = 0;
    int maxVentas = 0;
    int minVentas = INT_MAX;

    // Leer las ventas por mes de cada sucursal
    for (int i = 0; i < N; i++) {
        cout << "Ingrese las ventas por mes para la sucursal " << (i + 1) << ":" << endl;
        for (int j = 0; j < MESES; j++) {
            cin >> ventas[i][j];
            totalVentas += ventas[i][j];

            if (ventas[i][j] > maxVentas) {
                maxVentas = ventas[i][j];
                sucursalMasVendida = i;
            }

            if (ventas[i][j] < minVentas) {
                minVentas = ventas[i][j];
                sucursalMenosVendida = i;
            }
        }
    }

    // Calcular el total de ventas por sucursal
    int totalVentasPorSucursal[MAX_SUCURSALES] = {0};
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < MESES; j++) {
            totalVentasPorSucursal[i] += ventas[i][j];
        }
    }

    // Mostrar resultados
    cout << "a. Total de ventas: $" << totalVentas << endl;
    cout << "b. Total de ventas por sucursal:" << endl;
    for (int i = 0; i < N; i++) {
        cout << "   Sucursal " << (i + 1) << ": $" << totalVentasPorSucursal[i] << endl;
    }
    cout << "c. Sucursal que más ha vendido: Sucursal " << (sucursalMasVendida + 1) << " ($" << maxVentas << ")" << endl;
    cout << "d. Sucursal que menos ha vendido: Sucursal " << (sucursalMenosVendida + 1) << " ($" << minVentas << ")" << endl;

    return 0;
}
