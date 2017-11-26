#include<stdio.h>

int mul(int b)
{
return(b*2);
}

int main()
{
int a=4;
printf("%d\n", a=mul(2) );
a=mul(a=mul(a=mul(4)));
printf("\n %d",a);
return 0;
}
