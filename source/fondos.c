/*---------------------------------------------------------------------------------
Este código se ha implementado basándose en el ejemplo "Simple sprite demo" de 
dovoto y otro de Jaeden Amero
---------------------------------------------------------------------------------*/

#include <nds.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "fondos.h"

/* añadir aquí los includes para cada fondo. */

/* includes para los fondos del menu */
#include "Menu0.h"
#include "Menu1.h"
#include "Menu2.h"
#include "Menu3.h"
#include "Menu4.h"
#include "Menu5.h"
#include "Menu6.h"
#include "Menu7.h"
#include "fondo.h"
#include "GameOver.h"

/* Seleccionar un canal DMA para copiar a memoria las imágenes */
static const int DMA_CHANNEL = 3;

/* Procedimiento para configurar el sistema de fondos. */
void initFondos() {
    /*  Establecer la afinidad del fondo 3 de la pantalla principal con color de 16 bits. */
    REG_BG3CNT = BG_BMP16_256x256 |
                 BG_BMP_BASE(0) | // La dirección inicial de memoria
                 BG_PRIORITY(3); // Baja prioridad

    /*  Establecer la matriz de transformación afin del fondo 3 de la pantalla principal
        a la matriz de identidad. */
    REG_BG3PA = 1 << 8;
    REG_BG3PB = 0;
    REG_BG3PC = 0;
    REG_BG3PD = 1 << 8;

/*******************************************************************************************/
    /*  Definir la situación del fondo 3 de la pantalla principal. */
    /*  Esto deberá cambiar según la posición en la que se quiera poner el gráfico */
    REG_BG3X = 0;
    REG_BG3Y = 0;
/*******************************************************************************************/

    /*  Establecer la afinidad del fondo 2 de la pantalla principal con color de 16 bits. */
    REG_BG2CNT = BG_BMP16_128x128 |
                 BG_BMP_BASE(8) | // La dirección inicial de memoria
                 BG_PRIORITY(2);  // Baja prioridad

    /*  Establecer la matriz de transformación afin del fondo 2 de la pantalla principal 
        a la matriz de identidad. */
    REG_BG2PA = 1 << 8;
    REG_BG2PB = 0;
    REG_BG2PC = 0;
    REG_BG2PD = 1 << 8;

/*******************************************************************************************/
    /*  Definir la situación del fondo 2 de la pantalla principal. */
    /*  Esto deberá cambiar según la posición en la que se quiera poner el gráfico */
    REG_BG2X = -(SCREEN_WIDTH / 2 - 32) << 8;
    REG_BG2Y = -32 << 8;
/*******************************************************************************************/

    /*  Establecer la afinidad del fondo 3 de la pantalla secundaria con color de 16 bits. */
    REG_BG3CNT_SUB = BG_BMP16_256x256 |
                     BG_BMP_BASE(0) | // La dirección inicial de memoria
                     BG_PRIORITY(3); // Baja prioridad

    /*  Establecer la matriz de transformación afin del fondo 3 de la pantalla secundaria
        a la matriz de identidad. */
    REG_BG3PA_SUB = 1 << 8;
    REG_BG3PB_SUB = 0;
    REG_BG3PC_SUB = 0;
    REG_BG3PD_SUB = 1 << 8;

/*******************************************************************************************/
    /*  Definir la situación del fondo 3 de la pantalla secundaria. */
    /*  Esto deberá cambiar según la posición en la que se quiera poner el gráfico */
    REG_BG3X_SUB = 0;
    REG_BG3Y_SUB = 0;
/*******************************************************************************************/
}

/* Para cada imagen que se quiera llevar a pantalla hay que hacer una de estas funciones. */


/* Funciones para las fotos del menu principal */
void Menu0() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     Menu0Bitmap, /* Variable generada automáticamente */
                     (uint16 *)BG_BMP_RAM(0), /* Dirección del fondo 3 principal */
                     Menu0BitmapLen); /* Longitud (en bytes) generada automáticamente */
}
void Menu1() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     Menu1Bitmap, /* Variable generada automáticamente */
                     (uint16 *)BG_BMP_RAM(0), /* Dirección del fondo 3 principal */
                     Menu1BitmapLen); /* Longitud (en bytes) generada automáticamente */
}
void Menu2() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     Menu2Bitmap, /* Variable generada automáticamente */
                     (uint16 *)BG_BMP_RAM(0), /* Dirección del fondo 3 principal */
                     Menu2BitmapLen); /* Longitud (en bytes) generada automáticamente */
}
void Menu3() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     Menu3Bitmap, /* Variable generada automáticamente */
                     (uint16 *)BG_BMP_RAM(0), /* Dirección del fondo 3 principal */
                     Menu3BitmapLen); /* Longitud (en bytes) generada automáticamente */
}
void Menu4() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     Menu4Bitmap, /* Variable generada automáticamente */
                     (uint16 *)BG_BMP_RAM(0), /* Dirección del fondo 3 principal */
                     Menu4BitmapLen); /* Longitud (en bytes) generada automáticamente */
}
void Menu5() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     Menu5Bitmap, /* Variable generada automáticamente */
                     (uint16 *)BG_BMP_RAM(0), /* Dirección del fondo 3 principal */
                     Menu5BitmapLen); /* Longitud (en bytes) generada automáticamente */
}
void Menu6() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     Menu6Bitmap, /* Variable generada automáticamente */
                     (uint16 *)BG_BMP_RAM(0), /* Dirección del fondo 3 principal */
                     Menu6BitmapLen); /* Longitud (en bytes) generada automáticamente */
}
void Menu7() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     Menu7Bitmap, /* Variable generada automáticamente */
                     (uint16 *)BG_BMP_RAM(0), /* Dirección del fondo 3 principal */
                     Menu7BitmapLen); /* Longitud (en bytes) generada automáticamente */
}

/* Funcion para el fondo de la partida */

void fondo() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     fondoBitmap, /* Variable generada automáticamente */
                     (uint16 *)BG_BMP_RAM(0), /* Dirección del fondo 3 principal */
                     fondoBitmapLen); /* Longitud (en bytes) generada automáticamente */
}

/* Funcion para el fondo del fin partida */

void GameOver() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     GameOverBitmap, /* Variable generada automáticamente */
                     (uint16 *)BG_BMP_RAM(0), /* Dirección del fondo 3 principal */
                     GameOverBitmapLen); /* Longitud (en bytes) generada automáticamente */
}



