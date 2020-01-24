#include <stdio.h>
#include <string.h>

typedef struct{
	char item[150];
} string;

int Find(string arr[], char str[], int size);
void Order(string vet[], int size);

int main (){
	// case = casos de teste; uses = vezes que utilizou o Chirrin Chirrion; word = palavra dita na utilização; thing = objeto pedido;
	int cases, uses, aux, i, j, result;
	char word[10], thing[20];
	
	scanf("%d", &cases);
	while(cases--){
		scanf("%d", &uses);
		
		i = 0;
		aux = uses;
		string things[aux]; // Crio um vetor --> string --> struct para armazenar os itens pedidos.
		while(uses--){
			scanf(" %s %s", thing, word); // Recebo o que foi pedido e a palavra dita na utilização;

			if (!strcmp(word, "chirrin")){	
				// Se a palavra foi "chirrin", chama a função Find que verifica se o objeto pedido já existe na struct. Se não existir, insere no ínicio da struct;
				if (Find(things, thing, i) == -1){
					strcpy(things[i++].item, thing);
				}
			} else if (!strcmp(word, "chirrion")) {// Se a palavra foi "chirrion", chama a função Find que verifica se o objeto pedido já existe na struct. Se existir, insere na struct uma string qualquer;
				result = Find(things, thing, i);
				if(result != -1){
					strcpy(things[result].item, "-----------------");
				}
			}
			
			// Limpando a struct na posição do item, para a proxima leitura;
			memset(thing, 0, sizeof(thing));
		}

		Order(things, i); // Chama a função Order, que ordena os itens por ordem alfabética;

		printf("TOTAL\n");
		// "Printo" os elementos do struct, pulando a posição que tiver a string qualquer ("-----------------", adicionada na linha 34);
		for (j = 0; j < i; j++){
			if (strcmp(things[j].item, "-----------------")){
				printf("%s\n", things[j].item);
			}
		}	
	}
}

int Find(string arr[], char str[], int size){
	int i;
	
	//Verifica se o item já existe no struct, e retorna 1, caso contrário, retorna -1. Basicamene, altera o conteúdo contido na posição i;
	for (i = size - 1; i >= 0; i--){
		if (strcmp(arr[i].item, str) == 0){
			return i;
		}
	}
	return -1;	
}

void Order(string arr[], int amount){
	int i, j, position;
	string aux;

	for (i = 0; i < amount - 1; i++){
		position = i; // Salva a posição do menor elemento em relação ao i;
		
		// Verifica os elementos por ordem alfabetica.
		for (j = i + 1; j < amount; j++){
			if (strcmp(arr[j].item, arr[position].item) < 0){
				position = j;
			}
		}
		
		// Organiza os elementos de acordo com a verificação realizada pelo 'for' anterior.
		aux = arr[position];
		arr[position] = arr[i];
		arr[i] = aux;
	}
}
