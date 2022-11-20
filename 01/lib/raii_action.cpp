#include "raii_action.hpp"


// template <typename TReturn>
// RAIIAction<TReturn>::~RAIIAction() {
//     // provide destructor being safe
//     try
//     {
//         func();
//     }
//     catch (...)
//     {
//         std::cout << "Handle exeption" << std::endl;
//     }
// }

// template <typename TReturn>
// TReturn RAIIAction<TReturn>::getFunc() const {
//     return func();
// }

// template <typename TReturn>
// std::ostream& operator<<(std::ostream& out, const RAIIAction<TReturn>& obj) {
//     out << obj.getFunc();
//     return out;
// }