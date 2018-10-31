//
//  Controller.cpp
//  WavePayroll
//
//  Created by Priya Dhingra on 29/10/18.
//  Copyright © 2018 Priya Dhingra. All rights reserved.
//
//
//#include "Controller.hpp"
//#include "FileReader.hpp"
//
//
//Controller::Controller(string dbPath, string filename) : fileName(filename),
//                        DBPath(dbPath)
//{
//    
//    int rc = sqlite3_open("", &db);
//    if( rc ) {
//        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
//    }
//    else {
//        fprintf(stderr, "Opened database successfully\n");
//    }
//}
//
//string Controller::getFile()
//{
//    return fileName;
//}
//
//void Controller::generatePayrollReport()
//{
//    if (!fileName.empty()) {
//        FileReader fr(fileName);
//        fr.insertFileDataintoDB(db, mPayroll);
//    }
//}
//
//Controller :: ~Controller()
//{
//   sqlite3_close(db);
//}