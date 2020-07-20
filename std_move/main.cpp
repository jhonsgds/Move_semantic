#include <iostream>
#include <string>
#include <utility> // para std::move

template<class T>
void myswap(T& a, T& b)
{
  T tmp { std::move(a) }; // invocamos a move constructor
  a = std::move(b); // invocamos a move assignment
  b = std::move(tmp); // invocamos a move assignment
}

int main()
{
std::string x{ "abc" };
std::string y{ "de" };

std::cout << "x: " << x << '\n';
std::cout << "y: " << y << '\n';

myswap(x, y);

std::cout << "x: " << x << '\n';
std::cout << "y: " << y << '\n';

return 0;
}
