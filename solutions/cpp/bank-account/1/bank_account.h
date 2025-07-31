#if !defined(BANK_ACCOUNT_H)
#define BANK_ACCOUNT_H

#include <variant>
#include <stdexcept>
#include <cstdint>
#include <mutex>



namespace Bankaccount {

namespace State {
    struct Created { };
    struct Opened { std::int64_t balance{}; };
    struct Closed { };
}

namespace Event {
    struct Open { std::int64_t startBalance{}; };
    struct Deposit { std::int64_t amount{}; };
    struct Withdraw { std::int64_t amount{}; };
    struct Close { };
}

using AccountState = std::variant<State::Created, State::Opened, State::Closed>;
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
    //AccountState onEvent(const State::Created& state, const Event::Open& event);
    //AccountState onEvent(const State::Opened& state, const Event::Deposit& event);
    //AccountState onEvent(const State::Opened& state, const Event::Withdraw& event);
    //AccountState onEvent(const State::Opened& state, const Event::Close& event);
    //AccountState onEvent(const State::Closed& state, const Event::Open& event);

    template<class StateT, class EventT>
    AccountState onEvent(const StateT& state, const EventT& event);
    AccountState state_;

    std::mutex mutex_;
};

template<class StateT, class EventT>
inline AccountState Bankaccount::onEvent([[maybe_unused]] const StateT& state, [[maybe_unused]] const EventT& event) {
    throw std::runtime_error("Wrong event with current state");
    return {};
}

template<>
inline AccountState Bankaccount::onEvent([[maybe_unused]] const State::Created& state, const Event::Open& event) {
    return State::Opened{event.startBalance};
}

template<>
inline AccountState Bankaccount::onEvent(const State::Opened& state, const Event::Deposit& event) {
    if(event.amount < 0)
        throw std::runtime_error("Negativ deposit");
    return State::Opened{state.balance + event.amount};   
}

template<>
inline AccountState Bankaccount::onEvent(const State::Opened& state, const Event::Withdraw& event) {
    if(event.amount < 0 || event.amount > state.balance)
        throw std::runtime_error("Wrong withdraw amount");
    return State::Opened{state.balance - event.amount};
}

template<>
inline AccountState Bankaccount::onEvent([[maybe_unused]] const State::Opened& state, [[maybe_unused]] const Event::Close& event) {
    return State::Closed{};
}

template<>
inline AccountState Bankaccount::onEvent([[maybe_unused]] const State::Closed& state, const Event::Open& event) {
    return State::Opened{event.startBalance};
}

}  // namespace Bankaccount


#endif  // BANK_ACCOUNT_H
