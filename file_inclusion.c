#include<stdio.h>
#include<string.h>
int main(int argc,char **argv)
{
    if(argc!=2)
    {
        printf("Usage:./mypreporoccesor filname.c\n");
        return 0;
    }
    
    FILE *fp=fopen(argv[1],"r");
    FILE *fpw=fopen("input.i","w");
    if(fp==0)
    {
        printf("File no exist\n");
        return 1;
    }
    
    char s[100],filename[20],s1[100];
    while(fgets(s,sizeof(s),fp)!=NULL)
    {
        if(strncmp(s,"#include",8)==0)
        {
            sscanf(s, "#include \"%[^\"]\"", filename);
            FILE *in=fopen(filename,"r");
            if(in==0)
            {
                printf("File not exist\n");
                fclose(fp);
                fclose(fpw);
                return 1;
            }
            while(fgets(s1,sizeof(s1),in)!=NULL)
            fputs(s1,fpw);
            
            fclose(in);
        }
        else
        fputs(s,fpw);
    }
    fclose(fp);
    fclose(fpw);
}


