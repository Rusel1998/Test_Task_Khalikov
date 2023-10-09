#ifndef THREEDCURVE_H
#define THREEDCURVE_H

#include <vector>
#include <string>

using namespace std;

class threeDcurve
{
private:

public:
    threeDcurve();
    string name;
    double radius;
    virtual vector<double> GetPoint(double t)
    {
        vector<double> point(3, 0.0);
        return point;
    }

    virtual vector<double> GetDerivative(double t)
    {
        vector<double> derivative(3, 0.0);
        return derivative;
    }

    virtual ~threeDcurve(){};
};

#endif // THREEDCURVE_H
