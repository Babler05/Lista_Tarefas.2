#include <stdio.h>
#include "lab.h"
#include <string.h>
#include <stdlib.h>

int main() {

    int cod;
    char arquivo_b[] = "tarefas";
    char arquivo_txt[] = "tarefas.txt";
    ListadeTarefas *lt = malloc(sizeof(ListadeTarefas));
//transferir lista do arquivo binario
    cod = carregarLista(lt,arquivo_b);

    if(cod == 1)
        lt->qtd = 0;

    int opcao;
    do{
        printMenu();
        scanf("%d",&opcao);

        if(opcao == 0){

        }
        else if(opcao == 1){
            criarTarefa(lt);
        }else if(opcao == 2){
            deletarTarefa(lt);
        }else if(opcao == 3){
            listarTarefas(lt);
        }else if(opcao == 4){
            alterarTarefa(lt);
        }else if (opcao == 5){
            filtrarTarefas(lt);
        }else if (opcao== 6){
            exportarTarefas(lt,arquivo_txt);
        
        }else{
            printf("Opcao nao existe\n");
        }
    }while(opcao != 0);
    cod = salvarLista(lt,arquivo_b);
    if(cod != 0)
        printf("Erro ao salvar as tarefas");

    return 0;
}
