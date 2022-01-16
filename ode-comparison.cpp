#include<iostream>
#include<math.h>
#include<fstream>
#include<string>

using namespace std;

/// Exact solution of the ordinary differential equation

double ode_function(double* y_0,double* t,double* lamda){
    double y_n;
    y_n = exp(-(*t))+(*y_0-1)*exp(-(*lamda)*(*t));
    return y_n;
}

/// Impicit(Interpolation) method

double ode_implicit(double* y_i,double* t,double* interval,double* lamda){
    double y_n;
    //Entering simplified form of yn+1=yn + stepsize * (dy/dt|(tn+1,yn+1))
    y_n = (*y_i+exp(-*t)*(*interval)*(*lamda-1))/(1+(*interval)*(*lamda));
    return y_n;
}

/// Explicit(Extrapolation) method

double ode_explicit(double* y_i,double* t,double* interval,double* lamda){
    double y_n;
    // Entering yn+1=yn + stepsize* (dy/dt|(tn,yn))
    y_n = *y_i*(1-(*lamda)*(*interval))+exp(-*t)*(*lamda-1)*(*interval);
    return y_n;
}

double hue(double* y_i,double* t,double* interval,double* lamda){
    double y_n,y_nplus1_predict,slope1,slope2;

    // extrapolated value using initial conditions
    y_nplus1_predict = *y_i + *interval*(-(*lamda)*(*y_i-exp(-(*t)))-exp(-(*t)));

    // avg of slope 1  and slope is taken find yn+1
    slope1=-(*lamda)*(*y_i-exp(-(*t)))-exp(-(*t));
    slope2=-(*lamda)*(y_nplus1_predict-exp(-(*t)-(*interval)))-exp(-(*t)-(*interval));
    y_n = *y_i + *interval/2*(slope1+slope2);
    //cout<<y_n<<endl;
    return y_n;
}

double RK_method(double* y_i,double* t,double* interval, double* lamda){
    double y_n;
    double k1,k2,k3,k4;
    // y_dash = -(*lamda)*(*y_i-exp(-(*t)))-exp(-(*t));
    k1 = -(*lamda)*(*y_i-exp(-(*t)))-exp(-(*t));
    k2 = -(*lamda)*((*y_i+0.5*(*interval)*k1)-exp(-(*t+0.5*(*interval))))-exp((*t+0.5*(*interval)));
    k3 = -(*lamda)*((*y_i+0.5*(*interval)*k2)-exp(-(*t+0.5*(*interval))))-exp((*t+0.5*(*interval)));
    k4 = -(*lamda)*((*y_i+(*interval)*k3)-exp(-(*t+(*interval))))-exp(-(*t+(*interval)));
    y_n = *y_i+((*interval)/6*(k1+2*k2+2*k3+k4));
    return y_n;
}
int main(){

    // defining nececarry values
    int n,j,i;
    double y_0,lamda,t,start,stop,interval;
    y_0=10; lamda=10; start=0; stop=0.8; 
    // Enter  interval 0.1,0.05,0.025,0.0125,0.00625
    interval=0.1;
    n=(stop-start)/interval+1;
    cout<<"No of iteration"<<n<<endl;

    ofstream file;
    file.open("Iteration.csv");


    // creating arrays
    double* exact=new double[n];
    double* t_n=new double[n];
    double* implicit_solution = new double[n];
    double* explicit_solution = new double[n];
    double* hue_solution = new double[n];
    double* RK = new double[n];

    for(i=0;i<n;i++){
        t_n[i]=interval*i;
    }

    for(i=0;i<n;i++){

        exact[i]=ode_function(&y_0,&t_n[i],&lamda);
        implicit_solution[0]=y_0;
        explicit_solution[0]=y_0;
        hue_solution[0]=y_0;
        RK[0]=y_0;

        if (i==0)
        continue;
        else{
            implicit_solution[i]=ode_implicit(&implicit_solution[i-1],&t_n[i],&interval,&lamda);
            explicit_solution[i]=ode_explicit(&explicit_solution[i-1],&t_n[i-1],&interval,&lamda);
            RK[i]=RK_method(&RK[i-1],&t_n[i-1],&interval,&lamda);
            hue_solution[i]=hue(&hue_solution[i-1],&t_n[i-1],&interval,&lamda);
        }
        // cout<<"Itreation["<<i<<"]  implicit :"<<implicit_solution[i]<<" Explicit: "<<explicit_solution[i]<<" Exact :"<<exact[i]<<endl;
    }

    file<<"interval"<<","<<interval<<endl;
    file<<"Iteration"<<","<<"time"<<","<<"exact"<<","<<"Implicit"<<","<<"explicit"<<","<<"hue"<<","<<"RK method"<<endl;
    for(i=0;i<n;i++){
        cout<<"Itreation["<<i<<"] (t_n="<<t_n[i]<<") Exact :"<<exact[i]<<" implicit :"<<implicit_solution[i]<<" Explicit: "<<explicit_solution[i]<<" Hue Method: "<<hue_solution[i]<<" RK method: "<<RK[i]<<endl;
        file<<i<<","<<t_n[i]<<","<<exact[i]<<","<<implicit_solution[i]<<","<<explicit_solution[i]<<","<<hue_solution[i]<<","<<RK[i]<<endl;
    }
    return 0;   
}