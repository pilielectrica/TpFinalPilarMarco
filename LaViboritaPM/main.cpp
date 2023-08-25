#include <iostream>
#include <conio2.h>
#include <ctime>
#include <deque>
#include "Comida.h"
#include "Juego.h"
#include "Viborita.h"
#include "Pelota.h"
#include "Tablero.h"

using namespace std;

const int bordeSup = 1;
const int bordeIzq = 1;
const int bordeDer = 80;
const int bordeInf = 20;


int main(int argc, char *argv[]) {
	srand(time(NULL));

	
	Juego Jugar;
	Jugar.startViboritaYPelotita();
	
	
	return 0;
}
