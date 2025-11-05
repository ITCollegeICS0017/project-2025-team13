#ifndef ICLOCK_H
#define ICLOCK_H

#include <string>

struct IClock {
    virtual ~IClock() = default;
    virtual std::string nowDate() const = 0;
};

#endif
