#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct macro
{
    char name[20];
    char value[100];
};

int main(int argc, char **argv)
{
    if(argc != 2)
    {
        printf("Usage: ./mypreprocessor filename.c\n");
        return 0;
    }

    FILE *fp = fopen(argv[1], "r");
    FILE *fpw = fopen("input.i", "w");

    if(fp == NULL)
    {
        printf("File not exist\n");
        return 1;
    }

    if(fpw == NULL)
    {
        printf("Output file not created\n");
        fclose(fp);
        return 1;
    }

    struct macro m[20];
    int count = 0;

    char s[200];
    char temp[200];

    while(fgets(s, sizeof(s), fp) != NULL)
    {
       
        if(strncmp(s, "#define", 7) == 0)
        {
           
            if(strstr(s, "(") == NULL)
            {
                sscanf(s, "#define %s %s",
                       m[count].name,
                       m[count].value);

                count++;
            }

            else
            {
                char name[20];
                char argument[20];
                char value[100];

                sscanf(s, "#define %[^ (](%[^)]) %[^\n]",
                       name, argument, value);

                strcpy(m[count].name, name);

              
                sprintf(m[count].value, "%s %s",
                        argument, value);

                count++;
            }

        
            continue;
        }

        strcpy(temp, s);

       
        for(int i = 0; i < count; i++)
        {
            char *p;

           
            p = strstr(temp, m[i].name);

            if(p != NULL)
            {
                char result[200];

               
                
                int pos = p - temp;

                strncpy(result, temp, pos);
                result[pos] = '\0';

            
                strcat(result, m[i].value);

                
                strcat(result,
                       p + strlen(m[i].name));

                strcpy(temp, result);
            }
        }

        fputs(temp, fpw);
    }

    fclose(fp);
    fclose(fpw);

    return 0;
}