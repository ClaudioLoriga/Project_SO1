#include <signal.h>
#include "../functions.h"
#include "../sprite.h"

void missile(pos missile_pos, int pipeout) {

    do { // Ogni volta che si sposta un razzo, scrivo nella pipe fino ad arrivare a bordo schermo
        if (missile_pos.c == MISSILE_SX) { // RAZZO SINISTRA
            missile_pos.x = missile_pos.x - 1;
            missile_pos.y = missile_pos.y - 1;
            write(pipeout, &missile_pos, sizeof(missile_pos));
        } else if (missile_pos.c == MISSILE_DX) { // RAZZO DESTRA
            missile_pos.x = missile_pos.x + 1;
            missile_pos.y = missile_pos.y - 1;
            write(pipeout, &missile_pos, sizeof(missile_pos));
        }
        usleep(DELAY);
    } while (missile_pos.x >= 0 && missile_pos.x <= MAXX &&
             missile_pos.y >= 0);
    kill(getpid(), SIGHUP);
}
