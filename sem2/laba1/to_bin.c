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


int main(int argc, char *argv[]){
    if (argc < 3){
        fprintf(stderr, "где файлы?");
        return -1;
    }
    match m;
    FILE* file1 = fopen(argv[1], "rb"); 
    if (file1 == NULL) {
        fprintf(stderr, "Ошибка открытия входного файла\n");
        return -1;
    }
    
    FILE* file2 = fopen(argv[2], "wb");
    if (file2 == NULL) {
        fprintf(stderr, "Ошибка открытия выходного файла\n");
        fclose(file1);
        return -1;
    } 
    
    while(5 == fscanf(file1, "%34[^:]:%34[^:]:%34[^:]:%d:%d", m.team1, m.team2, m.tournament, &m.score1, &m.score2)){
        printf("%s:%s:%s:%d:%d\n", m.team1, m.team2, m.tournament, m.score1, m.score2);
        
        memset(m.team1 + strlen(m.team1), 0, 35 - strlen(m.team1));
        memset(m.team2 + strlen(m.team2), 0, 35 - strlen(m.team2));
        memset(m.tournament + strlen(m.tournament), 0, 35 - strlen(m.tournament));
        
        fwrite(&m, sizeof(match), 1, file2);
    }
    
    fclose(file1);
    fclose(file2);
    
    return 0;
}