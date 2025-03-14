#include <stdio.h>
#include <stdlib.h>

int main() {
    int m, n;

    // Pedir tamaño de la matriz
    printf("Ingrese el número de filas: ");
    scanf("%d", &m);
    printf("Ingrese el número de columnas: ");
    scanf("%d", &n);

    // Validar entrada
    if (m <= 0 || n <= 0) {
        printf("Error: El número de filas y columnas debe ser mayor que 0.\n");
        return 1;
    }

    // Asignar memoria con calloc (inicializa con ceros)
    int *matrix = (int *)calloc(m * n, sizeof(int));
    if (matrix == NULL) {
        printf("Error: No se pudo asignar memoria.\n");
        return 1;
    }

    // Mostrar la matriz inicializada con ceros
    printf("Matriz inicializada con ceros:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i * n + j]); // Acceso correcto en una matriz almacenada en un array lineal
        }
        printf("\n");
    }

    // Leer la coordenada y el valor a modificar
    int row, col, value;
    printf("Ingrese las coordenadas (fila, columna) y el valor para modificar (ej. 1 2 5):\n");
    scanf("%d %d %d", &row, &col, &value);

    // Validar que las coordenadas estén dentro del rango
    if (row < 1 || row > m || col < 1 || col > n) {
        printf("Error: Coordenadas fuera de rango.\n");
    } else {
        matrix[(row - 1) * n + (col - 1)] = value; // Asignar valor en la posición correcta
    }

    // Mostrar la matriz actualizada
    printf("Matriz actualizada:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i * n + j]);
        }
        printf("\n");
    }

   // Liberar memoria
   free(matrix);

   return 0;
}

