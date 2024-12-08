#include "TableroAB.h"
#include <iostream>
#include <algorithm> // Para std::max y std::min
#include <chrono>    // Para medir el tiempo de ejecución (tiempo de "pensar")

TableroAB::TableroAB() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            tablero[i][j] = ' '; // Cada celda inicia vacía
        }
    }
}

void TableroAB::imprimirTablero() {
    std::cout << "  1   2   3" << std::endl;
    for (int i = 0; i < 3; ++i) {
        std::cout << i + 1 << " ";
        for (int j = 0; j < 3; ++j) {
            std::cout << tablero[i][j];
            if (j < 2) std::cout << " | ";
        }
        std::cout << std::endl;
        if (i < 2) std::cout << " ---+---+---" << std::endl;
    }
    std::cout << std::endl;
}

bool TableroAB::juegoTablero() {
    static int turno = 0;
    char jugadorActual = (turno % 2 == 0) ? jugador1 : jugador2;

    if (jugadorActual == jugador1) {
        int fila, columna;
        std::cout << "Turno de " << jugadorActual << std::endl;
        std::cout << "Ingresa la fila y columna (1-3): ";
        std::cin >> fila >> columna;

        fila -= 1;
        columna -= 1;

        if (fila < 0 || fila >= 3 || columna < 0 || columna >= 3) {
            std::cout << "Entrada inválida. Intenta de nuevo." << std::endl;
            return false;
        }

        if (tablero[fila][columna] != ' ') {
            std::cout << "Celda ocupada. Intenta de nuevo." << std::endl;
            return false;
        }

        tablero[fila][columna] = jugadorActual;
    } else {
        std::cout << "Turno de la IA (" << jugadorActual << "):" << std::endl;

        // Iniciar medición de tiempo de "pensamiento"
        auto inicio = std::chrono::high_resolution_clock::now();

        int mejorFila, mejorColumna;
        encontrarMejorMovimientoConArbol(mejorFila, mejorColumna);

        auto fin = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> tiempo = fin - inicio;

        // Imprimir el tiempo que tardó la IA en pensar
        std::cout << "La IA ha elegido su movimiento en " << tiempo.count() << " ms." << std::endl;

        tablero[mejorFila][mejorColumna] = jugadorActual;
        ganador = jugadorActual;
    }

    turno++;
    return true;
}

bool TableroAB::verificarGanador(const char tablero[3][3]) {
    // Filas
    for (int i = 0; i < 3; ++i) {
        if (tablero[i][0] != ' ' &&
            tablero[i][0] == tablero[i][1] &&
            tablero[i][1] == tablero[i][2]) {
            return true;
        }
    }
    // Columnas
    for (int j = 0; j < 3; ++j) {
        if (tablero[0][j] != ' ' &&
            tablero[0][j] == tablero[1][j] &&
            tablero[1][j] == tablero[2][j]) {
            return true;
        }
    }
    // Diagonales
    if (tablero[0][0] != ' ' &&
        tablero[0][0] == tablero[1][1] &&
        tablero[1][1] == tablero[2][2]) {
        return true;
    }

    if (tablero[0][2] != ' ' &&
        tablero[0][2] == tablero[1][1] &&
        tablero[1][1] == tablero[2][0]) {
        return true;
    }
    return false;
}

bool TableroAB::empate(const char tablero[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (tablero[i][j] == ' ') {
                return false;
            }
        }
    }
    return !verificarGanador(tablero);
}

void TableroAB::encontrarMejorMovimientoConArbol(int& mejorFila, int& mejorColumna) {
    Nodo* raiz = new Nodo();
    std::copy(&tablero[0][0], &tablero[0][0] + 9, &raiz->tablero[0][0]);

    generarArbolDeDecisiones(raiz, true, jugador2, jugador1);
    // Ahora utilizamos minimax con poda alfa-beta
    minimaxConNodosAlphaBeta(raiz, true, jugador2, jugador1, -1000, 1000);

    int mejorPuntaje = -1000;
    for (Nodo* hijo : raiz->hijos) {
        if (hijo->puntaje > mejorPuntaje) {
            mejorPuntaje = hijo->puntaje;
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    if (hijo->tablero[i][j] != tablero[i][j]) {
                        mejorFila = i;
                        mejorColumna = j;
                    }
                }
            }
        }
    }

    liberarArbol(raiz);
}

void TableroAB::generarArbolDeDecisiones(Nodo* nodo, bool esTurnoIA, char jugadorIA, char jugadorHumano) {
    char jugadorActual = esTurnoIA ? jugadorIA : jugadorHumano;

    // Si ya hay ganador o empate, no generar más hijos.
    if (verificarGanador(nodo->tablero) || empate(nodo->tablero))
        return;

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (nodo->tablero[i][j] == ' ') {
                Nodo* hijo = new Nodo();
                std::copy(&nodo->tablero[0][0], &nodo->tablero[0][0] + 9, &hijo->tablero[0][0]);
                hijo->tablero[i][j] = jugadorActual;
                nodo->hijos.push_back(hijo);
                generarArbolDeDecisiones(hijo, !esTurnoIA, jugadorIA, jugadorHumano);
            }
        }
    }
}

int TableroAB::minimaxConNodosAlphaBeta(Nodo* nodo, bool esMaximizador, char jugadorIA, char jugadorHumano, int alpha, int beta) {
    if (nodo == nullptr) {
        std::cerr << "Error: nodo nulo en minimaxConNodosAlphaBeta" << std::endl;
        return 0;
    }

    // Verificar si el nodo actual es un estado terminal
    if (verificarGanador(nodo->tablero)) {
        return esMaximizador ? -10 : 10;
    }

    if (empate(nodo->tablero)) {
        return 0;
    }

    if (esMaximizador) {
        int maxEval = -1000;
        for (Nodo* hijo : nodo->hijos) {
            if (hijo == nullptr) continue;
            int eval = minimaxConNodosAlphaBeta(hijo, false, jugadorIA, jugadorHumano, alpha, beta);
            maxEval = std::max(maxEval, eval);
            alpha = std::max(alpha, eval);
            if (beta <= alpha) {
                // Poda
                break;
            }
        }
        nodo->puntaje = maxEval;
        return maxEval;
    } else {
        int minEval = 1000;
        for (Nodo* hijo : nodo->hijos) {
            if (hijo == nullptr) continue;
            int eval = minimaxConNodosAlphaBeta(hijo, true, jugadorIA, jugadorHumano, alpha, beta);
            minEval = std::min(minEval, eval);
            beta = std::min(beta, eval);
            if (beta <= alpha) {
                // Poda
                break;
            }
        }
        nodo->puntaje = minEval;
        return minEval;
    }
}

void TableroAB::liberarArbol(Nodo* nodo) {
    if (nodo == nullptr) return;

    for (Nodo* hijo : nodo->hijos) {
        if (hijo != nullptr) {
            liberarArbol(hijo);
            hijo = nullptr;
        }
    }

    nodo->hijos.clear();
    delete nodo;
    nodo = nullptr;
}

const char(&TableroAB::getTablero() const)[3][3] {
    return tablero;
}

char TableroAB::getGanador(){
    return ganador;
}

