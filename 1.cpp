#include <iostream>
#include <limits>
#include <sstream>
#include <vector>

using namespace std;

// Función para imprimir mensajes
void imprimir(const string &mensaje) {
    cout << mensaje;
}

// Función para obtener números desde una cadena
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
    
    // Simular entrada de usuario (puedes modificar esta cadena según necesites)
    cout << "Ingrese numeros enteros (separados por espacio): ";
    getline(cin, entrada);

    // Obtener los números desde la cadena de entrada
    vector<int> numeros = obtenerNumeros(entrada);
    int cantidadNumeros = numeros.size();
    int maxNumero = numeric_limits<int>::min();
    int maxPosicion = -1;
    int conteoPrimos = 0, sumaPrimos = 0;
    int conteoNoPrimos = 0, sumaNoPrimos = 0;
    int posicion = 0;

    // Analizar los números ingresados
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
    mensajeFinal << "\nEstadísticas finales:\n"
                 << "Número Mayor Ingresado: " << maxNumero << " en la posición " << maxPosicion << "\n"
                 << "Cantidad de Números Primos: " << conteoPrimos << "\n"
                 << "Suma de los Números Primos: " << sumaPrimos << "\n"
                 << "Promedio de los Números Primos: " << promedioPrimos << "\n"
                 << "Cantidad de Números No Primos: " << conteoNoPrimos << "\n"
                 << "Suma de los Números No Primos: " << sumaNoPrimos << "\n"
                 << "Promedio de los Números No Primos: " << promedioNoPrimos << "\n";

    imprimir(mensajeFinal.str());

    return 0;
}


