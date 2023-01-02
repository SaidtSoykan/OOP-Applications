//--- 2021-2022 Summer Object Oriented Programing Assignment 3 ---//
//--------------------------//
//---Name & Surname:Muhammed Said Soykan
//---Student Number:150190732
//--------------------------//

//-------------Do Not Add New Libraries-------------//
//-------------All Libraries Needed Were Given-------------//

#ifndef __UTILS_H
#define __UTILS_H

#include "statistics.h"

StatisticalDistribution* choose_function(int);
const double many_trials(StatisticalDistribution*, vector<double>, double, int, int, int);

#endif