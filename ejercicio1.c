/* 
  REQUERIMENTO:

  nombre del cliente
  Lugar de reservacion
  Dia de llegada(dia/mes/anio)
  Dia de partida(dia/mes/anio)
  Numero de personas que se hospedan
  Tipo de habitacion (master suite, junior suite, economica)
  Costo por dia en dolares(ms=100,js=7.95,e=50.5)
  Costo total de la estancia en dolares

  estructura RESERVACION
  union suites
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 80
#define LONGITUD_DIA_LLEGADA 12
#define LONGITUD_DIA_PARTIDA 12
#define LONGITUD_SUITE 15


/* Estructuras */

typedef union {
  char tipoHabitacion[LONGITUD_SUITE];
} Suite;

typedef struct {
  char campoNombreCliente[MAX];
  char campoLugarReservacion[MAX];
  char campoDiaLlegada[LONGITUD_DIA_LLEGADA];
  char campoDiaPartida[LONGITUD_DIA_PARTIDA];
  unsigned int campoNumeroNinios;
  unsigned int campoNumeroAdultos;
  unsigned int campoCostoEstancia;
  Suite habitacionSelecta;
} Reservacion;

/* FIRMAS DE FUNCIONES */
void mostrarMenu(void); //✅
int pedirOpcion(void); //✅
void altaReservacion(Reservacion* rs); //🔨
void reporteReservacion(void);

void pedirNombre(char campoNombre[]); //✅
void pedirLugarReservacion(char campoLugarReservacion[]); //✅
void pedirDiaLlegada(char campoDiaLlegada[]); //✅
void pedirDiaPartida(char campoDiaPartida[]); //✅
void pedirNumeroAdultos(void);
void pedirNumeroNinios(void);
void pedirTipoHabitacion(void);
void calcularCostoTotalDolares(unsigned int noches,
                               Suite tipoHabitacion);
void Error(void); //✅
void salirPrograma(int codigoSalida); //✅
void eliminarSaltoLinea(char nombreCampo[]); //🔨

/* INICIO DEL PROGRAMA */
int main() {

  //DECLARAR ESTRUCTURA
  Reservacion reservacion;
  
  char opcion = 0;
  
  do
  {
    mostrarMenu();
    opcion = pedirOpcion();
    getchar(); // consumir return

    switch (opcion)
    {
    case '1':
      //DEBUG puts("altaReservacion()");
      altaReservacion(&reservacion);
      break;
    case '2':
      puts("reporteReservacion()");
      //reporteReservacion();
      break;
    case '3':
      puts("saliendo del programa...");
      salirPrograma(0);
      break;
    default:
      Error();
    }
    
  } while ( (opcion < 1) || (opcion > 3) );
  
  return EXIT_SUCCESS;
}


/* DEFINICIONES DE FUNCIONES */
void mostrarMenu(void)
{
  puts("╔═══════════════════════════╗");
  puts("║      Hoteles Marriot      ║");
  puts("╠═══════════════════════════╣");
  puts("║ 1. Alta de Reservacion    ║");
  puts("║ 2. Reporte de Reservacion ║");
  puts("║ 3. Salir                  ║");
  puts("╚═══════════════════════════╝");
}

int pedirOpcion(void)
{
  printf("Ingrese una opcion valida -> ");
  return getchar();
}

void Error(void)
{
  puts("");//salto linea
  puts("\t\t¡Error!\n\
Usted introdujo una opcion invalida\n\
O realizo una accion inesperada!!");
  puts("");//salto linea
  salirPrograma(-1);
}

void salirPrograma(int codigoSalida)


{
  exit(codigoSalida);
}

void altaReservacion(Reservacion* rs)
{
  
  pedirNombre(rs->campoNombreCliente);
  pedirLugarReservacion(rs->campoLugarReservacion);
  pedirDiaLlegada(rs->campoDiaLlegada);
  pedirDiaPartida(rs->campoDiaPartida);
  // DEBUG
  printf("debug nombre:'%s'\n\
          reservacion:'%s'\n\
          dia llegada:'%s'\n\
          dia partida:'%s'\n",
            rs->campoNombreCliente,
            rs->campoLugarReservacion,
            rs->campoDiaLlegada,
            rs->campoDiaPartida);
}

void pedirNombre(char campoNombre[])
{
  puts("Dame el nombre y apellidos del cliente:");
  fgets(campoNombre,MAX,stdin);
  eliminarSaltoLinea(campoNombre);
}

void pedirLugarReservacion(char campoLugarReservacion[])
{
  puts("Dame el lugar de la reservacion: ");
  fgets(campoLugarReservacion,MAX,stdin);
  eliminarSaltoLinea(campoLugarReservacion);
}

void pedirDiaLlegada(char campoDiaLlegada[])
{
  puts("Dame el dia de llegada en formato dia/mes/anio: ");
  fgets(campoDiaLlegada,LONGITUD_DIA_LLEGADA,stdin);
  eliminarSaltoLinea(campoDiaLlegada);
}

void pedirDiaPartida(char campoDiaPartida[])
{
  puts("Dame el dia de partida en formato dia/mes/anio: ");
  fgets(campoDiaPartida,LONGITUD_DIA_PARTIDA,stdin);
  eliminarSaltoLinea(campoDiaPartida);
}

void eliminarSaltoLinea(char nombreCampo[])
{
  nombreCampo[strcspn(nombreCampo, "\n")] = '\0';
}