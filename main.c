#include "./util.h"
#include "./lista.h"

int main(int argc, char **argv) {
    Node *lista_contatos = NULL;

    exibe_menu(&lista_contatos);

    return 0;
}

void exibe_menu(Node **lista_contatos) {
    bool encerra_execucao = false;
    bool eh_opcao_invalida = false;

    while(!encerra_execucao) {
        exibe_opcoes(&eh_opcao_invalida);

        int opcao;
        scanf("%d", &opcao);
        getchar();

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