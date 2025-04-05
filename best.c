#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <ncurses.h>

#define MAX_WORDS 100
#define MAX_WORD_SIZE 20

char** load_words(const char* filename, int* words_count) {
    FILE* file = fopen(filename, "r");
    if (file == NULL || file  < 1) {
        return EXIT_FAILURE;
    }
    //É um ponteiro para um ponteiro. Temos um ponteiro para cada string e um pointeiro para uma lista de string
    char **words  = (char**) malloc(MAX_WORDS * sizeof(char*));
    if (words == NULL) {
        return NULL;
    }
    char buffer[MAX_WORD_SIZE];
    //fgets le um arquivo linha por linha. recebe a variavel que ira armazenar, o tamanho max da linha e o arquivo
        while (fgets(buffer, MAX_WORD_SIZE, file))
        {
            //troca o \n por \0 (desliga os bits)
            buffer[strcspn(buffer, "\n")] = "\0";
            //verifica se não tem mais nada na linha, como uma linha em branco
            if(strlen(buffer) == 0) {
                continue;
            }
            words[*words_count] = malloc(strlen(buffer) + 1);
            //copia o buffer para a lista de words
            strcpy(words[*words_count], buffer);
            //vai na memoria e incremnta
            (*words_count)++;
        }
        fclose(file);
        
}

char *random_word(const char** words, int count) {
    //% necessariamente volta um valor menor que o divisor
    return words[rand() % count];
}
 
int main() {
    initscr();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);
    curs_set(0);
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK);
    init_pair(3, COLOR_GREEN, COLOR_BLACK);


    int words_count = 0;
    char **words = load_words("palavras.txt", &words_count); 
    int exitGame = 0;
    while (!exitGame)
    {
        char* word = random_word(words, words_count);
    }
    
    return 0;
}