#ifndef _UTIL_H
#define _UTIL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "./lista.h"

#define ERR_MALLOC "Não foi possível alocar memória."


void exibe_menu(Node **);
void digita_dado(char *, char *, int);
void exibe_opcoes(bool *);
bool mallocou(void *);
void alerta_erro(char *);
void aguarda_input(char *);
char * strcxalta(const char *);
void free_nodes(Node **);

#endif