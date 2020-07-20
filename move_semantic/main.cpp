#include <iostream>

template<class T>
class Auto_ptr2
{
T* m_ptr;
public:
Auto_ptr2(T* ptr=nullptr)
:m_ptr(ptr)
{
}
~Auto_ptr2()
{
delete m_ptr;
}

// Un constructor de copia que implementa move semantics
Auto_ptr2(Auto_ptr2& a) // note: not const
{
m_ptr = a.m_ptr; // transferir nuestro puntero de la fuente a nuestro objeto local
a.m_ptr = nullptr; // nos aseguramos de que la fuente ya no posea el puntero
}
// Un operador de asignación que implementa move semantics
Auto_ptr2& operator=(Auto_ptr2& a) // nota:no const
{
if (&a == this)
return *this;

delete m_ptr; // nos aseguramos de desasignar cualquier puntero que el destino ya esté sosteniendo primero
m_ptr = a.m_ptr; // transferimos nuestro puntero de la fuente al objeto local
a.m_ptr = nullptr; // nos aseguramos de que la fuente ya no posea el puntero
return *this;
}

T& operator*() const { return *m_ptr; }
T* operator->() const { return m_ptr; }
bool isNull() const { return m_ptr == nullptr;  }
};

class Resource
{
public:
Resource() { std::cout << "Recurso adquirido\n"; }
~Resource() { std::cout << "Recurso destruido\n"; }
};

int main()
{
Auto_ptr2<Resource> res1(new Resource);
Auto_ptr2<Resource> res2; // Start as nullptr

std::cout << "res1 es " << (res1.isNull() ? "nulo\n" : "no nulo\n");
std::cout << "res2 es " << (res2.isNull() ? "nulo\n" : "no nulo\n");

res2 = res1; // res2 asume la propiedad, res1 se establece en nulo

std::cout << "Propiedad transferida\n";

std::cout << "res1 es " << (res1.isNull() ? "nulo\n" : "no nulo\n");
std::cout << "res2 es " << (res2.isNull() ? "nulo\n" : "no nulo\n");

return 0;
}
