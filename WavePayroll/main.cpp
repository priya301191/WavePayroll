//
//  main.cpp
//  WavePayroll
//
//  Created by Priya Dhingra.
//  Copyright © 2018 Priya Dhingra. All rights reserved.

#include <iostream>
#include <string>
#include <sstream>
#include <sqlite3.h>
#include "FileReader.hpp"
#include "Payroll.hpp"
#include "DataBaseController.hpp"


using namespace std;

static const char* DBPath = "/Users/prdhingr/Personal_Stuff/Wave_Project/WavePayroll/WavePayroll/payal.db";


int main(int argc, const char * argv[]) {
    
   
    int choice;
    
    cout<<"Enter Options:\n1. To upload a file and generate report \n2.  To generate a report \n";
    cin>>choice;
    
    
    Payroll payroll;
    
    //create DataBase object and insert File Data
    DataBaseController dbController(DBPath);
    
    switch(choice)
    {
            
        case 1:
        {
            string fileName;
            cout<<"Enter File Name : \n";
            cin>>fileName;
            
            FileReader reader(fileName, &dbController);
            reader.insertFileDataintoDB(payroll);
            dbController.displayReport();
            break;
            
        }
            
        case 2:
        {
            dbController.displayReport();
            break;
        }
            
        default:
            break;
    }

    
    return 0;
}
