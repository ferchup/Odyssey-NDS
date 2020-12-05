/*---------------------------------------------------------------------------------
Este código se ha implementado basándose en el ejemplo "Simple sprite demo" de 
dovoto y otro de Jaeden Amero
---------------------------------------------------------------------------------*/

#include <nds.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>       	// time 

#include "fondos.h"
#include "sprites.h"
#include "defines.h"
#include "rutservs.h"
#include "teclado.h"
#include "temporizadores.h"
#include "funciones.h"

//-----------------------------------------------------
// Variables globales
//-----------------------------------------------------

tSprites sprites;

tAsteroide asteroide1;
tAsteroide asteroide2;
tAsteroide asteroide3;
tAsteroide asteroide4;
tAsteroide asteroide5;
tAsteroide asteroide6;
tAsteroide asteroide7;
tAsteroide asteroide8;
tAsteroide asteroide9;
tAsteroide asteroide10;


int fase=0;
int estado;
//Los temporizadores a 0
int segsEsp=0;
int segundos=0;
int segsataque=0;
//Los asteroides tendran del indice 1 al 10
int ast=1;
//El cohete aparecerá en mitad de la pantalla
int x=128;	
int y=95;
//Integer de la cruz
int cruz;
//El cohete tendrá el indice 11
int i=11;
//Booleano para saber si el cohete y los asteroides colisionan
bool chocan=false;

int main() {

	//Se inician los enemigos en funciones.c
	iniciarEnemigos();

	// Variables del main
	touchPosition pos_pantalla;

	//  Poner en marcha el motor gráfico 2D.
    	powerOn(POWER_ALL_2D);

     	// Establecer la pantalla inferior como principal, inicializar el sistema gráfico
     	// y configurar el sistema de fondos.
    	lcdMainOnBottom();
    	initVideo();
    	initFondos();

	// Inicializar memoria de sprites y guardar en ella los sprites 
	initSpriteMem();
	guardarSpritesEnMemoria();

	// Establecer las paletas para los sprites 
	establecerPaletaPrincipal();

	// Para poder imprimir en pantalla (hacer trazas) 
	consoleDemoInit();
	
 	// Para inicializar el generador de números aleatorios en función de una semilla,
	// en este caso time(NULL). 
	// srand() sólo se suele activar una vez por ejecución y no devuelve ningún valor 
	srand (time(NULL));

	//Se inician las interrupciones
	interrupciones();

    
    
// ...
	

	while(1)
	{
		if (estado==MENU_PRINCIPAL)
		{
			//iprintf("\x1b[00;00H.123456789.123456789.123456789.1");
			iprintf("\x1b[02;00H +----------------------------+ ");
 			iprintf("\x1b[03;00H :           ODYSSEY          : ");
 			iprintf("\x1b[04;00H +----------------------------+ ");
			iprintf("\x1b[08;00H     Aqui empieza tu aventura   ");
			iprintf("\x1b[10;00H       a traves del espacio     ");
			iprintf("\x1b[12;00HEvita los asteroides y sobrevive");
			iprintf("\x1b[22;00H Pulsa la pantalla para empezar ");
			//Activamos la pantalla para poder leerla
			touchRead(&pos_pantalla);
			if(pos_pantalla.px!=0 || pos_pantalla.py!=0)	//Si se pulsa la pantalla se pasará al estado PARTIDA
			{
				fondo();
				estado=PARTIDA;
				consoleClear();
			}
		}
		if (estado==PARTIDA)
		{
			MostrarCohete(i,x,y);
			if(segsataque<30){
				//iprintf("\x1b[00;00H.123456789.123456789.123456789.1");
				iprintf("\x1b[02;00H +----------------------------+ ");
				iprintf("\x1b[03;00H :         Tiempo: %d         : ", segundos);
				iprintf("\x1b[04;00H :          Fase: %d           : ", fase);
				iprintf("\x1b[05;00H :  Ataque Especial: Cargando : ");			//Si segsataque es menor que 30 el ataque está cargando
				iprintf("\x1b[06;00H +----------------------------+ ");
				iprintf("\x1b[11;00HEvita los asteroides y sobrevive");
				iprintf("\x1b[13;00H  Usa la cruceta para moverte   ");
				iprintf("\x1b[22;00H       Pulsa B para salir       ");
			}else{
				//iprintf("\x1b[00;00H.123456789.123456789.123456789.1");
				iprintf("\x1b[02;00H +----------------------------+ ");
				iprintf("\x1b[03;00H :         Tiempo: %d         : ", segundos);
				iprintf("\x1b[04;00H :          Fase: %d           : ", fase);
				iprintf("\x1b[05;00H :  Ataque Especial: Listo    : ");			//Si segsataque es mayor que 30 el ataque está cargando
				iprintf("\x1b[06;00H +----------------------------+ ");
				iprintf("\x1b[11;00HEvita los asteroides y sobrevive");
				iprintf("\x1b[13;00H  Usa la cruceta para moverte   ");
				iprintf("\x1b[15;00HPulsa A para el Ataque Especial ");
				iprintf("\x1b[22;00H       Pulsa B para salir       ");
			}
			chocar();
			if(segsataque>=30 && TeclaPulsada()==A)		//Cuando esté cargado el ataque especial y se pulsa A se cambia el estado a ATAQUE ESP
			{
				estado=ATAQUE_ESP;
				consoleClear();
				segsataque=0;
			}
			if(chocan==true || TeclaPulsada()==B){		//Si chocan se pone a verdadero o se pulsa B se acaba el juego y cambia el estado a FIN
				BorrarCohete(i,x,y);
				estado=FIN;
				consoleClear();
				chocan=false;
				borrarEnemigo();
				GameOver();
			}
		}
		if (estado==ATAQUE_ESP)
		{
			//iprintf("\x1b[00;00H.123456789.123456789.123456789.1");
			iprintf("\x1b[02;00H +----------------------------+ ");
			iprintf("\x1b[03;00H :         Tiempo: %d         : ", segundos);
			iprintf("\x1b[04;00H :          Fase: %d           : ", fase);
			iprintf("\x1b[05;00H :  Ataque Especial: %d        : ", segsEsp);
			iprintf("\x1b[06;00H +----------------------------+ ");
			iprintf("\x1b[22;00H       Pulsa B para salir       ");
			MostrarCoheteEsp(i,x,y);
			if(TeclaPulsada()==B){				//Si se pulsa B se acaba el juego y cambia el estado a FIN 
				BorrarCoheteEsp(i,x,y);
				estado=FIN;
				borrarEnemigo();
				consoleClear();
				GameOver();
			}
			if(segsEsp==5)					//Al cabo de 5 segundo se vuelve automaticamente al estado PARTIDA
			{
				estado=PARTIDA;
				segsEsp=0;
				consoleClear();
			}
		}
		if (estado==FIN){
			//iprintf("\x1b[00;00H.123456789.123456789.123456789.1");
			iprintf("\x1b[09;00H         +------------+         ");
			iprintf("\x1b[10;00H         : PUNTUACION :         ");
			iprintf("\x1b[11;00H +-------+------------+-------+ ");
			iprintf("\x1b[12;00H :         Tiempo: %d         : ", segundos);
			iprintf("\x1b[13;00H :          Fase: %d           : ", fase);
			iprintf("\x1b[14;00H +----------------------------+ ");
			iprintf("\x1b[20;00H Pulsa START para volver a jugar");
			iprintf("\x1b[22;00H     Pulsa SELECT para salir    ");
			//Se vuelve a poner las coordenadas del cohete en medio de la pantalla
			x=128;
			y=95;
			cruz=0;
			if(TeclaPulsada()==START){			//Si se pulsa START se vuelve al estado PARTIDA y empieza el juego de nuevo
				segundos=0;
				segsEsp=0;
				segsataque=0;
				fondo();
				consoleClear();
				estado=PARTIDA;
			}
			if(TeclaPulsada()==SELECT){			//Si se pulsa SELECT se va al estado MENU PRINCIPAL
				segundos=0;
				segsEsp=0;
				segsataque=0;
				consoleClear();
				estado=MENU_PRINCIPAL;
			}
		}
		if (estado==PARTIDA || estado==ATAQUE_ESP){		//Se actualizan constantemente los métodos fases() y borrarEnemigo()
				fases();
				borrarEnemigo();
		}
	}
} 


