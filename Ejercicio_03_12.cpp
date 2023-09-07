// Materia: Programación I, Paralelo 1
// Autor: Jose Maria Cruz Llanos
// Fecha creación: 06/09/2023
// Fecha modificación: 07/09/2023
// Número de ejericio: 12
// Problema planteado: Ingresa una matriz de NxN y a continuación:
//a. Elimine una fila ingresada por el usuario.
//b. Elimine una columna ingresada por el usuario.
//c. Inserte una fila por un valor determinado por el usuario.
//d. Inserte una columna por un valor determinado por el usuario.

#include <iostream>
using namespace std;

const int MAX_N = 10;

void imprimirMatriz(int matriz[MAX_N][MAX_N], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}

void eliminarFila(int matriz[MAX_N][MAX_N], int &n, int filaEliminar) {
    if (filaEliminar >= 0 && filaEliminar < n) {
        for (int i = filaEliminar; i < n - 1; i++) {
            for (int j = 0; j < n; j++) {
                matriz[i][j] = matriz[i + 1][j];
            }
        }
        n--;
    } else {
        cout << "Fila a eliminar fuera de rango." << endl;
    }
}

void eliminarColumna(int matriz[MAX_N][MAX_N], int &n, int columnaEliminar) {
    if (columnaEliminar >= 0 && columnaEliminar < n) {
        for (int i = 0; i < n; i++) {
            for (int j = columnaEliminar; j < n - 1; j++) {
                matriz[i][j] = matriz[i][j + 1];
            }
        }
        n--;
    } else {
        cout << "Columna a eliminar fuera de rango." << endl;
    }
}

void insertarFila(int matriz[MAX_N][MAX_N], int &n, int filaInsertar, int valor) {
    if (filaInsertar >= 0 && filaInsertar <= n) {
        for (int i = n; i > filaInsertar; i--) {
            for (int j = 0; j < n; j++) {
                matriz[i][j] = matriz[i - 1][j];
            }
        }
        for (int j = 0; j < n; j++) {
            matriz[filaInsertar][j] = valor;
        }
        n++;
    } else {
        cout << "Fila a insertar fuera de rango." << endl;
    }
}


void insertarColumna(int matriz[MAX_N][MAX_N], int &n, int columnaInsertar, int valor) {
    if (columnaInsertar >= 0 && columnaInsertar <= n) {
        for (int i = 0; i < n; i++) {
            for (int j = n; j > columnaInsertar; j--) {
                matriz[i][j] = matriz[i][j - 1];
            }
            matriz[i][columnaInsertar] = valor;
        }
        n++;
    } else {
        cout << "Columna a insertar fuera de rango." << endl;
    }
}

int main() {
    int n;

    cout << "Ingrese el tamaño de la matriz (N): ";
    cin >> n;

    if (n <= 0 || n > MAX_N) {
        cout << "El tamaño de la matriz no es válido." << endl;
        return 1;
    }

    int matriz[MAX_N][MAX_N];

    cout << "Ingrese los elementos de la matriz de " << n << "x" << n << ":" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matriz[i][j];
        }
    }

    cout << "Matriz original:" << endl;
    imprimirMatriz(matriz, n);

    int opcion;
    do {
        cout << "Opciones:" << endl;
        cout << "1. Eliminar una fila" << endl;
        cout << "2. Eliminar una columna" << endl;
        cout << "3. Insertar una fila" << endl;
        cout << "4. Insertar una columna" << endl;
        cout << "5. Salir" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                int filaEliminar;
                cout << "Ingrese la fila a eliminar: ";
                cin >> filaEliminar;
                eliminarFila(matriz, n, filaEliminar);
                break;
            case 2:
                int columnaEliminar;
                cout << "Ingrese la columna a eliminar: ";
                cin >> columnaEliminar;
                eliminarColumna(matriz, n, columnaEliminar);
                break;
            case 3:
                int filaInsertar, valorFila;
                cout << "Ingrese la fila a insertar: ";
                cin >> filaInsertar;
                cout << "Ingrese el valor para la fila: ";
                cin >> valorFila;
                insertarFila(matriz, n, filaInsertar, valorFila);
                break;
            case 4:
                int columnaInsertar, valorColumna;
                cout << "Ingrese la columna a insertar: ";
                cin >> columnaInsertar;
                cout << "Ingrese el valor para la columna: ";
                cin >> valorColumna;
                insertarColumna(matriz, n, columnaInsertar, valorColumna);
                break;
            case 5:
                break;
            default:
                cout << "Opción no válida. Inténtelo de nuevo." << endl;
        }

        if (opcion >= 1 && opcion <= 4) {
            cout << "Matriz modificada:" << endl;
            imprimirMatriz(matriz, n);
        }
    } while (opcion != 5);

    return 0;
}
