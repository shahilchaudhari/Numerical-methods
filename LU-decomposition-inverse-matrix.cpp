#include <iostream>
using namespace std;

void luDecomposition(double** array,double** lower,double ** upper,int n);

void fbSubstitution(double** lower,double** upper,double** Identity,double** Inverse,int n);

int main(){

    int i,j,k,n;
    n=3;
    double **matrix = new double*[n];
    double **l=new double*[n];
    double **u= new double* [n];
    double **I=new double*[n];
    double **Inv=new double*[n];
    for(i=0;i<n;i++){
        matrix[i]= new double[n];
        l[i]=new double[n];
        u[i]=new double[n];
        I[i]=new double[n];
        Inv[i]=new double[n];
    }
    matrix[0][0]=3; matrix[0][1]=2; matrix[0][2]=1;
    matrix[1][0]=2; matrix[1][1]=3; matrix[1][2]=2;
    matrix[2][0]=1; matrix[2][1]=2; matrix[2][2]=2;

    cout<<endl<<"Matrix"<<endl;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl<<"Identity matrix"<<endl;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(i==j) I[i][j]=1;
            else{ I[i][j]=0; }
            cout<<I[i][j]<<"  ";
        }
        cout<<endl;
    }
    
    // calling LU factorization function
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

    // calling function to get inverse
    fbSubstitution(l,u,I,Inv,n);

    cout<<endl<<"Inverse of the matrix"<<endl;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cout<<Inv[i][j]<<" ";
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

void fbSubstitution(double** lower,double** upper,double** Identity,double** Inverse,int n){
    int i,j,k;
    double** y= new double*[n];
    for(i=0;i<n;i++){
        y[i]=new double[n];
    }

    // forward substitution
    cout<<endl<<"y (intermidiate matrix)"<<endl;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            y[i][j]=Identity[i][j]/lower[i][i];
            for(k=0;k<i;k++){
                y[i][j]-=lower[i][k]*y[k][j]/lower[i][i];
            }
            cout<<y[i][j]<<"    ";
        }
        cout<<endl;
    }

    // backward substitution
    for(i=n-1;i>=0;i--){
        for(j=0;j<n;j++){
            Inverse[i][j]=y[i][j]/upper[i][i];
            for(k=i+1;k<n;k++){
                Inverse[i][j]-=upper[i][k]*Inverse[k][i]/upper[i][i];
            }
        }
    }

    return;
}