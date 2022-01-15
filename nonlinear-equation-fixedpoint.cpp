# include<iostream>
# include<math.h>
using namespace std;

void** fixed_point(int* n,double* initial_guess){
    int i;
    double function;
    for(i=0;i<*n;i++){
        //------------------------------------------
        //function should be such that slope of the function 
        // is less than 1 in order to get convergence
        //-----------------------------------------------
        function=pow((3*pow(*initial_guess,2)+3*(*initial_guess)+4),0.333);
        cout<<"iteration["<<i+1<<"] f("<<*initial_guess<<")="<<function<<endl;
        *initial_guess=function;
    }
    return 0;
}

int main(){
    int i,n;
    n=15; // number of iteration
    double guess=2.5;
    fixed_point(&n,&guess);

    return 0;
}
