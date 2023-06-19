#include "nutri.h"
#include <stdio.h>

void lerArquivoPacientes(FILE *ptrFile, Paciente vetPac[], int numPac) {
    for (int i = 0; i < numPac; i++) {
        fscanf(ptrFile, "%s %f %f", vetPac[i].nome, &vetPac[i].altura, &vetPac[i].peso);
    }
}

void calcularIMC(Paciente *pac) {
    pac -> imc = pac -> peso / (pac -> altura * pac -> altura);

    if (pac -> imc < 18.5) {
        sprintf(pac -> classificacao, "Baixo peso");
    } else if (pac -> imc >= 18.5 && pac -> imc <= 24.99) {
        sprintf(pac -> classificacao, "Peso normal");
    } else if (pac -> imc >= 25 && pac -> imc <= 29.99) {
        sprintf(pac -> classificacao, "Sobrepeso");
    } else if (pac -> imc >= 30 && pac -> imc <= 39.99) {
        sprintf(pac -> classificacao, "Obesidade");
    } else if (pac -> imc >= 40) {
        sprintf(pac -> classificacao, "Obesidade grave");
    }
}

void mostrarDadosPaciente(Paciente pac) {
        printf("Nome   : %s\n", pac.nome);
        printf("Peso   : %.2f\n", pac.peso);
        printf("Altura : %.2f\n", pac.altura);
        printf("IMC    : %.2f\n\n", pac.imc);
        printf("Classificacao: %s\n", pac.classificacao);
        printf("----------------------------------------");
}