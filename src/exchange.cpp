#include "exchange.h"

namespace crex {

Exchange::Exchange(const std::string& name) : name_(name) {}

std::string Exchange::getName() const {
    return name_;
}

double Exchange::getBalance(const std::string& currency) const {
    auto it = balances_.find(currency);
    if (it != balances_.end()) {
        return it->second;
    }
    return 0.0;
}

void Exchange::setBalance(const std::string& currency, double amount) {
    balances_[currency] = amount;
}

void Exchange::addBalance(const std::string& currency, double amount) {
    balances_[currency] += amount;
}

bool Exchange::hasCurrency(const std::string& currency) const {
    return balances_.find(currency) != balances_.end();
}

} // namespace crex
