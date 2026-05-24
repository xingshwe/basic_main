#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "main.h"


struct Handler {
    int (*op)(int, int);
    void (*print)(int);
    void (*get_data)(int*);
};

struct Handler* get_handler(void);

void hanle_request(void) 
{
    struct Handler *handler = get_handler();
    int result = handler->op(10, 5);
    handler->print(result);
}

int main(void) {
    struct Handler *handler = get_handler();
    int result = handler->op(10, 5);
    handler->print(result);
    int data;
    handler->get_data(&data);
    printf("main: data = %d\n", data);
    //printf("op addr = %p, print addr = %p\n", (void *)handler->op, (void *)handler->print);
    return 0;
}