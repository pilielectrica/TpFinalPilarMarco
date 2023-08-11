#include <iostream>
#include <conio2.h>
#include <ctime>
#include <deque>
#include "Pelotita.h"
#include "Juego.h"

using namespace std;

const int bordeSup = 1;
const int bordeIzq = 1;
const int bordeDer = 80;
const int bordeInf = 20;


int main(int argc, char *argv[]) {
	
//	Pelotita pelotita(30,1);
//	Viborita viborita(20,14);
	
	/*pelotita.setViborita(&viborita);*/
	
//	while(true){
//		pelotita.start();
//		viborita.start();
//	}
//	
	Juego Jugar;
	Jugar.startViboritaYPelotita();
	
	
	return 0;
}
