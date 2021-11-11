#include <iostream>
#include <array>
#include <string>

// Vamos a incluir la clase Grupo
#include "Grupo.h"
#include "Grupo.h"

using namespace std;

// Declaramos las  funciones
void PedirpH(float& ph);
Grupo CrearGrupo(int i);

template <typename grupos>
int CalcularCargaApH(float& ph, grupos todosGrupos);


int main()
{
    // Definimos cuantos grupos tendra nuestra molécula
    const int numGrupos = 3;
    float phMolecula; // El pH en el  que va a estar sometida la molécula
    string nombreMolecula;

    // El usuario coloca el nombre de la molécula
    cout << "Nombre de la molecula:";
    cin >> nombreMolecula;

    // Creamos un arreglo de 'Grupos' para los grupos de la molécula
    array <Grupo, numGrupos> todosGrupos;
    // Pedimos información de cada grupo al usuario
    for (int i = 0; i < numGrupos; i++)
        todosGrupos[i] = CrearGrupo(i);

    // El usuario indica el pH al que está la molécula
    PedirpH(phMolecula);

    // Calculamos la carga neta de la molécula a un cierto pH
    int cargaMolecula = CalcularCargaApH(phMolecula, todosGrupos);
    cout << "Carga neta de la molecula:" << cargaMolecula << endl;

    // Si esta corrrecto  regresamos a 0
    return 0;
}

// Creamos  un nuevo 'Grupo' con la información ingresada
Grupo CrearGrupo(int i);

// Solicitamos el valor del pH
void PedirpH(float& ph)
{
    cout << "pH de la solucion (buffer): ";
    cin >> ph;
}

/* Calculamos  la carga eléctrica de la molécula dependiendo de la
 * carga eléctrica de cada uno de sus grupos y su pH.
*/
template <typename grupos>
int CalcularCargaApH(float& ph, grupos todosGrupos)
{
    int charge = 0;
    int netCharge = 0;

    for (int i = 0; i < todosGrupos.size(); i++) {

        if (ph > todosGrupos[i].getpK()){
            charge = todosGrupos[i].getCharge();
        }

        if(ph < todosGrupos[i].getpK()){
            charge = todosGrupos[i].getCharge() + 1;
        }

        netCharge += charge;
    }
    return netCharge;
}

Grupo CrearGrupo(int i) {
    string nombreGrupo;
    float pkGrupo;
    int cargaGrupo;
    cout << "Nombre grupo " << i << ":";
    cin >> nombreGrupo;
    cout << "pK del grupo " << nombreGrupo << ":";
    cin >> pkGrupo;
    cout << "Carga del grupo " << nombreGrupo << " a pH mayor a " << pkGrupo << ":";
    cin >> cargaGrupo;
    Grupo miGrupo(nombreGrupo, pkGrupo, cargaGrupo);
    return miGrupo;
}
