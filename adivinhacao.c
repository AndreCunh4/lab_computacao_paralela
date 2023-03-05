#include <stdio.h>

int main(void) {
  
  //imprime cabecalho do jogo
  printf("********************************\n");
  printf("Bem vindo ao jogo de adivinhação\n");
  printf("********************************\n");
  
  int numerosecreto=42;
  int chute;
  int acertou=(chute==numerosecreto);
  
  printf("Qual é o seu chute? ");
  scanf("%d", &chute);
  printf("Seu chute foi: %d \n", chute);

  if(acertou){
    printf("Parabéns, você ganhou!!\n");
  }
  else {
    int maior = chute>numerosecreto;
    if(maior){
      printf("Não foi dessa vez :( \n");
      printf("Dica: seu número é maior do que o secreto\n");
      }
    else {
      printf("Não foi dessa vez :( \n");
      printf("Dica: seu número é menor do que o secreto\n");
    }
    }
}
