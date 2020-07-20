#include <iostream>
class Fraccion
{
private:
int m_numerador;
int m_denominador;
public:
Fraccion(int numerador = 0, int denominador = 1) :
m_numerador{ numerador }, m_denominador{ denominador }
{
}
friend std::ostream& operator<<(std::ostream& out, const Fraccion &f1)
{
out << f1.m_numerador << '/' << f1.m_denominador;
return out;
}
};
int main()
{
auto &&rref{ Fraccion{ 3, 5 } }; // r-value referencia a Fraccion temporal
    // f1 de operator<< se une a lo temporal, no se crean copias.
    std::cout << rref << '\n';
return 0;
} // rref (y la Fraccion temporal) sale de alcance aquí.
