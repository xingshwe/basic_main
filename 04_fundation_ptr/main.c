#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
*bref:结构体有函数指针
*/
struct Handler {
    int (*op)(int, int);
    void (*print)(int);
};


int add(int a, int b) {
    return a + b;
}

void print_result(int value) {
    printf("result = %d\n", value);
}


/*
*bref:获取函数地址
*op:指向了add函数地址
*print:指向了print_result函数地址
*return:返回了一个Handler结构体的地址(这样就拿到了函数的地址)
*/
struct Handler* get_handler(void) {
    static struct Handler handler = {
        .op = add,
        .print = print_result,
    };
    return &handler;
}
