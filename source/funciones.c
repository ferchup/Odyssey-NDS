#include <nds.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "defines.h"
#include "funciones.h"
#include "fondos.h"
#include "rutservs.h"
#include "sprites.h"
#include "teclado.h"
#include "temporizadores.h"


/* Procedimiento para controlar el movimiento del cohete. Según el valor se moverá el cohete constantemente en esa dirección */

void movimiento(){
	if(cruz==1 && x!=0){ x=x-1; }
	if(cruz==2 && x!=239){ x=x+1; }
	if(cruz==3 && y!=0){ y=y-1; }
	if(cruz==4 && y!=176){ y=y+1; }
}

/* Procedimiento para controlar las fases. Según el tiempo transcurrido se cambiará de fase */

void fases(){
	if(segundos<=60){fase=0;}
	if(segundos>60 && segundos<=120){fase=1;}
	if(segundos>120 && segundos<=180){fase=2;}
	if(segundos>180){fase=3;}
}

/* Procedimiento para asignar una posición en el vector de cada asteroide. Tambien se asigna a x en el lado derecho de la pantalla y a la y un número random. Para que no aparezcan dos asteroides seguidos los pares apareceran por la mitad contraria de los impares. */

void iniciarEnemigos(){
	static int num=1;
	sprites.asteroides[1]=asteroide1;
	sprites.asteroides[2]=asteroide2;
	sprites.asteroides[3]=asteroide3;
	sprites.asteroides[4]=asteroide4;
	sprites.asteroides[5]=asteroide5;
	sprites.asteroides[6]=asteroide6;
	sprites.asteroides[7]=asteroide7;
	sprites.asteroides[8]=asteroide8;
	sprites.asteroides[9]=asteroide9;
	sprites.asteroides[10]=asteroide10;
	while(num<11)
	{
		sprites.asteroides[num].i=num;
		sprites.asteroides[num].x=256;
		sprites.asteroides[num].y= rand() % 175;
		if(num%2==0){
			if(sprites.asteroides[num-1].y<=87){sprites.asteroides[num].y= (rand() % 71)+104;}
			if(sprites.asteroides[num-1].y>87){sprites.asteroides[num].y= rand() % 71;}
		}
		sprites.asteroides[num].v=false;
		num++;
	}
}

/* Procedimiento para mover los asteroides. Según la fase se moveran a una velocidad diferente. Si la v es true se ira restando la x hasta que llegue a 0*/

void movimientoEnemigo(){
	static int num=1;
	if(fase==0 || fase==1){
		while(num<11)
		{
			if(sprites.asteroides[num].v==true)
			{
				sprites.asteroides[num].x=sprites.asteroides[num].x-2;
				MostrarAsteroide(num,sprites.asteroides[num].x,sprites.asteroides[num].y);
			}
			num++;
		}
		num=1;
	}
	if(fase==2){
		while(num<11)
		{
			if(sprites.asteroides[num].v==true)
			{
				sprites.asteroides[num].x=sprites.asteroides[num].x-3;
				MostrarAsteroide(num,sprites.asteroides[num].x,sprites.asteroides[num].y);
			}
			num++;
		}
		num=1;
	}
	if(fase==3){
		while(num<11)
		{
			if(sprites.asteroides[num].v==true)
			{
				sprites.asteroides[num].x=sprites.asteroides[num].x-4;
				MostrarAsteroide(num,sprites.asteroides[num].x,sprites.asteroides[num].y);
			}
			num++;
		}
		num=1;
	}
}

/* Procedimiento para borrar los enemigos. Si el estado es partida o ataque especial los enemigos se borrarán cuando salgan por la parte izquierda de la pantalla. Cuando el estado sea Fin simplemente desaparecerán todos. */

void borrarEnemigo(){
	static int num=1;
	while(num<11)
	{
		if(estado==PARTIDA || estado==ATAQUE_ESP)
		{
			if(sprites.asteroides[num].v==true && sprites.asteroides[num].x<=-16)
			{
				BorrarAsteroide(num,sprites.asteroides[num].x,sprites.asteroides[num].y);
				sprites.asteroides[num].x=256;
				sprites.asteroides[num].y= rand() % 175;
				if(num%2==0){
					if(sprites.asteroides[num-1].y<=87){sprites.asteroides[num].y= (rand() % 71)+104;}
					if(sprites.asteroides[num-1].y>87){sprites.asteroides[num].y= rand() % 71;}
				}
				sprites.asteroides[num].v=false;
			}
		}
		if(estado==FIN)
		{
			if(sprites.asteroides[num].v==true)
			{
				BorrarAsteroide(num,sprites.asteroides[num].x,sprites.asteroides[num].y);
				sprites.asteroides[num].x=256;
				sprites.asteroides[num].y= rand() % 175;
				if(num%2==0){
					if(sprites.asteroides[num-1].y<=87){sprites.asteroides[num].y= (rand() % 71)+104;}
					if(sprites.asteroides[num-1].y>87){sprites.asteroides[num].y= rand() % 71;}
				}
				sprites.asteroides[num].v=false;
			}
		}
		num++;
	}
	num=1;
}

/* Procedimiento para detectar si el cohete y un asteroide chocan. Pueden chocarse en cualquier pixel de los sprites. */

void chocar(){
	static int num=1;
	while(num<11){
		if(sprites.asteroides[num].x<=x+15 && sprites.asteroides[num].x>=x-16)
		{
			if(sprites.asteroides[num].y<=y+15 && sprites.asteroides[num].y>=y-16){chocan=true;}
		}
		num++;
	}
	num=1;
}






