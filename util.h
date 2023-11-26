#ifndef _UTIL_H
#define _UTIL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "./lista.h"

void exibe_menu(Node **);
void digita_dado(char *, char *, int);
void exibe_opcoes(bool *);
bool mallocou(Node *);

#endif