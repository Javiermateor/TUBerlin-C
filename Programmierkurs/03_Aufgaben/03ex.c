/*
Willkommen zum dritten Aufgabenblatt vom Programmierkurs. Auf diesem Aufgabenblatt geht es um folgende neue Konzepte:

- Aufrufen von Funktionen
- Definieren von Funktionen

Um die Tests für dieses Blatt zu kompilieren und zu starten, führen Sie den folgenden Befehl aus:
clang -std=c11 -g -Wall 03ex_test.c -o 03ex_test.o -lm && ./03ex_test.o
clang -std=c11 -g -Wall 03ex_test.c -o 03ex_test.o  && ./03ex_test.o

WINDOWS: clang -std=c11 -g -Wall 03ex_test.c -o 03ex_test.o && 03ex_test.o
*/

/* Die folgenden Zeilen enthalten einige C-Notwendigkeiten die Sie momentan ignorieren können. */
#include "03_canvas.h"
#include <stdio.h> 
/* Hier enden die Dinge, die Sie ignorieren können */

/*
Der folgende Code ist ein Beispiel für eine Funktionsdefinition. Die Funktion gibt `1` zurück falls `n` ein
ganzzahliges Vielfaches von `k` ist, und `0` falls nicht.
Innerhalb dieses Aufgabenblattes können Sie diese Funktion frei verwenden. Ein Funktionsaufruf könnte zum Beispiel
`is_multiple_of(n, 2)` sein. Dieser gäbe `1` zurück wenn `n` gerade ist, und `0` wenn `n` ungerade ist.

Für dieses und alle weiteren Aufgabenblätter animieren wir Sie, selbstständig Funktionen zu schreiben um Teilprobleme zu lösen.
Sie können zum Beispiel `is_multiple_of` in mehreren Aufgaben auf diesem Blatt verwenden. Wenn wir die nicht vordefiniert hätten, 
hätte es sich für Sie gelohnt, sie selbst zu definieren.
Teilprobleme zu identifizieren und losgelöst vom ursprünglichen Kontext als Hilfsfunktion zu implementierem ist
ein großer Teil von kompetentem Programmieren.
*/
int is_multiple_of(int n, int k) {
    int rest = n % k;
    return rest == 0;
}

/*
Aufgabe 1a:

Geben Sie in dieser Funktion die Summe der ersten `n` natürlichen Zahlen (exklusive der Null) zurück, die durch `m` teilbar sind.
*/
int sum_of_divisibles(int n, int m) {
    int summe = 0;
    for (int i = n; i >= 1; i--) {
        summe += i * m;
    }
    return summe;
}
    

/*
Aufgabe 1b:


Geben Sie in dieser Funktion die Summe der ersten `n` natürlichen Zahlen (exklusive der Null) zurück, die durch `l` und durch `m` teilbar sind.
*/

// Rekursive GCD Fuktion anhand des Euklidischen Algorithmus |  Quelle: S. 935, Introduction to Algorithms

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int sum_of_doubly_divisibles(int n, int l, int m) {
    int summe = 0;
    int lcm = l * m / gcd(l, m);
    for (int i = 1; i <= n; i++) {
        summe += i * lcm;
    }
    return summe;
}

/*
Aufgabe 2a:
Die folgenden Aufgaben (und auch weitere Aufgaben auf den kommenden Aufgabenblättern) erlauben es Ihnen,
einfache Grafiken zu erstellen.
In dieser Funktion starten wir mit einer komplett weißen "Canvas" (deutsch: "Leinwand") `c` und färben bestimmte Pixel schwarz.
Die Canvas ist ein zweidimensionales Raster aus Pixeln, ein einfaches, mit Code bearbeitbares Bild.
Dank der bereitgestellten Funktionen brauchen Sie nicht verstehen, wie der Computer Bilder repräsentiert. Sie müssen nur wissen,
wie Sie die Funktion `canvas_set_black` aufrufen, um die Canvas zu manipulieren.
*/
Canvas first_canvas_exercise(Canvas c) {
    /*
    Die `canvas_set_black` Funktion bekommt drei Parameter. Eine Canvas, sowie eine
    x-Koordinate und eine y-Koordinate innerhalb dieser Canvas.
    Die linke untere Ecke der Canvas ist der Koordinatenursprung, dort sind die x- und die y-Koordinate jeweils `0`.
    Nach rechts steigen die x-Koordinaten, nach oben die y-Koordinaten.
    */
    c = canvas_set_black(c, 1, 5);
    canvas_save_debug(c);

    c = canvas_set_black(c, 2, 1);
    canvas_save_debug(c);

    c = canvas_set_black(c, 13, 4);
    canvas_save_debug(c);

    /*
    Diese drei Funktionsaufrufe hier drüber färben drei unterschiedliche Pixel der Canvas schwarz.
    Versuchen Sie sich vorzustellen, wo diese drei Pixel gemäß unseres Koordinatensystems sein sollten.

    Führen Sie jetzt den Test für diese Aufgabe aus, indem Sie diesen Befehl nutzen:
    clang -std=c11 -g -Wall 03ex_test.c -o 03ex_test.o -lm && ./03ex_test.o first_canvas_exercise

    Der Test wird fehlschlagen, da wir drei leicht andere Pixel-Positionen schwarz gefärbt haben wollen. Schauen Sie sich
    die Test-Ausgabe an. Diese sollte Sie darüber informieren, dass ein Bild in einem "Feedback" Verzeichnis (im aktuellen Verzeichnis)
    gespeichert wurde, welches Ihnen die Abweichung darstellt.
    Öffnen Sie das Bild (eventuell müssen Sie etwas hineinzoomen, es ist recht klein).
    Das Bild ist in drei Segmente unterteilt. Zuerst das Bild welches Sie erstellt haben,
    dann das erwartete Bild, und als drittes eine Visualisierung
    welche Pixel in ihrer Farbe vom erwarteten Bild abweichen.

    Nutzen Sie diese Visualisierung, um die drei Funktionsaufrufe oben so zu verändern, dass Ihr Bild und das erwartete
    Bild übereinstimmen. Sie können den Test beliebig oft ausführen, um neue Feedback-Bilder zu erzeugen.

    Desweiteren existiert die `canvas_save_debug(Canvas c)` Funktion. Dieser können Sie jederzeit eine Canvas übergeben,
    um sie als Bild abzuspeichern. Die Bilder erscheinen im "Debug" Ordner und sind
    aufsteigend nummeriert, falls Sie für eine Canvas die Funktion mehrfach aufrufen. Probieren Sie die Funktion doch
    ein paar mal mit dem Canvas in dieser Aufgabe aus, zum Beispiel jedes mal nachdem ein Pixel gesetzt wurde!

    Sobald der Test erfolgreich ist, verschwindet das Feedback. Anstelle dessen können sie Ihre erfolgreiche Lösung
    im "Success" Ordner bestaunen :). Dies gilt genauso für alle weiteren Canvas-Aufgaben!
    */

    return c;
}

/*
Aufgabe 2b:
In dieser Aufgabe sollen Sie die vier Ecken der Canvas schwarz färben.
Dafür benötigen sie die Höhe und Breite einer gegebenen Canvas.
Um die Höhe und Breite herauszufinden können (und müssen) sie die `canvas_width` und `canvas_height` Funktionen nutzen. Diesen
Funktionen übergeben Sie eine Canvas (so: `canvas_width(c)` und `canvas_height(c)`) und bekommen dann jeweils
die Breite und Höhe zurückgegeben.
Hinweis: Koordinaten beginnen bei `0`, nicht bei `1`.
*/


Canvas color_corners(Canvas c) {
    int width = canvas_width(c);
    int height = canvas_height(c);
    c = canvas_set_black(c, 0, 0);
    c = canvas_set_black(c, 0, height - 1);
    c = canvas_set_black(c, width - 1, 0);
    c = canvas_set_black(c, width - 1, height - 1);
    return c;
}

/*
Aufgabe 2c:
Färben Sie alle Pixel der Canvas schwarz.
*/
Canvas paint_it_black(Canvas c) {

    int width = canvas_width(c);
    int height = canvas_height(c);

    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            c = canvas_set_black(c, x, y);
        }
    }

    return c;
}

/*
Aufgabe 2d:
Färben Sie den ersten Pixel der ersten Reihe von oben schwarz, dann die ersten beiden Pixel der zweiten Reihe, die
ersten drei der dritten Reihe und so weiter (falls das unklar war, führen Sie einfach den Test aus
und schauen sich das erwartete Ergebnis an).
Falls eine Reihe nicht breit genug ist, färben Sie alle Pixel dieser Reihe schwarz.
*/
Canvas descending_diagonal(Canvas c) {
    int width = canvas_width(c);
    int height = canvas_height(c);

    // Iteriere über die Reihen von oben nach unten
    for (int y = height - 1; y >= 0; y--) {
        // Bestimme die Anzahl der zu färbenden Pixel in der aktuellen Reihe
        int num_pixels_to_color = height - y;

        // Falls die Reihe nicht breit genug ist, färbe alle Pixel
        if (num_pixels_to_color > width) {
            num_pixels_to_color = width;
        }

        // Färbe die entsprechenden Pixel schwarz
        for (int x = 0; x < num_pixels_to_color; x++) {
            c = canvas_set_black(c, x, y);
        }
    }

    return c;
}

/*
Aufgabe 3a:
Diese Funktion soll ein gefülltes schwarzes Rechteck auf die Canvas zeichnen. Die obere linke Ecke des Rechtecks hat die
Koordinaten `(x, y)`. Die Breite des Rechtecks ist `width`, und die Höhe ist `height`. Falls das Rechteck nicht
auf die Canvas passt, sollen einfach die Teile ignoriert werden welche außerhalb liegen würden.
*/
Canvas draw_rectangle(Canvas c, int x, int y, int width, int height) {
    int canvas_w = canvas_width(c);
    int canvas_h = canvas_height(c);

    // Start- und Endkoordinaten für x anpassen
    int x_start = x < 0 ? 0 : x;
    int x_end = x + width - 1;
    if (x_end >= canvas_w) {
        x_end = canvas_w - 1;
    }

    // Start- und Endkoordinaten für y anpassen
    int y_start = y;
    if (y_start >= canvas_h) {
        y_start = canvas_h - 1;
    }
    int y_end = y - height + 1;
    if (y_end < 0) {
        y_end = 0;
    }

    // Über die angepassten Koordinaten iterieren und Pixel schwarz färben
    for (int curr_x = x_start; curr_x <= x_end; curr_x++) {
        for (int curr_y = y_start; curr_y >= y_end; curr_y--) {
            c = canvas_set_black(c, curr_x, curr_y);
        }
    }

    return c;
}

/*
Aufgabe 3b:
Diese Funktion soll ein gefülltes schwarzes Rechteck auf die Canvas zeichnen. Die obere linke Koordinate des Rechtecks
ist `(x0, y0)` und die untere rechte Koordinate ist `(x1, y1)`, und es gilt immer `x1 >= x0` und `y1 <= y0`.
Falls das Rechteck nicht auf die Canvas passt, sollen einfach die Teile ignoriert werden welche außerhalb liegen würden.

Tipp: Ob Sie diese Funktion von Grund auf implementieren oder `draw_rectangle` von Aufgabe 3a nutzen ist Ihnen überlassen.
Wir empfehlen beides auszuprobieren und selbst zu entscheiden welche Lösung Sie eleganter finden.
*/
Canvas draw_rectangle_via_corners(Canvas c, int x0, int y0, int x1, int y1) {
    // Berechne die Breite und Höhe des Rechtecks
    int width = x1 - x0 + 1;
    int height = y0 - y1 + 1;

    // Überprüfe, ob die Dimensionen gültig sind
    if (width <= 0 || height <= 0) {
        // Ungültige Dimensionen, nichts zu zeichnen
        return c;
    }

    // Zeichne das Rechteck mithilfe der Funktion aus Aufgabe 3a
    c = draw_rectangle(c, x0, y0, width, height);

    return c;
}
