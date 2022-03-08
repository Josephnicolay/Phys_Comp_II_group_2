#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <iomanip>


using namespace std;

//defining Ordinary Differential Equation (ODE) to be solved 
#define f(x,y) (y - x*x + 1)


void runge_kutta(float x0, float y0, float n, float xn, vector<float> &vect_x, vector<float> &vect_y)
{
    float yn, h, k1, k2, k3, k4, k;
    int i;

    // Calculating step size (h)
    h = (xn-x0)/n;


    /*
    cout<<"\n//////////////////////////////////////////\n";
    cout<<"            RUNGE KUTTA FOUR                ";
    cout<<"\n//////////////////////////////////////////\n";
    cout << setw(10) << "x0" << setw(10) << "y0" << setw(10) <<"yn" << endl;
    cout<<"    ---------------------------\n";
    */
    for(i=0; i < n; i++)
    {
    k1 = h * (f(x0, y0));
    k2 = h * (f((x0+h/2), (y0+k1/2)));
    k3 = h * (f((x0+h/2), (y0+k2/2)));
    k4 = h * (f((x0+h), (y0+k3)));
    k = (k1+2*k2+2*k3+k4)/6;
    yn = y0 + k;

    //cout << setw(10) << fixed << setprecision(3) << x0 << setw(10) << fixed << setprecision(3)<< y0 << setw(10)<< fixed << setprecision(3) << yn << endl;

    x0 = x0+h;
    y0 = yn;
    vect_x.push_back(x0);
    vect_y.push_back(y0);
        
	}
}

int main()
{
    float x0, y0, xn;
    int n;
    vector <float> vec_x, vec_y;



    cout<<"Enter Initial Condition"<< endl;
    cout<<"x0 = ";
    cin>> x0;
    cout<<"y0 = ";
    cin >> y0;
    cout<<"Enter calculation point xn = ";
    cin>>xn;
    cout<<"Enter number of steps: ";
    cin>> n;

    cout<<endl; 
    runge_kutta(x0, y0, n, xn, vec_x, vec_y);
    
    cout<<endl;
 

    
    for (int i = 0; i < vec_x.size(); i++) {
    cout << setw(10) << fixed << setprecision(4) << vec_x[i]
        << setw(10) << fixed << setprecision(4) << vec_y[i]<<endl;
    }
    
    return 0;       
}
