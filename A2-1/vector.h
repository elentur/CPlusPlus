//
// Created by roberto on 10.11.16.
//

#ifndef A2_1_MY_VECTOR_H
#define A2_1_MY_VECTOR_H

#include <array>

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
        void clear();
        void push_back(const T &element);
        T pop_back();
        T operator[](std::size_t index) const;
        T &operator[](std::size_t index);
        T at(size_t) const;
        void expand();
        void contract();

        vector(vector<T> const &) = delete;
        vector<T>& operator=(vector<T> const &) = delete;

    private:
        T *data_;
        size_t nfi = 0;
        size_t size_ = 0;
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
            nfi++;
        }
    }

    template<typename T>
    bool vector<T>::empty()const {
        return nfi == 0;
    }

    template<typename T>
    size_t vector<T>::size() const {
        return nfi;
    }

    template<typename T>
    void vector<T>::clear() {
        delete[] data_;
    }

    template<typename T>
    void vector<T>::push_back(const T &element) {
        if (nfi >= size_)
            expand();

        data_[nfi++] = element;
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
        T elm = data_[--nfi];
        contract();
        return elm;
    }

    template<typename T>
    void vector<T>::contract() {

        T *copy = new T[size_ - 1];
        for (size_t i = 0; i < size_;i++){
            copy[i] = data_[i];
        }

        size_--;

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
        if(index > size_ || index > nfi) throw std::out_of_range( "Index out of range." );
        return  data_[index];
    }

    template<typename T>
    vector<T>::~vector() {
        delete[] data_;
        nfi=0;
    }
}


#endif //A2_1_MY_VECTOR_H
