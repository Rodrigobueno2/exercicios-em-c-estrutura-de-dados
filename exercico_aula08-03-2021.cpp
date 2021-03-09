#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct funcionario{
   char nome[40];
   float salario;        
        
}Tfuncionario;

typedef struct lista{
   Tfuncionario funcionario[10];
   int tamanhoLista;        
}Tlista;

void inicializa(Tlista *p){
   p->tamanhoLista = 0;     
}

void inserirFuncionario(Tlista *p){
   if(p->tamanhoLista >=10){
      printf("\nLista cheia!!!\n");                   
   }else{
      printf("\nDigite o nome do funcionario\n");
      scanf("%s",&p->funcionario[p->tamanhoLista].nome);
      printf("\nDigite o salario do funcionario\n");
      scanf("%f",&p->funcionario[p->tamanhoLista].salario);
      p->tamanhoLista++;
   }
}

void apresentarFuncionario(Tlista *p){
    if(p->tamanhoLista == 0){
        printf("\nA lista de funcionario esta vazia\n");
    }else{
        for(int i = 0; i<p->tamanhoLista;i++){
            printf("\nFuncionario: %d ",i+1);
            printf("\nNome: %s",p->funcionario[i].nome);
            printf("\nSalario: %.2f",p->funcionario[i].salario);
            printf("\n\n");
        }
    }
}

void pesquisaFuncionario(Tlista *p){
     char nomePesquisa[40];
     int indice=0;
     if(p->tamanhoLista==0){
        printf("\nLista vazia, nao tem como pesquisr funcionario\n");
     }else{
         printf("\nDigite o nome que quer pesquisar\n");
         scanf("%s",&nomePesquisa);
         for(int i=0; i<p->tamanhoLista;i++){
              if(strcmp(nomePesquisa,p->funcionario[i].nome)== 0){
                   indice = i;
                   i = p->tamanhoLista;
              }
                    
         }
         if(strcmp(nomePesquisa, p->funcionario[indice].nome)==0){
              printf("\nNome: %s",p->funcionario[indice].nome);
              printf("\nSalario: %.2f",p->funcionario[indice].salario);
              printf("\n\n");
         }else{
              printf("\nNao foi encontrado o funcionario com esse nome\n");   
         }  
     }
     
}

void pesquisaMaiorSalario(Tlista *p){
     if(p->tamanhoLista == 0){
        printf("\nNao tem como ver o maior salario, pois nao tem funcionarios cadastrados\n");
        
     }else{
        //A variavel maior guarda o indice do array funcionario onde o salario é maior   
        int maior = 0;
        for(int i=1; i<p->tamanhoLista;i++){
            if(p->funcionario[maior].salario < p->funcionario[i].salario){
                maior = i;
            }    
        }
        for(int i = 0; i<p->tamanhoLista;i++){
            if(p->funcionario[maior].salario == p->funcionario[i].salario){
               printf("\nFuncionario %d",i+1);
               printf("\nNome: %s",p->funcionario[i].nome);
               printf("\nSalario: %.2f",p->funcionario[i].salario);
               printf("\n\n");
            }
        }
     }
}

void mediaSalarial(Tlista *p){
   float soma = 0,media;
   if(p->tamanhoLista==0){
      printf("\nNao tem funcionario cadastrado para calcular media salarial\n"); 
   }else{
      for(int i = 0; i<p->tamanhoLista;i++){
         soma = soma + p->funcionario[i].salario;
      }     
      media = soma/p->tamanhoLista;
      printf("\nA media salarial dos funcionarios eh: %.2f",media);
      printf("\n\n");
   }
   
}

void pesquisarAcimaDoSalarioDigitado(Tlista *p){
    float salario;
    int cont = 0;
    if(p->tamanhoLista == 0){
       printf("\nNao tem funcionarios cadastrados\n");
    }else{
       printf("\nDigite um salario\n");
       scanf("%f",&salario);
       for(int i = 0; i<p->tamanhoLista;i++){
          if(p->funcionario[i].salario > salario){
             cont = cont + 1;
             printf("\nFuncionario %d",i);
             printf("\nNome: %s",p->funcionario[i].nome);
             printf("\nSalario: %.2f",p->funcionario[i].salario);
             printf("\n\n");
          }
       }
       printf("\nQuantidade de funcionarios que ganham mais de %.2f : %d funcionarios",salario,cont);
    }
}
int main(){
   Tlista lista;
   int opcao;
   inicializa(&lista);
   do{
       printf("\n1- Inserir Funcionario\n"); 
       printf("\n2- Apresentar os Funcionarios\n"); 
       printf("\n3- Pesquisar Funcionario\n"); 
       printf("\n4- Funcionario que tem maior salario\n");    
       printf("\n5- Media salarial dos Funcionarios\n");
       printf("\n6- Pesquisar funcionarios que ganham mais do valor digitado\n");
       printf("\n7- Sair\n"); 
       scanf("%d",&opcao);
       switch(opcao){
          case 1:
               inserirFuncionario(&lista); 
          break;
          case 2:
               apresentarFuncionario(&lista);
          break;
          case 3:
               pesquisaFuncionario(&lista);
          break; 
          case 4:
               pesquisaMaiorSalario(&lista);
          break; 
          case 5:
               mediaSalarial(&lista);
          break; 
          case 6:
               pesquisarAcimaDoSalarioDigitado(&lista);
          break;           
       }  
   }while(opcao!=7); 
   return 0;   
}
