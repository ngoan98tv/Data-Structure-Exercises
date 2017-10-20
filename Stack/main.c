/* 
 * Author: Ngoan Tran
 *
 */

#include "basicLib_Stack.c"

void convertToBin(){
    int n;
    Stack bin;
    MAKENULL_STACK(&bin);
    
    printf(">> Enter a decimal number: "); scanf("%d",&n);
    while (n>0){
        PUSH((char)(n%2+48),&bin);
        n = n/2;
    }
    
    printf(">> Binary number: "); 
    while (!EMPTY(bin)){
        printf("%c", TOP(bin));
        POP(&bin);
    }
}

void bracketCheck(){
    Stack brackets;
    char bracket;
    getchar();
    printf(">> Enter a brackets string: ");
    while ((bracket = getchar()) != '\n'){
        if (bracket == '(')
            PUSH(bracket, &brackets);
        else if (bracket == ')')
            if (!POP(&brackets)){
                PUSH(bracket,&brackets);
                break;
            }
    }
    if (EMPTY(brackets))
        printf(">> The brackets are true");
    else
        printf(">> The brackets are false");
}

int main() {
    printf("\n---Problem 18a---\n");
    convertToBin();
    printf("\n---Problem 18b---\n");
    bracketCheck();
    return (EXIT_SUCCESS);
}

