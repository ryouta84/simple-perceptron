#include "perceptron.h"

perceptron::perceptron(const string& filename, size_t dSize, size_t hidSize)
: data(filename), dataSize(dSize), hiddenSize(hidSize),
  weight(new double[ dataSize*hiddenSize + hiddenSize ]),
  threshold(new double[hiddenSize+1]), output(new double[hiddenSize+1])
{
    init();
}

double perceptron::forward(double input[])
{
    //中間層の計算
    for(size_t i=0; i<hiddenSize; ++i){
        double hidout=0;
        for(int j=0; j<dataSize; ++j){
            hidout += weight[i*dataSize * j] * input[j];
        }
        output[i] = hidout - threshold[i];
    }
    //出力層の計算
    size_t outputLayerBegin = dataSize * hiddenSize;
    double buf=0;
    for (size_t i =0; i < hiddenSize; ++i) {
         buf += weight[outputLayerBegin+i] * output[i];
    }
    output[hiddenSize] = buf - threshold[hiddenSize];

    return output[hiddenSize];
}

void perceptron::backpropagation()
{

    //double error = forward() - 教師データ ;
    //中間層の学習
    hiddenLearn();
    //出力層の学習
    outputLearn();
}

void perceptron::hiddenLearn()
{

}

void perceptron::outputLearn()
{
    
}

double perceptron::f(double u)
{
    //シグモイド関数
    return 1.0 / ( 1.0 + exp(-u) );
}

void perceptron::init()
{
    std::random_device seedGen;
    std::mt19937 engine(seedGen());
    std::uniform_real_distribution<double> dist(-1.0, 1.0);

    //重みの初期化
    for(size_t i=0; i<dataSize*hiddenSize + hiddenSize; ++i){
        weight[i] = dist(engine);
        cout << weight[i] << " ";
    }
    cout << endl;

    for(size_t i=0; i<hiddenSize+1; ++i){
        threshold[i] = dist(engine);
        cout << threshold[i] << " ";
    }
    cout << endl;
}
