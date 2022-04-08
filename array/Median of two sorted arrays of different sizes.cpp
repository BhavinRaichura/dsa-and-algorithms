
// Median of two sorted arrays of different sizes



int medianOfSameSizeSortedArray(int a1[],int a2[],int n1,int n2){
    int n =n1+n2;
    int p=0, q=0,m1=0,m2=0;

    for(int  i=0;i<=n/2;i++){
        m1=m2;
        // if we reached last element of array1 then start array2 for next operations
        if(p==n){
            m2=a2[q];
            q++;
        }
      // if we reached last element of array2 then start array1 for next operations
        else if(q==n){
            m2=a1[p];
            p++;
        }
      
        //
        else if (a1[p]<a2[q]){
            m2=a1[p];
            p++;
        }
        else if (a2[q]<=a1[p]){
            m2=a2[q];
            q++;
        }
    }
  
    // if total size of both array is a even number
    if (n%2==0)  
        return (m1+m2)/2;
    // if odd then
    return m2;

}


int main(){
    int ar1[] = {900};
    int ar2[] = {5,8,10,20};
    cout<<medianOfSameSizeSortedArray(ar1,ar2,1,4);

}
