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
  * @file rag.c contains all the functions manipulating the
  * Region Adjacency Graph.
  * This graph contains all the regions (group of pixels) of the loaded picture
  */

#ifndef _RAG_H
#define _RAG_H


#include "fct/region.h"

/**
 * The structure Rag represents the organisation of all regions loaded from the
 * picture you want to segmentate.
 * This structure contains the list of all regions and informations about the
 * original regions and the image structure.
 */
typedef struct rag* Rag;

/**
 * Create a Rag from a given picture
 * @param img (image structure) the picture you want to turn into rag
 * @param the original height of each region
 * @param the original width of each region
 * @return the Rag of the given picture
 */
Rag createRag(image img,int height,int width);

/**
 * Create an image sctructure from a given Rag
 * @param the Rag you want to turn into image structure
 * @return the image structure of the given Rag
 */
image getRegionImage(Rag rag);

/**
 * Allow to get the original height of each region
 * @param the Rag you want the original height of each region
 * @return the original height
 */
int getHeight(Rag rag);

/**
 * Allow to get the original width of each region
 * @param the Rag you want the original width of each region
 * @return the original width
 */
int getWidth(Rag rag);

/**
 * Allow to get the image dimension
 * @param the Rag you want the image dimension
 * @return the image dimension
 */
int getDimension(Rag rag);

/**
 * Allow to get the current partition error of the Rag
 * @param the Rag you want the partition error
 * @return the partition error of the given Rag
 */
double getPartitionError(Rag rag);

/**
 * Allow to get the list of all the blocks (original regions) of the Rag
 * @param the Rag you want the list of blocks
 * @return the list of blocks contained in the given Rag
 */
LinkedList getBlocks(Rag rag);


#endif
