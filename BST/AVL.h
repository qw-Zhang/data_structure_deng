#include "../BST/BST.h"

#define Balance(x) ( stature((x).lc) == stature((x).rc ) )
#define BalFac(x) ( stature((x).lc) - stature((x).rc ) )
#define AvlBalance(x) ( (-2 < BalFac(x)) && (BalFac(x) < 2 ) )

template <typename T> class AVL: public BST<T>{
    public:
        BinNodePosi(T) insert(const T& e);
        bool remove(const T& e);
        //"search..." interfaces in BST are also work
};

#define tallerChild(x) ( \
    stature( (x)->lc ) > stature( (x)->rc ) ? (x)->lc : ( \
    stature( (x)->lc ) < stature( (x)->rc ) ? (x)->rc : ( \
    IsLChild( *(x) ) ? (x)->lc : (x)->rc \
    ) \
    ) \
)

template <typename T> BinNodePosi(T) AVL<T>::insert(const T& e){
    BinNodePosi(T)& x = search(e);
    if(x){
        return x;
    }
    BinNodePosi(T) xx = x = new BinNode<T> (e, this->_hot); this->_size++;

    for(BinNodePosi(T) g = this->_hot; g; g = g->parent){
        if(!AvlBalance(*g)){
            FromParentTo(*g) = rotateAt( tallerChild(tallerChild(g)));
            break;
        } else{
            BinTree<T>::updateHeight(g);
        }
    }
    return xx;
}