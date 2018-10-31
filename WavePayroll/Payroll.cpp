//
//  Payroll.cpp
//  WavePayroll
//
//  Created by Priya Dhingra.
//  Copyright © 2018 Priya Dhingra. All rights reserved.

#include "Payroll.hpp"
#include <sstream>

using namespace std;

static const int payForGroupA = 20;
static const int payForGroupB = 30;

float Payroll::getPayAmount(string hours,string group)
{
    //float amount=0;
    float hour = std::atof(hours.c_str());
    // cout<<"group is"<<group<<endl;
    
    if(group.compare("A")==0)
    {
        payAmount = payForGroupA * hour;
       // cout<<"yes";
        
    }
    else
        payAmount = payForGroupB * hour;
    
    //cout<<"amount is"<<payAmount<<endl;
    return payAmount;
    
}

string Payroll::getPeriod (string date)
{
    stringstream ss;
    ss << date;
    string dd, mm, yy;
    
    getline(ss, dd, '/');
    getline(ss, mm, '/');
    getline(ss, yy, '/');
    
    string mPeriod ="";
    
//format of period: 1/11/2016 - 15/11/2016
    
    if(std::atoi(dd.c_str())>=1 && std::atoi(dd.c_str())<=15)
        mPeriod = "1/"+mm+"/"+yy+" - 15/"+mm+"/"+yy;
    else
        mPeriod = "16/"+mm+"/"+yy+" - 30/"+mm+"/"+yy; //TODO:need to calucate exact end day of the month and then put value
    
    return mPeriod;
}
