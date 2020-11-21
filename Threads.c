#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>	
pthread_t *studante;		//thread do estudante
pthread_t TA;				//thread do TA
int CurrentIndex = 0;
sem_t Student_Sem;
pthread_mutex_t ChairAccess;

int main(int argc, char* argv[])
{
   int estudantes = atoi(argv[1]);
   studante = (pthread_t*) malloc(sizeof(pthread_t)*estudantes);//aloca memoria para os estudantes
   int id;
	srand(time(NULL));//usa a variavel aleatoria
	pthread_mutex_init(&ChairAccess, NULL);
	if(estudantes<1){// se não existem estudantes para ajudar ele volta a dormir
	    printf("TA is sleeping.");
	    printf(" \n");
	    printf("There is no more students to help. TA left the room.");
	    printf(" \n");
	    printf("TA went back to sleep.");
	    
	}
    //falta alocar memoria para o prof e pros alunos
	void *TA_Activity()

void *Student_Activity(void *threadID) 
{
	int ProgrammingTime;

	while(1)
	{
		printf("Student %l# is going to TA room.\n", (long)threadID);
		printf("Student %l# is awaking the TA.\n", (long)threadID);
	    printf("Student %l#  is getting inside TA room.\n", (long)threadID);
	     printf("TA is teaching studentStudent %l#  is getting inside TA room.\n", (long)threadID);
			sem_post(&TA_Sleep);//estudante acorda o Ta
            
		
			sem_wait(&Student_Sem);		//Student waits to go next.
			printf("Student %l# left TA room.\n",(long)threadID);
		}
		
}