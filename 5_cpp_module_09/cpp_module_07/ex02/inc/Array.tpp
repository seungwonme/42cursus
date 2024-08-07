#include <stdexcept>
#include "Array.hpp"

template <typename T>
Array<T>::Array(size_t size)
: mData(new T[size])
, mSize(size)
{
}
template <typename T>
Array<T>::~Array()
{
    delete[] mData;
}
template <typename T>
Array<T>::Array(const Array& rhs)
: mData(new T[rhs.mSize])
, mSize(rhs.mSize)
{
    for (size_t i = 0; i < mSize; i++)
    {
        mData[i] = rhs.mData[i];
    }
}
template <typename T>
const Array<T>& Array<T>::operator=(const Array<T>& rhs)
{
    if (this != &rhs)
    {
        if (rhs.mSize > mSize)
        {
            delete[] mData;
            mData = new T[rhs.mSize];
        }
        mSize = rhs.mSize;
        for (size_t i = 0; i < mSize; i++)
        {
            mData[i] = rhs.mData[i];
        }
    }
    return *this;
}
template <typename T>
T& Array<T>::operator[](const size_t idx)
{
    if (idx >= mSize)
    {
        throw std::out_of_range("\033[91mArray index out of bounds\033[0m");
    }
    return mData[idx];
}
template <typename T>
size_t Array<T>::size() const
{
    return mSize;
}
