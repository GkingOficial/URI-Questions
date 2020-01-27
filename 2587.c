/*
Entrada
A primeira linha contém um inteiro C representando a quantidade de casos de teste. Cada caso de teste possui três palavras, sendo as duas primeiras, as palavras que
Pasqualito está em dúvida, e a terceira é a palavra incompleta. As palavras têm, no máximo, 15 letras.

Saída
Para cada caso de teste, imprima Y se for possível resolver a dúvida, ou N se não for possível.
*/


/* Para este problema, além da utilização de bibliotecas (padrão na maioria dos projetos na linguagem C), utilizei os conceitos de variáveis, vetores, laços de
repetição, e estruturas condicionais, funções, além de uma função para comparar caracteres de duas strings.*/

// Inclusão das bibliotecas'stdio' e 'string'.
#include <stdio.h>
#include <string.h>

// Protótipo das funções Compare: responsável por comparar duas strings.
char Compare(char str1[], char str2[], int arr[]);

// Ínicio da função principal 'main'.
int main (){
	// cases = casos de teste; i, j e k = contadores; aux = receberá as posições da string que possuem o caracter '_'.
	int cases, i, j, k = 0, aux[3];
	// word1 e word2 = receberá as palavras que Pasqualito está em dúvida; displayed_word = receberá a palavra exibida no telão.
	char word1[16], word2[16], displayed_word[16];
	
	// Leitura de 'cases'.
	scanf("%d", &cases);
	
	// Laço de repetição, executará 'cases' vezes.
	for(i = 0; i < cases; i++){
		// Leitura de 'word1', 'word2' e 'displayed_word'.
		scanf(" %s %s %s", word1, word2, displayed_word);
		
		// Varrerá 'displayed_word' por completo.
		for(j = 0; j < strlen(displayed_word); j++){
			// Se o carater for sendo lido '_' (underline), então...
			if(displayed_word[j] == '_'){
				// Guardo a posição do caracter, em 'aux'
				aux[k] = j;
				// Incremento k, para a próxima leitura.
				k++;
			}
		}
		// "Printo" 'Y' caso seja possível resolver a dúvida, e 'N' caso contrário.
		printf("%c\n", Compare(word1, word2, aux));
		// Zero 'k' para a próxima leitura.
		k = 0;
	}
}

// Funçaõ Compare. str1 = string a ser comparada; str2 = string a ser comparada; arr = vetor contendo as posições dos caracteres a serem comparados.
char Compare(char str1[], char str2[], int arr[]){
	/* Se o primeiro caracter a ser comparado de 'string1' for igual ao segundo caracter a ser comparado de 'string2', ou, se o segundo caracter a ser comparado
	de 'string1' for igual ao primeiro caracter a ser comparado de 'string2'. Então...*/
	if(str1[arr[0]] == str2[arr[1]] || str1[arr[1]] == str2[arr[0]]){
		// Retornará 'Y'.
		return 'Y';
	}
	// Retornará 'N' caso a condição (descrita nas linhas 55 e 56) não seja atentida.
	return 'N';
}
