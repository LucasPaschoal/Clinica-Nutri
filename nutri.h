#ifndef NUTRI_H
#define NUTRI_H

#include <stdio.h>

struct _nutriPac {
    char nome[100];
    float altura;
    float peso;
    float imc;
    char classificacao[30];
};

typedef struct _nutriPac Paciente;

void lerArquivoPacientes(FILE *ptrFile, Paciente vetPac[], int numPac);
void calcularIMC(Paciente *pac);
void mostrarDadosPaciente(Paciente pac);

#endif