#ifndef REAL_CLOCK_H
#define REAL_CLOCK_H

#include "IClock.h"
#include "constants.h"
#include <string>

class RealClock : public IClock {
public:
    std::string nowDate() const override;
};

#endif
