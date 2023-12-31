class SmallestInfiniteSet {
public:
    unordered_map<int,int> mp;
    priority_queue<int,vector<int>,greater<int>> pq;
    SmallestInfiniteSet() {
        for(int i = 1;i<=1000;i++){
            pq.push(i);
        }
    }
    
    int popSmallest() {
        int ele = pq.top();
        pq.pop();
        mp[ele] = 1;
        return ele;
    }
    
    void addBack(int num) {
        if(mp.count(num)){
            mp.erase(num);
            pq.push(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
