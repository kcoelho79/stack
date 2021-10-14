# include "pilha.h"

Pilha	*cria()
{
	Pilha	*nova;
	
	nova = (Pilha *)malloc(sizeof(Pilha));
	nova->tamanho = 0;
	nova->topo = NULL;
	return nova;
}

int	PUSH(Item *item, Pilha *pilha)
{
	Celula	*nova;
	Item	*pItem;

	nova = (Celula *)malloc(sizeof(Celula));
	pItem = (Item *)malloc(sizeof(Item));

	*(pItem) = *item;
	nova->item = pItem;
	nova->proximo = pilha->topo;
	pilha->topo = nova;
	pilha->tamanho += 1;
	return (0);
}

Item	*POP(Pilha *pilha)
{
	Item	*valor;
	Celula	*topo;

	valor = (Item *)malloc(sizeof(Item));
	if (pilha->tamanho < 1)
		return NULL;
	*valor = *(pilha->topo->item);
	topo = pilha->topo;
	pilha->topo = pilha->topo->proximo;
	pilha->tamanho -=1;
	free(topo->item);
	free(topo);
	return valor;

}

int exibe(Pilha	*pilha)
{
	Celula	*p;

	p = pilha->topo;
	printf("Pilha tem %d elementos\n[", pilha->tamanho);
	
	while (p != NULL)
	{
		printf("'%c' ", p->item->letra);
		p = p->proximo;
	}
	printf("]\n");
	return 0;
}

Pilha* inverte(Pilha* origem)
{
	Pilha	*destino;
	Item	*item;

	item = POP(origem);
	destino = cria();
	while (item != NULL)
	{
		PUSH(item, destino);
		item = POP(origem);
	}
	return destino;
}

int	compara(Pilha	*uma, Pilha	*outra)
{
	Celula *pA;
	Celula *pB;

    if (uma->tamanho != outra->tamanho) 
		return 0;
    pA = uma->topo;
	pB = outra->topo;
    for (int i = 0; i < uma->tamanho; i += 1)
    {
        if (pA->item->letra != pB->item->letra) 
			return 0;
        pA = pA->proximo;
		pB = pB->proximo;
    }
    return 1;
}