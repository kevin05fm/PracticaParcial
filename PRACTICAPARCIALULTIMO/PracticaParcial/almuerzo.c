#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleado.h"
#include "almuerzo.h"
#include "validaciones.h"



void inicializarAlmuerzos(eAlmuerzo lista[], int tam)
{

    for(int i=0; i < tam; i++)
    {

        lista[i].isEmpty = 1;
    }
}

int buscarLibreAlmuerzo(eAlmuerzo lista[], int tam)
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
int buscarAlmuerzo(eAlmuerzo lista[], int tam, int legajo)
{
    int indice = -1;

    for(int i=0; i < tam; i++)
    {

        if( lista[i].idAlmuerzo == legajo && lista[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;

}
void altaAlmuerzo(eAlmuerzo alq[],int tamA,eEmpleado cli[],int tamC,eMenu cat[],int tamCat,int* pId)
{
    int idAlmuerzoAux= *pId;
    int indice;
    int legajo;
    int idMenuAux;
    eAlmuerzo nuevoAlmuerzo;
    int existe;
    eFechaAlmuerzo fechaAux;
    int diaAux;
    int mesAux;
    int anioAux;



   /*printf("%d",idAlmuerzo);
        system("pause");*/

    indice = buscarLibreAlmuerzo(alq,tamA);

    system("cls");
    printf("*** Alta Almuerzo ***\n\n");

    if( indice == -1)
    {

        printf("No hay lugar en el sistema\n\n");
        system("pause");
    }
    else
    {


            nuevoAlmuerzo.idAlmuerzo = idAlmuerzoAux;

          /*printf("Ingrese Almuerzo: ");
            fflush(stdin);
            gets(nuevoAlmuerzo.descripcion);*/
            mostrarEmpleados(cli,10);
            printf("Ingrese Legajo de Empleado: ");
            fflush(stdin);
            scanf("%d",&legajo);
            existe=buscarEmpleado(cli,tamC,legajo);
            if(existe == -1){

                printf("No existe un cliente con el codigo %d\n", legajo);
                //  mostrarAlmuerzo(lista[existe]);
                system("pause");
            }else{


                nuevoAlmuerzo.idEmpleado=legajo;
                if(!getValidInt("Ingrese Dia:\n","Dia no valido\n",&diaAux,1,31,2))
                {
                    fechaAux.diaAlmuerzo=diaAux;
                }
                if (!getValidInt("Ingrese Mes:\n","Mes no valido\n",&mesAux,1,12,2))
                {
                    fechaAux.mesAlmuerzo=mesAux;
                }
                if(!getValidInt("Ingrese Año:\n","Año no valido\n",&anioAux,1800,2018,2))
                {
                    fechaAux.anioAlmuerzo=anioAux;
                }
                listarMenues(cat,tamCat);
                printf("Ingrese Menu: ");
                fflush(stdin);
                scanf("%d",&idMenuAux);
                nuevoAlmuerzo.idMenu=idMenuAux;
                nuevoAlmuerzo.fechaAlmuerzo=fechaAux;

                nuevoAlmuerzo.isEmpty = 0;

                alq[indice] = nuevoAlmuerzo;

                *pId = idAlmuerzoAux +1;
            }
    }
}

void mostrarAlmuerzos(eAlmuerzo alq[], int tamA, eMenu cat[], int tamMenu, eEmpleado clie[], int tamC)
{
    int flag = 0;

    system("cls");
    printf("id Almuerzo - Nombre - ID Menu - Menu - Importe  - Fecha de Almuerzo\n\n");

    for(int i=0; i < tamA; i++)
    {
        if( alq[i].isEmpty == 0)
        {
            mostrarAlmuerzo(alq[i], cat, tamMenu, clie, tamC);
            flag = 1;
        }
    }

    if(flag == 0)
    {
        printf("No hay alquileres cargados");
    }
    printf("\n\n");
}

void mostrarAlmuerzo(eAlmuerzo unAlmuerzo, eMenu cat[], int tamMenu, eEmpleado cli[], int tamC)
{
    char descCategoria[20];
    float ImporteMenu;

    int indice;
    eEmpleado cliente;

    obtenerDescripcionMenues(cat,tamMenu,unAlmuerzo.idMenu,descCategoria);
    ImporteMenu=obtenerImporteMenues(cat,tamMenu,unAlmuerzo.idMenu);

    indice = buscarEmpleado(cli, tamC, unAlmuerzo.idEmpleado);

    cliente = cli[indice];

    printf("%4d   %10s %10d  %10s      %.2f   %d/%d/%d \n", unAlmuerzo.idAlmuerzo,cliente.nombre,unAlmuerzo.idMenu,descCategoria,ImporteMenu,unAlmuerzo.fechaAlmuerzo.diaAlmuerzo,unAlmuerzo.fechaAlmuerzo.mesAlmuerzo,unAlmuerzo.fechaAlmuerzo.anioAlmuerzo);
}

void mostrarAlmuerzosPorEmpleado(eAlmuerzo alq[], int tamA, eMenu cat[], int tamCat, eEmpleado clie[],int tamC)
{
    int flag = 0;
    int auxCodigo;

    system("cls");
    mostrarEmpleados(clie,tamC);
    printf("Ingrese codigo del cliente:");
    scanf("%d",&auxCodigo);

    for(int i=0; i < tamA; i++)
    {
        if( alq[i].isEmpty == 0 && alq[i].idEmpleado == auxCodigo)
        {
            mostrarAlmuerzo(alq[i], cat, tamCat, clie, tamC);
            flag = 1;
        }
    }

    if(flag == 0)
    {
        printf("No hay almuerzos cargados");
    }
    printf("\n\n");
}





//Funciones Menues


void cargarMenu(eMenu sector[])
{
       int i;
        eMenu cat[]={
        {1, "Milanesas",110},
        {2, "Fideos",80},
        {3, "Tarta",75},
        {4, "Sandwich",150},
        {5, "Asado",300}

    };

    for(i=0;i<5;i++)
    {
        sector[i]=cat[i];
    }
}
void listarMenues(eMenu lista[],int tamano)
{
    int i;
    printf("\n *****Lista de Menues***** \n");
    printf("ID  -  Menu  -   Precio  \n");
    for(i=0;i<tamano;i++)
    {
        printf("\n%d   %10s  %2.f \n",lista[i].id,lista[i].descripcion,lista[i].importe);
    }
}

void obtenerDescripcionMenues(eMenu sector[], int tamS, int idMenu, char* cadena)
{
    for(int i=0; i < tamS; i++)
    {
        if( sector[i].id == idMenu)
        {
            strcpy(cadena, sector[i].descripcion);
        }
    }
}

float obtenerImporteMenues(eMenu sector[], int tamS, int idMenu)
{
    float importe;
    for(int i=0; i < tamS; i++)
    {
        if( sector[i].id == idMenu)
        {
            importe=sector[i].importe;

        }
    }

    return importe;
}

void mostrarAlmuerzoPorMenu(eAlmuerzo unEmpleado, eMenu categorias[], int tam)
{
    char desCat[50];

    obtenerDescripcionMenues(categorias,tam,unEmpleado.idMenu,desCat);

    printf("%4d %20s\n", unEmpleado.idAlmuerzo, desCat);

  //  printf("%4d %15s %15s\n", unJuego.idMenu, unJuego.nombre,desCat);
}
void mostrarAlmuerzosConMenues(eAlmuerzo lista[], int tam, eMenu categorias[], int tamCat)
{

    system("cls");
    printf("Codigo   Nombre   Apellido  Sexo  Salario  Telefono  Fecha De Ingreso  Menu\n\n");

    for(int i=0; i < tam; i++)
    {

        if( lista[i].isEmpty == 0)
        {
            mostrarAlmuerzoPorMenu(lista[i], categorias, tamCat);
        }
    }
    system("pause");
}


void totalImporteMenu(eMenu* array,int limite)
{

    float auxAcumulador=0;
    int i;

    if(limite > 0 && array != NULL)
    {
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty )
            {
                auxAcumulador+=array[i].importe;
            }
        }
        printf("\nEl total de los importes es:%.2f\n",auxAcumulador);
    }

}

void MenuPromedioImporte(eMenu* array,int limite)
{
    float auxAcumulador=0;
    int contadorEmpleadosActivos=0;
    int i;
    float promedio;


    if(limite > 0 && array != NULL)
    {

        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty )
            {
                auxAcumulador+=array[i].importe;
                contadorEmpleadosActivos++;
            }
        }
        promedio=auxAcumulador/contadorEmpleadosActivos;
        printf("\nEl Promedio de los importes es:%.2f\n",promedio);
    }


}

int menuSuperaPromedio(eMenu* array,int limite)
{

    float auxAcumulador=0;
    int contadorEmpleadosActivos=0;
    int contadorSup=0;
    int i;

    if(limite > 0 && array != NULL)
    {
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty )
            {

                auxAcumulador+=array[i].importe;
                contadorEmpleadosActivos++;
                if(array[i].importe>auxAcumulador/contadorEmpleadosActivos)
                {
                    contadorSup++;
                }


            }

        }
        printf("\nLos importes que superan el promedio son: %d\n",contadorSup);

    }

}

int menuNoSuperaPromedio(eMenu* array,int limite)
{

    float auxAcumulador=0;
    int contadorEmpleadosActivos=0;
    int contadorNoSup=0;
    int i;

    if(limite > 0 && array != NULL)
    {
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty )
            {

                auxAcumulador+=array[i].importe;
                contadorEmpleadosActivos++;
                if(array[i].importe < auxAcumulador/contadorEmpleadosActivos)
                {
                    contadorNoSup++;
                }


            }

        }
        printf("\nLos importes que No superan el promedio son: %d\n",contadorNoSup);

    }

}

void InformarAlmuerzosConsumidosPorEmpleados(eAlmuerzo listaA[],int cantidadAlmuerzo)
{
    int acumuladorAlmuerzos=0;
    int i;

    for(i=0;i<cantidadAlmuerzo;i++ )
    {
        if(!listaA[i].isEmpty)
        {
            acumuladorAlmuerzos++;
        }
    }

    printf("La cantidad de almuerzos consumidos son :%d\n",acumuladorAlmuerzos);


}
void MenuConsumidosPorMasDe5Empleados(eMenu listaM[],int cantidadMenu,eAlmuerzo listaA[],int cantidadAlmuerzo)
{
    int acumuladorMenu=0;
    int mayor=0;
    int i;

    for(i=0;i<cantidadMenu;i++)
    {
        if(!listaM[i].isEmpty && listaM[i].id)
    }

    for(i=0;i<cantidadAlmuerzo;i++ )
    {
        if(!listaA[i].isEmpty  && )
        {
            acumuladorMenu++;
        }
    }


    printf("La cantidad de almuerzos consumidos son :%d\n",acumuladorMenu);


}
