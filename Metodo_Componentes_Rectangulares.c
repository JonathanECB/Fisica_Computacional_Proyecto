// Este codigo obtiene la resultante a partir de 2 vectores con cierto angulo o sin angulo al igual que la magnitud de ambos

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

int main(void) {
    //obtencion de datos
    double vector1, vector2, vector1_angulo, vector2_angulo;
    //calculo de formulas
    double fx1, fy1, fx2, fy2, funcionx, funciony, teta, magnitud;
    char command[512];

    printf("\n\t\t\tBienvenido a la suma de vectores con metodos vistos en la clase de fisica de computacion de la profesora ALEJANDRA SOTO\n\n");
    //foto de sistema de coordenadas
    printf("Si no tiene conocimiento previo de los cuadrantes en un sistema de coordenadas, escriba 'v' y de enter para abrir una imagen guia en su navegador, de lo contrario solo precione enter para seguir con el metodo.\n");
    if (getchar() == 'v') {
        // Abre la URL en el navegador predeterminado
        sprintf(command, "start https://1.bp.blogspot.com/-kXf1RSiur_U/VmItLJ9ZCDI/AAAAAAAAAiw/dmlzbPLVSas/s1600/Foto5.png");
        system(command);
        // Limpiar el buffer de entrada (en caso de que haya caracteres adicionales)
        while (getchar() != '\n');
    }

    //Recopila los datos del primer y segundo vector
    printf("Diga la magnitud del primer vector (sin simbologia, solo el numero): ");
    scanf("%lf", &vector1);
    printf("Diga el angulo de inclinacion respecto al cuadrante 1 [x](0 - 360 grados [solo exprese el angulo en numeros]): ");
    scanf("%lf", &vector1_angulo);
    printf("Diga la magnitud del segundo vector (sin simbologia, solo numeros): ");
    scanf("%lf", &vector2);
    printf("Diga el angulo de inclinacion respecto al cuadrante 1 [x](0 - 360 grados [solo exprese el angulo en numeros]): ");
    scanf("%lf", &vector2_angulo);

    //Obtencion de fx1, fx2, fy1, fy2

    // Conversión de grados a radianes
    vector1_angulo = vector1_angulo * (PI / 180.0);
    vector2_angulo = vector2_angulo * (PI / 180.0);

    // Cálculo de las componentes
    fx1 = vector1 * cos(vector1_angulo);
    fy1 = vector1 * sin(vector1_angulo);
    fx2 = vector2 * cos(vector2_angulo);
    fy2 = vector2 * sin(vector2_angulo);

    // Suma de componentes
    funcionx = fx1 + fx2;
    funciony = fy1 + fy2;

    // Cálculo de la magnitud y el angulo del vector resultante
    magnitud = sqrt(funcionx * funcionx + funciony * funciony);
    teta = atan2(funciony, funcionx) * (180.0 / PI); // Conversión de radianes a grados

    //Resultados
    printf("\nComponente X del vector resultante: %lf\n", funcionx);
    printf("Componente Y del vector resultante: %lf\n", funciony);
    printf("Magnitud del vector resultante: %lf\n", magnitud);
    printf("Angulo del vector resultante (en grados): %lf\n", teta);

    return 0;
}

