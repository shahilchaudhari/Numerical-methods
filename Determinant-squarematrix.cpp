# include <iostream>
# include <math.h>
using namespace std;

double det(int n, double** mat);

int main(){
    int i,j,n;
    //  n is size of the matrix
    n=3;
    double** matrix = new double*[n];
    for(i=0;i<n;i++){
        matrix[i]=new double[n];
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

    cout<<"Determinant "<<det(n,matrix)<<endl;
}

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