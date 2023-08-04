#include <iostream>
#include <conio2.h>
#include <ctime>

using namespace std;

const int bordeSup = 1;
const int bordeIzq = 1;
const int bordeDer = 80;
const int bordeInf = 20;

class Pelota{
	
protected:	
	clock_t tempo;
	clock_t paso;
	int direccionX;
	int direccionY;
	int col;
	int x,y;
	void borrar();
	void dibujar();
	void mover();
	
	
public:
	
	Pelota(int velocidad,int color);
	virtual void start();
	void cambiarDireccion(int dx, int dy);
	string figura = "O";
	int getx ();
	int gety();
	void setx(int posx);
	void sety(int posy);
	
};

Pelota::Pelota(int velocidad, int color=WHITE){
	
	paso=CLOCKS_PER_SEC/velocidad;
	tempo=clock();
	col=color;
	direccionX = 1;
	direccionY = 1;
	x=rand()%20+1;
	y=rand()%20+1;
	
}

void Pelota::start(){
	textcolor(col);
	
	
	if(tempo+paso<clock()){
		borrar();
		mover();
		dibujar();
		tempo=clock();
	}
}

void Pelota::borrar(){
	gotoxy(x,y);
	textcolor(7);
	cout<<' ';
	textcolor(col);
}

void Pelota::dibujar(){
	gotoxy(x,y);
	cout<<figura;
}

void Pelota::mover(){
	
	
	if (x >= bordeDer) {
		direccionX = -1;
	}
	if (x <= bordeIzq) {
		direccionX = 1;
	}
	if (y <= bordeSup) {
		direccionY = 1;
	}
	if (y >= bordeInf) {
		direccionY = -1;
	}
	x = x + (1 * direccionX);
	gotoxy(x,y);
	y = y + (1 * direccionY);    

}

int Pelota :: getx()
{
	return x;
}
int Pelota :: gety()
{
	return y;
}
void Pelota :: setx(int posx)
{
	x = posx;
}
void Pelota :: sety(int posy)
{
	y = posy;
}
class Viborita : public Pelota
{
public: 
	Viborita(int vel, int col) : Pelota (vel, col){};
	void cambiarDireccion();
	Viborita();
	void start();
	void alargarviborita();
};

void Viborita :: cambiarDireccion ()
{
		if (_kbhit())
		{
			int tecla = _getch();
			
			switch(tecla)
			{
			case 72: //arriba
				direccionX = 0;
				direccionY = -1;
			    break;	
			case 75: //izquierda
				direccionX = -1;
				direccionY = 0;
			    break;
			case 77: //derecha
				direccionX = 1;
				direccionY = 0;
				break;
			case 80: //abajo
			    direccionX = 0;
				direccionY = 1;
				
				
			}
		}
}
void Viborita :: start()
{
	textcolor(col);
	
	
	if(tempo+paso<clock()){
		borrar();		
		mover();
		cambiarDireccion();
		dibujar();
		tempo=clock();
	}
}

//void Viborita :: alargarviborita()
//{  
//	borrar();
//    mover();
//	cambiarDireccion();
//	gotoxy(x-veces,y-veces);
//	cout<<"O";
//	tempo=clock();
//}

class Pelotita : public Pelota
{
public:
	Pelotita(int vel, int col) : Pelota (vel, col){};
	void setViborita(Viborita* pViborita);
	bool comprobarchoque();
	void cambiarposicion();
	void start();
	int veceschoque = 0;
	void alargarviborita();
	
private:
	Viborita* posicionViborita;
	
};

void Pelotita::setViborita(Viborita* pViborita) 
{
	posicionViborita = pViborita;
}

bool Pelotita::comprobarchoque()
{
	if ((posicionViborita->getx() == getx()) &&(posicionViborita->gety() == gety()) )
	{
		return true;
	}
}
void Pelotita::cambiarposicion()
{
	if (comprobarchoque() == true)
	{setx(rand()%80 + 1);
	sety(rand()%20 + 1);
	veceschoque+1;
	};
}
void Pelotita::alargarviborita()
{
	if (comprobarchoque() == true)
	{    
		borrar();
		mover();
		posicionViborita->cambiarDireccion();
		gotoxy(x-veceschoque,y-veceschoque);
		cout<<"O";
		tempo=clock();
	}
}
void Pelotita::start(){
	textcolor(col);
	
	
	if(tempo+paso<clock()){
		borrar();
	    comprobarchoque();
		cambiarposicion();
		dibujar();
		alargarviborita();
		tempo=clock();
	}
}

int main(int argc, char *argv[]) {
	
	Pelotita pelotita(30,1);
	Viborita viborita(20,14);
	
	pelotita.setViborita(&viborita);
	
	while(true){
		pelotita.start();
		viborita.start();
	}
	
	
	
	return 0;
}
