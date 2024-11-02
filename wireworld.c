/*
 * FILE: wireworld.c
 * AUTHOR: Rivin Pathirage
 * UNIT: Unix and C Programming
 * PURPOSE: Implenting the simulation
 * Referrences:
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "newSleep.h"
#include "color.h"
#include "header.h"
#include "terminal.h"
#define MAX_LENGTH 50

int main(int argc, char *argv[])
{
	char filename[MAX_LENGTH];
	int iter;
	float sec;
	int count;
	int mapRow;
	int mapCol;
	int row;
	int col;
	int **mapArray;
	FILE* f;
	int nRead;
	int i;
	int j;
	int x;
	int y;


	count = 1;

	if (argc < 4)
	{
		printf("There should be 4 com,and line arguments\n");
	}
	else
	{

		strcpy(filename, argv[1]);
		iter = atoi(argv[2]);
		sec = atof(argv[3]);

		printf("arg count is %d and filename is %s \n", argc, filename);

		printf("iterations %d  seconds for sleep %f\n", iter, sec);

		/*read file*/

		f = fopen(filename, "r");

       		 if (f == NULL)
       		 {
               		 printf("Error: could not open file \n");

       		 }
        	else
        	{


               		 do
               		 {
                       		 if (count == 1)
                       		 {

                               		 nRead = fscanf(f, "%d %d", &mapRow, &mapCol);
                               		 count++;
                               		 printf("%d %d\n", mapRow, mapCol);


					 /*mallocing the mapArrays*/
            				mapArray = (int**)malloc(mapRow * sizeof(int*));

            				for (i = 0; i < mapRow; i++)
            				{
                				mapArray[i] = (int*)malloc(mapCol * sizeof(int));
           				}


            				for (i = 0; i < mapRow; i++)
    					{
        					for (j = 0; j < mapCol; j++)
        					{
                					mapArray[i][j] = 0;
        					}
    					}

                       		 }
                       		 else
                       		 {
                               		 


					 for (int row = 0; row < mapRow; row++) 
					 {
       						 nRead = fscanf(f, "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d",
						 &mapArray[row][0], &mapArray[row][1],&mapArray[row][2], &mapArray[row][3],&mapArray[row][4], &mapArray[row][5],&mapArray[row][6], &mapArray[row][7]
						 ,&mapArray[row][8], &mapArray[row][9],&mapArray[row][10], &mapArray[row][11],&mapArray[row][12], &mapArray[row][13],&mapArray[row][14], &mapArray[row][15]
						,&mapArray[row][16], &mapArray[row][17],&mapArray[row][18], &mapArray[row][19],&mapArray[row][20], &mapArray[row][21],&mapArray[row][22], &mapArray[row][23]
						,&mapArray[row][24], &mapArray[row][25],&mapArray[row][26], &mapArray[row][27],&mapArray[row][28], &mapArray[row][29],&mapArray[row][30], &mapArray[row][31]
					,&mapArray[row][32], &mapArray[row][33],&mapArray[row][34], &mapArray[row][35],&mapArray[row][36], &mapArray[row][37],&mapArray[row][38], &mapArray[row][39]);
   					 }

                               		 

                               		
                       		 }
               		 } while (nRead >= 0);

			 fclose(f);

			 /*Print the mapArray*/
			 for (i = 0; i < mapRow; i++)
   			 {
       				 for (j = 0; j < mapCol; j++)
       				 {
               				printf("%d",mapArray[i][j]);


       				 }
       				 printf("\n");
    			}


			 /*Print sim*/
			 displayMap(mapArray, mapRow, mapCol);


			 /*Moving the simulation*/

			 for (i = 0; i < iter; i++ )
			 {

				 system("clear");

				 displayMap(mapArray, mapRow, mapCol);


				 /*trail movement*/
				 for (x = 0; x < mapRow; x++)
				 {
					 for (y = 0; y < mapCol; y++)
					 {
						 if (mapArray[x][y] == 2)
						 {
							 mapArray[x][y] = 5;
						 }
					 }
				 }

				 /*change e head*/
				 eHeadMove(mapArray, mapRow, mapCol);

				 for (x = 0; x < mapRow; x++)
                                 {
                                         for (y = 0; y < mapCol; y++)
                                         {
                                                 if (mapArray[x][y] == 5)
                                                 {
                                                         mapArray[x][y] = 3;
                                                 }
                                         }
                                 } 

				/* system("clear");
				 displayMap(mapArray, mapRow, mapCol);*/

				 printf("%d\n", i);

				 newSleep(sec);
			 }



			 /*Put the freeing of the mapArray here*/
            		for (i = 0; i <mapRow; i++)
            		{
                		free(mapArray[i]);
           		}
           	 	free(mapArray);

		}
	}

		return 0;
}
