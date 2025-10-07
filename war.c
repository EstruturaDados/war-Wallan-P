#include <stdio.h>

int main() {

 //declaracão da Struct
    typedef struct{

        char nome[20];
        char cor[10];
        int tropas;

    }Territorio;

//criação da variavel do tipo Territorio 
    Territorio Territorio1[5];

//estrutura de repetição para scanear dados do usuario    
    for (int i=0; i<5; i++ ){


        printf("\nQantas tropas o territorio tem?  ");
        scanf("%d",&Territorio1[i].tropas);

        printf("\nQual a cor do territorio?  ");
        scanf("%s",Territorio1[i].cor);

        printf("\nQual o nome do territorio?  ");
        scanf("%s",Territorio1[i].nome);
    
    };
   
 
    
//estrutura de repetição para apresentar os dados cadastrados ao usuario
    for (int i=0; i<5; i++ ){

        printf("\n Tropas do territorio:  %d   ",Territorio1[i].tropas);
        printf("\n Nome do territorio:  %s  ",Territorio1[i].nome);
        printf("\n Cor do territorio:  %s  ",Territorio1[i].cor);
        
        printf("\n\n");

    };

    return 0;
}
