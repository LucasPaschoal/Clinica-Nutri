
#include <stdio.h>
#include <stdlib.h>
#include "nutri.h"

int main() {
    FILE *ptrFile;
    int numPac;

    // leitura do número de pacientes
    scanf("%d", &numPac);
    if (numPac <= 0) {
        printf("Informe um valor maior que 0.");
        return 1;
    }
    if (numPac > 100) {
        printf("O valor informado deve estar no intervalo: 0 < valor <= 100");
        return 0;
    }

    // abertura do arquivo
    ptrFile = fopen("nutri_dataset.txt", "r");
    if (ptrFile == NULL) {
        printf("Arquivo nao encontrado.");
        return 0;
    }

    // alocação dinâmica do vetor de pacientes
    Paciente *vetPac = (Paciente*) malloc(numPac * sizeof(Paciente));
    if (vetPac == NULL) {
        printf("Erro na alocacao de memoria\n");
        fclose(ptrFile);
        return 1;
    }

    // leitura dos pacientes a partir do arquivo
    lerArquivoPacientes(ptrFile, vetPac, numPac);

    // cálculo do IMC de cada paciente
    for (int i = 0; i < numPac; i++) {
        calcularIMC(&vetPac[i]);
    }

    // exibição dos dados de cada paciente
    printf("----------------------------------------\n");
    for (int i = 0; i < numPac; i++) {
        mostrarDadosPaciente(vetPac[i]);
        printf("\n");
    }

    // liberação da memória alocada
    free(vetPac);
    fclose(ptrFile);

    return 0;
}