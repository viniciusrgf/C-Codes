#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *xp, int *yp)                         //Função que faz a troca, ou o SWAP
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 

int main(){
	    
    int a, b;                                             //Define inteiros (a== comparação ; b == tamanho do array)
    printf("Quantidade de números no array: ");
    scanf("%d", &b);
    int V[b];                                            //Cria o array de tamanho [b]
    
    clock_t start = clock();                            //Inicia o relógio
    
    for(a=0; a<b; a++){                               //Loop pra criar um número aleatório para cada posição                       
	                                                 //
	    V[a] = rand()%b;                             //
    }
	
	int j, min;                                    //mais um coparador e o "minimo"
  
    
    for (a = 0; a < b; a++)           
    { 
     
        min = a; 
        for (j = a+1; j < b; j++){ 
          if (V[j] < V[min]){ 
            min = j; 
          }
        }
        swap(&V[min], &V[a]); 
    } 
	
    for (a=0; a<b; a++){
        
        printf("%d""/",V[a]);                          //Printar todos os elementos
    }
    
    clock_t stop = clock();                                             //Para o relógio
    double elapsed = (double)(stop - start) * 1000.0 / CLOCKS_PER_SEC;   //Salva o tempo     
    printf("\n Tempo de execução: %f", elapsed);                         //Printa o tempo
}