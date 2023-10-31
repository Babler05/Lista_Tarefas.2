
#include "lab.h"
#include <stdio.h>
#include <string.h>

void printMenu(){
    printf("Menu: \n");
    printf("0: Sair\n");
    printf("1. Criar Tarefa\n");
    printf("2. Deletar Tarefa(confira o numero na lista(opcao 3))\n");
    printf("3. Listar Tarefas:\n");
    printf("4. Alterar Tarefa\n");
}

int criarTarefa(ListadeTarefas *lt){
    //inputs do struct
    printf("Digite a categoria da tarefa: ");
    scanf("%s",lt->tarefas[lt->qtd].categoria);
    printf("Digite o numero de prioridade de tarefa(0-10): ");
    scanf("%d", &lt->tarefas[lt->qtd].prioridade);
    //se a prioridade for fora da margem
    if(lt->tarefas[lt->qtd].prioridade < 0 || lt->tarefas[lt->qtd].prioridade > 10){
        printf("Numero invalido! Tente outro numero(0-10): ");
        scanf("%d",&lt->tarefas[lt->qtd].prioridade);
    }
  
  printf("Escreva o estado da tarefa:\n");
  printf("Completo\n");
  printf("Em andamento\n");
  printf("Não iniciado\n");
  scanf("%s",lt->tarefas[lt->qtd].estado);
  
  printf("Escreva a descricao da tarefa: ");
  scanf("%s",lt -> tarefas[lt->qtd].descricao);
    //mudança da quantidade
   lt->qtd +=1;

 return 0;}
int deletarTarefa(ListadeTarefas *lt){
    // input da posicao da tarefa
    int pos;
    printf("Digite a posicao da tarefa: ");
    scanf("%d",&pos);
    //procurar o numero da tarefa
    for(int i = 0; i < lt->qtd; i++){
      if(pos-1 == i){
        for(int j =i; j < lt->qtd;j++ ) {
  //transfere as informações da struct seguinte para a padrão
          lt->tarefas[j] = lt->tarefas[j + 1];
//Diminui a quantidade para o comando listaTarefas não ler o q foi deletado
          lt->qtd--;

          }
        }
    }

  return 0;
}


int listaTarefas(ListadeTarefas lt){
    for(int i = 0; i < lt.qtd;i++){

        printf("Tarefa %d\n",i+1);
        printf("Categaria: %s \n",lt.tarefas[i].categoria);
        printf("Prioridade: %d \n",lt.tarefas[i].prioridade);
        printf("Estado: %s \n",lt.tarefas[i].estado);
        printf("Descricao: %s \n",lt.tarefas[i].descricao);
        printf("\n");
    }

    return 0;}


int salvarLista(ListadeTarefas lt, char nome[]){
    FILE *f = fopen(nome, "wb");

    fwrite(&lt, sizeof(ListadeTarefas),1,f);
    fclose(f);
    return 0;}

int carregarLista(ListadeTarefas *lt,char nome[]){
    FILE *f = fopen(nome, "rb");
    // checagem para ver se o arquivo tem erro ou nao
    if(f == NULL){
        printf("Erro ou arquivo inexistente\n");
        return 1;
    }

    fread(lt,sizeof(ListadeTarefas),1,f);
    fclose(f);
    return 0;}

int alterarTarefa(ListadeTarefas *lt){
  //variavel de qual é a tarefa q vai ser alterada
  int pos;
  int verifica =-1;
  //variavel de qual criterio da terefa vai mudar
  int criterio;
  
  printf("Qual tarefa desja alretar");
  scanf("%d",&pos);
  for(int i = 0; i < lt->qtd; i++){
    if(pos-1==i){
      printf("Qual criterio deseja alterar?\n");
      printf("1-Categoria\n");
      printf("2-Prioridade\n");
      printf("3-Estado\n");
      printf("4-Descricao\n");
      printf("Digite o numero:");
      scanf("%d",&criterio);
      switch(criterio){
        case 1:
          printf("Digite a nova categoria:");
          scanf("%s",lt->tarefas[i].categoria);
          break;
        case 2:
          printf("Digite a nova prioridade:");
          scanf("%d",&lt->tarefas[i].prioridade);
          break;
        case 3:
          printf("Digite o novo estado:");
          scanf("%s",lt->tarefas[i].estado);
          break;
        case 4:
          printf("Digite a nova descricao:");
          scanf("%s",lt->tarefas[i].descricao);
          break;
        default:
          printf("Opcao invalida");
        }
      }     
    }if(verifica == -1){
    printf("Tarefa nao encontrada");
  }
}
  
  
  
