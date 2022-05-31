#### heap

    // heap is a complete binary tree
    // every parent node has higher value then its child
    // every subtree is a heap

#### Properties 

    // parrent node = (n/2)th node
    // child node = left (2*n+1)th node and right (2*n+2)th node

#### Example

    // before insertion
    // arr = {15, 20, 12, 13, 19, 11}
    // after insertion and befor deletion
    // arr ={20, 19, 12, 13, 15, 11}
    // after deletion
    // arr = { 11,12,13,15,19,20 }
    // insert 1 element = log(n) time
    // delete 1 element = log(n) time


#### code

    void insertIntoHeap(vector<int>&arr,int n){
        // n = last element of array which gonna need to add in heap
        while(n>0 and arr[n/2]<arr[n]){
            int k = arr[n];
            arr[n]=arr[n/2];
            arr[n/2]=k;
            n=n/2;
        }
        cout<<"max heap:  "<<arr[0]<<endl;
    }

    void insertHeapRecursively(vector<int>&arr,int n){

        if(n>0 and arr[n/2]<arr[n]){
            int k = arr[n];
            arr[n]=arr[n/2];
            arr[n/2]=k;
            n=n/2;

            insertHeapRecursively(arr,n);
        }
        else
            return;
    }

    int topHeap(vector<int>&arr){
        return arr[0];
    }

    void deleteHeap(vector<int>&arr,int n){
        // n = index of last element of array which we are adding to heap
        int x= arr[0];
        arr[0]=arr[n];
        int i =0;
        int j=2*i+1;

        while(j<n){
            if(arr[j]<arr[j+1]){
                j = j+1;
            }
            if(arr[i]<arr[j]){
                swap(arr[i],arr[j]);
                i = j;
                j = 2*i+1;
            }
            else
                break;
        }

        cout<<"   deleted element:  "<<x<<" new top is: "<<arr[0]<<endl;
        arr[n]=x;
    }


    int main(){
        vector<int>arr;
        arr.push_back(1);
        cout<<"max heap:  "<<arr[0]<<endl;
        int x=0;

        for(int i=0;i<5;i++){
            cin>>x;
            arr.push_back(x);
            insertHeapRecursively(arr,i+1);
            cout<<"   max heap:  "<<arr[0]<<endl;
        }

        cout<<"\n-------------------------------------------\n";

        for(int i=0;i<arr.size();i++){
            deleteHeap(arr,arr.size()-1-i);
        }

        cout<<"\n-------------------------------------------\n";

        for(int i=0;i<arr.size();i++){
            cout<<arr[i]<<"    ";
        }

        return 0;
    }
