/* ----------------------------------------------------
   PROGETTO SPACE INVADERS.
   ---------------------------------------------------- */

#include <stdio.h> // Inclusione di libreria
#include <ncurses.h> // Inclusione di libreria
#include <unistd.h> // Inclusione di libreria
#include <stdlib.h> // Inclusione di libreria

#define CORPO 219;
#define CANNONE_L 221
#define CANNONE_R 222
#define SU 65; 
#define GIU 66;
#define DESTRA 67;
#define SINISTRA 68;

int MAXX, MAXY; // Definizione variabili globali per dimensione schermo

//char astronave_stampa [3][6] = {    " ,CANNONE_L, , ,CANNONE_R, ,"
			  //"CORPO,CORPO,CORPO,CORPO,CORPO,CORPO"
			 // "CORPO,CORPO,CORPO,CORPO,CORPO,CORPO"};
			  
/* Struttura che consentirà di riconoscere quale processo comunica col processo padre */
struct pos { 
int x; // Coordinata x dell'oggetto
int y; // Coordinata y dell'oggetto
char c [6][6]; // Carattere identificativo dell'oggetto
};

/* Dichiarazione Funzioni */
void astronave (int pipeout);


int main (){ // Funzione main

int p[2]; // Inizializzazione del file descriptor per la pipe
int pidA; // Inizializzazione del pid del processo figlio "ASTRONAVE"
int i;
int y=22;

initscr(); // Inizializzazione dello schermo 
noecho; // 
curs_set(0); // Rendo invisibile il cursore
pipe(p); // Inizializzo la pipe 

/* Inizializzazione del seed per la generazione casuale */
srand(time(NULL));

/* Ottengo dimensioni schermo */
getmaxyx(stdscr, MAXY, MAXX);

mvprintw(y, MAXX/2, "|||");




//TODO


refresh();
endwin;
return 0;
}

void astronave (int pipeout){

struct pos astronave;

astronave.x = MAXX/2;
astronave.y = 23;
//astronave.c = astronave_stampa;

}
