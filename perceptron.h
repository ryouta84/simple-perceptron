#pragma once

#include "data.h"
#include <memory>
#include <random>
#include <cmath>

using namespace std;

class perceptron {
public:
    perceptron(const string& filename, size_t dSize, size_t hidSize);
    double forward(double input[]);
private:
    Data<double> data;
    size_t dataSize;    //一つの教師データの要素数
    size_t hiddenSize;  //中間層のセルの個数
    double f(double u);
    void backpropagation();
    void hiddenLearn();
    void outputLearn();
    void init();
    const unique_ptr<double[]> weight;
    const unique_ptr<double[]> threshold;
    const unique_ptr<double[]> output;
};
