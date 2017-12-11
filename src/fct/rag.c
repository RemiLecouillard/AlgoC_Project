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
  * @file rag.c
  */
#include "fct/region.h"
#include "fct/moments.h"
#include "list/linkedlist.h"
#include "image/image.h"
#include "fct/rag.h"
#include <stdlib.h>
#include <stdio.h>


struct rag {
  image image;
  int height, width;
  LinkedList blocks;
};

Rag createRag(image img,int height,int width) {
  Rag rag = malloc(sizeof(struct rag));
  rag->image = img;
  if(image_give_largeur(img)%width == 0 && image_give_hauteur(img)%height == 0){
    rag->height = height;
    rag->width = width;
    rag->blocks = initRegion(rag);
    initNeighbourgs(rag);
    return rag;
  }else{
    printf("Size error\n");
    return NULL;
  }


}

image getRegionImage(Rag rag) {
 return NULL;
}

int getHeight(Rag rag) {
  return rag->height;
}

int getWidth(Rag rag) {
  return rag->width;
}

LinkedList getBlocks(Rag rag) {
 return rag->blocks;
}

static void initNeighbourgs(Rag rag) {
  Region region = NULL;
  Region neighbourg = NULL;
  Node iter = getIterator(getBlocks(rag));
  Node next = iter;
  int num_region;

  while(hasNext(iter)) {
    iter = next;
    next = getNext(iter);
    /*Get all elements next to the region and addNeighbourg*/
    region = getElement(iter);
    addNeighbourg(region, region);
  }
}

static LinkedList initRegion(Rag rag) {

  LinkedList list = createList();
  Region reg = NULL;

  int height = image_give_hauteur(rag->image);
  int width = image_give_largeur(rag->image);
  int pos_bloc_i, pos_bloc_j;
  int pos_pix_i, pos_pix_j;
  int i;
  int** pix;
  pix = malloc(sizeof(int*) * rag->height*rag->width);
  for (i=0; i < 3; i++) {
    pix[i] = malloc(sizeof(int));
  }

  int nb_pix = 0;
  Point position;

  image_debut(rag->image);
  /*route the image block by block*/
  for(pos_bloc_i=0; pos_bloc_i<height; pos_bloc_i+=rag->height){
    for(pos_bloc_j=0; pos_bloc_j<width; pos_bloc_j+=rag->width){
      /*route the bloc pixel by pixel*/
      for(pos_pix_i=pos_bloc_i; pos_pix_i<pos_bloc_i+rag->height; pos_pix_i++){
        for(pos_pix_j=pos_bloc_j; pos_pix_j<pos_bloc_j+rag->width; pos_pix_j++){
          COORDX(position) = pos_pix_i;
          COORDY(position) = pos_pix_j;
          image_move_to(rag->image, &position);
          pix[nb_pix] = image_lire_pixel(rag->image);
          nb_pix++;
        }
      }

      /*Convert the block into a region*/
      reg = createRegion(pix, nb_pix);
      addRegion(list, reg);

      for(i=0; i<nb_pix; i++){
        pix[i][0] = 0;
        pix[i][1] = 0;
        pix[i][2] = 0;
      }
      nb_pix = 0;
    }
  }

  return list;

}
