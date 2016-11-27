//
// Created by roberto on 10.11.16.
//

#ifndef A2_1_MY_VECTOR_H
#define A2_1_MY_VECTOR_H

#include <array>
#include <malloc.h>

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
        void push_back(const T &element);
        T pop_back();
        void reserve(size_t new_capacity);
        T operator[](std::size_t index) const;
        T &operator[](std::size_t index);
        T at(size_t) const;
        T &at(size_t);

        vector(vector<T> const &) = delete;
        vector<T>& operator=(vector<T> const &) = delete;

    private:
        T *data_;
        size_t size_ = 0;
        size_t capacity_ = 0;
        void expand();
        void contract();
    };

    template<typename T>
    vector<T>::vector() : data_(new T[0]) { }

    template<typename T>
    vector<T>::vector(size_t const &size) : data_(new T[size]){
        size_ = size;
    }

    template<typename T>
    vector<T>::vector(size_t const &size,T const &element) : data_(new T[size]){

        size_ = size;

        for (int i = 0; i < size; ++i) {
            data_[i] = element;
            size_++;
        }
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
        delete[] data_;
    }

    template<typename T>
    void vector<T>::push_back(const T &element) {
        if(size_ != capacity_){
            new((void *) (data_ + size_)) T(element);
            ++size_;
            return;
        }


        if (size_ >= size_)
            expand();

        data_[size_++] = element;
    }

    template<typename T>
    void vector<T>::expand() {

        T *copy = new T[size_ + 1];
        for (size_t i = 0; i < size_;i++){
            copy[i] = data_[i];
        }

        size_++;

        delete[] data_;
        data_ = copy;
    }

    template<typename T>
    T vector<T>::pop_back() {
        if (size_ <= 0) throw std::out_of_range( "Index out of range." );
        T elm = data_[--size_];
        contract();
        return elm;
    }

    template<typename T>
    void vector<T>::contract() {

        T *copy = new T[--size_];
        for (size_t i = 0; i < size_;i++){
            copy[i] = data_[i];
        }

        delete[] data_;
        data_ = copy;
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
    T vector<T>::at(size_t index) const{
        if(index > size_ || index > size_) throw std::out_of_range( "Index out of range." );
        return  data_[index];
    }

    template <typename T>
    T &vector<T>::at(std::size_t index) {
        if (index >= size_ || index < 0) throw std::out_of_range( "Index out of range." );
        return data_[index];
    }

    template<typename T>
    vector<T>::~vector() {
        delete[] data_;
        size_=0;
    }

    template<typename T>
    size_t vector<T>::capacity() const{
        return capacity_;
    }

    template<typename T>
    void vector<T>::reserve(size_t new_capacity) {

        T* data_ = static_cast<T*>(malloc(sizeof(data_)));

        capacity_ = new_capacity;
    }
}


#endif //A2_1_MY_VECTOR_H
