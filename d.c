#include <stdio.h>
#include <string.h>
#include <math.h>

int A=80, B=4, C=9, D=16, E=25;

int stack[10];
int top=-1;

int value (char nx) {
    return nx=='A'?A:nx=='B'?B:nx=='C'?C:nx=='D'?D:nx=='E'?E:0;
}

int main (){

    int i, res;

    char postfix[]="AB-CD*Z^EFG^^/";
    int sz =strlen (postfix);

    for (i=0; i<sz; i++) {
        char nx = postfix[i];

        if (nx =='+'|| nx == '-'|| nx == '*'|| nx == '/'|| nx == '^') {
            int b= stack[top--];
            int a= stack[top--];
            switch (nx) {
                case '+': res = a + b; break;
                case '-': res = a - b; break;
                case '*': res = a * b; break;
                case '/': res = a / b; break;
                case '^': res = pow(a, b); break;
            }
            stack[++top] = res;
        } else {
            stack[++top] = value(nx);
        }
    }
    printf ("%d\n", stack[top]);
    return 0;
}