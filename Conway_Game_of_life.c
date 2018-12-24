// USING POINTERS //
/*
 * Conway_Game_of_Life.c
 *
 *  Created on: November 03, 2018
 *      Author: Sanchit
 */

#include<stdio.h>

int Size_of_row, Size_of_column;
int row_Index, column_Index, Number_of_generations;
int Number_of_Live_Cells;

void Populations_Contorller(int **pointer, int Size_of_row, int Size_of_column); // declare the function
int main()
    {

printf("           Welcome to the Game of Life:\n ");
printf("................................................");
printf("\n");

printf("Please Enter the Size of the Array:\n");
	printf("Enter number of Rows: ");
	scanf("%d", &Size_of_row);
 	printf("Enter number of columns: ");
 	scanf("%d", &Size_of_column);

    // Creating a 2D array with 10 rows and 10 columns
   int Array_Size[Size_of_row][Size_of_column];

   // Allocating the memory by using the malloc function
int **pointer = malloc(Size_of_row * sizeof(int*));
  for (int i = 0; i < Size_of_row; i++) {
            pointer[i] = malloc(Size_of_column * sizeof(int));
    }

  //Scan through each row and column and put 0 at each index in the array
   for(int s = 0; s<Size_of_row; s++){
	   for(int a = 0; a<Size_of_column; a++){
		   pointer[s][a] = 0;
	   }
   }

   printf("Enter the number of Living Cells: ");
   scanf("%d", &Number_of_Live_Cells);

   for(int start = 0; start<Number_of_Live_Cells; start++){
       
       printf("Please Enter the Co-ordinates for the Live Cell: \n"); // Print the message
	   printf("Enter Row Index: "); // Print the message for input row number
	   scanf("%d", &row_Index);  // read and store the value
	   printf("Enter column Index: "); //Print the message for input column index
	   scanf("%d", &column_Index);  // read and store the value
	   pointer[row_Index][column_Index] = 1; //Initializing the array from the 1

   }
        // Displaying the grid
        printf("\n");  
        printf("Original State: \n");     //Prints the initial state of CGOL
        for (int l = 0; l < Size_of_row; l++)  // start the loop to read rows
        {
            for (int m = 0; m < Size_of_column; m++)  // start the loop to read columns
            {
                if (pointer[l][m] == 0)  // check condtion fpr the live and dead cell
                    printf("0");        //Prints the '0' if the cell is dead
                else
                    printf("1");        //Prints the '1' if the cell is alive
            }
           printf("\n");
        }
       printf("\n");
        Populations_Contorller(pointer, Size_of_row, Size_of_column); // Calling the function Populations_Contorller
    }

 //Implement the method for the control the rules
    void Populations_Contorller(int **pointer, int Size_of_row, int Size_of_column)        
    {

  int start = 1;

 // Allocating the memory by using the malloc function
    int **Update_Array = malloc(Size_of_row * sizeof(int*));
        for (int i = 0; i < Size_of_row; i++) {
            Update_Array[i] = malloc(Size_of_column * sizeof(int));
    }
    
    printf("Enter the Number of generations: ");  //prints the message to enter the generations
    scanf("%d", &Number_of_generations);  //read and store teh value 

    for(int initiate = 0; initiate<Number_of_generations; initiate++){        //start the loop for the Number_of_generations
        for (int row_initiate = 0; row_initiate < Size_of_row ; row_initiate++)     // initiate the loop through each row
        {
            for (int cellIterate = 0; cellIterate < Size_of_column ; cellIterate++) // initiate loop through each columns
            {

int neighbours = 0;            //Initializing the count as 0 for the neighbours

// code to check the eight neighbours of the liveCell

 // condition to check if the cell is in the top row
if(row_initiate == 0){                     
    for (int i = 0; i <= 1; i++) // scan the whole row
      for (int j = -1; j <= 1; j++)   // scan the whole columns
   
                 // update the value of the neighbours cell 
            neighbours += pointer[row_initiate + i][cellIterate + j]; 
            neighbours -= pointer[row_initiate][cellIterate];}

// Condition to check if the cell is at top-left
else if(row_initiate == 0 && cellIterate == 0){      
    for (int i = 0; i <= 1; i++) // scan the whole row
        for (int j = 0; j <= 1; j++) //scan the whole columns
        
        //update the value of the neighbours cell
            neighbours += pointer[row_initiate + i][cellIterate + j];   
            neighbours -= pointer[row_initiate][cellIterate];  }

 // Condition to check if the cell is at bottom-left
else if(cellIterate == 0 && row_initiate == Size_of_row - 1){      
    for (int i = -1; i < 1; i++)  // scan the whole row          
        for (int j = 0; j <= 1; j++)  // scan the whole columns

        // update the value of the neighbours cell
            neighbours += pointer[row_initiate + i][cellIterate + j];   
            neighbours -= pointer[row_initiate][cellIterate]; }

// Condition to check if the cell is at the bottom
else if(row_initiate == Size_of_row - 1){                 
    for (int i = -1; i < 1; i++)  // scan the whole row
        for (int j = -1; j <= 1; j++) // scan the whole columns

        // update the value of neighbours cell
            neighbours += pointer[row_initiate + i][cellIterate + j];   
            neighbours -= pointer[row_initiate][cellIterate]; }

 // Condition to check if the cell is at the bottom-right
else if(row_initiate == Size_of_row -1 && cellIterate == Size_of_column -1){    
    for (int i = -1; i < 1; i++)   // scan the whole row     
        for (int j = -1; j < 1; j++)    // scan the whole columns

        // update the value of the neighbours cell
            neighbours += pointer[row_initiate + i][cellIterate + j]; 
            neighbours -= pointer[row_initiate][cellIterate];   }

// Condition to check if the cell is in the last columns
else if(cellIterate == Size_of_column -1 ){                  
    for (int i = -1; i <= 1; i++)  // scan the whole row
        for (int j = -1; j < 1; j++)  //scan the whole columns
        
        // update the value of the neighbours cell
            neighbours += pointer[row_initiate + i][cellIterate + j];  
            neighbours -= pointer[row_initiate][cellIterate];   }
 
 // Condition to check if the cell at the top-right
 else if(row_initiate == 0 && cellIterate == Size_of_column - 1){      
    for (int i = 0; i <= 1; i++) // scan the whole row         
        for (int j = -1; j < 1; j++)    // scan the whole columns
         
         // update the value of the neighbours cell
            neighbours += pointer[row_initiate + i][cellIterate + j];   
            neighbours -= pointer[row_initiate][cellIterate];   }

// Condition to check if the cell is in the first column
else if(cellIterate == 0){                
    for (int i = -1; i <= 1; i++) // scan thw whole roww
        for (int j = 0; j <= 1; j++)    // scan the whole column
        
         // update the value of the neighbours
            neighbours += pointer[row_initiate + i][cellIterate + j];  
            neighbours -= pointer[row_initiate][cellIterate];    }

  //Loop through every row near the alive cell
else {
for (int i = -1; i <= 1; i++)          
for (int j = -1; j <= 1; j++)       
neighbours += pointer[row_initiate + i][cellIterate + j];   

neighbours -= pointer[row_initiate][cellIterate];       

}
                // applying all the four rules for the Conway_Game_of_Life
                
                if ((pointer[row_initiate][cellIterate] == 1) && (neighbours < 2))  // Implementing first rule
                    Update_Array[row_initiate][cellIterate] = 0;            // accordingly upda the arra value

                // Cell dies due to over population
                else if ((pointer[cellIterate] == 1) && (neighbours > 3)) // Implementingthe over population rule
                    Update_Array[row_initiate][cellIterate] = 0;  // accordingly upda the arra value

                // A new cell is born
                else if ((pointer[row_initiate][cellIterate] == 0) && (neighbours == 3)) // Implementing the the reule for the new cell
                    Update_Array[row_initiate][cellIterate] = 1; // accordingly upda the arra value

                // Remains the same
                else
                    Update_Array[row_initiate][cellIterate] = pointer[row_initiate][cellIterate];  //either remains same the array
            }
        }

        for(int r = 0; r<Size_of_row ; r++){  // start the loop to read the rowsw
        	for(int w = 0; w<Size_of_column; w++){  // start the loop to read the columns
        		pointer[r][w] = Update_Array[r][w];  // update the new array from the previous one
        	}
        }

        printf("Next Generation: \n", start);          //Prints the First Generation of CGOL after applying the first rule
        start++;
        for (int i = 0; i < Size_of_row; i++)  // start to read the row
        {
            for (int j = 0; j < Size_of_column; j++)  // start to read the columns
            {
                if (pointer[i][j] == 0)  // use condtion to check where to print 0 and 1
                   printf("0");        //Prints "0" for every dead cell
                else
                    printf("1");       //Prints "1" for every alive cell
            }
            printf("\n");
        }
        printf("\n");
    }
    }

