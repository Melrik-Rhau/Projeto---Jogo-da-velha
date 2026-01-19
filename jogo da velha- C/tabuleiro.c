#include<stdio.h>

void IMPRIMIR_TABULEIRO();
void IMPRIMIR_TABULEIRO();

char TAB[3][3];

//-------------------------------------------------
void INICIALIZAR_TABULEIRO()
{
    int L, C;
    for (L=0; L<3; L++)
        for(C=0; C<3; C++)
            TAB[L][C]='-';
}
//-------------------------------------------------
void IMPRIMIR_TABULEIRO()
{
    int L, C;
    printf("\n\nJOGO DA VELHA\n");
    printf("\n---------------------\n");
    for (L=0; L<3; L++)
    {
        for(C=0; C<3; C++)
               printf("%c\t",TAB[L][C]);
        printf("\n");
    }
    printf("\n----------------------\n\n");
}
//-------------------------------------------------
void JOGADA(char JOGADOR)
{
    int LINHA, COLUNA;
    do
    {
        printf("Digite a posicao da linha\n");
        scanf("%d",&LINHA);
        if(LINHA<0 || LINHA >2)
            printf("Posicao da linha invalida. Digite novamente\n");
    }while(LINHA<0 || LINHA >2);
    do
    {
        printf("Digite a posicao da coluna\n");
        scanf("%d",&COLUNA);
        if(COLUNA<0 || COLUNA >2)
            printf("Posicao da coluna invalida. Digite novamente\n");
    }while(COLUNA<0 || COLUNA >2);

    if (TAB[LINHA][COLUNA] == '-')
      TAB[LINHA][COLUNA]=JOGADOR;
    else
    {
        printf("Esta posicao esta ocupada. Digite novamente\n");
        JOGADA(JOGADOR);
    }
}
//-------------------------------------------------
int VERIFICAR_GANHADOR(char JOGADOR)
{
    int L, C, GANHOU=0;
    for (L=0; L<3; L++)// testa se houve ganhador na diagonal principal
    {
        for(C=0; C<3; C++)
        {
            if((L==C)&& (TAB[L][C]== JOGADOR))
                GANHOU++;
        }
    }
    if (GANHOU == 3)
    {
        printf("\nJogador %c voce ganhou (Diagonal principal)\n", JOGADOR);
        return 1;
    }
    GANHOU=0;
    for (L=0; L<3; L++)// testa se houve ganhador na diagonal secundaria
    {
        for(C=0; C<3; C++)
        {
            if((L+C==2)&& (TAB[L][C]== JOGADOR))
                GANHOU++;
        }
    }
    if (GANHOU == 3)
    {
        printf("\nJogador %c voce ganhou (Diagonal secudaria)\n", JOGADOR);
        return 1;
    }
    GANHOU = 0;
    for (L = 0; L < 3; L++) {
        for (C = 0; C < 3; C++){
            if (TAB[L][C] == JOGADOR) {
                GANHOU++;
            } if (GANHOU == 3) {
                    printf("\nJogador %c voce ganhou (linha)");
              }
        }
    }









}
//=======================================================================









//-------------------------------------------------
int main()
{
    int CONT=0, GANHOU=0;
    char JOGADOR;
    INICIALIZAR_TABULEIRO();
    IMPRIMIR_TABULEIRO();
    while (CONT<9)
    {
        if(CONT % 2 == 0)
        {
            JOGADOR='X';
            printf("\nJogador %c sua vez\n", JOGADOR);
            JOGADA(JOGADOR);
        }
        else
        {
            JOGADOR='O';
            printf("\nJogador %c sua vez\n", JOGADOR);
            JOGADA(JOGADOR);
        }
        IMPRIMIR_TABULEIRO();
        CONT++;
        if (CONT >= 4)//so a partir da 5� jogada ha necessidade de testar se houve ganhador
            GANHOU = VERIFICAR_GANHADOR(JOGADOR);
        if (GANHOU == 1)//houve vencedor, encerrar a jogada
            break;
    }

}
//-------------------------------------------------
