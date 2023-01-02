//--- 2021-2022 Summer Object Oriented Programing Assignment 3 ---//
//--------------------------//
//---Name & Surname:Muhammed Said Soykan
//---Student Number:150190732
//--------------------------//

//-------------Do Not Add New Libraries-------------//
//-------------All Libraries Needed Were Given-------------//

#ifndef __STATISTICS_H
#define __STATISTICS_H

#include <vector>

using namespace std;

class StatisticalDistribution{
    private:
        const double mean;
    public:
        StatisticalDistribution(double Mean): mean(Mean){};
        const double getmean();
        vector<double> virtual sample(int, int) = 0;
        vector<double> calculate_confidence_interval(vector<double>, int, double);
};

class NormalDistribution : public StatisticalDistribution{
    private:
        const double stDeviation;
    public:
        NormalDistribution(): StatisticalDistribution(0.0), stDeviation(1.0){};
        vector<double> sample(int, int);
};

class UniformDistribution : public StatisticalDistribution{
    private:
        const double a;
        const double b;
    public:
        UniformDistribution(): StatisticalDistribution(0.0), a(-1.0), b(1.0){};
        vector<double> sample(int, int);
};

class ExponentialDistribution : public StatisticalDistribution{
    private:
        const double lambda;
    public:
       ExponentialDistribution(): StatisticalDistribution(1.0), lambda(1.0){};
       vector<double> sample(int, int);
};

#endif