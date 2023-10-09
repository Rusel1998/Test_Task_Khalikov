#ifndef ELLIPSES_H
#define ELLIPSES_H

#include "threedcurve.h"

class Ellipses : public threeDcurve
{
public:
    Ellipses(double r1 = 1, double r2 = 1);
    double xradius;
    double yradius;
    vector <double> GetPoint(double t);
    vector <double> GetDerivative(double t);
};

#endif // ELLIPSES_H
