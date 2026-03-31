/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {

        int lastEndtime = 0;
        int lastStarttime = INT_MAX;

        for(int i = 0; i < intervals.size(); i++){
            if(!(intervals[i].start >= lastEndtime) && !(intervals[i].end <= lastStarttime)){
                return false;
            }
            lastEndtime = intervals[i].end;
            lastStarttime = intervals[i].start;
        }

        return true;
        
    }
};
