class Solution {
public:
    string dayOfTheWeek(int day, int month, int year) {
        
        vector<string> week = {
            "Sunday", "Monday", "Tuesday",
            "Wednesday", "Thursday", "Friday", "Saturday"
        };
        
        int daysInMonth[] = {
            31, 28, 31, 30, 31, 30,
            31, 31, 30, 31, 30, 31
        };
        
        int total = 0;
        
        // Count complete years
        for (int i = 1971; i < year; i++) {
            if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0)
                total += 366;
            else
                total += 365;
        }
        
        // Leap year
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
            daysInMonth[1] = 29;
        
        // Count complete months
        for (int i = 0; i < month - 1; i++) {
            total += daysInMonth[i];
        }
        
        // Days before the given date
        total += day - 1;
        
        // 1 Jan 1971 was Friday
        return week[(total + 5) % 7];
    }
};