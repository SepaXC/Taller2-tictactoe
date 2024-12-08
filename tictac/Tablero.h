//
// Created by vicen on 12/07/2024.
// Edited by Sebastian Pleticosic on 12/08/2024
//

#ifndef TABLERO_H
#define TABLERO_H

#include <utility>
#include "Nodo.h" // Incluye la definición de la clase Nodo, utilizada en la generación del árbol

// Clase Tablero: Maneja la lógica y representación del juego
class Tablero {
private:
    char tablero[3][3]; // Representación del tablero de 3x3 como matriz de caracteres
    char jugador1 = 'X'; // Símbolo del jugador 1
    char jugador2 = 'O'; // Símbolo del jugador 2
    char ganador = 'C';  // Indica el ganador actual del juego ('C' para continuar o sin ganador)

public:
    Tablero(); // Constructor para inicializar un tablero vacío

    // Imprime el estado actual del tablero
    void imprimirTablero();

    // Gestiona los turnos de los jugadores y actualiza el tablero
    bool juegoTablero();

    // Verifica si hay un ganador en el tablero dado
    bool verificarGanador(const char tablero[3][3]);

    // Verifica si el juego ha terminado en empate
    bool empate(const char tablero[3][3]);

    // Encuentra el mejor movimiento para la IA utilizando Minimax con generación de árbol
    void encontrarMejorMovimientoConArbol(int& mejorFila, int& mejorColumna);

    // Genera un árbol de decisiones para explorar posibles movimientos
    void generarArbolDeDecisiones(Nodo* nodo, bool esTurnoIA, char jugadorIA, char jugadorHumano);

    // Implementa el algoritmo Minimax utilizando nodos del árbol
    int minimaxConNodos(Nodo* nodo, bool esMaximizador, char jugadorIA, char jugadorHumano);

    // Libera la memoria utilizada por el árbol de decisiones
    void liberarArbol(Nodo* nodo);

    // Devuelve el estado actual del tablero
    const char(&getTablero() const)[3][3];

    // Devuelve el ganador actual del juego
    char getGanador();
};

#endif //TABLERO_H
