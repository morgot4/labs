#include <stdio.h>
#include <stdint.h>
#include <ctype.h>
#include <locale.h>
#include <wchar.h>


#define CYR_YA 1071 // Я
#define CYR_ya 1103

#define CYR_E 1045 // Е
#define CYR_e 1077

#define CYR_EO 1025 // Ё
#define CYR_eo 1105

#define CYR_U 1070 // Ю
#define CYR_u 1102

//=================================

#define CYR_A 1040 // A
#define CYR_a 1072

#define CYR_O 1054 // O
#define CYR_o 1086

#define CYR_Y 1059 // У
#define CYR_y 1091

#define CYR_I 1048 // И
#define CYR_i 1080

#define CYR_EE 1069 // Э
#define CYR_ee 1101

#define CYR_EI 1067 // Ы
#define CYR_ei 1099


#define SET_BIT(set, idx)   ((set) |= (1ULL << (idx)))


void printBinary(uint64_t num) {
    for (int i = sizeof(uint64_t) * 8 - 1; i >= 0; i--) {
        printf("%lu", (num >> i) & 1);
    }
    printf("\n");
}


int getUnicode(int c) {
    if (c != EOF && c < 128){
        return c;
    }

    else if ((c & 0xE0) == 0xC0){
        int c2 = getchar();
        int unicode = ((c & 0x1F) << 6) | (c2 & 0x3F);
        return unicode;

    }
    return -1;

}

int getIndex(int c){
    //printf("%d\n", c);
    if (c >= CYR_A && c <= CYR_YA){
        if (c - CYR_A > 6){
            return (c - CYR_A) + 1;
        }
        return c - CYR_A;
    }
    else if (c >= CYR_a && c <= CYR_ya){
        if (c - CYR_a > 6){
            return (c - CYR_a) + 1;
        }   
        return c - CYR_a;
    }
    else if (c == CYR_EO || c == CYR_eo){
        return 6;
    }
    return -1;
}

uint64_t generateCorrectMask(){
    uint64_t bitSet = 0;
    SET_BIT(bitSet, getIndex(CYR_EO));
    SET_BIT(bitSet, getIndex(CYR_E));
    SET_BIT(bitSet, getIndex(CYR_YA));
    SET_BIT(bitSet, getIndex(CYR_U));
    return bitSet;
    
}

uint64_t generateInCorrectMask(){
    uint64_t bitSet = 0;
    SET_BIT(bitSet, getIndex(CYR_A));
    SET_BIT(bitSet, getIndex(CYR_O));
    SET_BIT(bitSet, getIndex(CYR_Y));
    SET_BIT(bitSet, getIndex(CYR_EE));
    SET_BIT(bitSet, getIndex(CYR_I));
    SET_BIT(bitSet, getIndex(CYR_EI));
    return bitSet;
    
}

enum states{
    IN_WORD,
    OUT_WORD
};

int isSep(int c){
    return (c == ' ' || c == '\t' || c == '\n' || c == ',');
}

int main() {
    int c, ans=0;
    uint64_t maskSecond = generateCorrectMask();
    uint64_t maskFirst = generateInCorrectMask();
    uint64_t bitSet = 0;

    enum states state = OUT_WORD;
    while ((c = getUnicode(getchar())) != EOF){

        if (state == OUT_WORD){
            if (!isSep(c)){
                state = IN_WORD;
                SET_BIT(bitSet, getIndex(c));

            }
                
        }
        if (state == IN_WORD){

            if (isSep(c)){
                if ((bitSet & maskFirst) == 0 && (bitSet & maskSecond) != 0)
                    ans++;
                bitSet = 0;
                state = OUT_WORD;
            }
            else{
                SET_BIT(bitSet, getIndex(c));
            }
        }

        
    }
    
    printf("%d\n", ans);

    return 0;
}
