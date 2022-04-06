#define STRUCTURE

#ifndef NULL
#define NULL ((void*)0)
#endif

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