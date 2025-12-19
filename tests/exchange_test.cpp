#include "exchange.h"
#include <gtest/gtest.h>

namespace crex {
namespace {

// Test fixture for Exchange tests
class ExchangeTest : public ::testing::Test {
protected:
    void SetUp() override {
        exchange = new Exchange("TestExchange");
    }

    void TearDown() override {
        delete exchange;
    }

    Exchange* exchange;
};

// Test constructor and getName
TEST_F(ExchangeTest, ConstructorAndGetName) {
    EXPECT_EQ(exchange->getName(), "TestExchange");
}

// Test setting and getting balance
TEST_F(ExchangeTest, SetAndGetBalance) {
    exchange->setBalance("BTC", 1.5);
    EXPECT_DOUBLE_EQ(exchange->getBalance("BTC"), 1.5);
}

// Test getting balance for non-existent currency
TEST_F(ExchangeTest, GetBalanceNonExistentCurrency) {
    EXPECT_DOUBLE_EQ(exchange->getBalance("XYZ"), 0.0);
}

// Test adding to balance
TEST_F(ExchangeTest, AddBalance) {
    exchange->setBalance("ETH", 10.0);
    exchange->addBalance("ETH", 5.0);
    EXPECT_DOUBLE_EQ(exchange->getBalance("ETH"), 15.0);
}

// Test adding to balance of non-existent currency
TEST_F(ExchangeTest, AddBalanceNewCurrency) {
    exchange->addBalance("USDT", 100.0);
    EXPECT_DOUBLE_EQ(exchange->getBalance("USDT"), 100.0);
}

// Test hasCurrency
TEST_F(ExchangeTest, HasCurrency) {
    EXPECT_FALSE(exchange->hasCurrency("BTC"));
    exchange->setBalance("BTC", 1.0);
    EXPECT_TRUE(exchange->hasCurrency("BTC"));
}

// Test multiple currencies
TEST_F(ExchangeTest, MultipleCurrencies) {
    exchange->setBalance("BTC", 1.5);
    exchange->setBalance("ETH", 10.0);
    exchange->setBalance("USDT", 5000.0);
    
    EXPECT_DOUBLE_EQ(exchange->getBalance("BTC"), 1.5);
    EXPECT_DOUBLE_EQ(exchange->getBalance("ETH"), 10.0);
    EXPECT_DOUBLE_EQ(exchange->getBalance("USDT"), 5000.0);
    
    EXPECT_TRUE(exchange->hasCurrency("BTC"));
    EXPECT_TRUE(exchange->hasCurrency("ETH"));
    EXPECT_TRUE(exchange->hasCurrency("USDT"));
    EXPECT_FALSE(exchange->hasCurrency("XRP"));
}

} // namespace
} // namespace crex
