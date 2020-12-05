extern u16* gfxCohete;
extern u16* gfxCoheteEsp;
extern u16* gfxAsteroide;


/* Inicializar la memoria de Sprites. */
extern void initSpriteMem();

/* Dentro de esta función hay que definir el color con el que se mostrará cada uno de los 256 
 * colores posibles en la pantalla principal. El 0 es transparente y los no definidos son negros.
 */
extern void establecerPaletaPrincipal();

/* Dentro de esta función hay que definir el color con el que se mostrará cada uno de los 256 
 * colores posibles en la pantalla secundaria. El 0 es transparente y los no definidos son negros.
 */
extern void establecerPaletaSecundaria();

/* Para guardar los sprites en memoria y luego poder usarlos. */

extern void guardarSpritesEnMemoria();

/* Funciones específicas para manejar los sprites. */

extern void MostrarCohete(int indice, int x, int y);
extern void BorrarCohete(int indice,int x, int y);

extern void MostrarCoheteEsp(int indice, int x, int y);
extern void BorrarCoheteEsp(int indice,int x, int y);

extern void MostrarAsteroide(int indice, int x, int y);
extern void BorrarAsteroide(int indice,int x, int y);









