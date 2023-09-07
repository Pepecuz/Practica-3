// Materia: Programación I, Paralelo 1
// Autor: Jose Maria Cruz Llanos
// Fecha creación: 06/09/2023
// Fecha modificación: 07/09/2023
// Número de ejericio: 4
// Problema planteado:En la segunda temporada de The Walking Dead, los personajes llegaron a una
//cárcel para refugiarse. La cárcel estaba rodeada de vallas por lo que los muertos
//vivientes no podían entrar en ella. Sin embargo, dentro de las instalaciones aun
//existían muertos vivientes que amenazaban a los personajes. Por tanto, Rick y
//otros miembros del grupo decidieron ir a investigar las instalaciones con el fin
//de determinar cuáles eran los lugares seguros. Para lograr su objetivo
//construyeron un mapa basado en una matriz que indicaba las zonas seguras.
//Después de un tiempo, tu grupo llega al mismo complejo y encuentra el mapa
//hecho por Rick. Para mantener a salvo a tus amigos decides diseñar e
//implementar un programa que te ayude a determinar las zonas seguras.
//Tu trabajo es determinar los siguientes datos:
//a) Mostrar la matriz que describe el área.
//b) Mostrar el número de filas y columnas que no tienen un muerto viviente.
//c) Determinar las coordenadas de los muertos vivientes en la matriz. Utilice vectores
//paralelos para almacenar la posición de los muertos vivientes. Un vector almacenara el
//índice de la fila y otro vector almacenara el índice de la columna.
//d) La cantidad de muertos vivientes que existen en toda la matriz.
//e) Determinar si dos o más muertos vivientes se encuentran en la primera columna. Si
//es así imprimir “no es posible entrar al complejo” de otro modo imprimir “es posible
//entrar al complejo”.

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int filas, columnas;

    
    cout << "Ingrese el número de filas: ";
    cin >> filas;
    cout << "Ingrese el número de columnas: ";
    cin >> columnas;

   
    vector<vector<char>> area(filas, vector<char>(columnas));
    vector<int> filasMuertos, columnasMuertos;

  
    cout << "Ingrese la descripción del área:" << endl;
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cin >> area[i][j];
            if (area[i][j] == 'M') {
                filasMuertos.push_back(i);
                columnasMuertos.push_back(j);
            }
        }
    }

   
    cout << "Matriz del área:" << endl;
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cout << area[i][j] << " ";
        }
        cout << endl;
    }

    
    int filasSeguras = 0, columnasSeguras = 0;
    for (int i = 0; i < filas; i++) {
        bool tieneMuerto = false;
        for (int j = 0; j < columnas; j++) {
            if (area[i][j] == 'M') {
                tieneMuerto = true;
                break;
            }
        }
        if (!tieneMuerto) {
            filasSeguras++;
        }
    }
    for (int j = 0; j < columnas; j++) {
        bool tieneMuerto = false;
        for (int i = 0; i < filas; i++) {
            if (area[i][j] == 'M') {
                tieneMuerto = true;
                break;
            }
        }
        if (!tieneMuerto) {
            columnasSeguras++;
        }
    }

    int cantidadMuertos = filasMuertos.size();

    bool esPosibleEntrar = true;
    for (int i = 0; i < filasMuertos.size(); i++) {
        if (columnasMuertos[i] == 0) {
            esPosibleEntrar = false;
            break;
        }
    }

    // Mostramos los resultados
    cout << "Número de filas sin muertos vivientes: " << filasSeguras << endl;
    cout << "Número de columnas sin muertos vivientes: " << columnasSeguras << endl;
    cout << "Cantidad de muertos vivientes: " << cantidadMuertos << endl;
    
    if (esPosibleEntrar) {
        cout << "Es posible entrar al complejo." << endl;
    } else {
        cout << "No es posible entrar al complejo." << endl;
    }

    return 0;
}
