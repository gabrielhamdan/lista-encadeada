#include "./util.h"
#include "lista.h"

void insere_item(Node **lista_contatos) {
    Contato *novo_contato = cria_novo_contato();

    Node *node_anterior = NULL;
    Node *node_atual = *lista_contatos;

    // Se node_atual não é NULL, então compara se s1 < s2.
    // Se node_atual->contato->sobrenome > novo_contato->sobrenome, encerra o laço, pois o novo contato deve ser inserido agora.
    while(node_atual != NULL && strcmp(node_atual->contato->sobrenome, novo_contato->sobrenome) < 0) {
        node_anterior = node_atual;
        node_atual = node_atual->proximo;
    }

    Node *novo_node = malloc(sizeof(Node)); // Malloca o novo_node.

    if(!mallocou(novo_node)) { // Se não mallocou, alerta o erro e sai da função.
        alerta_erro(ERR_MALLOC);
        free(novo_contato);
        return;
    }

    novo_node->contato = novo_contato; // Atribui novo contato.
    novo_node->proximo = node_atual; // O próximo é o atual, já que node_atual->contato->nome é MAIOR que novo_contato->nome.

    if (node_anterior == NULL) // Verifica se é o primeiro node da lista.
        *lista_contatos = novo_node; // Atribui, portanto, o novo_node ao primeiro item da lista.
    else
        node_anterior->proximo = novo_node; // Caso contrário, atribui o novo_node ao sucessor do node_anterior.
}

Contato * cria_novo_contato() {
    system("clear");

    Contato *novo_contato = malloc(sizeof(Contato));

    if(!mallocou(novo_contato)) { // Se não mallocou novo_contato, alerta o erro e encerra a execução do programa.
        alerta_erro(ERR_MALLOC);
        exit(EXIT_FAILURE);
    }

    digita_dado("Nome", novo_contato->nome, T_NOME);
    digita_dado("Sobrenome", novo_contato->sobrenome, T_SOBRENOME);
    digita_dado("CPF", novo_contato->cpf, T_CPF);
    digita_dado("E-mail", novo_contato->email, T_EMAIL);
    digita_dado("Telefone", novo_contato->telefone, T_TELEFONE);

    return novo_contato;
}

char * remove_item(Node **lista_contatos) {
    if(lista_itens(lista_contatos) == ALT_LISTA_VAZIA) // Lista itens ou informa que a lista está vazia.
        return ALT_LISTA_VAZIA;

    Node *node_atual = *lista_contatos;
    Node *node_anterior = NULL;
    Node *node_proximo = NULL;

    int index;
    printf("Digite a posição do item que deseja remover da lista: ");
    scanf("%d", &index);
    getchar(); // Consome \n do buffer do teclado.
    system("clear");

    if(index <= 0) // Valida índice >= 1.
        return ALT_INDEX_INVALIDO;

    int i = 1;
    while(i < index && node_atual != NULL) { // Itera a lista até o índice do item selecionado ou até o fim da lista (subótimo).
        node_anterior = node_atual;
        node_atual = node_atual->proximo;
        i++;
    }

    if (node_atual == NULL) // Node null indica que extrapolou a quantidade de itens.
        return ALT_INDEX_INVALIDO;
    
    if (node_anterior != NULL) // Se não é o primeiro item da lista, une próximo do anterior ao próximo do atual.
        node_anterior->proximo = node_atual->proximo;
    else
        *lista_contatos = node_atual->proximo; // Se for o primeiro item, o próximo será o primeiro (caso seja NULL, a lista estará, portanto, vazia).

    // Desaloca memória do contato e do node.
    free(node_atual->contato);
    free(node_atual);

    return "Contato removido com sucesso.";
}

void consulta_item(int i_item) {
    // Lista dados do contato.
}

char * lista_itens(Node **lista_contatos) {
    system("clear");

    if(*lista_contatos == NULL) // Se a lista estiver vazia, informa o usuário e retorna ao menu quando ENTER for pressionado.
        return ALT_LISTA_VAZIA;

    Node *node_atual = *lista_contatos;

    int i = 1;

    while(node_atual != NULL) { // Itera a lista e printa # - SOBRENOME, Nome
        printf("%d - %s, %s", i, strcxalta(node_atual->contato->sobrenome), node_atual->contato->nome);
        node_atual = node_atual->proximo;
        i++;
    }

    return ALT_AGUARDA_INPUT;
}