#include "bank_account.h"
#include <mutex>
#include <stdexcept>
#include <variant>
namespace {
using namespace Bankaccount; //meh
template<class StateT, class EventT>
AccountState onEvent(const StateT&, const EventT&) {
    throw std::runtime_error("Wrong event with current state");
}

template<>
AccountState onEvent(const State::Inactive&, const Event::Open& event) {
    return State::Active{event.startBalance};
}

template<>
AccountState onEvent(const State::Active& state, const Event::Deposit& event) {
    if(event.amount < 0)
        throw std::runtime_error("Negativ deposit");
    return State::Active{state.balance + event.amount};   
}

template<>
AccountState onEvent(const State::Active& state, const Event::Withdraw& event) {
    if(event.amount < 0 || event.amount > state.balance)
        throw std::runtime_error("Wrong withdraw amount");
    return State::Active{state.balance - event.amount};
}

template<>
AccountState onEvent(const State::Active&,const Event::Close&) {
    return State::Inactive{};
}
} 
namespace Bankaccount {

void Bankaccount::open(std::int64_t startBalance) {
    processEvent(Event::Open{startBalance});
}

void Bankaccount::deposit(std::int64_t amount) {
    processEvent(Event::Deposit{amount});
}

void Bankaccount::withdraw(std::int64_t amount) { 
    processEvent(Event::Withdraw{amount});
}

void Bankaccount::close() {
    processEvent(Event::Close{});
}

std::int64_t Bankaccount::balance() {
    std::lock_guard<std::mutex> guard{mutex_};
    if(std::holds_alternative<State::Active>(state_))
        return std::get<State::Active>(state_).balance;
    else
        throw std::runtime_error("Check balance with not opened account");
}

void Bankaccount::processEvent(const PossibleEvent& event) {
    std::lock_guard<std::mutex> guard{mutex_};
    state_ = std::visit(
        [](const auto& state, const auto& ev) {
            return onEvent(state, ev);
        }, state_, event);
}

}
