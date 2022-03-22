#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int RandBetween(int min, int max)
{
    return min+rand()%(max-min+1);
}

int main()
{
    int count[10]={0};
    char a[4];
    char b[5];

    srand(time(NULL));

    int index=0;
    while( index<=3 ){
        int r=RandBetween(1,9);
        if( count[r]==0 ){
            count[r]=1;
            a[index]='0'+r;
            index++;
        }
    }

    while( 1 ){
        printf("Please guess: ");
        scanf("%s", b);
        int A=0,B=0;

        for(int i=0;i<4;i++)
            for(int j=0;j<4;j++){
                if( a[i]==b[j] ){
                    if( i==j )
                        A++;
                    else
                        B++;
                }
            }

        printf("Your guess is %dA%dB\n",A,B);
        if( A==4 )
            break;

    }

    return 0;
}