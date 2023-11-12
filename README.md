# Lista_Tarefas.2

O projeto de lista de tarefas armazena as informações de cada tarefa por um struct e a lista onde estão essas tarefas é um array onde cada indice é uma tarefa, isso juto com uma variavel que serve pra contar o numero de tarefas está dentro de outro struct. Na struct de tarefa tem as variaveis de prioridade(int), categoria(char), estado(char) e descrição(char).

Na main.c primeiramente cria uma variavel pra armazer a struct lista de tarefas, depois checa se existe o arquivo para obter informações salvas, se existir, ele transfere para a variavel, em seguida o programa chama o função printMenu onde mostra as opçõesde operações que o usuario pode fazer

Operações:

1 - criarTarefa: O usuario coloca todas as informações falada acima, onde todas seram armazenadas no array (tarefas) adiciona 1 ao contador(qtd).
 
2 - deletarTarefa: O usuario escolhe qual tarfa ele quer deletar usando o numero fornecido na opção 3 como referencia e decrementa 1 do contador(qtd), as informações do proximo indice são passadas para o atual, isso se repete pros indices seguintes.

3 - listarTarefas: O programa passa por tarefas(array) de acordo com o contador, imprime todas as informações de cada tarefa e enumera elas de acordo com a posição delas no array.

4 - alterarTarefa: Pede ao usuario qual tarefa ele quer alterar, se encontrar no array, o programa pergunta qual das variaveis da tarefa ele quer mudar e então o usuario altera a tarefa .

5 - filtrarTarefas: Cria uma outra vatiavel pra lista de tarefas, só que com nome filtradas, o programa pergunta para o usuario qual é o criterio de filtro(prioridade, estado, categoria ou categoria e prioridade), passa pelo array de tarefaz totais e se forem condizentes com o filtro, adiciona a lista filtrada, e depois que termina de passar pela lista inteira chama a operação listarTarefas com a lista de tarefas filtradas como parametro.

6 - exportarTarefas: O programa abre o arquivo para escrever, pede ao usuario qual vai ser o filtro(prioridade, categoria ou categoria e prioridade) de quais tarefas vai ir para o arquivo, passando por todas as tarefas do array e imprime as que tiverem de acordo com o filtro por cada linha.
