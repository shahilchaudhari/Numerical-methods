# include<iostream>
# include<math.h>
using namespace std;

double nonLinearEqn(double* guess){
    double func = 3*(*guess)+sin(*guess)-exp(*guess);
    return func;
}

void** secant(int* n,double* initial_guess1,double* initial_guess2){
    int i;
    double function1,function2,function3,iter,dummy;
    for(i=0;i<*n;i++){
        //-----------------------------------------------------
        //convergence rate more than linear less than quadratic
        //-----------------------------------------------------
        function1=nonLinearEqn(initial_guess1);
        function2=nonLinearEqn(initial_guess2);
        //interpolation
        iter=(*initial_guess1)-function1*((*initial_guess1-*initial_guess2)/(function1-function2));
        function3=nonLinearEqn(&iter);
        
        cout<<endl; 
        cout<<"Iteration["<<i+1<<"]  xi-1="<<*initial_guess1<<"  f(xi-1)="<<function1<<"  xi="<<*initial_guess2<<"  f(xi)="<<function2<<"  xi+1="<<iter<<"  f(xi+1)="<<function3<<endl;
        // Updating successive iteration
        *initial_guess1=*initial_guess2;
        *initial_guess2=iter;
    }
    return 0;
}

int main(){
    int i,n;
    n=8; // number of iteration
    double guess1=0,guess2=1;

    secant(&n,&guess1,&guess2);

    return 0;
}
