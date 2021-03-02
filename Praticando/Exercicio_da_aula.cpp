#include<stdio.h>
#include<stdlib.h>

typedef struct valor{
      int valor; 
}Tvalor;

typedef struct lista{
      Tvalor lista[10];
      int tamanhoLista;        
}Tlista;

void inicializar(Tlista *p1, Tlista *p2){
     p1->tamanhoLista = 0;
     p2->tamanhoLista = 0;
     
}

void listar(Tlista *p){
   if(p->tamanhoLista > 0){
      for(int i=0; i<p->tamanhoLista; i++){
         printf(", %d",p->lista[i].valor);
         //printf("\n");
      }
   }else{
        printf("\nNao ha valor na lista\n");
   }   
}

void inserir(Tlista *p){
   if(p->tamanhoLista >= 10){
      printf("\nLista cheia\n");
   }else{
      printf("\nDigite um valor\n");
      scanf("%d",&p->lista[p->tamanhoLista].valor);
      p->tamanhoLista ++;
   }  
}

void copial2(Tlista *p1, Tlista *p2){
     if(p1->tamanhoLista == p2->tamanhoLista){
        printf("\nNao ha valor em lista1 para copiar em lista2 ou nao tem o que copiar\n");
     }else{
        for(int i=0; i<p1->tamanhoLista; i++){
           p2->lista[i].valor = p1->lista[i].valor;
           //forma 1 para acrecentar + 1 no tamanho lista 2
           //if(p2->tamanhoLista < p1->tamanhoLista){
             // p2->tamanhoLista ++;
           //}
        }
        //forma 2 para acrescentar +1 no tamanho lista 2
        p2->tamanhoLista = p1->tamanhoLista;
     }   
}

bool verificaOrdenacao(Tlista *p){
    for(int i = 0; i<p->tamanhoLista;i++){
       if(p->lista[i].valor > p->lista[i+1].valor){
            return false;
       }
    }
    return true;

}


int main(){
   
   int opcao;
   Tlista l1,l2;
   bool ordenado;
   
   inicializar(&l1,&l2);
   do{
      printf("\n1 - Listar L1\n");
      printf("2 - inserir L1\n");
      printf("3 - copiar L1 em L2\n");
      printf("4 - Listar L2\n");
      printf("5 - verificar ordenacao de L1\n");
      printf("9 - sair\n");
      scanf("%d",&opcao);
      switch(opcao){
         case 1:
            listar(&l1);
         break;
         case 2:
            inserir(&l1);  
         break;
         case 3:
            copial2(&l1,&l2);
         break;
         case 4:
            listar(&l2);
         break;
         case 5:
            ordenado = verificaOrdenacao(&l1);
            if(ordenado == true){
               printf("\nEsta ordenado a lista 1\n");
            }else{
               printf("\nNao esta ordenado a lista 1\n");
            }
         break;
      }
         
   }while(opcao != 9);    
       
   return 0; 
}
