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
  image image; /** A reference to the original image structure */
  int height, width; /** The original width and height of each blocks */
  double partitionError; /** The partition error of the Rag */
  int dimension; /** image dimension (1=Greyscale, 3=RGB) */
  LinkedList blocks; /** The list of all original blocks */
};

/**
 * initialize the original list of blocks
 * @param the Rag that will contain the list of blocks
 */
static void initRegion(Rag rag);
/**
 * initialize the neighbours of all original regions
 * @param the Rag containing the regions you want initialize their neighbours
 */
static void initNeighbours(Rag rag);


Rag createRag(image img,int height,int width) {
  Rag rag = malloc(sizeof(struct rag));
  rag->image = img;
  if(image_give_largeur(img)%width == 0 && image_give_hauteur(img)%height == 0){
    rag->height = height;
    rag->width = width;
    rag->dimension = image_give_dim(img);
    initRegion(rag);
    initNeighbours(rag);
    return rag;
  }else{
    printf("Block size impossible\n");
    return NULL;
  }
}

image getRegionImage(Rag rag) {
  image img = FAIRE_image();
  LinkedList list = getBlocks(rag);
  Iterator iter = getIterator(list);
  Region region = NULL;
  rgb color;
  Point position;
  int rgb[3];
  int pos_x, pos_y, index, line;
  int img_height = image_give_hauteur(rag->image);
  int img_width = image_give_largeur(rag->image);
  int nb_bloc_width = img_width/rag->width;

  image_initialize(img, image_give_dim(rag->image), img_width ,img_height);
  image_debut(img);
  index = 0;
  line = 0;

  /*Route all regions of the RAG*/
  while(moveNext(iter)) {
    region = getElement(iter);
    color = getColor(region);
    rgb[0] = color.red;
    rgb[1] = color.green;
    rgb[2] = color.blue;
    /*Set the same color to all the pixels in the block*/
    for (pos_y = line*rag->height; pos_y < (line+1)*rag->height; pos_y++) {
      for (pos_x = (index%nb_bloc_width)*rag->width; pos_x < ((index%nb_bloc_width)+1)*rag->width; pos_x++) {
        COORDX(position) = pos_x;
        COORDY(position) = pos_y;
        image_move_to(img, &position);
        image_ecrire_pixel(img, rgb);
      }
    }

    index++;
    if(index%nb_bloc_width == 0){
      line++;
    }
  }

  return img;
}

int getHeight(Rag rag) {
  return rag->height;
}

int getWidth(Rag rag) {
  return rag->width;
}

int getDimension(Rag rag) {
  return rag->dimension;
}

LinkedList getBlocks(Rag rag) {
 return rag->blocks;
}

double getPartitionError(Rag rag){
  return rag->partitionError;
}

static void initNeighbours(Rag rag) {
  Region region = NULL;
  Region neighbourg = NULL;
  LinkedList list = getBlocks(rag);
  Iterator iter = getIterator(list);
  int index = 0;
  int width = image_give_largeur(rag->image)/rag->width;
  int height = image_give_hauteur(rag->image)/rag->height;

  /*Route all regions of the RAG*/
  while(moveNext(iter)) {
    region = getElement(iter);
    /*right neighbourg*/
    if((index+1)%width != 0){
      neighbourg = get(list, index+1);
      addNeighbourg(region, neighbourg);
    }
    /* neighbourg from bellow*/
    if(index+width < width*height){
      neighbourg = get(list, index+width);
      addNeighbourg(region, neighbourg);
    }
    index++;
  }
}

static void initRegion(Rag rag) {
  LinkedList list = createList();
  Region reg = NULL;
  int height = image_give_hauteur(rag->image);
  int width = image_give_largeur(rag->image);
  int pos_bloc_x, pos_bloc_y;
  int pos_pix_x, pos_pix_y;
  int** pix;
  int num_pix = 0;
  Point position;
  double partitionError = 0.0;

  /*initialize the list of pixels included in one bloc*/
  pix = malloc(sizeof(int*) * rag->height*rag->width);

  image_debut(rag->image);
  /*route the image block by block*/
  for(pos_bloc_y=0; pos_bloc_y<height; pos_bloc_y+=rag->height){
    for(pos_bloc_x=0; pos_bloc_x<width; pos_bloc_x+=rag->width){
      /*route the bloc pixel by pixel*/
      for(pos_pix_y=pos_bloc_y; pos_pix_y<pos_bloc_y+rag->height; pos_pix_y++){
        for(pos_pix_x=pos_bloc_x; pos_pix_x<pos_bloc_x+rag->width; pos_pix_x++){
          COORDX(position) = pos_pix_x;
          COORDY(position) = pos_pix_y;
          image_move_to(rag->image, &position);
          pix[num_pix] = malloc(sizeof(int)*3);
          pix[num_pix][0] = image_lire_pixel(rag->image)[0];
          /*If RGB get the 3 colors, else, convert the color into grey*/
          if(rag->dimension == 3){
            pix[num_pix][1] = image_lire_pixel(rag->image)[1];
            pix[num_pix][2] = image_lire_pixel(rag->image)[2];
          }else{
            pix[num_pix][1] = pix[num_pix][0];
            pix[num_pix][2] = pix[num_pix][0];
          }
          num_pix++;
        }
      }
      /*Convert the block into a region*/
      reg = createRegion(pix, num_pix);
      addRegion(list, reg);
      num_pix = 0;
      partitionError += getQuadraticError(reg);
    }
  }

  rag->partitionError = partitionError;
  rag->blocks = list;

}
