#include <stdio.h>
#include <stdlib.h>

int main() {
    int size = 2; // Inicializa con un número pequeño
    int *arr = (int *)malloc(size * sizeof(int)); // Reserva memoria inicial
    if (arr == NULL) {
        printf("Error: No se pudo asignar memoria.\n");
        return 1;
    }

    int count = 0;
    int num;
    printf("Ingrese números (ingrese -1 para terminar):\n");
    
    while (1) {
        scanf("%d", &num);
        if (num == -1) break; // Rompe el ciclo si el usuario ingresa -1

        // Redimensionar el arreglo si es necesario
        if (count >= size) {
            size *= 2;
            int *temp = (int *)realloc(arr, size * sizeof(int)); // Reasigna memoria
            if (temp == NULL) {
                printf("Error: No se pudo reasignar memoria.\n");
                free(arr); // Libera la memoria antes de salir
                return 1;
            }
            arr = temp; // Asigna el nuevo puntero a arr
        }
        arr[count++] = num; // Agrega el número al arreglo
    }

    // Imprimir la lista
    printf("La lista ingresada es: ");
    for (int i = 0; i < count; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Liberar la memoria
    free(arr);

    return 0;
}
