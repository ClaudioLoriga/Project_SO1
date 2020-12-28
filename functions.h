#ifndef PROGETTOSPACEINVADERS_FUNCTIONS_H
#define PROGETTOSPACEINVADERS_FUNCTIONS_H

#include <stdio.h> // Inclusione di libreria
#include <unistd.h> // Inclusione di libreria
#include <stdlib.h> // Inclusione di libreria
#include <time.h> // Inclusione di libreria
#include <curses.h> // Inclusione di libreria

#define SU 65
#define GIU 66
#define DESTRA 67
#define SINISTRA 68
#define SPACE 32
#define MAXX 80
#define MAXY 20
#define DELAY 80000

/* Struttura che consentirà di riconoscere quale processo comunica col processo padre */
typedef struct {
    int x; // Coordinata x dell'oggetto
    int y; // Coordinata y dell'oggetto
    char c; // Carattere identificativo dell'oggetto
} pos;

//int MAXX, MAXY; // Definizione variabili globali per dimensione schermo
int p[2]; // Inizializzazione del file descriptor per la pipe

#endif