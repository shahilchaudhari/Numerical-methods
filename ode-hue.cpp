# include<iostream>
# include<math.h>
using namespace std;

// exact solution formulae
double exact_solution(double* t){
    double y_n = -2*(*t-1)-3*exp(-(*t));
    return y_n;
}

// ODE 
double y_dash(double* t,double* y_i){
    double y_n = -2*(*t)-(*y_i);
    return y_n;
}

double hue(double* t, double* y_i,double* interval){
    double y_n;
    double slope1,slope2,tinst,yinst,h,ypredict,tpredict;

    tinst=*t;  yinst=*y_i; h=*interval;
    slope1=y_dash(&tinst,&yinst);

    ypredict=yinst+h*slope1; tpredict=h+tinst;
    slope2=y_dash(&tpredict,&ypredict);

    y_n=yinst+h/2*(slope1+slope2);
    cout<<"slope1:"<<slope1<<" slope2:"<<slope2<<"  yn+1="<<y_n<<endl;

    return y_n;
}

int main(){
    int n,j,i;
    double y_0,lamda,t,start,stop,interval;
    y_0=-1; start=0; stop=0.5; interval=0.1;
    n=(stop-start)/interval+1;
    cout<<"No of iteration"<<n<<endl;

    double* semi_imp=new double[n];
    double* exact= new double[n];
    double* t_n=new double[n+1];
    for(i=0;i<n+1;i++){
        t_n[i]=i*interval;
    }

    for(i=0;i<n;i++){
        // populating arrays by calling functions
        exact[i]=exact_solution(&t_n[i]);
        semi_imp[0]=y_0;
        if (i==0)
        continue;
        else{
        semi_imp[i]=hue(&t_n[i-1],&semi_imp[i-1],&interval);    
        }
    }
    cout<<endl;
    for(i=0;i<n;i++){
        cout<<"Exact :"<<exact[i]<<" Semi implicit :"<<semi_imp[i]<<endl;
    }
}