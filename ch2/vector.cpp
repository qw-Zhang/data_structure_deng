#include"vector.h"
#include<cstdlib>

template <typename T> 
void Vector<T>::copyFrom(T const* A,Rank lo,Rank hi)
{
    _capacity = 2*(hi - lo);
    _elem = new T[_capacity];
    _size = 0;
    while(lo < hi){
        _elem[size] = A[lo];
        size++;lo++;
    }
}

/*
template <typename T>
Vector<T>& Vector<T>::operator= (Vecotr<T> const& V)
{
    if(_elem)
        delete [] _elem;
    copyFrom(V._elem,0,V.size());
    return *this;
}
*/

template <typename T> 
void Vector<T>::expand()
{
    if(_size < _capacity)
        return;
    if(_capacity < DEFAULT_CAPACITY)
        _capacity = DEFAULT_CAPACITY;
    T* old_elem = _elem;
    _elem = new T[_capacity <<= 1];
    for(int i = 0;i < _size;i++)
        _elem[i] = old_elem[i];
    delete [] old_elem;
}

template <typename T> 
void Vector<T>::shrink()
{
    if(_capacity < DEFAULT_CAPACITY<<1)
        return;
    if(_size<<2 > _capacity )
        return ;
    T* old_elem = _elem;
    _elem = new T[_capacity >>= 1];
    for(int i = 0;i < _size;i++){
        _elem[i] = old_elem[i];
    }
    delete [] old_elem;
}

template <typename T> T& Vector<T>::operator[] (Rank r) const
{return _elem[r];}

template <typename T> 
void Vector<T>::unsort(Rank lo,Rank hi)
{
    T* v = _elem + lo;
    for(Rank i = hi - lo; i > 0;i--){
        swap(v[i - 1],v[rand() % i]);
    }
}

template <typename T>
Rank Vector<T>::find(T const& e,Rank lo,Rank hi) const
{
    while((lo < hi--)&&( e != _elem[hi])); //from back to front
    return hi;
}

