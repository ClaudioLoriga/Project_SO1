void controllo(int pipein) {

    pos astronave, missile_left, missile_right, valore_letto;
    astronave.x = -1;
    missile_left.x = -1;
    missile_right.x = -1;

    do {
        read(pipein, &valore_letto, sizeof(valore_letto)); /* leggo dalla pipe */

        if (valore_letto.c == NAVICELLA) {
            if (astronave.x >= 0) { /* cancello la 'vecchia' posizione dell'astronave*/
                mvaddch(astronave.y, astronave.x, ' ');
            }
            astronave = valore_letto;
        }
        if (valore_letto.c == MISSILE_SX) {
            if (missile_left.x >= 0) { /* cancello la 'vecchia' posizione della  */
                mvaddch(missile_left.y, missile_left.x, ' ');
            }
            missile_left = valore_letto;
        }
        if (valore_letto.c == MISSILE_DX) {
            if (missile_right.x <= MAXX) {
                mvaddch(missile_right.y, missile_right.x, ' ');
            }
            missile_right = valore_letto;

        }
        mvaddch(valore_letto.y, valore_letto.x, valore_letto.c);

        curs_set(0);
        refresh();
    } while (1);
}

