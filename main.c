#include <stdio.h>
#include "lab.h"
#include <string.h>

int main() {

    int cod;
    char arquivo[] = "tarefas";
    ListadeTarefas lt;
//transferir lista do arquivo binario
    cod = carregarLista(&lt,arquivo);

    if(cod == 1)
        lt.qtd = 0;

    int opcao;
    do{
        printMenu();
        scanf("%d",&opcao);

        if(opcao == 0){

        }
        else if(opcao == 1){
            criarTarefa(&lt);
        }else if(opcao == 2){
            deletarTarefa(&lt);
        }else if(opcao == 3){
            listaTarefas(lt);
        }else{
            printf("Opcao nao existe\n");
        }
    }while(opcao != 0);
    cod = salvarLista(lt,arquivo);
    if(cod != 0)
        printf("Erro ao salvar as tarefas");

    return 0;
}
