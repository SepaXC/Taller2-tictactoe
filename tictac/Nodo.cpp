#include "Nodo.h"

#include "Nodo.h"

// Constructor
Nodo::Nodo() : puntaje(0) {
    // Inicializar el tablero vacío
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            tablero[i][j] = ' ';
        }
    }
}

// Destructor: libera los nodos hijos recursivamente
Nodo::~Nodo() {
    for (Nodo* hijo : hijos) {
        delete hijo;
    }
}