#include <iostream>
#include <vector>
using namespace std;

class A{
  int *ptr;
public:
  A(){
    // Constructor predeteminado
    cout << "Llamando al constructor predeterminado\n";
    ptr = new int ;
  }

  A( const A & obj){
    // Constructor copia
    // se crea una copia del objeto
    this->ptr = new int;
    // Copia profunda
    cout << "Llamando al contructor de copia\n";
  }

  A ( A && obj){
    // Move constructor
    // Simplemente cambiara los recursos
    // sin crear una copia.
     cout << "Llamando Move constructor\n";
    this->ptr = obj.ptr;
    obj.ptr = NULL;
  }

  ~A(){
    // Destructor
    cout << "Llamando al Destructor\n";
    delete ptr;
  }

};

int main() {

  vector <A> vec;
  vec.push_back(A());

  return 0;
}

