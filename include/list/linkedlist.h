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
  * @file linkedlist.h
  */
#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H

#include "fct/region.h"

typedef struct node* Node;

typedef struct linkedlist* LinkedList;

LinkedList createList();

Region get(LinkedList list,int index);

void deleteIndex(LinkedList list,int index);

int getIndex(LinkedList list,Region reg);

int deleteRegion(LinkedList list,Region reg);

void addRegion(LinkedList list,Region reg);

int getSize(LinkedList list);

Node getIterator(LinkedList list);

int hasNext(Node node);

Node getNext(Node node);

Region getElement(Node node);

#endif
