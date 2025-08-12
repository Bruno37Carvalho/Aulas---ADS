#include <stdio.h>
#include <stdlib.h>

#define MAXIMO_tab 10

// Variáveis
int tabuleiro[MAXIMO_tab][MAXIMO_tab]; // tamanho máximo do tabuleiro
int tam_tab; // tamanho escolhido pro tabuleiro
int num_navios; // número de navios que terá no tabuleiro
int i, j, k; // variáveis para loop
int tam_navios; // tamanho dos navios no tabuleiro
int orientação; // define orientação dos navios no tabuleiro
int r, c; // localização no tabuleiro
int contador; //Indica se o navio existe
int aceitar; // indica se o navio foi colocado certo
int marcado = 3; // usado para marcar o navio no tabuleiro

// Função principal
int main() {
    // Escolher tamanho do tabuleiro
    printf("Digite o tamanho do tabuleiro (max %d): ", MAXIMO_tab);
    scanf("%d", &tam_tab);

    // Inicializando tabuleiro
    for(i=0;i<tam_tab;i++){
        for(j=0;j<tam_tab;j++){
            tabuleiro[i][j]=0;
        }
    }

    // Escolher número de navios
    printf("Digite o numero de navios: ");
    scanf("%d", &num_navios);

    // Escolher tamanho dos navios
    printf("Digite o tamanho dos navios: ");
    scanf("%d", &tam_navios);

    // Colocando navios
    for(i=0;i<num_navios;i++){
        aceitar=0;
        while(!aceitar){
            r = rand() % tam_tab;
            c = rand() % tam_tab;
            orientação = rand() % 2;

            if(orientação==0 && c+tam_navios<=tam_tab){
                contador=0;
                for(k=0;k<tam_navios;k++){
                    if(tabuleiro[r][c+k]==0) contador++;
                }
                if(contador==tam_navios){
                    for(k=0;k<tam_navios;k++){
                        tabuleiro[r][c+k]=marcado;
                    }
                    aceitar=1;
                }
            }

            if(orientação==1 && r+tam_navios<=tam_tab){
                contador=0;
                for(k=0;k<tam_navios;k++){
                    if(tabuleiro[r+k][c]==0) contador++;
                }
                if(contador==tam_navios){
                    for(k=0;k<tam_navios;k++){
                        tabuleiro[r+k][c]=marcado;
                    }
                    aceitar=1;
                }
            }
        }
    }

    // Exibindo tabuleiro
    printf("   ");
    for(i=0;i<tam_tab;i++){
        printf("%d ", i+1);
    }
    printf("\n");

    for(i=0;i<tam_tab;i++){
        printf("%c  ", 'A'+i);
        for(j=0;j<tam_tab;j++){
            if(tabuleiro[i][j]==0) printf("~ ");
            else printf("X ");
        }
        printf("\n");
    }

    return 0;
}
