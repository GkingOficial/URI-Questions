#include <stdio.h>
#include <stdlib.h>

int main(){
	int cases, shots, i, j, hitted = 0, array_shots[51];
	char array_states[51];
	
	scanf("%d", &cases);
	
	for(i = 0; i < cases; i++){
		scanf("%d", &shots);
		for(j = 0; j < shots; j++){
			scanf("%d", &array_shots[j]);
		}
		scanf("%s", &array_states);
		
		for(j = 0; j < shots; j++){
			if(array_states[j] == 'J'){
				if(array_shots[j] > 2){
					hitted++;
				}
			} else {
				if(array_shots[j] < 3){
					hitted++;
				}
			}
		}
		printf("%d\n", hitted);
		hitted = 0;
	}
}
