class KthLargest {
public:
priority_queue<int, vector<int>, greater<int>> pq;
int K;

 KthLargest(int k, vector<int>& nums) {
        
        K=std::move(k);
        for(int num:nums){
            pq.push(num);
            if(pq.size()>K) pq.pop();
        }
    }

int add(int val) {
        pq.push(val);
        if (pq.size() > K) pq.pop();

        return pq.top();
    }
};
