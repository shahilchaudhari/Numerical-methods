# include<iostream>
# include<time.h>
using namespace std;

void gaussElimination(int n, double** array,double output[]){
    int i,j,k;
    double ratio;

    // forward elimination
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            ratio = array[j][i]/array[i][i];
            for(k=0;k<n+1;k++){
                if(j>k) array[j][k]==0;
                array[j][k]=array[j][k]-ratio*array[i][k];
            }
        }
    }
    
    // printing lower triangular matrix
    cout<<endl;
    for(i=0;i<n;i++){
        for(j=0;j<n+1;j++){
            cout<<array[i][j]<<"  ";
        }
        cout<<endl;
    }

    // backward substitution
    output[n]=array[n-1][n]/array[n-1][n-1];
    for(i=n-1;i>=0;i--){
        output[i]=array[i][n];
        for(j=i+1;j<n;j++){
            output[i]-=array[i][j]*output[j];
        }
        output[i]=output[i]/array[i][i];
    }

    return;
}

int main(){
    int i,j,k,n;
    n=3;

    cout<<"Number of row/coulumn "<<n<<endl;
    double *solution = new double [n];
    double** matrix = new double*[n];
    for (i=0;i<n;i++){
        matrix[i]=new double [n+1];
    }

    matrix[0][0]=1; matrix[0][1]=2; matrix[0][2]=-1; matrix[0][3]=2;
    matrix[1][0]=3; matrix[1][1]=3; matrix[1][2]=2; matrix[1][3]=3;
    matrix[2][0]=3; matrix[2][1]=6; matrix[2][2]=1; matrix[2][3]=1;

    cout<<"Augmented matrix :"<<endl;
    for(i=0;i<n;i++){
        for(j=0;j<n+1;j++){
            cout<<matrix[i][j]<<"  ";
        }
        cout<<endl;
    }
    // calling function to populate solution array
    gaussElimination(n,matrix,solution);

    cout<<endl;
    for(i=0;i<n;i++){
        cout<<"X["<<i+1<<"] : "<<solution[i]<<endl;
    }

    return 0;
}
