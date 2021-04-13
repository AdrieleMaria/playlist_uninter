#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <locale.h> // biblioteca para utilizar acentos
#include "player.h" // arquivo (.h) onde criei os protótipos

int main(void){

    // utilização da biblioteca locale
    setlocale(LC_ALL, "");
    

    Playlist *inicioLista; // iniciolista é um ponteiro para ponteiro para a struct elemento

    // chamada da função cria lista
    inicioLista = cria_lista();

    // declaração da variável music do tipo musica
    struct musica music;

    // variáveis para inserção via teclado
    char nome[50];
    char artista[50];
    float duracao;

    // variáveis auxiliares
    int tmp;
    int opcao;

    // criar menu de visualização 
    do{
        printf("\n--------MENU-------- \n1. Libera Playlist  |\n2. Exibir playlist  |\n");
        printf("3. Adicionar música | \n4. Retirar música   |\n5. Sair             |\n--------------------\nOpção Escolhida: ");

        scanf("%d", &opcao);

        // switch case para escolha das opções do menu
        switch(opcao){
        
        case 1:
            libera_lista(inicioLista); // chamada da função libera lista
            break;

        case 2:
            imprime_lista(inicioLista); // chamada da função imprime lista
            break;

        case 3:

            // limpeza de buffer, inserção dos dados pelo teclado (através de fgets e scanf) e atribuí-los aos dados que serão armazenados na lista (através de strcpy e atribuição de dados para uma struct)

            printf("\nNome da musica: ");
            setbuf(stdin, NULL); 
            fgets( nome, sizeof(nome), stdin);
            strcpy(music.nome, nome);

            printf("\nNome do artista/Banda: ");
            setbuf(stdin, NULL);
            fgets( artista, sizeof(artista), stdin);
            strcpy(music.artista, artista); 

            printf("\nDuracao da musica: ");
            setbuf(stdin, NULL);
            scanf("%f", &duracao);
            music.duracao = duracao;

            inserir(inicioLista, music);// chamada da função inserir 

            break;

        case 4:
            remover(inicioLista);// chamada da função remover

            break;

        case 5:
            break; // caso a opção seja 5, sair do loop

        default:
            printf("\nOpção inválida\n\n"); // se digitar qualquer outra número que não seja os que estão acima, printa opção inválida
            break;
        }

    }while(opcao != 5); // rodar loop até que digite a opção 5

    return 0;
}

