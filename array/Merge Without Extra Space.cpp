// Merge Without Extra Space 


//---------------------------------------------------------without using extra space-----------------------------------------------------------------------
void merge(int arr1[], int arr2[], int n, int m){
        int i=n-1;
        int j=0;
        
        while(i>=0 && j<m){
            if (arr1[i]<=arr2[j]){
                j++;
            }
            else{
                swap(arr1[i],arr2[j]);
                i--;
                j++;
            }
                
        }
        sort(arr1,arr1+n);
        sort(arr2,arr2+m);
}




//------------------------------------------------merge using extra space------------------------------------------------------------------------------

// 

void merge(int arr1[], int arr2[], int n, int m) {
    // code here
    queue<int>que;
    int i=0,j=0;
    for (int count =0;count<n+m;count++){
        if (i==n ){
            que.push(arr2[j]);
            j++;
        }
        else if (j==m ){
            que.push(arr1[i]);
            i++;
        }
        else if (arr1[i]>=arr2[j]){
            que.push(arr2[j]);
            j++;
        }
        else{
            que.push(arr1[i]);
            i++;

        }
    }

    i=0;
    j=0;
    while(!que.empty()){
       if (i<n) {
            arr1[i] = que.front();
            i++;
        }
        else {
            arr2[j] = que.front();
            j++;
        }
        que.pop();
    }
}






// -----------------------------------------main function--------------------------------------------
int main(){
    int ar1[] = {1, 3, 5, 7};
    int ar2[] = {0, 2, 6, 8, 9};
    merge(ar1,ar2,4,5);
   for(int i =0;i<4;i++){
        cout<<"   "<<ar1[i];
    }
    cout<<"\n-------------\n";
    for(int i =0;i<5;i++){
        cout<<"  "<<ar2[i];
    }

}
