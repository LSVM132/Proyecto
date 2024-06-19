#include <iostream>
#include <limits>
#include <sstream>
#include <vector>

using namespace std;

// Funci�n para imprimir mensajes
void imprimir(const string &mensaje) {
    cout << mensaje;
}

// Funci�n para obtener n�meros desde una cadena
vector<int> obtenerNumeros(const string &entrada) {
    vector<int> numeros;
    stringstream ss(entrada);
    int num;
    
    while (ss >> num) {
        numeros.push_back(num);
    }
    
    return numeros;
}

bool esPrimo(int num) {
    if (num <= 1) return false;
    for (int i = 2; i <= num / 2; ++i) {
        if (num % i == 0) return false;
    }
    return true;
}

int main() {
    string entrada;
    
    // Simular entrada de usuario (puedes modificar esta cadena seg�n necesites)
    cout << "Ingrese numeros enteros (separados por espacio): ";
    getline(cin, entrada);

    // Obtener los n�meros desde la cadena de entrada
    vector<int> numeros = obtenerNumeros(entrada);
    int cantidadNumeros = numeros.size();
    int maxNumero = numeric_limits<int>::min();
    int maxPosicion = -1;
    int conteoPrimos = 0, sumaPrimos = 0;
    int conteoNoPrimos = 0, sumaNoPrimos = 0;
    int posicion = 0;

    // Analizar los n�meros ingresados
    for (int i = 0; i < cantidadNumeros; ++i) {
        int num = numeros[i];
        posicion++;

        if (num > maxNumero) {
            maxNumero = num;
            maxPosicion = posicion;
        }

        if (esPrimo(num)) {
            conteoPrimos++;
            sumaPrimos += num;
        } else {
            conteoNoPrimos++;
            sumaNoPrimos += num;
        }
    }

    double promedioPrimos = (conteoPrimos == 0) ? 0 : static_cast<double>(sumaPrimos) / conteoPrimos;
    double promedioNoPrimos = (conteoNoPrimos == 0) ? 0 : static_cast<double>(sumaNoPrimos) / conteoNoPrimos;

    stringstream mensajeFinal;
    mensajeFinal << "\nEstad�sticas finales:\n"
                 << "N�mero Mayor Ingresado: " << maxNumero << " en la posici�n " << maxPosicion << "\n"
                 << "Cantidad de N�meros Primos: " << conteoPrimos << "\n"
                 << "Suma de los N�meros Primos: " << sumaPrimos << "\n"
                 << "Promedio de los N�meros Primos: " << promedioPrimos << "\n"
                 << "Cantidad de N�meros No Primos: " << conteoNoPrimos << "\n"
                 << "Suma de los N�meros No Primos: " << sumaNoPrimos << "\n"
                 << "Promedio de los N�meros No Primos: " << promedioNoPrimos << "\n";

    imprimir(mensajeFinal.str());

    return 0;
}


