#ifndef HELIXES_H
#define HELIXES_H

#include "threedcurve.h"

class Helixes : public threeDcurve
{
public:
    Helixes(double r = 1, double s = 1);
    double step;
    vector <double> GetPoint(double t);
    vector <double> GetDerivative(double t);
};

#endif // HELIXES_H
