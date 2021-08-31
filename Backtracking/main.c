// Backtracking. Daniel Fern�ndez Mart�nez.

#include <stdio.h>
#include <string.h>

// Tama�o del tablero
#define N 4

// Contador de soluciones
int count = 0;

int main()
{
    // Matriz N X N
    char tablero[N][N];

    // Inicializaci�n de la matriz con "-"
    memset(tablero, '-', sizeof tablero);

    // LLamada a la funci�n principal
    nReinas(tablero, 0);

    printf("Soluciones totales: %d", count);

    return 0;
}

// Funci�n para evaluar si una posici�n es segura
int testPosicion(char tablero[][N], int f, int c)
{
    // �Hay dos reinas en la misma columna?
    for (int i = 0; i < f; i++)
    {
        if (tablero[i][c] == '*') {
            return 0;
        }

    }

    // �Hay dos reinas en la misma `\` diagonal?
    for (int i = f, j = c; i >= 0 && j >= 0; i--, j--)
    {
        if (tablero[i][j] == '*') {
            return 0;
        }
    }

    // �Hay dos reinas en la misma `/` diagonal?
    for (int i = f, j = c; i >= 0 && j < N; i--, j++)
    {
        if (tablero[i][j] == '*') {
            return 0;
        }
    }

    return 1;
}

// Funci�n para mostrar una soluci�n por pantalla
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
    // Si las N reinas han sido colocadas, muestra la soluci�n
    if (f == N)
    {
        printSolucion(tablero);
        return;
    }

    // Recorremos por columnas
    for (int i = 0; i < N; i++)
    {
        // Verificamos si es segura la posici�n
        if (testPosicion(tablero, f, i) == 1)
        {
            // Colocamos la reina en la posici�n actual
            tablero[f][i] = '*';

            // Recursividad: siguiente reina
            nReinas(tablero, f + 1);

            // Backtracking: si no es posible colocar las N reinas, eliminamos la reina de la posici�n actual
            tablero[f][i] = '-';
        }
    }
}
