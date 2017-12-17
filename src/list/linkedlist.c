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

struct iterator {
  Node current;
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
  Iterator iter = getIterator(list);

  assert(list->size > index);

  while(index--) {
    moveNext(iter);
  }

  return getElement(iter);
}

void deleteIndex(LinkedList list,int index){
  Node iter = list->first;
  Node last;

  assert(list->size > index);

  while(index) {
    last = iter;
    iter = iter->next;
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
  Iterator iter = getIterator(list);
  int index;

  index = 0;

  while(moveNext(iter)) {
    if(isSame(getElement(iter), reg)) {
      break;
    }
    index++;
  }

  /* if the region has not been found */
  if (!isSame(getElement(iter), reg)) {
    index = -1;
  }
  destroyIterator(iter);

  return index;
}

int deleteRegion(LinkedList list,Region reg){
  Iterator iter = getIterator(list);
  Node last;
  int isDeleted;

  isDeleted = 0;

  do{
    last = iter->current;
    if (isSame(getElement(iter), reg)) {
      break;
    }
  } while (moveNext(iter));

  /* if the region has been found */
  if (isSame(getElement(iter), reg)) {
    last->next = iter->current->next;

    if(last->next == NULL) {  /* if it is the last member */
      list->last = last;
    }

    list->size = list->size - 1;
    isDeleted = 1;
  }

  destroyIterator(iter);

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
  Iterator iter;
  Node last, tmp;

  iter = getIterator(l1);
  if (moveNext(iter)) {
    /* Init the first element of the list */
    last = copyNode(iter->current);
    list->first = last;
  }

  /* copy the first list in the new list */
  while(moveNext(iter)) {
    tmp = copyNode(iter->current);
    last->next = tmp;
    last =tmp;
  }

  destroyIterator(iter);
  iter = getIterator(l2);
  /* copy the second list in the new list */
  while(moveNext(iter)) {
    tmp = copyNode(iter->current);
    last->next = tmp;
    last =tmp;
  }

  list->last = last;
  list->size = l1->size + l2->size;

  return list;
}

void destroyList(LinkedList list){
  Iterator iter = getIterator(list);

  while(moveNext(iter)) {
    destroyNode(iter->current);
  }

  destroyIterator(iter);
  free(list);
}

static Node copyNode(Node node){
  Node new = malloc(sizeof(struct node));
  new->element = node->element;
  return new;
}

Iterator getIterator(LinkedList list){
  Iterator iter = malloc(sizeof(Iterator));
  Node first = malloc(sizeof(Node));
  first->next = list->first;
  iter->current = first;
  return iter;
}

void destroyNode(Node node) {
  free(node);
}

int moveNext(Iterator iter) {
  Node next;

  next = iter->current->next;

  if (next) { /* If there is a next one */
    iter->current = next;
    return 1;
  } else {
    /* Nothing here because the iterator stays at the last element of the list */
    return 0;
  }
}

Region getElement(Iterator iter){
  return iter->current->element;
}

void destroyIterator(Iterator iter) {
  free(iter);
}
