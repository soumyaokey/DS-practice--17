#include <stdio.h>
#include <string.h>
#include <math.h>

int A=2,B=2,C=3,D=16,E=100;

int stack[10];
int top=-1;

int value (char nx) {
    return nx=='A'?A:nx=='B'?B:nx=='C'?C:nx=='D'?D:E;
}

int main (){

    int i, res;

    char postfix[]="ABC^^D*E-";
    int sz =strlen (postfix);

    for (i=0; i<sz; i++) {
        char nx = postfix[i];

        if (nx =='+'|| nx == '-'|| nx == '*'|| nx == '/') {
            int b= stack[top--];
            int a= stack[top--];
            switch (nx) {
                case '+': res = a + b; break;
                case '-': res = a - b; break;
                case '*': res = a * b; break;
                case '/': res = a / b; break;
            }
            stack[++top] = res;
        } else {
            stack[++top] = value(nx);
        }
    }
    printf ("%d\n", stack[top]);
    return 0;
}