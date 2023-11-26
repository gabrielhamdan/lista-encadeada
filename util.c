#include "./util.h"
#include "./lista.h"

void exibe_opcoes(bool *eh_opcao_invalida) {
    system("clear");

    printf("##### LISTA ENCADEADA #####\n");
    printf("1 - Inserir item na lista\n");
    printf("2 - Remover item da lista\n");
    printf("3 - Consultar item da lista\n");
    printf("4 - Listar todos os itens\n");
    printf("5 - Sair\n");

    if(*eh_opcao_invalida) {
        printf("Opção inválida!\n");
        *eh_opcao_invalida = false;
    } else printf("\n");

    printf("> ");
}

void digita_dado(char *descricao, char *campo, int t_campo) {
    t_campo--;
    printf("%s: ", descricao);
    fgets(campo, t_campo, stdin);
}

bool mallocou(Node *node) {
    return node == NULL;
}