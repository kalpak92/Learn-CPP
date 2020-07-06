#include <algorithm>
#include <chrono>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;

using std::chrono::system_clock;
using std::chrono::duration;

using std::vector;

class BigArray
{

    public:
        BigArray(size_t len): len_(len), data_(new int[len]){}

        BigArray(const BigArray& other): len_(other.len_), data_(new int[other.len_])
        {
            cout << "Copy construction of " << other.len_ << " elements "<< endl;
            std::copy(other.data_, other.data_ + len_, data_);
        }

        BigArray& operator = (const BigArray& other)
        {
            cout << "Copy assignment of " << other.len_ << " elements "<< endl;
            if (this != &other){
            delete[] data_;

            len_ = other.len_;
            data_ = new int[len_];
            std::copy(other.data_, other.data_ + len_, data_);
            }
            return *this;
        }

        ~BigArray()
        {
            if (data_ != nullptr) delete[] data_;
        }

    private:
        size_t len_;
        int* data_;
};

int main()
{

    cout << endl;

    vector<BigArray> myVec;

    auto begin = system_clock::now();

    myVec.push_back(BigArray(1000000000));

    auto end = system_clock::now() - begin;
    auto timeInSeconds = duration<double>(end).count();

    cout << endl;
    cout << "time in seconds: " << timeInSeconds << endl;
    cout << endl;

}