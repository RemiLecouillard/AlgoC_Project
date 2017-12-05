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

  return NULL;
}

Region get(LinkedList list,int index){

  return NULL;
}

void deleteIndex(LinkedList list,int index){

}

int getIndex(LinkedList list,Region reg){


  return 0;
}

void deleteRegion(LinkedList list,Region reg){

}

int getSize(LinkedList list){

  return 0;
}

Node getIterator(LinkedList list){

  return NULL;
}

int hasNext(Node node){

}

Node getNext(Node node){

  return NULL;
}

Region getElement(Node node){

  return NULL;
}
