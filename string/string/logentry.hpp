//
// File:        logentry.hpp
//
// Version:     1.0
// Date:
// Author:
//
// Description: Class definition for a log entry.
//
//
//
 
#ifndef CS_LOGENTRY_H_
#define CS_LOGENTRY_H_

#include "string.hpp"
#include <iostream>
#include <vector>
#include <map>

//

class Date {
public:
    Date():day('0'),month('0'),year('0') {};
    Date(String&day, String&month, String&year):day(day),month(month),year(year) {};

    String getDay()const {return day;}
    String getMonth()const {return month;}
    String getYear() const {return year;}
private:
    String day, month, year;
};

//
class Time {
  public:
    Time():hour('0'),minute('0'),second('0') {};
    Time(String&hour, String&minute, String&second):hour(hour),minute(minute),second(second) {};

    String getHour()const {return hour;}
    String getMinute()const {return minute;}
    String getSecond() const {return second;}
  private:
    String  hour, minute, second;
};


// A single log entry
class LogEntry {
public:
    LogEntry() {};
    LogEntry(const String&);

    String getHost() const{return host;}

    int getNumOfBytes() const{return number_of_bytes;}

    friend  std::ostream& operator<<(std::ostream&, const LogEntry&);

private:
    String  host;
    Date    date;
    Time    time;
    String  request;
    String  status;
    int     number_of_bytes;
};


std::vector<LogEntry>   parse       (std::istream&);
void                    output_all  (std::ostream&, const std::vector<LogEntry>&);
void                    by_host     (std::ostream&, const std::vector<LogEntry>&);
int                     byte_count  (const std::vector<LogEntry>&);
// void get_ip(std::ostream&,std::vector<LogEntry>&);
#endif
