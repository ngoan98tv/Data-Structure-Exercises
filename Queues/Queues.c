/* 
 * Author: Ngoan Tran
 */
#include "basicLib_Queues.c"
#include <string.h>
#include <windows.h>

void buffer(){
    Queues b;
    int i=0;
    char str[255];
    MAKENULL_QUEUE(&b);
    FILE *f = fopen("test.txt", "r");
    while ((fgets(str,255,f)) != NULL){
        ENQUEUE(str, &b);
        i++;
        printf(">> Read %d lines\n", i);
    } 
    printf("\n------------Printing--------------------------\n\n");
    while (!EMPTY(b)){
        puts(FRONT(b));
        DEQUEUE(&b);
        Sleep(10);
    }
    printf("\n\n------------End of File------------\n");
    fclose(f);
}

int main() {
    buffer();
    return (0);
}

