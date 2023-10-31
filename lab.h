#include <stdio.h>

typedef struct{
    int prioridade;
    char categoria[100];
    char estado[13];
    char descricao[300];

}Tarefa;
//limitar tarefas até 100
typedef struct{
    Tarefa tarefas[100];
    int qtd;
}ListadeTarefas;


int criarTarefa(ListadeTarefas *lt);
int deletarTarefa(ListadeTarefas *lt);
int listaTarefas(ListadeTarefas lt);
int alterarTarefa(ListadeTarefas *lt);

void printMenu();
int salvarLista(ListadeTarefas lt, char nome[]);
int carregarLista(ListadeTarefas *lt,char nome[]);
