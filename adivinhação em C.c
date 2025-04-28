#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");

    // imprime cabeÃ§alho do nosso jogo
    printf("****************************************\n");
    printf("*BEM VINDO AO NOSSO JOGO DE ADIVINHA��O!!!*\n");
    printf("****************************************\n");

    int segundos = time(0);
    srand(segundos);

    int numerogrande = rand();

    int numerosecreto = numerogrande % 100;
    int chute;
    int tentativas = 1;
    double pontos = 1000;

    int acertou;

    int nivel;
    printf("Dificuldade\n");
    printf("(1) F�cil (2) M�dio (3) Dif�cil\n\n");
    printf("Escolha: ");
    scanf("%d", &nivel);

    int numerodetentativas;

    switch (nivel)
    {
    case 1:
        numerodetentativas = 20;
        break;
    case 2:
        numerodetentativas = 15;
        break;
    default:
        numerodetentativas = 6;
        break;
    }

    for (int i = 1; i <= numerodetentativas; i++)
    {

        printf("Tentativa %d\n ", tentativas);
        printf("Qual e o seu chute?\n ");
        scanf("%d", &chute);
        printf("Seu chute foi %d\n", chute);

        if (chute < 0)
        {
            printf("Voc� n�o pode chutar numeros negativos\n");
            continue;
        }

        acertou = (chute == numerosecreto);
        int maior = chute > numerosecreto;

        if (acertou)
        {
            break;
        }
        else if (maior)
        {
            printf("Seu numero � maior que o numero secreto\n");
        }
        else
        {
            printf("Seu chute � menor que o numero secreto\n");
        }
        
        tentativas++;
        
        double pontosperdidos = abs(chute - numerosecreto) / (double)2;
        pontos = pontos - pontosperdidos;
    }

    printf("Fim de jogo\n");

    if (acertou)
    {
        printf("Parabens voc� acertou\n");
        printf("Voc� acertou em %d tentativas!\n", tentativas);
        printf("total de pontos %.1f\n", pontos);
        printf("Jogue novamente!\n");
    }
    else
    {
        printf("voc� perdeu, tente de novo");
    }
}


