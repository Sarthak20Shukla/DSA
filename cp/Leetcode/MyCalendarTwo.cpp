class MyCalendarTwo {
public:
vector<pair<int,int>> checkdoublebooking;
vector<pair<int,int>> overallbooking;

    MyCalendarTwo() {
        
    }
    bool checkBooking(int a1,int b1,int a2,int b2){
        return (max(a1,a2)<min(b1,b2));
    }
    pair<int,int> givedouiblebooking(int a1,int b1,int a2,int b2){
        return {max(a1,a2),min(b1,b2)};
    }
    bool book(int start, int end) {
        for(pair<int,int> p:checkdoublebooking){
            if(checkBooking(p.first,p.second,start,end)){
                return false;
            }
        }
                for(pair<int,int> b:overallbooking){
                    if(checkBooking(b.first,b.second,start,end)){
                        checkdoublebooking.push_back(givedouiblebooking(b.first,b.second,start,end));
                    }
                }
        overallbooking.push_back(pair{start,end});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */