#define STRUCTURE

#ifndef NULL
#define NULL ((void*)0)
#endif

#define visit(p,q) (*((p)+(q)))

struct stack{
    
    void push();
    void pop();
};
struct list{
    
};

struct chainNode{
    chainNode* up;
    void* value=NULL;
};
struct treeNode{
    treeNode* leftson;
    treeNode* rightson;
    treeNode* root;
    void* here=NULL;
};