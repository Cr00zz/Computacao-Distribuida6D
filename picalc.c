#include <stdio.h>
#include <stdlib.h>


int main(int argc, char ** argv) {
 
	int i;
	double x,y,quad;
	long num_ptos = 0; /* num pontos gerados */
	long num_ptos_cir = 0; /* num pontos no circulo */
	double pi;
        int numint; /* recebe da linha de comando o num de pontos */
	numint = atoi(argv[1]);
	
	for (i = 0; i<numint; i++){
 
		/* sorteia um numero de 0 a 1 -> x */ 
		/* sorteia um numero de 0 a 1 -> y */
		quad = ((x*x) + (y*y));
		/* Se a soma dos quadrados for menor que R = 1
		   então caiu no circulo */
		if (quad <= 1){
			num_ptos_cir ++; /* conta pontos no circulo */
		}
 
		num_ptos++; /* incrementa os pontos totais; 
			       no programa serial eh igual a numint  */
 
	}
 
	/* calcula o num pi conforme algoritmo visto em sala */


	/* Unica saida do programa eh o valor de pi */
							
	printf(pi);	
	return 0;
}
