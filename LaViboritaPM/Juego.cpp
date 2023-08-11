#include "Juego.h"
#include "Pelotita.h"
#include "Viborita.h"


Juego::Juego(){
	viborita = Viborita(20,14);
	pelotita = new Pelotita(30,1);
}

bool Juego::comprobarChoque()
{ 
	if ((viborita.getx() == pelotita->getx()) &&(viborita.gety() == pelotita->gety()) )
	{
		return true;
	}
	return false;
}
//void Juego::cambiarPosicion()
//{
//	if (comprobarChoque() == true)
//	{
//		pelotita.setx(rand()%80 + 1);
//		pelotita.sety(rand()%20 + 1);
//	}	
//}

void Juego::startViboritaYPelotita()
{
	
		viborita.start();
		pelotita->start();
	
}
