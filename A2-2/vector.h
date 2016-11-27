//
// Created by roberto on 10.11.16.
//

#ifndef A2_1_MY_VECTOR_H
#define A2_1_MY_VECTOR_H

#include <array>
#include <malloc.h>
#include "payload.h"


namespace my {

    template<typename T>
    class vector {

    public:
        vector();
        vector(size_t const &size);
        vector(size_t const &size,T const &element);
        ~vector();

        bool empty() const;
        size_t size() const;
        size_t capacity() const;
        void clear();
        void shrink_to_fit();
        void push_back(const T &element);
        T pop_back();
        void reserve(size_t new_capacity);
        T operator[](std::size_t index) const;
        T &operator[](std::size_t index);
        T at(size_t) const;
        T &at(size_t);

        vector(vector<T> const &) = delete;
        vector<T>& operator=(vector<T> const &) = delete;

        operator bool() const { return data_ != nullptr; }

    private:
        T *data_;
        size_t size_ = 0;
        size_t capacity_ = 0;
    };

    template<typename T>
    vector<T>::vector() : data_(nullptr) { }

    template<typename T>
    vector<T>::vector(size_t const &size) : data_(new T[size]){
        size_ = size;
    }

    template<typename T>
    vector<T>::vector(size_t const &size,T const &element) : data_(new T[size]){
        size_ = size;
        push_back(element);
    }

    template<typename T>
    bool vector<T>::empty()const {
        return size_ == 0;
    }

    template<typename T>
    size_t vector<T>::size() const {
        return size_;
    }

    template<typename T>
    void vector<T>::clear() {

        for (size_t i = 0; i < size_; i++)
        {
            (data_ + i)->~T();
        }

        free(data_);
        data_ = nullptr;
        size_ = 0;
    }

    template<typename T>
    void vector<T>::push_back(const T &element) {
        //if there is space in the array
        if (size_ != capacity_)
        {
            new ((void *)(data_ + size_++)) T(element);
            return;
        }
        //if there is no more space
        capacity_ = capacity_ ? (size_t) capacity_ * 2 : 1;

        T *temp = data_;
        reserve(capacity_);

        //copy old data & delete old memory
        for (size_t i = 0; i < size_; i++)
        {
            new ((void *)(data_ + i)) T(std::move(*(temp + i)));

        }

        //add new data
        new ((void *)(data_ + size_)) T(element);
        free(temp);
        size_++;
    }

    template <typename T>
    T vector<T>::pop_back()
    {
        if (size_ <= 0)return nullptr;
        T r = T(data_[--size_]);
        return r;
    }

    template<typename T>
    T vector<T>::operator[](std::size_t index) const {
        return  data_[index];
    }

    template<typename T>
    T &vector<T>::operator[](std::size_t index) {
        return  data_[index];
    }

    template<typename T>
    T vector<T>::at(std::size_t index) const{
        if(index >= capacity_ || index < 0) throw std::out_of_range( "Index out of range." );
        return  data_[index];
    }

    template <typename T>
    T &vector<T>::at(std::size_t index) {
        if (index >= size_ || index < 0) throw std::out_of_range( "Index out of range." );
        return data_[index];
    }

    template<typename T>
    vector<T>::~vector() {
        for (size_t i = 0; i < size_; i++)
        {
            (data_ + i)->~T();
        }
        free(data_);
        size_=0;
    }

    template<typename T>
    size_t vector<T>::capacity() const{
        return capacity_;
    }

    template<typename T>
    void vector<T>::reserve(size_t new_capacity) {
        data_ = static_cast<T*>(malloc(sizeof(T) * new_capacity));
        capacity_ = new_capacity;
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
}


#endif //A2_1_MY_VECTOR_H
