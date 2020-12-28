#include "../missile/missile.c"
#include "../sprite.h"


void astronave(int pipeout) {
    int pid_missile1, pid_missile2;
    pos astronave, rocket_left, rocket_right;
    char c;
    //pipe(p); // Inizializzo la pipe

/* Inizializzo l'astronave coi valori della sua posizione iniziale */
    astronave.x = MAXX / 2;
    astronave.y = MAXY;
    astronave.c = NAVICELLA; //TODO IMPLEMENTARE SPRITE ASTRONAVE

    write(pipeout, &astronave, sizeof(astronave));

    while (1) {
        c = getch();

        if (c == SINISTRA && astronave.x > 0) {
            astronave.x = astronave.x - 1;
        }
        if (c == DESTRA && astronave.x < MAXX - 1) {
            astronave.x = astronave.x + 1;
        }
        if (c == SPACE) {
            rocket_left.x = astronave.x - 1;
            rocket_left.y = astronave.y - 1;
            rocket_left.c = MISSILE_SX;

            rocket_right.x = astronave.x + 1;
            rocket_right.y = astronave.y - 1;
            rocket_right.c = MISSILE_DX;

            write(pipeout, &rocket_left, sizeof(rocket_left));
            write(pipeout, &rocket_right, sizeof(rocket_right));

            pid_missile1 = fork();
            if (pid_missile1 == 0) {
                close(p[0]);
                missile(rocket_left, p[1]);
            } else {
                pid_missile2 = fork();
                if (pid_missile2 == 0) {
                    close(p[0]);
                    missile(rocket_right, p[1]);
                }
            }
        }

        if ((c == SINISTRA || c == DESTRA || c == SPACE) && (pid_missile1 != 0 && pid_missile2 != 0)) {
            write(pipeout, &astronave, sizeof(astronave));
            usleep(DELAY);
        }
    }
}
