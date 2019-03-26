//
// Created by 陈瀚泽 on 2019-03-26.
//

#include <MacTypes.h>
#include <cstdlib>
#include "../../../include/utils/data_stucture/linkList.h"

template<class T>
int linkList<T>::size() {return numberOfNode;}

template<class T>
bool linkList<T>::isEmpty() { return this->numberOfNode == 0;}

template<class T>
int linkList<T>::indexOf(T data) {
    linkNode_t tmpNode = new linkNode_t;
    memccpy(&tmpNode,this->headNode, sizeof(linkNode_t));

    for (int i = 0; i < numberOfNode; ++i) {
        if(tmpNode.data == data)
            return i;
        else
            tmpNode = tmpNode.nextNode;
    }
}

template<class T>
void *linkList<T>::getNodePtrByIndex(int x) {
    linkNode_t tmpNode = new linkNode_t;
    memccpy(&tmpNode,this->headNode, sizeof(linkNode_t));

    if (x > this->numberOfNode)
        return nullptr;

    for (int i = 0; i < x ; ++i)
        tmpNode = tmpNode.nextNode;

    return tmpNode;
}

template<class T>
T linkList<T>::add(T data) {
    linkNode_t * tmpNode = new linkNode_t;
    memcpy(tmpNode->data,&data, sizeof(data));
    insertNode(&tmpNode, &tailNode);
}

template<class T>
void linkList<T>::removeNode(linkList::linkNode_t node) {
    node.nextNode->prevNode = node.prevNode;
    node.prevNode->nextNode = node.nextNode;

    free(node);
}

template<class T>
void linkList<T>::checkInit() {
    if (this->tailNode == nullptr && this->headNode == nullptr){
        tailNode = new linkNode_t;
        headNode = new linkNode_t;

        tailNode->data = nullptr;
        headNode->data = nullptr;

        tailNode->nextNode = headNode;
        tailNode->prevNode = headNode;

        headNode->nextNode = tailNode;
        headNode->prevNode = tailNode;
    }
}

template<class T>
int linkList<T>::clear() {
    headNode = headNode->nextNode;
    while (headNode->data != nullptr){
        linkNode_t * tmpNodePtr = headNode;
        headNode = headNode->nextNode;
        free(headNode);
    }

    free(headNode);
    free(tailNode);
}

template<class T>
T linkList<T>::pop() {
    T result = tailNode->prevNode->data;
    removeNode(tailNode->prevNode);
    return result;
}

template<class T>
T linkList<T>::peek() { return tailNode->prevNode->data; }

template<class T>
int linkList<T>::add(T data, int index) {
    linkNode_t * tmpNode = new linkNode_t;
    linkNode_t * tmpNodePtr = getNodePtrByIndex(index);

    insertNode(tmpNode,tmpNodePtr);
}

template<class T>
T linkList<T>::remove(T data) {
   linkNode_t * tmpNode = headNode;

   while (tmpNode->data != nullptr){
       if (tmpNode->data == data){
           T result = tmpNode->data;
           remove(tmpNode);
           return result;
       }
   }

    return nullptr;
}

template<class T>
int linkList<T>::remove(int index) {
    removeNode(getNodePtrByIndex(index));
    return 0;
}

template<class T>
void linkList<T>::insertNode(linkList::linkNode_t *node1, linkList::linkNode_t node2) {
    checkInit();
    node1->prevNode = node2.prevNode;
    node1->nextNode = node2;
    node2.prevNode->nextNode = node1;
    node2.prevNode = node1;
}

