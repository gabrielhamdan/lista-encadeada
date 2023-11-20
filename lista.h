#ifndef _LISTA_H
#define _LISTA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

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

typedef struct {
    char sobrenome[T_SOBRENOME];
    char nome[T_NOME];
    char email[T_EMAIL];
    char cpf[T_CPF];
    char telefone[T_TELEFONE];
} Contato;

typedef struct Node {
    Contato contato;
    struct Node *anterior;
    struct Node *proximo;
} Node;

void inicializa_lista(Node *);
void insere_item(Node *);
void remove_item(Node *);
void consulta_item(int);
void lista_itens(Node *);

#endif