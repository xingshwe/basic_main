#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Person {
    char name[50];
    int age;
    char *info; // Pointer to additional information
};

char buf[10] = "Hello";
struct Person person_t ={
    .name = "John Doe",
    .age = 30,
    .info = buf
};



static void input_person(struct Person *p) {
    printf("Enter name: ");
    fgets(p->name, sizeof(p->name), stdin);
    p->name[strcspn(p->name, "\n")] = '\0'; // Remove newline character

    printf("Enter age: ");
    scanf("%d", &p->age);
    getchar(); // Consume the newline character left by scanf
}

int main() {
    char *p = person_t.info;

    printf("Info: %s\n", p);
    return 0;
}