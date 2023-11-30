#include "./util.h"
#include "./lista.h"

int main(int argc, char **argv) {
    Node *lista_contatos = NULL;

    exibe_menu(&lista_contatos);

    free_nodes(&lista_contatos);

    exit(EXIT_SUCCESS);
}

void exibe_menu(Node **lista_contatos) {
    bool encerra_execucao = false;
    bool eh_opcao_invalida = false;

    while(!encerra_execucao) {
        exibe_opcoes(&eh_opcao_invalida);

        int opcao;
        scanf("%d", &opcao);
        getchar(); // Consome \n do buffer do teclado.

        switch (opcao) // Seleciona enum
        {
            case INSERIR_ITEM:
                insere_item(lista_contatos);
                break;
            case REMOVER_ITEM:
                aguarda_input(remove_item(lista_contatos));
                break;
            case CONSULTAR_ITEM:
                consulta_item(lista_contatos);
                break;
            case LISTAR_ITENS:
                aguarda_input(lista_itens(lista_contatos));
                break;
            case SAIR:
                encerra_execucao = true;
                break;
            default: eh_opcao_invalida = true; break;
        }
    }
}