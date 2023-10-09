#ifndef CIRCLES_H
#define CIRCLES_H

#include "threedcurve.h"

class Circles : public threeDcurve
{
public:
    Circles(double r = 1);
    vector <double> GetPoint(double t);
    vector <double> GetDerivative(double t);
private:

};

#endif // CIRCLES_H
