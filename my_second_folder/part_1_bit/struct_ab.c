#include <stdio.h>

struct A {
    char c;
    int i;
    char d;
};

struct B {
    int i;
    char c;
    char d;
};

int main() {
    printf("Size of struct A: %zu\n", sizeof(struct A));
    printf("Size of struct B: %zu\n", sizeof(struct B));
    return 0;
}
