#include <stdio.h>

int main(void) {
  
  //imprime cabecalho do jogo
  printf("********************************\n");
  printf("Bem vindo ao jogo de adivinha��o\n");
  printf("********************************\n");
  
  int numerosecreto=42;
  int chute;
  int acertou=(chute==numerosecreto);
  
  printf("Qual � o seu chute? ");
  scanf("%d", &chute);
  printf("Seu chute foi: %d \n", chute);

  if(acertou){
    printf("Parab�ns, voc� ganhou!!\n");
  }
  else {
    int maior = chute>numerosecreto;
    if(maior){
      printf("N�o foi dessa vez :( \n");
      printf("Dica: seu n�mero � maior do que o secreto\n");
      }
    else {
      printf("N�o foi dessa vez :( \n");
      printf("Dica: seu n�mero � menor do que o secreto\n");
    }
    }
}
