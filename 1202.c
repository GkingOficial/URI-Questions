#include <stdio.h>
#include <string.h>
#include <math.h>

int Recursion(int index);
int Bin_To_Dec(char string[]);

int main(){
	int i, row;
	char in[10000];
	scanf("%d", &row);
	for(i = 0; i < row; i++){
		scanf("%s", in);
		printf("%03d\n", Recursion(Bin_To_Dec(in)));
	}
	
}

int Recursion(int index){
	if(index == 1 || index ==2){
		return 1;
	} else {
		return (Recursion(index - 1) + Recursion(index - 2));
	}
}

int Bin_To_Dec(char string[]){
	int i, j = 0, binary = 0;
	
	for(i = strlen(string) - 1; i >= 0; i--){
		if(string[i] != '0'){
			binary += pow(2, j);	
		}
		j++;
	}
	return binary;
}
