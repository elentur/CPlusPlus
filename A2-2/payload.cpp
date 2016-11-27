#include "payload.h"

// instantiate the payload's static count
size_t Payload::count_ = 0;

std::ostream &operator<<(std::ostream &os, const Payload &payload) {
    os << "x: " << payload.x << " y: " << payload.y << " z: " << payload.z;
    return os;
}


