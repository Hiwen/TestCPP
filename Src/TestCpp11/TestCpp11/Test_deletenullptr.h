#pragma once
#include "Test_move.h"

inline void Test_delete_nullptr()
{
    {
        Time* t = nullptr;

        delete t;   // OK
        delete t;   // OK

        t = new Time(10, 10, 10);

        delete t;   // OK

        // delete t;   // error 读取位置 0xXXXX 时发生访问冲突
    }

    {
        Time* t = NULL;

        delete t;   // OK
        delete t;   // OK
    }
}
