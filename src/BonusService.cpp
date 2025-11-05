#include "BonusService.h"

double BonusService::calculateBonus(double profit) const {
    return profit * constants::BONUS_RATE;
}
