#include <stdio.h>
#include <string.h>

typedef struct
{
    char team1[35];
    char team2[35];
    char tournament[35];
    int score1;
    int score2;
} match;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "где файлы?");
        return -1;
    }

    match m;
    FILE* binFile = fopen(argv[1], "rb");
    if (binFile == NULL) {
        fprintf(stderr, "Ошибка открытия файла\n");
        return -1;
    }
  
    while (1) {
   
        size_t read_count = fread(&m, sizeof(match), 1, binFile);
        
        
        if (read_count < 1) {
            if (feof(binFile)) {
                break; 
            } else {
                fprintf(stderr, "Ошибка чтения файла\n");
                break;
            }
        }
       
        printf("%s:%s:%s:%d:%d\n", 
               m.team1, m.team2, m.tournament, m.score1, m.score2);
    }
    
    fclose(binFile);
    return 0;
}