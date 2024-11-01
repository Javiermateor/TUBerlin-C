/*
Willkommen zum achten Aufgabenblatt vom Programmierkurs. Auf diesem Aufabenblatt geht es um Pointer und Arrays.

Um die Tests für dieses Blatt zu kompilieren und zu starten, führen Sie den folgenden Befehl aus:
clang -std=c11 -g -Wall 08ex_test.c -o 08ex_test.o -lm && ./08ex_test.o
clang -std=c11 -g -Wall 08ex_test.c -o 08ex_test.o && 08ex_test.o
*/

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "turtlecanvas.h"

/*
Aufgabe 1a:
Lesen Sie das Headerfile `turtlecanvas.h`. Diese Funktion soll die Turtle `d` Schritte vorwärts machen lassen.
*/
void turtle_advance_by(TurtleCanvas *c, uint32_t d) {

    //Schildkröte bewegt sich d Schritte vorwärts
    for (uint32_t i = 0; i < d; i++) {
        turtle_advance(c);
    }
}

/*
Aufgabe 1b:
Füllen Sie die Turtlecanvas mit horizontalen, abwechselnd schwarzen und weißen Linien (die unterste Zeile soll
schwarz gefärbt werden). Die Turtle ist anfangs an Position (0, 0), ist nach rechts orientiert, und zeichnet schwarz.
*/
void turtle_stripes(TurtleCanvas *c) {
    size_t width = turtle_canvas_width(c);
    size_t height = turtle_canvas_height(c);

    // Initial position and black line
    turtle_advance_by(c, width);

    for (size_t y = 0; y < height; y++) {
        turtle_rotate_left(c);      // North
        turtle_advance(c);          // Move 
        turtle_rotate_right(c);      // East to return to start
        turtle_toggle_color(c);     // Toggle color
        turtle_advance_by(c, width); // Draw line
    }
}

/*
Aufgabe 1c:
Lesen Sie die Implementierungen der Turtlecanvas-Funktionen weiter unten in der "turtlecanvas.h".
Der Quellcode sollte vollständig verständlich und unüberraschend sein.
Hinweis: Diese Aufgabe wird nicht bewertet.
*/

/*
Aufgabe 2a:
Geben Sie einen Pointer auf das erste Vorkommen der größten Zahl im Eingabearray zurück.
*/
uint16_t *find_maximal_number(uint16_t numbers[], size_t numbers_len) {
   if (numbers_len == 0) {
        return NULL; // Considering an empty array
    }

    // Initialize max_index to the first position
    size_t max_index = 0;

    for (size_t i = 1; i < numbers_len; i++) {
        if (numbers[i] > numbers[max_index]) {
            max_index = i; // Index with new maximum number
        }
    }

    return &numbers[max_index];
}

/*
Aufgabe 2b:
Geben Sie (einen Pointer auf) das Teilarray zurück, welches ab dem ersten Vorkommen der größten Zahl im Eingabearray beginnt.
*/
uint16_t *find_subarray_starting_at_maximal_number(uint16_t numbers[], size_t numbers_len) {
    // Reusing find_maximal_number 
    uint16_t *pMax = find_maximal_number(numbers, numbers_len);

    return pMax;
}

/*
Aufgabe 2c:
Geben Sie die größtmögliche Distanz zwischen zwei Zahlenwerten aus dem Array `numbers` zurück.
Beispiel: Im Array {1, 3, 7, 4} ist die größte Distanz die zwischen 1 und 7, und beträgt damit `6`.
*/

void insertionSort(uint16_t arr[], size_t len) {
    for (size_t i = 1; i < len; i++) {
        uint16_t key = arr[i];
        int j = i - 1;

        // Move elements of arr[0..i-1] that are greater than key to one position ahead
        // of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

uint16_t find_maximum_distance(uint16_t numbers[], size_t numbers_len) {
    if (numbers_len < 2) {
        return 0;
    }

    // Create and copy to temporary array
    uint16_t *temp = (uint16_t *)malloc(numbers_len * sizeof(uint16_t));
    if (temp == NULL) {
        return 0; // Handle memory allocation failure
    }
    for (size_t i = 0; i < numbers_len; i++) {
        temp[i] = numbers[i];
    }

    // Sort temporary array
    insertionSort(temp, numbers_len);

    // Calculate maximum distance
    uint16_t max_distance = temp[numbers_len - 1] - temp[0];
    free(temp); // Free allocated memory
    return max_distance;
}
/*
Aufgabe 2d:
Geben Sie die kleinstmögliche Distanz zwischen zwei Zahlenwerten aus dem Array `numbers` zurück.
Beispiel: Im Array {1, 3, 7, 4} ist die kleinste Distanz die zwischen 3 und 4, und beträgt damit `1`.
*/
/*
Aufgabe 2d:
Find the minimum distance between any two consecutive numbers in the array.
*/
uint16_t find_minimum_distance(uint16_t numbers[], size_t numbers_len) {
    if (numbers_len < 2) {
        return 0; // No meaningful distance if there are fewer than 2 elements
    }

    // Create and copy to temporary array
    uint16_t *temp = (uint16_t *)malloc(numbers_len * sizeof(uint16_t));
    if (temp == NULL) {
        return 0; // Handle memory allocation failure
    }
    for (size_t i = 0; i < numbers_len; i++) {
        temp[i] = numbers[i];
    }
    // Sort the array using Insertion Sort
    insertionSort(numbers, numbers_len);

    // Initialize min_distance with the largest possible difference
    uint16_t min_distance = UINT16_MAX;

    // Iterate over the sorted array to find the minimum distance between consecutive elements
    for (size_t i = 1; i < numbers_len; i++) {
        uint16_t distance = numbers[i] - numbers[i - 1];
        if (distance < min_distance) {
            min_distance = distance;
        }
    }

    return min_distance;
}
/*
Aufgabe 2e:
Schreiben Sie die ersten `numbers_len` Quadratzahlen aufsteigend in das gegebene Array `numbers`.
Hinweis: Wir starten bei `1`. Sollte numbers_len also `5` sein, sind die ersten 5 Quadratzahlen bis
einschließlich die von 5 gemeint: 1, 4, 9, 16, 25.
*/
void square_ascending(uint16_t numbers[], size_t numbers_len) {
    for (size_t i = 0; i < numbers_len; i++) {
        numbers[i] = (i + 1) * (i + 1);
    }
}

/*
Aufgabe 2f:
Füllen Sie das Array `out` mit den aufsteigend sortierten Zahlen aus dem `in` Array. Beide Arrays haben die Länge `len`.
Beispiel: Ist `in` {1, 4, 3, 7, 4}, so soll `out` am Ende {1, 3, 4, 4, 7} sein.
*/
void sort_ascending(uint16_t in[], uint16_t out[], size_t len) {
    // Handle empty array
    if (len == 0) {
        return;
    }

    // Copy input array to output array
    for (size_t i = 0; i < len; i++) {
        out[i] = in[i];
    }

    // Sort output array using existing insertionSort
    insertionSort(out, len);
}