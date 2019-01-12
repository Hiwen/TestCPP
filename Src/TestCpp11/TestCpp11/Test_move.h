#pragma once

#include <iostream>

using namespace std;

class Time
{
public:

    Time(int h, int m, int s)
    {
        _h = new int(h);
        _m = new int(m);
        _s = new int(s);
    }

    Time(const Time& r)
    {
        cout << "copy" << endl;
        _h = new int(*r._h);
        _m = new int(*r._m);
        _s = new int(*r._s);
    }

    Time(Time&& t) noexcept 
        : _h(t._h) , _m(t._m), _s(t._s)
    {
        t._h = nullptr;
        t._m = nullptr;
        t._h = nullptr;
        cout << "move" << endl;
    }

    ~Time()
    {
        cout << "dstor" << endl;

        if (_h != nullptr) delete _h;
        if (_m != nullptr) delete _m;
        if (_s != nullptr) delete _s;
    }

private:

    int* _h;
    int* _m;
    int* _s;

};


inline void Test_move()
{
    {
        Time t(10, 20, 30);
        Time t2(t); 
    }

    cout << "move================" << endl;
    {
        Time t(10, 20, 30);
        Time t2(move(t));
    }
}
