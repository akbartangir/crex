#ifndef CREX_EXCHANGE_H
#define CREX_EXCHANGE_H

#include <string>
#include <map>

namespace crex {

class Exchange {
public:
    Exchange(const std::string& name);
    ~Exchange() = default;

    // Get exchange name
    std::string getName() const;

    // Get balance for a specific currency
    double getBalance(const std::string& currency) const;

    // Set balance for a specific currency
    void setBalance(const std::string& currency, double amount);

    // Add to balance
    void addBalance(const std::string& currency, double amount);

    // Check if currency exists
    bool hasCurrency(const std::string& currency) const;

private:
    std::string name_;
    std::map<std::string, double> balances_;
};

} // namespace crex

#endif // CREX_EXCHANGE_H
