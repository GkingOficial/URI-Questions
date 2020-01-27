// Inclusão das bibliotecas'stdio' e 'string'.
#include <stdio.h>
#include <string.h>

// Definição de um tipo 'kids' (linha 9), sendo este um 'struct' (estrutura heterogênea de dados).
typedef struct{
	// name = armazenará os nomes das crianças.
	char name[21];
} kids;

// Protótipo da função Order: responsável pela ordenação de 'kids'.
void Order(kids arr[], int size);

// Ínicio da função principal 'main'.
int main(){
	// i = contador; good_behavior = número de crianças que tiveram um bom comportamento; bad_behavior = número de crianças que tiveram um mau comportamento; amount = número de crianças; aux = auxiliar;
	int i = 0, good_behavior = 0, bad_behavior = 0, amount, aux;
	// behavior = comportamento da criança;
	char behavior;
	
	// Leitura de 'amount';
	scanf("%d", &amount);
	
	// aux recebe o número de crianças, lido anteriormente (linha 23);
	aux = amount;
	// list = vetor de 'kids' (kids --> list --> struc), com tamanho igual ao número de crianças;
	kids list[amount];
	
	// Laço de repetição, executará 'aux' vezes. 
	while (aux--){
		// Leitura de 'behavior' (caracter representando o comportamento da criança), e o nome da criança.
		scanf(" %c %s", &behavior, list[i].name);
		
		// Se o caracter lido foi '+', entaõ...
		if (behavior == '+'){
			// Incremento 'good_behavior'.
			good_behavior++;
			
		// Caso o caracter lido não fio '+', logo, só poderá ter sido '-', entaõ...
		} else{
			// Incremento 'bad_behavior'.
			bad_behavior++;
		}
		// Incremento i, para que na próxima leitura, analise a próxima criança.
		i++;
	}
	
	// Chamo a função Order, passando para ela os parâmetros 'list' (lista com os nomes das crianças) e 'amount' (quantidade de crianças).
	Order(list, amount);
	
	// Laço de repetição, executará 'amount' vezes.
	for (i = 0; i < amount; i++){
		// "Printo" a lista, já ordenada.
		printf("%s\n", list[i].name);
	}
	
	// "Printo" a quantidade de crianças que se comportaram, e, a quantidade de crianças que não se comportaram.
	printf("Se comportaram: %d | Nao se comportaram: %d\n", good_behavior, bad_behavior);
}

// Funçaõ Order. arr = vetor do tipo 'kids'; size = quantidade de nomes lidos.
void Order(kids arr[], int size){
	// i e j = contadores;
	int i = 1, j;
	// aux = variável do tipo 'kids';
	kids aux;
	
	// Laço de repetição, executará tantas vezes quanto a quantidade de elementos em ('kids' - 1), para que possa ordenar 'kids' sem ultrapassar seus limites.
	while(i < size){
		// aux recebe o elemento de 'kids' na posição i.
		aux = arr[i];
		
		// j recebe o índice do elemento de 'kids', anterior ao elemento na posição 'i'.
		j = i - 1;
		
		// Laço de repetição, varrerá 'arr' (list), comparando os nomes por meio da função 'strcasecmp' que desconsidera a diferença entre as letras maiúsculas e minúsculas.
		while (strcmp(arr[j].name, aux.name) > 0 && j >= 0){
			// Pego o elemento de 'arr' (list) na posição j + 1, e igua-lo ao elemento na posição j.
			arr[j + 1] = arr[j];
			// Decremetno j, para a próxima leitura.
			j--;
		}
		// 'arr' (list) na posição j + 1 recebe o 'arr' (contendo o elemento da posição i).
		arr[j + 1] = aux;
		//Incremento 'i', para a próxima leitura.
		i++;
	}
}

/* Para este problema, além da utilização de bibliotecas (padrão na maioria dos projetos na linguagem C), utilizei os conceitos de variáveis, vetores, laços de repetição, e estruturas condicionais,
funções, estrutura heterogênea de dados, e, uma função para ordenar um vetor em ordem alfabética.*/
