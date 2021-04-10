//
// Created by Yifen on 12/1/2017.
//

#ifndef INC_202_PROJ10_DATATYPE_H
#define INC_202_PROJ10_DATATYPE_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;

class DataType{

    friend std::ostream& operator<< (std::ostream& os, const DataType& dataType);
    friend std::istream& operator>> (std::istream& is, DataType& dataType);

public:
    DataType();
    DataType(int intVal, double doubleVal);

    bool operator==(const DataType& other_dataType) const;
    DataType& operator= (const DataType& other_dataType);

    int GetIntVal() const;
    void SetIntVal(int i);
    double GetDoubleVal() const;
    void SetDoubleVal(double d);

private:
    size_t m_intVal;
    size_t m_doubleVal;
};


DataType::DataType(){
    m_intVal = 0;
    m_doubleVal = 0.0;
}


DataType::DataType(int intVal, double doubleVal){
    m_intVal = intVal;
    m_doubleVal = doubleVal;
}


bool DataType::operator==(const DataType& rhs) const{
    return m_intVal==rhs.m_intVal && m_doubleVal==rhs.m_doubleVal;
}


DataType& DataType::operator=(const DataType& rhs){
    if (this != &rhs){
        m_intVal = rhs.m_intVal;
        m_doubleVal = rhs.m_doubleVal;
    }
    return *this;
}


int DataType::GetIntVal() const{
    return m_intVal;
}


void DataType::SetIntVal(int i){
    m_intVal = i;
}


double DataType::GetDoubleVal() const{
    return m_doubleVal;
}


void DataType::SetDoubleVal(double d){
    m_doubleVal = d;
}


std::ostream& operator<<(std::ostream& os, const DataType& dt){
    os << "{" << dt.m_intVal << "," << dt.m_doubleVal << "}";
    return os;
}


std::istream& operator>>(std::istream& is, DataType& dt){
    char in_buf[255];
    is >> in_buf;
    //dt.m_doubleVal = atof(in_buf);
    dt.m_intVal = (int)dt.m_doubleVal;
    dt.m_doubleVal -= dt.m_intVal;
    return is;
}


#endif //INC_202_PROJ10_DATATYPE_H

