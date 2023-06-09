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
#define LONGITUD_DIA_LLEGADA 11
#define LONGITUD_DIA_PARTIDA 11
#define LONGITUD_SUITE 13


/* Estructuras */

typedef union {
  char tipoHabitacion[LONGITUD_SUITE];
} Suite;

typedef struct {
  char campoNombreCliente[MAX];
  char lugarReservacion[MAX];
  char diaLlegada[LONGITUD_DIA_LLEGADA];
  char diaPartida[LONGITUD_DIA_PARTIDA];
  unsigned int numeroNinios;
  unsigned int numeroAdultos;
  unsigned int costoEstancia;
  Suite habitacionSelecta;
} Reservacion;

/* FIRMAS DE FUNCIONES */
void mostrarMenu(void); //✅
int pedirOpcion(void); //✅
void altaReservacion(Reservacion* rs); //🔨
void reporteReservacion(void);

void pedirNombre(char campoNombre[]); //🔨
void pedirLugarReservacion(void);
void pedirDiaLlegada(void);
void pedirDiaPartida(void);
void pedirNumeroAdultos(void);
void pedirNumeroNinios(void);
void pedirTipoHabitacion(void);
void calcularCostoTotalDolares(unsigned int noches,
                               Suite tipoHabitacion);
void Error(void); //✅
void salirPrograma(int codigoSalida); //✅

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
  puts("mostrando nombre y apellidos: ");
  printf("%s", rs->campoNombreCliente);
}

void pedirNombre(char campoNombre[])
{
  puts("Dame el nombre y apellidos del cliente:");
  fgets(campoNombre,MAX-1,stdin);
}
