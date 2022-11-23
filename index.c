#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdio_ext.h>

    struct endereco{
        char rua[256];
        char bairro[256];
        char cidade[256];
        char estado[2];
        int numero;
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
        char email[256];
        unsigned int cpf;
        int telefone[11];
        char comorbidade[256];
        struct datas data_nasc;
        struct datas data_diag;
        struct endereco endereco_paciente;
    };

    struct paciente cria_arquivo_paciente(struct paciente value);
    struct paciente cria_arquivo_grupo_de_risco(struct paciente value);
    int verificar_agente(struct agente value);
    void __fpurge(FILE *stream);
    void pegar_entrada(char *buff);
    
int main(void){
    struct paciente paciente;
    struct agente agente;
    int opcao, opcao_d_login, result, mais_um;
    
    printf("-------------\n");
    printf(" 1 - Login\n");
    printf(" 2 - Sair\n");
    printf("-------------\n");
    printf("Digite sua opção: ");
    scanf("%i", &opcao);

    switch(opcao){
    case 1:
        system("clear"); // trocar esse comando quando for fazer a parte para o Windows
        printf("--- LOGIN ---\n");
        printf("Nome: ");
        pegar_entrada(agente.nome);
        printf("Usuário: ");
        pegar_entrada(agente.usuario);
        printf("Senha: ");
        pegar_entrada(agente.senha);
        result = verificar_agente(agente);

        switch (result){
        case 0:
            system("clear");
            printf("-----------------------\n");
            printf(" 1 - Cadastrar paciente\n");
            printf(" 2 - Sair\n");
            printf("-----------------------\n");
            printf("Digite sua opção: ");
            scanf("%i", &opcao_d_login);

            do{
                system("clear");
                printf("--- CADASTRO DO PACIENTE ---\n");
                printf("Nome: ");
                pegar_entrada(paciente.nome);
                printf("Email: ");
                pegar_entrada(paciente.email);
                printf("CPF: ");
                scanf("%i", &paciente.cpf);
                printf("Telefone: ");
                scanf("%i", paciente.telefone);
                printf("comorbidade: ");
                pegar_entrada(paciente.comorbidade);
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
                pegar_entrada(paciente.endereco_paciente.rua);
                printf("Bairro: ");
                pegar_entrada(paciente.endereco_paciente.bairro);
                printf("Cidade: ");
                pegar_entrada(paciente.endereco_paciente.cidade);
                printf("Estado [SP/MG/RJ]: ");
                pegar_entrada(paciente.endereco_paciente.estado);
                printf("Número: ");
                scanf("%i", &paciente.endereco_paciente.numero);
                printf("CEP: ");
                scanf("%i", &paciente.endereco_paciente.cep);

                cria_arquivo_paciente(paciente);
                cria_arquivo_grupo_de_risco(paciente);

                system("clear");
                printf("Deseja Cadastrar mais alguma paciente?\n");
                printf("---------------\n");
                printf(" 1 - Sim\n");
                printf(" 0 - Não\n");
                printf("---------------\n");
                printf("Digite sua opção: ");
                scanf("%i", &mais_um);

                if(mais_um == 1){
                    printf("Paciente anterior cadastrado com sucesso!\n");
                    opcao_d_login = 1;
                }else if(mais_um == 0){
                    printf("Paciente cadastrado com sucesso!\n");
                    opcao_d_login = 2;
                    break;
                }

            }while(opcao_d_login == 1);
        case 1:
            printf("Execute o programa e tente novamente!\n");
            break;
        default:
            printf("Informação invalida!\n");
            break;
        }
        break;
    case 2:
        printf("Até a proxima!\n");
        break;
    default:
        printf("Informação invalida!\n");
        break;
    }

    return 0;
}

struct paciente cria_arquivo_paciente(struct paciente value){
    FILE *file;
    // gambiarra para criar o arquivo com o nome do paciente
    char nome_do_arquivo[256] = "./databases/pacientes/";
    char txt[256] = ".txt";
    strcat(nome_do_arquivo, value.nome);
    strcat(nome_do_arquivo, txt);

    file = fopen(nome_do_arquivo, "w");
        fprintf(file,"Nome: %s\n", value.nome);
        fprintf(file,"Email: %s\n", value.email);
        fprintf(file,"Cpf: %i\n", value.cpf);
        fprintf(file,"Telefone: %n\n", value.telefone);
        fprintf(file,"Comorbidade: %s\n", value.comorbidade);
        fprintf(file,"Data de Nasc: %i/%i/%i\n", value.data_nasc.dia, value.data_nasc.mes, value.data_nasc.ano);
        fprintf(file,"Data de Diag: %i/%i/%i\n", value.data_diag.dia, value.data_diag.mes, value.data_diag.ano);
        fprintf(file,"Rua/Número/Bairro: %s - nº%i - %s\n", value.endereco_paciente.rua, value.endereco_paciente.numero, value.endereco_paciente.bairro);
        fprintf(file,"cidade/Estado: %s - %s\n", value.endereco_paciente.cidade, value.endereco_paciente.estado);
        fprintf(file,"CEP: %i\n", value.endereco_paciente.cep);
    fclose(file);
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
        // gambiarra para criar o arquivo com o nome do paciente
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
};

int verificar_agente(struct agente value){
    FILE *file;

    char nome_do_arquivo[256] = "./databases/agentes/";
    char txt[256] = ".txt";
    strcat(nome_do_arquivo, value.nome);
    strcat(nome_do_arquivo, txt);
    
    printf("-------- %s", nome_do_arquivo);
    file = fopen(nome_do_arquivo, "r");
        if(file == NULL){
            printf("Agente não cadastrado!");
        }

        char frases[100];
        int i = 0;
        while(fgets(frases,100,file) != NULL){
            printf("%i - %s\n", i, frases);
            if(i == 1){
                if(*frases != *value.usuario){
                    printf("Usuário incorreto!\n");
                    return 1;
                }
            }else if(i == 2){
                if(*frases != *value.senha){
                    printf("Senha incorreto!\n");
                    return 1;
                }
            }
            i++;
        }
    fclose(file);

    return 0;
};

void pegar_entrada(char *buff){
    // função para pegar os inputs corretamentes
    int len;
    __fpurge(stdin);
    fgets(buff, sizeof(buff), stdin);

    len = strlen(buff);
    if(buff[len - 1] == '\n')
        buff[--len] = '\0';
};