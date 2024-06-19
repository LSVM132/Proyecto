#include <cstdio>

int numeros_reves(int numeros) {
    int numeros_reves = 0;
    while (numeros > 0) {
        numeros_reves = numeros_reves * 10 + numeros % 10;
        numeros /= 10;
    }
    return numeros_reves;
}

int main() {
    int numero_maximo;
    char continuar;

    do {
        printf("Digite un numero (maximo 5 digitos): ");
        scanf("%d", &numero_maximo);

        if (numero_maximo >= 0 && numero_maximo <= 99999) {
            printf("Número digitado: %d\n", numero_maximo);
            printf("Número al revés: %d\n", numeros_reves(numero_maximo));
        } else {
            printf("Número no válido.\n");
        }

        printf("¿Quieres continuar? (Si/No): ");
        scanf(" %c", &continuar);

    } while (continuar == 's' || continuar == 'S');
    // se usa || para que se puedan usar mayusculas y minisculas

    return 0;
}
