#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	    
    int a, b;
    printf("Quantidade de números no array: ");
    scanf("%d", &b);
    int V[b];
    
   clock_t start = clock();                           //Inicia o relógio
    
    for(a=0; a<b; a++){
	
	    V[a] = rand()%b;                            //Gera valores aleatórios pro array de tamanho [b]
    }
	
	int j, aux;
    for(a=0;a<b;a++){
        for(j=0;j<b-1-a;j++){
            if(V[j]>V[j+1]){             //Se j >  j+1 (posição)
                aux=V[j];                //  j vira aux
                V[j]=V[j+1];           // j+1 vira  j
                V[j+1]=aux;              //auxiliar vira j+1
              
            }
        }
        
    }
    
    for (a=0; a<b; a++){
        
        printf("%d""/",V[a]);              //Printa todos os elementos
    }
    
    clock_t stop = clock();                //Para o relógio
    double elapsed = (double)(stop - start) * 1000.0 / CLOCKS_PER_SEC;          // Salva o tempo de ex
    printf("\n Tempo de execução: %f", elapsed);                                //Printa o tempo de ex
}


    /*-bubblesort não é recomendado para grandes conjuntos de dados.*/