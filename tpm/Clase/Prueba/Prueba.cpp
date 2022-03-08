#include <string>
#include <iomanip>
#include <fstream>
#include <vector>
#include <iostream>

using namespace std;

int main(){

    vector<int> nums = {1,2,3,4,5,6,7};
    string linea;
    
    for (int i: nums){
    
        linea += to_string(i) + " ";
        
    }
    
    cout << linea << endl;

}