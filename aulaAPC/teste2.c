#include <stdio.h>

int main (){
    int Nlinhas, check, i, x, j, y, cL, X, tamanho, numLetra[1000];
    char str[1000], vetorLetra[1000], strResposta[1000];
    scanf("%d", &Nlinhas);
    i=0;
    X=0;
    check=0;
    while(i<Nlinhas){
        scanf("%s[^\n]", str);
        tamanho=0;
        x=0;
        while(str[x]!='\0'){
            tamanho++;
            x++;
        }
        x=0;
        j=0;
        cL=0;
        while(x<tamanho){
            if((int)str[x]<'A'){
                if (check>0){
                    numLetra[cL-1]=(int)str[x]+numLetra[cL-1]*10-48;
                    check++;
                }
                else{
                    numLetra[cL]=((int)str[x])-48;
                    check++;
                    cL++;
                }
            }
            else{
                check=0;
                vetorLetra[j]=str[x];
                j++;
            }
            x++;
        }
        y=0;
        while(y<=j){
            x=0;
            while(x<numLetra[y]){
                if (vetorLetra[y]<='z' || vetorLetra[y]>='0')
                {
                    strResposta[X]=vetorLetra[y];
                    X++;
                    x++;
                }
            }
            y++;
        }
        strResposta[X]='\n';
        X++;
        i++;
        x=0;
        while(x<=j){
            numLetra[x]=0;
            vetorLetra[x]=0;
            x++;
        }
    }
    i=0;
    while(i<X){
        printf("%c", strResposta[i]);
        i++;
    }
    return 0;
}
