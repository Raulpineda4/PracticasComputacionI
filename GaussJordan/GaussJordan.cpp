/*
 * Autor: Raul Pineda Urbina
 * Correo: pinedaurbinaraul@gmail.com
 * 20 de Septiembre de 2021
 */

#include <iostream>
#include <array>

// Añadimos std para el llamado de funciones
using namespace std;

//// Declaración de funciones
//Definimos un template que es un tipo de dato para la matriz
template <typename matriz>
void LlenarMatriz(matriz & miMatriz);

template <typename matriz>
void ImprimirMatriz(matriz & miMatriz);

template <typename matriz>
void GaussJordan(matriz & miMatriz);

template <typename matriz>
void Imprimirlasolucion(matriz & miMatriz);


int main()
{
    // Definir el número de variables de nuestro sistema
    const int variables = 3;
    // El número de variables nos lo dice el numero de columnas  más su solición para cada ecuación
    const int columnas = variables + 1;

    // Iniciamos la matriz que vamos a ocupar
    array <array<float, columnas>, variables> miMatriz = { 0 };

    // El usuario llena la matriz
    LlenarMatriz(miMatriz);

    // Vamos a Aplicar el método de Gauss-Jordan sobre nuestra matriz
    GaussJordan(miMatriz);

    // Imprimimos la solución de la matriz
    Imprimirlasolucion(miMatriz);

    return 0; // Salida del programa
}

/*
Llena 'miMatriz' con valores ingresados por el usuario para cada elemento.
No regresa ningún valor.
*/
template <typename matriz>
void LlenarMatriz(matriz & miMatriz)
{
    int variables = miMatriz.size();
    // el ciclo for no tiene error, arriba es 2 por que en variables solo tengo 3 valores
    for (int i = 0; i < variables; i++) {
        for (int j = 0; j <= variables; j++) {
            cout << "Valor elemento [" << i << "][" << j << "]:";
            cin >> miMatriz[i][j];
        }
    }
}

/*
Imprime cada elemento de 'miMatriz' emulando una matriz con corchetes cuadrados.
No regresa ningún valor.
*/
template <typename matriz>
void ImprimirMatriz(matriz & miMatriz)
{
    int variables = miMatriz.size();
    for (int i = 0; i < variables; i++) {
        cout << "[ ";
        for (int j = 0; j < variables + 1; j++)
            cout << miMatriz[i][j] << '\t';
        cout << "]\n";
    }
}

/*
Imprime  la solución  del sistema de ecuaciones para cada variable correspondiente a los valores en 'miMatriz'.
No regresa ningún valor.
*/
template <typename matriz>
void Imprimirlasolucion(matriz & miMatriz)
{
    int variables = miMatriz.size();
    cout << "\nSolución:" <<endl;
    for(int i = 0; i < variables; i++){
        cout <<"x" << i << " = "<< miMatriz[i][variables] << endl;
    }
}

/*
Implementa el algoritmo de Gauss-Jordan sobre 'miMatriz', finalizando en ella la solución del algoritmo.
No regresa ningún valor.
*/
template <typename matriz>
void GaussJordan(matriz & miMatriz) {
    double upper;
    int index;
    double auxiliar;
    double pivote;

    int rows = miMatriz.size();
    for(int i = 0; i < rows; i++ ){
        upper = abs(miMatriz[i][i]);
        index = i;
        for(int j = i + 1; j < rows; j++){
            if(upper < abs(miMatriz[j][i])){
                upper = abs(miMatriz[j][i]);
                index = j;
            }
        }
        if(i != index){
            for(int k = 0; k < rows + 1; k++){
                auxiliar = miMatriz[i][k];
                miMatriz[i][k] = miMatriz[index][k];
                miMatriz[index][k] = auxiliar;
            }
        }
        if(miMatriz[i][i] == 0){
            cout << "No existe solucion\n";
        }
        else{
            for(int k = 0; k < rows; k++){
                if (k != i){
                    pivote = -miMatriz[k][i];
                    for(int l = i; l < rows + 1; l++){
                        miMatriz[k][l] = miMatriz[k][l] + pivote * miMatriz[i][l] / miMatriz[i][i];
                    }
                }
                else{
                    pivote = miMatriz[i][i];
                    for(int l = i; l < rows + 1; l++){
                        miMatriz[k][l] = miMatriz[k][l] / pivote;
                    }
                }
            }
        }
    }
}
