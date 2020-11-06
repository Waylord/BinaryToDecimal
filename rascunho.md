#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int MAX_MANTISSA = 52;


int main(void) {
  double n_base10, n_base2;

  int ieee[64];
  bool sinal; //tratar como booleano, 1 para true e 0 para false
  int expoente;
  char mantissa[MAX_MANTISSA];
  double input;
  
  printf("Digite um valor: ");
  scanf("%lf", &input);

  (input < 0) ? (sinal = true) : (sinal = false);

  int aux[52];
  int i = 0;
  while(input > 1){
    int resto = (int) input % 2;
    input /= 2;
    aux[i] = resto;
    i++;
  }

  aux[i] = input;
  input -= 1;
  i++;

  for(int j = 0, aux2 = i; aux2 >= 0; i--, j++) {
    mantissa[j] = aux[aux2];
  }

  while(input != 1 && i < MAX_MANTISSA){
    input *= 2;
    (input > 1) ? (aux[i] = 1) : (aux[i] = 0);
    i++;
  }

  expoente = i;

  for(int cursor = 0; cursor < expoente; cursor++) {
    printf("%d", mantissa[cursor]);
  }

  return 0;
}

