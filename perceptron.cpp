#include "perceptron.h"

perceptron::perceptron(const string& filename, size_t dSize, size_t hidSize)
: data(filename), mDataSize(dSize), mHiddenSize(hidSize),
  weight(new double[ mDataSize*mHiddenSize + mHiddenSize ]),
  threshold(new double[mHiddenSize+1]), output(new double[mHiddenSize+1])
{
    init();
    learn();
}

double perceptron::forward(double input[])
{
    //中間層の計算
    for(size_t i=0; i<mHiddenSize; ++i){
        double hidbuf=0;
        for(int j=0; j<mDataSize; ++j){
            hidbuf += weight[i*mDataSize * j] * input[j];
        }
        output[i] = f(hidbuf - threshold[i]);
    }
    //出力層の計算
    size_t outputLayerBegin = mDataSize * mHiddenSize;
    double outbuf=0;
    for (size_t i =0; i < mHiddenSize; ++i) {
         outbuf += weight[outputLayerBegin+i] * output[i];
    }
    output[mHiddenSize] = f(outbuf - threshold[mHiddenSize]);

    return output[mHiddenSize];
}

void perceptron::learn()
{
    std::vector<double> input;
    double totalError = 100.0;
    size_t count =0;
    while(totalError > 0.001){
        totalError = 0;
        ++count;
        std::cout << count << "times" << std::endl;
        for(size_t num=0; num<data.setsNo; ++num){
            data.aData(input, num);
            double E = input.at( data.teacher() ) - forward( input.data() );
            std::cout << std::endl;
            //中間層の学習
            double di =0;
            double o = output[mHiddenSize];
            std::cout << "--------------------weight of hidden layer--------------------" << std::endl;
            for(size_t i=0; i<mHiddenSize; ++i){ //i番目のセル
                di = output[i] * weight[mDataSize*mHiddenSize] * E * o * (1-o);
                for(size_t j=0; j<mDataSize; ++j){ //i番目のセルのj番目の入力
                    weight[i*mHiddenSize + j] = weight[i*mHiddenSize + j] + alpha * input.at(j) * di;
                    cout << weight[i * mHiddenSize + j] << " ";
                }
                threshold[i] += alpha * (-1.0) * di;
            }
            std::cout << std::endl << "--------------------------------------------------------------" << std::endl;
            //出力層の学習
            outputLayerLearn(E);

            totalError += E * E;
        }
        std::cout << "error==" << totalError << std::endl << std::endl;
    }
}

void perceptron::outputLayerLearn(double E)
{
    std::cout << "--------------------weight of ouput layer-------------------" << std::endl;
    for (size_t i = 0; i < mHiddenSize; i++) {
        weight[mDataSize*mHiddenSize + i] += alpha * E * output[mHiddenSize] * (1- output[mHiddenSize] ) * output[i];
        cout << weight[mDataSize*mHiddenSize + i] << " ";
    }
    threshold[mHiddenSize] += alpha * E * output[mHiddenSize] * (1- output[mHiddenSize] ) * (-1);
    std::cout << std::endl << "------------------------------------------------------------" << std::endl;
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
    for(size_t i=0; i<mDataSize*mHiddenSize + mHiddenSize; ++i){
        weight[i] = dist(engine);
        cout << weight[i] << " ";
    }
    cout << endl;

    for(size_t i=0; i<mHiddenSize+1; ++i){
        threshold[i] = dist(engine);
        cout << threshold[i] << " ";
    }
    cout << endl;
}
