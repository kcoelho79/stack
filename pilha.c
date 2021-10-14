# include "pilha.h"

int	main(void)
{
	Pilha	*p = cria();
	Item	item;
	exibe(p);
	printf("Insere de 'A' a 'Z'\n");
    for (item.letra = 'A'; item.letra <= 'Z'; item.letra += 1) PUSH(&item, p);
	exibe(p);

	int n = p->tamanho / 2;
    printf("Desempilhando %d elementos\n", n);
    for (int i = 0; i < n; i += 1)
        printf("%c ", (POP(p))->letra);
    printf("\n");

	printf("Pilha restante\n");
    exibe(p);

	printf("Inverte a Pilha\n");
    Pilha* inv_p = inverte(p);
    exibe(inv_p);
    printf("Pilha original\n");
    exibe(p);

	printf("\n\nComparando pilhas:\n\n");
    Pilha* outra = cria();
    exibe(outra);
    exibe(inv_p);
    if (compara(inv_p, outra))
        printf("As pilhas sao iguais\n");
    else
        printf("As pilhas sao diferentes\n");
    printf("\nCarregando a pilha que estava vazia: \
Insere de 'B' a 'M'\n");
    for (item.letra = 'M'; item.letra >= 'B'; item.letra -= 1) PUSH(&item, outra);
    printf("\nCompara de novo:\n");
    exibe(outra);
    exibe(inv_p);
    if (compara(inv_p, outra))
        printf("As pilhas sao iguais\n");
    else
        printf("As pilhas sao diferentes\n");
    printf("\nInsere a letra que faltava e compara de novo:\n");
    item.letra = 'A';
    PUSH(&item, outra);
    exibe(outra);
    exibe(inv_p);
    if (compara(inv_p, outra))
        printf("As pilhas sao iguais\n");
    else
        printf("As pilhas sao diferentes\n");

		return (0);
}