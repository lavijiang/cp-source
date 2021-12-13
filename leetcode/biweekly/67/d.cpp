https://leetcode-cn.com/problems/sequentially-ordinal-rank-tracker/

//最小最大堆

class SORTracker {
public:
    typedef pair<int,string> PIS;
    struct comp1{
        bool operator()(const PIS& p1, const PIS& p2){
            if(p1.first==p2.first)
                return p1.second<p2.second;
            return p1.first>p2.first;
        }
    };
    
    struct comp2{
        //定义的是小于比较。大的在数组最后（堆顶），所以是大根堆
        bool operator()(const PIS& p1, const PIS& p2){
            if(p1.first==p2.first)
                return p1.second>p2.second;
            return p1.first<p2.first;
        }
    };
    priority_queue<PIS,vector<PIS>,comp2> maxp; //大根堆
    priority_queue<PIS,vector<PIS>,comp1> minp; //小根堆

    SORTracker() { 
    }
    
    void add(string name, int score) {
        minp.push({score,name});
        maxp.push(minp.top());
        minp.pop();
    }
    
    string get() {
        string res = maxp.top().second;
        minp.push(maxp.top());
        maxp.pop();
        return res;
    }
};
