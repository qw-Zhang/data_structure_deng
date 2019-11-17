#include<iostream>
#include"ListNode.h"

template <typename T> class List{
    
private:
    int _size;
    ListNodePosi(T) header;
    ListNodePosi(T) trailer;

protected:
    void init();
    int clear();
    void copyNodes(ListNodePosi(T), int);
    void merge(ListNodePosi(T)&, int , List<T>&, ListNodePosi(T), int);
    void mergeSort(ListNodePosi(T)&,int);
    void selectionSort(ListNodePosi(T),int);
    void insertionSort(ListNodePosi(T),int);

public:
    List(){
        init();
    }
    List(List<T> const& L);
    List(List<T> const& L, Rank r, int n);
    List(ListNodePosi(T) p,int n);

    
    ~List();
    
    
    Rank size() const {return _size;}
    bool empty() const {return _size <= 0;}
    T& operator[] (Rank r) const;
    ListNodePosi(T) first() const {return header->succ;}
    ListNodePosi(T) last() const {return trailer->pred;}
    bool vaild(ListNodePosi(T) p)
    {
        return p && (trailer != p) && (header != p);
    }
    int disordered() const;
    ListNodePosi(T) find(T const& e) const
    {
        return find(e,_size,trailer);
    }
    ListNodePosi(T) find(T const& e,int n, ListNodePosi(T) p) const;
    ListNodePosi(T) search(T const& e) const
    {
        return search(e, _size, trailer);
    }
    ListNodePosi(T) search(T const& e, int n, ListNodePosi(T) p) const;
    ListNodePosi(T) selectMax(ListNodePosi(T) p ,int n);
    ListNodePosi(T) selectMax() 
    {
        return selectMax(header->succ,_size);
    }

    ListNodePosi(T) insertAsFirst(T const& e);
    ListNodePosi(T) insertAsLast(T const& e);
    ListNodePosi(T) insertA(ListNodePosi(T) p, T const& e);
    ListNodePosi(T) insertB(ListNodePosi(T) p, T const& e);
    T remove(ListNodePosi(T) p);
    
    /*
    void merge(List<T>& L)
    {
        merge(first(),size,L,L.first(),L._size);
    }
    */
    void sort(ListNodePosi(T) p,int n);
    void sort()
    {
        sort(first(),_size);
    }
    int deduplicate();
    int uniquify();
    void reverse();

    void traverse(void(* ) (T&));
    template <typename VST>
        void traverse(VST&);

};

template <typename T>
List<T>::~List<T>()
{
    std::cout<<"bye"<<std::endl;
}

template <typename T> 
void List<T>::init(){
    header = new ListNode<T>;
    trailer = new ListNode<T>;
    header->succ = trailer;
    header->pred = NULL;
    trailer->pred = header;
    trailer->succ = NULL;
    _size = 0;
}

template <typename T>
T& List<T>::operator[] (Rank r) const{ //assert: 0<=r<=_size
    ListNodePosi(T) p = first();
    while(0 < r--)
        p = p->succ;
    return p->data;
}
