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
    chainNode* up=NULL;
    void* value=NULL;
};

struct chain{
    
    chainNode* head;
    chainNode* tail;
    
    inline chain(){
        head= new chainNode;
        tail=head;
    };
    inline chain(chainNode*& c){
        head=c;
        tail=head;
    };
    void append(void*& value){
        tail->up=new chainNode;
        tail=tail->up;
        tail->value=value;
    };
    bool remove(void*& addr){
        chainNode* here=head;
        chainNode* past=NULL;
        do{
            if(here->value==addr){
                past->up=here->up;
                delete here->value;
                delete here->up;
                delete here;
                return true;
            }
            past=here;
            here=here->up;
        }while(here!=NULL);
        return false;
    };
    
};

struct treeNode{
    treeNode* leftson;
    treeNode* rightson;
    treeNode* root;
    void* value=NULL;
};