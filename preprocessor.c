#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char *argv[]){
    FILE *fs = fopen("myprog.c","r");

    if(fs == NULL){
        puts("file doesn't exits in the current directory");
        return;
    }

    char ch, ch1;
    int i = 0, ct = 0, ll = 0, c = 0, a = 0, b = 0;

    while((ch = fgetc(fs)) != EOF){
        ct ++;
        c++;
        if(ch == '\n'){
            if(ll < c)
            ll = c;

            c = 0;
        }
    }
    rewind(fs);

    char *buf1[40], *buf2[100], *buf =(char *)malloc((ct+1)*sizeof(char));

    for(i=0;(ch = fgetc(fs)) != EOF; i++)
    buf[i] = ch;

    buf[i] = '\0';
    fclose(fs);

    char *stop;
    unsigned int j = 0, k = 0, r = 0;
    i = 0;

    while((stop = strstr(buf+i, "#define")) != NULL){
        j = stop-buf+strlen("#define");

        *(buf1 + r) = (char *)malloc(40);
        if(buf[j] == ' '){
            k=0;
            for(k = 0, j = j+1; (buf[j] != ' ');j++)
            buf1[r][k++] = buf[j];
        }

        buf1[r][k]='\0';
        *(buf2+r) = (char*)malloc(100);
        for(k = 0, j = j+1;(buf[j] != '\n'); j++)
        buf2[r][k++] = buf[j];

        buf2[r][k]='\0';
        i = j;
        r++;
    }

    FILE *fdt, *fh;
    int q = 0;
    while(q < r){
        int z = 0, flag1 = 0, flag2 = 0;
        i = 0;

        fdt = fopen("temp.txt","w");
        if (fdt == NULL) {
            perror("Failed to open temp.txt");
            return 1;
        }
        while((stop = strstr(buf+i,buf1[q])) != NULL){
            for(j = stop-buf;i < j; i++)
            fputc(buf[i], fdt);

            j = j - 1;
            i = i+strlen(buf1[q]);

            flag1 = ((j == -1)||(buf[j] == ' ')||(buf[j] == '\n')||(buf[j] == ',')||(buf[j] == '.')||(buf[j] == '[')||(buf[j] == '('));
            flag2 = ((buf[i] == ' ')||(buf[i] == '\n')||(buf[i] == ',')||(buf[i] == '.')||(buf[i] == ';')||(buf[i] == ')')||(buf[i] == ']'));

            if(flag1 && flag2)
            fputs(buf2[q], fdt);
            else
            fputs(buf1[q], fdt);
        }

        for(;buf[i];i++)
        fputc(buf[i], fdt);
        fclose(fdt);

        if(!(q == r-1)){
            fdt = fopen("temp.txt","r");
            if (fdt == NULL) { 
                perror("Failed to open temp.txt");
                return 1;
            }
            for(z = 0;(ch = fgetc(fdt)) != EOF; z++)
            buf[z] = ch;
            buf[z] = '\0';
            fclose(fdt);
        }
        q++;
    }

    fdt = fopen("temp.txt","r");
    fh = fopen("temp2.txt","w");

        char def[] = "define", def1[8];
    while ((ch = fgetc(fdt)) != EOF) {
        if (ch == '#') {
            fgets(def1, 7, fdt);
            if (strcmp(def1, "define") == 0) {
                while ((ch = fgetc(fdt)) != '\n' && ch != EOF);
            } else {
                fputc(ch, fh);
                fputs(def1, fh);
            }
        } else {
            fputc(ch, fh);
        }
    }

    fclose(fh);
    fclose(fdt);
    fh = fopen("temp2.txt","r"), fdt = fopen("temp.txt","w");
    while((ch = fgetc(fh)) != -1)
    fputc(ch, fdt);
    for (int i = 0; i < r; i++) {
        free(buf1[i]);
        free(buf2[i]);
    }
    fclose(fh);
    fclose(fdt);
    remove("temp.txt");
    remove("temp2.txt");
}
