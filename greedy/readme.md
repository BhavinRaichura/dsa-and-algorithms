# Greedy

## max heap 
            priority_queue<int>maxHeap;
            
## Min heap
            priority_queue<int,vector<int>,greater<int>>minHeap;

## custom sort
            sort(arr, arr+n,[](pair<int,int> i1, pair<int,int> i2){
                        return (i1.first / i1.second) > (i2.first / i2.second);
                    });
