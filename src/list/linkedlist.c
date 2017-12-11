/*
 * ENSICAEN
 * 6 Boulevard Marechal Juin
 * F-14050 Caen Cedex
 *
 * This file is owned by ENSICAEN students.
 * No portion of this document may be reproduced, copied
 * or revised without written permission of the authors.
 */
/**
  * @file linkedlist.c
  */
#include "list/linkedlist.h"
#include "fct/region.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

struct node {
  Region element;
  Node next;
};

struct linkedlist {
  Node first;
  Node last;
  int size;
};

/** Copies a Node. Without its next pointer.
  * @param node the node the perform the operations.
  * @return the copy of the node.
  */
static Node copyNode(Node node);

LinkedList createList(){
  LinkedList list = malloc(sizeof(struct linkedlist));
  list->size = 0;
  return list;
}

Region get(LinkedList list,int index){
  Node iter = getIterator(list);

  assert(list->size > index);

  while(index) {
    iter = getNext(iter);
    index--;
  }

  return getElement(iter);
}

void deleteIndex(LinkedList list,int index){
  Node iter = getIterator(list);
  Node last;

  assert(list->size > index);

  while(index) {
    last = iter;
    iter = getNext(iter);
    index--;
  }

  /* destroying the node at the given index */
  last->next = iter->next;
  destroyNode(iter);

  if(last->next == NULL) {  /* if it is the last member */
    list->last = last;
  }

  list->size = list->size - 1;
}

int getIndex(LinkedList list,Region reg){
  Node iter = getIterator(list);
  int index;

  index = 0;

  while(!isSame(getElement(iter), reg) && hasNext(iter)) {
    iter = getNext(iter);
    index++;
  }

  /* if the region has not been found */
  if (!isSame(getElement(iter), reg)) {
    index = -1;
  }

  return index;
}

int deleteRegion(LinkedList list,Region reg){
  Node iter = getIterator(list);
  Node last;
  int isDeleted;

  isDeleted = 0;

  while (!isSame(getElement(iter), reg) && hasNext(iter)) {
    last = iter;
    iter = getNext(iter);
  }

  /* if the region has not been found */
  if (isSame(getElement(iter), reg)) {
    last->next = iter->next;

    if(last->next == NULL) {  /* if it is the last member */
      list->last = last;
    }

    list->size = list->size - 1;
    destroyNode(iter);
    isDeleted = 1;
  }
  return isDeleted;
}

void addRegion(LinkedList list,Region reg){
  Node new = malloc(sizeof(struct node));

  new->element = reg;
  new->next = NULL;

  /* if this is the first element */
  if (list->size == 0) {
    list->first = new;
  } else {
    list->last->next = new;
  }
  list->last = new;


  list->size = list->size + 1;
}

int getSize(LinkedList list){
  return list->size;
}

LinkedList mergeList(LinkedList l1, LinkedList l2){
  LinkedList list = createList();
  Node iter = getIterator(l1);
  Node last;

  last = list->first;

  while(hasNext(iter)){
    iter = getNext(iter);
    last->next = copyNode(iter);
    last = getNext(last);
  }

  iter = getIterator(l2);
  while(hasNext(iter)){
    iter = getNext(iter);
    last->next = copyNode(iter);
    last = getNext(last);
  }

  list->size = l1->size + l2->size;

  return list;
}

void destroyList(LinkedList list){
  Node iter = getIterator(list);
  Node next = iter;

  while(hasNext(iter)) {
    iter = next;
    next = getNext(iter);
    destroyNode(iter);
  }

  free(list);
}

static Node copyNode(Node node){
  Node new = malloc(sizeof(struct node));
  new->element = node->element;
  return new;
}

Node getIterator(LinkedList list){
  return list->first;
}

int hasNext(Node node){
  return node->next != NULL ? 1 : 0;
}

Node getNext(Node node){
  return node->next;
}

Region getElement(Node node){
  return node->element;
}

void destroyNode(Node node) {
  free(node);
}
