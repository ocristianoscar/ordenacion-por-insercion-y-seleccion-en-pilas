#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pila.h"


//funciones de utilidad

//carga una pila con elementos random en el rango 0 - rango_mayor
void cargarPilaRandom(Pila *pila, int cant_elementos, int rango_mayor){
    srand(time(NULL));                                          //inicialización de random
    for(int i=0 ; i < cant_elementos ; i++){
        apilar(pila, (rand() % (rango_mayor + 1)));               //crea elementos de valor entre 0 y rango_mayor
        }
}


//ORDENACION POR SELECCION

int buscarMenor(Pila *dada){

    Pila aux, menor;

    inicpila(&aux);
    inicpila(&menor);

    apilar(&menor, desapilar(dada));   //apila el primer elemento de dada en menor

    while(!pilavacia(dada)){

        if(tope(dada) < tope(&menor)){

            apilar(&aux, desapilar(&menor));
            apilar(&menor, desapilar(dada));

        }else{
            apilar(&aux, desapilar(dada));
        }

    }

    while(!pilavacia(&aux)){
        apilar(dada, desapilar(&aux));
    }

    return tope(&menor);        //retorna el menor elemento de la pila

}


void ordenacionSeleccion(Pila *origen, Pila *destino){

    while(!pilavacia(origen)){
        apilar(destino, buscarMenor(origen));
    }

}


//ORDENACION POR INSERCION

void insertarOrdenado(Pila *dada, int nuevo){

    Pila aux;
    inicpila(&aux);

    while(!pilavacia(dada) && tope(dada) < nuevo){
        apilar(&aux, desapilar(dada));
    }

    apilar(dada, nuevo);

    while(!pilavacia(&aux)){
        apilar(dada, desapilar(&aux));
    }

}

void ordenacionInsercion(Pila *origen, Pila *destino){

    while(!pilavacia(origen)){
        insertarOrdenado(destino, desapilar(origen));
    }

}


int main()
{

    Pila PilaAOrdenar, PilaOrdenada;

    inicpila(&PilaAOrdenar);
    inicpila(&PilaOrdenada);

    printf("--- ORDENACION POR SELECCION EN PILAS ---\n");

    cargarPilaRandom(&PilaAOrdenar, 10, 100);

    printf("\nContenido de la pila a ordenar:\n");
    mostrar(&PilaAOrdenar);

    printf("Contenido de la pila luego de ser ordenada:\n");
    ordenacionSeleccion(&PilaAOrdenar, &PilaOrdenada);
    mostrar(&PilaOrdenada);


    printf("--- ORDENACION POR INSERCION EN PILAS ---\n");

    inicpila(&PilaAOrdenar);
    inicpila(&PilaOrdenada);

    cargarPilaRandom(&PilaAOrdenar, 10, 100);

    printf("\nContenido de la pila a ordenar:\n");
    mostrar(&PilaAOrdenar);

    printf("Contenido de la pila luego de ser ordenada:\n");
    ordenacionInsercion(&PilaAOrdenar, &PilaOrdenada);
    mostrar(&PilaOrdenada);


}
