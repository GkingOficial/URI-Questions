/*
Entrada
O primeiro valor a ser lido é um inteiro C, indicando o número de casos de teste. Cada caso de teste inicia com um inteiro N, informando quantas utilizações foram
feitas. Considere que antes ele não possuía nada, que um Chirrion só terá efeito se ele possuir tal coisa dita, e que um Chirrin só terá efeito se ele ainda não
possuir tal coisa, ou seja, não tem como ele possuir dois exemplares de uma mesma coisa.

Saída
Para cada caso de teste, imprima a palavra TOTAL, seguida da relação de coisas que Tausfo tem, em ordem alfabética.
*/


/* Para este problema, além da utilização de bibliotecas (padrão na maioria dos projetos na linguagem C), utilizei os conceitos de variáveis, vetores, laços de
repetição, e estruturas condicionais, funções, estrutura heterogênea de dados, e, uma função para ordenar um vetor em ordem alfabética juntamente com uma função que
busca um determinado elemento em um vetor.*/

// Inclusão das bibliotecas'stdio' e 'string'.
#include <stdio.h>
#include <string.h>

// Definição de um tipo 'string' (linha 23), sendo este um 'struct' (estrutura de dados heterogêneas).
typedef struct{
	// item = armazenará os objetos pedidos.
	char item[150];
} string;

// Protótipo das funções Find: responsável por verificar se um elemento pertence à 'string' e Order: responsável pela ordenação de 'string'.
int Find(string arr[], char str[], int size);
void Order(string vet[], int size);

// Ínicio da função principal 'main'.
int main (){
	// case = casos de teste; uses = vezes que utilizou o Chirrin Chirrion;
	int cases, uses, aux, i, j, result;
	// word = palavra dita na utilização; thing = objeto pedido;
	char word[10], thing[20];
	
	// Leitura de cases.
	scanf("%d", &cases);
	
	// Laço de repetição, executará 'cases' vezes.
	while(cases--){
		// Leitura de uses.
		scanf("%d", &uses);
		// Zero 'i' para utilizar posteriormente em Find (linha).
		i = 0;
		// Guardo o valor de 'uses' em 'aux'.
		aux = uses;
		
		// Crio um vetor --> string --> struct para armazenar os itens pedidos.
		string things[aux];
		
		// Laço de repetição, executará 'uses' vezes.
		while(uses--){
			// Recebo o que foi pedido e a palavra dita na utilização;
			scanf(" %s %s", thing, word);
			
			// Se a palavra digitada foi "chirrin", então...
			if (!strcmp(word, "chirrin")){	
				// chama a função Find que verifica se o objeto pedido já existe na struct.
				if (Find(things, thing, i) == -1){
					// Se não existir, insere no ínicio da struct;
					strcpy(things[i++].item, thing);
				}
				
			// Se a palavra digitada não foi "chirrin", logo, só poderá ter sido chirrion", então...
			} else if (!strcmp(word, "chirrion")) {
				// chama a função Find que verifica se o objeto pedido já existe na struct, caso exista, 'resul' receberá -1.
				result = Find(things, thing, i);
				if(result != -1){
					// Se resul for difere de -1, significa que a palavra digitada pertence à 'string' e insere na struct uma string qualquer;
					strcpy(things[result].item, "-----------------");
				}
			}
			
			// Limpando a struct na posição do item, para a proxima leitura;
			memset(thing, 0, sizeof(thing));
		}
		// Chama a função Order, que ordena os itens por ordem alfabética;
		Order(things, i); 
		
		printf("TOTAL\n");
		// Laço que varrerá 'things'
		for (j = 0; j < i; j++){
			// Verifico se o item de 'thing' não é a string qualquer ("-----------------", adicionada na linha 71).
			if (strcmp(things[j].item, "-----------------")){
				// "Printo" os elementos do struct.
				printf("%s\n", things[j].item);
			}
		}	
	}
}

// Funçaõ Find. arr = vetor de 'string'; str = elemento a ser verificado; size = quantidade de elementos lidos.
int Find(string arr[], char str[], int size){
	// i = contador;
	int i;
	
	//Verifica se o item já existe no struct, e retorna 1, caso contrário, retorna -1. Basicamene, altera o conteúdo contido na posição i;
	for (i = size - 1; i >= 0; i--){
		if (strcmp(arr[i].item, str) == 0){
			return i;
		}
	}
	return -1;	
}

// Funçaõ Order. arr = vetor do tipo 'string'; size = quantidade de elementos de 'string'.
void Order(string arr[], int amount){
	// i e j = contadores; position = guarda a posição de um determinado elemento de 'string';
	int i, j, position;
	
	// aux = variável auxiliar, do tipo 'string'.
	string aux;
	
	// Laço de repetição. "Varrerá" 'string'.
	for (i = 0; i < amount - 1; i++){
		// Salva a posição do menor elemento em relação ao i;
		position = i;
		
		// Verifica os elementos por ordem alfabetica.
		for (j = i + 1; j < amount; j++){
			if (strcmp(arr[j].item, arr[position].item) < 0){
				position = j;
			}
		}
		
		// Organiza os elementos de acordo com a verificação realizada pelo 'for' anterior (linha 121).
		aux = arr[position];
		arr[position] = arr[i];
		arr[i] = aux;
	}
}
