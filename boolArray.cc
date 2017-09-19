#include <iostream>
#include <cassert>

class boolArray{
    public:
        boolArray();
        boolArray(int num);
        ~boolArray();
        void toggleBool(int boolIndex);
        void setToZero(int boolIndex);
        void setToOne(int boolIndex);
        int at(int boolIndex);
        void print();
    private:
        int booleanArray;
};

boolArray::boolArray() : booleanArray(0){}

boolArray::boolArray(int num) : booleanArray(num){}

boolArray::~boolArray(){}

void boolArray::toggleBool(int boolIndex) {
    assert(boolIndex > -1 && boolIndex < 32);
    int singleOne = 1; 
    singleOne <<= boolIndex;
    this->booleanArray ^= singleOne; //xor by 0 does nothing, only the one bit xored by 1 is inverted//
}

void boolArray::setToZero(int boolIndex){
    assert(boolIndex > -1 && boolIndex < 32);
    int singleZero = ~0;
    int singleOne = 1;
    singleOne <<= boolIndex;
    singleZero ^= singleOne;
    this->booleanArray &= singleZero;
}

void boolArray::setToOne(int boolIndex){
    assert(boolIndex > -1 && boolIndex < 32);
    int singleOne = 1; 
    singleOne <<= boolIndex;
    this->booleanArray |= singleOne; //or by one guarantees one//
}

int boolArray::at(int boolIndex) {
    assert(boolIndex > -1 && boolIndex < 32);
    int singleOne = 1;
    singleOne <<= boolIndex;
    if (this->booleanArray & singleOne) {
        return 1;
    }
    return 0;
}

void boolArray::print() {
    for (int i = 31; i > -1; i--){
        if (this->at(i)){
            std::cout<< 1;
        }
        else{
            std::cout << 0;
        }
    }
    std::cout << std::endl;
}