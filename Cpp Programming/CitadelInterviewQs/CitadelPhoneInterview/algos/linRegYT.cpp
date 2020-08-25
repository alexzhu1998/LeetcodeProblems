#include <iostream>
#include <math.h>
using namespace std;

int main () {
    int i;
    int n = 5;
    double x[n] = {0,1,2,3,4};
    double y[n] = {1,2,3,4,5};
    double xsum=0,x2sum=0,ysum=0,xysum=0;
    double beta0,beta1;
    for (i = 0;i<n;i++) {
        xsum+= x[i];
        ysum+= y[i];
        x2sum+= pow(x[i],2);
        xysum+= x[i]*y[i];
    }
    // Sxy/Sxx
    beta1 = (n*xysum-xsum*ysum)/(n*x2sum-pow(xsum,2));
    beta0 = ysum/n - beta1*xsum/n;

    cout << "linear fit" << endl;
    cout << "y = " << beta0 << " + " << beta1 << "x" << endl;

    double pred,givenX;
    givenX = 4;
    pred = beta0 + beta1*givenX;
    cout << "Given " << givenX << endl;
    cout << "The value predicted by the model is " << pred << endl;
}