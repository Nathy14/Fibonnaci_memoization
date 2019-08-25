#include <stdio.h>

int contador = 0;
int contador2 = 0;

int fibo_recursivo(int valor){
  contador ++;
  if(valor == 0)
    return 0;
  else if(valor == 1 || valor == 2)
    return 1;
  else
    return fibo_recursivo(valor-1) + fibo_recursivo(valor-2);
}
void preencher(int tam, long long int *vet){
  for(int i = 0; i < tam; i++)  
    vet[i] = -1;
}
int fibo_memoization(long long int valor,long long int *vet){
  contador2++;
  if(valor == 0){
    vet[0] = 0;
    return 0;
  }
  else if(valor == 1 || valor == 2){
    vet[1] = 1;
    vet[2] = 1;
    return 1;
  }
  else if (vet[valor] == -1){
    long long int fibo =  fibo_memoization(valor-1,vet) + fibo_memoization(valor-2,vet);
    vet[valor] = fibo;
    return fibo;
  }
}
int main() {
  printf("\n Digite o valor de Fibonacci a ser calculado: ");
  int valor;
  scanf("%d", &valor);
  long long int vetorzinho[valor];
  preencher(valor,vetorzinho);
  printf("\nResultado recursivo: %d \n", fibo_recursivo(valor));
  printf("Número de chamadas da função: %d \n", contador);
  printf("Resultado memoization: %d \n", fibo_memoization(valor,vetorzinho));
  printf("Número de chamadas da função: %d \n", contador2);
return 0;
}
