#include <iostream>

#include "Tablero.h"
#include "TableroAB.h"
using namespace std;


int main() {
    // Crear una instancia del tablero para el juego sin poda alfa-beta
    Tablero* tablero = new Tablero();

    // Crear una instancia del tablero para el juego con poda alfa-beta
    TableroAB* tableroAB = new TableroAB();

    // Bucle para jugar el primer juego (sin optimización alfa-beta)
    while (!tablero->verificarGanador(tablero->getTablero()) && !tablero->empate(tablero->getTablero())) {
        std::cout << "===Juego 1===" << std::endl; // Indicar el inicio del juego 1
        tablero->imprimirTablero();               // Imprimir el estado actual del tablero
        tablero->juegoTablero();                  // Realizar el turno del jugador o de la IA
    }

    // Imprimir el estado final del tablero del juego 1
    tablero->imprimirTablero();

    // Verificar el resultado del juego 1
    if (tablero->verificarGanador(tablero->getTablero())) {
        std::cout << "El ganador es jugador " << tablero->getGanador() << std::endl;
    } else if (tablero->empate(tablero->getTablero())) {
        std::cout << "Es un Empate" << std::endl;
    }

    std::cout << "------------------------------------------------------------" << std::endl;

    // Liberar la memoria utilizada por el primer tablero
    delete tablero;

    // Bucle para jugar el segundo juego (con optimización alfa-beta)
    while (!tableroAB->verificarGanador(tableroAB->getTablero()) && !tableroAB->empate(tableroAB->getTablero())) {
        std::cout << "===Juego 2 alfabeta===" << std::endl; // Indicar el inicio del juego 2
        tableroAB->imprimirTablero();                       // Imprimir el estado actual del tablero
        tableroAB->juegoTablero();                          // Realizar el turno del jugador o de la IA optimizada
    }

    // Imprimir el estado final del tablero del juego 2
    tableroAB->imprimirTablero();

    // Verificar el resultado del juego 2
    if (tableroAB->verificarGanador(tableroAB->getTablero())) {
        std::cout << "El ganador es jugador " << tableroAB->getGanador() << std::endl;
    } else if (tableroAB->empate(tableroAB->getTablero())) {
        std::cout << "Es un Empate" << std::endl;
    }

    // Liberar la memoria utilizada por el segundo tablero
    delete tableroAB;

    return 0; // Finalizar el programa exitosamente
}
