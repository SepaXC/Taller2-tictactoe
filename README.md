# Taller2-tictactoe
poda alfabetha y minmax


Proyecto de Juego de Tic-Tac-Toe con y sin Poda Alfa-Beta

Este proyecto presenta una implementación de un juego de Tic-Tac-Toe en C++. Incluye dos versiones del juego:

•	Una versión estándar sin optimización de búsqueda.

•	Una versión que emplea la técnica de poda alfa-beta para optimizar la búsqueda del movimiento ideal por parte de la IA.

La estructura del proyecto incorpora dos clases principales:
•	Tablero: Implementa el juego sin optimizaciones.
•	TableroAB: Implementa el juego con la poda alfa-beta, mejorando la eficiencia a la hora de tomar decisiones.

Características

·        Juego 1 (sin poda alfa-beta):

La IA selecciona movimientos sin ningún tipo de optimización, explorando el espacio de búsqueda de forma más extensa y, por ende, menos eficiente.

·        Juego 2 (con poda alfa-beta):
La IA emplea poda alfa-beta para reducir el número de estados que deben ser evaluados. Esto se traduce en una ejecución más rápida y una toma de decisiones más óptima.

·        Detección de Ganador y Empate:
Ambos tableros detectan automáticamente la condición de victoria de un jugador o un empate, finalizando el juego en consecuencia.

·        Interfaz de Consola:
Se muestra el estado actual del tablero en cada turno, y el usuario (o la IA) realiza los movimientos hasta que se determina el resultado final.

Requisitos del Sistema

•	Un compilador C++ compatible con el estándar C++11 o superior (por ejemplo, g++ o clang++).

•	Sistema operativo: Linux, macOS o Windows.

•	No se requieren librerías externas.

Instrucciones de Compilación y Ejecución

1.     Clonar el repositorio:

git clone https://github.com/usuario/repo-tres-en-raya.git
cd repo-tres-en-raya
 
Compilar el código:

Dependiendo de tu entorno, puedes
g++ main.cpp Tablero.cpp TableroAB.cpp -o juego

Asegúrate de incluir todos los archivos .cpp necesarios y tener a mano los correspondientes .h.

2.     Ejecutar el programa

./juego

3.     Interacción:

Sigue las instrucciones en consola para realizar tus movimientos (normalmente ingresando posiciones o pulsando Enter según el diseño de juegoTablero()).

Estructura del Código

·        main.cpp:

Contiene el punto de entrada del programa. Aquí se crean las instancias de Tablero y TableroAB, se llevan a cabo las partidas, y se muestran los resultados.

·        Tablero.h / Tablero.cpp:

Implementación del juego sin poda alfa-beta. Incluye métodos para:

•	Crear y gestionar el tablero.

•	Detectar el estado del juego (ganador, empate).

•	Imprimir el tablero.

•	Mover jugadores y/o IA.

·        TableroAB.h / TableroAB.cpp:

Implementación del juego con poda alfa-beta, optimizando el cálculo del mejor movimiento. Añade:

•	Algoritmo de minimax con poda alfa-beta.

•	Heurísticas o evaluaciones para seleccionar el mejor movimiento.

Diagramas

![image](https://github.com/user-attachments/assets/e555d96b-250e-428f-b82e-2f100c2fb670)

![image](https://github.com/user-attachments/assets/b77c957c-7525-423b-80b4-f2eabd6a1994)

![image](https://github.com/user-attachments/assets/2b3cf643-3c0b-43db-b089-272873b994eb)



