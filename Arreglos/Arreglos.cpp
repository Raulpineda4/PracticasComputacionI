/*
 * Autor: Raul Pineda Urbina
 * Correo: pinedaurbinaraul@gmail.com
 * 20 de Septiembre de 2021
 */

#include <iostream>
#include <array>

#define LEN 3 //Número de elementos en los arreglos

// Añadir std para el llamado de funciones
using namespace std;

// Declarar las  funciones
void ImprimirArreglo(array<float, LEN> arreglo);
array<float, LEN> LlenarArreglo(void);
array<float, LEN> MultiplicarArreglo(array<float, LEN> arreglo, float multiplo);
array<float, LEN> SumadeArreglos(array<float, LEN> arr1, array<float, LEN> arr2);


int main()
{
    array<float, LEN> arr = { 0 }; // Inicializamos el arreglo con ceros como debe de ser
    arr = LlenarArreglo(); // El usuario tiene que llenar un arreglo y lo asignamos a nuestro arreglo principal
    char decision;
    cout << "Operación:";
    cin >> decision;
    // Si la operación no es '+' de suma, o '*' de multiplicación, seguimos preguntando al usuario.
    while (decision != '+' && decision != '*')
    {
        cout << "Operación:";
        cin >> decision;
    }
    // Si se ingresa una multiplicación
    if (decision == '*') {
        float factor;
        cout << "Factor:";
        cin >> factor;  // Pedimos el factor que multiplicara a los elementos
        arr = MultiplicarArreglo(arr, factor); // Multiplicamos nuestro arreglo principal por el factor y el resultado lo asignamos a nuestro arreglo principal.
    }
    // Si se ingresa la suma
    else if (decision == '+') {
        array<float, LEN> arr2 {0}; // Se crea un segundo arreglo y lo inicializamos en ceros
        arr2 = LlenarArreglo(); // Pedimos al usuario que llene otro arreglo y lo asignamos a nuestro nuevo arreglo
        arr = SumadeArreglos(arr, arr2); // Vamos a sumar ambos arreglos elemento a elemento, y reasignamos el resultado a nuestro arreglo principal
    }
    cout << "Resultado: ";
    ImprimirArreglo(arr); // Imprimimos el resultado de la operación sobre el arreglo principal
    return 0; // Decimos que el programa fue un exito
}

// Imprime los elementos del arreglo 'arreglo' separando cada elemento con un espacio en blanco
void ImprimirArreglo(array<float, LEN> arreglo)
{

    for (int i = 0; i < LEN; i++)
        cout << arreglo[i] << ' ';
    cout << '\n';
}

// Llena un arreglo de tamaño LEN y lo "regresa" como resultado
array<float, LEN> LlenarArreglo()
{
    array<float, LEN> arr{0};
    float a = 0, b = 0, c = 0;
    cout << "Valor elemento [0]:";
    cin >> a;
    cout << "Valor elemento [1]:";
    cin >> b;
    cout << "Valor elemento [2]:";
    cin >> c;

    arr[LEN - (LEN)] = a;
    arr[LEN - (LEN - 1)] = b;
    arr[LEN - (LEN - 2)] = c;
    return arr;
}

// Multiplica cada elemento del arreglo 'arreglo' por el factor 'mult'
array<float, LEN> MultiplicarArreglo(array<float, LEN> arreglo, float multiplo)
{
    array<float, LEN> arr{0};
    for (int i = 0; i < LEN; i++){
        arr[i] = arreglo[i] * multiplo;
    }
    return arr;
}

// Suma elemento a elemento los arreglos 'arr1' y 'arr2' y regresa el arreglo resultante
array<float, LEN> SumadeArreglos(array<float, LEN> arr1, array<float, LEN> arr2)
{
    array<float, LEN> arr{0};
    for (int i = 0; i < LEN; i++){
        arr[i] = arr1[i] + arr2[i];
    }
    return arr;
}
