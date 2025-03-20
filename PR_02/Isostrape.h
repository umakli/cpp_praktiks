#pragma once
#include "Shape.h"
#include <math.h>
class Isostrape :
    public Shape
{
private:
    double a,b,c,d;

public:
    Isostrape() : Shape("Р/б трапеция")
    {
        a = 0;
        b = 0;
        c = 0;
        d = 0;
    }
    Isostrape(double a, double b, double c, double d) : Shape("Р/б трапеция")
    {
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
    }
    double Area() const override
    {
        return ((a+b)/2)* sqrt(pow(c, 2) - pow((a - b), 2) / 4);
    }
    double Perimetr() const override
    {
        return a+b+c+d;
    }
};
