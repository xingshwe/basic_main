#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef  struct   
{
    /* data */
};




// 1. 先定义结构体
struct view {
    char name[64];
    int age;
};

// ✅ 核心：参数是二级指针
static void get_point(struct view **p) 
{
    // ✅ *p 就是外部那个指针变量
    *p = (struct view *)malloc(sizeof(struct view));
    if(*p == NULL) {
        perror("malloc failed");
        return;
    }
    // ✅ 访问成员：先解引用，再用 ->
    strcpy((*p)->name, "John Doe");
    (*p)->age = 30;
}


int main() 
{
    struct view *view_ptr = NULL;
    // ✅ 传参：传 指针变量的地址 &view_ptr
    get_point(&view_ptr);

    // ✅ 现在可以安全操作了
    strncpy(view_ptr->name, "Additional info...", sizeof(view_ptr->name)-1);
    view_ptr->name[sizeof(view_ptr->name)-1] = '\0';

    printf("Name: %s\n", view_ptr->name);
    printf("Age: %d\n", view_ptr->age);

    // ✅ 用完释放
    free(view_ptr);
    view_ptr = NULL; // 好习惯，防止野指针

    return 0;
}