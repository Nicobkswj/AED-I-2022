//Azulejos
//Alunos: Nicolas Rocha, Kauan Henrik, Igor Nunes, Lucas Rodrigues, Gabriel Azevedo & Luiz Felipe Silva.

#include <stdio.h>
#include <stdlib.h>

int main () {

	int N, verdadeiro = 1, A, B, i, contAzulPintados;
	while (verdadeiro) {
	contAzulPintados = 0;
		while (verdadeiro) {
			printf ("Digite o numero de azulejos: ");
			scanf ("%d" , &N );

			if (N < 3 || N > 10000 ){
			    if (N == 0) {
			    	break;
				}
				printf ("Numero de azulejos invalido. Tente novamente\n");

			} else {

				break;
			}
		}

		while (verdadeiro) {


			printf ("Digite o valor de A: ");
			scanf ("%d" , &A);

		    printf ("Digite o valor de B: ");
			scanf ("%d" , &B);

	       if ((A < 2 || A > N) || (B < 2 || B > N)) {
	       	if (N == 0) {
	            break;
			}
		   	printf ("Os valores de A e/ou B sao invalidos. Digite novamente \n");

		   }
		   else {

		   		break;

		   }

		}
		if (N == 0) {
			if ((A == 0) && (B == 0)) {
				printf ("Fim\nGoodbye :)");
				break;
			}
			else
			    printf ("Numero de azulejos invalido. Tente novamente\n");

		}
		else {

			for (i = 1; i <= N; i++ ) {

	        	if ((i % A == 0) || (i % B == 0)) {

	      			contAzulPintados++;
		  		}

	    	}


			printf ("Para o numero de azulejos = %d, A  = %d, B = %d \nO numero de azulejos pintado e: %d\n\n" , N , A , B , contAzulPintados );

		}



	}




}

