#include <iostream>
#include <math.h>
using namespace std;

void** ode_implicit_explicit(double* initialvalue,double* start,double* stop,double* interval){
    int i,n;
    double y_npus1;
    n=((*stop-*start)/(*interval))+1;
    double* exact=new double[n];
    double* implicit=new double[n];
    double* _explicit=new double[n];

    implicit[0]=*initialvalue;
    _explicit[0]=*initialvalue;

     cout<<endl;
    //-------------------------------------------
    //Exact solution for ODE 
    //-----------------------------------------
    for(i=0;i<n;i++){
        exact[i]=exp(-10*i*(*interval));
        cout<<"Exact_solution["<<i<<"] at t="<<i*(*interval)<<" : "<<exact[i]<<endl;
    }
    cout<<endl;

    //-------------------------------------------
    //Euler Implicit(Interpolation) method for ODE 
    //-----------------------------------------
    for(i=1;i<n;i++){
        //------------------------------------------------
        //Entering yn+1=yn + stepsize* (dy/dt|(tn+1,yn+1))
        //------------------------------------------------
        implicit[i]= implicit[i-1]/(1+10*(*interval));
        cout<<"Implicit_Iteration["<<i<<"]: "<<implicit[i]<<endl;
    }
    cout<<endl;

    //-------------------------------------------
    //Euler Explicit(Extrapolation) method for ODE 
    //----------------------------------------------
    for(i=1;i<n;i++){
        //----------------------------------------------
        //Entering yn+1=yn + stepsize* (dy/dt|(tn,yn))
        //--------------------------------------------
        _explicit[i]=_explicit[i-1]*(1-10*(*interval));
        cout<<"Explicit_Iteration["<<i<<"]: "<<_explicit[i]<<endl;
    }
    return 0;
}

int main(){
    int i,j,n;
    double y0=1;
    double interval,start,stop,lamda;
    start=0; stop=0.8; ;lamda=10; interval=0.1;
    
    ode_implicit_explicit(&y0,&start,&stop,&interval);

    return 0;
}