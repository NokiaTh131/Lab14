#include <iostream>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << "Arithmetic Mean = " << B[0];
    cout << "\nStandard Deviation = " << B[1];
    cout << "\nGeometric Mean = " << B[2];
    cout << "\nHarmonic Mean = " << B[3];
    cout << "\nMax = " << B[4];
    cout << "\nMin = " << B[5];
    return 0;
}

void stat(const double A[], int length, double Ans[]) {
    for(int i = 0;i<length;i++) Ans[0] += A[i];
    Ans[0] /= length;
    double Average1 = Ans[0]; 

    double X_Xbar2;
    for(int j = 0;j<length;j++) {
        X_Xbar2 += pow(A[j] - Average1,2);
    }
    double SD = sqrt(X_Xbar2/(length));
    Ans[1] = SD;

    double xtimes = A[0];
    for(int k = 1;k<length;k++) xtimes *= A[k];
    double GM = pow(xtimes,1/(double) length);
    Ans[2] = GM;

    double X_n = 1/A[0];
    for(int x = 1;x<length;x++) X_n += 1/A[x];
    double HM = length/X_n;
    Ans[3] = HM;

    Ans[4] = A[0];
    Ans[5] = A[0];
    for(int p = 1;p<length;p++) {
       if(Ans[4] < A[p]) Ans[4] = A[p];
       if(Ans[5] > A[p]) Ans[5] = A[p]; 
    }

}