#include <stdio.h>


FILE *rfd,*wfd;
char ch;

void end()
{
    int c=0;
    switch((ch=fgetc(rfd)))
    {
    case '/':
            do
            {
                ch=fgetc(rfd);
                if(ch=='\n')
                    break;
            }while(ch!=EOF);
            ch=fgetc(rfd);
            return;     

    case '*':do
            {
                c++;
                ch=fgetc(rfd);
                if(ch=='*' && (fgetc(rfd))=='/')
                    break;
            }while(ch!=EOF);            
            if(ch==EOF)
                fseek(rfd,-c-1,2);
            ch=fgetc(rfd);
            return;

    default:
        fputc('/',wfd);
        return;
    }
}

int main (int argc,char **argv)
{

    rfd=fopen("read.txt","r");
    wfd=fopen("write.txt","w");

    while((ch=fgetc(rfd))!=EOF)
    {
        if(ch=='/')
                end();

        fputc(ch,wfd);
    }

    printf("\ndone ");
    fflush(stdin);
    getchar();
}   