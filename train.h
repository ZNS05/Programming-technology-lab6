#pragma once
#include <iostream>
#include <string>
using namespace std;

class Train
{
    string sEndPoint; 
    string sTrainNum; 
    string sTimeStart; 
public:
    Train();
    Train(const Train &obj);
    ~Train();

    // Seters
    void setEndPoint(string _sEndPoint);
    void setTrainNum(string _sTrainNum);
    void setTimeStart(string _sTimeStart);

    // Geters
    string getEndPoint();
    string getTrainNum();
    string getTimeStart();

    // Metods
    friend ostream &operator<<(ostream &stream, Train &obj);
};
