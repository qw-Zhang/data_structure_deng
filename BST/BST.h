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
    BinTree<T>::updateHeightAbove(x);
    return x;
}

template <typename T>
static BinNodePosi(T) removeAt(BinNodePosi(T)& x, BinNodePosi(T)& hot){
    BinNodePosi(T) w = x;
    BinNodePosi(T) succ_temp = NULL;
    if(!HasLChild(*x)){
        succ_temp = x = x->rc;
    }
    else if(!HasRChild(*x)){
        succ_temp = x = x->lc;
    }
    else{
        w = w->succ();
        //swap(x->data,w->data);
        T temp;
        temp = x->data;
        x->data = w->data;
        w->data = temp;
        BinNodePosi(T) u = w->parent;
        ((u==x)? u->rc:u->lc) = succ_temp = w->rc;
    }
    hot = w->parent;
    if(succ_temp){
        succ_temp->parent = hot;
    }
    //release(w->data);
//    delete w->data;
    delete w;
    //release(w);
    return succ_temp;
}

template <typename T> bool BST<T>::remove(const T& e){
    BinNodePosi(T)& x = search(e);
    if(!x){
        return false;
    }
    removeAt(x, this->_hot);
    this->_size--;
    BinTree<T>::updateHeightAbove(this->_hot);
    return true;
}

