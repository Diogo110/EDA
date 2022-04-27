#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <errno.h>

#include "header.h"
#include "functions.c"

int main(int argc, char const *argv[]) {
    job *jobList;
    int opcao, idCont = 0;
    
    jobList = inicializarJob();
	verificarDadosNoFicheiro(jobList->op,&idCont,&(jobList->nOperations));

    do {
        menu(&opcao);

        switch(opcao) {
            case 0: printf("Goodbye!!\n\n"); 
					break;
            case 1: InserirNovaOp(jobList->op,&idCont); 
					break;
            case 2: ListarOp(jobList->op,jobList->nOperations); 
					break;
            case 3: RemoverOp(&jobList);
					break;
            case 4: EditarOp(jobList->op);
					break;
            case 5: DeterminarTempoMin(jobList->op);
					break;
            case 6: DeterminarTempoMax(jobList->op);
					break;
        }
    }while(opcao != 0);

    free(jobList->op);
    free(jobList);
    return 0;
}