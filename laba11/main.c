#include <stdio.h>

enum states {
    SEARCH_OF_START,
    WAIT_0_1,
    WAIT_0_2,
    WAIT_END_OF_NUM_1,
    END_OR_SEARCH_START,
    WAIT_01_1,
    WAIT_01_2,
    WAIT_END_OF_NUM_2,
    END_OF_FILE
};

int main(){

    enum states state=SEARCH_OF_START;
    int k=0, c;
    while (state != END_OF_FILE){
        c = getchar();

        if (state == SEARCH_OF_START){
            if (c == '1')
                state = WAIT_0_1;
            else if (c == '0')
                state = WAIT_01_1;
            else if (c == EOF){
                state = END_OF_FILE;
                printf("%d\n", k);
            }
                
        }

        else if (state == WAIT_0_1){
            if (c == '0')
                state = WAIT_0_2;
            else if (c == EOF){
                state = END_OF_FILE;
                printf("%d\n", k);
            }
            else
                state = SEARCH_OF_START;
        
        }

        else if (state == WAIT_0_2){
            if (c == '0')
                state = WAIT_END_OF_NUM_1;
            else if (c == EOF){
                state = END_OF_FILE;
                printf("%d\n", k);
            }
            else
                state = SEARCH_OF_START;
        }

        else if (state == WAIT_END_OF_NUM_1){
            if (c == '0' || c == '1')
                state = END_OR_SEARCH_START;
            else if (c == EOF){
                state = END_OF_FILE;
                printf("%d\n", k);
            }
            else
                state = SEARCH_OF_START;
            
        }
        else if (state == END_OR_SEARCH_START){
            if (c == '1')
                state = WAIT_0_1;
            else if (c == '0')
                state = WAIT_01_1;
            else if (c == EOF){
                k++;
                state = END_OF_FILE;
                printf("%d\n", k);
            }
            else{
                k++;
                state = SEARCH_OF_START;
            }
        }
        else if (state == WAIT_01_1){
            if (c == '0' || c == '1')
                state = WAIT_01_2;
            else if (c == EOF){
                state = END_OF_FILE;
                printf("%d\n", k);
            }
            else
                state = SEARCH_OF_START;
        }
        else if (state == WAIT_01_2){
            if (c == '0' || c == '1')
                state =  WAIT_END_OF_NUM_2;
            else if (c == EOF){
                state = END_OF_FILE;
                printf("%d\n", k);
            }
            else
                state = SEARCH_OF_START;
   
        }
        else if (state == WAIT_END_OF_NUM_2){
            if (c == '0' || c == '1')
                state = END_OR_SEARCH_START;
            else if (c == EOF){
                state = END_OF_FILE;
                printf("%d\n", k);
            }
            else
                state = SEARCH_OF_START;

        }
    }

    return 0;
}