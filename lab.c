
#include "lab.h"
#include <stdio.h>
#include <string.h>

void printMenu(){
#include "lab.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void printMenu(){
  printf("Menu: \n");
  printf("0: Sair\n");
  printf("1. Criar Tarefa\n");
  printf("2. Deletar Tarefa(confira o numero na lista(opcao 3))\n");
  printf("3. Listar Tarefas:\n");
  printf("4. Alterar Tarefa\n");
  printf("5. Filtrar\n");
  printf("6. Exportar tarefas\n");

  
  
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
  printf("'Completo'\n");
  printf("'Em_andamento'\n");
  printf("'Não_iniciado'\n");
  scanf("%s", lt->tarefas[lt->qtd].estado);
  
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


int listarTarefas(ListadeTarefas *lt){
  //passa por todas as tarefas
    for(int i = 0; i < lt->qtd;i++){
      //imprime a lista de tarefas cada linha uma informação
        printf("Tarefa %d\n",i+1);
        printf("Categaria: %s \n",lt->tarefas[i].categoria);
        printf("Prioridade: %d \n",lt->tarefas[i].prioridade);
        printf("Estado: %s \n",lt->tarefas[i].estado);
        printf("Descricao: %s \n",lt->tarefas[i].descricao);
        printf("\n");
    }

    return 0;}

int filtrarTarefas(ListadeTarefas *lt){
  // criando ltfiltro para receber as tarefas filtradas
  ListadeTarefas *ltfiltro = malloc(sizeof(ListadeTarefas));
  int c = 0;
  //seleção de qual tipo de filtro
  printf("Digite a opção desejada: \n");
  printf("1 - Filtrar por prioridade\n");
  printf("2 - Filtrar por estado\n");
  printf("3 - Filtrar por categoria\n");
  printf("4 - Filtrar por categori e prioridade\n");
  scanf("%d",&c);
  
  switch(c){
    case 0:
      //imprime a lista normal
      listarTarefas(lt);
      break;
    case 1:
      printf("");
      int prio;
      
      printf("Qual a prioridade?\n");
      scanf("%d",&prio);
      for(int i = 0; i < lt->qtd;i++){
        //se a prioridade for igual a requerida, pega as informações da struct original e passa para a filtrada 
        if(lt->tarefas[i].prioridade == prio){
          ltfiltro->tarefas[ltfiltro->qtd] = lt->tarefas[i];
          ltfiltro->qtd++;
        }
      }
      //chamando a função de listar tarefas mas só no struck das filtradas
      listarTarefas(ltfiltro);
      break;
    case 2:
      printf("");
      char est[13];
      printf("'Completo'/ 'Em_andamento' / 'Não_iniciado' \n");
      scanf("%s",est);
      for(int i=0;i<lt->qtd;i++){
        //O mesmo da opçãoa anterior só que para o estado da tarefa
        if(strcmp(lt->tarefas[i].estado,est) == 0){
          ltfiltro->tarefas[ltfiltro->qtd] = lt->tarefas[i];
          ltfiltro->qtd++;
        }
      }
      listarTarefas(ltfiltro);
      break;
    case 3:
      printf("");
      char cat[100];
      
      printf("Digite a categoria: \n");
      scanf("%s",cat);
      // mesma coisa da opção anterior só que para a categoria e a ordem de maior prioridade para menor
      for(int p=10;p>=0;p--){
        for(int i=0;i<lt->qtd;i++){
          if((strcmp(lt->tarefas[i].categoria,cat) == 0)){
            if(lt->tarefas[i].prioridade == p){
              ltfiltro->tarefas[ltfiltro->qtd] = lt->tarefas[i];
              ltfiltro->qtd++;
            }
          }
        }
      }
      listarTarefas(ltfiltro);
      break;
    case 4:
      printf("");
      printf("Digite a categoria: \n");
      scanf("%s",cat);
      printf("Qual a prioridade?\n");
      scanf("%d",&prio);
      for(int i=0;i<lt->qtd;i++){
        //A mesma coisa só q usando o criterio de prioridade e categoria como filtro
        if((strcmp(lt->tarefas[i].categoria,cat) == 0)&&(lt->tarefas[i].prioridade==prio)){
          ltfiltro->tarefas[ltfiltro->qtd] = lt->tarefas[i];
          ltfiltro->qtd++;
        }
      }
      listarTarefas(ltfiltro);
      break;
    
    default:
      break;
  }
  return 0;
}

int exportarTarefas(ListadeTarefas *lt, char nome_txt[]){
  //criando o arquivo e abrindo
  FILE *f= fopen(nome_txt,"w");
  int opcao;
  //selecionar opção
  printf("Escolha o tipo de exportação: \n");
  printf("1-Por prioridade\n");
  printf("2-Por categoria\n");
  printf("3-Prioridade e categoria\n");
  scanf("%d", &opcao);
  switch(opcao){
    case 0:
    printf("Opção inexistente");
      
    break;
    case 1:
      printf("");
      int prio;
      printf("Qual a prioridade?");
      scanf("%d",&prio);
      for(int i = 0; i < lt->qtd;i++){
        //Checa a prioridade
        if(lt->tarefas[i].prioridade == prio){
          //passa todas as informações da tarefa condizente em uma linhas do arquivo
          fprintf(f,"Prioridade: %d; Categoria: %s; Estado: %s; Descrição: %s;\n", lt->tarefas[i].prioridade, lt->tarefas[i].categoria, lt->tarefas[i].estado, lt->tarefas[i].descricao);
        
        }
      } 
      
      break;
    case 2:
      printf("");
      char cat[13];
      printf("Digite a categoria: \n");
      scanf("%s",cat);
      
      for(int p=10;p>=0;p--){
        for(int i=0;i<lt->qtd;i++){
          if((strcmp(lt->tarefas[i].categoria,cat) == 0)&&(lt->tarefas[i].prioridade==p)){
            
            fprintf(f,"Prioridade: %d; Categoria: %s; Estado: %s; Descrição: %s;\n", lt->tarefas[i].prioridade, lt->tarefas[i].categoria, lt->tarefas[i].estado, lt->tarefas[i].descricao);
          }
        }
      }
      
      break;
    case 3:
      printf("Digite a prioridade:\n");
      scanf("%d",&prio);
      printf("Digite a categoria:\n");
      scanf("%s",cat);
      for(int i=0;i<lt->qtd;i++){
        if((strcmp(lt->tarefas[i].categoria,cat) == 0)&&(lt->tarefas[i].prioridade==prio)){
          fprintf(f,"Prioridade: %d; Categoria: %s; Estado: %s; Descrição: %s;\n", lt->tarefas[i].prioridade, lt->tarefas[i].categoria, lt->tarefas[i].estado, lt->tarefas[i].descricao);
        }
      }
        
      break;
    default:
      ;
      break;
    
  }
  fclose(f);
}

int salvarLista(ListadeTarefas *lt, char nome[]){
    FILE *f = fopen(nome, "wb");

    fwrite(lt, sizeof(ListadeTarefas),1,f);
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
  
  
  
