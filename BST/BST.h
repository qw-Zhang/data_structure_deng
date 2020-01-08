#include "../BinaryTree/BinTree.h"

template <typename T> class BST : public BinTree<T>{
    protected:
        BinNodePosi(T) _hot;
        BinNodePosi(T) connect34(
            BinNodePosi(T), BinNodePosi(T), BinNodePosi(T), 
            BinNodePosi(T), BinNodePosi(T), BinNodePosi(T), BinNodePosi(T)
        );
        BinNodePosi(T) rotateAt(BinNodePosi(T) x);
    public:
        //i don't know why the function which is nearest "public" can't use normally...
        //so i add variable named "nothing" between the first funtion and "public"..
        int nothing;
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
    return searchIn(this->_root, e , this->_hot = NULL);
}

template <typename T>
BinNodePosi(T) BST<T>::insert(const T& e){
    BinNodePosi(T)& x = search(e);
    if(x){
        return x;
    }

    x = new BinNode<T>(e,_hot);
    this->_size++;
    updateHeightAbove(x);
    return x;
}

template <typename T> bool BST<T>::remove(const T& e){
    BinNodePosi(T)& x = search(e);
    if(!x){
        return false;
    }
    removeAt(x, _hot);
    this->_size--;
    updateHeightAbove(_hot);
    return true;
}

template <typename T>
static BinNodePosi(T) removeAt(BinNodePosi(T)& x, BinNodePosi(T)& hot){
    BinNodePosi(T) w = x;
    BinNodePosi(T) succ = NULL;
    if(!HasLChild(*x)){
        succ = x = x->rc;
    }
    else if(!HasRChild(*x)){
        succ = x = x->lc;
    }
    else{
        w = w->succ();
        swap(x->data,w->data);
        BinNodePosi(T) u = w->parent;
        ((u==x)? u->rc:u->lc) = succ = w->rc;
    }
    hot = w->parent;
    if(succ){
        succ->parent = hot;
    }
    //release(w->data);
    delete w->data;
    delete w;
    //release(w);
    return succ;
}