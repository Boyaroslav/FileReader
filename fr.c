#include<stdio.h>
#include<unistd.h>
#include<wchar.h>
#include<locale.h>
#include<stdlib.h>
#define SPEED 10000

FILE* text;

char cyan[]= "\033[0;36m";
char lime[] = "\033[1;32m";
char green[] = "\033[0;32m";



int main(int argc, char **argv){
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
            printf("%lc", i);
            fflush(stdout);
            usleep(SPEED);
        }
        putchar('\n');
        fclose(text);
        return EXIT_SUCCESS;
    }
    

}
