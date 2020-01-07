#include "../BinaryTree/BinTree.h"

template <typename T> class BST : public BinTree<T>{
    protected:
        BinNodePosi(T) _hot;
        BinNodePosi(T) connect34(
            BinNodePosi(T), BinNodePosi(T), BinNodePosi(T), 
            BinNodePosi(T), BinNodePosi(T), BinNodePosi(T), BinNodePosi(T);
        )

    public:
        void nothing(void);
        virtual BinNodePosi(T) insert(const T& e);
        virtual bool remove( const T& e);
        virtual BinNodePosi(T)& search( const T& e);
};

template <typename T>
static BinNodePosi(T) & searchIn(BinNodePosi(T) & v, const T& e, BinNodePosi(T) & hot){
    if(!v || (e == v->data)){
        return v;
    }
    hot = v;
    return searchIn( ( ( e < v->data )? v->lc : v->rc ) , e , hot);
}

template <typename T>
BinNodePosi(T)& BST<T>::search( const T& e){
    return searchIn(_root, e , _hot = NULL);
}
