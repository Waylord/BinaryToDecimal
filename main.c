#include <stdio.h>
#include <math.h>

#define TAM_MANTISSA 52

int main() {
	double input;
	printf("Digite um valor: ");
	scanf("%lf", &input);

	//criando valor inteiro e atribuindo valores apos a virgula em outra variavel
	int num = (int)input;
	double resto = input - num;

	// vetor de MAX posições para guardar o número em binário

	int vet_aux[TAM_MANTISSA], vet_bin[TAM_MANTISSA], vet_resto[TAM_MANTISSA];

	// variáveis de controle de loop
	int i = 0;
	double aux_num = num;

	while (num > 0) {
		vet_aux[i] = (int)num % 2;
		i++;
		num = num / 2;
	}

	printf("%lf em binario: ", aux_num);

	for (int j = i - 1, k = 0; j >= 0; j--, k++) {
		vet_bin[k] = vet_aux[j];
	}

	int a = 0;
	while (resto != 1 && resto != 0) {
		resto *= 2;
    (resto >= 1) ? (vet_resto[a] = 1, resto -= 1) : (vet_resto[a] = 0);
    a++;	
	}

  for(int x = 0; x < i; x++) {
    printf("%d", vet_bin[x]);
  }

  printf(",");

  for(int x = 0; x < a; x++) {
    printf("%d", vet_resto[x]);
  }

  printf("\n");

  //De binário para decimal
  double binToDec = 0;
  for(int x = 0; x < i; x++) {
    if(vet_aux[x] == 1){
      binToDec += pow(2.0, x);
    }
  }
  for(int x = 0; x < a; x++) {
    if(vet_resto[x] == 1){
      binToDec += pow(2.0, -(x+1));
    }
  }

  for(int x = 0; x < i; x++) {
    printf("%d", vet_bin[x]);
  }

  printf(",");

  for(int x = 0; x < a; x++) {
    printf("%d", vet_resto[x]);
  }
  
  printf(" em decimal: %lf", binToDec);

	return 0;
}