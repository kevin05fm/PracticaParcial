#ifndef JUEGOS_H_INCLUDED
#define JUEGOS_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[20];
    int importe;
    int idCategoria;
    int isEmpty;
}eJuego;

typedef struct
{
    int id;
    char descripcion[30];
}eCategoria;

void inicializarJuegos(eJuego lista[], int tam);
int buscarLibreJuegos(eJuego lista[], int tam);
int buscarJuego(eJuego lista[], int tam, int legajo);
void listarJuegos(eJuego juegos[], int tam);
void obtenerJuegos(eJuego juegos[], int tam, int idJuegos, char cadena[]);
void cargarJuegos(eJuego juegos[]);

void cargarCategoria(eCategoria categoria[]);
void listarCategorias(eCategoria lista[],int tamano);
void obtenerDescCategoria(eCategoria cat[], int tamC, int idCategoria, char* cadena);
void mostrarJuegosPorCat(eJuego unJuego, eCategoria categorias[], int tam);
void mostrarJuegosConCat(eJuego lista[], int tam, eCategoria categorias[], int tamCat);
void mostrarJuegosConCatDeMesa(eJuego lista[], int tam, eCategoria categorias[], int tamCat);




#endif // JUEGOS_H_INCLUDED
