class MyCalendar {
public:
    map<int,int>DiffArr;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        DiffArr[start]++;
        DiffArr[end]--;
        int booking=0;
        for(auto&val:DiffArr){
            booking+=val.second;
            if(booking>=2){
                //remove this added event
                DiffArr[start]--;
                DiffArr[end]++;
                return false;
            }
        }
    return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
