#include <iostream>
#include <string.h>
#include <iomanip>
using namespace std;

const int longCad = 20;

struct costoPorArticulo{
    char nombreArticulo[longCad + 1];
    int cantidad;
    float precio;
    float costoPorArticulo;
};

//Declaración de las funciones a utilizar en el programa
void leerDatos(costoPorArticulo *articulo, int n);
void calcularCosto(costoPorArticulo *articulo, int n);
void mostrarDatos(costoPorArticulo *articulo, int n);
float totalCompra(costoPorArticulo *articulo, int n);

int main(){
    int n; //Variable que almacenará el número de artículos a comprar
    cout<<"\n********************************************************";
    cout<<"\n\t\tTIENDA \"El SUPERCITO\""<<endl;
    cout<<"********************************************************"<<endl;
    cout<<"Ingrese la cantidad de productos que desea comprar: ";
    cin>>n; //Pedimos al usuario que ingrese la cantidad de articulos
    cin.ignore(100, '\n'); //Limpiamos el teclado

    /*Declaramos un puntero de tipo "costoPorArticulo". Asimismo, reservamos de manera dinámica un
    espacio de memoria para almacenar un arreglo de tipo "costoPorArticulo" de longitud n. El puntero
    "*articulo" apunta a la dirección de memoria donde comienza dicho arreglo y todas las tareas
    que necesitemos realizar con el arreglo serán manejadas con el puntero.*/
    costoPorArticulo *articulo = new costoPorArticulo[n];

    //Invocamos la función leerDatos
    leerDatos(articulo, n);
    //Invocamos la función calcularCosto
    calcularCosto(articulo, n);
    //Invocamos la función mostrarDatos
    mostrarDatos(articulo, n);
    //Invocamos la función totalCompra y mostramos en pantalla el total de la compra
    cout<<"El total de la compra es: $"<<fixed<<setprecision(2)<<totalCompra(articulo, n)<<endl;
    cout<<"\n********************************************************";
    cout<<"\n\t   MUCHAS GRACIAS POR SU PREFERENCIA"<<endl;
    cout<<"********************************************************"<<endl;
    return 0;
}

/*Función que lee los datos de cada artículo y los incorpora al arreglo. Esta función recibe como
parámetros el puntero que referencia al arreglo donde se almacena la información y el índice de dicho 
arreglo. Utilizamos operaciones con punteros, recorriendo las celdas de memoria donde está almacenado
el arreglo para guardar la información*/
void leerDatos(costoPorArticulo *articulo, int n){
    string nombre; //Declaramos una variable para almacenar el nombre del articulo
    for(int i=0; i<n; i++){
        cout<<"\nIngrese el nombre del producto #"<<i+1<<": ";
        getline(cin, nombre, '\n'); //Capturamos lo que el usuario ingrese en el teclado
        /*Copiamos lo que está almacenado en la variable "nombre" y lo incorporamos al
        campo "nombreArticulo" con la función strncpy de la librería string.h*/
        strncpy((articulo+i)->nombreArticulo, nombre.c_str(), longCad);
        /*"nombreArticulo" acepta un máximo de 20 caracteres y podría existir la posibilidad
        de que el usuario ingrese un nombre con mas de 20 caracteres, por lo cual, nos aseguramos
        que en la última posición exista un '\0' que indica el final de la cadena.*/
        (articulo+i)->nombreArticulo[longCad] = '\0';
        cout<<"Ingrese la cantidad de articulos comprados: ";
        cin>>(articulo+i)->cantidad; //Solicitamos la cantidad
        cout<<"Ingrese el precio unitario por articulo: $";
        cin>>(articulo+i)->precio; //Solicitamos el precio unitario
        cin.ignore(100, '\n');
    }
}

/*Función que calcula el costo total de cada artículo y lo incorpora al arreglo en su respectiva
posición. Esta función recibe como parámetros el puntero que hace referencia al arreglo y la 
longitud de dicho arreglo*/
void calcularCosto(costoPorArticulo *articulo, int n){
    for(int i=0; i<n; i++){
        (articulo+i)->costoPorArticulo = ((articulo+i)->precio * (articulo+i)->cantidad);
    }
}

/*Función que imprime en pantalla los datos de cada artículo. Recibe como parámetros el puntero 
que referencia al arreglo donde están almacenados los datos, y la longitud de dicho arreglo.*/
void mostrarDatos(costoPorArticulo *articulo, int n){
    cout<<"\n********************************************************";
    cout<<"\n\tFACTURA COMERCIAL - DETALLE DE LA COMPRA"<<endl;
    cout<<"********************************************************"<<endl;
    for(int i=0; i<n; i++){
        cout<<">PRODUCTO #"<<i+1<<":"<<endl;
        cout<<"Nombre: "<<(articulo+i)->nombreArticulo<<endl;
        cout<<"Precio unitario: $"<<fixed<<setprecision(2)<<(articulo+i)->precio<<endl;
        cout<<"Cantidad: "<<(articulo+i)->cantidad<<endl;
        cout<<"Costo del articulo: $"<<fixed<<setprecision(2)<<(articulo+i)->costoPorArticulo<<endl<<endl;
    }
}

/*Función que calcula el costo total de la compra. Suma los costos de cada artículo y retorna
dicho valor. Recibe como parámetros el puntero que referencia al arreglo donde están 
almacenados los datos, y la longitud de dicho arreglo.*/
float totalCompra(costoPorArticulo *articulo, int n){
    float total = 0;
    for(int i=0; i<n; i++){
        total += (articulo+i)->costoPorArticulo;
    }
    return total;
}