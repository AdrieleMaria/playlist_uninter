
// tipo de dado armazenado na lista
struct musica{
    char nome[50];
    char artista[50];
    float duracao;
};

// o ponteiro Playlist
typedef struct elemento* Playlist;

// os prototipos das funçoes
Playlist* cria_lista(void);

void libera_lista(Playlist* inicioLista);

int tamanho_lista(Playlist* inicioLista);

int lista_vazia(Playlist* inicioLista);

int inserir(Playlist* inicioLista, struct musica music);

int remover(Playlist* inicioLista);

void imprime_lista(Playlist* inicioLista);
