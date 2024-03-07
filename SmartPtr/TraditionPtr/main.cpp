#include <iostream>
using namespace std;
#include <stdlib.h>
#include <stdio.h>

void test()
{
    
    /* 传统指针 */
    int * ptr;      // 1.野指针


    char * str = (char *)malloc(sizeof(char) * 10);     // 需要手动管理

    printf("11111\n");

    free(str);

    printf("222222\n");


    int * size = new int;

    printf("3333333\n");


    delete size;

    printf("4444444\n");

    
}

int main()
{
    /* */
    test();

    return 0;
}