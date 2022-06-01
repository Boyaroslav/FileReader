#include<stdio.h>
#include<unistd.h>
#include<wchar.h>
#include<locale.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>

#define speed 10000

FILE* text;
int SPEED = speed;

int momental = 0;
int rainbow = 0;
int rainbcol;

char cyan[]= "\033[0;36m";
char lime[] = "\033[1;32m";
char green[] = "\033[0;32m";
char *rainbowcolors[] = {"\x1b[1;31m", "\x1b[1;33m", "\x1b[93;m", "\x1b[1;92m", "\x1b[1;96m", "\x1b[1;94m", "\x1b[1;95m"};

int toint(char *x){
    int n=0, j=0;
    while(x[j] >= '0' && x[j] <= '9'){
        n = (n * 10) + (x[j] - '0'); j++;

    }
    return n;
}

int main(int argc, char **argv){
    for(int i=0; i<argc; i++){
        if(strcmp(argv[i], "-r") == 0){rainbow = 1;}
        if(strcmp(argv[i], "-t") == 0){SPEED = toint(argv[i+1]);}
        if(strcmp(argv[i], "-f") == 0){SPEED = 0; momental = 1;}
    }
    srand(time(NULL)); 
    int ri = 0;
    setlocale(LC_ALL, "");
    text = fopen(argv[1], "r");
    if(text == NULL){
        fprintf(stderr, "\nCan't open file\n");
        return 0;}
    else{
        printf("\n%s%s%s\n", green, argv[1], lime);
        wchar_t i;
        int highlight = 0;
        while((i = fgetwc(text)) != WEOF){
            fflush(text);
            if(rainbow == 0){
                if(highlight > 0 && i != '(' && i != ')' && i != '{' && i != '}'){
                    printf("%s", cyan);
                }
                else{
                    printf("%s", lime);
                }

                if(i == '('  || i == '{'){
                    highlight++;
                }
                if(i == ')' || i == '}'){
                    highlight --;
                }
            }
            else{
                //rainbcol = rand() % 7;
                printf("%s", *(rainbowcolors + ri));
                ri++;
                if(ri > 6){ri=0;}
            }
            printf("%lc", i);
            fflush(stdout);
            if (momental == 0){
                usleep(SPEED);}
        }
        putchar('\n');
        fclose(text);
        return EXIT_SUCCESS;
    }
    

}
