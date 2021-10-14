#ifndef	PILHA_H
# define PILHA_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct
{
	char	letra;
}	Item;

typedef struct st_celula
{
	Item *item;
	struct st_celula *proximo;
} Celula;

typedef struct
{
	Celula	*topo;
	int		tamanho;
} Pilha;

int         compara(Pilha*, Pilha*);
Pilha       *cria();
Item        *POP(Pilha*);
int         PUSH(Item*, Pilha*);
int         exibe(Pilha*);
Pilha       *inverte(Pilha*);

#endif
