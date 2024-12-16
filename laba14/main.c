#include <stdio.h>

enum states{
    UP_DOWN,
    DOWN_UP
};

int main() {
    int n;

    printf("Введите размер матрицы (n <= 7): ");
    scanf("%d", &n);

    int matrix[n][n];
    int ans[n * n];

    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            scanf("%d", &matrix[i][j]);
        }
         
    }
    

    int i=0, j=n-1, cur=0, len=n, next[2] = {0, 0};
    enum states state = DOWN_UP;
    while (cur < n * n){
        if (state==DOWN_UP){

            for (int k=0; k < len; k++){
                ans[cur] = matrix[i][j];  
                cur++;
                if (k == len-1)
                    break;
                i++;
                j--;
            }
            if (i == n - 1 && j == 0){  // запоминаем где начать сверху вниз первый раз
                next[0] = i;
                next[1] = j + 1;
            }
            len--;
            i--;
            for (int k=0; k < len; k++){
                ans[cur] = matrix[i][j];
                cur++;
                if (k == len-1)
                    break;
                i--;
                j++;
            }
            if (i == 0 && j ==0){
                if (n % 2 == 0){
                    ans[cur] = matrix[next[0]][next[1]];
                }

                break;
            }
            int i_next=i, j_next=j-1;
            i=next[0];
            j=next[1];
            next[0] = i_next;
            next[1] = j_next;
            state=UP_DOWN;

        }
    
        if (state == UP_DOWN){  
            for (int k=0; k < len; k++){
                ans[cur] = matrix[i][j];
                cur++;
                if (k == len-1)
                    break;
                i--;
                j++;
            }
            len--;
            i++;
            for (int k=0; k < len; k++){
                ans[cur] = matrix[i][j];
                cur++;
                if (k == len-1)
                    break;
                i++;
                j--;
            }


            if (i == n-1 && j == n-1){
                if (n % 2 != 0){
                    ans[cur] = matrix[next[0]][next[1]];
                }

                break;
            }
            int i_next=i, j_next=j+1;
            i=next[0];
            j=next[1];
            next[0] = i_next;
            next[1] = j_next;
            state=DOWN_UP;
        }
    }

    
    for (int l=0; l < n*n; ++l){
        printf("%d ", ans[l]);
    }

    return 0;
}