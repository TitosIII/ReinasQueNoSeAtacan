#include <stdio.h>
#include <graphics.h>

void reinas(int [], int [], int [], int[], int, int);
void tablero(int, int[]);

int main() {
    int collibre[8], librearriba[16], libreabajo[15], columna[8], renglon = 0, c, m;
    
    // Modo gráfico
    int gdriver = DETECT, gmode, errorcode;
    initgraph(&gdriver, &gmode, ""); 
    errorcode = graphresult();
    if (errorcode != grOk) {
        printf("Graphics error: %s\n", grapherrormsg(errorcode)); // para errores d graphics
        getch();
        exit(1);
    }
    initwindow(1000, 1000, "LAS REINAS QUE NO SE ATACAN"); 
    tablero(-1, columna); // Dibujar el tablero inicial
    getch();

    // Llenar arreglos de ceros
    for (m = 0; m < 8; m++) {
        collibre[m] = 0;
    }

    for (m = 0; m < 16; m++) {
        librearriba[m] = 0;
    }

    for (m = 0; m < 15; m++) {
        libreabajo[m] = 0;
    }

    //función reinas
    reinas(collibre, librearriba, libreabajo, columna, renglon, c);
    getch();
    closegraph(); 

    return 0;
}

// Algoritmo de las reinas
void reinas(int collibre[], int librearriba[], int libreabajo[], int columna[], int renglon, int c) {
    int aux = 0;
    renglon = renglon + 1;
    for (c = 1; c < 9; c++) {
        // Evaluación para la colocación de reinas
        if (collibre[c - 1] == 0 && librearriba[renglon + c - 2] == 0 && libreabajo[renglon + 7 - c] == 0) {
            // Ocupar lugares para reinas
            columna[renglon - 1] = c;
            collibre[c - 1] = 1;
            librearriba[renglon + c - 2] = 1;
            libreabajo[renglon + 7 - c] = 1;
            // Cuando haya solución, imprimir el tablero
            if (renglon == 8) {
                for (aux = 0; aux < 8; aux++) {
                    printf("renglon: %d columna: %d\n", aux + 1, columna[aux]);
                    tablero(aux, columna); // Dibujar el tablero con las reinas
                }
                getch();
                setbkcolor(0);
                cleardevice();
                tablero(-1, columna); // Dibujar el tablero inicial
                printf("\n");
            } else {
                // Si no hay solución, volver a compilar reinas (recursividad)
                reinas(collibre, librearriba, libreabajo, columna, renglon, c);
            }
            // Aplicación de backtracking porque no se encuentran espacios libres
            collibre[c - 1] = 0;
            librearriba[renglon + c - 2] = 0;
            libreabajo[renglon + 7 - c] = 0;
        }
    }
    renglon = renglon - 1;
}

// Dibuja el tablero y las reinas
void tablero(int i, int columna[8]) {
    int x;
    char s[33];
    setbkcolor(11);
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    settextstyle(3, 0, 3);
    outtextxy(140, 90, "8 REINAS");
    setbkcolor(3);
    
    rectangle(700, 50, 930, 200); 
    //setfillstyle(2,4); 
   
	settextstyle(8, 0, 1);
    outtextxy(710, 75, "Lupe");
    outtextxy(710, 105, "Alda");
    outtextxy(710, 135, "Carlos");
    outtextxy(710, 165, "Renata");
  

    // Construcción del tablero
    if (i < 0) {
        for (x = 0; x < 8; x++) {
            itoa(x + 1, s, 10);
            outtextxy(50, 150 + 70 * x, s);
            outtextxy(70 + 70 * x, 120, s);
        }
        for (x = 0; x < 8; x++) {
            rectangle(70 + 70 * x, 150 + 70 * x, 140 + 70 * x, 220 + 70 * x);
            floodfill(80 + 70 * x, 160 + 70 * x, WHITE);
        }
        for (x = 0; x < 7; x++) {
            rectangle(70 + 70 * x, 220 + 70 * x, 140 + 70 * x, 290 + 70 * x);
            rectangle(140 + 70 * x, 150 + 70 * x, 210 + 70 * x, 220 + 70 * x);
        }
        for (x = 0; x < 6; x++) {
            rectangle(70 + 70 * x, 290 + 70 * x, 140 + 70 * x, 360 + 70 * x);
            floodfill(80 + 70 * x, 300 + 70 * x, WHITE);
            rectangle(210 + 70 * x, 150 + 70 * x, 280 + 70 * x, 220 + 70 * x);
            floodfill(220 + 70 * x, 160 + 70 * x, WHITE);
        }
        for (x = 0; x < 5; x++) {
            rectangle(70 + 70 * x, 360 + 70 * x, 140 + 70 * x, 430 + 70 * x);
            rectangle(280 + 70 * x, 150 + 70 * x, 350 + 70 * x, 220 + 70 * x);
        }
        for (x = 0; x < 4; x++) {
            rectangle(70 + 70 * x, 430 + 70 * x, 140 + 70 * x, 500 + 70 * x);
            floodfill(80 + 70 * x, 440 + 70 * x, WHITE);
            rectangle(350 + 70 * x, 150 + 70 * x, 420 + 70 * x, 220 + 70 * x);
            floodfill(360 + 70 * x, 160 + 70 * x, WHITE);
        }
        for (x = 0; x < 3; x++) {
            rectangle(70 + 70 * x, 500 + 70 * x, 140 + 70 * x, 570 + 70 * x);
            rectangle(420 + 70 * x, 150 + 70 * x, 490 + 70 * x, 220 + 70 * x);
        }
        for (x = 0; x < 2; x++) {
            rectangle(70 + 70 * x, 570 + 70 * x, 140 + 70 * x, 640 + 70 * x);
            floodfill(80 + 70 * x, 580 + 70 * x, WHITE);
            rectangle(490 + 70 * x, 150 + 70 * x, 560 + 70 * x, 220 + 70 * x);
            floodfill(500 + 70 * x, 160 + 70 * x, WHITE);
        }
        for (x = 0; x < 1; x++) {
            rectangle(70 + 70 * x, 640 + 70 * x, 140 + 70 * x, 710 + 70 * x);
            rectangle(560 + 70 * x, 150 + 70 * x, 630 + 70 * x, 220 + 70 * x);
        }
    }

    // Construcción de las reinas, dibujándolas en sus posiciones
    if (i >= 0) {
        setcolor(13);
        setbkcolor(11);
        line(80 + i * 70, 95 + 70 * columna[i], 80 + 70 * i, 130 + 70 * columna[i]);
        line(80 + i * 70, 95 + 70 * columna[i], 95 + 70 * i, 120 + 70 * columna[i]);
        line(95 + 70 * i, 120 + 70 * columna[i], 100 + 70 * i, 90 + 70 * columna[i]);
        line(100 + 70 * i, 90 + 70 * columna[i], 105 + 70 * i, 120 + 70 * columna[i]);
        line(105 + 70 * i, 120 + 70 * columna[i], 120 + 70 * i, 95 + 70 * columna[i]);
        line(120 + 70 * i, 130 + 70 * columna[i], 120 + 70 * i, 95 + 70 * columna[i]);
        line(120 + 70 * i, 120 + 70 * columna[i], 80 + 70 * i, 120 + 70 * columna[i]);
        line(120 + 70 * i, 130 + 70 * columna[i], 80 + 70 * i, 130 + 70 * columna[i]);
        setcolor(5);
        circle(80 + 70 * i, 90 + 70 * columna[i], 5);
        circle(100 + 70 * i, 85 + 70 * columna[i], 5);
        circle(120 + 70 * i, 90 + 70 * columna[i], 5);
        setcolor(WHITE);
    }
}
/**/
