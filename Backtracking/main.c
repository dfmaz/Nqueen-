// Backtracking. Daniel Fernández Martínez.

#include <stdio.h>
#include <string.h>

// Tamaño del tablero
#define N 4

// Contador de soluciones
int count = 0;

int main()
{
    // Matriz N X N
    char tablero[N][N];

    // Inicialización de la matriz con "-"
    memset(tablero, '-', sizeof tablero);

    // LLamada a la función principal
    nReinas(tablero, 0);

    printf("Soluciones totales: %d", count);

    return 0;
}

// Función para evaluar si una posición es segura
int testPosicion(char tablero[][N], int f, int c)
{
    // ¿Hay dos reinas en la misma columna?
    for (int i = 0; i < f; i++)
    {
        if (tablero[i][c] == '*') {
            return 0;
        }

    }

    // ¿Hay dos reinas en la misma `\` diagonal?
    for (int i = f, j = c; i >= 0 && j >= 0; i--, j--)
    {
        if (tablero[i][j] == '*') {
            return 0;
        }
    }

    // ¿Hay dos reinas en la misma `/` diagonal?
    for (int i = f, j = c; i >= 0 && j < N; i--, j++)
    {
        if (tablero[i][j] == '*') {
            return 0;
        }
    }

    return 1;
}

// Función para mostrar una solución por pantalla
void printSolucion(char tablero[][N])
{
    count++;
    printf("Solucion %d:\n", count);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++) {
            printf("%c ", tablero[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Algoritmo para resolver el problema con backtracking
void nReinas(char tablero[][N], int f)
{
    // Si las N reinas han sido colocadas, muestra la solución
    if (f == N)
    {
        printSolucion(tablero);
        return;
    }

    // Recorremos por columnas
    for (int i = 0; i < N; i++)
    {
        // Verificamos si es segura la posición
        if (testPosicion(tablero, f, i) == 1)
        {
            // Colocamos la reina en la posición actual
            tablero[f][i] = '*';

            // Recursividad: siguiente reina
            nReinas(tablero, f + 1);

            // Backtracking: si no es posible colocar las N reinas, eliminamos la reina de la posición actual
            tablero[f][i] = '-';
        }
    }
}
