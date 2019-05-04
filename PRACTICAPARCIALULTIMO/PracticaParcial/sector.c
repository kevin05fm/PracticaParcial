#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
#include "alquileres.h"
#include "juegos.h"
#include "validaciones.h"

/*
void cargarSector(eSector sector[])
{
       int i;
        eSector cat[]={
        {1, "Contabilidad"},
        {2, "Sistemas"},
        {3, "RRHH"},
        {4, "Limpieza"},
        {5, "Finanzas"}

    };

    for(i=0;i<5;i++)
    {
        sector[i]=cat[i];
    }
}

void listarSectores(eSector lista[],int tamano)
{
    int i;
    printf("\n Lista de Sectores \n");
    for(i=0;i<tamano;i++)
    {
        printf("\n%d   %10s\n",lista[i].id,lista[i].descripcion);
    }
}

void obtenerDescripcionSectores(eSector sector[], int tamS, int idSector, char* cadena)
{
    for(int i=0; i < tamS; i++)
    {
        if( sector[i].id == idSector)
        {
            strcpy(cadena, sector[i].descripcion);
        }
    }
}

void mostrarEmpleadoPorSector(eCliente unJuego, eSector categorias[], int tam)
{
    char desCat[20];

    obtenerDescripcionSectores(categorias,tam,unJuego.idSector,desCat);

    printf("%4d %15s %15s\n", unJuego.idSector, unJuego.nombre,desCat);
}
void mostrarEmpleadosPorSectores(eCliente lista[], int tam, eSector categorias[], int tamCat)
{

    system("cls");
    printf("\nJuegos               categorias\n\n");

    for(int i=0; i < tam; i++)
    {

        if( lista[i].isEmpty == 0)
        {
            mostrarEmpleadoPorSector(lista[i], categorias, tamCat);
        }
    }
    system("pause");
}
*/
/*
void mostrarJuegosConCatDeMesa(eJuego lista[], int tam, eSector categorias[], int tamCat)
{

    system("cls");
    printf("Juegos               categorias\n\n");

    for(int i=0; i < tam; i++)
    {

        if( lista[i].isEmpty == 0 && lista[i].idCategoria ==1)
        {
            mostrarJuegosPorCat(lista[i], categorias, tamCat);
        }
    }
    system("pause");
}
*/
