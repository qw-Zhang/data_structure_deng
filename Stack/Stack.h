#include "../Vector/vector.h"

template <typename T> class Stack: public Vector<T>{
    
public :
    void push(T const& e){ Vector<T>::insert(Vector<T>::size(),e); }
    T pop(){return this->remove(this->size() - 1); }
    T& top() {return (*this) [this->size() - 1]; }

};
