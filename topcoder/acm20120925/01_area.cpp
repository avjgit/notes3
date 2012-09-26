#include <fstream>
#include <iostream>
#include <iomanip>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

#define PI 3.14159265

int main()
{
    ifstream input;
    ofstream output;

    double AB;
    double BC;
    double CD;
    double DA;
    double AC;

    input.open("area.in");

    input >> AB;
    input >> BC;
    input >> CD;
    input >> DA;
    input >> AC;


    double p1 = (AB + BC + AC) / 2.0;
    double S1 = sqrt(p1 * (p1 - AB) * (p1 - BC) * (p1 - AC));
//    cout << S1;

    double sin1 = S1/ 0.5/ AC/ BC;
//    cout << sin1;

    double angle1 = asin(sin1);
//    cout << angle1;


    double p2 = (AC + CD + DA) / 2.0;
    double S2 = sqrt(p2 * (p2 - AC) * (p2 - CD) * (p2 - DA));


    double sin2 = S2/ 0.5/ AC/ CD;
    double angle2 = asin(sin2);
    double angleTCS = PI - angle1 - angleTCS;
    double S_TCS = 0.5 * 2*CD * BC * sin(angleTCS);

    double sin_ADC = S2/ 0.5/ DA/ CD;


    double angle_ADC;
    angle_ADC = asin(sin_ADC);

    double angleTDQ = PI - angle_ADC;
    double S_TDQ = 0.5 * CD * 2 * DA * sin(angleTDQ);


    double sinDAC = S2/ 0.5/ DA/ AC;
    double angleDAC = asin(sinDAC);
    double sinCAB = S1/ 0.5/ AC/ AB;
    double angleCAB = asin(sinCAB);
    double angleQAR = PI - angleDAC - angleCAB;
    double S_QAR = 0.5 * AB*2 * DA * sin(angleQAR);

    double sinABC = S1/ 0.5/ AB/ BC;
    double angleABC = asin(sinABC);
    double angleRBS = PI - angleABC;
    double S_RBS = 0.5 * AB * 2*BC * sin(angleRBS);
//
//    cout << S1 << S2 << S_TCS << S_TDQ << S_QAR << S_RBS;


    output.open("area.out");
    output << fixed << setprecision (10) << (S1 + S2 + S_TCS + S_TDQ + S_QAR + S_RBS)/ (S1 + S2);

    input.close();
    output.close();
    return 0;
}


