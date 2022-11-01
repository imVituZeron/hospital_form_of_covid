#include <stdio.h>
#include <string.h>

    struct endereco{
        char rua[30];
        char bairro[25];
        char cidade[25];
        char estado[2];
        int numero[4];
        unsigned int cep;
    };

    struct datas{
        unsigned int dia;
        unsigned int mes;
        int ano;
    };

    struct agente{
        char nome[30];
        char usuario[40];
        char senha[10];
    };

    struct paciente{
        char nome[256];
        char email[40];
        unsigned int cpf;
        int telefone[11];
        char comorbidade[40];
        struct datas data_nasc;
        struct datas data_diag;
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
                scanf("%i", &paciente.cpf);
                printf("Telefone: ");
                scanf("%i", paciente.telefone);
                printf("comorbidade: ");
                scanf("%s", paciente.comorbidade);
                printf(">--- Data Nascimento ---<\n");
                printf("Dia: ");
                scanf("%i", &paciente.data_nasc.dia);
                printf("Mês: ");
                scanf("%i", &paciente.data_nasc.mes);
                printf("Ano: ");
                scanf("%i", &paciente.data_nasc.ano);
                printf(">--- Data Diagnostico ---<\n");
                printf("Dia: ");
                scanf("%i", &paciente.data_diag.dia);
                printf("Mês: ");
                scanf("%i", &paciente.data_diag.mes);
                printf("Ano: ");
                scanf("%i", &paciente.data_diag.ano);
                printf(">--- Endereço ---<\n");
                printf("Rua: ");
                scanf("%s", paciente.endereco_paciente.rua);
                printf("Bairro: ");
                scanf("%s", paciente.endereco_paciente.bairro);
                printf("Cidade: ");
                scanf("%s", paciente.endereco_paciente.cidade);
                printf("Estado [SP/MG/RJ]: ");
                scanf("%s", paciente.endereco_paciente.estado);
                printf("Número: ");
                scanf("%i", paciente.endereco_paciente.numero);
                printf("CEP: ");
                scanf("%i", &paciente.endereco_paciente.cep);

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
    printf("> ---- Cadastro de Paciente completo.\n");

    return value;
};

struct paciente cria_arquivo_grupo_de_risco(struct paciente value){
    int idade = 2022 - value.data_nasc.ano; 

    if(value.comorbidade != "\0" && idade >= 65){
        printf(">----------------------------<\n");
        printf("Paciente do Grupo de Risco!\n");
        printf("Idade: %i\n", idade);
        printf("Contem comorbidades: %s\n", value.comorbidade);
        printf(">----------------------------<\n");

        FILE *file;
        // gambiarra pra criar o arquivo com o nome do paciente
        char nome_do_arquivo[256] = "./databases/grupo_de_risco/";
        char txt[256] = ".txt";
        strcat(nome_do_arquivo, value.nome);
        strcat(nome_do_arquivo, txt);

        file = fopen(nome_do_arquivo,"w");
            fprintf(file, "Nome: %s\n",value.nome);
            fprintf(file, "CPF: %d\n",value.cpf);
            fprintf(file, "CEP: %i\n",value.endereco_paciente.cep);
            fprintf(file, "Comorbidade: %s\n",value.comorbidade);
        fclose(file);
    }else{
        printf("Paciente NÃO faz parte do Grupo de Risco!\n");
    }

    return value;
}