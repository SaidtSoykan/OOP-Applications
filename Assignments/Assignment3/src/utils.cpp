//--- 2021-2022 Summer Object Oriented Programing Assignment 3 ---//
//--------------------------//
//---Name & Surname:Muhammed Said Soykan
//---Student Number:150190732
//--------------------------//

//-------------Do Not Add New Libraries-------------//
//-------------All Libraries Needed Were Given-------------//

#include "utils.h"
#include <string>
#include <iostream>

using namespace std;

//Function that returns statistical distribution object according to distribution type read from text file
StatisticalDistribution* choose_function(int dist_type){
    StatisticalDistribution *dist;
    switch(dist_type) {
    case 0:
        dist = new NormalDistribution();
        break;
    case 1:
        dist = new UniformDistribution();
        break;
    case 2:
        dist = new ExponentialDistribution();
        break;
    default:
        dist = nullptr;
        try{
            throw "Unidentified distribution function!";
        }
        catch(string exception){
            cout << exception;
        } 
    }
    return dist;
}

const double many_trials(StatisticalDistribution *dist , vector<double> random_sample,double t_value, int trials, int sample_size, int seed_val){
    double success = 0.0;
    int i = 0;
    while(i < trials){
        //keep calculate confidence interval values in a temporary vector
        vector<double> trialSample = dist->calculate_confidence_interval(random_sample, sample_size, t_value);
        random_sample = dist->sample(sample_size, seed_val);
        //increment success value if theoretical mean is in true position
        if(trialSample[0] < dist->getmean() && dist->getmean() < trialSample[2]){
            success++;
        }
        //increment seed_value by one at each trial.
        seed_val++;
        i++;
    }
    return success / trials;
}