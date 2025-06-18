/*
De acordo com as políticas de entrega de atividades repassadas pelo professor, certifico que os algorítmos e programas que estou entregando são de minha autoria e que não
os repasei ou os recebi de qualquer outra pessoa.
Isaac Menezes Pereira 19/0088885
*/
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#define TAM_FORNECEDOR 100 //Variavel que delimita o tamanho de caracteres que cada nome de fornecedor vai conter.
#define TAM_LUNO 100 //Definição da variável que delimita a quantidade de caracteres que a variável 'nome_luno' (localizada na struct Dados) vai suportar,
                                                //sendo que, caso o usuário digite uma quantidade de caracteres que exceda o tamanho reservado na memória o algorítmo somente
                                                //gravará no arquivo a string até o caracter limite definido pelo tamanho da string. Por exemplo, se o usuário digitar cem caracteres 'n'
                                                //e o espaço na memória reservado pela variável 'TAM_LUNO' fosse 10, o algorítimo apenas gravarina no arquivo até a nona letra 'n'.
#define TAM_LEITOR_COPIA 1000 //Variavel que delimita a quantidade de carcteres que srao lidos na funcao copiar_conteudo.

 typedef struct dados{ //Struct para os dados de nome do aluno e hora do pedido
    char nome_luno[TAM_LUNO]; //Esta variável armazena o nome do aluno; sendo que a palavra 'luno' significa aluno
    int hora; //Armazena hora
    int minutos; //Armazena minutos
    int segun; //Armazena segundos
}Dados;  //(função: cadastro_pedido)

typedef struct tudo{ //Essa struct é apenas um ponto de partida para leitura e impressao de outras structs (no caso, é ponto de partida somente da struct Dados)
    Dados dados;
}Tudo; //(função: cadastro_pedido)


//Assinatura de funcoes:
void menu();
void cadastro_fornecedor();
void cadastro_pedido();
void del_fornecedor();
void consultarPedido();
void gerarRelatorio();
void removeLinha();


                                      //A ordem das variáveis globais, para a função 'cadastro_pedido', estão na ordem de uso no código, sendo que
                                      //a variável tamanho_marmita é usada primeiro e assim sucessivamente
int tamanho_marmita; //Variável que define a opção de tamanho da marmita que o usuário desejar; variável global (função: cadastro_pedido)
int sabor_marmita; //Variável que define a opção de sabor da marmita que o usuário desejar; variável global (função: cadastro_pedido)
int opcao_continuar_regi; //Variável que define se o usuario deseja ou não continuar o registro; váriavel global (função: cadastro_pedido)

int opcao_numero; //Define a opcao do usuario no menu principal; variavel global

int main () {
    menu();

return 0;
}



void menu() {
    while(1){
    printf("Digite a opcao desejada: \n");
    printf("-------------------------------------------------\n");
    printf("1 - Registrar fornecedor\n");
    printf("2 - Registrar pedido\n");
    printf("3 - Excluir fornecedor\n");
    printf("4 - Consultar pedido\n");
    printf("5 - Gerar relatorio de pedidos\n");
    printf("6 - Finalizar secao\n");
    printf("-------------------------------------------------\n");
    scanf ("%d", &opcao_numero);
    getchar();

    switch (opcao_numero){
        case 1:
            system("cls || clear");
            cadastro_fornecedor();
            break;
        case 2:
            system ("cls || clear");
            cadastro_pedido ();
            break;
        case 3:
            system("cls || clear");
           del_fornecedor();
            break;
        case 4:
            system("cls || clear");
            consultarPedido();
            break;
        case 5:
            system("cls || clear");
            gerarRelatorio();
            break;
        case 6:
           exit (1);
            break;
        default:
            system ("cls || clear");
            printf ("Opcao invalida\n");
    }
    }
}



void cadastro_fornecedor () { //Esta funcao cadastra quantos fornecedores o usuario desejar
    int variavel_continua; //Variavel que define se o usuario deseja ou nao continuar o cadastro de fornecedores

    char texto [TAM_FORNECEDOR]; //Le o nome do fornecedpr
    FILE *arq_fornecedores;
    arq_fornecedores = fopen ("fornecedores.txt", "at");

       if (arq_fornecedores == NULL){
        printf ("Arquivo inexistente!\n");
        getchar ();
        exit (1);
    }else {
        do {
            printf("(Caso seja digitado mais caracteres que o suportado o nome so sera gravado ate o ultimo caracter definido)\n");
            printf ("----------------------------------------------------------------------------\n");
            printf ("Digite o fornecedor: ");
            fgets (texto, TAM_FORNECEDOR, stdin);
            removeLinha ();
            fflush(stdin);
            fprintf (arq_fornecedores, "\n%s", texto);
            printf ("-------------------------------\n");
            printf ("Deseja continuar cadastrando?\n1 - Sim\n0 - Nao \n");
            scanf ("%d", &variavel_continua);
            getchar ();
            printf ("Sua opcao: %d\n", variavel_continua);
            system ("cls || clear");
            printf ("-------------------------------\n");
        }while (variavel_continua==1);
     fclose (arq_fornecedores);
    }
}



void cadastro_pedido (){
    //Abrindo o arquivo
    FILE *arq_pedidos;
    arq_pedidos = fopen ("pedido.txt", "at");
    //Declaração de variáveis locais
    int vari_continua_registro; //Variável que define se o usuário deseja continuar o cadastro de mais um pedido
    Tudo armazena_tudo; //Variável do tipo Tudo que é usado nesta função para serivir como ponto de partida para manipulações de dados na struct Dados

    if (arq_pedidos == NULL){ //Caso o arquivo que se deseja abrir não exista
        printf ("Arquivo inexistente!\n");
        getchar ();
        exit (1);
    }else {
        do {
            printf ("---------NOME DO ALUNO---------\n"); //Código que armazena o nome do aluno no arquivo pedido
            printf ("Digite o nome do aluno: ");
            fflush(stdin); //buffer: nao estava gravando  a primeira letra do primeiro aluno que se cadastrava
            fgets(armazena_tudo.dados.nome_luno, TAM_LUNO, stdin);
            fflush(stdin); //buffer
            fprintf (arq_pedidos, "%s", armazena_tudo.dados.nome_luno);
            printf("\n");
             //O código está protegido caso o usuário tente digitar um valor de hora maior que 24

            printf ("---------HORA DO REGISTRO---------\n"); //Código que armazena a hora do registro no arquivo pedido
            printf ("Digite a hora do registro: \n");
            printf ("Hora: ");
            scanf ("%d", &armazena_tudo.dados.hora);


            if (armazena_tudo.dados.hora > 0 && armazena_tudo.dados.hora <= 24){
                fprintf (arq_pedidos, "%d\n", armazena_tudo.dados.hora);
                getchar();
                system ("cls || clear");
            } else if (armazena_tudo.dados.hora  < 0 || armazena_tudo.dados.hora  > 24) {
                    do {
                    printf ("\n");
                    printf ("Hora invalida!\n");
                    printf ("Digite um horario valido: ");
                    scanf ("%d", &armazena_tudo.dados.hora );
                    getchar();
                    }while(armazena_tudo.dados.hora < 0 || armazena_tudo.dados.hora > 24);
                    fprintf (arq_pedidos, "%d\n", armazena_tudo.dados.hora);
            }

            printf ("--------------------------------------------------------\n");
            printf ("Minutos: ");
            scanf ("%d", &armazena_tudo.dados.minutos);
            //O código está protegido caso o usuário tente digitar um valor de minutos maior que 60

                if (armazena_tudo.dados.minutos >= 0 && armazena_tudo.dados.minutos < 60){
                fprintf (arq_pedidos, "%d\n", armazena_tudo.dados.minutos);
                getchar();
                system ("cls || clear");
                } else if (armazena_tudo.dados.minutos  < 0 || armazena_tudo.dados.minutos  >= 60) {
                    do {
                    printf ("\n");
                    printf ("Minutos invalidos!\n");
                    printf ("Digite um horario valido: ");
                    scanf ("%d", &armazena_tudo.dados.minutos );
                    getchar ();
                    }while(armazena_tudo.dados.minutos < 0 || armazena_tudo.dados.minutos > 60);
                    fprintf (arq_pedidos, "%d\n", armazena_tudo.dados.minutos);
            }
            printf ("\n");


            printf ("---------TAMANHO DA MARMITA---------\n"); //Código que armazena o tamanho da marmita no arquivo pedido
            printf ("Escolha o tamanho da marmita: \n");
            printf ("1 - Pequeno\n");
            printf ("2 - Medio\n");
            printf ("3 - Grande\n");
            scanf ("%d", &tamanho_marmita);

            if (tamanho_marmita==1){
                fprintf (arq_pedidos, "%d\n", tamanho_marmita);
            }else if (tamanho_marmita==2) {
                fprintf (arq_pedidos, "%d\n", tamanho_marmita);
            }else if (tamanho_marmita==3){
                fprintf (arq_pedidos, "%d\n", tamanho_marmita);
            }

            switch (tamanho_marmita){ //Menu de opções para o tamanho da marmita
                case 1:
                    printf ("Opcao escolhida: Pequena\n");
                    printf("\n");
                break;
                case 2:
                    printf ("Opcao escolhida: Medio\n");
                    printf("\n");
                break;
                case 3:
                    printf ("Opcao escolhida: Grande\n");
                    printf("\n");
                break;
                default:
                    printf ("Opcao invalida!\n");
                    printf ("Reinicie o programa e digite uma opcao valida!\n");
                    printf("\n");
           }


            printf ("---------SABOR DA MARMITA---------\n"); //Código que armazena o sabor da marmita no arquivo pedido
            printf ("Escolha o sabor da marmita: \n");
            printf ("1 - Arroz e feijao\n");
            printf ("2 - Strogonoff\n");
            printf ("3 - Churrasco\n");
            printf ("4 - Macarrao\n");
            scanf ("%d", &sabor_marmita);
            getchar ();
            if (sabor_marmita==1){
                fprintf (arq_pedidos, "%d\n\n", sabor_marmita);
            }else if (sabor_marmita==2) {
                fprintf (arq_pedidos, "%d\n\n", sabor_marmita);
            }else if (sabor_marmita==3){
                fprintf (arq_pedidos, "%d\n\n", sabor_marmita);
            }else if (sabor_marmita==4){
                fprintf (arq_pedidos, "%d\n\n", sabor_marmita);
            }
            switch (sabor_marmita){ //Menu de opções para o sabor da marmita
                case 1:
                    printf ("Sabor escolhido: Arroz e feijao\n");
                    printf("\n");
                break;
                case 2:
                    printf ("Sabor escolhido: Strogonoff\n");
                    printf("\n");
                break;
                case 3:
                    printf ("Sabor escolhido: Churrasco\n");
                    printf("\n");
                break;
                case 4:
                    printf ("Sabor escolhido: Macarrao\n");
                    printf("\n");
                break;
                default:
                    printf ("Opcao invalida!\n");
                    printf ("Reinicie o programa e digite uma opcao valida!\n");
                    printf("\n");
            }

            printf ("-------------------------------\n");
            printf ("Deseja continuar cadastrando?\n1 - Sim\n0 - Nao \n"); //Código que define se o usuário quer ou não contnuar o registro, sendo possível regsitrar o quanto quiser (menu)
            scanf ("%d", &vari_continua_registro);
            printf ("Sua opcao: %d\n", vari_continua_registro);
            system ("cls || clear"); //Função que permite que a tela seja limpa tanto no sistema iOS quanto no Windows
            if (vari_continua_registro != 1){
                system("cls || clear"); //Função que permite limpar a tela do compilador tanto no sistema iOS quanto no Windows
                //menu();
            }
            printf ("-------------------------------\n");
        }while (vari_continua_registro==1);

     fclose (arq_pedidos);
    }
}



void del_fornecedor() { //Funcao para deletar fornecedores
    FILE *excluir_fornecedor;
   excluir_fornecedor = fopen("exc_fornecedor.txt", "at");
   fclose (excluir_fornecedor);
    excluir_fornecedor = fopen("exc_fornecedor.txt", "a");
    FILE *arq_fornecedores;
    arq_fornecedores = fopen ("fornecedores.txt", "r"); //Arqivo ja existente

    char forn [1000]; //Variavel que le todas as strings do arquivo fornecedores
    char variExcluir[1000]; //Variavel que le o fornecedor que o usuario deseja excluir
    char str[1000]; //Esta variavel e usada para ler todo o arquivo dos fornecedores
    int contFornecedor; //Contador que verifica se o existem fornecedores cadastrados no arquivo dos fornecedores

    printf ("(Caso seja digitado um fornecedor inexistente nenhum fornecedor sera excluido)\n");
    printf ("----------------------------------------------------------------------------\n");
    printf ("Lista de fornecedores ja cadastrados: \n");
    while (fgets(forn, sizeof (forn), arq_fornecedores) != NULL){
        contFornecedor = contFornecedor + 1;
        fputs (forn, stdout);
    }
    fclose (arq_fornecedores);
    if (contFornecedor == 0){
         printf ("\n");
        printf ("Nenhum fornecedor cadastrado!\n");
        getchar ();
        system ("cls || clear");
        return;
    }

    arq_fornecedores = fopen ("fornecedores.txt", "r");
    printf ("\nDigite o fornecedor que deseja excluir: ");
    scanf ("%s", &variExcluir);
    fflush(stdin);

    while (fscanf (arq_fornecedores, "%s", str)!= EOF){
        if (strcmp(str, variExcluir) != 0){
            fprintf(excluir_fornecedor, "%s\n", str);
        }
    }

    printf ("Fornecedor excluido!\n");
    printf ("Digite para continuar...\n");
    getchar();
    system("cls || clear");
    fclose(excluir_fornecedor);
    fclose (arq_fornecedores);

    remove ("fornecedores.txt");
    rename ("exc_fornecedor.txt", "fornecedores.txt");
}




void consultarPedido(){ //Funcao para consultar o pedido
    int variSeuPedido;
    char nomeAlunoConsulta[100];
    int cont;
    cont = 0;
    char nomeLerPedidos[100];
    int horaLerPedido;
    int minutosLerPedido;
    int tamanhoLerPedido;
    int saborLerPedido;

     FILE *arq_pedidos;
     arq_pedidos = fopen ("pedido.txt", "r"); //Abrindo o arquivo dos pedidos

            printf ("Pedidos: \n");
            printf ("--------------------------------------------------------\n");
        while ((fscanf (arq_pedidos, "%s", &nomeLerPedidos)) != EOF){
            cont = cont + 1;
            fscanf (arq_pedidos, "%d", &horaLerPedido);
            fscanf(arq_pedidos, "%d", &minutosLerPedido);
            fscanf (arq_pedidos, "%d", &tamanhoLerPedido);
            fscanf (arq_pedidos, "%d", &saborLerPedido);
            printf ("\n");

            printf ("Nome do aluno: %s\n", nomeLerPedidos);
            printf ("Hora do pedido: %d hora(s)\n", horaLerPedido);
            printf ("Minutos do pedido: %d minuto(s)\n", minutosLerPedido);
            printf ("Tamanho da marmita: %d\n", tamanhoLerPedido);
            printf ("Sabor da marmita: %d\n", saborLerPedido);
        }
        printf ("--------------------------------------------------------\n");
        printf ("Quantida de pedidos feitos: %d\n", cont);
        printf ("--------------------------------------------------------\n");
           if (cont == 0){
                printf ("Nenhum pedido foi feito ainda...\n");
                getchar ();
                system ("cls || clear");
            }
            getchar();
            system("cls || clear");
    }



void gerarRelatorio(){ //Funcao que gera o relatorio de pedidos
    FILE *arq_pedidos;
    arq_pedidos = fopen("pedido.txt", "r"); //Abrindo o arquivo de pedidos

    char nomeRelatorio[100];
    int horaRelatorio;
    int minutosRelatorio;
    int tamanhoRelatorio;
    int saborRelatorio;
    int contControlaRelatorio; //Contador que verifica se existem pedidos feitos ou nao
    contControlaRelatorio = 0;

    int contRelatorio; //Le cada linha do arquivo dos pedidos
    contRelatorio = 0;
    //Contadores usados para informar quantas vezes cada pedido foi feito:
    int contPedido1;
    contPedido1 = 0;
    int contPedido2;
    contPedido2 = 0;
    int contPedido3;
    contPedido3 = 0;
    int contPedido4;
    contPedido4 = 0;
    //Variaveis que sao usadas para armazenar o valor obtido pela divisao que informara  a porcentagem de vezes que cada sabor foi pedido
    float variDivisao1;
    float variDivisao2;
    float variDivisao3;
    float variDivisao4;
    //Contadores usados para o calculo da porcentagem de vezes que cada sabor foi pedido:
    int contDivizao1;
    contDivizao1 = 0;
    int contDivizao2;
    contDivizao2 = 0;
    int contDivizao3;
    contDivizao3 = 0;
    int contDivizao4;
    contDivizao4 = 0;

    printf ("Pedidos feitos: \n\n");
    while ((fscanf (arq_pedidos, "%s", &nomeRelatorio)) != EOF){
        contControlaRelatorio = contControlaRelatorio + 1;
        fscanf (arq_pedidos, "%d", &horaRelatorio);
        contControlaRelatorio = contControlaRelatorio + 1;
        fscanf (arq_pedidos, "%d", &minutosRelatorio);
        contControlaRelatorio = contControlaRelatorio + 1;
        fscanf (arq_pedidos, "%d", &tamanhoRelatorio);
        contControlaRelatorio = contControlaRelatorio + 1;
        fscanf (arq_pedidos, "%d", &saborRelatorio);
        contControlaRelatorio = contControlaRelatorio + 1;
        contRelatorio = contRelatorio + 1;
        }
        if (saborRelatorio == 1){
             contPedido1 = contPedido1 + 1;
        }else if (saborRelatorio  == 2){
            contPedido2 = contPedido2 + 1;
        }else if (saborRelatorio   == 3){
            contPedido3 = contPedido3+ 1;
        }else if (saborRelatorio  == 4){
            contPedido4 = contPedido4 + 1;
        }

        if (contControlaRelatorio == 0){
            printf ("Nenhum pedido foi feito ainda...\n");
            getchar();
            system ("cls || clear");
        }else {
        variDivisao1 = (float) contPedido1 / contRelatorio;
        variDivisao2 = (float) contPedido2 / contRelatorio;
        variDivisao3 = (float) contPedido3 / contRelatorio;
        variDivisao4 = (float) contPedido4 / contRelatorio;

        printf ("Arroz e feijao: %d veze(s)\n", contPedido1);
        printf ("Foi pedido %.2f%% das vezes\n", variDivisao1);
        printf ("--------------------------------------------------------\n");
        printf ("Strogonoff: %d veze(s)\n", contPedido2);
        printf ("Foi pedido %.2f%% das vezes\n", variDivisao2);
        printf ("--------------------------------------------------------\n");
        printf ("Churrasco: %d veze(s)\n", contPedido3);
        printf ("Foi pedido %.2f%% das vezes\n", variDivisao3);
        printf ("--------------------------------------------------------\n");
        printf ("Macarrao: %d veze(s)\n", contPedido4);
        printf ("Foi pedido %.2f%% das vezes\n", variDivisao4);
        printf ("--------------------------------------------------------\n");
        printf ("Quantidade de pedidos feitos: %d\n", contRelatorio);
        getchar ();
        system("cls || clear");
        }
}



void removeLinha (char texto[]){ //Funcao para remover o \n da funcao fgets
    texto[strcspn(texto, "\n")] = 0;
}
