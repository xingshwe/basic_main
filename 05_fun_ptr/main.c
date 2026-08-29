#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

//学生信息模版
typedef struct Student {
    char name[50];
    int age;
} Student;

//学生信息模版
Student student = {
    .name = "张三",
    .age = 20
};

//函数指针结构体
typedef struct student_handler {
    void (*input_info)(Student *);
    void (*print_info)(Student *);
} student_handler_t;


/*
* @brief  输入学生信息
* @param student 
*/
static void input_student_info(Student *student) {
    printf("请输入学生姓名: ");
    scanf("%s", student->name);
    printf("请输入学生年龄: ");
    scanf("%d", &student->age);
}

static void print_student_info(Student *student) {
    printf("学生姓名: %s\n", student->name);
    printf("学生年龄: %d\n", student->age);
}



//返回的函数指针结
static student_handler_t get_student_handler(void) {
    static student_handler_t handler = {
        .input_info = input_student_info,
        .print_info = print_student_info
    };
    return handler;
}


int main(void) {
   student_handler_t handler = get_student_handler();
   handler.input_info(&student);
   handler.print_info(&student);
    return 0;
}

