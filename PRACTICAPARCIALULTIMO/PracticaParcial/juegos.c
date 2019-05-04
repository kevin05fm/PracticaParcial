#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleado.h"
#include "almuerzo.h"
#include "juegos.h"

void inicializarJuegos(eJuego lista[], int tam)
{

    for(int i=0; i < tam; i++)
    {

        lista[i].isEmpty = 1;
    }
}

int buscarLibreJuegos(eJuego lista[], int tam)
{
    int indice = -1;

    for(int i=0; i < tam; i++)
    {

        if( lista[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int buscarJuego(eJuego lista[], int tam, int legajo)
{
    int indice = -1;

    for(int i=0; i < tam; i++)
    {

        if( lista[i].id == legajo && lista[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;

}


/*
void altaJuegos(eJuego lista[], int tam, eJuego juegos[], int tamjuegos)
{
    int indice;
    int legajo;
    int existe;
    int idJuego;
    char auxSex;
    eJuego nuevoJuego;

    indice = buscarLibreClientes(lista, tam);

    system("cls");
    printf("*** Alta Juego ***\n\n");

    if( indice == -1)
    {

        printf("No hay lugar en el sistema\n\n");
        system("pause");
    }
    else
    {
        printf("Ingrese ID: ");
        scanf("%d", &legajo);

        existe = buscarCliente(lista, tam, legajo);

        if( existe != -1)
        {

            printf("Ya existe un juego con el ID %d\n", legajo);
          //  mostrarEmpleado(lista[existe]);
            system("pause");

        }
        else
        {

            nuevoJuego.id = legajo;
            if(!getValidString("\nIngrese Descripcion:\n","\nEso no es una descripcion\n","Exede Caracteres",nuevoJuego.descripcion,51,2))
            {
                    if(!getValidInt("Ingrese Importe:\n","\nEso no es un Importe\n",&nuevoJuego.importe,1, 999999999,2))
                    {


                            listarJuegos(juegos, tamjuegos);
                            printf("\nIngrese Juego: ");
                            scanf("%d", &eJuego.id);

                            nuevoJuego.idJuegos = idJuego;
                            nuevoJuego.isEmpty = 0;

                            lista[indice] = nuevoJuego;



                    }

            }


        }
    }

}
*/

void listarJuegos(eJuego juegos[], int tam){

  printf("Id  Descripcion\n");
    for(int i=0; i< tam; i++){
      printf("%d   %10s\n", juegos[i].id, juegos[i].descripcion);

    }
    printf("\n\n");
}

void obtenerJuegos(eJuego juegos[], int tam, int idJuegos, char cadena[]){

    for(int i=0; i < tam; i++){

        if( juegos[i].id == idJuegos){
            strcpy(cadena, juegos[i].descripcion);
        }
    }

}

void cargarJuegos(eJuego juegos[])
{
       int i;
        eJuego jug[]={
        {1, "Juego de la Oca",234,1,0},
        {2, "Counter Strike",560,3,0},
        {3, "UNO",690,1,0},
        {4, "TEG",1200,4,0},
        {5, "Quien es Quien",350,1,0}

    };

    for(i=0;i<5;i++)
    {
        juegos[i]=jug[i];
    }
}
/*
void cargarCategoria(eCategoria categoria[])
{
       int i;
        eCategoria cat[]={
        {1, "Mesa"},
        {2, "Azar"},
        {3, "Estrategia"},
        {4, "Salon"},
        {5, "Magia"}

    };

    for(i=0;i<5;i++)
    {
        categoria[i]=cat[i];
    }
}

void listarCategorias(eCategoria lista[],int tamano)
{
    int i;
    printf("\n Lista de Categorias \n");
    for(i=0;i<tamano;i++)
    {
        printf("\n%d   %10s\n",lista[i].id,lista[i].descripcion);
    }
}

void obtenerDescCategoria(eCategoria cat[], int tamC, int idCategoria, char* cadena)
{
    for(int i=0; i < tamC; i++)
    {
        if( cat[i].id == idCategoria)
        {
            strcpy(cadena, cat[i].descripcion);
        }
    }
}

void mostrarJuegosPorCat(eJuego unJuego, eCategoria categorias[], int tam)
{
    char desCat[20];

    obtenerDescCategoria(categorias,tam,unJuego.idCategoria,desCat);

    printf("%4d %15s %15s\n", unJuego.id, unJuego.descripcion,desCat);
}
void mostrarJuegosConCat(eJuego lista[], int tam, eCategoria categorias[], int tamCat)
{

    system("cls");
    printf("\nJuegos               categorias\n\n");

    for(int i=0; i < tam; i++)
    {

        if( lista[i].isEmpty == 0)
        {
            mostrarJuegosPorCat(lista[i], categorias, tamCat);
        }
    }
    system("pause");
}

void mostrarJuegosConCatDeMesa(eJuego lista[], int tam, eCategoria categorias[], int tamCat)
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
/*void mostrarJuegosSinAlquiler(eJuego lista[], int tam, eCategoria categorias[], int tamCat,eAlquiler* alq,int tamAlq)
{

    system("cls");
    printf("Juegos               categorias\n\n");

    for(int i=0; i < tam; i++)
    {

        if( lista[i].isEmpty == 0 && alq[i].isEmpty ==1)
        {
            mostrarJuegosPorCat(lista[i], categorias, tamCat);
        }
    }
    system("pause");
}*/
