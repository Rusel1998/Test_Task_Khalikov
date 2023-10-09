#include <cmath>
#include <iostream>
#include "helixes.h"

Helixes::Helixes(double r, double s)
{
    name = "Helix";
    radius = r;
    step = s;
}

vector<double> Helixes::GetPoint(double t)
{
    vector<double> point;
    point.push_back(radius * cos(t));
    point.push_back(radius * sin(t));
    point.push_back(step * t / 2 / M_PI);
    return point;
}

vector<double> Helixes::GetDerivative(double t)
{
    vector<double> derivative;
    derivative.push_back(- radius * sin(t));
    derivative.push_back(radius * cos(t));
    derivative.push_back(step / 2 / M_PI);
    return derivative;
}
