#include <stdio.h>
#include <string.h>

char Compare(char str1[], char str2[], int arr[]);

int main (){
	int cases, i, j, k = 0, aux[3];
	char word1[16], word2[16], displayed_word[16];
	
	scanf("%d", &cases);
	for(i = 0; i < cases; i++){
		scanf(" %s %s %s", word1, word2, displayed_word);
		
		for(j = 0; j < strlen(displayed_word); j++){
			if(displayed_word[j] == '_'){
				aux[k] = j;
				k++;
			}
		}
		printf("%c\n", Compare(word1, word2, aux));
		k = 0;
	}
}

char Compare(char str1[], char str2[], int arr[]){
	if(str1[arr[0]] == str2[arr[1]] || str1[arr[1]] == str2[arr[0]]){
		return 'Y';
	}
	return 'N';
}
