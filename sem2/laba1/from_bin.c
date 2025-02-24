#include <stdio.h>

typedef struct
{
    char team1[20];
    char team2[20];
    char tournament[20];
    int score1;
    int score2;
} match;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <binary_file>\n", argv[0]);
        return -1;
    }

    match m;
    FILE* file = fopen(argv[1], "rb");
    if (file == NULL) {
        perror("Failed to open binary file");
        return -1;
    }

    while (fread(&m, sizeof(match), 1, file) == 1) {
        printf("Read: %s:%s:%s:%d:%d\n", m.team1, m.team2, m.tournament, m.score1, m.score2);
    }

    fclose(file);
    return 0;
}