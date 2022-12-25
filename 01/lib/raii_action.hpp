#pragma once

#include <functional>
#include <iostream>
#include <concepts>


template <typename T>
concept callable =
    requires(T func)
    {
        func();
    };

template <callable T>
class RAIIAction {
private:
    T func_

public:
    RAIIAction(T func) : func_(func) {}
    RAIIAction(const RAIIAction&) = delete;
    RAIIAction(RAIIAction&&) = delete;
    RAIIAction& operator=(const RAIIAction&) = delete;
    RAIIAction& operator=(RAIIAction&&) = delete;

    ~RAIIAction();

    void getFunc() const {
        func;
    }

    template<callable U>
    friend std::ostream& operator<<(std::ostream& out, const RAIIAction<U>& obj);

};


template <callable T>
RAIIAction<T>::~RAIIAction() {
    // provide destructor being safe
    try
    {
        func();
    }
    catch (...)
    {
        std::cout << "Handle exeption" << std::endl;
    }
}


template <callable T>
std::ostream& operator<<(std::ostream& out, const RAIIAction<T>& obj) {
    out << obj.func();

    return out;
}
