#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *lchild;
    int data;
    int height;
    struct Node *rchild;
} *root = NULL;

int NodeHeight(struct Node *p)
{
    int hl, hr;
    hl = p && p->lchild ? p->lchild->height : 0;
    hr = p && p->rchild ? p->rchild->height : 0;
    return hl > hr ? hl + 1 : hr + 1;
}

int BalanceFactorCal(struct Node *p)
{
    int hl, hr;
    hl = p && p->lchild ? p->lchild->height : 0;
    hr = p && p->rchild ? p->rchild->height : 0;

    return hl - hr;
}

struct Node *LLRotation(struct Node *p)
{
    struct Node *pl = p->lchild;
    struct Node *plr = pl->rchild;

    pl->rchild = p;
    p->lchild = plr;

    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);

    if (root == p)
    {
        root = pl;
    }

    return pl; // this is new root
}

struct Node *RRRotation(struct Node *p)
{
    struct Node *pr = p->rchild;
    struct Node *prl = pr->lchild;

    pr->lchild = p;
    p->rchild = prl;

    p->height = NodeHeight(p);
    pr->height = NodeHeight(pr);

    if (root == p)
    {
        root = pr;
    }

    return pr; // this is new root
}

struct Node *LRRotation(struct Node *p)
{
    struct Node *pl = p->lchild;
    struct Node *plr = pl->rchild;
    pl->rchild = plr->lchild;
    p->lchild = plr->rchild;

    plr->lchild = pl;
    plr->rchild = p;

    pl->height = NodeHeight(pl);
    plr->height = NodeHeight(plr);
    p->height = NodeHeight(p);

    if (root == p)
    {
        root = plr;
    }
    return plr;
}

struct Node *RLRotation(struct Node *p)
{
    struct Node *pr = p->rchild;
    struct Node *prl = pr->lchild;
    pr->lchild = prl->rchild;
    p->rchild = prl->lchild;

    prl->rchild = pr;
    prl->lchild = p;

    pr->height = NodeHeight(pr);
    prl->height = NodeHeight(prl);
    p->height = NodeHeight(p);

    if (root == p)
    {
        root = prl;
    }
    return prl;
}

struct Node *RecursiveInsert(struct Node *p, int key)
{                  // p is root
    if (p == NULL) // if the tree if empty
    {
        Node *t = (struct Node *)malloc(sizeof(struct Node));
        t->data = key;
        t->height = 1; // height of the tree starting at 0 but we will try starting at 1
        t->lchild = t->rchild = NULL;
        return t;
    }
    if (key < p->data)
    { // insert in the LHS
        p->lchild = RecursiveInsert(p->lchild, key);
    }
    else if (key > p->data)
    { // insert in the RHS
        p->rchild = RecursiveInsert(p->rchild, key);
    }

    // update height of the current node that we just add, due to recursive, we will revisit the branch that we added till the root node to check for imbalance
    p->height = NodeHeight(p);

    if (BalanceFactorCal(p) == 2 && BalanceFactorCal(p->lchild) == 1)
    { // condition to do LL rotation
        return LLRotation(p);
    }
    else if (BalanceFactorCal(p) == 2 && BalanceFactorCal(p->lchild) == -1)
    {
        return LRRotation(p);
    }
    else if (BalanceFactorCal(p) == -2 && BalanceFactorCal(p->rchild) == -1)
    {
        return RRRotation(p);
    }
    else if (BalanceFactorCal(p) == -2 && BalanceFactorCal(p->rchild) == 1)
    {
        return RLRotation(p);
    }

    return p;
}

int main()
{
    root = RecursiveInsert(root, 50);
    RecursiveInsert(root, 10);
    RecursiveInsert(root, 20);

    printf("Root Data is: %d", root->data);

    return 0;
}