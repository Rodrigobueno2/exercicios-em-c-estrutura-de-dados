#include<stdio.h>
#include<conio.h>

typedef struct aluno{
     int ra;
     char nome[30];
     char curso[30]; 
        
}Taluno;

typedef struct lista{
     Taluno lista [10];    
     int tamanhoLista;   
}Tlista;

void inicializarLista(Tlista *p){
   p->tamanhoLista = 0;
}

void inserir(Tlista *p){
   if(p->tamanhoLista < 10){
      printf("\nDigite o RA do aluno\n");
      scanf("%d",&p->lista[p->tamanhoLista].ra);
      printf("\nDigite o nome do aluno\n");
      scanf("%s",&p->lista[p->tamanhoLista].nome);
      printf("\nDigite o nome do curso\n");
      scanf("%s",&p->lista[p->tamanhoLista].curso);  //scanf("%d", &p->lista[p->tamanhoLista].valor);
      p->tamanhoLista ++;
   }else{
      printf("\nLista cheia\n");
   }

}

void pesquisar(Tlista *p){
     if(p->tamanhoLista > 0){
        for(int i = 0; i < p->tamanhoLista; i++){
           printf("--------Aluno %d ---------\n",i+1);
           printf("RA: %d",p->lista[i].ra);
           printf("\nAluno: %s",p->lista[i].nome);
           printf("\nCurso: %s \n",p->lista[i].curso);
        }
     }else{
        printf("\nNão tem nenhum registro\n");
     }
     printf("----------------------------\n");            
}

int main(){
   int opcao;
   Tlista list; 
    
   inicializarLista(&list); 
    
   do{
      printf(" 1- Cadastrar Aluno\n");
      printf(" 2- Pesquisar Alunos\n");
      printf(" 3- Sair\n");
      scanf("%d",&opcao);
      switch(opcao){
         case 1:
            inserir(&list);
         break;
         case 2:
            pesquisar(&list);
         break;           
      } 
                            
   }while(opcao != 0); 
    
   
}
