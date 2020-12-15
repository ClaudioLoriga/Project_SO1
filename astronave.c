int astronave (int pipeout){

struct pos astronave, rocket_left, rocket_right;
char c;

/* Inizializzo l'astronave coi valori della sua posizione iniziale */
astronave.x = MAXX/2;
astronave.y = MAXY;
astronave.c = ''; //TODO IMPLEMENTARE SPRITE ASTRONAVE

write(pipeout, &astronave, sizeof(astronave));

while(1){

c = getch();

/* Movimento dell'astronave */
switch(c){

case KEY_UP:
if (astronave.y > 0)
astronave.y -= 1;
break;

case KEY_DOWN:
if (astronave.y < MAXY - 1)
astronave.y += 1;
break;

case KEY_LEFT:
if (astronave.x > 0)
astronave.x -= 1;
break;

case KEY_RIGHT:
if (astronave.x < MAXX - 1)
astronave.x += 1;
break;

case SPACE: //TODO #define SPACE = 32

rocket_left.x = astronave.x - 1;
rocket_left.y = astronave.y - 1;
rocket_left.c = '' //TODO DECIDERE CARATTERE RAPPR. ROCKET 

rocket_right.x = astronave.x + 1;
rocket_right.y = astronave.y - 1;
rocket_right.c = '' //TODO DECIDERE CARATTERE RAPPR. ROCKET

write (pipeout, &rocket_left, sizeof(rocket_left));
write (pipeout, &rocket_right, sizeof(rocket_right));

do {

if (rocket.x > 




}
}




}






}
