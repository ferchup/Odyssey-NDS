/*-------------------------------------
 teclado.c
-------------------------------------*/

// Añadir los includes que sean necesarios
#include <nds.h>
#include <stdio.h>
#include "defines.h"
#include "sprites.h"
#include "temporizadores.h"


// Esta funcion tiene que devolver el valor de la tecla pulsada
int  TeclaPulsada() {

	if((TECLAS_DAT & 0x0001)==0)return A;
	else if((TECLAS_DAT & 0x0002)==0)return B;
	else if((TECLAS_DAT & 0x0004)==0)return SELECT;
	else if((TECLAS_DAT & 0x0008)==0)return START;
	else if((TECLAS_DAT & 0x0010)==0)return IZDA;
	else if((TECLAS_DAT & 0x0020)==0)return DCHA;
	else if((TECLAS_DAT & 0x0040)==0)return ARRIBA;
	else if((TECLAS_DAT & 0x0080)==0)return ABAJO;
	else if((TECLAS_DAT & 0x0100)==0)return R;
	else if((TECLAS_DAT & 0x0200)==0)return L;
	else return -1;
}


// Rutina de atencion a la interrupcion del teclado

//Se utiliza para controlar el cohete. Según la tecla que se pulse cruz tomará un valor y se controlará el movimiento del cohete desde funciones.c

void IntTec() {	
		if(estado==PARTIDA || estado==ATAQUE_ESP){
			if (TeclaPulsada()==DCHA)
			{
				cruz=1; 
			}
			if (TeclaPulsada()==IZDA)
			{
				cruz=2;
			}
			if (TeclaPulsada()==ARRIBA)
			{
				cruz=3;
			}
			if (TeclaPulsada()==ABAJO)
			{
				cruz=4;
			}
		}
}



