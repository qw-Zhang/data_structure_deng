#include<cstdlib>

typedef int Rank;
#define ListNodePosi(T) ListNode<T>*

template <typename T> struct ListNode{
    T data;
    ListNodePosi(T) pred;
    ListNodePosi(T) succ;

    ListNode(){

    }

    //ListNode(T e,ListNodePosi(T) p = NULL,ListNodePosi(T) s = NULL){
    ListNode(T e,ListNodePosi(T) p = NULL,ListNodePosi(T) s = NULL){
        data = e;
        pred = p;
        succ = s;
    }

    ListNodePosi(T) insertAsPred(T const& e);
    ListNodePosi(T) insertAsSucc(T const& e);
};

template <typename T>
ListNodePosi(T) ListNode<T>::insertAsPred(T const& e){
    ListNodePosi(T) n = new ListNode(e,pred,this);
    pred->succ = n;
    this->pred = n;
    return n;
}


template <typename T>
ListNodePosi(T) ListNode<T>::insertAsSucc(T const& e){
    ListNodePosi(T) n = new ListNode(e,this,succ);
    succ->pred = n;
    this->succ = n;
    return n;
}
