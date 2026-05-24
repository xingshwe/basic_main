#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

struct Handler {
    int (*op)(int, int);
    void (*print)(int);
    void (*get_data)(int *);
};


int value = 42;

// Function declarations
static  int add(int a, int b);
static void print_result(int value);






static  int add(int a, int b) {
    return a + b;
}

static void print_result(int value) {
    printf("result = %d\n", value);
}


void get_data(int *data) {
    *data = value;
    printf("get_data: data = %d\n", *data);
}


struct Handler* get_handler(void) {
    static struct Handler handler = {
        .op = add,
        .print = print_result,
        .get_data = get_data
    };
    return &handler;
}
