#include <stdio.h>

int main(void){
    int opcao;

    printf("-------------\n");
    printf(" Login - 1\n");
    printf(" Cadastro - 2\n");
    printf("-------------\n");
    printf("Digite sua opção: ");
    scanf("%i", &opcao);

    if(opcao == 1){
        printf("opção == 1");
    }else if(opcao == 2){
        printf("opção == 2");
    }



}