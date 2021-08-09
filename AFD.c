#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void funcTransicao(int num, int tamAlf,int mat[num][tamAlf], char *a){
    
    printf("\n\nPreencha a matriz de transição:\n\n");
    for(int i=0; i<num; i++){
        for(int j = 0; j<tamAlf; j++){
            printf("Estado[%d]Caractere[%c]:", i, *a+j);
            scanf("%d", &mat[i][j]);
        }
    }

}

int palProcessada(int tamPal,int num, int tamAlf, int mat[num][tamAlf], int EstIni, char *a){
    int estadoAtual= EstIni;
    char aux;

    printf("Digite os caracteres da palavra a ser processada:\n");
    
    for (int i = 0; i < tamPal; i++){
        getchar();
        printf("%d:",i+1);
        scanf("%c", &aux);
       

        switch (aux){
        case 'a':
            estadoAtual = mat[estadoAtual][0];
            break;
        case 'b': 
            estadoAtual = mat[estadoAtual][1];
            break;
        }
    }
    return estadoAtual;
}

bool verifica(int EstFinal, int *EstFinais, int numEstFinais){
    bool valida = false;
    for(int i = 0; i<numEstFinais; i++)  
        if(EstFinal == *EstFinais+i){
            printf("Condição Verificada\n");
            valida = true;
        }
    return valida;
}

int main(){
    char a[2] = {'a','b'};    
    

    //Função de transição
    int numEst;
    printf("Digite quandos estados tem no automato:");
    scanf("%d", &numEst);
    int mat[numEst][2];
    funcTransicao(numEst, 2, mat, &a[0]);

    //Estado inicial
    int EstIni = 0;

    //Conjunto de estados finais
    int numEstFinais;
    printf("Digite o numero de estados finais:");
    scanf("%d", &numEstFinais);
    if(numEstFinais>numEst){
        numEstFinais = numEst;
        printf("ERROR: numero inválido. \n Foi atribuido %d estados finais. \n", numEstFinais);
    }
    int EstFinais[numEstFinais];
    printf("Quais são os estados finais?");
    for (int i = 0; i < numEstFinais; i++){
        printf(" %d:", i+1);
        scanf("%d", &EstFinais[i]);
        if(EstFinais[i]>numEst){
            printf("ERROR: numero inválido");
            i--;
        }
    }
    printf("------------\n");


    //Palavra a ser processada
    int tamPal;
    printf("Digite o tamanho da palavra a ser processada:");
    scanf("%d", &tamPal);
    char palavra[tamPal];
    int EstFinal = palProcessada(tamPal,numEst, sizeof(a)-2, mat, EstIni, &a[0]);

    //Sáida
    if(verifica(EstFinal,&EstFinais[0], numEstFinais)==true)
        printf("Condição de parada ACEITA! Estado final %d\n", EstFinal);
    else
        printf("Condição de para REJEITA! Estado final %d\n", EstFinal);
    

    

    return 0;
}