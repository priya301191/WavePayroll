//
//  Payroll.hpp
//  WavePayroll
//
//  Created by Priya Dhingra.
//  Copyright © 2018 Priya Dhingra. All rights reserved.

#ifndef Payroll_hpp
#define Payroll_hpp

#include <stdio.h>
#include <iostream>
#include <string>

using std::string;

class Payroll
{
private:
    
    int mEmployeeId;
    float payAmount;
    string mPeriod;
    
public:
    float getPayAmount(string hours,string group);
    string getPeriod (string date);
    void showPayrollReport();
};

#endif /* Payroll_hpp */
