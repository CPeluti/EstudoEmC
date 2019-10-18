#include <stdio.h>

int main(){

    int n, i, j;

    scanf("%d", &n);
    int mat[n][n];

    for(i=0; i<n; i++){
        for(j=0; j<n; j++){

            /* 
            i == 0; i+1;
            i == 1; 2
            j == 0; j+1
            n-i
            n-j 
            */

            if(i+1 <= j+1 && i+1 <= n-i && i+1 <= n-j){
                mat[i][j] = i+1;
                continue;
            }

            else if(j+1 <= i+1 && j+1 <= n-i && j+1 <= n-j){
                mat[i][j] = j+1;
                continue;
            }

            else if(n-i <= i+1 && n-i <= j+1 && n-i <= n-j){
                mat[i][j] = n-i;
                continue;
            }

            else if(n-j <= i+1 && n-j <= j+1 && n-j <= n-i){
                mat[i][j] = n-j;
            }
            
        }
    }

    for(i=0; i<n; i++){
        for(j=0; i<n; j++){

            if(mat[i][j] > 10){
                printf(" %d ", mat[i][j]);
            }
            else{
                printf("  %d ", mat[i][j]);
            }
        }
    }

return 0;
}