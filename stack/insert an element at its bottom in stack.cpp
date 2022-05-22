// stack overflow
// https://stackoverflow.com/questions/45130465/inserting-at-the-end-of-stack
// Implement a method to insert an element at its bottom without using any other data structure.


void push_to_bottom(stack<int>&st,int x){
    if (st.empty()){
        st.push(x);
        return;
    }
    else{
        int a= st.top();
        st.pop();
        push_to_bottom(st,x);
        st.push(a);
    }
}

int main(){
    stack<int>st;
  
    st.push(2);
    st.push(3);
    
    push_to_bottom(st,4);
    push_to_bottom(st,10);
    push_to_bottom(st,12);

    while(!st.empty()){
        cout<<st.top()<<"      ";
        st.pop();
    }

    return 0;
}
