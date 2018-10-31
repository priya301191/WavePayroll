//
//  DataBaseController.hpp
//  WavePayroll
//
//  Created by Priya Dhingra.
//  Copyright © 2018 Priya Dhingra. All rights reserved.

#ifndef DataBaseController_hpp
#define DataBaseController_hpp

#include <stdio.h>
#include <iostream>
#include <sqlite3.h>

using namespace std;

class DataBaseController
{
    
private:
    string DBPath;
    sqlite3 * db;
    
public:
    DataBaseController(string dbPath = "PayRoll.db");
    ~DataBaseController();
    void createTablewithHeaderInfo (string header);
    void insertEmployeeDetailsIntoPayroll(int employeeId, string payPeriod, float payAmount);
    void displayReport();
};

#endif /* DataBaseController_hpp */
