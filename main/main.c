/* ----------------------------------------------------
   PROGETTO SPACE INVADERS.
   ---------------------------------------------------- */
#include "../astronave/astronave.c"
#include "../controllo/controllo.c"
#include "../functions.h"


int main() { // Funzione main

    int pid_astronave; // Inizializzazione del pid del processo figlio "ASTRONAVE"
    int i;

    initscr(); // Inizializzazione dello schermo
    noecho(); //
    curs_set(0); // Rendo invisibile il cursore
    pipe(p); // Inizializzo la pipe

/* Inizializzazione del seed per la generazione casuale */
    srand(time(NULL));

/* Ottengo dimensioni schermo */
    //getmaxyx(stdscr, MAXY, MAXX);

    if (p == -1) { // Se la pipe restituisce -1, la sua creazione non è riuscita
        perror("Errore nella creazione della pipe!");
        _exit(1);
    }

    pid_astronave = fork();

    switch (pid_astronave) {

        case -1:
            printf("Errore nella esecuzione della fork.");
            _exit(1);

        case 0:   // PROCESSO FIGLIO
            close(p[0]); // Chiudiamo la funzione non necessaria, ossia quella di lettura
            astronave(p[1]); // Il primo processo figlio invoca la funzione ladro
            break;

        default:  //PADRE - FUNZIONE CONTROLLO TEMPORANEA
            close(p[1]); // Chiudiamo la funzione di scrittura
            controllo(p[0]); // Il processo padre invoca la funzione di controllo
            break;
//TODO
    }

    refresh();
    endwin();
    return 0;
}
