#include <stdio.h>
 
struct stack{
    int pilha[6];
    int cabeca;
};
typedef struct stack STK;
STK s;
 
void empilhar(void);
int  desempilhar(void);
void imprimir(void);
 
void main ()
{
    int choice;
    s.cabeca = -1;
    do{
        printf ("1- para empilhar\n");
        printf ("2- para desempilhar\n");
        printf ("3 para exibir\n");
        printf ("4 para terminar\n");
        scanf    ("%d", &choice);
       
        switch (choice){
        case 1:
            empilhar();
            break;
        case 2:
            desempilhar();
            break;
        case 3:
            imprimir();
            break;
        }
fflush(stdin);
        scanf    ("%d", &choice);
       
    }
    while(choice != 4);
        return;
   
}
void imprimir (){
    int i;
    if (s.cabeca == -1){
        printf ("Vazia\n");
       
    }
    else{
        printf ("Elementos na pilha: \n");
        for (i = s.cabeca; i >= 0; i--){
            printf ("%d\n", s.pilha[i]);
        }
    }
}
void empilhar (){
    int num;
    if (s.cabeca == (6 - 1)){
        printf ("Cheia\n");
       
    }
    else{
        printf ("Insira o numero: \n");
        scanf ("%d", &num);
        s.cabeca = s.cabeca + 1;
        s.pilha[s.cabeca] = num;
    }
   
}int desempilhar (){
    int num;
    if (s.cabeca == - 1){
        printf ("vazia\n");
        return (s.cabeca);
    }
    else{
        num = s.pilha[s.cabeca];
        printf ("Elemento retirado");
        s.cabeca = s.cabeca - 1;
    }
    return(num);
   
}
