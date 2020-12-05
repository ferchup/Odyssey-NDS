/*-------------------------------------
defines.h
-------------------------------------*/

#include <nds.h>
#include <stdio.h>

// Aquí se definen los registros del gestor de interrupciones
#define IME		(*(vuint16*)0x04000208) //Interrupt Master Enable - Habilita o deshabilita todas las interrupciones
#define IE		(*(vuint32*)0x04000210) //Interrupt Enable - Activa o desactiva las interrupciones una a una
#define IF		(*(vuint32*)0x04000214) //Interrupt Flag - Guarda las peticiones de interrupción

// Aquí se definen algunas funciones para el tratamiento de las interrupciones
#define EnableInts() 	IME=1 //Habilita todas las interrupciones
#define DisableInts() 	IME=0 //Deshabilita todas las interrupciones

// Aquí se definen los registros del teclado 
#define TECLAS_DAT	(*(vuint16*)0x4000130) //Registro de datos del teclado
#define TECLAS_CNT	(*(vuint16*)0x4000132) //Registro de control del teclado

// Aquí se definen los registros del temporizador
#define TIMER0_CNT   	(*(vuint16*)0x04000102) //Registro de control del temporizador
// El temporizador se activa poniendo un 1 en el 7º bit.
// El temporizador interrumpirá al desbordarse el contador, si hay un 1 en el 6º bit.
// Los dos bits de menos peso indican lo siguiente:
//		00 frecuencia 33554432 hz
//		01 frecuencia 33554432/64 hz
//		10 frecuencia 33554432/256 hz
//		11 frecuencia 33554432/1024 hz

#define TIMER0_DAT    (*(vuint16*)0x04000100) //Registro de datos del temporizador
// Se utiliza para indicar a partir de qué valor tiene que empezar a contar

// Para no liarse con los números a cada teclas se le ha asignado un nombre

#define A		0 
#define B		1
#define SELECT		2 
#define START		3
#define IZDA		4 
#define DCHA		5
#define ARRIBA		6 
#define ABAJO		7
#define R		8 
#define L		9

// Asignar un nombre a cada estado
#define MENU_PRINCIPAL	0
#define PARTIDA		1
#define ATAQUE_ESP	2
#define FIN		3

//...


// Variables globales

extern int estado;	//Variable para controlar el estado
extern int fase;	//Variable que indica la fase en la que estan los asteroides
extern int segsEsp;	//Integer que cuenta hasta 5 segundos, que es la duración del ataque especial
extern int segundos;	//Integer que cuanta los segundos de la partida
extern int segsataque;	//Integer que cuenta hasta 30 segundos para que se desbloquee el ataque especial
extern int ast;		//Integer para controlar cuando salen los asteroides en temporizadores.c 
extern int x;		//Eje x del cohete
extern int y;		//Eje y del cohete
extern int i;		//Indice del cohete
extern int cruz;	//Variable cruz que se utiliza en teclas.c y dunciones.c
extern bool chocan;	//Si los personajes chocan el booleano chocar se pondrá a verdadero

//Registro de cada asteroide

typedef struct{
	int i;
	int x;
	int y;
	bool v;
} tAsteroide;

//Registro con un vector

typedef struct{
	tAsteroide asteroides[10];
} tSprites;

//Todos los asteroides

extern tSprites sprites;
extern tAsteroide asteroide1;
extern tAsteroide asteroide2;
extern tAsteroide asteroide3;
extern tAsteroide asteroide4;
extern tAsteroide asteroide5;
extern tAsteroide asteroide6;
extern tAsteroide asteroide7;
extern tAsteroide asteroide8;
extern tAsteroide asteroide9;
extern tAsteroide asteroide10;


//...
