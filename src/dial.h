#pragma once

/**
 * Liczba całkowita z dolnym i górnym limitem
 */

class Dial
{
    int value;
    int max;
    int min;
public:
    Dial ( const int val=0,const int max=0,const int min = 0 ) noexcept: value ( val ), max ( max ),  min ( min ) {};
    void turnUp() noexcept
    {
        if ( value<max ) value++;
    }
    void turnDown() noexcept
    {
        if ( value>min ) value--;
    }
    void operator++ ( int ) noexcept
    {
        turnUp();
    }
    void operator-- ( int ) noexcept
    {
        turnDown();
    }
    int val() const noexcept
    {
        return value;
    }
    operator int() const noexcept
    {
        return value;
    }

};
