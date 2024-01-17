// Este codigo obtiene la resultante a partir de 2 vectores con cierto angulo o sin angulo en comun al igual que la magnitud de ambos con el metodo del triangulo sencillo (no se incluye un metodo complejo como la obtencion a partir de los angulos alfa, teta, beta)

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

int main(void)
{
    double vector1, vector2, vector1_angulo, vector2_angulo, angulo, magnitud, angulo_resultante;
    int opcion;

    printf("Seleccione el modo de ingreso de los vectores:\n");
    printf("1. Tengo el angulo entre los dos vectores.\n");
    printf("2. Tengo los angulos de cada vector respecto a un eje comun.\n");
    printf("Ingrese su opcion (1 o 2): ");
    scanf("%d", &opcion);

    if (opcion == 1) {
        // Caso donde el usuario tiene el angulo entre los dos vectores
        printf("Ingrese la magnitud del primer vector: ");
        scanf("%lf", &vector1);
        printf("Ingrese la magnitud del segundo vector: ");
        scanf("%lf", &vector2);
        printf("Ingrese el angulo entre los dos vectores (en grados): ");
        scanf("%lf", &angulo);
    } 
    else if (opcion == 2) 
    {
        // Caso donde el usuario tiene los angulos de cada vector individualmente
        printf("Ingrese la magnitud del primer vector: ");
        scanf("%lf", &vector1);
        printf("Ingrese el angulo del primer vector (en grados, respecto al eje X): ");
        scanf("%lf", &vector1_angulo);
        printf("Ingrese la magnitud del segundo vector: ");
        scanf("%lf", &vector2);
        printf("Ingrese el angulo del segundo vector (en grados, respecto al eje X): ");
        scanf("%lf", &vector2_angulo);

        //calcula y ajustar el angulo entre los vectores
        angulo = fabs(vector2_angulo - vector1_angulo); // Calcula la diferencia absoluta
        if (angulo > 180) 
        {
            angulo = 360 - angulo; // Ajusta si el angulo es mayor de 180 grados
        } 
    }
    else 
    {
        printf("Opcion no valida. Por favor, reinicie el programa e ingrese una opcion valida.\n");
        return 1;
    }

    // Conversión del angulo de grados a radianes
    angulo = angulo * (PI / 180.0);

    // Cálculo de la magnitud del vector resultante
    magnitud = sqrt(vector1 * vector1 + vector2 * vector2 + 2 * vector1 * vector2 * cos(angulo));

    // Cálculo del angulo del vector resultante
    if (opcion == 1) {
        if(vector1 + vector2 * cos(angulo) != 0) {
            angulo_resultante = atan2(vector2 * sin(angulo), vector1 + vector2 * cos(angulo)) * (180.0 / PI);
        } else {
            angulo_resultante = (vector2 * sin(angulo) >= 0) ? 90.0 : -90.0;
        }
    } else if (opcion == 2) {
        // Aquí sumas el angulo del segundo vector al angulo resultante para obtener la dirección final
        angulo_resultante = vector1_angulo + (atan2(vector2 * sin(angulo), vector1 + vector2 * cos(angulo)) * (180.0 / PI));
    }

    // Mostrar los resultados
    printf("\nMagnitud del vector resultante: %lf\n", magnitud);
    printf("angulo del vector resultante (en grados): %lf\n", angulo_resultante);

    if (opcion == 2) 
    {
        printf("angulo del primer vector respecto al eje X (angulo del eje comun, en grados): %lf\n", vector1_angulo);
    }

    return 0;

}
        