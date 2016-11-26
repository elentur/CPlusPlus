#ifndef PAYLOAD_H
#define PAYLOAD_H

#include <memory>
#include <iostream>

class Payload {

public:
    // data
    float x, y, z;

    // constructors
    Payload(float xx=0, float yy=0, float zz=0) : x(xx), y(yy), z(zz) { count_++; }
    Payload(const Payload& rhs) : x(rhs.x), y(rhs.y), z(rhs.z) { count_++; }
    Payload( Payload&& rhs) : x(NULL)
            , y(NULL), z(NULL) { 
     rhs.swap(*this);
    }
    void swap( Payload& rhs){
        std::swap(x,  rhs.x);
        std::swap(y, rhs.y);
        std::swap(z, rhs.z);
     }

    // destructor
    ~Payload()  { count_--; }

    // assignment - keeps count the same 
    Payload& operator=( Payload rhs) { x=rhs.x; y=rhs.y; z=rhs.z; return *this; }
    // comparison
    bool operator==(const Payload& rhs) const {
         return x==rhs.x && y==rhs.y && z==rhs.z; }



    // tell count
    static size_t count() { return count_; }
    friend std::ostream &operator << (std::ostream &os, const Payload &payload){
    os << "x: " << payload.x<< " y: " << payload.y<<" z: " << payload.z; 
    return os;}

private:
    static size_t count_;

};



#endif // PAYLOAD_H
