#if !defined(BANK_ACCOUNT_H)
#define BANK_ACCOUNT_H

#include <variant>
#include <cstdint>
#include <mutex>

namespace Bankaccount {

namespace State {
    struct Inactive { };
    struct Active { std::int64_t balance{}; };
}

namespace Event {
    struct Open { std::int64_t startBalance{}; };
    struct Deposit { std::int64_t amount{}; };
    struct Withdraw { std::int64_t amount{}; };
    struct Close { };
}

using AccountState = std::variant<State::Inactive, State::Active>;
using PossibleEvent = std::variant<Event::Open, Event::Deposit, Event::Withdraw, Event::Close>;

class Bankaccount {
public:
    void open(std::int64_t startBalance = 0);
    void deposit(std::int64_t amount);
    void withdraw(std::int64_t amount);
    void close();
    std::int64_t balance();
private:
    void processEvent(const PossibleEvent& event);

    AccountState state_;

    std::mutex mutex_;
};

}  // namespace Bankaccount


#endif  // BANK_ACCOUNT_H
