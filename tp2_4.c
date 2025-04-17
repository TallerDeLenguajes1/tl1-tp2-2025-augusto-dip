#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct compu
{
    int velocidad;
    int anio;
    int cantidad_nucleos;
    char *tipo_cpu;
};
void listarPCs(struct compu pcs[], int cantidad);
void mostrarMasVieja(struct compu pcs[], int cantidad);
void mostrarMasVeloz(struct compu pcs[], int cantidad);

int main (){
    int i;
    srand(time(NULL));

    char tipos[6][10] = {"Intel", "AMD", "Celeron", "Athlon", "Core", "Pentium"}; // Esto es un arreglo de 6 strings, y cada string puede tener hasta 9 caracteres
    struct compu pcs[5]; // Arreglo de 5 computadoras

    for (i = 0; i < 5; i++) {
        pcs[i].velocidad = 1 + rand() % 3;               // entre 1 y 3
        pcs[i].anio = 2015 + rand() % (2024 - 2015 + 1); // entre 2015 y 2024
        pcs[i].cantidad_nucleos = 1 + rand() % 8;        // entre 1 y 8
        pcs[i].tipo_cpu = tipos[rand() % 6];             //rand() % 6: genera un numero aleatorio entre 0 y 5 (porque % 6 da 6 posibles valores).
    }

    listarPCs(pcs, 5);
    mostrarMasVieja(pcs, 5);
    mostrarMasVeloz(pcs, 5);

    return 0;
}
// DECLARACION DE FUNCIONES //
void listarPCs(struct compu pcs[], int cantidad){
    int i;
    for (i=0; i<cantidad; i++){
        printf(" PC %d:\n", i + 1);
        printf("  Velocidad: %d GHz\n", pcs[i].velocidad);
        printf("  Anio: %d\n", pcs[i].anio);
        printf("  Nucleos: %d\n", pcs[i].cantidad_nucleos);
        printf("  Tipo CPU: %s\n\n", pcs[i].tipo_cpu);
        printf(" /////////////////////////////////////// \n");
    }
}

void mostrarMasVieja(struct compu pcs[], int cantidad){
    int i, indice, pc_mas_vieja = 5000;

    for (i=0; i<cantidad; i++){
        if(pcs[i].anio < pc_mas_vieja){
            pc_mas_vieja = pcs[i].anio;
            indice = i;
        }
    }
    printf(" Caracteristicas de la PC mas vieja: PC %d\n", indice + 1);
    printf("  Velocidad: %d GHz\n", pcs[indice].velocidad);
    printf("  Anio: %d\n", pcs[indice].anio);
    printf("  Nucleos: %d\n", pcs[indice].cantidad_nucleos);
    printf("  Tipo CPU: %s\n\n", pcs[indice].tipo_cpu);
    printf("  La computadora mas vieja es del anio: %d \n\n", pc_mas_vieja);
    printf(" /////////////////////////////////////// \n");        
}

void mostrarMasVeloz(struct compu pcs[], int cantidad){
    int i, indice, pc_mas_veloz = 0;

    for (i=0; i<cantidad; i++){
        if(pcs[i].velocidad > pc_mas_veloz){
            pc_mas_veloz = pcs[i].velocidad;
            indice = i;
        }
    }
    printf(" Caracteristicas de la PC mas veloz: PC %d\n", indice + 1);
    printf("  Velocidad: %d GHz\n", pcs[indice].velocidad);
    printf("  Anio: %d\n", pcs[indice].anio);
    printf("  Nucleos: %d\n", pcs[indice].cantidad_nucleos);
    printf("  Tipo CPU: %s\n\n", pcs[indice].tipo_cpu);
    printf("  La computadora mas veloz es del anio: %d \n\n", pc_mas_veloz);
    printf(" /////////////////////////////////////// \n");        
}

