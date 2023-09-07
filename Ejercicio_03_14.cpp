// Materia: Programación I, Paralelo 1
// Autor: Jose Maria Cruz Llanos
// Fecha creación: 06/09/2023
// Fecha modificación: 07/09/2023
// Número de ejericio: 14
// Problema planteado: Simule una elección de nuestro país Bolivia. En ello se mostrará las elecciones
//por departamento y existirá N candidatos.
//El programa debe pedir la cantidad de votos por departamento y candidato y
//almacenarlos en una matriz.
//El programa debe calcular lo siguiente:
//• Si un candidato gana con el 50% + 1 voto es ganador absoluto.
//• Si no ningún candidato que logre el 50% + 1 voto el programa debe sacar
//los dos mas votados para una segunda vuelta.

#include <iostream>
using namespace std;

const int MAX_DEPARTAMENTOS = 9; 
const int MAX_CANDIDATOS = 10;  

int main() {
    int N; 
    int departamentos[MAX_DEPARTAMENTOS];
    int votos[MAX_DEPARTAMENTOS][MAX_CANDIDATOS];
    
    cout << "Ingrese el número de candidatos: ";
    cin >> N;

    if (N <= 0 || N > MAX_CANDIDATOS) {
        cout << "Número de candidatos no válido." << endl;
        return 1;
    }

  
    for (int i = 0; i < MAX_DEPARTAMENTOS; i++) {
        departamentos[i] = 0;
        for (int j = 0; j < N; j++) {
            votos[i][j] = 0;
        }
    }

    // Pedimos al usuario ingresar los votos por departamento y candidato
    for (int i = 0; i < MAX_DEPARTAMENTOS; i++) {
        cout << "Departamento " << (i + 1) << ":" << endl;
        for (int j = 0; j < N; j++) {
            cout << "Votos para candidato " << (j + 1) << ": ";
            cin >> votos[i][j];
            departamentos[i] += votos[i][j];
        }
    }

    // Verificamos si hay un ganador absoluto
    bool hayGanadorAbsoluto = false;
    int ganadorAbsoluto = -1;
    for (int j = 0; j < N; j++) {
        int totalVotosCandidato = 0;
        for (int i = 0; i < MAX_DEPARTAMENTOS; i++) {
            totalVotosCandidato += votos[i][j];
        }
        if (totalVotosCandidato > departamentos[0] / 2) {
            hayGanadorAbsoluto = true;
            ganadorAbsoluto = j;
            break;
        }
    }

    // Mostramos los resultados
    if (hayGanadorAbsoluto) {
        cout << "El candidato " << (ganadorAbsoluto + 1) << " es el ganador absoluto." << endl;
    } else {
        cout << "Ningún candidato logra el 50% + 1 voto. Se realiza una segunda vuelta." << endl;

        // Encontrar los dos candidatos más votados
        int masVotado = -1, segundoMasVotado = -1;
        int votosMasVotado = -1, votosSegundoMasVotado = -1;

        for (int j = 0; j < N; j++) {
            int totalVotosCandidato = 0;
            for (int i = 0; i < MAX_DEPARTAMENTOS; i++) {
                totalVotosCandidato += votos[i][j];
            }

            if (totalVotosCandidato > votosMasVotado) {
                segundoMasVotado = masVotado;
                votosSegundoMasVotado = votosMasVotado;
                masVotado = j;
                votosMasVotado = totalVotosCandidato;
            } else if (totalVotosCandidato > votosSegundoMasVotado) {
                segundoMasVotado = j;
                votosSegundoMasVotado = totalVotosCandidato;
            }
        }

        cout << "Candidato " << (masVotado + 1) << " y Candidato " << (segundoMasVotado + 1) << " pasan a la segunda vuelta." << endl;
    }

    return 0;
}
