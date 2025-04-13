#include <stdio.h>
#include <string.h>

typedef struct Command{
    char name[16];
    char description[64];
    double (*func) (double, double);
} Command;

double add(double x, double y){return x+y;}
double min(double x, double y){return x-y;}
double mult(double x, double y){return x*y;}
double div(double x, double y){return x/y;}

void show_help(Command* commands, int size) {
    
    for (int i = 0; i < size; i++) {
        fprintf(stderr, "> %s - %s\n", commands[i].name, commands[i].description);
    }
    printf("> help - Print \n");
    printf("> exit - \n");
}


void StartCalculator()
{
    Command commands[] = {
        {"add", "sum 2 values", add},
        {"sub", "1st value minus 2nd value", min},
        {"mult", "1st value multiplication on 2nd value ", mult},
        {"div", "1st value devided by 2nd value", div}
    };
    int N = sizeof(commands) / sizeof(Command);
    show_help(commands, N);

    int statusExit = -1;
    char option[16];
    memset(option, '\0', sizeof(option));
    double a, b;

    while(statusExit != 1)
    {
        fprintf(stderr, "Enter command: ");
        scanf("%s", option);

        if(strcmp(option, "exit") == 0){
            statusExit = 1;
            break;
        }
        if(strcmp(option, "help") == 0){
            show_help(commands, N);
            continue;;
        }
        
        printf("Enter two real numbers:\n");
        scanf("%lf %lf", &a, &b);
        for(int i = 0; i < N; i++){
            if(strcmp(option, commands[i].name) == 0){
                double res = commands[i].func(a,b);
                fprintf(stderr, "Result: %lf\n", res);
            }
        }
        memset(option, '\0', sizeof(option));
    }
    return;
}
int main()
{
    StartCalculator();
}