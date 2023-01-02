//--- 2021-2022 Summer Object Oriented Programing Assignment 3 ---//
//--------------------------//
//---Name & Surname:Muhammed Said Soykan
//---Student Number:150190732
//--------------------------//

//-------------Do Not Add New Libraries-------------//
//-------------All Libraries Needed Were Given-------------//

#include "statistics.h"
#include <random>
#include <iostream>

using namespace std;

//mean getter
const double StatisticalDistribution::getmean(){
    return this->mean;
}

vector<double> StatisticalDistribution::calculate_confidence_interval(vector<double> random_sample, int sample_size, double t_value){
    //defining the vector holding the elements to be returned in the function
    vector<double> statisticSample;
    //total is equal to the sum of the elements of the given random sample
    double total = 0.0;
    for (int i = 0; i < sample_size; i++)
        total += random_sample[i];
    //found the mean value by dividing the calculated total value by sample_size
    double mean = total / sample_size;
    //the sum of the squares of the values found by subtracting the mean from each element to calculate the standard deviation
    double stDeviation = 0.0;
    for (int i = 0; i < sample_size; i++)
        stDeviation += (random_sample[i] - mean) * (random_sample[i] - mean);
    //The values calculated according to the order and formula given in the pdf were added to the vector defined at the beginning with push_back
    statisticSample.push_back(mean - ((t_value * sqrt(stDeviation / sample_size)) / sqrt(sample_size)));
    statisticSample.push_back(mean);
    statisticSample.push_back(mean + ((t_value * sqrt(stDeviation / sample_size)) / sqrt(sample_size)));
    return statisticSample;
}

//creating a sample vector with normal distribution
vector<double> NormalDistribution::sample(int sample_size, int seed_val){
    //vector created to hold the generated values
    vector<double> normSample;
    //Generator definition to generate random values for normal distribution
    default_random_engine generator;
    generator.seed(seed_val);
    normal_distribution<double> distribution(getmean(), stDeviation);
    for(int i = 0;i < sample_size; i++)
        normSample.push_back(distribution(generator));        
    return normSample;
}

//creating a sample vector with uniform real distribution
vector<double> UniformDistribution::sample(int sample_size, int seed_val){
    //vector created to hold the generated values
    vector<double> uniSample;
    //Generator definition to generate random values for uniform real distribution
    default_random_engine generator;
    generator.seed(seed_val);
    uniform_real_distribution<double> distribution(a,b);
    for(int i = 0; i < sample_size; i++)
        uniSample.push_back(distribution(generator));
    return uniSample;
}

//creating a sample vector exponential distribution
vector<double> ExponentialDistribution::sample(int sample_size, int seed_val){
    //vector created to hold the generated values
    vector<double> expSample;
    //Generator definition to generate random values for exponential distribution
    default_random_engine generator;
    generator.seed(seed_val);
    exponential_distribution<double> distribution(lambda);
    for(int i = 0; i < sample_size; i++)
        expSample.push_back(distribution(generator));
    return expSample;
}