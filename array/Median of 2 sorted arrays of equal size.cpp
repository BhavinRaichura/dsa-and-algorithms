// Median of 2 sorted arrays of equal size


// ---------------------------------------------------------------------------------------------------
// Time complexity O(n)

int medianOfSameSizeSortedArray(int a1[],int a2[],int n){
    int p=0, q=0,m1=0,m2=0;

    for(int  i=0;i<=n;i++){
        if(p==n){
            m1=m2;
            m2=a2[0];
            break;
        }
        else if(q==n){
            m1=m2;
            m2=a1[0];
            break;
        }
        if (a1[p]<a2[q]){
            m1=m2;
            m2=a1[p];
            p++;
        }
        else if (a2[q]<=a1[p]){
            m1=m2;
            m2=a2[q];
            q++;
        }
    }
    return (m1+m2)/2;

}





/*--------------------------------------------------------------------------------------------------------------------*/

// Time Complexity O(log n)
// recursion



//-------------------------------------------------------------------------------------------------------------------
// main function

int main(){
    int ar1[] = {1, 12, 15, 26, 38};
    int ar2[] = {2, 13, 17, 30, 45};
    cout<<"median using O(n) method: "<<medianOfSameSizeSortedArray(ar1,ar2,5);
  cout<<"median using O(log n) method: "<<recursiveMethodOfMedium();

}
