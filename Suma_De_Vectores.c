#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define PI 3.14159265358979323846

void menu(void);


int main (void)
{
    double vector1, vector2, vector1_angulo, vector2_angulo, angulo, magnitud, angulo_resultante;
    double fx1, fy1, fx2, fy2, funcionx, funciony, teta;
    int opcion, eleccion;
    char command[512];
    
    printf("\nBienvenido a la suma de vectores con metodos vistos en la clase de fisica de computacion de la profesora ALEJANDRA SOTO\n\n");

    //foto de sistema de coordenadas
    printf("Si no tiene conocimiento previo de los cuadrantes en un sistema de coordenadas, escriba 'v' (minuscula) y de enter para abrir una imagen guia en su navegador, de lo contrario solo precione enter para seguir con el metodo.\n");
    if (getchar() == 'v') {
        // Abre la URL en el navegador predeterminado
        sprintf(command, "start https://1.bp.blogspot.com/-kXf1RSiur_U/VmItLJ9ZCDI/AAAAAAAAAiw/dmlzbPLVSas/s1600/Foto5.png");
        system(command);
        // Limpiar el buffer de entrada (en caso de que haya caracteres adicionales)
        while (getchar() != '\n');
    }
    do
    {
        // Resetear variables para evitar que se quede algun dato en alguna
        vector1 = 0;
        vector2 = 0;
        vector1_angulo = 0;
        vector2_angulo = 0;
        angulo = 0;
        fx1 = 0;
        fy1 = 0;
        fx2 = 0;
        fy2 = 0;
        funcionx = 0;
        funciony = 0;
        teta = 0;
        magnitud = 0;
        angulo_resultante = 0;

        menu();
        scanf("%d", &eleccion);
        switch (eleccion)
        {
            case 1:
            {
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
            }
            break;
            case 2:
            {
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
            }
            break;
            case 3:
            {
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
                if(vector1 + vector2 * cos(angulo) != 0) 
                {
                    angulo_resultante = atan2(vector2 * sin(angulo), vector1 + vector2 * cos(angulo)) * (180.0 / PI);
                }
                else 
                {
                    // Manejar el caso especial donde el denominador es 0
                    angulo_resultante = (vector2 * sin(angulo) >= 0) ? 90.0 : -90.0;
                }

                // Mostrar los resultados
                printf("\nMagnitud del vector resultante: %lf\n", magnitud);
                printf("angulo del vector resultante respecto al primer vector (en grados): %lf\n", angulo_resultante);

                if (opcion == 2) 
                {
                    printf("angulo del primer vector respecto al eje X (angulo del eje comun, en grados): %lf\n", vector1_angulo);
                }
            }
            break;
            case 4: printf("Que tenga buen dia !!!!");
            break;
            default: printf("Operador incorrecto, intente nuevamente");
            break;
        }   
    } while (eleccion != 4);
    
    return 0;
}

void menu()
{
    printf("\nEliga la opcion que desee que se ejecute: \n\n");
    printf("1.- Usar Metodo de Componentes Rectangulares\n");
    printf("2.- Usar Metodo Triangulo\n");
    printf("3.- Usar Metodo Paralelogramo\n");
    printf("4.- Salir\n\n");
    printf("\t\tOpcion: ");
}