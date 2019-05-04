#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleado.h"
#include "almuerzo.h"
#include "validaciones.h"



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


//Funciones Empleados

int menu()
{

    int opcion;

    system("cls");
    printf("\n*** Menu de Opciones ***\n\n");
    printf(" 1- Alta de Empleado\n");
    printf(" 2- Modificar Empleado\n");
    printf(" 3- Baja de Empleado\n");
    printf(" 4- Listar Empleados por Sexo y Nombre\n");
    printf(" 5- Alta de Almuerzos\n");
    printf(" 6- Listar Almuerzos\n");
    printf(" 7- \n");
    printf(" 8- Listar menues\n");
    printf(" 9- Mostrar Almuerzos Por Empleado\n");
    printf(" 10- Mostrar el total de todos los importes pagados por el cliente\n");
    printf(" 11- Mostrar Total de Importes de Menu su Promedio y los que superan promedio \n");
    printf(" 12- Mostrar Total de Importes de Menu su Promedio y los que No superan promedio \n");
    printf(" 13- Cantidad de almuerzos consumidos por Empleados\n");
    printf(" 14- \n");
    printf(" 20- Salir\n");
    printf(" Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}
/** \brief modifica el valor del estado
 * \param eEmpleado lista* corresponde al array ingresado por el usuario
 * \param tam int corresponde a la cantidad de elementos del array
 *
 */
void inicializarEmpleados(eEmpleado lista[], int tam)
{

    for(int i=0; i < tam; i++)
    {

        lista[i].isEmpty = 1;
    }
}
/** \brief muestra el cliente ingresado
 * \param  unEmpleado corresponde al array de clientes ingresado por el usuario
 * \param juevos corresponde al array de juegos
 *  \param tam corresponde a la cantidad de elementos del array
 *
 */
void mostrarEmpleado(eEmpleado unEmpleado)
{
    printf("%4d %10s %10s %2c     %2.f %10d %2d/%2d/%d \n", unEmpleado.codigo, unEmpleado.nombre,unEmpleado.apellido, unEmpleado.sexo,unEmpleado.salario, unEmpleado.telefono,unEmpleado.fecha.dia,unEmpleado.fecha.mes,unEmpleado.fecha.anio);
}

/** \brief muestra la lista de clientes ingresados
 * \param  eEmpleado Lista corresponde al array de clientes ingresado por el usuario
 *\param tam corresponde a la cantidad de elementos del array cliente
 * \param juegos corresponde al array de juegos
 *  \param tam corresponde a la cantidad de elementos del array juegos
 *
 */
void mostrarEmpleados(eEmpleado lista[], int tam)
{

    system("cls");
    printf("Codigo   Nombre   Apellido  Sexo  Salario  Telefono  Fecha De Ingreso\n\n");

    for(int i=0; i < tam; i++)
    {

        if( lista[i].isEmpty == 0)
        {
            mostrarEmpleado(lista[i]);
        }
    }
    system("pause");
}
/** \brief busca un lugar de estado que no este ocupado
 *
 * \param eEmpleado lista* corresponde a la lista de clientes
 * \param int tam corresponde a la cantidad de elementos de la lista clientes
 *
 */

int buscarLibreEmpleados(eEmpleado lista[], int tam)
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
/** \brief busca por identificador al cliente
 *
 * \param eEmpleado Lista* corresponde a la lista de clientes
 * \param tam int corresponde a la cantidad de elementos del array
 * \param legajo int corresponde al numero de identificador que ingresa el usuario
 *
 */

int buscarEmpleado(eEmpleado lista[], int tam, int legajo)
{
    int indice = -1;

    for(int i=0; i < tam; i++)
    {

        if( lista[i].codigo == legajo && lista[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;

}
/** \brief se ingresa el alta de un cliente
 * \param eEmpleado lista* corresponde al array ingresado por el usuario
 * \param tam int corresponde a la cantidad de elementos del array
 * \param eJuego juegos* corresponde l array de juegos
 * \param tamjuegos int corresponde a la cantidad de elementos del array juegos
 *
 *
 */
void altaEmpleado(eEmpleado lista[], int tam,eSector sector[],int tamS)
{
    int indice;
    int legajo;
    int existe;
    char auxSex;
    int auxDia;
    int auxMes;
    int auxAnio;
    int idSectorAux;
    eFecha fechaIngreso;
    eEmpleado nuevoEmpleado;

    indice = buscarLibreEmpleados(lista, tam);

    system("cls");
    printf("*** Alta Empleado ***\n\n");

    if( indice == -1)
    {

        printf("No hay lugar en el sistema\n\n");
        system("pause");
    }
    else
    {
        if(!getValidInt("Ingrese Codigo:\n","\nEso no es un codigo\n",&legajo,1, 1000,2))
        {
            existe = buscarEmpleado(lista, tam, legajo);

            if( existe != -1)
            {

                printf("Ya existe un cliente con el codigo %d\n", legajo);
              //  mostrarEmpleado(lista[existe]);
                system("pause");

            }
            else
            {

                nuevoEmpleado.codigo = legajo;
                if(!getValidString("\nIngrese Nombre:\n","\nEso no es un Nombre\n","Exede Caracteres",nuevoEmpleado.nombre,51,2))
                {
                    if(!getValidString("\nIngrese Apellido:\n","\nEso no es un Apellido\n","Exede Caracteres",nuevoEmpleado.apellido,51,2))
                    {
                        if(!getValidInt("Ingrese telefono:\n","\nEso no es un telefono\n",&nuevoEmpleado.telefono,1, 999999999,3))
                        {
                            if(!getValidFloat("Ingrese Salario:\n","/n Eso no es un salario",&nuevoEmpleado.salario,1,99999999,2))
                               {
                                    printf("Ingrese sexo: ");
                                    fflush(stdin);
                                    scanf("%c",&auxSex);
                                    if(auxSex =='m' || auxSex=='f')
                                    {
                                        nuevoEmpleado.sexo=auxSex;

                                        if(!getValidInt("Ingrese Dia:\n","Dia no valido\n",&auxDia,1,31,2))
                                        {
                                            fechaIngreso.dia=auxDia;
                                        }
                                        if (!getValidInt("Ingrese Mes:\n","Mes no valido\n",&auxMes,1,12,2))
                                        {
                                            fechaIngreso.mes=auxMes;
                                        }
                                        if(!getValidInt("Ingrese Año:\n","Año no valido\n",&auxAnio,1,2018,2))
                                        {
                                            fechaIngreso.anio=auxAnio;
                                        }
                                        listarSectores(sector,tamS);
                                        printf("Ingrese Sector");
                                        fflush(stdin);
                                        scanf("%d",&idSectorAux);
                                        nuevoEmpleado.idSector=idSectorAux;
                                        nuevoEmpleado.fecha=fechaIngreso;

                                        nuevoEmpleado.isEmpty = 0;

                                        lista[indice] = nuevoEmpleado;

                                    }else if(nuevoEmpleado.sexo!= 'm' || nuevoEmpleado.sexo != 'f')
                                    {
                                        printf("Sexo No Valido\n");
                                        system("pause");
                                    }
                               }
                        }
                    }
                }
            }
        }
    }

}

void bajaEmpleado(eEmpleado lista[], int tam)
{

    int legajo;
    int indice;
    char seguir;

    system("cls");
    printf("  *** Baja cliente ***\n\n");

    printf("Ingrese codigo: ");
    scanf("%d", &legajo);

    indice = buscarEmpleado(lista, tam, legajo);

    if( indice == -1)
    {
        printf("No hay ningun cliente de codigo %d\n\n", legajo);
        system("pause");
    }
    else
    {
       // mostrarEmpleado(lista[indice]);

        printf("\nConfima borrado s/n: ");
        fflush(stdin);
        scanf("%c", &seguir);

        if(seguir == 'n')
        {
            printf("Baja cancelada\n\n");

        }
        else

        {

            lista[indice].isEmpty = 1;
            printf("Borrado exitoso\n\n");
        }
        system("pause");
    }

}

void ModificarEmpleado(eEmpleado lista[], int tam)
{
    int legajo;
    int indice;
    char seguir;
    int nuevoTel;
    char nuevoNom[51];
    char NuevoSex;
    char nuevoAp[51];
    float nuevoSal;



    system("cls");
    printf("  *** Modificar  Empleado ***\n\n");

    printf("Ingrese Codigo: ");
    scanf("%d", &legajo);

    indice = buscarEmpleado(lista, tam, legajo);

    if( indice == -1)
    {
        printf("No hay ningun cliente de codigo %d\n\n", legajo);
        system("pause");
    }
    else
    {
      //  mostrarEmpleado(lista[indice]);
        printf("\nSeguro desea Modificar? s/n: ");
        fflush(stdin);
        scanf("%c", &seguir);

        if(seguir == 'n')
        {
            printf("Modificacion cancelada\n\n");

        }
        else
        {
            if(!getValidString("\n Ingrese Nombre\n","\n Eso no es un Nombre\n","Exede Caracteres",nuevoNom,51,2))
            {
                if(!getValidString("\nIngrese Apellido:\n","\nEso no es un Apellido\n","Exede Caracteres",nuevoAp,51,2))
                {
                    if(!getValidInt("Ingrese telefono\n","\nEso no es un telefono\n",&nuevoTel,1, 999999999,2))
                    {
                        if(!getValidFloat("Ingrese Salario:\n","/n Eso no es un salario",&nuevoSal,1,99999999,2))
                        {
                            printf("Ingrese sexo: ");
                            fflush(stdin);
                            scanf("%c", &NuevoSex);
                            if(NuevoSex =='m' || NuevoSex=='f')
                            {
                                strcpy(lista[indice].nombre,nuevoNom);
                                lista[indice].sexo = NuevoSex;
                                lista[indice].telefono = nuevoTel;
                                printf("Modificacion exitosa\n\n");

                            }else if(NuevoSex!= 'm' || NuevoSex!= 'f')
                            {
                                printf("Sexo No Valido\n");
                                system("pause");
                            }
                        }
                    }
                }
            }


        }
        system("pause");
    }


}

void ordenarEmpleadosXCodigo(eEmpleado lista[], int tam)
{
    eEmpleado auxEmpleado;
    for(int i=0; i<tam-1; i++)
    {
        for(int j= i+1; j < tam; j++)
        {

            if( lista[i].sexo > lista[j].sexo)
            {
                auxEmpleado = lista[i];
                lista[i] = lista[j];
                lista[j] = auxEmpleado;

            }else if ( lista[i].sexo == lista[j].sexo && strcmp(lista[i].nombre,lista[j].nombre) >0)
            {
                auxEmpleado = lista[i];
                lista[i] = lista[j];
                lista[j] = auxEmpleado;
            }
        }
    }

    printf("Empleados oredenados con exito!!!\n\n");


}

void harcodearEmpleados(eEmpleado clientes[])
{

    eEmpleado x[]=
    {

        {1, "juan","perez", 'm',30000,42066544,12,01,2018,1,0},
        {2, "luis","richard",'m',25000,42276059,28,05,2017, 1,0},
        {3, "ana","perez", 'f',35000,42173212,30,03,2005, 5,0},
        {4, "carmen","alem", 'f',40000,43534063,10,07,2018 , 2, 0},
        {5, "mia","fernandez" ,'f',18000,46565869,19,01,2000, 3, 0},
        {6, "mauro","piccone",'m',23000,42074343,01,11,1995,5, 0},
        {7, "alberto","orman" ,'m',29000,42093219,14,12,2003, 4,0},
        {8, "valentina","manrique",'f',50000,45930227,01,8,2017,5, 0}

    };

    for(int i=0; i < 8; i++)
    {

        clientes[i] = x[i];
    }

}


//Funciones Sectores

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

void mostrarEmpleadoPorSector(eEmpleado unEmpleado, eSector categorias[], int tam)
{
    char desCat[50];

    obtenerDescripcionSectores(categorias,tam,unEmpleado.idSector,desCat);

    printf("%4d %10s %10s %2c     %2.f %10d   %2d/%2d/%2d  %15s\n", unEmpleado.codigo, unEmpleado.nombre,unEmpleado.apellido, unEmpleado.sexo,unEmpleado.salario, unEmpleado.telefono,unEmpleado.fecha.dia,unEmpleado.fecha.mes,unEmpleado.fecha.anio, desCat);

  //  printf("%4d %15s %15s\n", unJuego.idSector, unJuego.nombre,desCat);
}
void mostrarEmpleadosConSectores(eEmpleado lista[], int tam, eSector categorias[], int tamCat)
{

    system("cls");
    printf("Legajo   Nombre   Apellido  Sexo  Salario  Telefono  Fecha De Ingreso  Sector\n\n");

    for(int i=0; i < tam; i++)
    {

        if( lista[i].isEmpty == 0)
        {
            mostrarEmpleadoPorSector(lista[i], categorias, tamCat);
        }
    }
    system("pause");
}



