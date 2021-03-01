#include<stdio.h>
#include<stdlib.h>

typedef struct produtos{
    int codigo;
    char nome[30];
    float preco;
    int quantidade_estoque;
}Tproduto;
   
   
typedef struct lista{
    Tproduto produto[5];
    int tamanhoLista; 
}Tlista;

void inicializa(Tlista *p){
   //
   p->tamanhoLista = 0;
   //printf("%d \n",p->tamanhoLista);
   //printf("%d \n",p);
}

void listarProduto(Tlista *p){
   int contEstoqueAcimaQuinhentos = 0;
   if(p->tamanhoLista == 0){
      printf("Lista esta vazia\n");
   }else{
      for(int i=0; i<p->tamanhoLista; i++){
          printf("_______produto %d _______\n",i+1);
          printf("Codigo do produto: %d \n",p->produto[i].codigo);
          printf("Nome do produto: %s \n",p->produto[i].nome);
          printf("Preco do produto: %.2f \n",p->produto[i].preco);
          printf("Quantidade em estoque: %d \n",p->produto[i].quantidade_estoque);
          printf("=================================\n");
          if(p->produto[i].quantidade_estoque > 500){
             contEstoqueAcimaQuinhentos ++;
          }
      }
      printf("Quantidade de produtos acima de 500 itens no estoque: %d",contEstoqueAcimaQuinhentos);
      printf("\n=================================================================================\n");
   }     
}
   

void cadastrarProduto(Tlista *p){
     float desc;
     if(p->tamanhoLista > 4){
        printf("Lista Cheia");
     }else{
        printf("Codigo do produto: ");
        scanf("%d",&p->produto[p->tamanhoLista].codigo);
        printf("Nome do produto: ");
        scanf("%s",&p->produto[p->tamanhoLista].nome);
        printf("Preco do produto: ");
        scanf("%f",&p->produto[p->tamanhoLista].preco);
        printf("Quantidade em estoque: ");
        scanf("%d",&p->produto[p->tamanhoLista].quantidade_estoque);
        printf("\nDigitar o desconto em % só numeros\n");
        scanf("%f",&desc);
        
        p->produto[p->tamanhoLista].preco = p->produto[p->tamanhoLista].preco -(p->produto[p->tamanhoLista].preco * desc/100);
        
        p->tamanhoLista ++;
     }
}


int main(){
   Tlista list;
   inicializa(&list);
   //printf("%d \n",list.tamanhoLista);
   int opcao;
   do{ 
      printf("Digite o numero da opcao\n");
      printf("1 - Listar Produto\n");
      printf("2 - Cadastrar Produto\n");
      printf("3 - Aplicar Desconto\n");
      printf("4 - Sair\n"); 
      scanf("%d",&opcao);
   
      switch(opcao){
         case 1:
            listarProduto(&list);
         break;
         case 2:
            cadastrarProduto(&list);
         break;
         case 3:
            //aplicarDesconto(&list);
         break;
                  
      }   
   }while(opcao != 4); 
   
   
   return 0;    
}
