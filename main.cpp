#include "perceptron.h"
#include <iostream>

using namespace std;

int main() {
    string filename;

    cout << fixed;
    cout << "filename:";
    cin >> filename;

    int aDataSize = 3;
    int hiddenSize = 3;
    perceptron p(filename, aDataSize, hiddenSize);

    double input[aDataSize];
    while(true){
        for(int i=0; i<aDataSize; ++i){
            cin >> input[i];
        }
        cout << std::endl << "forward(buf) == " << p.forward(input) << endl;
        cout << endl;
    }

    return 0;
}
