#ifndef PAYLOAD_H
#define PAYLOAD_H

#include <memory>
#include <ostream>

class Payload {
    // data
    float x, y, z;
public:
    // ctor
    Payload(float xx=0, float yy=0, float zz=0) : x(xx), y(yy), z(zz) { count_++; }

    // copy-ctor
    Payload(const Payload& rhs) : x(rhs.x), y(rhs.y), z(rhs.z) { count_++; }
    // move-ctor
    Payload( Payload&& rhs) : x(0), y(0), z(0) { std::swap(*this,rhs); }
    // copy assignment - keeps count the same
    Payload& operator=(const Payload& rhs) {
        if(this != &rhs) {
            x=rhs.x; y=rhs.y; z=rhs.z;
        }
        return *this;
    }
    // move assignment
    Payload& operator=(Payload&& rhs){
        Payload temp(std::move(*this));
        swap(*this,rhs);
        return *this;
    }

    friend void swap(Payload& lhs, Payload& rhs) {
        std::swap(lhs.x,rhs.x);
        std::swap(lhs.y,rhs.y);
        std::swap(lhs.z,rhs.z);
    }

    // destructor
    ~Payload() { count_--; }

    // comparison
    bool operator==(const Payload& rhs) const { return x==rhs.x && y==rhs.y && z==rhs.z; }

    // tell count
    static size_t count() { return count_; }

    friend std::ostream &operator<<(std::ostream &os, const Payload &payload);
private:
    static size_t count_;

};


#endif // PAYLOAD_H
