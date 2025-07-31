#include "bank_account.h"

namespace {

template<class... Ts>
struct overloaded : Ts... { 
    using Ts::operator()...; 
};

template<class... Ts> overloaded(Ts...) -> overloaded<Ts...>;

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
    try {
        return std::get<State::Opened>(state_).balance;
    }
    catch(...) {
        throw std::runtime_error("Check balance with not opened account");
    }
}

void Bankaccount::processEvent(const PossibleEvent& event) {
    std::lock_guard<std::mutex> guard{mutex_};
    state_ = std::visit(overloaded{
        [this](const auto& state, const auto& ev) {
            return onEvent(state, ev);
        }
    }, state_, event);
}

}
