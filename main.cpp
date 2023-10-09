#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include<memory>
#include<cmath>
#include "threedcurve.h"
#include "circles.h"
#include "ellipses.h"
#include "helixes.h"

using namespace std;

//генератор "случайных" чисел типа int в заданном диапазоне
int RandomNumber(int min, int max)
{
    //srand(time(NULL));
    int num = min + rand() % (max - min + 1);
    return num;
}

//генератор "случайных" чисел типа double в заданном диапазоне
double fRand(double fMin, double fMax)
{
    //srand(time(NULL));
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}

int main()
{
    srand(time(NULL));
    vector<shared_ptr<threeDcurve>> curves;
    //генерируем случайное количество кривых в диапазоне от 5 до 15
    int n = RandomNumber(5, 15);
    cout << "Coordinates of points {x, y, z} and derivatives {dx/dt, dy/dt, dz/dt} of all curves in the container at t=PI/4\n";
    for (int i = 0; i < n; i++)
    {
        double t = M_PI / 4;
        int k = RandomNumber(1, 3);
        if (k == 1)
        {
            Circles* circle = new Circles(fRand(0, 10));
            curves.push_back(shared_ptr<threeDcurve>(circle));
            cout << i + 1 << ". " << "Circle with radius = " << circle->radius << " - {";
        }
        else if (k == 2)
        {
            Ellipses* ellipse = new Ellipses(fRand(0, 10), fRand(0, 10));
            curves.push_back(shared_ptr<threeDcurve>(ellipse));
            cout << i + 1 << ". " << "Ellipse with xradius = " << ellipse->xradius << " and yradius = " << ellipse->yradius << " - {";
        }
        else if (k == 3)
        {
            Helixes* helix = new Helixes(fRand(0, 10), fRand(0, 10));
            curves.push_back(shared_ptr<threeDcurve>(helix));
            cout << i + 1 << ". " << "Helix with radius = " << helix->radius << " and step = " << helix->step << " - {";
        }

        for (int j = 0; j < 3; j++)
        {
            cout << curves.at(i)->GetPoint(t).at(j);
            if (j != 2) cout << ", ";
        }
        cout << "}, {";

        for (int j = 0; j < 3; j++)
        {
            cout << curves.at(i)->GetDerivative(t).at(j);
            if (j != 2) cout << ", ";
        }
        cout << "}\n";
    }

    //Заполнение вектора окружностей
    vector<shared_ptr<threeDcurve>> circles;
    double radiusSum = 0;//сумма радиусов окружностей
    for (int i = 0; i < n; i++)
    {
        if (curves.at(i)->name == "Circle")
        {
            circles.push_back(curves.at(i));
            radiusSum += curves.at(i)->radius;
        }
    }

    cout << "\nThe sum of the circles' radii is " << radiusSum << "\n";

    sort(circles.begin(), circles.end(), [](shared_ptr<threeDcurve>(a), shared_ptr<threeDcurve>(b)){ return a->radius < b->radius; });

    cout << "\nVector of circles sorted by radius:\n";
    for (int i = 0; i < circles.size(); i++)
        cout << circles.at(i)->radius << " ";

    return 0;
}
