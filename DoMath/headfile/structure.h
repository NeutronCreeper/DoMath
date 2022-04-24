#define STRUCTURE

#ifndef NULL
#define NULL ((void*)0)
#endif



struct stack{
    
    void push();
    void pop();
};
struct list{
    
};

template<typename data>struct chainNode{
    chainNode* up=NULL;
    data value;
};

template<typename data>struct chain{
    chainNode<data>* head;
    chainNode<data>* tail;
    unsigned short length;

    chain(){
        head= new chainNode<data>;
        tail=head;
        length=1;
    };
    chain(const data& value){
        head= new chainNode<data>;
        head->value=value;
        tail=head;
        length=1;
    };
    ~chain(){
        chainNode<data>* here=head;
        chainNode<data>* next_one=head->up;
        do{
            delete here;
            here=next_one;
            next_one=next_one->up;
        }while(next_one!=NULL);
    };
    void operator+=(const data& value){
        tail->up= new chainNode<data>;
        tail=tail->up;
        tail->value=value;
        length++;
    };
    void operator+=(const chain<data>& chain2){
        chainNode<data>* here=chain2.head;
        do{
            tail->up= new chainNode<data>;
            tail=tail->up;
            tail->value=here->value;
            here=here->up;
        }while(here!=NULL);
    };
    bool operator-=(const data& value){
        chainNode<data>* here=head->up;
        chainNode<data>* previous=head;
        bool deleted=false;
        if(head->value==value){
            head=head->up;
            delete previous;
            deleted=true;
            length--;
        }
        do{
            if(here->value==value){
                previous->up=here->up;
                delete here;
                deleted=true;
                length--;
            }
            previous=here;
            here=here->up;
        }while(here!=NULL);
        return deleted;
    };
    void operator=(const chain<data>& chain2){
        chainNode<data>* here=chain2.head;
        length=0;
        tail=head;
        do{
            tail->value=here->value;
            if(tail->up==NULL) tail->up= new chainNode<data>;
            tail=tail->up;
            here=here->up;
            length++;
        }while(here!=NULL);
    };
    bool searchfor(const data& value){
        chainNode<data>* here=head;
        do{
            if(here->value==value) return true;
            here=here->up;
        }while(here!=NULL);
        return false;
    };
    void print(std::ostream& output,char placeholder=' '){
        chainNode<data>* here=head;
        do{
            output<<here->value<<placeholder;
            here=here->up;
        }while(here!=NULL);
    };
};




template<typename data>struct treeNode{
    chain<treeNode*> sons;
    treeNode* father;
    unsigned char height;
    data value;
};
template<typename data>struct tree{
    treeNode<data>* root;
    tree(){
        root= new treeNode<data>;
    };
    tree(const data& value){
        root= new treeNode<data>;
        root->value=value;
    };
    tree(const tree<data>& tree2){
        root= new treeNode<data>;
        root->sons.head=tree2.root;
    };
};