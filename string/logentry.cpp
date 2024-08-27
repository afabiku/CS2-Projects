//
//
// File:        logentry.cpp  
//       
// Version:     1.0
// Date:        
// Author:      
//
// Description: Class implementation for a log entry.
//
//
 
#include "string.hpp"
#include "logentry.hpp"
#include <iostream>
#include <vector>


// REQUIRES:
// ENSURES:
LogEntry::LogEntry(const String& line) {
    std::vector<String> logEntryParts = line.split(' ');
    // std::cout << line << std::endl;
    if(logEntryParts.size() == 10){
        String dateInfo(logEntryParts[3]);

        dateInfo = dateInfo.substr(1,dateInfo.length());

        String day = dateInfo.split('/')[0];
        String month = dateInfo.split('/')[1];

        int offset = 1;
        int startIndex = dateInfo.findstr(0,month) + month.length() + offset;
        String timeInfo = dateInfo.substr(startIndex,dateInfo.length());

        String year = timeInfo.split(':')[0];
        String hour = timeInfo.split(':')[1];
        String minute = timeInfo.split(':')[2];
        String seconds = timeInfo.split(':')[3];

        date = Date(day,month,year);
        time = Time(hour,minute,year);
        host = logEntryParts[0];

        int requestFirstQuote = line.findch(0,'"');
        int requestSecondQuote = line.findch(requestFirstQuote+1,'"');

        request = line.substr(requestFirstQuote+1,requestSecondQuote-1);

        status =  logEntryParts[8];
        
        String bytes = logEntryParts[9];
        int index = bytes.length() - 1;
        int digits = 1;
        

        number_of_bytes = 0;
        if(bytes != '-'){
            while(index >= 0){
                int number = bytes[index] - '0';
                number_of_bytes += (number * digits);
                index -= 1;
                digits *= 10;
            }
            digits = 1;
        }
    }else{
        LogEntry();
    }
}

// REQUIRES:
// ENSURES:
std::vector<LogEntry> parse(std::istream& file) {
    std::vector<LogEntry> result;
    char text;
    while(!file.eof()){
        String log("");
        while(file.get(text)){
            if(text == '\n'){result.push_back(LogEntry(log));break;}
            log += text;
        }
        if(file.eof()){
            if(log.length() > 0){result.push_back(LogEntry(log));}
            break;
        }
    }
    return result;
}


//
// Free functions
//
std::ostream&operator<<(std::ostream&cout, const LogEntry&entry){
    std::cout << entry.host << " " << entry.time.getHour() << " " << entry.time.getMinute() << " " << entry.time.getSecond() 
              << " " << entry.date.getDay() << " " << entry.date.getMonth() << entry.date.getYear() 
              << " "  << entry.request << " " << entry.status << " "<< entry.number_of_bytes;
    return cout;
}


// REQUIRES:
// ENSURES:
void output_all(std::ostream& cout, const std::vector<LogEntry>&entryVector) {
    for(size_t i = 0; i < entryVector.size(); ++i){
        cout << entryVector[i] << std::endl;
    }
}

// // REQUIRES:
// // ENSURES:
void by_host(std::ostream& out, const std::vector<LogEntry>&entry) {
    for(size_t i = 0; i < entry.size(); ++i){
        out << entry[i].getHost() << std::endl;
    }
}

// // REQUIRES:
// // ENSURES:
int byte_count(const std::vector<LogEntry>&entry) {
    int amount = 0;
    for(size_t i = 0; i < entry.size(); ++i){
        if(entry[i].getNumOfBytes() != 0){
            amount+= entry[i].getNumOfBytes();
        }
    }
    return amount;
}


// void get_ip(std::ostream& cout,std::vector<LogEntry>&entry){
//     std::map<String, int> mp;
//     for(size_t i = 0; i < entry.size(); ++i){
//         cout << mp[entry[i].getHost()];
//         mp[entry[i].getHost()]++;
//     }
// }
