#include <stdio.h>
#include <string.h>

    struct endereco{
        char rua[30];
        char bairro[25];
        char cidade[25];
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
        char sobrenome[256];
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
    // struct agente verificar_agente(struct agente value);
    int verificar_agente(struct agente value);

int main(void){
    struct paciente paciente;
    struct agente agente;
    int opcao, opcao_d_login;
    int mais_um;
    
    printf("-------------\n");
    printf(" Login - 1\n");
    printf(" Sair - 2\n");
    printf("-------------\n");
    printf("Digite sua opção: ");
    scanf("%i", &opcao);

    while(true){
        if(opcao == 1){
            printf("--- LOGIN ---\n");
            printf("Nome: ");
            scanf("%s", agente.nome);
            printf("Usuário: ");
            scanf("%s", agente.usuario);
            printf("Senha: ");
            scanf("%s", agente.senha);
            if(verificar_agente(agente) == 1){
                printf("Tente novamente!\n");
                break;
            }else if(verificar_agente(agente) == 0){
                printf("-----------------------\n");
                printf(" 1 - Cadastrar paciente\n");
                printf(" 2 - Sair\n");
                printf("-----------------------\n");
                printf("Digite sua opção: ");
                scanf("%i", &opcao_d_login);

                if(opcao_d_login == 1){
                    char caractere;
                    int i = 0;
                    printf("--- CADASTRO DO PACIENTE ---\n");
                    printf("Primeiro nome: ");
                    scanf("%s", paciente.nome);
                    printf("Sobrenome: ");
                    scanf("%s", paciente.sobrenome);
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
                    scanf("%i", &paciente.endereco_paciente.numero);
                    printf("CEP: ");
                    scanf("%i", &paciente.endereco_paciente.cep);

                    cria_arquivo_paciente(paciente);
                    cria_arquivo_grupo_de_risco(paciente);
                    break;
                
                }else if(opcao_d_login == 2){
                    printf("Até a proxima!\n");
                    break;
                }else{
                    printf("Informação invalida!\n");
                    break;
                }
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
    FILE *file;
    // gambiarra para criar o arquivo com o nome do paciente
    char nome_do_arquivo[256] = "./databases/pacientes/";
    char txt[256] = ".txt";
    strcat(nome_do_arquivo, value.nome);
    strcat(nome_do_arquivo, txt);

    file = fopen(nome_do_arquivo, "w");
        fprintf(file,"Nome: %s %s\n", value.nome, value.sobrenome);
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
}
int verificar_agente(struct agente value){
    FILE *file;

    char nome_do_arquivo[256] = "./databases/agentes/";
    char txt[256] = ".txt";
    strcat(nome_do_arquivo, value.nome);
    strcat(nome_do_arquivo, txt);

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
                    printf("%s = %s", frases, value.usuario);
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