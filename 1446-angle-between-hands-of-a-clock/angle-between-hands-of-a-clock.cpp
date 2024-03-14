class Solution {
public:
    double angleClock(int hour, int minutes) {
        int dom = 6*minutes;
        double doh = (30*hour)+(0.5*minutes);
        double diff = abs(doh-dom);

        return min(diff, 360-diff);
    }
};