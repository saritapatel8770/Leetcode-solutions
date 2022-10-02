class MedianFinder {

public:
    priority_queue<int> small;
    priority_queue<int,vector<int>,greater<int>> large;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(small.empty() || num < (int)small.top()) small.push(num);
        else large.push(num);
        
        if(small.size() > large.size() && small.size() - large.size() > 1) {
            int x = small.top();
            large.push(x);
            small.pop();
        }       
        else if(large.size() > small.size() && large.size() - small.size() > 1) {
            int x = large.top();
            large.pop();
            small.push(x);            
        }
        return ;
    }
    
    double findMedian() {
        int n = large.size() + small.size();
        if(n%2 == 1 ) { 
            if(small.size() > large.size()) return small.top();
            else return large.top();
        }
        return (double)(small.top() + large.top())/2.0;
    }
};
