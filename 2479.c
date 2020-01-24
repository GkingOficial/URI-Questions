#include <stdio.h>
#include <string.h>

typedef struct{
	char name[21];
} kids;

void Order(kids arr[], int size);

int main (){
	int i = 0, good_behavior = 0, bad_behavior = 0, amount, aux;
	char behavior;
	
	scanf("%d", &amount);
	aux = amount;
	kids list[amount];
	
	while (aux--){
		scanf(" %c %s", &behavior, list[i].name);
		
		if (behavior == '+'){
			good_behavior++;
		} else{
			bad_behavior++;
		}
		i++;
	}

	Order(list, amount);
	
	for (i = 0; i < amount; i++){
		printf("%s\n", list[i].name);
	}
	
	printf("Se comportaram: %d | Nao se comportaram: %d\n", good_behavior, bad_behavior);
	i = 0;
}

void Order(kids arr[], int size){
	int i = 1, j;
	kids aux;

	while(i < size){
		j = i - 1;
		aux = arr[i];

		while (strcmp(arr[j].name, aux.name) > 0 && j >= 0){
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = aux;
		i++;
	}
}
