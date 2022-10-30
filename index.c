#include <stdio.h>

    struct endereco{
        char rua[30];
        char bairro[25];
        char cidade[25];
        char estado[2];
        int numero[4];
        int cep[8];
    };

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
        char data_nasc[2];
        int data_diag[2];
        struct endereco endereco_paciente;
    };

    // prototipando as funções com estruturas
    struct paciente cria_arquivo_paciente(struct paciente value);
    struct paciente cria_arquivo_grupo_de_risco(struct paciente value);

int main(void){
    struct paciente paciente;
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

            if(opcao_d_login == 1){
                printf("--- CADASTRO DO PACIENTE ---\n");
                printf("Nome: ");
                scanf("%s", paciente.nome);
                printf("Email: ");
                scanf("%s", paciente.email);
                printf("CPF: ");
                scanf("%i", paciente.cpf);
                printf("Telefone: ");
                scanf("%i", paciente.telefone);
                printf("comorbidade: ");
                scanf("%s", paciente.comorbidade);
                printf(">--- Data Nascimento ---<\n");
                printf("Dia: ");
                scanf("%s", &paciente.data_nasc[0]);
                setbuf(stdin, NULL);
                printf("Mês: ");
                scanf("%s", &paciente.data_nasc[1]);
                setbuf(stdin, NULL);
                printf("Ano: ");
                scanf("%s", &paciente.data_nasc[2]);
                setbuf(stdin, NULL);
                printf("--------------------------\n");
                printf(">--- Data Diagnostico ---<\n");
                printf("Dia: ");
                scanf("%i", &paciente.data_diag[0]);
                setbuf(stdin, NULL);
                printf("Mês: ");
                scanf("%i", &paciente.data_diag[1]);
                setbuf(stdin, NULL);
                printf("Ano: ");
                scanf("%i", &paciente.data_diag[2]);
                setbuf(stdin, NULL);
                printf("--------------------------\n");
                cria_arquivo_paciente(paciente);
                cria_arquivo_grupo_de_risco(paciente);
                
                break;
            }else if(opcao_d_login == 2){
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

struct paciente cria_arquivo_paciente(struct paciente value){
    printf("prototipo - cadastro paciente\n");

    return value;
};

struct paciente cria_arquivo_grupo_de_risco(struct paciente value){
    int idade = 2022 - (int)value.data_nasc[2]; // esta com alguns erros
    printf("nasc - %i\n", (int)value.data_nasc[2]); // esta com alguns erros
    printf("%s\n", value.comorbidade);

    if(value.comorbidade != "\0" && idade >= 65){
        printf("vai ser criado o arquivo deste paciente por ser do grupo de risco!\n");
    }else{
        printf("saindo da função grupo_de_risco\n");
    }

    return value;
}