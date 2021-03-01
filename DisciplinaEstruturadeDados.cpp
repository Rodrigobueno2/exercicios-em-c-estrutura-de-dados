#include <stdio.h>
#include <conio.h>
//******************************************************************
typedef struct tipoElemento{
   int valor;
        
}TElemento;
//******************************************************************

//******************************************************************
typedef struct tipoLista{
    TElemento lista[10];
    int tamanhoLista;
                  
}TLista;
//*******************************************************************

//*******************************************************************
void inicializar(TLista *p){
     p->tamanhoLista = 0;
}
//*******************************************************************

void inserir(TLista *p){
     if(p->tamanhoLista < 10){
         printf("\n Informe valor: ");
         scanf("%d",&p->lista[p->tamanhoLista].valor);
         p->tamanhoLista++;
     }else{
         printf("\n Lista Cheia");  
     }   
     
}

void apresentar (TLista *p){
     if (p->tamanhoLista > 0){
         int i;
         for(i = 0; i<p->tamanhoLista; i++){
               printf("\n Valor: %d",p->lista[i].valor);
         }                
     }else{
          printf("\n Lista vazia!"); 
     }
}

int main(){
   TLista L; 
   
   inicializar(&L);  
    
   int opcao;
   do{
      printf("\n 1 - Inserir");
      printf("\n 2 - Apresentar");
      printf("\n 0 - Sair");  
      scanf("%d",&opcao);
      switch(opcao){
         case 1: inserir(&L);break;
         case 2: apresentar(&L);break;        
      }  
   } while(opcao != 0);
}
