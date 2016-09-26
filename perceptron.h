#pragma once

#include "data.h"
#include <memory>
#include <random>
#include <cmath>
#include <vector>

using namespace std;
/*
一つのデータの要素数と隠れ層のセルの数は同じにする
*/
class perceptron {
public:
    perceptron(const string& filename, size_t dSize, size_t hidSize);
    double forward(double input[]);
private:
    Data<double> data;
    size_t mDataSize;    //一つの教師データの要素数
    size_t mHiddenSize;  //中間層のセルの個数
    double f(double u);
    void learn();
    void outputLayerLearn(double E);
    void init();
    const unique_ptr<double[]> weight;
    const unique_ptr<double[]> threshold;
    const unique_ptr<double[]> output;

    double alpha = 10.0;
};
