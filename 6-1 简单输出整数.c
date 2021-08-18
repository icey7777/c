#include <stdio.h>

void PrintN ( int N );

int main ()
{
    int N;

    scanf("%d", &N);
    PrintN( N );

    return 0;
}
void  PrintN ( int N ){
	int i;
	int a=N;
	for(i=1;i<=a;i++){
		printf("%d\n",i);
	}
}
