class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hourmov=360/12;
        double minmov=0.5;
        double min=360/60;

        hour=12-hour;
        double hourhand=(12-hour)*hourmov + minmov*minutes;
        double minutehand=minutes*min;

        double ans=abs(hourhand-minutehand);
        if(ans>360-ans){
            return 360-ans;
        }
        return ans;
    }
};
