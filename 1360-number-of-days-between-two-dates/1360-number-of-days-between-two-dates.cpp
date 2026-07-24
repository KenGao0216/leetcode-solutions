class Solution {
public:
    int daysBetweenDates(string date1, string date2) {
        vector<int>months={0,31,59,90,120,151,181,212,243,273,304,334,365};
        int leap1 = (getYear(date1) - 1968)/4 - (getYear(date1) == 2100? 1: 0);
        int leap2 = (getYear(date2) - 1968)/4 - (getYear(date2) == 2100? 1: 0);
        int d1 = (getYear(date1) - 1968)*365+leap1 + months[(getMonth(date1) -1)] + getDay(date1) + (((getYear(date1)%4) == 0 && getMonth(date1) < 3)? -1 : 0);
        int d2 = (getYear(date2) - 1968)*365+leap2 + months[(getMonth(date2) -1)] + getDay(date2)+ (((getYear(date2)%4) == 0 && getMonth(date2) < 3)? -1 : 0);
        
        return abs(d1-d2);

    }

 
    int getYear(string s){
        return stoi(s.substr(0, 4));
    }
    int getMonth(string s){
        return stoi(s.substr(5,2));
    }
    int getDay(string s){
        return stoi(s.substr(8));
    }
};