#ifndef ALQUILERES_H_INCLUDED
#define ALQUILERES_H_INCLUDED

typedef struct
{
    int diaAlmuerzo;
    int mesAlmuerzo;
    int anioAlmuerzo;

}eFechaAlmuerzo;

typedef struct
{
    int idAlmuerzo;
    int idSector;
    int idEmpleado;
    int idMenu;
    eFechaAlmuerzo fechaAlmuerzo;

    int isEmpty;

}eAlmuerzo;

typedef struct
{
    int id;
    char descripcion[30];
    float importe;

    int isEmpty;

}eMenu;


int buscarLibreAlmuerzo(eAlmuerzo lista[], int tam);
int buscarAlmuerzo(eAlmuerzo lista[], int tam, int legajo);
void inicializarAlmuerzos(eAlmuerzo lista[], int tam);
void altaAlmuerzo(eAlmuerzo alq[],int tamA,eEmpleado Client[],int tamC,eMenu cat[],int tamCat,int *pId);
void mostrarAlmuerzo(eAlmuerzo unAlmuerzo, eMenu cat[], int tamcat, eEmpleado cli[], int tamC);
void mostrarAlmuerzos(eAlmuerzo alq[], int tamA, eMenu cat[], int tamMenu, eEmpleado clie[], int tamC);
void mostrarAlmuerzosPorEmpleado(eAlmuerzo alq[], int tamA, eMenu cat[], int tamCat, eEmpleado clie[], int tamC);
void harcodearAlmuerzos(eAlmuerzo alquileres[]);


//MENU

void cargarMenu(eMenu sector[]);
void listarMenues(eMenu lista[],int tamano);
void obtenerDescripcionMenu(eMenu cat[], int tamC, int idMenu, char* cadena);
void mostrarEmpleadoPorMenu(eAlmuerzo unJuego, eMenu categorias[], int tam);
void mostrarEmpleadosConMenues(eAlmuerzo lista[], int tam, eMenu categorias[], int tamCat);
float obtenerImporteMenues(eMenu sector[], int tamS, int idMenu);
void totalImporteMenu(eMenu* array,int limite);
void MenuPromedioImporte(eMenu* array,int limite);
int menuSuperaPromedio(eMenu* array,int limite);
int menuNoSuperaPromedio(eMenu* array,int limite);
void InformarAlmuerzosConsumidosPorEmpleados(eAlmuerzo listaA[],int cantidadAlmuerzo);


//void mostrarJuegosConCatDeMesa(eJuego lista[], int tam, eMenu categorias[], int tamCat);

#endif // ALQUILERES_H_INCLUDED
