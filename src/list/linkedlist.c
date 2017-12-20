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
  Node first;
  Node current;
};

LinkedList createList(){
  LinkedList list = malloc(sizeof(struct linkedlist));
  list->size = 0;
  return list;
}

Region get(LinkedList list,int index){
  Iterator iter = getIterator(list);

  assert(list->size > index);

  do {
    moveNext(iter);
  }while(index--);

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
  Node last = NULL;
  int isDeleted;

  isDeleted = 0;

  while(moveNext(iter)) {
    if (isSame(getElement(iter), reg)) {
      if (last == NULL) {
        list->first = iter->current->next;
        if(list->last == iter->current) {  /* if it is the last member */
          list->last = list->first;
        }
      } else {
        last->next = iter->current->next;
        if(list->last == iter->current) {  /* if it is the last member */
          list->last = last;
        }
      }

      destroyNode(iter->current);
      list->size = list->size - 1;
      isDeleted = 1;
      break;
    }
    last = iter->current;
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

  list->first = l1->first;
  l1->last->next = l2->first;
  list->last = l2->last;

  list->size = l1->size + l2->size;
  /* Don't call destroy because it will destroy the nodes */
  free(l1);
  free(l2);
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

Iterator getIterator(LinkedList list){
  Iterator iter = malloc(sizeof(struct iterator));
  Node first = malloc(sizeof(struct node));
  first->next = list->first;
  iter->current = first;
  iter->first = first;
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
  destroyNode(iter->first);
  free(iter);
}
