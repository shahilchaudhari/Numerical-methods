# include<iostream>
# include<math.h>
# include<iomanip>
using namespace std;

// exact solution formulae
double exact_solution(double* t){
    double y_n = 3*exp(-3*(*t));
    return y_n;
}

// ODE 
double y_dash(double* t,double* y_i){
    double y_n = -3*(*y_i);
    return y_n;
}

// Definig rk method function
double RK_method(double* t,double* y_i,double* interval){
    double y_n,k1,k2,k3,k4;
    double yinst, tinst,h,tk2,yk2,tk3,yk3,tk4,yk4;
    tinst = *t;
    yinst = *y_i;
    h = *interval;

    k1 = y_dash(&tinst,&yinst);  // explicit slope

    tk2=tinst+0.5*h; yk2=yinst+0.5*h*k1;
    k2 = y_dash(&tk2,&yk2);  // intermediate slope

    tk3=tinst+0.5*h; yk3=yinst+0.5*h*k2;
    k3 = y_dash(&tk3,&yk3); // intermediate slope

    tk4=tinst+h;     yk4=yinst+h*k3;
    k4 = y_dash(&tk4,&yk4); //implicit slope

    y_n = yinst + h/6*(k1+2*k2+2*k3+k4);
    cout<<"tn="<<*t<<"  yn="<<*y_i<<"  k1:"<<k1<<"   k2:"<<k2<<"   k3:"<<k3<<"   k4:"<<k4<<"  yn+1= "<<y_n<<endl;
    cout<<endl;
    return y_n;

}


int main(){
    int n,j,i;
    double y_0,t,start,stop,interval;
    y_0=3; start=0; stop=0.4; interval=0.2;
    n=(stop-start)/interval+1;

    cout.precision(7);
    cout.setf(ios::fixed);
    cout<<"No of iteration"<<n<<endl;

    double* t_n =new double[n+1];
    double* exact = new double[n];
    double* rk = new double[n];

    for(i=0;i<n+1;i++){
        t_n[i]=interval*i;
        //cout<<t_n[i]<<endl;
    }

    for(i=0;i<n;i++){
        // populating arrays by calling functions
        exact[i]=exact_solution(&t_n[i]);
        rk[0]=y_0;
        if (i==0)
        continue;
        else{
        rk[i]=RK_method(&t_n[i-1],&rk[i-1],&interval);    
        }
    }

    for(i=0;i<n;i++){
        cout<<"iteration ["<<i<<"]EXAct: "<<exact[i]<<" rk method: "<<rk[i]<<" error :"<<abs((exact[i]-rk[i])/exact[i])<<endl;
    }

    return 0;

}