#include<stdio.h>
int main(int argc,char **argv)
{
    if(argc!=2)
    {
        printf("Usage:./mypreproccessor filename.c\n");
        return 0;
    }
    FILE *fp=fopen(argv[1],"r");
    FILE *fp1=fopen("demo.i","w");
    if(fp==0)
    {
        printf("File not exist\n");
        return 1;
    }
    if(fp1==0)
    {
        printf("File not created successfully\n");
        return 1;
    }
    char ch,next;
    while((ch=fgetc(fp))!=EOF)
    {
        if(ch=='/')
        {
            next=fgetc(fp);
            if(next=='/')
            {
                while((ch=fgetc(fp))!=EOF && ch!='\n')
                {
                    if(ch=='\n')
                    fputc('\n',fp1);
                }
            }
            else if(next== '*')
            {
                while((ch=fgetc(fp))!=EOF)
                {
                    if(ch== '*')
                    {
                        next=fgetc(fp);
                        if(next=='/')
                        break;
                    }
                }
            }
            else
            {
                fputc(ch,fp1);
                if(next!=EOF)
                fputc(next,fp1);
            }
        }
        else
        fputc(ch,fp1);
    }
    fclose(fp);
    fclose(fp1);
}