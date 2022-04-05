#define STRUCTURE

#define NULL ((void*)0)

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