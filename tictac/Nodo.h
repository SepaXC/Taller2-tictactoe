#ifndef NODO_H
#define NODO_H

#include <vector>

// Nodo para el árbol de decisiones
struct Nodo {
    char tablero[3][3];              // Estado actual del tablero
    int puntaje;                     // Puntaje asociado al nodo
    std::vector<Nodo*> hijos;        // Hijos que representan las jugadas posibles

    Nodo();                          // Constructor
    ~Nodo();                         // Destructor para liberar memoria recursivamente
};

#endif // NODO_H
