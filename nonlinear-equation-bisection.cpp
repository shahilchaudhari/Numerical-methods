# include<iostream>
# include<math.h>
# include <iomanip>
using namespace std;

double nonLinFunction(double* guess){
    //------------------------------------------
    // Introducing non linear function f(x)=0
    //------------------------------------------
    
    double func;
    func=3*(*guess)+sin(*guess)-exp(*guess);
    return func;
}

void** bisection_nonlinear(int* n,double* initial_guess1,double* initial_guess2){
    double function1,function2,bisect,function3;
    for(int i=0;i<*n;i++){

        // bisection=(guess1+guess2)/2
        bisect = (*initial_guess1+*initial_guess2)/2; 

        function1 = nonLinFunction(initial_guess1);
        function2 = nonLinFunction(initial_guess2);
        function3 = nonLinFunction(&bisect);

        //--------------------------
        //Printing Iteration Values
        //--------------------------

        cout<<"iteration["<<i+1<<"]=";
        cout<<"f("<<*initial_guess1<<")"<<":"<<fixed<<setprecision(6)<<function1<<"  ";
        cout<<"f("<<*initial_guess2<<")"<<":"<<fixed<<setprecision(6)<<function2<<"  ";
        cout<<"(a+b)/2="<<bisect<<",  f("<<bisect<<")"<<":"<<fixed<<setprecision(10)<<function3<<endl;

        //--------------------------------------------------
        // Updating values of guess in order to get solution
        //---------------------------------------------------
        // if the function have positive slope for given interval
        if(function1<0){
            if(function3>0){
                *initial_guess2=bisect;
            }
            else if (function3<0){
                *initial_guess1=bisect;
            }
            else{
                cout<<"f(x)=0"<<endl;
                break;
            }
        }
        // If the function has negative slop for given interval
        else if(function2<0){
            if(function3>0){
                *initial_guess1=bisect;
            }
            else if (function3<0){
                *initial_guess2=bisect;
            }
            else{
                cout<<"f(x)=0"<<endl;
                break;
            }
        }
    }
    return 0;
}

int main(){
    int i,n;
    double guess1,guess2,a,b;
    n=20; // number of Iterations
    //---------------------------------------------------
    // guesses should be in such a way that one guess 
    // will give positive value and another give negative value ]
    // of when we put it in function
    //-------------------------------------------------
    
    // for interval (-1,0)
    cout<<endl;
    guess1=0; 
    guess2=1;
    cout<<"For interval "<<guess1<<" - "<<guess2<<"------------------------------------"<<endl;
    bisection_nonlinear(&n,&guess1,&guess2);
    cout<<endl;
    cout<<endl;

    //for interval (0,1)

    cout<<endl;
    a =0.15; b=0.9;
    cout<<"For interval "<<a<<" - "<<b<<"------------------------------------"<<endl;
    bisection_nonlinear(&n,&a,&b);
    return 0;
}