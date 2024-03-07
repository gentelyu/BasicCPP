#include <iostream>
using namespace std;
#include "myAdd.h"

int main()
{
    // call	_Z5myAddIiET_S0_S0_@PLT
    // 汇编在链接之前, 所以这个_Z5myAddIiET_S0_S0_@PLT是随机值。
    /* 直到链接完成之后, 才会更新这个值. */
    myAdd(10, 20);      // call 随机的
    // cout << res << endl;
    return 0;
}