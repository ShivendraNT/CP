class Solution {
public:
    int secondsBetweenTimes(string startTime, string endTime) {
        //converting seconds 
        int starthr=startTime[1]-'0';
        starthr+=(startTime[0]-'0')*10;
        int endhr=endTime[1]-'0';
        endhr+=(endTime[0]-'0')*10;
        int startmin=startTime[4]-'0';
        startmin += (startTime[3]-'0')*10;
        int endmin=endTime[4]-'0';
        endmin += (endTime[3]-'0')*10;
        int startsec=startTime[7]-'0';
        startsec+=(startTime[6]-'0')*10;
        int endsec=endTime[7]-'0';
        endsec += (endTime[6]-'0')*10;

        int sec=0;
        sec+=startsec-endsec;
        sec+= (startmin-endmin)*60;
        sec+= (starthr-endhr)*3600;
        return -1*sec;
    }
};
