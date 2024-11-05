/*
Willkommen zum fünften Aufgabenblatt vom Programmierkurs. Auf diesem Aufabenblatt geht es um Rekursion.

Um die Tests für dieses Blatt zu kompilieren und zu starten, führen Sie den folgenden Befehl aus:
clang -std=c11 -g -Wall 05ex_test.c -o 05ex_test.o -lm && ./05ex_test.o
clang -std=c11 -g -Wall 05ex_test.c -o 05ex_test.o && 05ex_test.o
*/

#include "05_canvas.h"
#include <stdio.h>
#include <math.h>

/*
Aufgabe 1a:
Zeichnen Sie eine horizontale Linie der Länge `width`, deren am weitesten links liegender Pixel bei `(x, y)` ist.

_Benutzen Sie keine Schleifen - Die Aufgabe soll über Rekursion gelöst werden!_

*/

Canvas recursive_line(Canvas c, int x, int y, int width) {
    // Validierung 
    if (width <= 0) {
        return c;  // Basisfall: Keine weitere Rekursion nötig
    }

    // Canvas-Dimensionen ermitteln
    const int canvas_w = canvas_width(c);
    const int canvas_h = canvas_height(c);

    // Prüfe vertikale Grenzen
    if (y < 0 || y >= canvas_h) {
        return c;  // Y-Koordinate außerhalb der Canvas
    }

    // Horizontale Position anpassen falls nötig
    if (x < 0) {
        width += x;  // Breite entsprechend anpassen
        x = 0;      // X-Koordinate auf Canvasrand setzen
    }

    // Zeichne aktuellen Pixel wenn möglich
    if (x < canvas_w) {
        c = canvas_set_black(c, x, y);
    }

    // Rekursiver Aufruf für nächsten Pixel
    return recursive_line(c, x + 1, y, width - 1);
}
    
/*
Aufgabe 1b:
Zeichnen Sie ein Rechteck mit der Breite `width` und der Höhe `height`. Der Pixel der linken unteren Ecke liegt bei `(x, y)`.

_Benutzen Sie keine Schleifen, die Aufgabe soll über Rekursion gelöst werden!_
*/
Canvas recursive_rectangle(Canvas c, int x, int y, int width, int height) {
    // Abbruchbedingung: Wenn die Höhe null oder negativ ist
    if (height <= 0) {
        return c;
    }

    // Horizontale Linie für die aktuelle Höhe
    c = recursive_line(c, x, y, width);

    // Eine Linie höher zeichnen
    return recursive_rectangle(c, x, y + 1, width, height - 1);
}

/*
Aufgabe 2:
Die Fibonaccizahlen sind wie folgt definiert:

- die nullte Fibonaccizahl ist 1,
- die erste Fibonaccizahl ist ebenfalls 1, und
- jede weitere Fibonaccizahl ist die Summe der zwei vorigen Fibonaccizahlen.

Berechne die `n`-te Fibonaccizahl.
*/
int fibonacci(int n) {
    // Basisfälle: die 0-te und 1-te Fibonacci-Zahl sind jeweils 1
    if (n == 0 || n == 1) {
        return 1;
    }
    
    // Rekursiver Aufruf: F(n) = F(n-1) + F(n-2)
    return fibonacci(n - 1) + fibonacci(n - 2);
}
/*
Aufgabe 3:
Implementieren Sie einen schwarzen Fülleimer. Gegeben eine Koordinate `(x, y)` auf einer (bereits bemalten) Canvas, soll die komplette
zusammenhängende Fläche aller Pixel der selben Farbe (schwarz oder weiß) schwarz gefärbt werden.
Zwei Pixel sind Teil der selben Fläche wenn sie die selbe Farbe haben und direkt benachbart sind. Jeder Pixel hat bis
zu vier direkte Nachbarn - die Diagonalen zählen nicht.

Funktionen, um die Farbe eines Pixels auf der Canvas zu bestimmen, sind im Headerfile der Canvas dokumentiert.
*/

 // Hilfsfunktion zur Überprüfung der Koordinaten

int is_within_canvas(Canvas c, int x, int y) {
    int width = canvas_width(c);
    int height = canvas_height(c);
    return (x >= 0 && x < width && y >= 0 && y < height);
}

Canvas bucket_fill(Canvas c, int x, int y) {

    // Überprüfen, ob die Koordinaten innerhalb der Canvas liegen
    if (!is_within_canvas(c, x, y)) {
        return c;
    }
   
    // Überprüfen, ob das aktuelle Pixel bereits schwarz ist
    if (pixel_is_black(c, x, y)) {
        return c;  // Wenn das Pixel bereits schwarz ist, keine weitere Aktion erforderlich
    }

    // Setze das aktuelle Pixel auf schwarz
    c = canvas_set_black(c, x, y);

    // Rekursiv die benachbarten Pixel überprüfen und füllen
    c = bucket_fill(c, x + 1, y);  // Fülle den rechten Nachbarn
    c = bucket_fill(c, x - 1, y);  // Fülle den linken Nachbarn
    c = bucket_fill(c, x, y + 1);  // Fülle den oberen Nachbarn
    c = bucket_fill(c, x, y - 1);  // Fülle den unteren Nachbarn

    return c;
}
