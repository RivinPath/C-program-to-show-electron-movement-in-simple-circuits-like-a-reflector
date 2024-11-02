/*
 * FILE: simulation.c
 * AUTHOR: Rivin Pathirage
 * UNIT: Unix and C Programming
 * PURPOSE: Implenting the methods wireworld
 * Referrences:
 */

#include <stdio.h>
#include "color.h"
#include "header.h"
#include <stdlib.h>


/*
 * METHOD: displayMap
 * PURPOSE: displaying the output
 * IMPORTS: **mapArray, mapRow, mapCol
 * EXPORTS:
 */
void displayMap(int **mapArray, int mapRow, int mapCol)
{
    int j;
    int p;
    for (j = 0; j < mapRow; j++)
    {
        for (p = 0; p < mapCol; p++)
        {
            if (mapArray[j][p] == 0)
            {
                setBackground("black");
                printf("  ");
                setBackground("reset");
            }
            else if (mapArray[j][p] == 1)
            {
                setBackground("blue");
                printf("  ");
                setBackground("reset");
            }
            else if (mapArray[j][p] == 2)
            {
                setBackground("red");
                printf("  ");
                setBackground("reset");
            }
	    else if (mapArray[j][p] == 3)
            {
                setBackground("yellow");
                printf("  ");
                setBackground("reset");
            }


        }
        printf("\n");
    }
}

/*
 * METHOD: eHeadMove
 * PURPOSE: updating the simuation
 * IMPORTS: **mapArray, mapRow, mapCol
 * EXPORTS:
 */
void eHeadMove(int **mapArray, int mapRow, int mapCol)
{
	int i;
	int j;
	int near = 0;
	int **trailArray;


	/*mallocing the trailArrays*/
        trailArray = (int**)malloc(mapRow * sizeof(int*));

        for (i = 0; i < mapRow; i++)
        {
               trailArray[i] = (int*)malloc(mapCol * sizeof(int));
        }


	for (i = 0; i < mapRow; i++)
        {
               for (j = 0; j < mapCol; j++)
	       {
                         trailArray[i][j] = 0;
               }
        }



	for (i = 0; i < mapRow; i++)
	{
		for (j = 0; j < mapCol; j++)
		{

			near = 0;

			/*if (mapArray[i][j] == 2)
			{
				mapArray[i][j] = 4;
			}*/

			if (mapArray[i][j] == 3)
			{
				/*NW*/
				if (mapArray[i-1][j-1] == 1)
				{
					/*near = 1;*/
					near++;

					if (near <= 2)
					{
						trailArray[i-1][j-1] = 2;
					}
				}

				/*N*/
				if (mapArray[i-1][j] == 1)
				{
					near++;

					if (near <= 2)
                                        {
                                               trailArray[i-1][j] = 2;
                                        }
				}

				/*NE*/
				if (mapArray[i-1][j+1] == 1)
				{
					near++;

					if (near <= 2)
                                        {
                                                trailArray[i-1][j+1] = 2;
                                        }
				}

				/*E*/
				if (mapArray[i][j+1] == 1)
                                {
                                        near++;

					if (near <= 2)
                                        {
                                                trailArray[i][j+1] = 2;
                                        }
                                }

				/*SE*/
				if (mapArray[i+1][j+1] == 1)
                                {
                                        near++;

					if (near <= 2)
                                        {
                                                trailArray[i+1][j+1] = 2;
                                        }
                                }

				/*S*/
				if (mapArray[i+1][j] == 1)
                                {
                                        near++;

					if (near <= 2)
                                        {
                                                trailArray[i+1][j] = 2;
                                        }
                                }

				/*SW*/
				if (mapArray[i+1][j-1] == 1)
                                {
                                        near++;

					if (near <= 2)
                                        {
                                                trailArray[i+1][j-1] = 2;
                                        }
                                }

				/*W*/
				if (mapArray[i][j-1] == 1)
                                {
                                        near++;

					if (near <= 2)
                                        {
                                                trailArray[i][j-1] = 2;
                                        }
                                }



				/*Moving electron head*/
				if (near <= 2 && near != 0/* && (near == 1 || near == 2)*/)
				{
					mapArray[i][j] = 4;
				}

				/*if (mapArray[i][j] == 4)
                        	{
                                	mapArray[i][j] = 3;
                        	}*/

			}

			/*if (mapArray[i][j] == 4)
                        {
                                mapArray[i][j] = 3;
                        }*/
		}
	}

	for (i = 0; i < mapRow; i++)
        {
                 for (j = 0; j < mapCol; j++)
                 {
                        if (mapArray[i][j] == 1)
                        {
                                  mapArray[i][j] = 2;
                        }
                 }
        }
	
	for (i = 0; i < mapRow; i++)
	{
                 for (j = 0; j < mapCol; j++)
                 {
                        if (mapArray[i][j] == 4)
                        {
                                  mapArray[i][j] = 1;
                        }
                 }
        }

	for (i = 0; i < mapRow; i++)
        {
                 for (j = 0; j < mapCol; j++)
                 {
                        if (trailArray[i][j] == 2)
                        {
                                  mapArray[i][j] = 2;
                        }
                 }
        }

	/*Put the freeing of the trailArray here*/
        for (i = 0; i <mapRow; i++)
        {
                free(trailArray[i]);
        }
        free(trailArray);

	/*return PmapArray;*/
}

