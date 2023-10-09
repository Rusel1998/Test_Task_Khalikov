#include <cmath>
#include <iostream>
#include "circles.h"

Circles::Circles(double r)
{
    name = "Circle";
    radius = r;
}

vector<double> Circles::GetPoint(double t)
{
    vector<double> point;
    point.push_back(radius * cos(t));
    point.push_back(radius * sin(t));
    point.push_back(0);
    return point;
}

vector<double> Circles::GetDerivative(double t)
{
    vector<double> derivative;
    derivative.push_back(- radius * sin(t));
    derivative.push_back(radius * cos(t));
    derivative.push_back(0);
    return derivative;
}
