# include<iostream>
using namespace std;

int main(){
    double x,y,z,xnew,ynew,znew;
    int i,n;
    n=16;
    x=0,y=0;
    for(i=0;i<n;i++){

        xnew=x,ynew=y,znew=z;
        x = 0.75-ynew*0.125+0.5*xnew;
        y = 2.5-1.5*xnew+0.5*ynew;
        cout<<"iteration  "<<i<<endl;
        cout<<"X "<<x<<endl;
        cout<<"Y "<<y<<endl;
    }
}