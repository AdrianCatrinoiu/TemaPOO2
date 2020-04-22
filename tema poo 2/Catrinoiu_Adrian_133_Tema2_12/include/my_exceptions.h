#include <iostream>
#include <exception>
#include <string>
#include <bitset>
class my_exceptions: public std::exception
{
    const char* what_arg;
public:
  my_exceptions(const char* what_arg) noexcept {
    this->what_arg = what_arg;
  }
  ~my_exceptions() noexcept {};

  const char* what() const noexcept {
    return this->what_arg;
  }
};
