#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

 
 //declaracão da Struct
typedef struct {

        char nome[30];
        char cor[10];
        int tropas;

    }Territorio;

void Atacar(Territorio* atacante, Territorio* defensor){
    
    int dado_atacante = (rand() % 6)+ 1;
    int dado_defensor = (rand() % 6)+ 1;

    printf("\n\nTerritorio %s cor %s atacou %s cor %s ",atacante->nome,atacante->cor, defensor->nome,defensor->cor);
    printf("Dado do atacante: %d\n", dado_atacante);
    printf("Dado do defensor: %d\n", dado_defensor);

    
    if(dado_atacante > dado_defensor){

        printf("\n ataque bem sucedido\n");
        int metade = atacante->tropas / 2;

        defensor->tropas = metade;
        atacante->tropas = metade;
       strcpy(defensor->cor , atacante->cor); 
    }
    
    else {
         printf("\n defesa bem sucedida\n");
         atacante->tropas -1;

    };

};

int main() {


    int num;
    srand(time(NULL));

   

//criação da variavel do tipo Territorio 
    

 
    printf("\nQaul o numero total de territorios?  ");
    scanf("%d",&num);


    Territorio* Territorio1= ( Territorio*) calloc(num,sizeof( Territorio) );

//estrutura de repetição para scanear dados do usuario    
    for (int i=0; i<num; i++ ){

        
        
        printf("\nQantas tropas o territorio tem?  ");
        scanf("%d",&Territorio1[i].tropas);

        printf("\nQual a cor do territorio?  ");
        scanf("%s",Territorio1[i].cor);

        printf("\nQual o nome do territorio?  ");
        scanf("%s",Territorio1[i].nome);
    
    }
   
 
    
    
//estrutura de repetição para apresentar os dados cadastrados ao usuario
    for (int i=0; i<num; i++ ){

        printf("\n Tropas do territorio:  %d   ",Territorio1[i].tropas);
        printf("\n Nome do territorio:  %s  ",Territorio1[i].nome);
        printf("\n Cor do territorio:  %s  ",Territorio1[i].cor);
        
        printf("\n\n");

    };

    free(Territorio1);

    return 0;
}
