// Inclusão das bibliotecas'stdio', 'string' e 'math'.
#include <stdio.h>
#include <string.h>
#include <math.h>

// Protótipo das funções Recursion: responsável pelo cálculo do n-ésimo elemento da sequência dada; e Bin_To_Dec: responsável pela conversão de um número em binário para decimal.
int Recursion(int index);
int Bin_To_Dec(char string[]);

// Ínicio da função principal 'main'.
int main(){
	// i = contador; row = o n-ésimo elemento da sequência.
	int i, row;
	
	// in = descrição das fileiras, em binário, porém estarei recebendo como string (vetor de caracteres).
	char in[10000];
	
	// Leitura de 'row'
	scanf("%d", &row);
	
	// Laço de repetição, executará 'row' vezes.
	for(i = 0; i < row; i++){
		// Leitura de 'in'.
		scanf("%s", in);
		// Impressão dos três dígitos que devem estar escrito no cartão para a pessoa entrar no teatro, com 0 ocupando os valores vazios à esquerda.
		printf("%03d\n", Recursion(Bin_To_Dec(in)));
	}
}

// Função 'Recursion'. index = e-nésimo número da sequência;
int Recursion(int index){
	// Dada a sequência no enunciado do problema, a primeira e a segunda linha possuem o valor igual a 1.
	if(index == 1 || index == 2){
		return 1;
	
	// Dada a sequência no enunciado do problema, o e-nésimo número é calculado por f(n) = f(n - 1) + f(n - 2).
	} else {
		return (Recursion(index - 1) + Recursion(index - 2));
	}
}

// Função Bin_To_Dec. string = valor binário a ser convertido, em string (vetor de carateres).
int Bin_To_Dec(char string[]){
	// i e j = contadores; decimal = receberá o valor convertido;
	int i, j = 0, decimal = 0;
	
	// Laço de repetição, executará tantas vezes quanto o número de caracteres de 'string'. "Varrerá" 'string' da direita para a esquerda, ou seja, do final para o ínicio.
	for(i = strlen(string) - 1; i >= 0; i--){
		// Caso o caracter lido de 'string' seja diferente de 0, então...
		if(string[i] != '0'){
			// 'decimal' receberá 2 elevado à j (j é um contador crescente, ou seja, "andará" no sentido oposto à i.
			decimal += pow(2, j);	
		}
		// Incremento j, para a próxima leitura.
		j++;
	}
	// Retorno decimal.
	return decimal;
}
