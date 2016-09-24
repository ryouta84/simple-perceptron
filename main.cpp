#include <iostream>
#include "perceptron.h"

using namespace std;

int main() {
    string filename;

    cout << fixed;
    cout << "filename:";
    cin >> filename;

    perceptron p(filename, 3, 3);
    //double buf[] = {1, 0, 1};
    //cout << "forward(buf) == " << p.forward(buf) << endl;
    cin >> filename;

    return 0;
}
