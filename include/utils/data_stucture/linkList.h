//
// Created by 陈瀚泽 on 2019-03-26.
//

#ifndef DUNGEON_COMS327_F19_LINKLIST_H
#define DUNGEON_COMS327_F19_LINKLIST_H

template <class T>
class linkList {
private:
    typedef struct linkNode{
        T data;
        linkNode * prevNode;
        linkNode * nextNode;
    }linkNode_t;

    int numberOfNode = 0;
    linkNode_t *tailNode = nullptr;
    linkNode_t *headNode = nullptr;

    bool isEmpty();
    void checkInit();
    void * getNodePtrByIndex(int x);
    void removeNode(linkNode_t node);
    void insertNode(linkNode_t * node1, linkNode_t node2);
public:

    //get opreation
    T pop();
    T peek();

    //add operation
    T add(T data);
    int add(T data, int index);

    //get propriety
    int size();
    int indexOf(T data);

    //remove operation
    int clear();
    T remove(T data);
    int remove(int index);

};




#endif //DUNGEON_COMS327_F19_LINKLIST_H
