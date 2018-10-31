//
//  DataBaseController.cpp
//  WavePayroll
//
//  Created by Priya Dhingra.
//  Copyright © 2018 Priya Dhingra. All rights reserved.

#include "DataBaseController.hpp"

namespace {
    static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
        int i;
        static int count=0;
      // printf("%s || ", azColName[0],azColName[0]);
        if(count==0)
        {
            for(i = 0; i<argc; i++) {
                printf(" %s || ", azColName[i]);
            }
            printf("\n");
        }
        
        for(i = 0; i<argc; i++) {
            printf(" %s || ", argv[i] ? argv[i] : "NULL");
        }
        count++;
        printf("\n");
        return 0;
    }
}

DataBaseController::DataBaseController(string dbPath) : DBPath(dbPath)
{
    int rc = sqlite3_open(DBPath.c_str(), &db);
    if( rc ) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
    }
    else {
        fprintf(stderr, "Opened database successfully\n");
    }
}

DataBaseController::~DataBaseController()
{
      sqlite3_close(db);
}

void DataBaseController::createTablewithHeaderInfo (string header)
{
    //TODO: read header and make table...as of now hardCoded as per client document
    string sql;
    sql = "CREATE TABLE PAYROLL("  \
    "EMPLOYEE_ID INT      NOT NULL," \
    "AMOUNT_PAID  REAL NOT NULL,"\
    "PAY_PERIOD           TEXT    NOT NULL,"\
    " PRIMARY KEY(EMPLOYEE_ID,PAY_PERIOD));";
    
    /* Execute SQL statement */
    char* zErrMsg = 0;
    int rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);
    
    if( rc != SQLITE_OK ){
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } else {
        fprintf(stdout, "Table created successfully\n");
    }
}


void DataBaseController::insertEmployeeDetailsIntoPayroll(int employeeId, string payPeriod, float payAmount)
{
    //adding into db
    char buffer[300];
    char* zErrMsg = 0;
    
    sprintf(buffer, "INSERT INTO PAYROLL(EMPLOYEE_ID,PAY_PERIOD,AMOUNT_PAID) VALUES ('%d', '%s' ,'%f')",
            employeeId,payPeriod.c_str(),payAmount);
    
    int rc = sqlite3_exec(db, buffer, NULL, NULL, &zErrMsg);
    
    if( rc != SQLITE_OK ) {
        // fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
        
            sprintf(buffer, "UPDATE PAYROLL SET AMOUNT_PAID = '%f'+ AMOUNT_PAID WHERE EMPLOYEE_ID = '%d' AND PAY_PERIOD= '%s'",
                    payAmount,employeeId,payPeriod.c_str());
            int rc1 = sqlite3_exec(db, buffer, NULL, NULL, &zErrMsg);
        
            if( rc1 != SQLITE_OK ){
                fprintf(stderr, "SQL error: %s for update\n", zErrMsg);
                sqlite3_free(zErrMsg);
            }
            else
            {
                //cout<<"row updated successfully\n";
            }
    }
    else {
        //cout<<"row inserted successfully\n";
    }
}

void DataBaseController::displayReport()
{
    char buffer[300];
    char* zErrMsg = 0;
    
    cout << "\n ------ DISPLAYING TABLE ------\n";
    sprintf(buffer, "SELECT * FROM PAYROLL ORDER BY EMPLOYEE_ID");
    
    int rc = sqlite3_exec(db, buffer, callback, NULL, &zErrMsg);
       
    if( rc != SQLITE_OK ) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } else {
        fprintf(stdout, "Operation done successfully\n");
    }
}
