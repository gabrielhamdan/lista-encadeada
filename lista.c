#include "./util.h"
#include "lista.h"

void insere_item(Node **lista_contatos) {
    Contato *novo_contato = cria_novo_contato();

    while(*lista_contatos != NULL)
        lista_contatos = &((*lista_contatos)->proximo);

    *lista_contatos = malloc(sizeof(Node));

    (*lista_contatos)->contato = novo_contato;
}

Contato* cria_novo_contato() {
    system("clear");

    Contato *novo_contato = malloc(sizeof(Contato));

    // testar malloc

    digita_dado("Nome", novo_contato->nome, T_NOME);
    // digita_dado("Sobrenome", novo_contato->sobrenome, T_SOBRENOME);
    // digita_dado("CPF", novo_contato->cpf, T_CPF);
    // digita_dado("E-mail", novo_contato->email, T_EMAIL);
    // digita_dado("Telefone", novo_contato->telefone, T_TELEFONE);

    return novo_contato;
}

void remove_item(Node **lista_contatos) {

}

void consulta_item(int i_item) {

}

void lista_itens(Node **lista_contatos) {
    system("clear");

    if(*lista_contatos == NULL) {
        printf("Lista vazia.");
        while((getchar() != '\n'));
        return;
    }

    Node *node_atual = *lista_contatos;

    int i = 1;

    while(node_atual != NULL) {
        printf("%d - %s", i, node_atual->contato->nome);
        node_atual = node_atual->proximo;
        i++;
    }

    printf("Tecle ENTER para voltar ao menu.");

    while((getchar() != '\n'));
}