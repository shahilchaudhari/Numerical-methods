# include<iostream>
# include<math.h>
# include<iomanip>
#include<fstream>
using namespace std;

// exact solution formulae
double exact_solution(double* t){
    double y_n = -2*(*t-1)-3*exp(-(*t));
    return y_n;
}

// ODE 
double y1_dash(double* t,double* y1,double* y2){
    double y_n1 = *y2;
    return y_n1;
}

double y2_dash(double*t, double* y1,double*y2){
    double y_n2= -16*(*y1);
    return y_n2;
}

void RK_system(double* t,double* y1,double* y2,double* interval,double* y1plus,double* y2plus){
    double yn_1,yn_2,tinst,y1inst,y2inst,h;
    double k11,k12,k21,k22,k31,k32,k41,k42;
    double tk2,yk21,yk22,tk3,yk31,yk32,tk4,yk41,yk42;

    tinst = *t;
    y1inst = *y1;
    y2inst = *y2;
    h = *interval;

    cout<<endl;
    cout<<"tn="<<tinst<<" y1="<<y1inst<<" y2="<<y2inst<<endl;

    // determining k11 and k12
    k11 = y1_dash(&tinst,&y1inst,&y2inst);
    k12 = y2_dash(&tinst,&y1inst,&y2inst);
    cout<<"k11 ="<<k11<<"  k12= "<<k12<<endl;

    // determining k21 and k22
    tk2=tinst+h/2; yk21 = y1inst+h/2*k11; yk22= y2inst +h/2*k12;
    k21=y1_dash(&tk2,&yk21,&yk22);
    k22=y2_dash(&tk2,&yk21,&yk22);
    cout<<"k21 ="<<k21<<"  k22 "<<k22<<endl;

    // determining k31 and k32
    tk3=tinst+h/2; yk31 = y1inst+h/2*k21; yk32= y2inst +h/2*k22;
    k31=y1_dash(&tk3,&yk31,&yk32);
    k32=y2_dash(&tk3,&yk31,&yk32);
    cout<<"k31= "<<k31<<"  k32 ="<<k32<<endl;

    // determining k41 and k42
    tk4=tinst+h; yk41 = y1inst+h*k31; yk42= y2inst+h*k32;
    k41=y1_dash(&tk4,&yk41,&yk42);
    k42=y2_dash(&tk4,&yk41,&yk42);
    cout<<"k41= "<<k41<<"  k42= "<<k42<<endl;

    yn_1 = y1inst+h/6*(k11+2*k21+2*k31+k41);
    yn_2 = y2inst+h/6*(k21+2*k22+2*k32+k42); 
    
    *y1plus=yn_1;
    *y2plus=yn_2;

    return;
}

int main(){ 
    int i,j,k,n;
    double y_01=1, y_02=0, start=0, stop=9, interval=0.1;
    n=(stop-start)/interval+1;
    cout<<"No of iteration="<<n<<endl;

    double* t_n =new double[n+1];
    double* exact_y1 = new double[n];
    double* exact_y2 = new double[n];
    double* rk_y1 = new double[n];
    double* rk_y2 = new double[n];

    for(i=0;i<n+1;i++){
        t_n[i]=interval*i;
        //cout<<t_n[i]<<endl;
    }

    for(i=0;i<n;i++){
        // populating arrays by calling functions
        //exact[i]=exact_solution(&t_n[i]);
        rk_y1[0]=y_01;
        rk_y2[0]=y_02;
        if (i==0)
        continue;
        else{
        RK_system(&t_n[i-1],&rk_y1[i-1],&rk_y2[i-1],&interval,&rk_y1[i],&rk_y2[i]);   
        }
    }

    cout<<endl;
    for(i=0;i<n;i++){
        cout<<"iteration["<<i<<"]  "<<"y("<<t_n[i]<<") "<<" y1="<<rk_y1[i]<<" y2="<<rk_y2[i]<<endl;
    }
    
    return 0;
}