// Inclusão das bibliotecas'stdio' e 'string'.
#include <stdio.h>
#include <string.h>

// Definição de um tipo 'list' (linha 9), sendo este um 'struct' (estrutura de dados heterogêneas).
typedef struct{
	// name = armazenará os nomes das crianças.
	char name[81];
} list;

// Protótipo da função Order: responsável pela ordenação de 'list'.
void Order(list *kids, int amount);

// Ínicio da função principal 'main'.
void main(){
	// i e j = contadores;
	int i = 0, j;
	// kids = vetor de 'list' (kids --> list --> struc);
	list kids[1001];
	
	// Laço de repetição, realiza a leitura dos nomes das crianças, executará até receber EOF (End Of File). 
	while(scanf(" %[^\n]s", kids[i].name) != EOF){
		// Incremetno o contador para receber o próximo nome.
		i++;
	}
	// Chamo a função Order, passando para ela os parâmetros 'kids' (lista com todos os nomes lidos) e 'i' (quantidade de nomes lidos).
	Order(kids, i);
	
	// "Printo" o nome da última criança da lista já ordenada.
	printf("%s\n", kids[i - 1].name);
}

// Funçaõ Order. *kids = ponteiro para o ínicio de 'list'; amount = quantidade de elementos em 'list'.
void Order(list *kids, int amount){
	// i e j = contadores;
	int i = 1, j;
	
	// aux = variável do tipo 'list';
	list aux;
	
	// Laço de repetição, executará tantas vezes quanto a quantidade de elementos em ('list' - 1), para que possa ordenar 'list' sem ultrapassar seus limites.
	while (i < amount){
		// aux recebe o elemento de 'list' na posição i.
		aux = kids[i];
		
		// j recebe o índice do elemento de 'list', anterior ao elemento na posição 'i'.
		j = i - 1;
		
		// Laço de repetição, varrerá 'kids', comparando os nomes por meio da função 'strcasecmp' que desconsidera a diferença entre as letras maiúsculas e minúsculas.
		while (j >= 0 && strcasecmp(kids[j].name, aux.name) > 0){
			// Pego o elemento de 'kids' na posição j + 1, e igua-lo ao elemento na posição j.
			kids[j + 1] = kids[j];
			// Decremetno j, para a próxima leitura.
			j--;
		}
		// 'kids' na posição j + 1 recebe o 'aux' (contendo o elemento da posição i).
		kids[j + 1] = aux;
		
		//Incremento 'i', para a próxima leitura.
		i++;
	}
}

/* Para este problema, além da utilização de bibliotecas (padrão na maioria dos projetos na linguagem C), utilizei os conceitos de variáveis, vetores, laços de repetição, e estruturas condicionais,
funções, estrutura heterogênea de dados, e, uma função para ordenar um vetor em ordem alfabética.*/
