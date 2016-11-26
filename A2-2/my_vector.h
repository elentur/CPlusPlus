#pragma once

#include <array>
#include <iostream>
#include <stdexcept>
#include <stdlib.h>
#include <malloc.h>
#include "payload.h"

namespace my
{
template <typename T = float>
class vector
{
  public:
    vector();
    vector(size_t size);
    vector(size_t size, T &value);
    vector(vector<T> const &) = delete;
    vector<T> &operator=(vector<T> const &) = delete;
    ~vector();
    bool empty() const;
    std::size_t size() const;
    std::size_t capacity() const;
    void reserve(size_t n);
    void clear();
    void shrink_to_fit();
    void push_back(const T &value);
    T pop_back();
    /**
        Overloading operator [] for reading purpose
        */
    T operator[](std::size_t index) const;
    /**
        Overloading operator [] for writing purpose
        */
    T &operator[](std::size_t index);

    T at(std::size_t index) const;

    T &at(std::size_t index);

  private:
    void reduce_size();
    T *data_;
    size_t size_ = 0;
    size_t capacity_ = 0;

    void increase_size();
};
template <typename T>
vector<T>::vector()
{
}
template <typename T>
vector<T>::vector(size_t size) : data_(new T[size])
{
    size_ = size;
}
template <typename T>
vector<T>::vector(size_t size, T &value) : data_(new T[size])
{
    size_ = size;
    push_back(value);
}
template <typename T>
vector<T>::~vector()
{
    for (size_t i = 0; i < size_; i++)
    {
       (data_ + i)->~T();
    }
    free(data_);
}
template <typename T>
bool vector<T>::empty() const
{
    return size_ == 0;
}
template <typename T>
std::size_t vector<T>::size() const
{
    return size_;
}
template <typename T>
std::size_t vector<T>::capacity() const
{
    return capacity_;
}
template <typename T>
void vector<T>::reserve(size_t n)
{
    data_ = static_cast<T *>(malloc(sizeof(T) * n));

    capacity_ = n;
}
template <typename T>
void vector<T>::clear()
{
    delete data_;
    data_(new T[0]);
    size_ = 0;
}
template <typename T>
void vector<T>::push_back(const T &value)
{
    //if there is space in the array
    if (size_ != capacity_)
    {
        new ((void *)(data_ + size_++)) T(value);
        return;
    }
    //if there is no more space
    capacity_ = capacity_ ? (size_t)ceil(capacity_ * 1.5) : 1;
    T *temp = data_;
    reserve(capacity_);
    //copy old data & delete old memory
    for (size_t i = 0; i < size_; i++)
    {
        new ((void *)(data_ + i)) T(std::move(*(temp + i)));
    }
    //add new data 
    new ((void *)(data_ + size_)) T(value);
    free(temp);
    size_++;
}
template <typename T>
T vector<T>::pop_back()
{
    if (size_ <= 0)return NULL;
    T r = T(data_[--size_]);
    return r;
}
template <typename T>
void vector<T>::shrink_to_fit(){
     //if there is no space in the array
    if (size_ == capacity_)return;
    //if there is space
    T *temp = data_;
    reserve(size_);
    //copy old data and delete old memory
    for (size_t i = 0; i < size_; i++)
    {
        new ((void *)(data_ + i)) T(std::move(*(temp + i)));
    }
    free(temp);
}
/**
        Overloading operator [] for reading purpose
        */
template <typename T>
T vector<T>::operator[](std::size_t index) const
{
    return data_[index];
}
/**
        Overloading operator [] for writing purpose
        */
template <typename T>
T &vector<T>::operator[](std::size_t index)
{
    return data_[index];
}

template <typename T>
T vector<T>::at(std::size_t index) const
{

    if (index >= capacity_ || index < 0)
    {
        throw std::out_of_range("Index out of range.");
    }
    return data_[index];
}

template <typename T>
T &vector<T>::at(std::size_t index)
{
    if (index >= capacity_ || index < 0)
    {
        throw std::out_of_range("Index out of range.");
    }
    return data_[index];
}
}