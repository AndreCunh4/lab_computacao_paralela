//Andre Cunh TIA:32073801
//Pedro Augusto Lima TIA:32136374

#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <stdlib.h>

#define quant_filosofos 5 
//identificador de filosofos
#define filosofo_aguardando 0 
//identificador de filosofo_aguardando
#define filosofo_com_fome 1 
//identificador de filosofo_com_fome
#define filosofo_comendo 2 
//identificador de filosofo_comendo

sem_t sem[quant_filosofos];//inicia semaforo
sem_t mutex;
int estado [quant_filosofos];// estado em que os filosofos se encontram
int num_filosofo[quant_filosofos]= {0,1,2,3,4};// inicializa filosofos

// funções
void *fil(void *n);
void pegar_garfo(int);
void soltar_garfo(int);
void test(int);


//Função pega garfo//

void pegar_garfo(int num_filosofo)
{
  sem_wait(&mutex);
  estado[num_filosofo]= filosofo_com_fome;
  printf("Filosofo de numero %d esta com fome \n",num_filosofo+1);// print desde o 1
  test(num_filosofo);
  sem_post(&mutex);
  sem_wait(&sem[num_filosofo]);
  sleep(1);
}



//Função solta garfo//

void soltar_garfo(int num_filosofo)
{
  sem_wait(&mutex);
  estado[num_filosofo]= filosofo_aguardando;
  printf("Filosofo de numero %d terminou de comer e deixou os garfos %d e %d \n",num_filosofo+1,(num_filosofo+4)%quant_filosofos+1,num_filosofo+1);
  printf("Filosofo de numero %d agora esta aguardando\n\n",num_filosofo+1);
  test((num_filosofo+4)%quant_filosofos);
  test((num_filosofo+1)%quant_filosofos);
  sem_post(&mutex);
}




//Função fill//

void *fil(void *n)
{
  while(1)
  {
   int *i = n;
   sleep(1);
   pegar_garfo(*i);
   sleep(1);
   soltar_garfo(*i);
  }
}




//Função main//

int main()
{
  int i;
  pthread_t ident_tr[quant_filosofos];//identificador de thread
  sem_init(&mutex,0,1);
  for(i=0; i<quant_filosofos; i++)
    sem_init(&sem[i],0,0);
  for(i=0;i<quant_filosofos;i++)
  {
    pthread_create(&ident_tr[i], NULL, fil, &num_filosofo[i]);//criador de threads necessarias
    printf("Filosofo de numero %d esta aguardando.\n",i+1);//imprime filosofo que esta pensando
  }
  printf("\n");
  for(i=0;i<quant_filosofos;i++)
  {
    pthread_join(ident_tr[i],NULL);// Thread principal aguarda as outras threads
  }
  return(0);
}



//Função teste//

void test(int num_filosofo)
{
  if(estado[num_filosofo]==filosofo_com_fome&& estado[(num_filosofo+4)%quant_filosofos]!=filosofo_comendo&& estado[(num_filosofo+1)%quant_filosofos]!=filosofo_comendo)
  {
    estado[num_filosofo]=filosofo_comendo;
    sleep(1);
    printf("Filosofo de numero %d pegou os garfos %d e %d \n",num_filosofo+1,(num_filosofo+4)%quant_filosofos+1,num_filosofo+1);
    printf("Filosofo de numero %d esta comendo \n",num_filosofo+1);
    sem_post(&sem[num_filosofo]);
  }
}
