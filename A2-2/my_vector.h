#pragma once

#include <array>
#include <iostream>
#include <stdexcept>
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
    void vector<T>::increase_size();
    void vector<T>::reduce_size();
    T *data_;
    size_t nfi_ = 0;
    size_t size_ = 0;
    size_t capacity_ = 0;
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
    delete data_;
}
template <typename T>
bool vector<T>::empty() const
{
    return nfi_ == 0;
}
template <typename T>
std::size_t vector<T>::size() const
{
    return size_;
}
template <typename T>
void vector<T>::reserve(size_t n)
{
    
   data_ =  static_cast<T*>(malloc(sizeof(T)*n));
   
   capacity_=n;
   
}
template <typename T>
void vector<T>::clear()
{
    delete data_;
    data_(new T[0]);
    nfi_ = 0;
    size_ = 0;
}
template <typename T>
void vector<T>::push_back(const T &value)
{
    if (nfi_ >= capacity_)
        increase_size();
    new (data_+(nfi_++)) T(value);
    // new erlaubt als separaten Paramerter eine speicheradresse
}

template <typename T>
void vector<T>::increase_size()
{
    T* temp = data_;
    reserve(size_t(capacity_*1.5));
    new(data_) T(std::move(*temp));
    
    temp->~T();
    free(temp);

}

template <typename T>
T vector<T>::pop_back()
{
    if (nfi_<= 0)
        return NULL;
    T r = Payload(data_[--nfi_]);

   // reduce_size();
    return r;
}
template <typename T>
void vector<T>::reduce_size()
{
    T *new_data = new T[--size_];
    for (size_t i = 0; i < size_; i++)
    {
        new_data[i] = data_[i];
    }

    delete[] data_;
    data_ = new_data;
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
       throw std::out_of_range( "Index out of range." );
    }
    return data_[index];
}

template <typename T>
T &vector<T>::at(std::size_t index)
{
    if (index >= capacity_ || index < 0)
    {
       throw std::out_of_range( "Index out of range." );
    }
    return data_[index];
}
}