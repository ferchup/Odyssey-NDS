/*-------------------------------------
 temporizadores.c
-------------------------------------*/
// Añadir los includes que sean necesarios
#include "defines.h"
#include "fondos.h"
#include "sprites.h"
#include "funciones.h"
#include <nds.h>
#include <stdio.h>

// Rutina de atención a la interrupción del temporizador
void IntTemp() {
	
	static int tick = 0;
	static int a=0;

	tick++;
	
	//Cada 6 ticks se cambiará la foto del menú principal haciendo un efecto de gif infinito.		
	
	if(tick%6==0){		
		
		if(estado==MENU_PRINCIPAL){
			if(a==0){ Menu0();	a++;}
			else if(a==1){Menu1();	a++;}
			else if(a==2){Menu2();	a++;}
			else if(a==3){Menu3();	a++;}
			else if(a==4){Menu4();	a++;}
			else if(a==5){Menu5();	a++;}
			else if(a==6){Menu6();	a++;}
			else if(a==7){Menu7();	a=0;}
		}
	}
	
	//Cada tick se llama a la función movimiento, es decir, el cohete se mueve a pixel por tick
	
	if(tick%1==0){
		movimiento();
	}

	//Cada 60 ticks es 1 segundo en la vida real, por tanto todos los contadores aumentan en 1.	

	if(tick==60){
		tick=0;
		if(estado==PARTIDA){
			segsataque++;
		}
		if(estado==PARTIDA || estado==ATAQUE_ESP)	//Dependiendo de las fases los enemigos aparecerán con una frecuencia diferente.
		{
			segundos++;
			if(fase==0){
				if(segundos%2==0){sprites.asteroides[ast].v=true; ast++;}
			}
			if(fase==1 || fase==2 || fase==3){
				if(segundos%1==0){sprites.asteroides[ast].v=true; ast++; sprites.asteroides[ast].v=true; ast++;}
			}
			if(ast>10){ast=1;}
		}
		if(estado==ATAQUE_ESP)
		{
			segsEsp++;
		}
	}
		
	//Según la fase el movimiento del enemigo se actualizara de una manera diferente.
	
	if(fase==0){
		if(tick%2==0){movimientoEnemigo();}
	}
	if(fase==1 || fase==2 || fase==3){
		if(tick%1==0){movimientoEnemigo();}	
	}

}





