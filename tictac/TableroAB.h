//
// Created by Sepaxl based in vicent code on 12/7/2024.
//
#ifndef TABLEROAB_H // Verifica que el archivo de encabezado no haya sido definido previamente
#define TABLEROAB_H

#include <utility>  // Para usar funciones y estructuras de utilidad estándar
#include "Nodo.h"   // Incluye la definición de la clase Nodo necesaria para manejar el árbol de decisiones

// Clase TableroAB: Representa el tablero del juego con IA utilizando el algoritmo Minimax con poda Alfa-Beta
class TableroAB {
public:
    // Constructor: Inicializa el tablero vacío
    TableroAB();

    // Imprime el estado actual del tablero en la consola
    void imprimirTablero();

    // Gestiona los turnos del jugador humano y la IA
    bool juegoTablero();

    // Verifica si hay un ganador en el tablero actual
    bool verificarGanador(const char tablero[3][3]);

    // Verifica si el juego ha terminado en empate
    bool empate(const char tablero[3][3]);

    // Encuentra el mejor movimiento posible para la IA utilizando Minimax con poda Alfa-Beta
    void encontrarMejorMovimientoConArbol(int& mejorFila, int& mejorColumna);

    // Genera un árbol de decisiones explorando todos los movimientos posibles
    void generarArbolDeDecisiones(Nodo* nodo, bool esTurnoIA, char jugadorIA, char jugadorHumano);

    // Implementación del algoritmo Minimax con poda Alfa-Beta para optimizar el árbol de decisiones
    int minimaxConNodosAlphaBeta(Nodo* nodo, bool esMaximizador, char jugadorIA, char jugadorHumano, int alpha, int beta);

    // Libera la memoria ocupada por el árbol de decisiones
    void liberarArbol(Nodo* nodo);

    // Devuelve el estado actual del tablero
    const char(&getTablero() const)[3][3];

    // Devuelve el símbolo del jugador ganador, si lo hay
    char getGanador();

private:
    char tablero[3][3];  // Matriz que representa el estado actual del tablero
    char jugador1 = 'X'; // Símbolo que representa al jugador humano
    char jugador2 = 'O'; // Símbolo que representa a la IA
    char ganador = 'C';  // Indica el ganador actual ('X', 'O', o 'C' para continuar)
};

#endif // TABLEROAB_H
