#include "exchange.h"
#include <iostream>

int main() {
    crex::Exchange exchange("MyExchange");
    
    std::cout << "Welcome to " << exchange.getName() << "!" << std::endl;
    
    // Set some initial balances
    exchange.setBalance("BTC", 1.5);
    exchange.setBalance("ETH", 10.0);
    exchange.setBalance("USDT", 5000.0);
    
    // Display balances
    std::cout << "\nCurrent Balances:" << std::endl;
    std::cout << "BTC: " << exchange.getBalance("BTC") << std::endl;
    std::cout << "ETH: " << exchange.getBalance("ETH") << std::endl;
    std::cout << "USDT: " << exchange.getBalance("USDT") << std::endl;
    
    // Add to balance
    exchange.addBalance("BTC", 0.5);
    std::cout << "\nAfter adding 0.5 BTC:" << std::endl;
    std::cout << "BTC: " << exchange.getBalance("BTC") << std::endl;
    
    return 0;
}
