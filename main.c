#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int cargarArray(int *, int),
    calcularSumaElementos(int array[], int),
    cargarArrayTipoFloat(float array[],int),
    cargarElementosArrayChar(char *, int),
    encontrarElementoEnArrayChar(char array[], char, int),
    insertarCaracterEnCadenaChar(char [], char, int),
    cargarAbcChar(char *),
    isArrayCapicua(int *, int),
    joinChars(char *, char *, char *, int, int),
    fibonacciParaElProfe(int);

float sumarArrayTipoFloat(float array[], int);

char encontrarMaximoArrayChar(char *, int);

void mostrarArray(int *, int ),
     hacerCopiaDeArrayAPila(int array[], int *, int),
     mostrarArrayFloat(float array[], int),
     mostrarArrayChar(char array[], int),
     invertirArrayInt(int *, int),
     ordenarArrayIntSeleccion(int array[], int),
     ordenarArrayIntInsercion(int array[], int),
     sumatoriaEnOtroArray(int array[], int array2[], int),
     ordenarArrayCharSeleccion(char array[], int);


int main(){

    int array[20],
        arrayResultado[20],
        elementos = 0,
        elementosResultado = 0,
        elementosAbc=25, n,
        elementosArrayCapicua=0,
        arrayCapicua[5],
        elementosArrayChar=0, elementosChar1, elementosChar2;
    Pila pila;
    float arrayFloat[100];
    char arrayChar[30], //{'p','u','b','e','t','a','c','g'},
         charABuscar,
         charInsertar,
         arrayChar2[30], //{'h','i','o','a','c','f','q','e','r'},
         joinChar[60],
         charAbcd[30]={'a','b','c','d','e','f','g','h','i','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'},
         resp;

    srand(time(NULL));

    inicpila(&pila);

    do {
        printf("\nSeleccione una opcion para continuar, presione Escape para salir del programa\n\n");
        printf("\n1 - Cargar un arreglo teniendo como maximo 20 lugares.");
        printf("\n2 - Mostrar arreglo");
        printf("\n3 - Sumatoria del arreglo");
        printf("\n4 - Pasar los elementos a una pila y ver la pila como queda");
        printf("\n5 - Buscar un caracter en un arreglo cargado de caracteres");
        printf("\n6 - Insertar un caracter en el arreglo de caracteres");
        printf("\n7 - Buscar el caracter mas grande en un arreglo de caracteres");
        printf("\n8 - Determinar si un arreglo es capicua");
        printf("\n9 - Invertir un arreglo");
        printf("\n10 - Ordenar un arreglo por seleccion");
        printf("\n11 - Ordenar un arreglo por insercion");
        printf("\n12 - Join de arrays");
        printf("\n13 - Sumatoria de un vector ya cargado en otro");

        resp = getch();

        system("CLS");

        switch (resp){
            case '1':
                //ejercicio1
                elementos = cargarArray(array, 20);
            break;

            case '2':
                //ejercicio2
                mostrarArray(array, elementos);
            break;

            case '3':
                //ejercicio3
                printf("\nLa suma de elementos del arreglo es: %d\n\n\n", calcularSumaElementos(array, elementos));
            break;

            case '4':
                //ejercicio4
                hacerCopiaDeArrayAPila(array, &pila, elementos);
            break;

            case '5':
                //ejercicio6
                elementosArrayChar = cargarElementosArrayChar(arrayChar,20);
                mostrarArrayChar(arrayChar,elementosArrayChar);
                printf("\nIngrese un caracter a buscar en el arreglo de caracteres: ");
                fflush(stdin);
                scanf("%c", &charABuscar);
                if (encontrarElementoEnArrayChar(arrayChar, charABuscar, elementosArrayChar))
                    printf("\nEl elemento se encuentra en el arreglo");
                else
                    printf("\nEl elemento no se encuentra en el arreglo");
            break;

            case '6':
                //ejercicio7
                mostrarArrayChar(charAbcd,elementosAbc);
                printf("\n\n");
                printf("\nIngrese una letra para insertar en el arreglo: ");
                fflush(stdin);
                scanf("%c", &charInsertar);
                elementosAbc = insertarCaracterEnCadenaChar(charAbcd,charInsertar,elementosAbc);
                mostrarArrayChar(charAbcd,elementosAbc);
            break;

            case '7':
                //ejercicio8
                if (elementos !=0){//se maneja que tenga datos el array
                    mostrarArrayChar(arrayChar,elementosArrayChar);
                    printf("\nEl mayor elemento del arreglado de caracteres es: %c", encontrarMaximoArrayChar(arrayChar, elementos));
                } else {
                    elementosArrayChar = cargarElementosArrayChar(arrayChar, 30);
                    mostrarArrayChar(arrayChar,elementosArrayChar);
                    printf("\nEl mayor elemento del arreglado de caracteres es: %c", encontrarMaximoArrayChar(arrayChar, elementos));
                }
            break;

            case '8':
                //ejercicio9
                printf("\nCargar el array con 5 elementos");
                elementosArrayCapicua = cargarArray(arrayCapicua, 5);
                mostrarArray(arrayCapicua, elementosArrayCapicua);
                if (isArrayCapicua(arrayCapicua,elementosArrayCapicua))
                    printf("\nEl arreglo era capicua");
                else
                    printf("\nEl arreglo no era capicua");
            break;

            case '9':
                //ejercicio10
                if (elementos != 0){//se maneja que tenga datos el array
                    invertirArrayInt(array, elementos);
                    mostrarArray(array, elementos);
                } else {
                    printf("\nCargar el array de enteros\n");
                    elementos = cargarArray(array, 20);
                    invertirArrayInt(array, elementos);
                    mostrarArray(array, elementos);
                }

            break;
            case 33:
                //ejercicio11
                if (elementos !=0){//se maneja que tenga datos el array
                    ordenarArrayIntSeleccion(array,elementos);
                    mostrarArray(array,elementos);
                } else {
                    elementos = cargarArray(array,10);
                    ordenarArrayIntSeleccion(array,elementos);
                    mostrarArray(array,elementos);
                }
            break;

            case 64:
                if (elementos !=0){//se maneja que tenga datos el array
                    ordenarArrayIntInsercion(array,elementos);
                    mostrarArray(array,elementos);
                } else {
                    elementos = cargarArray(array, 20);
                    ordenarArrayIntInsercion(array,elementos);
                    mostrarArray(array,elementos);
                }
            break;

            case 35:
                //ejercicio12
                elementosChar1 = cargarElementosArrayChar(arrayChar,30);
                elementosChar2 = cargarElementosArrayChar(arrayChar2,30);

                ordenarArrayCharSeleccion(arrayChar,elementosChar1);
                ordenarArrayCharSeleccion(arrayChar2,elementosChar2);
                printf("\n\n0");
                mostrarArrayChar(arrayChar,elementosChar1);
                printf("\n\n1");
                mostrarArrayChar(arrayChar2,elementosChar2);
                printf("\n\n2");
                elementos = joinChars(arrayChar, arrayChar2, joinChar,elementosChar1,elementosChar2);
                printf("\n\n2");
                mostrarArrayChar(joinChar,elementos);
            break;

            case 36:
                //ejercicio12
                if (elementos != 0){//se maneja que tenga datos el array
                    sumatoriaEnOtroArray(array, arrayResultado, elementos);
                    mostrarArray(arrayResultado, elementos);
                } else {
                    elementos = cargarArray(array, 20);
                    sumatoriaEnOtroArray(array, arrayResultado, elementos);
                    mostrarArray(arrayResultado, elementos);
                }
            break;

        }
        system("PAUSE");
        system("CLS");
    } while (resp != 27);


    printf("%d", fibonacciParaElProfe(7));

    //ejercicio5
//    cargarArrayTipoFloat(arrayFloat,100);
//    mostrarArrayFloat(arrayFloat,100);
//    printf("\nLa suma de todos los elementos del array float: %.2f", sumarArrayTipoFloat(arrayFloat,100));

    return 0;
}

/*1. Hacer una función que reciba como parámetro un arreglo de números enteros y permita que
el usuario ingrese valores al mismo por teclado. La función debe retornar la cantidad de
elementos cargados en el arreglo (o pueden utilizar como puntero válidos).*/

int cargarArray (int array[], int dimension){

    int i, n;

    printf("\nIngrese la cantidad de elementos a cargar(maximo 20)\n");
    scanf("%d",&n);
    for (i=0; i<n; i++){
        printf("\nElemento %d: ", i+1);
        scanf("%d", &array[i]);
    }
    return n;
}

/*2. Hacer una función que reciba como parámetro un arreglo y la cantidad de elementos (válidos)
cargados en él y los muestre por pantalla.*/

void mostrarArray (int array[], int elementosValidos){

    int i;

    printf("\nLa cantidad de elementos que contiene el arreglo: ");
    for (i=0; i < elementosValidos; i++){
        printf(" %d | ", array[i]);
    }
}

/*3. Hacer una función que reciba como parámetro un arreglo y la cantidad de elementos (válidos)
cargados en él y calcule la suma de sus elementos.*/

int calcularSumaElementos(int array[], int elementosValidos){

    int i, suma=0;

    for (i=0; i<elementosValidos; i++){
        suma+= array[i];
    }
    return suma;
}

/*4. Hacer una función que reciba como parámetro un arreglo, la cantidad de elementos (válidos)
cargados en él y una Pila. La función debe copiar los elementos del arreglo en la pila.*/

void hacerCopiaDeArrayAPila(int array[], int * pPila, int elementosValidos){

    int i;

    for (i=0; i<elementosValidos; i++){
        apilar(pPila, array[i]);
    }
    mostrar(pPila);
}

/*5. Realizar una función que sume los elementos de un arreglo de números reales (float) de
dimensión 100. (se recomienda hacer una función para cargar y otra para mostrar para este
tipo de dato asociado al arreglo)*/

int cargarArrayTipoFloat(float array[], int elementos){

    int i;

    for(i=0; i<elementos; i++){
        array[i]=rand()%100*.1;
    }
    return elementos;
}

void mostrarArrayFloat(float array[], int elementosValidos){

    int i;

    printf("\nLos elemntos del array tipo float: ");
    for(i=0; i < elementosValidos; i++){

        printf(" %.2f |", array[i]);
    }

}

float sumarArrayTipoFloat(float array[], int elementos){

    int i;  float suma=0;

    for(i=0; i < elementos; i++){
        suma += array[i];
    }
    return suma;
}

/*6. Realizar una función que indique si un elemento dado se encuentra en un arreglo de
caracteres.*/

int cargarElementosArrayChar (char array[], int dimension){

    int i=0, opcion=0;

    printf("\nIngrese los elementos del arreglo de caracteres, para salir presione '1': ");
    while (i<dimension && opcion!=1){
        fflush(stdin);
        scanf("%c",&array[i]);
        printf("\nDesea continuar? ");
        scanf("%d",&opcion);
        i++;
    }
    return i;
}

void mostrarArrayChar(char array[], int elementos){
    int i;

    printf("\nLos elementos del array de char son: ");
    for (i=0; i < elementos; i++){

        printf("%c | ", array[i]);
    }
}

int encontrarElementoEnArrayChar (char array[], char valorEncontrar, int elementos){

    int i, flagEncontrarElemento=0;

    while(i<elementos && flagEncontrarElemento != 1){
        if (array[i] == valorEncontrar){
            flagEncontrarElemento = 1;
        }

    }
    return flagEncontrarElemento;
}

/*7. Realizar una función que inserte un carácter en un arreglo ordenado alfabéticamente,
conservando el orden.*/

int insertarCaracterEnCadenaChar (char array[], char charInsertar, int elementos){

    int i;

    i=elementos-1;
    //se busca el hueco
    while (i>=0 && array[i] > charInsertar){
        array[i+1] = array[i];
        i--;
    }

    array[i+1] = charInsertar;

    return elementos+1;
}

/*8. Realizar una función que obtenga el máximo carácter de un arreglo dado.*/

char encontrarMaximoArrayChar(char array[], int elementos){

    int i; char mayor=array[0];

    for (i=1; i < elementos; i++){
        if (array[i] > mayor)
            mayor = array[i];
    }

    return mayor;
}

/*9. Realizar una función que determine si un arreglo es capicúa.*/

int isArrayCapicua(int array[], int elementos){

    int i, j=elementos-1, flag=1;

    for (i=0; i<=j; i++){

        if (array[i] != array[j])
            flag=0;
        j--;
    }

    return flag;
}

/*10. Realizar una función que invierta los elementos de un arreglo. (sin utilizar un arreglo auxiliar)*/

void invertirArrayInt (int array[], int elementos){

    int i, j=elementos-1, auxArray;

    for (i=0; i<j; i++){
        auxArray = array[j];
        array[j] = array[i];
        array[i] = auxArray;
        j--;
    }
}

/*11. Ordenar un arreglo según los siguientes métodos:
a. Selección
b. Inserción*/

void ordenarArrayIntSeleccion(int array[], int elementos){

    int i, j, auxArray;

    for (i=0; i < elementos-1; i++){
        for (j=i+1; j< elementos; j++){
            if (array[i] > array[j]){
                auxArray = array[i];
                array[i] = array[j];
                array[j] = auxArray;
            }
        }
    }
}

void ordenarArrayIntInsercion(int array[], int elementos){

    int i,j, auxArray;

    for (i=0; i < elementos; i++){
        j = i-1;
        auxArray = array[i];
        while (j >= 0 && auxArray < array[j]){
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = auxArray;
    }
}

/*12. Dados dos arreglos ordenados alfabéticamente, crear un tercer arreglo con los elementos de
los dos primeros intercalados, de manera que quede un arreglo también ordenado
alfabéticamente.*/

void ordenarArrayCharSeleccion(char array[], int elementos){

    int i, j, auxArray;

    for (i=0; i < elementos-1; i++){
        for (j=i+1; j< elementos; j++){
            if (array[i] > array[j]){
                auxArray = array[i];
                array[i] = array[j];
                array[j] = auxArray;
            }
        }
    }
}

int joinChars(char arrayChar1[], char arrayChar2[], char joinChar[], int elementosArray1, int elementosArray2){

    int i,j, elementosJoin=0;

    for (i=0; i < elementosArray1; i++){
        joinChar[i] = arrayChar1[i];
    }
    elementosJoin = i;
    for (j=0; j < elementosArray2; j++){
        elementosJoin = insertarCaracterEnCadenaChar(joinChar, arrayChar2[j], elementosJoin);
    }
    return elementosJoin;
}

/*13. Dado el vector {1,5,6,7,8} escribir un programa que genere otro vector con la suma del
contenido de todo los elementos anteriores al índice actual: {1,6,12,19,27}.*/

void sumatoriaEnOtroArray(int array1[], int arrayResultado[],int elementos){

    int i;

    arrayResultado[0] = array1[0];
    for (i=1; i < elementos; i++){
        arrayResultado[i] = array1[i] + arrayResultado[i-1];
    }


}

int fibonacciParaElProfe(int n){
    int n1,n2,fibo=0, i;

    if (n==0)
        return n;
    else if (n==1 || n==2)
        return n;
    else {
        n1 = 1;
        n2 = 1;
        i=2;
        while(i<=n){
            fibo = n1 + n2;
            n1 = n2;
            n2 = fibo;
            i++;
        }
    }
    return fibo;
//    if (n < 2)
//        return n;
//    return fibonacciParaElProfe(n - 1) + fibonacciParaElProfe(n - 2);

}

/*int * idEmpleados = malloc (100 8 sizeof(int));
    idEmpleados = realloc (idEmpleados, tamaño);
    free(idEmpleados);

si n=0 return n

sino si n=1 || n==2 return n

else i=2 n1 =1 n2 =1
    while i <=n
    fibo = n1+n2
    n1 = n2
    n2=fibo


    */

