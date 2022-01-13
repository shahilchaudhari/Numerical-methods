#include <iostream>
using namespace std;

void luDecomposition(double** array,double** lower,double ** upper,int n);

int main(){

    int i,j,k,n;
    n=3;
    double **matrix = new double*[n];
    double **l=new double*[n];
    double **u= new double* [n];
    double **I=new double*[n];
    for(i=0;i<n;i++){
        matrix[i]= new double[n];
        l[i]=new double[n];
        u[i]=new double[n];
    }
    matrix[0][0]=1; matrix[0][1]=5; matrix[0][2]=1;
    matrix[1][0]=2; matrix[1][1]=1; matrix[1][2]=3;
    matrix[2][0]=3; matrix[2][1]=1; matrix[2][2]=4;


    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }

    luDecomposition(matrix,l,u,n);
    // lower triangular matrix
    cout<<"lower triangular matrix"<<endl;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cout<<l[i][j]<<" ";
        }
        cout<<endl;
    }
    // upper tringular matrix
    cout<<"upper triangular matrix"<<endl;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cout<<u[i][j]<<" ";
        }
        cout<<endl;
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