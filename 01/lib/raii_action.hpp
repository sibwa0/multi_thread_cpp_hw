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
    T func;

public:
    RAIIAction(T _func) : func(_func) {}
    RAIIAction& operator=(const RAIIAction& src);
    RAIIAction(RAIIAction&&) = delete;

    ~RAIIAction();

    void getFunc() const {
        func;
    }

    template<callable U>
    friend std::ostream& operator<<(std::ostream& out, const RAIIAction<U>& obj);

};

template <callable T>
RAIIAction<T>& RAIIAction<T>::operator=(const RAIIAction& src)
{
    if (&src == this) { return *this; }

    func = src.func;
    return *this;
}


// #include "raii_action.cpp"

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
