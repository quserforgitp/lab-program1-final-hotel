/* 
  REQUERIMENTO:

  nombre del cliente
  Lugar de reservacion
  Dia de llegada(dia/mes/anio)
  Dia de partida(dia/mes/anio)
  Numero de personas que se hospedan
  Tipo de habitacion (master suite, junior suite, economica)
  Costo por dia en dolares(ms=100,js=75.95,e=50.5)
  Costo total de la estancia en dolares

  estructura RESERVACION
  union suites
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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
  float campoCostoEstancia;
  Suite habitacionSelecta;
} Reservacion;

/* FIRMAS DE FUNCIONES */
void mostrarMenu(void); //✅
int pedirOpcion(void); //✅
void altaReservacion(Reservacion* rs); //✅
void reporteReservacion(Reservacion* rs); //✅

//PARA altaReservacion()
void pedirNombre(char campoNombre[]); //✅
void pedirLugarReservacion(char campoLugarReservacion[]); //✅
void pedirDiaLlegada(char campoDiaLlegada[]); //✅
void pedirDiaPartida(char campoDiaPartida[]); //✅
void pedirNumeroAdultos(int *campoNumeroAdultos); //✅
void pedirNumeroNinios(int *campoNumeroNinios); //✅
void pedirTipoHabitacion(char tipoHabitacion[]); //✅
float calcularCostoTotalDolares(unsigned int dias,
                               Suite tipoHabitacion);//✅
unsigned int calcularDias(char fechaLlegada[],char fechaPartida[]);//✅
void Error(void); //✅
void salirPrograma(int codigoSalida); //✅
void eliminarSaltoLinea(char nombreCampo[]); //✅

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
      reporteReservacion(&reservacion);
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
  pedirNumeroNinios(&(rs->campoNumeroNinios));
  pedirNumeroAdultos(&(rs->campoNumeroAdultos));
  pedirTipoHabitacion(rs->habitacionSelecta.tipoHabitacion);
  unsigned int dias = calcularDias(rs->campoDiaLlegada,rs->campoDiaPartida);
  rs->campoCostoEstancia = calcularCostoTotalDolares(dias,rs->habitacionSelecta);
  

  // DEBUG
  /* printf("debug nombre:'%s'\n\
          reservacion:'%s'\n\
          dia llegada:'%s'\n\
          dia partida:'%s'\n\
          numero ninios:%d\n\
          numero de adultos:%d\n\
          tipo de habitacion:%s\n\
          dias: %d\n\
          costo estancia: %.2f\n",
            rs->campoNombreCliente,
            rs->campoLugarReservacion,
            rs->campoDiaLlegada,
            rs->campoDiaPartida,
            rs->campoNumeroNinios,
            rs->campoNumeroAdultos,
            rs->habitacionSelecta.tipoHabitacion,
            dias,
            rs->campoCostoEstancia); */
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

void pedirNumeroNinios(int *campoNumeroNinios)
{
  puts("Dame el numero de ninios que se van a hospedar: ");
  scanf("%d", campoNumeroNinios);
  getchar();//consumir salto de linea
}

void pedirNumeroAdultos(int *campoNumeroAdultos)
{
  puts("Dame el numero de Adultos que se van a hospedar: ");
  scanf("%d", campoNumeroAdultos);
  getchar();//consumir salto de linea
}

void pedirTipoHabitacion(char tipoHabitacion[])
{
  puts("╔═══════════════════════════╗");
  puts("║      TIPOS DE SUITE       ║");
  puts("╠═══════════════════════════╣");
  puts("║    master suite... $100   ║");
  puts("║    Junior suite... $75.95 ║");
  puts("║    economica...... $50.5  ║");
  puts("╚═══════════════════════════╝");
  puts("Dime el tipo de suite que deseas (escribe bien para evitar errores): ");
  fgets(tipoHabitacion,LONGITUD_SUITE,stdin);
  eliminarSaltoLinea(tipoHabitacion);
}

float calcularCostoTotalDolares(unsigned int dias,
                               Suite tipoHabitacion)
{
  /* Precios:
     master suite -> 100
     Junior suite -> 75.95
     economica -> 50.5
   */
  //DETERMINAR PRECIO
  float precio = 0;
  char juniorSuiteString[50] = "Junior suite";
  char masterSuiteString[50] = "master suite";
  char economicaSuiteString[20] = "economica";
  /* IMPORTANTE -> RECUERDA DQUE strcmp() devuelve 0 si las cadenas son iguales ;( */
  if (strcmp(masterSuiteString,tipoHabitacion.tipoHabitacion) == 0){
    precio = 100;
  } else if(strcmp(juniorSuiteString,tipoHabitacion.tipoHabitacion) == 0){
    precio = 75.95;
  } else if(strcmp(economicaSuiteString,tipoHabitacion.tipoHabitacion) == 0){
    precio = 50.5;
  }

    // debug precio
    printf("suite: %s\nprecio:%.2f", tipoHabitacion.tipoHabitacion,precio);
    getchar();

    return precio*dias;
}

unsigned int calcularDias(char fechaLlegada[],char fechaPartida[])
{
  // Convertir las fechas a enteros
  int dia1, mes1, anio1, dia2, mes2, anio2;
  sscanf(fechaLlegada, "%d/%d/%d", &dia1, &mes1, &anio1);
  sscanf(fechaPartida, "%d/%d/%d", &dia2, &mes2, &anio2);

  // Calcular la diferencia en días
  struct tm t1 = {0};
  struct tm t2 = {0};

  t1.tm_year = anio1 - 1900;
  t1.tm_mon = mes1 - 1;
  t1.tm_mday = dia1;

  t2.tm_year = anio2 - 1900;
  t2.tm_mon = mes2 - 1;
  t2.tm_mday = dia2;

  time_t fecha1unix = mktime(&t1);
  time_t fecha2unix = mktime(&t2);

  double diferenciaUnix = difftime(fecha2unix, fecha1unix); // gracias a diosito existe esta funcion :)
  unsigned int diferenciaDias = abs((unsigned int)(diferenciaUnix / (60 * 60 * 24)));

  return diferenciaDias;
}

void reporteReservacion(Reservacion *rs)
{
  puts("───────────────────────────────────────────");
  puts("             Reporte de Reservación        ");
  puts("───────────────────────────────────────────");
  printf("Nombre del cliente: %s\n", rs->campoNombreCliente);
  printf("Lugar de reservación: %s\n", rs->campoLugarReservacion);
  printf("Día de llegada: %s\n", rs->campoDiaLlegada);
  printf("Día de partida: %s\n", rs->campoDiaPartida);
  printf("Número de niños: %d\n", rs->campoNumeroNinios);
  printf("Número de adultos: %d\n", rs->campoNumeroAdultos);
  printf("Tipo de habitación: %s\n", rs->habitacionSelecta.tipoHabitacion);
  printf("Costo total de la estancia: %.2f\n", rs->campoCostoEstancia);
  puts("───────────────────────────────────────────");  
}

void eliminarSaltoLinea(char nombreCampo[])
{
  nombreCampo[strcspn(nombreCampo, "\n")] = '\0';
}


