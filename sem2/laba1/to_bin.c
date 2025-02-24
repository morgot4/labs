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

#define FIXED_LENGTH 100

int main(int argc, char *argv[]){
    if (argc < 3){
        fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
        return -1;
    }

    match m;
    FILE* file1 = fopen(argv[1], "r");
    if (file1 == NULL) {
        perror("Failed to open input file");
        return -1;
    }

    FILE* file2 = fopen(argv[2], "wb");
    if (file2 == NULL) {
        perror("Failed to open output file");
        fclose(file1);
        return -1;
    }

    char buffer[FIXED_LENGTH];
    while(5 == fscanf(file1, "%34[^:]:%34[^:]:%34[^:]:%d:%d", m.team1, m.team2, m.tournament, &m.score1, &m.score2)){
  
        fwrite(&m, sizeof(match), 1, file2);
    
        printf("Written: %s:%s:%s:%d:%d\n", m.team1, m.team2, m.tournament, m.score1, m.score2);
    }

    fclose(file1);
    fclose(file2);

    return 0;
}