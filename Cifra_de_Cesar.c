#include <stdio.h>
#include <stdlib.h>

void Codifica(FILE *x, char *m, int chave){

    //char alfabeto[30] = {'A', 'B'}; //"C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};
    char aux;
    for(; *m != '\0'; m++){
        printf("%c\t", *m);
        if(*m == ' '){
            fprintf(x, "%c", *m);
        }
        else {
            aux = *m + chave;
            printf("%c\n", aux);
            fprintf(x, "%c", aux);
        }
    }
    return ;
}

void Decodifica(FILE *x, int chave){
    char aux, aj;
    aux = getc(x);
    while (aux != EOF){
        aj=aux-chave;
        printf("%c\t", aj);
        aux = getc(x);
    }
}

int main()
{
    int menu, chave;
    FILE *OUTPUT, *ENTRADA;
    char *mensagem[200];
    printf("1- Codificar\n2- Decodificar\n");
    printf("\tDigite a sua opcao: ");
    scanf("%d", &menu);
    if(menu == 1){

        OUTPUT = fopen("saida.txt", "w");

        if (!OUTPUT){
            printf("Erro....\n");
            exit(0);
        }
        fflush(stdin);
        printf("Digite a mensagem: ");
        gets(mensagem);
        fflush(stdin);
        printf("Digite a chave: ");
        scanf("%d", &chave);

        Codifica(OUTPUT, mensagem, chave);
        fclose(OUTPUT);
    }
    else if(menu == 2){
        ENTRADA = fopen("saida.txt", "r");

       if (!ENTRADA){
            printf("Erro....\n");
            exit(0);
        }
        fflush(stdin);
        printf("Digite a chave: ");
        scanf("%d", &chave);
        Decodifica(ENTRADA, chave);
    }
    else {
        printf("Entrada invalida");
    }
    return 0;
}
