#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleado.h"
#include "almuerzo.h"
#include "juegos.h"

#define TAM 10



int main()
{
    char seguir = 's';

    eJuego juegos[5];
    eAlmuerzo alquileres[5];
    eSector sectores[5];
    eMenu menues[5];
    int idAlmuerzo=1;

    cargarJuegos(juegos);
    cargarSector(sectores);
    cargarMenu(menues);
    eEmpleado clientes[TAM];
    inicializarEmpleados(clientes,TAM);
    inicializarAlmuerzos(alquileres,5);
    harcodearEmpleados(clientes);


    do
    {
        switch(menu())
        {
        case 1:
            altaEmpleado(clientes, TAM,sectores,5);
            break;
        case 2:
            ModificarEmpleado(clientes, TAM);
            system("pause");
            break;
        case 3:
            bajaEmpleado(clientes,TAM);
            break;
        case 4:
            ordenarEmpleadosXCodigo(clientes, TAM);
            mostrarEmpleadosConSectores(clientes,TAM,sectores,5);
            //mostrarEmpleados(clientes, TAM, juegos, 5,sectores,5);
            system("pause");
            break;
        case 5:
            altaAlmuerzo(alquileres,5,clientes,TAM,menues,5,&idAlmuerzo);
           // printf("%d",&idAlquiler);
            system("pause");
            break;
        case 6:
            mostrarAlmuerzos(alquileres,5,menues,5,clientes,TAM);
            system("pause");
            break;
        case 7:
             mostrarEmpleadosConSectores(clientes,TAM,sectores,5);
             system("pause");

            break;
         case 8:
                listarMenues(menues,5);
               // mostrarJuegosConCatDeMesa(juegos,5,categorias,5);
                system("pause");
            break;
        case 9:
                mostrarAlmuerzosPorEmpleado(alquileres,5,menues,5,clientes,TAM);
            system("pause");
            break;
        case 10:
                //mostrarJuegosSinAlquiler(juegos,5, categorias, 5,alquileres,5);
            break;
        case 11:
                totalImporteMenu(menues,5);
                MenuPromedioImporte(menues,5);
                menuSuperaPromedio(menues,5);
                system("pause");
                break;
        case 12:
                totalImporteMenu(menues,5);
                MenuPromedioImporte(menues,5);
                menuNoSuperaPromedio(menues,5);
                system("pause");
                break;
        case 13:
            InformarAlmuerzosConsumidosPorEmpleados(alquileres,5);
            system("pause");
            break;
        case 14:
            break;
        case 20:
            printf("Salir");
            system("pause");
            seguir = 'n';
            break;
        }
    }
    while(seguir == 's');

    return 0;
}

