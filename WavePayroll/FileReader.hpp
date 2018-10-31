//
//  FileReader.hpp
//  WavePayroll
//
//  Created by Priya Dhingra.
//  Copyright © 2018 Priya Dhingra. All rights reserved.

#ifndef FileReader_hpp
#define FileReader_hpp

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <sqlite3.h>
#include <string>
#include "Payroll.hpp"
#include "DataBaseController.hpp"
#include <set>


/*
 * A class to read data from a csv file.
 */
class FileReader
{
    std::string fileName;
    DataBaseController *dbController;
    std::string delimeter;
    std::set<int> reportIDs;
    
public:
    FileReader(std::string filename, DataBaseController *dbc, std::string delm = ",") :
    fileName(filename), dbController(dbc), delimeter(delm)
    { }
    
    // Function to fetch data from a CSV File
   // std::vector<std::vector<std::string> > getData();
    bool fileValidator(ifstream &fin);
    void insertFileDataintoDB(Payroll payroll);
   // void createTablewithHeaderInfo (string header, sqlite3* db);
    //void insertEmployeeDetailsIntoPayroll(int employeeId,string payPeriod,float payAmount);
};


#endif /* FileReader_hpp */





