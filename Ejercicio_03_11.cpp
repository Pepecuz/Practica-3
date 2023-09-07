// Materia: Programación I, Paralelo 1
// Autor: Jose Maria Cruz Llanos
// Fecha creación: 06/09/2023
// Fecha modificación: 07/09/2023
// Número de ejericio: 11
// Problema planteado:Realizar el típico juego del 3 en raya, donde habrá dos jugadores que tengan que
//hacer el 3 en raya, los signos serán el X y el O, cuando haya una posición vacía
//habrá un – El tablero de juego, será una matriz de 3×3 de char.
//El juego termina cuando uno de los jugadores hace 3 en raya o si no hay más
//posiciones que poner.
//El juego debe pedir las posiciones donde el jugador actual quiera poner su
//marca, esta debe ser validada y por supuesto que no haya una marca ya puesta.
//Por último mostrar la matriz del juego y muestra al ganador.

#include <iostream>
using namespace std;

const int SIZE = 3;

void imprimirTablero(char tablero[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << tablero[i][j] << " ";
        }
        cout << endl;
    }
}

bool verificarGanador(char tablero[SIZE][SIZE], char jugador) {
    for (int i = 0; i < SIZE; i++) {
        if (tablero[i][0] == jugador && tablero[i][1] == jugador && tablero[i][2] == jugador) {
            return true; // Ganador en fila i
        }
        if (tablero[0][i] == jugador && tablero[1][i] == jugador && tablero[2][i] == jugador) {
            return true; // Ganador en columna i
        }
    }


    if (tablero[0][0] == jugador && tablero[1][1] == jugador && tablero[2][2] == jugador) {
        return true; 
    }
    if (tablero[0][2] == jugador && tablero[1][1] == jugador && tablero[2][0] == jugador) {
        return true; 
    }

    return false; 
}

int main() {
    char tablero[SIZE][SIZE];
    char jugadorActual = 'X';
    int fila, columna;
    int movimientos = 0;
    bool juegoTerminado = false;

    // Inicializar el tablero
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            tablero[i][j] = '-';
        }
    }

    // Juego principal
    while (movimientos < SIZE * SIZE && !juegoTerminado) {
        cout << "Turno del jugador " << jugadorActual << endl;
        imprimirTablero(tablero);
        cout << "Ingrese la fila (0, 1, 2): ";
        cin >> fila;
        cout << "Ingrese la columna (0, 1, 2): ";
        cin >> columna;

        if (fila >= 0 && fila < SIZE && columna >= 0 && columna < SIZE && tablero[fila][columna] == '-') {
            tablero[fila][columna] = jugadorActual;
            movimientos++;

            if (verificarGanador(tablero, jugadorActual)) {
                juegoTerminado = true;
                cout << "¡El jugador " << jugadorActual << " ha ganado!" << endl;
                imprimirTablero(tablero);
            } else {
                jugadorActual = (jugadorActual == 'X') ? 'O' : 'X';
            }
        } else {
            cout << "Movimiento inválido. Inténtalo de nuevo." << endl;
        }
    }

    if (!juegoTerminado) {
        cout << "¡Es un empate!" << endl;
    }

    return 0;
}
