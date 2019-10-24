#include <stdio.h>
#include <string.h>

int potencia(int a,int b){/*mesma coisa que pow, mas como não podia usar o math.h tive que fazer pra isso aqui pra deixar o código legivel*/
    if(b==0)
    {
        return 1;
    }else
    {
        while(b>1)
        {
            a=a*a;
            b--;
        }
        return a;
    }
}

int main()
{
    int numeroDeLinhas,tamanhoString,numeros[100],charToNumber[100],i = 0;
    char letras[100],linha[100];
    scanf("%d",&numeroDeLinhas);
    while(i<numeroDeLinhas)
    {
        int z,x,y,w,contador=0,numero=0,tamanhoNumeros=0;
        scanf("%s",linha);
        tamanhoString=strlen(linha);
        z=0;
        while (z<tamanhoString)/*procura letras*/
        {
            
            if(linha[z]>='A'&&z<tamanhoString)
            {
                letras[contador]=linha[z];
                contador++;
            }
            z++;
        }/*fim procura letras*/
        z=0;
        w=0;
        while (z<tamanhoString)/*procura e transforma numeros*/
        {
            contador=0;
            if(linha[z]<'A')/*checa se é numero*/
            {
                
                while (linha[z]<'A'&&z<tamanhoString)
                {
                    charToNumber[contador]=linha[z]-'0';/*sepera algarismos para conversão*/
                    z++;
                    contador++;
                }
                x=0;
                y=contador-1;
                while (y>=0)
                {
                    numero+=charToNumber[y]*potencia(10,x);
                    x++;
                    y--;
                }
                numeros[w]=numero;
                numero=0;
                tamanhoNumeros++;
                w++;
                
            }
            z++;
        }
        w=0;
        
        while(w<tamanhoNumeros)
        {
            z=0;

            while(z<numeros[w]){
                printf("%c",letras[w]);
                z++;
            }
            
            w++;
        }
        printf("\n");
        i++;
    }
        
    
   
        

    



    return 0;
}
    




