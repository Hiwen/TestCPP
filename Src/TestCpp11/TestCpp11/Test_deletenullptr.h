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

        // delete t;   // error ��ȡλ�� 0xXXXX ʱ�������ʳ�ͻ
    }

    {
        Time* t = NULL;

        delete t;   // OK
        delete t;   // OK
    }
}
