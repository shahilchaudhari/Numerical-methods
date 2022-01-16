# include<iostream>
# include<math.h>
# include<fstream>
# include<iomanip>
using namespace std;

double eqn(double x){
    double u = 7 - x*tan(x);
    return u;
}

double y_dash(double x){
    double dy = -tan(x)-x/pow(cos(x),2);
    return dy;
}

void forward_difference(double x,double interval,double* oder1,double* oder2,double* oder4){
    double oder_1,oder_2,oder_4;

    oder_1 = (eqn(x+interval)-eqn(x))/interval;
    oder_2 = (4*eqn(x+interval)-eqn(x+2*interval)-3*eqn(x))/(2*interval);
    oder_4 = (4*eqn(x+interval)-3*eqn(x+2*interval)+4/3*eqn(x+3*interval)-1/4*eqn(x+4*interval)-25/12*eqn(x))/interval;
    *oder1=oder_1;
    *oder2=oder_2;
    *oder4=oder_4;

    return;
}

int main(){
    int i,n;
    cout.precision(10);
    cout.setf(ios::fixed);

    ofstream file1;
    double start=-1, stop=1, interval=0.1;
    n=(stop-start)/interval+1;

    double* t=new double[n];
    double* first=new double[n];
    double* second= new double[n];
    double* fourth=new double[n];
    double* exact=new double[n];

    for(i=0;i<n;i++){
        t[i]=start + i*interval;
        exact[i]=y_dash(t[i]);
        // cout<<t[i]<<endl;
    }

    file1.open("assignment5_q2.csv");
    file1<<endl<<"h="<<interval<<endl;
    file1<<"Iteration"<<","<<"x"<<","<<"First oder"<<","<<"Second oder"<<","<<"Fourth oder"<<","<<"Exact"<<","<<"log(x)"<<","<<"1oder_error"<<","<<"2oder_error"<<","<<"4oder_error"<<endl;
    for(i=0;i<n;i++){
        forward_difference(t[i],interval,&first[i],&second[i],&fourth[i]);
        cout<<first[i]<<" "<<second[i]<<"   "<<fourth[i]<<" "<<exact[i]<<endl;
        file1<<i<<","<<t[i]<<","<<first[i]<<","<<second[i]<<","<<fourth[i]<<","<<exact[i]<<","<<abs(log(abs(t[i])))<<","<<abs(log(abs(exact[i]-first[i])))<<","<<abs(log(abs(exact[i]-second[i])))<<","<<abs(log(abs(exact[i]-fourth[i])))<<endl;
    }

    file1.close();
    return 0;
}

