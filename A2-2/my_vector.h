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
    vector(const vector &rhs);
    vector(vector &&rhs);
    ~vector();
    vector<T> &operator=(vector<T> rhs);
    void swap(vector<T> &lhs, vector<T> &rhs);
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
    T *data_;
    size_t size_ = 0;
    size_t capacity_ = 0;
};

template <typename T>
void vector<T>::swap(vector<T> &lhs, vector<T> &rhs)
{
    std::swap(lhs.data_, rhs.data_);
    std::swap(lhs.size_, rhs.size_);
    std::swap(lhs.capacity_, rhs.capacity_);
}
template <typename T>
vector<T>::vector() : data_(nullptr)
{
}
template <typename T>
vector<T>::vector(size_t size)
{
    reserve(size);
}
template <typename T>
vector<T>::vector(size_t size, T &value)
{
    reserve(size);
    push_back(value);
}
template <typename T>
vector<T>::vector(const vector<T> &rhs) : size_(rhs.size_), capacity_(rhs.capacity_)
{
    data_ = static_cast<T *>(malloc(sizeof(T) * capacity_));
    for (size_t i = 0; i < size_; i++)
    {
        new (data_ + i) T(*(rhs.data_ + i));
    }
}
template <typename T>
vector<T>::vector(vector<T> &&rhs) : vector<T>()
{
    swap(*this, rhs);
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
    T *temp = data_;
    data_ = static_cast<T *>(malloc(sizeof(T) * n));
    capacity_ = n;
    for (size_t i = 0; i < size_; i++)
    {
        new (data_ + i) T(std::move(*(temp + i)));
    }
}
template <typename T>
void vector<T>::clear()
{
    for (size_t i = 0; i < size_; i++)
    {
        (data_ + i)->~T();
    }
    free(data_);
    data_ = nullptr;
    size_ = 0;
}
template <typename T>
void vector<T>::push_back(const T &value)
{
    //if there is space in the array
    if (size_ != capacity_)
    {
        new (data_+ size_++) T(value);
        return;
    }
    reserve(capacity_ ? (size_t)ceil(capacity_ * 1.5) : 1);
    //add new data
    new (data_ + size_) T(value);
    size_++;
}
template <typename T>
T vector<T>::pop_back()
{
    if (size_ <= 0)
        throw std::out_of_range("Index out of range.");
    T r = T(data_[--size_]);
    return r;
}
template <typename T>
void vector<T>::shrink_to_fit()
{
    //if there is no space in the array
    if (size_ == capacity_)
        return;
    //if there is space
    reserve(size_);
}
template <typename T>
vector<T> &vector<T>::operator=(vector<T> rhs)
{
    swap(*this, rhs);
    return *this;
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