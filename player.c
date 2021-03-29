#include <stdio.h>
#include <stdlib.h>

#include "player.h"

struct elemento{

    struct musica dados; // os dados que serão armazenados na lista do tipo struct musica

    struct elemento *proximo; // um ponteiro para o proximo elemento da lista
};

// renomeação do tipo elemento para simplificar/ facilitar algumas operações
typedef struct elemento Elem;


/*
   IMPLEMENTANDO AS FUNÇÕES
*/

Playlist* cria_lista(void){

    // cria o primeiro elemento da lista e aloca ele na memória
    Playlist* inicioLista = (Playlist*)malloc(sizeof(Playlist));  

    // se deu certo (lista criada)
    if(inicioLista != NULL){

        // primeiro elemento recebe nulo
        *inicioLista = NULL;
    }

    printf("\n|  Playlist criada  |\n\n"); // printa a confirmação da lista criada
    return inicioLista;  // função tipo ponteiro (Playlist) retorna inicio lista
    
}

void libera_lista(Playlist* inicioLista){

    // se a lista existir
    if(inicioLista != NULL){

        // cria o elemento auxiliar
        Elem* aux;

        // enquanto tiver elemento na lista
        while(*inicioLista != NULL){

            // auxiliar recebe o inicio da lista
            aux = *inicioLista;

            // o primeiro elemento da lista passa a receber o próximo
            *inicioLista = (*inicioLista)->proximo;

            // libera o elemento auxiliar
            free(aux);
        }
        printf("\nlista liberada\n\n"); // printa a confirmação da lista liberada

        // libera lista   
        free(inicioLista);  
    }  

}

int tamanho_lista(Playlist* inicioLista){

    // variável contadora
    int cont = 0;

    // cria elemento auxiliar
    Elem* aux = *inicioLista;

    // enquanto não chegar ao final da lista
    while(aux != NULL){

        // incrementa o contador
        cont ++;

        // pula para o próximo elemento
        aux = aux->proximo;
    }
    return cont; // função tipo (int) retorna o contador
}

int inserir(Playlist* inicioLista, struct musica music){

    if(inicioLista == NULL) return 0; // lista existe?

    //cria um novo (NO), realoca memoria para ele. 
    Elem* no = (Elem*)malloc(sizeof(Elem));

    // verifica se conseguiu alocar
    if(no == NULL) return 0; // no existe?

    //copia os dados que eu quero inserir para esse (NO)
    no->dados = music;
    no->proximo = NULL; // inserçao no final, então o proximo após o (NO) será nulo.

    if((*inicioLista)== NULL){ // lista vazia?
        *inicioLista = no; // se lista vazia, insere no inicio
    }else{
        // cria elemento auxiliar recebendo o inicio da lista
        Elem* aux = *inicioLista;

        // percorre a lista até encontrar o ultimo elemento utilizando o elemento auxiliar percorrer (não utilize o inicio da lista)
        while(aux->proximo != NULL){
            aux = aux->proximo;
        }
        // chegou ao final da lista, proximo elemento = nulo, então insere o (NO) no final
        aux->proximo = no;

    }    
    
    // mostrar a música que foi inserida
    printf("\nA música: %sfoi adicionada a Playlist\n\n", no->dados.nome);

    return 1;
}

int remover(Playlist* inicioLista){

    if(inicioLista == NULL)  return 0; // se lista não existe       
    if(*inicioLista == NULL)  return 0;// se o conteúdo do inicio ad lista aponta para nulo, então a lista está vazia       

    // se passou nos IFs acima, então tem conteudo na lista
    // cria elemento auxiliar e recebe o valor do inicio da lista
    Elem *aux = *inicioLista;

    // o inicio da lista aponta para o elemento seguinte ao elemento auxiliar (se o próximo for nulo, então a lista fica vazia)
    *inicioLista = aux->proximo;

    // imprime qual musica foi removida
    printf("\nA música: %sfoi excluida da Playlist!\n\n", aux->dados.nome);

    // libera o elemento auxiliar (foi excluido)
    free(aux);    

    return 1;
}

void imprime_lista(Playlist* inicioLista){ 

    // se a lista for vazia 
    if(*inicioLista == NULL){
        printf("\nPlaylist vazia\n\n");// imprime lista vazia
    }else{// se não

      // cria o elemento auxiliar recebendo o inicio da lista
      Elem* aux = *inicioLista;

      // mostra o tamanho da lista
      printf("\nA Playlist tem %d músicas\n", tamanho_lista(inicioLista));

      // enquanto não chegar ao final
      while(aux != NULL){
        
          // imprime os elementos da lista
          printf("-------------------------------\n");
          printf("Musica: %s\n",aux->dados.nome);
          printf("Artista/Banda: %s\n",aux->dados.artista);
          printf("duracao: %.2f min\n",aux->dados.duracao);
          //printf("-------------------------------\n");

          // percorre os elementos da lista
          aux = aux->proximo;
          
      }
  }    
}