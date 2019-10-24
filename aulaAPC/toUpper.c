#include <stdio.h>
#include <string.h>

void toUpper(char* string){

    int i,length = strlen(string);
    for(i=0;i<length;i++){
        if(string[i]>=97&&string[i]<=122){
            string[i]=string[i]-32;
        }
    }
}

int main(){
    char string[101];
    scanf("%s",string);
    toUpper(string);
    printf("%s\n",string);
    return 0;
}
