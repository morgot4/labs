#include <stdio.h>
#include <stdint.h>
#include <ctype.h>

// yoa - Первый род
// eiu - второй род

#define SET_BIT(set, idx)   ((set) |= (1ULL << (idx)))


int getIndex(int c){
    if (c >= 'A' && c <= 'Z'){
        return c - 'A';
    }
    else if (c >= 'a' && c <= 'z'){
        return c - 'a';
    }
    return -1;
}

uint64_t generateCorrectMask(){  //маска для 2 рода
    uint64_t bitSet = 0;
    SET_BIT(bitSet, getIndex('e'));
    SET_BIT(bitSet, getIndex('i'));
    SET_BIT(bitSet, getIndex('u'));
    return bitSet;
    
}

uint64_t generateInCorrectMask(){ // маска для 1 рода
    uint64_t bitSet = 0;
    SET_BIT(bitSet, getIndex('y'));
    SET_BIT(bitSet, getIndex('o'));
    SET_BIT(bitSet, getIndex('a'));
    return bitSet;
    
}

//0100000000100000000000001


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
    while ((c = getchar()) != EOF){

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
    if (state == IN_WORD){
        ans++;
    }
    printf("%d\n", ans);

    return 0;
}
