#ifndef TYPES_H
#define TYPES_H

#include <string>
#include <stdexcept>
#include <algorithm>

enum class Currency { USD, EUR, GBP };

std::string to_string(Currency c);
Currency currency_from_string(std::string s);

#endif
