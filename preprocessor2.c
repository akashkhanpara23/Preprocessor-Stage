#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    FILE *fp = fopen("myprog.c","r");
    char ch;
    int i = 0, size = 0, bl = 0, c = 0, j = 0, k = 0;

    if(fp == NULL){
        puts("file doesn't exits in the current directory");
        return;
    }

    while((ch = fgetc(fp)) != -1){
        size++;
        c++;
        if(ch == '\n'){
            if(bl < size)
            bl = size;

            size = 0;
        }
    }
    rewind(fp);

    char *buf =(char *)malloc((c+1)*sizeof(char));
    char *buf1 = (char *)malloc((bl+1)*sizeof(char));

    FILE *fs = fopen("temp.txt","w");
    char r[20] = "#define", *p, m2[20], n2[20];

    while(fgets(buf1,bl,fp) != NULL){
        if((p = strstr(buf1,r)) != NULL){
            i = 0;
            while(buf1[i++]){
                if(buf1[i++] == ' '){
                    j = 0;
                    
                    while((buf1[i] != ' ')&&(buf1[i] != ' '))
                    m2[j++] = buf1[i++];
                    m2[j] = '\0';

                    printf("%s\n",m2);
                    if(buf1[i] = ' '){
                        j = 0;
                        int k = 0;

                        while((buf1[i++] != '\n')&&(buf1[i] != '\n'))
                        n2[k++] = buf1[i];
                        n2[k] = '\0';

                        printf("%s\n",n2);
                    }
                }
            }
        }
        else
        fputs(buf1, fs);
    }
    fclose(fs);

    fs = fopen("temp.txt","r");
    i = 0;

    while((ch = fgetc(fs)) != -1)
    buf[i++] = ch;
    buf[i] = '\0';

    fclose(fp);
    //fp = fopen("myprog.c","w");

    int l = strlen(m2), flag1 = 0, flag2 = 0;
    char * stop, temp;

    i = 0;
    FILE *fd = fopen("hey.c","w");

    while((stop = strstr(buf+i,m2)) != NULL){
        for(j = stop-buf; i < j; i++)
        fputc(buf[i], fd);

        j = j - 1;
        i = i+strlen(m2);
        flag1 = ((j == 1)||(buf[j] == ' ')||(buf[j] == '\n')||(buf[j] == '.')||(buf[j] == ','));
        flag2 = ((buf[i] == ' ')||(buf[i] == ',')||(buf[i] == ';'));

        if(flag1 && flag2){
            fputs(n2,fd);
        }
    }
    for(;buf[i];i++)
    fputc(buf[i],fd);

    fclose(fd);
}
