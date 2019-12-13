#include "BinNode.h"
#include "../Stack/Stack.h"
#include "../Stack/queue.h"
//#include <memory>

template <typename T>
class BinTree
{
protected:
    int _size;
    BinNodePosi(T) _root;
    virtual int updateHeight(BinNodePosi(T) x); //this virtual function is a interface because every binTree may have different define of its height
    void updateHeightAbove(BinNodePosi(T) x);

public:
    BinTree()
    {
        _size = 0;
        _root = NULL;
    }

    ~BinTree()
    {
        if (0 < _size)
        {
            remove(_root);
        }
    }

    int size() const { return _size; }
    bool empty() const { return !_root; }

    BinNodePosi(T) root() const { return _root; }
    BinNodePosi(T) insertAsRoot(T const &e);
    BinNodePosi(T) insertAsLC(BinNodePosi(T) x, T const &e);
    BinNodePosi(T) insertAsRC(BinNodePosi(T) x, T const &e);
    BinNodePosi(T) attachAsLC(BinNodePosi(T) x, BinTree<T> *&S);
    BinNodePosi(T) attachAsRC(BinNodePosi(T) x, BinTree<T> *&S);
    int remove(BinNodePosi(T) x);
    BinTree<T> *secede(BinNodePosi(T) x);

    template <typename VST>
    void travLevel(VST &visit)
    {
        if (_root)
        {
            _root->travLevel(visit);
        }
    }
    template <typename VST>
    void travPre(VST &visit)
    {
        if (_root)
        {
            _root->travPre(visit);
        }
    }
    template <typename VST>
    void travIn(VST &visit)
    {
        if (_root)
        {
            _root->travIn(visit);
        }
    }
    template <typename VST>
    void travPost(VST &visit)
    {
        if (_root)
        {
            _root->travPost(visit);
        }
    }

    bool operator<(BinTree<T> const &t)
    {
        return _root && t._root && lt(_root, t._root);
    }
    bool operator==(BinTree<T> const &t)
    {
        return _root && t._root && (_root->data == t._root->data);
    }
};

template <typename T>
bool lt(BinNodePosi(T) r1, BinNodePosi(T) r2)
{
    return (r1->data) < (r2->data);
}

int max(int m1, int m2)
{
    if (m1 > m2)
    {
        return m1;
    }
    return m2;
}

template <typename T>
int BinTree<T>::updateHeight(BinNodePosi(T) x)
{
    return x->height = 1 + max(stature(x->lc), stature(x->rc));
}

template <typename T>
void BinTree<T>::updateHeightAbove(BinNodePosi(T) x)
{
    while (x)
    {
        updateHeight(x);
        x = x->parent;
    }
}

template <typename T>
BinNodePosi(T) BinTree<T>::insertAsRoot(T const &e)
{
    _size = 1;
    return _root = new BinNode<T>(e);
}

template <typename T>
BinNodePosi(T) BinTree<T>::insertAsLC(BinNodePosi(T) x, T const &e)
{
    _size++;
    x->insertAsLC(e);
    updateHeightAbove(x);
    return x->lc;
}

template <typename T>
BinNodePosi(T) BinTree<T>::insertAsRC(BinNodePosi(T) x, T const &e)
{
    _size++;
    x->insertAsRC(e);
    updateHeightAbove(x);
    return x->rc;
}

template <typename T>
BinNodePosi(T) BinTree<T>::attachAsLC(BinNodePosi(T) x, BinTree<T> *&S)
{
    if (x->lc = S->_root)
    {
        x->lc->parent = x;
    }
    _size += S->_size;
    updateHeightAbove(x);
    S->_root = NULL;
    S->_size = 0;
    release(S);
    S = NULL;
    return x;
}

template <typename T>
BinNodePosi(T) BinTree<T>::attachAsRC(BinNodePosi(T) x, BinTree<T> *&S)
{
    if (x->rc = S->_root)
    {
        x->rc->parent = x;
    }
    _size += S->_size;
    updateHeightAbove(x);
    S->_root = NULL;
    S->_size = 0;
    release(S);
    S = NULL;
    return x;
}

template <typename T>
int BinTree<T>::remove(BinNodePosi(T) x)
{
    FromParentTo(*x) = NULL; //???
    updateHeightAbove(x->parent);
    int n = removeAt(x);
    _size -= n;
    return n;
}

template <typename T>
static int removeAt(BinNodePosi(T) x)
{
    if (!x)
    {
        return 0;
    }
    int n = 1 + removeAt(x->lc) + removeAt(x->rc);
    //release(x->data);
    release(x);
    return n;
}

template <typename T>
BinTree<T> *BinTree<T>::secede(BinNodePosi(T) x)
{
    FromParentTo(*x) = NULL;
    updateHeightAbove(x->parent);
    BinTree<T> *S = new BinTree<T>;
    S->_root = x;
    x->parent = NULL;
    S->_size = x->size();
    _size -= S->_size;
    return S;
}

template <typename T, typename VST>
void traverse(BinNodePosi(T) x, VST &visit) //this function is general iteration algorithm. It's easy to transform preorder, inorder or backorder
                                            // but the efficency is slow.
{
    if (!x)
        return;
    visit(x->data);
    traverse(x->lc, visit);
    traverse(x->rc, visit);
}

template <typename T, typename VST>
void travPre_I1(BinNodePosi(T) x, VST &visit)
{
    Stack<BinNodePosi(T)> S;
    if (x)
    {
        S.push();
    }
    while (!S.empty())
    {
        x = S.pop();
        visit(x->data);
        if (HasRChild(*x))
        {
            S.push(x->rc);
        }
        if (HasLChild(*x))
        {
            S.push(x->lc);
        }
    }
}

template <typename T, typename VST>
static void visitAlongLeftBranch(BinNodePosi(T) x, VST &visit, Stack<BinNodePosi(T)> &S)
{
    while (x)
    {
        visit(x->data);
        S.push(x->rc);
        x = x->lc;
    }
}

template <typename T, typename VST>
void travPre_I2(BinNodePosi(T) x, VST &visit)
{
    Stack<BinNodePosi(T)> S;
    while (true)
    {
        visitAlongLeftBranch(x, visit, S);
        if (S.empty())
        {
            break;
        }
        x = S.pop();
    }
}

template <typename T>
static void goAlongLeftBranch(BinNodePosi(T) x, Stack<BinNodePosi(T)> &S)
{
    while (x)
    {
        S.push(x);
        x = x->lc;
    }
}

template <typename T, typename VST>
void travIn_1(BinNodePosi(T) x, VST &visit)
{
    Stack<BinNodePosi(T)> S;
    while (true)
    {
        goAlongLeftBranch(x, S);
        if (S.empty())
        {
            break;
        }
        x = S.pop();
        visit(x->data);
        x = x->rc;
    }
}

template <typename T> template <typename VST>
void BinNode<T>::travLevel(VST & visit)
{
    Queue <BinNodePosi(T)> Q;
    Q.enqueue(this);
    while(!Q.empty()){
        BinNodePosi(T) x = Q.dequeue();
        visit(x->data);
        if(HasLChild(*x)){
            Q.enqueue(x->lc);
        }
        if(HasRChild(*x)){
            Q.enqueue(x->rc);
        }
    }
    
}