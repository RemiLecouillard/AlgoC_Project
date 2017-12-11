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
  * @file linkedlist.h This file contains all the functions to handle a list
  * and node.
  */
#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H

#include "fct/region.h"

/** This is a pointer to a structure of a node.
  * Every elements of a list is a node.
  * Can be used as an iterator.
  */
typedef struct node* Node;

/** This is a pointer to a structure of a list.
  * The list is indexed from 0 to size - 1.
  */
typedef struct linkedlist* LinkedList;

/** Creates a LinkedList.
  * @return the created list.
  */
LinkedList createList();

/** Seeks for the Region at the given index
  * The index must be betwen 0 and size-1
  * @param list the list to perform operations
  * @param index the wanted index
  * @return the Region at the given index
  */
Region get(LinkedList list,int index);

/** Deletes the Region at the given index
  * @param list the list to perform operations
  * @param index the wanted index
  */
void deleteIndex(LinkedList list,int index);

/** Returns the index of the first occurence of the given Region
  * @param list the list to perform operations
  * @param reg the wanted region
  * @return the index of the region in the list
  */
int getIndex(LinkedList list,Region reg);

/** Deletes the given Region.
  * @param list the list to perform operations
  * @param reg the region to erase from the list
  * @return 1 if the region has been deleted. 0 otherwise.
  */
int deleteRegion(LinkedList list,Region reg);

/** Adds the given Region at the end of the list.
  * @param list the list to perform operations
  * @param reg the region to add
  */
void addRegion(LinkedList list,Region reg);

/**
  * @param list the list to perform operations
  * @return the number of elements in the list
  */
int getSize(LinkedList list);

/** Merges two lists by creating an other one.
  * The old ones are still usable.
  * @param l1 the first list to merge
  * @param l2 the second list to merge
  * @return the new list
  */
LinkedList mergeList(LinkedList l1, LinkedList l2);

/** Destroy the giving list by freeing the memory.
  * @param list the list to perform operations
  */
void destroyList(LinkedList list);

/** Returns an object to iterate the list.
  * @param list the list to perform operations
  * @param the first Node of the list
  */
Node getIterator(LinkedList list);

/** Tells if there is an other node after.
  * @param node the node the perform the operations.
  * @return 1 if has a next node. 0 otherwise.
  */
int hasNext(Node node);

/**
  * @param node the node the perform the operations.
  * @return the next Node
  */
Node getNext(Node node);

/**
  * @param node the node the perform the operations.
  * @return the Region in the Node
  */
Region getElement(Node node);

/**
  * @param node the node the perform the operations.
  */
void destroyNode(Node node);

#endif
