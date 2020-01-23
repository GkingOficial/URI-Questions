#include <stdio.h>
#include <string.h>

typedef struct{
	char item[150];
} string;

int Find(string vet[], char str[], short);
void Order(string vet[], short tam);

void main ()
{

	int casos, utilizacoes, aux, i, k, resultado;
	char comando[10], objeto[20];


	scanf("%hu", &casos);

	while (casos--)
	{

		scanf("%hu", &utilizacoes);

		aux = utilizacoes;
		string objetos[aux];

		i = 0;
		while(utilizacoes--)
		{

			scanf(" %s %s", objeto, comando);

			if (strcmp(comando, "chirrin") == 0)
			{	
				// Caso o comando seja "chirrin"
				// Procura na struct se o objeto j� existe dentro dela;
				// Uma vez que esse comando s� funciona caso Tausfo ainda n�o tenha o objeto;
				// Se n�o existir, o coloca na posi��o atual e incrementa o 'i';
				if (procuraCoisa(objetos, objeto, i) == -1)
					strcpy(objetos[i++].coisa, objeto);
	
			}
			// Se o comando for "chirrion"
			// Quer dizer que n�o quero mais esse objeto;
			// O procuro no struct para ver se o tenho;
			// Caso o tenha, substituo a string da posi��o do objeto por uma string qualquer "aaaaaaa";
			else if (strcmp(comando, "chirrion") == 0)
			{

				resultado = procuraCoisa(objetos, objeto, i);
				if(resultado != -1)
					strcpy(objetos[resultado].coisa, "aaaaaaa");
				
			}

			// Reseta a struct para a proxima itera��o;
			memset(objeto, 0, sizeof(objeto));
		}

		ordena(objetos, i); // Ordena��a por ordem alfab�tica;

		printf("TOTAL\n");
		// Impress�o final dos elementos do struct
		// A posi��o que contiver a string "aaaaaaa" n�o ser� impressa;
		for (k = 0; k < i; k++)
			if (strcmp(objetos[k].coisa, "aaaaaaa") != 0)
				printf("%s\n", objetos[k].coisa);

	}

}

short procuraCoisa(string vet[], char str[], short tam)
{

	short i;

	// Caso encontre um exemploar da string 'comando' dentro do struct, retorna o �ndice
	// Dessa forma, conte�do contido nessa posi��o pode ser alterado;
	// Se n�o encontrar repeti��o retorna -1;
	for (i = tam - 1; i >= 0; i--)
		if (strcmp(vet[i].coisa, str) == 0)
			return i;

	return -1;

}

void ordena(string vet[], short tam)
{

	short i, j, posicaoMenor;
	string temp;

	for (i = 0; i < tam - 1; i++)
	{
		posicaoMenor = i;

		// Salva a posi��o do menor elemento em rela��o ao i e o coloca em seu lugar;
		for (j = i + 1; j < tam; j++)
			if (strcmp(vet[j].coisa, vet[posicaoMenor].coisa) < 0)
				posicaoMenor = j;

		temp = vet[posicaoMenor];
		vet[posicaoMenor] = vet[i];
		vet[i] = temp;

	}

}
