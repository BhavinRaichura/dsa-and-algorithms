

#include <bits/stdc++.h>
using namespace std;

class Circle{
public:
    int x, y ,radius;
    Circle(int a,int b,int c){
        x= a;
        y= b;
        radius = c;
    }
};

int main(){
    vector<Circle>v;
    int n;

    cin>>n;

    for(int i=0;i<n;i++){
        int a,b,c;
        cin>>a>>b>>c;
        v.push_back({a,b,c});

    }

    sort(v.begin(),v.end(),[](Circle c1, Circle c2){
        if(c1.x == c2.x and c1.y != c2.y)
            return c1.y < c2.y;
        else if(c1.x == c2.x and c1.y == c2.y)
            return c1.radius <c2.radius;
       return c1.x < c2.x;
    });

    int prev = 0;

    int verticle  =0, horizontal =0,cnt =1;

    for(int i=1;i<n;i++){
        verticle = pow(v[prev].y - v[i].y,2);
        horizontal = pow(v[prev].x - v[i].x,2);

        int dis = sqrt(verticle + horizontal);

        if(dis>  v[prev].radius + v[i].radius){
            cnt++;
            prev = i;
        }

    }

    cout<<endl<<"answer: "<< n - cnt;



    return 0;

}
