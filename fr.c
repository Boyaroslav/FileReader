#include<stdio.h>
#include<unistd.h>
#define SPEED 10000

FILE* text;

char cyan[]= "\033[0;36m";
char lime[] = "\033[1;32m";
char green[] = "\033[0;32m";



int main(int argc, char **argv){

    text = fopen(argv[1], "r");
    if(text == NULL){
        fprintf(stderr, "\nCan't open file\n");
        return 0;}
    else{
        printf("\n%s%s%s\n", green, argv[1], lime);
        char i;
        int highlight = 0;
        i = (char)getc(text);
        while(i != EOF){
            fflush(text);
            if(highlight > 0 && i != '(' && i != ')' && i != '{' && i != '}'){
                printf(cyan);
            }
            else{
                printf(lime);
            }
            printf("%c", i);

            if(i == '('  || i == '{'){
                highlight++;
            }
            if(i == ')' || i == '}'){
                highlight --;
            }

            fflush(stdout);
            usleep(SPEED);
            i = (char)getc(text);
        }
        putchar('\n');
        fclose(text);
        return 0;
    }
    

}