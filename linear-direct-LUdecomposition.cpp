#include <iostream>
using namespace std;


#include <iostream>
using namespace std;

void luDecomposition(double** array,double** lower,double ** upper,int n);

void fbSubstitution(double** lower,double** upper,double* b,double* solution,int n);

int main(){

    int i,j,k,n;
    // dimenstion of square matrix
    n=3;

    double **matrix = new double*[n];
    double **l=new double*[n];
    double **u= new double* [n];
    // non homogeneous
    double *b=new double[n];
    // solution array
    double *soln=new double[n];
    
    for(i=0;i<n;i++){
        matrix[i]= new double[n];
        l[i]=new double[n];
        u[i]=new double[n];
    }
    // matrix                                       //non homogeneous part
    matrix[0][0]=1; matrix[0][1]=5; matrix[0][2]=1; b[0]=14;
    matrix[1][0]=2; matrix[1][1]=1; matrix[1][2]=3; b[1]=13;
    matrix[2][0]=3; matrix[2][1]=1; matrix[2][2]=4; b[2]=17;

    cout<<endl<<"Augmented matrix"<<endl;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<b[i]<<endl;
    }
    // lu factorization function
    luDecomposition(matrix,l,u,n);

    cout<<endl<<"lower triangular matrix"<<endl;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cout<<l[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<endl<<"upper triangular matrix"<<endl;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cout<<u[i][j]<<" ";
        }
        cout<<endl;
    }

    // calling function to get solution matrix
    fbSubstitution(l,u,b,soln,n);

    cout<<endl<<"solution"<<endl;
    for(i=0;i<n;i++){
        cout<<"X["<<i+1<<"] : "<<soln[i]<<endl;
    }

    return 0;
}

void luDecomposition(double** array,double** lower,double** upper,int n){
    int i,j,k;

    // Upper triangular matrix
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(i>j) upper[i][j]=0;
            else {
                upper[i][j]=array[i][j];
                for(k=0;k<i;k++){
                    upper[i][j]-=lower[i][k]*upper[k][j];
                }
            }
        }

        // Lower triangular matrix
        for(j=0;j<n;j++){
            if(i==j) lower[j][i]=1;
            else if(i>j) lower[j][i]=0;
            else{
                lower[j][i]=array[j][i]/upper[i][i];
                for(k=0;k<i;k++){
                    lower[j][i]-=lower[j][k]*upper[k][i]/upper[i][i];
                }
            }   
        }
    }

    return;
}

void fbSubstitution(double** lower,double** upper,double* b,double* solution,int n){
    int i,j;
    double* y= new double[n];

    //forward substitution
    for(i=0;i<n;i++){
        y[i]=b[i];
        for(j=0;j<i;j++){
            y[i]-=y[j]*lower[i][j];
        }
        // cout<<y[i]<<endl;
    }

    // baward substitution
    for(i=n-1;i>=0;i--){ 
        solution[i]=y[i]/upper[i][i];
        for(j=i+1;j<n;j++){
            solution[i]-=solution[j]*upper[i][j]/upper[i][i];
        } 
    }

    return;
}