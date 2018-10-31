//
//  FileReader.cpp
//  WavePayroll
//
//  Created by Priya Dhingra.
//  Copyright © 2018 Priya Dhingra. All rights reserved.

#include "FileReader.hpp"
#include "DataBaseController.hpp"
#include <string>

using namespace std;

void FileReader::insertFileDataintoDB(Payroll payroll)
{
    std::ifstream file(fileName);
    
    if(!file.is_open())
        std::cout<<"Error :opening file"<<std::endl;
    
    ///it will check about footer info and tell if the file is valid or not
    if(!fileValidator(file))
    {
        std::cout<<"Invalid file with duplicate footer info \n";
        return;
    }
    
    //move to the begining
    file.clear();
    file.seekg(0, ios::beg);

    //read first line and create table
    string header;
    if (file.good())
    {
        getline(file, header);
    }
    
    
    //create Table request if table does not exist
    dbController->createTablewithHeaderInfo(header);
    
    std::string date;
    std::string hours;
    std::string empId;
    std::string group;
    
    while(file.good())
    {
        getline(file,date,',');
        if(date.find("report")!= date.npos)
            break;
        
        getline(file,hours,',');
        getline(file,empId,',');
        getline(file,group,'\n');
        
        float payAmount = payroll.getPayAmount(hours,group);
        int employeeId = std::atoi(empId.c_str());
        string payPeriod = payroll.getPeriod(date).c_str();
        
        dbController->insertEmployeeDetailsIntoPayroll(employeeId,payPeriod.c_str(),payAmount);
    }
    file.close();
}

bool FileReader::fileValidator(ifstream &fin)
{
    //check if report Id is unique else make upload fail
    if(fin.is_open()) {
        fin.seekg(0,std::ios_base::end);      //Start at end of file
        char ch = ' ';                        //Init ch not equal to '\n'
        while(ch != '\n') {
            fin.seekg(-2,std::ios_base::cur); //Two steps back, this means we
            //will NOT check the last character
            if((int)fin.tellg() <= 0){        //If passed the start of the file,
                fin.seekg(0);                 //this is the start of the line
                break;
            }
            fin.get(ch);                      //Check the next character
        }
        
        string name,reportID;
        getline(fin,name,',');
        getline(fin,reportID,',');
        
       // cout<<"name is"<<name<<endl;
        //cout<<"ReportID "<<reportID<<endl;
        
        int rID = std::stoi(reportID.c_str());
        
        if (reportIDs.find(rID)!= reportIDs.end()) {
            return false;
        }
        else
            reportIDs.insert(rID);
        
    }
    return true;
}
