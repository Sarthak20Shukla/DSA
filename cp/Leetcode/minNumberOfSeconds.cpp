class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        auto isPossible = [&](int sarbadhiksamay, int mountainHeight, vector<int>& workerTimes) {
            int TotHght = 0;
            for (int samay : workerTimes) {
                int bartamanH = 0;
                int bartaman = 0;
                while (bartaman + (bartamanH + 1) * samay <= sarbadhiksamay) {
                    bartamanH += 1;
                    bartaman += bartamanH * samay;
                }
                TotHght += bartamanH;

                if (TotHght >= mountainHeight) {
                    return true;
                }
            }
            return TotHght >= mountainHeight;
        };

        int nich = 0, uchh = 1;
        while (!isPossible(uchh, mountainHeight, workerTimes)) {
            uchh *= 2;
        }

        while (nich < uchh) {
            int middd = (nich + uchh) / 2;
            if (isPossible(middd, mountainHeight, workerTimes)) {
                uchh = middd;
            } else {
                nich = middd + 1;
            }
        }
        return nich;
    }
};