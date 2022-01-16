# include<iostream>
using namespace std;

int main(){
    double x,y,z;
    int n=4,i;
    x=0,y=0,z=0;
    for(i=0;i<n;i++){
        x=(8-y-2*z)/3;
        y=(11-2*x-z)/7;
        z=(9-x-2*y)/3;
        cout<<"Interation :"<<i<<endl;
        cout<<"x"<<x<<endl;
        cout<<"y"<<y<<endl;
        cout<<"z"<<z<<endl;
        
    }
}

