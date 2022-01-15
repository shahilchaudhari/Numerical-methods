# include<iostream>
# include<math.h>
using namespace std;

double nonLinearEq(double* guess){
    double func;

    func =pow(*guess,3)-3*pow(*guess,2)+(*guess)-3;
    return func;
}

void** regula_falsi(int* n,double* initial_guess1,double* initial_guess2){
    int i;
    double function1,function2,function3,iter;
    for(i=0;i<*n;i++){
        //-----------------------------------------------------
        //convergence rate more than linear less than quadratic
        //-----------------------------------------------------
        function1=nonLinearEq(initial_guess1);
        function2=nonLinearEq(initial_guess2);
        //interpolation
        iter=(*initial_guess1)-function1*((*initial_guess1-*initial_guess2)/(function1-function2));
        function3=nonLinearEq(&iter);
        cout<<"Iteration ["<<i<<"]"<<"  (xn-1)="<<*initial_guess1<<"   f(xn-1)="<<function1<<"  (xn)="<<*initial_guess2<<"  f(xn)="<<function2<<"  (xn+1)="<<iter<<" f(xn+1)= "<<function3<<endl;

        // for positive slope
        if(function3<0){
            *initial_guess1=iter;
        }
        else if(function3>0){
            *initial_guess2=iter;
        }
    }
    return 0;
}

int main(){
    int i,n;
    n=9; // number of iteration
    double guess1=0,guess2=3.6;

    regula_falsi(&n,&guess1,&guess2);

    return 0;
}
