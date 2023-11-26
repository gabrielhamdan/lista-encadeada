#ifndef _LISTA_H
#define _LISTA_H

#include "util.h"

#define T_SOBRENOME 100
#define T_NOME 50
#define T_EMAIL 50
#define T_CPF 25
#define T_TELEFONE 25

enum Opcoes {
    INSERIR_ITEM = 1,
    REMOVER_ITEM,
    CONSULTAR_ITEM,
    LISTAR_ITENS,
    SAIR
};

typedef struct s_contato {
    char sobrenome[T_SOBRENOME];
    char nome[T_NOME];
    char email[T_EMAIL];
    char cpf[T_CPF];
    char telefone[T_TELEFONE];
} Contato;

typedef struct s_node {
    Contato *contato;
    struct s_node *anterior;
    struct s_node *proximo;
} Node;

void exibe_menu(Node **);
void insere_item(Node **);
Contato * cria_novo_contato();
void remove_item(Node **);
void consulta_item(int);
void lista_itens(Node **);

#endif