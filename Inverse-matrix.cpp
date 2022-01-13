#include <iostream>
#include <math.h>
using namespace std;

double det(int n,double** mat){
    int i,j,k,subi,subj;
    double d=0;
    double** sub=new double*[n];
    for(i=0;i<n;i++){
        sub[i]=new double[n];
    }
    
    if (n==2)
        return((mat[0][0]*mat[1][1])-(mat[1][0]*mat[0][1]));
    else{
        for(k=0;k<n;k++){
            subi=0;
            for(i=1;i<n;i++){
                subj=0;
                for(j=0;j<n;j++){
                    if (j==k)
                    continue;
                    sub[subi][subj]=mat[i][j];
                    subj++;
                }
                subi++;
            }
            d = d+(pow(-1,k)*mat[0][k]*det(n-1,sub));
        }
    }
    return d;
}

void adjoint(int n,double determinant,double** mat,double** invmat){
    int i,j;
    double** adjmat= new double*[n];
    double** dummy= new double*[n+2];

    for(i=0;i<n+2;i++){
        adjmat[i]=new double[n];
        dummy[i]=new double[n+2];
    }
    
    // createing dummy matrix from given matrix
    for(i=0;i<n+2;i++){
        for(j=0;j<n+2;j++){
            if(i<n & j<n){
            dummy[i][j] = mat[i][j];
            }
            if(j>=n & j<n+2){
                if(i<n)
                dummy[i][j]=mat[i][j-n];
            }
            if(i>=n & i<n+2){
                dummy[i][j]=dummy[i-n][j];
            }
        }
    }

    // Calculating adjoint matrix 
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            // transpose
            adjmat[j][i]=dummy[i+1][j+1]*dummy[i+2][j+2]-dummy[i+1][j+2]*dummy[i+2][j+1];
        }
    }

    // Calculating Inverse of matrix
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            invmat[i][j]=1/determinant*adjmat[i][j];
        }
    }

    return;
}

int main(){
    int i,j,k,n;
    double determinant;
    n=3;
    double** matrix = new double*[n];
    double** inverse = new double*[n];
    for(i=0;i<n;i++){
        matrix[i]=new double[n];
        inverse[i]=new double[n];
    }
    matrix[0][0]=5; matrix[0][1]=2; matrix[0][2]=1;
    matrix[1][0]=1; matrix[1][1]=2; matrix[1][2]=1;
    matrix[2][0]=1; matrix[2][1]=1; matrix[2][2]=3;

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cout<<matrix[i][j]<<"   ";
        }
        cout<<endl;
    }
    determinant = det(n,matrix);

    adjoint(n,determinant,matrix,inverse);

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cout<<inverse[i][j]<<"   ";
        }
        cout<<endl;
    }

    return 0;
}