#include <iostream>

template<class T>
class Auto_ptr4
{
	T* m_ptr;
public:
	Auto_ptr4(T* ptr = nullptr)
		:m_ptr(ptr)
	{
	}

	~Auto_ptr4()
	{
		delete m_ptr;
	}

	// Constructor copia
    // Hacer una copia profunda de a.m_ptr a m_ptr
	Auto_ptr4(const Auto_ptr4& a)
	{
		m_ptr = new T;
		*m_ptr = *a.m_ptr;
	}

    // Move constructor
    // Transferir la propiedad de a.m_ptr a m_ptr
	Auto_ptr4(Auto_ptr4&& a)
		: m_ptr(a.m_ptr)
	{
		a.m_ptr = nullptr;
	}

    // Asignación de copia
    // Hacemos una copia profunda de a.m_ptr a m_ptr
    Auto_ptr4& operator=(const Auto_ptr4& a)
	{
		// Detección de autoasignación
		if (&a == this)
			return *this;

		// Liberamos cualquier recurso que tengamos
		delete m_ptr;

		// Copia de recurso
		m_ptr = new T;
		*m_ptr = *a.m_ptr;

		return *this;
	}

    // Move assignment
    // Transferimos la propiedad de a.m_ptr a m_ptr
	Auto_ptr4& operator=(Auto_ptr4&& a)
	{
		// Detección de autoasignación
		if (&a == this)
			return *this;

		// Liberamos cualquier recurso que tengamos
		delete m_ptr;

		// Transferimos la propiedad de a.m_ptr a m_ptr
		m_ptr = a.m_ptr;
		a.m_ptr = nullptr;

		return *this;
	}

	T& operator*() const { return *m_ptr; }
	T* operator->() const { return m_ptr; }
	bool isNull() const { return m_ptr == nullptr; }
};

class Resource
{
public:
	Resource() { std::cout << "Recurso adquirido\n"; }
	~Resource() { std::cout << "Recurso destruido\n"; }
};

Auto_ptr4<Resource> generateResource()
{
	Auto_ptr4<Resource> res(new Resource);
	return res; // este valor de retorno invocará el move constructor
}

int main()
{
	Auto_ptr4<Resource> mainres;
	mainres = generateResource(); // esta asignación invocará  move assignment

	return 0;
}
