// Inclusão da biblioteca 'stdio' para poder utilizar as funções 'printf' e 'scanf'
#include <stdio.h> 

int main(){
	// cases = quantidade de casos a serem testados; shots = quantidade de tiros disprados; hitted = aramazenará quantas vezes KiloMan foi atingido; array_shots = armazenará a altura dos tiros;
	int cases, shots, i, j, hitted = 0, array_shots[51]; 
	
	// array_states = armazenará as ações (S - Stop; J - Jump) de KiloMan;
	char array_states[51];
	
	// Leitura de cases.
	scanf("%d", &cases);
	
	// Laço de repetição, executará 'cases' vezes.
	for(i = 0; i < cases; i++){
		// Leitura de shots.
		scanf("%d", &shots);
		
		// Laço de repetição, executará 'shots' vezes.
		for(j = 0; j < shots; j++){
			// Leitura dos valores correspondentes às alturas dos tiros.
			scanf("%d", &array_shots[j]);
		}
		// Leitura da string (vetor dos caracteres representando as ações de KiloMan).
		scanf("%s", &array_states);
		
		// Laço de repetição responsável pela verificação dos resultados, executará 'shots' vezes.
		for(j = 0; j < shots; j++){
			// Se KiloMan optou por pular...
			if(array_states[j] == 'J'){
				// Verifico se o tiro foi a uma altura superior a 2.
				if(array_shots[j] > 2){
					// KiloMan foi atingido, adiciono 1 a hitted.
					hitted++;
				}
				
			// Caso KiloMan não optou por pular, logo, optou por ficar parado. Então...
			} else {
				// Verifico se o tiro foi a uma altura inferior a 3.
				if(array_shots[j] < 3){
					// KiloMan foi atingido, adiciono 1 a hitted.
					hitted++;
				}
			}
		}
		
		// "Printo" quantas vez KiloMan foi atingido (hitted), seguido de uma quebra de linha (\n).
		printf("%d\n", hitted);
		
		// Zero a variável hitted, para a próxima leitura.
		hitted = 0;
	}
}
