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

  last->next = iter->next;

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

    isDeleted = 1;
  }
  return isDeleted;
}

void addRegion(LinkedList list,Region reg){
  Node new = malloc(sizeof(struct node));

  new->element = reg;
  new->next = NULL;

  list->last->next = new;
  list->last = new;
  list->size = list->size + 1;
}

int getSize(LinkedList list){
  return list->size;
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
