#include "./lista.h"

void exibe_menu(Node *);
void exibe_opcoes(bool *);

int main(int argc, char **argv) {
    Node lista_contatos;

    inicializa_lista(&lista_contatos);

    exibe_menu(&lista_contatos);

    return 0;
}

void exibe_menu(Node *lista_contatos) {
    bool encerra_execucao = false;
    bool eh_opcao_invalida = false;

    while(!encerra_execucao) {
        exibe_opcoes(&eh_opcao_invalida);

        int opcao;
        scanf("%d", &opcao);

        switch (opcao)
        {
            case INSERIR_ITEM:
                insere_item(lista_contatos);
                break;
            case REMOVER_ITEM:
                remove_item(lista_contatos);
                break;
            case CONSULTAR_ITEM:
                consulta_item(0);
                break;
            case LISTAR_ITENS:
                lista_itens(lista_contatos);
                break;
            case SAIR:
                exit(EXIT_SUCCESS);
            default: eh_opcao_invalida = true; break;
        }
    }
}

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