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
    novo_node->anterior = NULL;
    novo_node->contato = NULL;
    novo_node->proximo = NULL;

    if(!mallocou(novo_node)) { // Se não mallocou, alerta o erro e sai da função.
        alerta_erro(ERR_MALLOC);
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

//void remove_item(Node **lista_contatos) {
//
//    int indice;
//    int i=1;
//
//    Node *node_atual = *lista_contatos;
//    Node *node_anterior = NULL;
//    Node *node_proximo = NULL;
//
//    printf("Indice a ser removido:\n");
//    scanf("%d", &indice);
//
//
//    
//    while(node_atual != NULL && indice != i) {
//
//        if(i>indice){
//            printf("Índice maior que lista.\n");
//            break;
//        }
//        
//        node_anterior = node_atual->anterior;
//        node_atual = node_atual->proximo;
//        node_proximo = node_atual->proximo;
//        i++;
//    }
//        node_anterior->proximo = node_atual->proximo;
//        node_proximo->anterior = node_atual->anterior;
//
//        free(node_atual->contato);
//        free(node_atual);
//}
void remove_item(Node **lista_contatos) {
    int indice;
    int i = 1;

    Node *node_atual = *lista_contatos;
    Node *node_anterior = NULL;
    Node *node_proximo = NULL;

    printf("Indice a ser removido:\n");
    scanf("%d", &indice);

    while (i < indice || node_atual == NULL) {
        node_anterior = node_atual;
        node_atual = node_atual->proximo;
        i++;
    }

    if (node_atual == NULL) {
        printf("Índice maior que o tamanho da lista.\n");
        return;
    }

    if (node_anterior == NULL) {
        *lista_contatos = node_atual->proximo;
    } else {
        node_anterior->proximo = node_atual->proximo;
    }

    if (node_atual->proximo != NULL) {
        node_proximo = node_atual->proximo;
        node_proximo->anterior = node_anterior;
    }

    free(node_atual->contato);
    free(node_atual);

    printf("Contato removido com sucesso.\n");
}


void consulta_item(int i_item) {

}

void lista_itens(Node **lista_contatos) {
    system("clear");

    if(*lista_contatos == NULL) { // Se a lista estiver vazia, informa o usuário e retorna ao menu quando ENTER for pressionado.
        aguarda_input("Lista vazia.");
        return;
    }

    Node *node_atual = *lista_contatos;

    int i = 1;

    while(node_atual != NULL) { // Itera a lista e printa # - SOBRENOME, Nome
        printf("%d - %s, %s", i, strcxalta(node_atual->contato->sobrenome), node_atual->contato->nome);
        node_atual = node_atual->proximo;
        i++;
    }

    aguarda_input("Tecle ENTER para voltar ao menu.");
}