#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED
#include "sector.h"

typedef struct
{
    int dia;
    int mes;
    int anio;

}eFecha;

typedef struct
{
    int codigo;
    char nombre[51];
    char apellido[51];
    char sexo;
    float salario;
    int telefono;
    eFecha fecha;
    int idSector;

    int isEmpty;
} eEmpleado;


typedef struct
{
    int id;
    char descripcion[30];
}eSector;




int menu();
void inicializarEmpleados(eEmpleado lista[], int tam);
void mostrarEmpleado(eEmpleado unEmpleado);

int buscarLibreEmpleados(eEmpleado lista[], int tam);
int buscarEmpleado(eEmpleado lista[], int tam, int legajo);
void altaEmpleado(eEmpleado lista[], int tam,eSector sector[],int tamS);
//void altaEmpleado(eEmpleado lista[], int tam, eJuego juegos[], int tamJuegos);
void bajaEmpleado(eEmpleado lista[], int tam);
void ModificarEmpleado(eEmpleado lista[], int tam);
void ordenarEmpleadosXCodigo(eEmpleado lista[], int tam);
void harcodearEmpleados(eEmpleado clientes[]);
void mostrarEmpleados(eEmpleado lista[], int tam);
//void mostrarEmpleados(eEmpleado lista[], int tam, eJuego juegos[], int tamJuegos,eSector sectores[],int tamS);




//Sectores
void cargarSector(eSector sector[]);
void listarSectores(eSector lista[],int tamano);
void obtenerDescripcionSector(eSector cat[], int tamC, int idSector, char* cadena);
void mostrarEmpleadoPorSector(eEmpleado unJuego, eSector categorias[], int tam);
void mostrarEmpleadosConSectores(eEmpleado lista[], int tam, eSector categorias[], int tamCat);
//void mostrarJuegosConCatDeMesa(eJuego lista[], int tam, eSector categorias[], int tamCat);





#endif // CLIENTE_H_INCLUDED
