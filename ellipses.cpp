#include <cmath>
#include <iostream>
#include "ellipses.h"

Ellipses::Ellipses(double r1, double r2)
{
    name = "Ellipse";
    xradius = r1;
    yradius = r2;
}

vector<double> Ellipses::GetPoint(double t)
{
    vector<double> point;
    point.push_back(xradius * cos(t));
    point.push_back(yradius * sin(t));
    point.push_back(0);
    return point;
}

vector<double> Ellipses::GetDerivative(double t)
{
    vector<double> derivative;
    derivative.push_back(- xradius * sin(t));
    derivative.push_back(yradius * cos(t));
    derivative.push_back(0);
    return derivative;
}
