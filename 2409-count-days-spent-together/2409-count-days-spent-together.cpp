class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        string start=max(arriveAlice,arriveBob);
        string end=min(leaveAlice,leaveBob);

        if(start>end)
            return 0;

        int days[]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        auto convert=[&](string s){
            int month=stoi(s.substr(0, 2));
            int day=stoi(s.substr(3, 2));
            for(int i=0;i<month-1;i++)
                day += days[i];
            return day;
        };
    return convert(end)-convert(start)+1;
    }
};