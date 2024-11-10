/*
Zur Abgabe einen branch `iprg-b01` erstellen und pushen, in dem als einzige Datei die `01ex.c` liegt.
*/

/*
Um die Tests für dieses Blatt zu kompilieren und zu starten, führen Sie den folgenden Befehl aus:
clang -std=c11 -g -Wall -Werror 01ex_test.c -o 01ex_test.o -lm && ./01ex_test.o

Wir empfehlen, mit möglichst streng eingestelltem valgrind zu testen, denn so testen wir auch auf dem Server:
clang -std=c11 -g -Wall -Werror 01ex_test.c -o 01ex_test.o -lm && valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./01ex_test.o
*/

#include "array_visualizer.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/*
Aufgabe 1:
Machen Sie sich in dieser Aufgabe mit dem `Visualizer` (siehe array_visualizer.h) vertraut.
Nutzen Sie die `visualizer_append_array` Funktion, um die Tests zum durchlaufen zu bringen.

Tipp 1: Die erste Zeile im erzeugten Bild stellt das Eingabearray dar.
Tipp 2: Jede weitere Zeile wird aus der Zeile davor durch eine einfache Modifikation gewonnen. Die Modifikation ist immer die gleiche.
*/

void warmup(Visualizer *v, uint8_t *arr, size_t len) {
    // First row is the original array
    visualizer_append_array(v, arr);
    
    // Create a working array for subsequent rows
    uint8_t *current_row = (uint8_t *)malloc(len * sizeof(uint8_t));
    memcpy(current_row, arr, len * sizeof(uint8_t));
    
    // For each subsequent row
    for (size_t i = 1; i < len; i++) {
        // Shift everything one position right
        for (size_t j = len - 1; j >= i; j--) {
            current_row[j] = current_row[j-1];
        }
        // Fill ALL positions up to i with the value of the first column
        for (size_t j = 0; j < i; j++) {
           current_row[j] = arr[0];
        }
        
        visualizer_append_array(v, current_row);
    }
    
    free(current_row);
}

/*
Aufgabe 2:
Bringen Sie die Tests zum durchlaufen.

Tipp: Die erste Zeile im erzeugten Bild stellt das Eingabearray dar.
*/
void sort_it(Visualizer *v, uint8_t *arr, size_t len) {
    
}


