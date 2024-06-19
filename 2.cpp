#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
 
using namespace std;
 
// Se imprime los mensajes
void imprimir(const string &mensaje) {
    cout << mensaje;
}
 
 
string leerLinea(const string &mensaje) {
    string linea;
    imprimir(mensaje);
    getline(cin, linea);
    return linea;
}
 
// Función para leer la entrada
int leerEntero(const string &mensaje) {
    int valor;
    string linea;
    while (true) {
        linea = leerLinea(mensaje);
        stringstream ss(linea);
        if (ss >> valor) {
            return valor;
        }
        imprimir("Entrada invalida. Por favor, ingrese un numero entero.\n");
    }
}
 
 
char leerCaracter(const string &mensaje) {
    char valor;
    string linea;
    while (true) {
        linea = leerLinea(mensaje);
        if (linea.length() == 1) {
            valor = linea[0];
            return valor;
        }
        imprimir("Entrada invalida. Por favor, ingrese un solo caracter.\n");
    }
}
 
int main() {
    int numeroFactura = 0;
    int cantidadGaleria = 0, cantidadPalco = 0, cantidadTotal = 0;
    double dineroGaleria = 0.0, dineroPalco = 0.0, dineroTotal = 0.0;
 
    while (true) {
        string cedula, nombre;
        int cliente, tiquete, cantidad;
        double montoUnitario, montoVenta, descuento, subtotal, impuesto, totalPagar;
 
        numeroFactura++;
 
        cedula = leerLinea("Ingrese la cedula del Usuario: ");
        nombre = leerLinea("Ingrese el nombre del Usuario: ");
 
        do {
            cliente = leerEntero("Ingrese el tipo de Usuario (1=Nino o adulto mayor, 2=Adulto): ");
        } while (cliente != 1 && cliente != 2);
 
        do {
            tiquete = leerEntero("Ingrese el tipo de tiquete (1=Graderia, 2=Palco): ");
        } while (tiquete != 1 && tiquete != 2);
 
        cantidad = leerEntero("Ingrese la cantidad de tiquetes: ");
 
        if (tiquete == 1) {
            montoUnitario = 6000.0;
        } else {
            montoUnitario = 12000.0;
        }
 
        montoVenta = montoUnitario * cantidad;
 
        if (cliente == 1) {
            descuento = montoVenta * 0.30;
        } else {
            descuento = 0.0;
        }
 
        subtotal = montoVenta - descuento;
        impuesto = subtotal * 0.13;
        totalPagar = subtotal + impuesto;
 
        if (tiquete == 1) {
            cantidadGaleria += cantidad;
            dineroGaleria += totalPagar;
        } else {
            cantidadPalco += cantidad;
            dineroPalco += totalPagar;
        }
 
        cantidadTotal += cantidad;
        dineroTotal += totalPagar;
 			//Desglose 
        stringstream ss;
        ss << fixed << setprecision(2);
        ss << "Número de factura: " << numeroFactura << endl;
        ss << "Cédula del cliente: " << cedula << endl;
        ss << "Nombre del cliente: " << nombre << endl;
        ss << "Tipo de cliente: " << (cliente == 1 ? "Nino o adulto mayor" : "Adulto") << endl;
        ss << "Tipo de tiquete: " << (tiquete == 1 ? "Graderia" : "Palco") << endl;
        ss << "Cantidad de tiquetes: " << cantidad << endl;
        ss << "Monto unitario por tiquete: " << montoUnitario << endl;
        ss << "Monto de venta: " << montoVenta << endl;
        ss << "Descuento: " << descuento << endl;
        ss << "Subtotal de venta: " << subtotal << endl;
        ss << "Impuesto de venta: " << impuesto << endl;
        ss << "Total a pagar: " << totalPagar << endl;
        imprimir(ss.str());
 
        char c = leerCaracter("¿Desea registrar otra venta? (s/n): ");
        if (c != 's' && c != 'S') {
            break;
        }
    }
  //mensaje final 
    stringstream estadisticasFinales;
    estadisticasFinales << "Estadísticas finales:" << endl;
    estadisticasFinales << "Cantidad de entradas Tiquetes Galeria: " << cantidadGaleria << endl;
    estadisticasFinales << "Acumulado Dinero por Tiquetes Galeria: " << dineroGaleria << endl;
    estadisticasFinales << "Cantidad de entradas Tiquetes Palco: " << cantidadPalco << endl;
    estadisticasFinales << "Acumulado Dinero por Tiquetes Palco: " << dineroPalco << endl;
    estadisticasFinales << "Cantidad General de Entradas: " << cantidadTotal << endl;
    estadisticasFinales << "Acumulado General Dinero por Entradas: " << dineroTotal << endl;
    estadisticasFinales << "Promedio General por Ventas: " << (dineroTotal / numeroFactura) << endl;
    imprimir(estadisticasFinales.str());
 
    return 0;
}


