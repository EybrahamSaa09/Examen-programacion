#include <stdio.h>
#include <string.h>

int main() {
    char nombres[5][30];
    int puntos[5][4];
    float promedios[5];
    float suma_puntos;
    float mejor_promedio = -1;
    int mejor_jugador = -1;
    int entrada_valida;

    printf("\n=== ESTADISTICAS DE JUGADORES DE BASQUET ===\n");

    // Ingresar nombres de los jugadores
    for (int i = 0; i < 5; i++) {
        printf("\nIngrese el nombre del jugador %d: ", i + 1);
        fflush(stdin);
        fgets(nombres[i], 30, stdin);
        nombres[i][strlen(nombres[i]) - 1] = '\0';
    }

    // Ingresar puntos por partido de cada jugador
    for (int i = 0; i < 5; i++) {
        printf("\nEstadisticas de %s:\n", nombres[i]);
        suma_puntos = 0;
        for (int j = 0; j < 4; j++) {
            do {
                printf("  Partido %d: Puntos anotados: ", j + 1);
                scanf("%d", &puntos[i][j]);
                if (puntos[i][j] < 0) {
                    printf("Error: Los puntos no pueden ser negativos.\n");
                    entrada_valida = 0;
                } else {
                    entrada_valida = 1;
                }
            } while (!entrada_valida);
            suma_puntos += puntos[i][j];
        }
        promedios[i] = suma_puntos / 4.0;
    }

    // Encontrar el mejor jugador
    for (int i = 0; i < 5; i++) {
        if (promedios[i] > mejor_promedio) {
            mejor_promedio = promedios[i];
            mejor_jugador = i;
        }
    }

    // Mostrar tabla de resultados
    printf("\n=== TABLA DE RESULTADOS ===\n");
    printf("%-20s", "Jugador");
    for (int i = 1; i <= 4; i++) {
        printf("%-10s", "Partido");
    }
    printf("%-10s\n", "Promedio");
    printf("-------------------------------------------------------------\n");
    for (int i = 0; i < 5; i++) {
        printf("%-20s", nombres[i]);
        for (int j = 0; j < 4; j++) {
            printf("%-10d", puntos[i][j]);
        }
        printf("%-10.2f\n", promedios[i]);
    }

    // Mostrar el mejor jugador
    if (mejor_jugador != -1) {
        printf("\nEl mejor jugador con un promedio de %.2f puntos es: %s\n", mejor_promedio, nombres[mejor_jugador]);
    }

    return 0;
}