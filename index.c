#include <stdio.h>

    struct agente{
        char nome[30];
        char usuario[40];
        char senha[10];
    };

    struct paciente{
        char nome[30];
        char email[40];
        int cpf[11];
        int telefone[11];
        char comorbidade[40];
        int data_nasc[2];
        int data_diag[2];
    };

    struct endereco{
        char rua[30];
        char bairro[25];
        char cidade[25];
        char estado[2];
        int numero[4];
        int cep[8];
    };




int main(void){

    struct agente agente;
    int opcao, opcao_d_login;

    printf("-------------\n");
    printf(" Login - 1\n");
    printf(" Sair - 2\n");
    printf("-------------\n");
    printf("Digite sua opção: ");
    scanf("%i", &opcao);

    while(true){
        if(opcao == 1){
            printf("--- LOGIN ---\n");
            printf("Usuário: ");
            scanf("%s", agente.usuario);
            printf("Senha: ");
            scanf("%s", agente.senha);
            printf("%s ; %s\n", agente.usuario, agente.senha);

            printf("-------------\n");
            printf(" Cadastrar paciente - 1\n");
            printf(" Sair - 2\n");
            printf("-------------\n");
            printf("Digite sua opção: ");
            scanf("%i", &opcao_d_login);

            if(opcao_d_login == 2){
                opcao = 2;
            }else if(opcao_d_login == 1){
                printf("ESTÁ AQUI!");
                break;
            }
            
            
        }else if(opcao == 2){
            printf("Até a proxima!\n");
            break;
        }else{
            printf("Informação invalida!\n");
            break;
        }
    }
    
    return 0;
}