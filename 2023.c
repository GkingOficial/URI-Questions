#include <stdio.h>
#include <string.h>

typedef struct{
	char name[100];
} list;

void Order(list*, int);

void main ()
{
	int i = 0, j;
	list kids[1100];
	
	while(scanf(" %[^\n]s", kids[i].name) != EOF){
		i++;
	}
	Order(kids, i);
	printf("%s\n", kids[i - 1].name);
}

void Order(list *kids, int amount){
	int i = 1, j;
	list aux;
	while (i < amount){
		j = i - 1;
		aux = kids[i];
		
		while (j >= 0 && strcasecmp(kids[j].name, aux.name) > 0){
			kids[j + 1] = kids[j];
			j--;
		}
		kids[j + 1] = aux;
		i++;
	}

}
