
// ADICIONANDO TODAS BIBLIOTECAS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>


#define LIMPAR_TELA "clear"



// DEFININDO TODAS CORES QUE SERÃO USADAS NO CÓDIGO
#define AZUL "\x1B[34m"
#define VERMELHO "\x1B[31m"
#define VERDE "\x1B[32m"
#define AMARELO "\x1B[33m"
#define CIANO "\x1B[36m"
#define MAGENTA "\x1B[35m"
#define BRANCO "\x1B[37m"
#define PRETO "\x1B[30m"
#define RESET "\x1B[0m"
#define FUNDO_VERMELHO "\x1b[41m"






// CRIANDO UM NOVO TIPO ATRAVÉS DO STRUCT
typedef struct
{
    char NomeCompleto[100];
    char DataNascimento[100];
    char Sexo[3];
    char Email[100];
    char Telefone[100];
    char Rua[100];
    char Numero[10];
    char Complemento[100];
    char Cep[100];
    char Bairro[100];
    char Cidade[100];
    char Estado[3];
}Cliente;


// LISTA DE APRESENTAÇÕES DO MUSEO
char OPCAO01[50] = "FUTEBOL";
char OPCAO02[50] = "ATLETISMO";
char OPCAO03[50] = "GINASTICA";
char OPCAO04[50] = "TÊNIS";


// PROTOTICO DE FUNÇÕES
void ReduzCaractere(char *str);
void SalvarCsv(cliente);
void LimpaBuffer();
int TICKET();





int main(){

    // DEFININDO A LINGUAGEM PORTUGUESA COMO PADRÃO DO CÓDIGO
    setlocale(LC_ALL, "Portuguese");


    // DECLARAÇÃO DE VARIÁVEIS USADAS NO CÓDIGO
    int OPCAO = 0;
    // NÂO ESTÁ EM USO int i = 0;
    // NÂO ESTÁ EM USO int MENU_ANTERIOR = 0;
    int TOTAL_INGRESSO = 0;
    int INGRESSO_REGULAR = 0;
    int INGRESSO_ESTUDANTE =0;
    int INGRESSO_CRIANCA =0;
    int INGRESSO_IDOSO =0;
    int OPCAO_CASE1 = 0;
    int OPCAO_CASE3 =0;
    int OPCAO_CASE4 = 0;
    int OPCAO_CASE5 =0;
    int OPCAO_CASE6 =0;
    int OPCAO_CASE7 =0;
    int OPCAO_CASE8 =0;
    char EXPOSICAO[50];
    char CPF[15]; // USADO PARA ARMAZENAR O CPF DO CLIENTE
    FILE *arquivo;



    while(1){
        switch(OPCAO)
        {

        case 0:
        //BUSCAR CLIENTE
            // MENU PRINCIPAL DO PROGRAMA
            system(LIMPAR_TELA);
            printf("%s",AZUL);
            printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
            printf("%s", RESET);
            printf("%s┃%s%s     BEM-VINDO AO MUSEU   %s%s┃%s\n",AZUL,RESET,FUNDO_VERMELHO,RESET,AZUL,RESET);
            printf("%s┃━━━━━━━━━━━━━━━━━━━━━━━━━━┃%s\n",AZUL, RESET);
            printf("%s┃%sVENDA                  %s[1]%s%s┃%s\n",AZUL,RESET,AMARELO,RESET,AZUL,RESET);
            printf("%s┃%sCADASTRO               %s[2]%s%s┃%s\n",AZUL,RESET,AMARELO,RESET,AZUL,RESET);
            printf("%s┃%sEXPOSIÇÕES             %s[3]%s%s┃%s\n",AZUL,RESET,AMARELO,RESET,AZUL,RESET);
            printf("%s┃%sVALIDAR TICKET         %s[4]%s%s┃%s\n",AZUL,RESET,AMARELO,RESET,AZUL,RESET);
            printf("%s┃%sSUPORTE                %s[5]%s%s┃%s\n",AZUL,RESET,AMARELO,RESET,AZUL,RESET);
            printf("%s┃                          ┃%s\n",AZUL,RESET);
            printf("%s┃%s%sSAIR                  [10]%s%s┃%s\n",AZUL,RESET,VERMELHO,RESET,AZUL,RESET);
            printf("%s┃━━━━━━━━━━━━━━━━━━━━━━━━━━┛%s\n",AZUL,RESET);
            printf("%s┗┫%s%sINFORME UMA OPÇÃO%s: ",AZUL,RESET,AMARELO,RESET);
            printf("\x1B(B");
            if (scanf("%3d", &OPCAO) != 1) {
                printf("%sERROR!%s\n%sOPÇÃO INVÁLIDA.%s\n", VERMELHO, RESET, VERMELHO, RESET);
                sleep(2.0);
                LimpaBuffer(); // ou fflush(stdin);
                continue;
            }
            break;



        case 1:
            // EXPOSIÇÕES DE VENDA
            // TELA DE EXPOSIÇÕES DO PROGRAMA
            system(LIMPAR_TELA);
            printf("%s",AZUL);
            printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
            printf("%s",RESET);
            printf("%s┃%s%s        EXPOSIÇÕES        %s%s┃%s\n",AZUL,RESET,FUNDO_VERMELHO,RESET,AZUL,RESET);
            printf("%s┃━━━━━━━━━━━━━━━━━━━━━━━━━━┃%s\n",AZUL,RESET);
            printf("%s┃%s%s                %s[1]%s%s┃%s\n",AZUL,RESET,OPCAO01,AMARELO,RESET,AZUL,RESET);
            printf("%s┃%s%s              %s[2]%s%s┃%s\n",AZUL,RESET,OPCAO02,AMARELO,RESET,AZUL,RESET);
            printf("%s┃%s%s              %s[3]%s%s┃%s\n",AZUL,RESET,OPCAO03,AMARELO,RESET,AZUL,RESET);
            printf("%s┃%s%s                  %s[4]%s%s┃%s\n",AZUL,RESET,OPCAO04,AMARELO,RESET,AZUL,RESET);
            printf("%s┃                          ┃%s\n",AZUL,RESET);
            printf("%s┃%s%sVOLTAR                 [0]%s%s┃%s\n",AZUL,RESET,VERMELHO,RESET,AZUL,RESET);
            printf("%s┃━━━━━━━━━━━━━━━━━━━━━━━━━━┛%s\n",AZUL,RESET);
            printf("%s┗┫%s%sESCOLHA A OPÇÃO DESEJADA%s: ",AZUL,RESET,AMARELO,RESET);
            scanf("%d", &OPCAO_CASE1); // SALVANDO NA VARIVEL OPCAO_CASE1 A ESCOLHA DO CLIENTE


            // SWITCH CASE COM TODAS OPÇÕES DA TELA DE EXPOSIÇÕES
            switch(OPCAO_CASE1){
            case 0:
                OPCAO = 0;// VOLTANDO AO MENU
                break;

            case 1:
                strcpy(EXPOSICAO,OPCAO01);
                OPCAO = 8;
                break;

            case 2:
                strcpy(EXPOSICAO,OPCAO02);
                OPCAO = 8;
                break;
            case 3:
                strcpy(EXPOSICAO,OPCAO03);
                OPCAO = 8;
                break;
            case 4:
                strcpy(EXPOSICAO,OPCAO04);
                OPCAO = 8;
                break;

            default:
                OPCAO = 1;
                LimpaBuffer();
                printf("%sERROR!%s\n%sOPÇÂO INVÁLIDA.%s\n",VERMELHO,RESET,VERMELHO,RESET);
                sleep(2.0);
                break;

            }
            break;





        case 2:
            // TELA DE CADASTRO DOS CLIENTES
            getchar();
            Cliente cliente;
            system(LIMPAR_TELA);
            printf("%s",AZUL);
            printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
            printf("%s",RESET);
            printf("%s┃%s%s        CADASTRO           %s%s┃%s\n",AZUL,RESET,FUNDO_VERMELHO,RESET,AZUL,RESET);
            printf("%s┃━━━━━━━━━━━━━━━━━━━━━━━━━━━┛%s\n",AZUL,RESET);
            printf("%s┗┫%sNOME COMPLETO: ",AZUL,RESET);// NOME COMPLETO
            fgets(cliente.NomeCompleto, 100, stdin);
            ReduzCaractere(cliente.NomeCompleto);



            printf("%s┗┫%sDATA DE NASCIMENTO: ",AZUL,RESET); // DATA DE NASCIMENTO
            fgets(cliente.DataNascimento, 50, stdin);
            ReduzCaractere(cliente.DataNascimento);


            printf("%s┗┫%sSEXO [M/F]: ",AZUL,RESET); // SEXO
            fgets(cliente.Sexo, 3, stdin);
            ReduzCaractere(cliente.Sexo);



            printf("%s┗┫%sEMAIL: ",AZUL,RESET); // EMAIL
            fgets(cliente.Email, 50, stdin);
            ReduzCaractere(cliente.Email);


            printf("%s┗┫%sTELEFONE: ",AZUL,RESET); // TELEFONE
            fgets(cliente.Telefone, 50, stdin);
            ReduzCaractere(cliente.Telefone);


            printf("%s┗┫%sRUA: ",AZUL,RESET); // RUA
            fgets(cliente.Rua, 100, stdin);
            ReduzCaractere(cliente.Rua);


            printf("%s┗┫%sNÚMERO: ",AZUL,RESET); // NUMERO
            fgets(cliente.Numero, 9, stdin);
            ReduzCaractere(cliente.Numero);


            printf("%s┗┫%sCOMPLEMENTO: ",AZUL,RESET); // COMPLEMENTO
            fgets(cliente.Complemento, 100, stdin);
            ReduzCaractere(cliente.Complemento);


            printf("%s┗┫%sCEP: ",AZUL,RESET); // CEP
            fgets(cliente.Cep, 50, stdin);
            ReduzCaractere(cliente.Cep);


            printf("%s┗┫%sBAIRRO: ",AZUL,RESET); // BAIRRO
            fgets(cliente.Bairro, 100, stdin);
            ReduzCaractere(cliente.Bairro);


            printf("%s┗┫%sCIDADE: ",AZUL,RESET); // CIDADE
            fgets(cliente.Cidade, 100, stdin);
            ReduzCaractere(cliente.Cidade);


            printf("%s┗┫%sESTADO: ",AZUL,RESET); // ESTADO
            fgets(cliente.Estado, 3, stdin);

            SalvarCsv(cliente);

            OPCAO = 6;


            break;



        case 3:
            // TELA COM TODAS APRESENTAÇÕES DO MUSEU
            system(LIMPAR_TELA);
            printf("\x1B[0"); // ATIVA CARACTERES ESPECIAIS
            printf("%s",AZUL);
            printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
            printf("%s",RESET);
            printf("%s┃%s%s EXPOSIÇÕES  ┃     SETOR  %s%s┃%s\n",AZUL,RESET,FUNDO_VERMELHO,RESET,AZUL,RESET);
            printf("%s┃━━━━━━━━━━━━━━━━━━━━━━━━━━┃%s\n",AZUL,RESET);
            printf("%s┃%s%s            AZUL%s[1]%s%s┃%s\n",AZUL,RESET,OPCAO01,AMARELO,RESET,AZUL,RESET,AZUL,RESET);
            printf("%s┃%s%s         VERDE%s[2]%s%s┃%s\n",AZUL,RESET,OPCAO02,AMARELO,RESET,AZUL,RESET,AZUL,RESET);
            printf("%s┃%s%s       AMARELO%s[3]%s%s┃%s\n",AZUL,RESET,OPCAO03,AMARELO,RESET,AZUL,RESET,AZUL,RESET);
            printf("%s┃%s%s          VERMELHO%s[4]%s%s┃%s\n",AZUL,RESET,OPCAO04,AMARELO,RESET,AZUL,RESET,AZUL,RESET);
            printf("%s┃                          ┃%s\n",AZUL,RESET);
            printf("%s┃%s%sVOLTAR                 [0]%s%s┃%s\n",AZUL,RESET,VERMELHO,RESET,AZUL,RESET);
            printf("%s┃━━━━━━━━━━━━━━━━━━━━━━━━━━┛%s\n",AZUL,RESET);
            printf("%s┗┫%s%sINFORME UMA OPÇÃO%s: ",AZUL,RESET,AMARELO,RESET);
            scanf("%d", &OPCAO_CASE3);
            switch(OPCAO_CASE3){
                case 0:
                OPCAO = 0;// VOLTANDO AO MENU
                break;




                case 1:
                    int VOLTAR;
                    system(LIMPAR_TELA);
                    printf("%s┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓%s\n",AZUL,RESET);
                    printf("%s┃%s%s                FUTEBOL                             %s%s┃%s\n",AZUL,RESET,FUNDO_VERMELHO,RESET,AZUL,RESET);
                    printf("%s┃━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┃%s\n",AZUL, RESET);
                    printf("%s┃%sO futebol é o esporte mais popular do mundo e é.    %s┃%s\n",AZUL,RESET,AZUL,RESET);
                    printf("%s┃%ssempre um dos destaques dos Jogos Olímpicos.        %s┃%s\n",AZUL,RESET,AZUL,RESET);
                    printf("%s┃%sA exposição de futebol nos Jogos Olímpicos de       %s┃%s\n",AZUL,RESET,AZUL,RESET);
                    printf("%s┃%sde Paris 2024 apresenta a história,os campeões e    %s┃%s\n",AZUL,RESET,AZUL,RESET);
                    printf("%s┃%sas curiosidades desse esporte tão amado.            %s┃%s\n",AZUL,RESET,AZUL,RESET);
                    printf("%s┃                                                    ┃%s\n",AZUL,RESET);
                    printf("%s┃%s%sVOLTAR                                           [0]%s%s┃%s\n",AZUL,RESET,VERMELHO,RESET,AZUL,RESET);
                    printf("%s┃━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛%s\n",AZUL,RESET);
                    printf("%s┗┫%s%sINFORME UMA OPÇÃO%s: ",AZUL,RESET,AMARELO,RESET);
                    scanf("%d", &VOLTAR);
                    switch(VOLTAR){

                        case 0:
                            OPCAO = 3;
                            break;



                        default:
                            LimpaBuffer();
                            printf("%sERROR!%s\n%sOPÇÂO INVÁLIDA.%s\n",VERMELHO,RESET,VERMELHO,RESET);
                            OPCAO = 3;
                            sleep(2.0);
                            break;




                    }
                    break;








                case 2:
                    int VOLTAR_ATLETISMO;
                    system(LIMPAR_TELA);
                    printf("%s┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓%s\n",AZUL,RESET);
                    printf("%s┃%s%s                   ATLETISMO                        %s%s┃%s\n",AZUL,RESET,FUNDO_VERMELHO,RESET,AZUL,RESET);
                    printf("%s┃━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┃%s\n",AZUL, RESET);
                    printf("%s┃%sO atletismo é uma das modalidades mais antigas dos  %s┃%s\n",AZUL,RESET,AZUL,RESET);
                    printf("%s┃%sJogos Olímpicos. A exposição de atletismo nos Jogos %s┃%s\n",AZUL,RESET,AZUL,RESET);
                    printf("%s┃%sOlímpicos de Paris 2024 apresenta a história,       %s┃%s\n",AZUL,RESET,AZUL,RESET);
                    printf("%s┃%sos campeões e as curiosidades desse esporte tão     %s┃%s\n",AZUL,RESET,AZUL,RESET);
                    printf("%s┃%semocionante.                                        %s┃%s\n",AZUL,RESET,AZUL,RESET);
                    printf("%s┃                                                    ┃%s\n",AZUL,RESET);
                    printf("%s┃%s%sVOLTAR                                           [0]%s%s┃%s\n",AZUL,RESET,VERMELHO,RESET,AZUL,RESET);
                    printf("%s┃━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛%s\n",AZUL,RESET);
                    printf("%s┗┫%s%sINFORME UMA OPÇÃO%s: ",AZUL,RESET,AMARELO,RESET);
                    scanf("%d", &VOLTAR_ATLETISMO);
                    switch(VOLTAR_ATLETISMO){

                        case 0:
                            OPCAO = 3;
                            break;



                        default:
                            LimpaBuffer();
                            printf("%sERROR!%s\n%sOPÇÂO INVÁLIDA.%s\n",VERMELHO,RESET,VERMELHO,RESET);
                            OPCAO = 3;
                            sleep(2.0);
                            break;




                    }
                    break;


                case 3:
                    int VOLTAR_G;
                    system(LIMPAR_TELA);
                    printf("%s┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓%s\n",AZUL,RESET);
                    printf("%s┃%s%s                   GINÁSTICA                        %s%s┃%s\n",AZUL,RESET,FUNDO_VERMELHO,RESET,AZUL,RESET);
                    printf("%s┃━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┃%s\n",AZUL, RESET);
                    printf("%s┃%sA ginástica é um esporte acrobático e elegante que  %s┃%s\n",AZUL,RESET,AZUL,RESET);
                    printf("%s┃%ssempre impressiona os espectadores. A exposição de  %s┃%s\n",AZUL,RESET,AZUL,RESET);
                    printf("%s┃%sginástica nos Jogos Olímpicos de Paris 2024         %s┃%s\n",AZUL,RESET,AZUL,RESET);
                    printf("%s┃%sapresenta a história,os campeões e as curiosidades  %s┃%s\n",AZUL,RESET,AZUL,RESET);
                    printf("%s┃%sdesse esporte tão belo.                             %s┃%s\n",AZUL,RESET,AZUL,RESET);
                    printf("%s┃                                                    ┃%s\n",AZUL,RESET);
                    printf("%s┃%s%sVOLTAR                                           [0]%s%s┃%s\n",AZUL,RESET,VERMELHO,RESET,AZUL,RESET);
                    printf("%s┃━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛%s\n",AZUL,RESET);
                    printf("%s┗┫%s%sINFORME UMA OPÇÃO%s: ",AZUL,RESET,AMARELO,RESET);
                    scanf("%d", &VOLTAR_G);
                    switch(VOLTAR_G){

                        case 0:
                            OPCAO = 3;
                            break;



                        default:
                            LimpaBuffer();
                            printf("%sERROR!%s\n%sOPÇÂO INVÁLIDA.%s\n",VERMELHO,RESET,VERMELHO,RESET);
                            OPCAO = 3;
                            sleep(2.0);
                            break;




                    }
                    break;


                case 4:
                    int VOLTAR_T;
                    system(LIMPAR_TELA);
                    printf("%s┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓%s\n",AZUL,RESET);
                    printf("%s┃%s%s                   TÊNIS                            %s%s┃%s\n",AZUL,RESET,FUNDO_VERMELHO,RESET,AZUL,RESET);
                    printf("%s┃━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┃%s\n",AZUL, RESET);
                    printf("%s┃%sA exposição começa com uma introdução à história    %s┃%s\n",AZUL,RESET,AZUL,RESET);
                    printf("%s┃%sdo tênis.Os visitantes aprenderão sobre as origens  %s┃%s\n",AZUL,RESET,AZUL,RESET);
                    printf("%s┃%sdo esporte,que remontam ao século XVI, na França.   %s┃%s\n",AZUL,RESET,AZUL,RESET);
                    printf("%s┃%sTambém aprenderão sobre a evolução do tênis ao longo%s┃%s\n",AZUL,RESET,AZUL,RESET);
                    printf("%s┃%sdos séculos,até se tornar o esporte popular que     %s┃%s\n",AZUL,RESET,AZUL,RESET);
                    printf("%s┃%sconhecemos hoje.                                    %s┃%s\n",AZUL,RESET,AZUL,RESET);
                    printf("%s┃                                                    ┃%s\n",AZUL,RESET);
                    printf("%s┃%s%sVOLTAR                                           [0]%s%s┃%s\n",AZUL,RESET,VERMELHO,RESET,AZUL,RESET);
                    printf("%s┃━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛%s\n",AZUL,RESET);
                    printf("%s┗┫%s%sINFORME UMA OPÇÃO%s: ",AZUL,RESET,AMARELO,RESET);
                    scanf("%d", &VOLTAR_T);
                    switch(VOLTAR_T){

                        case 0:
                            OPCAO = 3;
                            break;



                        default:
                            LimpaBuffer();
                            printf("%sERROR!%s\n%sOPÇÂO INVÁLIDA.%s\n",VERMELHO,RESET,VERMELHO,RESET);
                            OPCAO = 3;
                            sleep(2.0);
                            break;




                    }
                    break;



                default:
                    OPCAO = 3;
                    LimpaBuffer();
                    printf("%sERROR!%s\n%sOPÇÂO INVÁLIDA.%s\n",VERMELHO,RESET,VERMELHO,RESET);
                    sleep(2.0);
                    break;

            }
            break;



        case 4:
            system(LIMPAR_TELA);
            printf("%s┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓%s\n",AZUL,RESET);
            printf("%s┃%s%s                  VALIDAR TICKET            %s%s┃%s\n",AZUL,RESET,FUNDO_VERMELHO,RESET,AZUL,RESET);
            printf("%s┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛%s\n",AZUL,RESET);
            int NUMERO_TICKET;
            int NUMERO_LIDO;
            int TICKET_ENCONTRADO = 0;
            printf("\n NUMERO DO TICKET: ");
            scanf(" %d", &NUMERO_TICKET);
            arquivo = fopen("TICKET.txt", "r");
            if(arquivo == NULL){
                printf("ERRO AO ABRIR O ARQUIVO TICKET.txt\n");
                OPCAO = 8;
                break;
            }
            fscanf(arquivo, "%*[^\n]\n");
            while (fscanf(arquivo, "%d%*[^\n]\n", &NUMERO_LIDO) == 1){
                if(NUMERO_TICKET == NUMERO_LIDO){
                    printf("%s TICKET VALIDO%s\n", VERDE,RESET);
                    TICKET_ENCONTRADO = 1;
                    sleep(5.0);
                    break;

                }
            }
            if (!TICKET_ENCONTRADO == 1){
                printf("%s TICKET NÃO ENCONTRADO.%s\n", VERMELHO, RESET);
                OPCAO = 4;
                sleep(5);
            }
            char RESPOSTA;

            do {
                printf("\n RETORNAR AO MENU PRINCIPAL? [S/N]: ");
                scanf(" %c", &RESPOSTA);

                // Converter a resposta para maiúsculas para lidar com 's' ou 'S'
                RESPOSTA = toupper(RESPOSTA);

                if (RESPOSTA != 'S' && RESPOSTA != 'N') {
                    printf(" POR FAVOR, DIGITE 'S' PARA SIM ou 'N' PARA NÃO.\n");
                }

            } while (RESPOSTA != 'S' && RESPOSTA != 'N');

            if(RESPOSTA == 'S'){
                printf("\n RETORNANDO AO MENU PRINCIPAL...\n");
                OPCAO = 0;
                sleep(5);
                break;
            }
            else{
                OPCAO = 4;
            }


            fclose(arquivo);
            OPCAO = 4;
            // BREAK DO SWITCH CASE 2
            break;


        case 5:
            system(LIMPAR_TELA);
            printf("\x1B[0"); // ATIVA CARACTERES ESPECIAIS
            printf("%s",AZUL);
            printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
            printf("%s",RESET);
            printf("%s┃%s%s                  SUPORTE                   %s%s┃%s\n",AZUL,RESET,FUNDO_VERMELHO,RESET,AZUL,RESET);
            printf("%s┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛%s\n",AZUL,RESET);
            printf(" TELEFONE:        (11)999999999               \n");
            printf(" EMAIL:           olimpicdigitools@gmail.com      \n");
            printf(" WHATSAPP:        (11)999999999                \n");
            printf(" EMPRESA:         Olimpic Digitools \n");

            printf("\n%s VOLTAR           [0]%s\n",VERMELHO, RESET);
            printf("%s┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━%s\n",AZUL,RESET);
            printf("%s┗┫%s%sINFORME UMA OPÇÃO%s: ",AZUL,RESET,AMARELO,RESET);
            scanf("%d", &OPCAO_CASE5);
            switch(OPCAO_CASE5){
                case 0:
                    OPCAO = 0;
                    break;





                default:
                OPCAO = 5;
                LimpaBuffer();
                printf("%sERROR!%s\n%sOPÇÂO INVÁLIDA.%s\n",VERMELHO,RESET,VERMELHO,RESET);
                sleep(2.0);
                break;









            }break;


        case 6:
            system(LIMPAR_TELA);
            printf("\x1B[0"); // ATIVA CARACTERES ESPECIAIS
            printf("\x1B[34m");
            printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
            printf("\x1B[0m");
            printf("\x1B[34m┃\x1B[0m\x1b[0m\x1b[41m                  PAGAMENTO                 \x1B[0m\x1B[34m┃\x1B[0m\n");
            printf("\x1B[34m┃━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┃\x1B[0m\n");
            printf("%s┃%sCARTÃO DE CRÉDITO                        %s[1]%s%s┃%s\n",AZUL,RESET,AMARELO,RESET,AZUL,RESET);
            printf("%s┃%sCARTÃO DE DÉBITO                         %s[2]%s%s┃%s\n",AZUL,RESET,AMARELO,RESET,AZUL,RESET);
            printf("%s┃%sDINHEIRO                                 %s[3]%s%s┃%s\n",AZUL,RESET,AMARELO,RESET,AZUL,RESET);
            printf("%s┃%s                                            %s┃%s\n",AZUL,RESET,AZUL,RESET);
            printf("%s┃%s%sTOTAL                                R$%5d%s%s┃%s\n",AZUL,RESET,VERMELHO,TOTAL_INGRESSO,RESET,AZUL,RESET);
            printf("%s┃%s                                            %s┃%s\n",AZUL,RESET,AZUL,RESET);
            printf("%s┃%s%sVOLTAR                                   [0]%s%s┃%s\n",AZUL,RESET,VERMELHO,RESET,AZUL,RESET);
            printf("%s┃━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛%s\n",AZUL,RESET);
            printf("%s┗┫%s%sSELECIONE UMA OPÇÃO DE PAGAMENTO%s: ",AZUL,RESET,AMARELO,RESET);
            scanf("%d", &OPCAO_CASE6);
            switch(OPCAO_CASE6){
                case 1:

                    int CARTAO;
                    char VALIDADE[15];
                    int COD;

                    printf("\nNÚMERO DO CARTÃO: ");
                    scanf(" %d", &CARTAO);

                    printf("DATA DE VALIDADE: ");
                    scanf(" %s", &VALIDADE);

                    printf("CÓDIGO DE SEGURANÇA: ");
                    scanf(" %d", &COD);

                    printf("AGUARDE.\n");
                    sleep(2.0);
                    printf("%sPAGAMENTO APROVADO!%s\n",VERDE,RESET);
                    sleep(5.0);
                    OPCAO = 7;
                    break;

                case 2:

                    printf("NÚMERO DO CARTÃO: ");
                    scanf(" %d", &CARTAO);

                    printf("DATA DE VALIDADE: ");
                    scanf(" %s", &VALIDADE);

                    printf("CÓDIGO DE SEGURANÇA: ");
                    scanf(" %d", &COD);

                    printf("AGUARDE.\n");
                    sleep(2.0);
                    printf("%sPAGAMENTO APROVADO!%s\n",VERDE,RESET);
                    sleep(5.0);
                    OPCAO = 7;
                    break;



                case 3:
                    int DINHEIRO;
                    int TROCO;

                    printf("VALOR DO PAGAMENTO: ");
                    scanf(" %d", &DINHEIRO);

                    if(DINHEIRO >= TOTAL_INGRESSO){
                        TROCO = DINHEIRO - TOTAL_INGRESSO;
                        printf("TROCO: R$%d\n", TROCO);
                        sleep(5.0);
                        printf("%sPAGAMENTO REALIZADO COM SUCESSO!%s\n",VERDE,RESET);
                        OPCAO = 7;
                        sleep(5.0);


                    }
                    else{
                        printf("O VALOR DO PAGAMENTO É INSUFICIENTE!\n");
                        OPCAO = 7;



                    }
                    break;





            }
            break;



        case 7:
            system(LIMPAR_TELA);
            printf("%s",AZUL);
            printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
            printf("%s",RESET);
            printf("%s┃%s%s      INGRESSO       QTD       %s%s┃%s\n",AZUL,RESET,FUNDO_VERMELHO,RESET,AZUL,RESET);
            printf("%s┃━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┃%s\n",AZUL,RESET);
            printf("%s┃%sINGRESSO REGULAR    [%s%2.0d%s]       %s┃%s\n",AZUL,RESET,VERMELHO, INGRESSO_REGULAR, RESET,AZUL,RESET);
            printf("%s┃%sINGRESSO ESTUDANTE  [%s%2.0d%s]       %s┃%s\n",AZUL,RESET,VERMELHO, INGRESSO_ESTUDANTE, RESET,AZUL,RESET);
            printf("%s┃%sINGRESSO CRIANÇA    [%s%2.0d%s]       %s┃%s\n",AZUL,RESET,VERMELHO, INGRESSO_CRIANCA, RESET,AZUL,RESET);
            printf("%s┃%sINGRESSO IDOSO      [%s%2.0d%s]       %s┃%s\n",AZUL,RESET,VERMELHO, INGRESSO_IDOSO, RESET,AZUL,RESET);
            printf("%s┃%s                               %s┃%s\n",AZUL,RESET,AZUL,RESET);
            printf("%s┃%s%sIMPRIMIR                    [1]%s%s┃%s\n",AZUL,RESET,VERMELHO,RESET,AZUL,RESET);
            printf("%s┃━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛%s\n",AZUL,RESET);
            printf("%s┗┫%s%sESCOLHA A OPÇÃO DESEJADA%s: ",AZUL,RESET,AMARELO,RESET);
            scanf("%d",&OPCAO_CASE7);
            switch(OPCAO_CASE7){
                case 1:
                    //FILE *arquivo;

                    arquivo = fopen("TICKET.txt", "w+");
                    if(arquivo == NULL){
                        printf(" ERROR AO CRIAR ARQUIVO DE ARMAZENAMENTO DOS TICKETS.\n");
                        fclose(arquivo);
                    }
                    else{

                        fprintf(arquivo, "TICKET \t\t\t\tTIPO\n");
                        printf(" CRIANDO ARQUIVO\n");
                        sleep(1.0);
                        printf(" %sCRIADO COM SUCESSO!%s\n",VERDE,RESET);
                        printf(" NOME DO ARQUIVO %s\"TICKET.txt\"%s\n\n",VERDE,RESET);

                        sleep(2.0);

                    }



                    if(INGRESSO_REGULAR > 0){
                        int IMPRESSAO = TICKET();
                        printf(" IMPRIMINDO TICKET REGULAR\n");
                        sleep(2.0);
                        printf(" %sTICKET: %d%s\n\n",VERDE,IMPRESSAO,RESET);
                        fprintf(arquivo, "%d\t\t\tREGULAR\n",IMPRESSAO);
                        sleep(2.0);

                    }
                    if(INGRESSO_ESTUDANTE > 0){
                        int IMPRESSAO = TICKET();
                        printf(" IMPRIMINDO TICKET ESTUDANTE\n");
                        sleep(2.0);
                        printf(" %sTICKET: %d%s\n\n",VERDE,IMPRESSAO,RESET);
                        fprintf(arquivo, "%d\t\t\tESTUDANTE\n",IMPRESSAO);
                        sleep(2.0);

                    }
                    if(INGRESSO_CRIANCA > 0){
                        int IMPRESSAO = TICKET();
                        printf(" IMPRIMINDO TICKET CRIANCA\n");
                        sleep(2.0);
                        printf(" %sTICKET: %d%s\n\n",VERDE,IMPRESSAO,RESET);
                        fprintf(arquivo, "%d\t\t\tCRIANCA\n",IMPRESSAO);
                        sleep(2.0);

                    }
                    if(INGRESSO_IDOSO > 0){
                        int IMPRESSAO = TICKET();
                        printf(" IMPRIMINDO TICKET IDOSO\n");
                        printf(" %sTICKET: %d%s\n\n",VERDE,IMPRESSAO,RESET);
                        fprintf(arquivo, "%d\t\t\tIDOSO\n",IMPRESSAO);
                        sleep(2.0);

                    }
                    fclose(arquivo);
                    //FINALIZANDO PROGRAMA
                    OPCAO = 0;
                    printf(" ATENDIMENTO FINALIZADO.\n");
                    sleep(2.0);
                    printf(" \n RETORNANDO AO MENU PRINCIPAL\n");
                    sleep(2.0);
                    //FINALIZANDO SWITCH CASE
                    break;

                case 2:
                    int NUMERO_TICKET;
                    int NUMERO_LIDO;
                    int TICKET_ENCONTRADO = 1;
                    printf("\n NUMERO DO TICKET: ");
                    scanf(" %d", &NUMERO_TICKET);
                    arquivo = fopen("TICKET.txt", "r");
                    if(arquivo == NULL){
                        printf("ERRO AO ABRIR O ARQUIVO TICKET.txt\n");
                        OPCAO = 8;
                        break;
                    }
                    fscanf(arquivo, "%*[^\n]\n");
                    while (fscanf(arquivo, "%d%*[^\n]\n", &NUMERO_LIDO) == 1){
                        if(NUMERO_TICKET == NUMERO_LIDO){
                            printf("%sTICKET VALIDO%s\n", VERDE,RESET);
                            TICKET_ENCONTRADO = 1;
                            sleep(10.0);
                            OPCAO = 7;
                            break;

                        }
                    }
                    if (!TICKET_ENCONTRADO){
                        printf("%sTICKET NÃO ENCONTRADO%s\n", VERMELHO, RESET);
                        sleep(10);
                    }


                    fclose(arquivo);
                    OPCAO = 7;






                    // BREAK DO SWITCH CASE 2
                    break;



















                default:
                    OPCAO = 7;
                    LimpaBuffer();
                    printf("%sERROR!%s\n%sOPÇÂO INVÁLIDA.%s\n",VERMELHO,RESET,VERMELHO,RESET);
                    sleep(2.0);
                    system(LIMPAR_TELA);
                    break;

            }
            break;


        case 8:
        // TELA COM TIPO DE INGRESSOS A SEREM ESCOLHIDOS PELO CLIENTE
        while (1) {
        system(LIMPAR_TELA);
        printf("%s",AZUL);
        printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
        printf("%s",RESET);
        printf("%s┃%s%s      INGRESSO       QTD       %s%s┃%s\n",AZUL,RESET,FUNDO_VERMELHO,RESET,AZUL,RESET);
        printf("%s┃━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┃%s\n",AZUL,RESET);
        printf("%s┃%sINGRESSO REGULAR    [%s%2.0d%s]    %s[1]%s%s┃%s\n",AZUL,RESET,VERMELHO, INGRESSO_REGULAR, RESET,AMARELO,RESET,AZUL,RESET);
        printf("%s┃%sINGRESSO ESTUDANTE  [%s%2.0d%s]    %s[2]%s%s┃%s\n",AZUL,RESET,VERMELHO, INGRESSO_ESTUDANTE, RESET,AMARELO,RESET,AZUL,RESET);
        printf("%s┃%sINGRESSO CRIANÇA    [%s%2.0d%s]    %s[3]%s%s┃%s\n",AZUL,RESET,VERMELHO, INGRESSO_CRIANCA, RESET,AMARELO,RESET,AZUL,RESET);
        printf("%s┃%sINGRESSO IDOSO      [%s%2.0d%s]    %s[4]%s%s┃%s\n",AZUL,RESET,VERMELHO, INGRESSO_IDOSO, RESET,AMARELO,RESET,AZUL,RESET);
        printf("%s┃%s                               %s┃%s\n",AZUL,RESET,AZUL,RESET);
        printf("%s┃%s%sFINALIZAR COMPRA            [5]%s%s┃%s\n",AZUL,RESET,VERMELHO,RESET,AZUL,RESET);
        printf("%s┃%s%sVOLTAR                      [6]%s%s┃%s\n",AZUL,RESET,VERMELHO,RESET,AZUL,RESET);
        printf("%s┃━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛%s\n",AZUL,RESET);
        printf("%s┗┫%s%sESCOLHA A OPÇÃO DESEJADA%s: ",AZUL,RESET,AMARELO,RESET);
        scanf("%d", &OPCAO_CASE8);

        switch (OPCAO_CASE8) {
            case 1:
                TOTAL_INGRESSO += 25;
                INGRESSO_REGULAR++;
                break;

            case 2:
                TOTAL_INGRESSO += 10;
                INGRESSO_ESTUDANTE++;
                break;

            case 3:
                //TOTAL_INGRESSO += 0; NÃO TEM UTILIDADE
                INGRESSO_CRIANCA++;
                break;

            case 4:
                TOTAL_INGRESSO += 10;
                INGRESSO_IDOSO++;
                break;

            case 5:
                //getchar();
                OPCAO = 2;
                break;
            case 6:
                OPCAO = 0;
                break;

            default:
                OPCAO = 8;
                LimpaBuffer();
                printf("%sERROR!%s\n%sOPÇÂO INVÁLIDA.%s\n",VERMELHO,RESET,VERMELHO,RESET);
                sleep(2.0);
                break;
        }

        if(OPCAO_CASE8 == 6){
                char resp;
                printf("TODOS INGRESSOS SERÃO PERDIDOS!\n");
                printf("DESEJA CONTINUAR? [S/N]: ");
                scanf("%s",&resp);
                resp = toupper(resp);
                if(resp == "S"){
                    OPCAO = 0;
                    printf("VOLTANDO AO MENU");
                    sleep(1.0);
                }
            }
        break;






        if (OPCAO_CASE8 == 5) {
            // VERIFICANDO SE O CLIENTE TEM CADASTRO NO PROGRAMA
            char STATUS_CADASTRO;
            printf("\nO CLIENTE POSSUI CADASTRO? [S/N]: ");
            scanf(" %c",&STATUS_CADASTRO);
            STATUS_CADASTRO = toupper(STATUS_CADASTRO);
            if(STATUS_CADASTRO == 'S'){
                printf("\nINFORME O CPF CADASTRADO: ");
                scanf(" %15s", CPF);
            }
            else{
                // CASO NÃO TENHA CADASTRO, O SISTEMA DIRECIONA PARA TELA DE CADASTRO DO PROGRAMA
                break;
            }


            break; // BREAK ADICIONADO PARA SAIR DO LOOP/While DO SWITCH CASE[4]
        }
        }
        break;




        case 10:
            // FINALIZANDO O PROGRAMA COM O RETURN 0
            system(LIMPAR_TELA);
            printf("%sFINALIZANDO%s\n",VERMELHO,RESET);
            sleep(1.0);
            printf("\x1B[35m\n%sPROGRAMA FINALIZADO!%s\x1B[0m.\n",VERMELHO,RESET);
            sleep(2.0);
            return 0;



        default:
            // QUANDO E ENVIADO UM VALOR NÃO IDENTIFICADO NO CÓDIGO
            OPCAO = 0;
            system(LIMPAR_TELA);
            LimpaBuffer();
            printf("%sERROR!%s\n%sOPÇÂO INVÁLIDA.%s\n",VERMELHO,RESET,VERMELHO,RESET);
            sleep(2.0);
            break;




        }// SWITCH CASE MENU PRINCIPAL

    }// LAÇO WHILE DO MENU

}// FINAL DA FUNÇÃO MAIN











// FUNÇÃO PARA REMOVER O \n[QUEBRA DE LINHA] AO FINAL DA STRING
void ReduzCaractere(char *str){
    int total = strlen(str);
    if(str[total - 1] == '\n'){
        str[total - 1] = '\0';

    }


}




// FUNÇÃO PARA SALVAR OS DADOS NO PADRÃO CSV
void SalvarCsv(Cliente cliente){
    FILE *dados;
    dados = fopen("dadoscliente.csv", "a");

    if(dados != NULL){

        fprintf(dados,"%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s\n",cliente.NomeCompleto,cliente.DataNascimento,cliente.Sexo,cliente.Email,cliente.Telefone,cliente.Rua,cliente.Numero,cliente.Complemento,cliente.Cep,cliente.Bairro,cliente.Cidade,cliente.Estado);
        printf("DADOS SALVO COM SUCESSO \"dadoscliente.csv\"\n");
        sleep(3);
        fclose(dados);



    }
    else{
        printf("ERROR AO ABRIR ARQUIVO .csv\n");
    }

}




// FUNÇÃO PARA LIMPEZA DO BUFFER DO TECLADO
void LimpaBuffer(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}


int TICKET(){
    int NUMERO_TICKET = random() % 1000000000;


    return NUMERO_TICKET;

}

















