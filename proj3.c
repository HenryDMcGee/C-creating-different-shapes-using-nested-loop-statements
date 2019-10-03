#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Global variables for loop indicies 
int i, j, y, c, lengthd, lengthe; 
char r,t,h,o,p;

//Get a shape from a user, and return the shape if it is valid;
// otherwise, print an error message and terminate the program
char getShapeFromUser(void);

//Get a length from a user, and return the length if it is valid;
//  otherwise, print an error message and terminate the program
int getLengthFromUser(void);

//Get a height from a user, and return the height if it is valid;
//  otherwise, print an error message and terminate the program
int getHeightFromUser(void);

bool isShapeValid(char shape);

bool isLengthValid(int length);

bool isHeightValid(int height);

void drawRectangle(int length, int height);

void drawTriangle(int length);

void drawHexagon(int length);

void drawOctagon(int length);

void drawPentagon(int length);

//Do not modify the main function
int main(void){  
  char shape = getShapeFromUser();
  int length = getLengthFromUser();
  int height;

  if(shape == 'r'){
    height = getHeightFromUser();
    printf("Below is a %d by %d rectangle of *\n", length, height);
    drawRectangle(length, height);
  }
  else if(shape == 't'){
    printf("Below is a triangle with two side lengths of %d *\n", length);
    drawTriangle(length);
  }
  else if(shape == 'h'){
    printf("Below is a hexagon with side lengths of %d *\n", length);
    drawHexagon(length);
  }
  else if(shape == 'o'){
    printf("Below is an octagon with side lengths of %d *\n", length);
    drawOctagon(length);
  }
  else if(shape == 'p'){
    printf("Below is a pentagon with 4 side lengths of %d *\n", length);
    drawPentagon(length);
  }
  return 0;
}

//Implement function prototypes below

char getShapeFromUser(void){
  char shape = '\0';
  printf("Enter a shape: r t h o p\n");
  scanf("%c", &shape);
  if( !isShapeValid(shape) ){
    printf("Invalid shape\nGoodbye!\n");
    exit(0);
  }
  return shape;
}

bool isShapeValid(char shape){				//Prototype for Shape Validation
	if(shape=='r'||shape=='t'||shape=='h'||shape=='o'||shape=='p')
	{
		return true;
	}
	else 
	{
		return false;
	}
}

int getLengthFromUser(void){
  int length = 0;
  printf("Enter a length\n");
  scanf("%d", &length);  		
    if( !isLengthValid(length) ){
    printf("Length must be greater than 1\nGoodbye!\n");
    exit(0);    
  }
  return length;
}

bool isLengthValid(int length){   			//Prototype for Length Validation
if(length>1)
{
	return true;
}					
else
{
	return false;
}
}

int getHeightFromUser(void){
  int height = 0;
  printf("Enter a height\n");
  scanf("%d", &height);
  if( !isHeightValid(height) ){
    printf("Height must be greater than 1\nGoodbye!\n");
    exit(0);    
  }    
  return height;
}

 bool isHeightValid(int height){		//Prototype for Height Validation
if(height>1)
{
	return true;
}
else
{
	return false;
}
}

//rectangle
void drawRectangle(int length, int height)
{
for(y=1; y<=height; y++)								//assigns the columns based on the user inputted height. 
{
	for(c=1; c<=length; c++)							//assigns the row based on the user inputted length. 
			printf("*");
{
			printf("\n");			
}
}
}

//triangle
void drawTriangle(int length)
{		
for(y=1, lengthd=length, lengthe=length; y<=length; y++, lengthd--, lengthe++)
{
	for(c=1; c<=length*3; c++)			
	{
			if(c>=lengthd && c<=lengthe)					/*This if else statement creates the spacing for a hexagon. c=row, lengthd=front spacing, lengthe=rear spacing. row 												must be greater than lengthd and less than lengthe to print *. otherwise a space will be printed.*/
			{
					printf("*");
			}
			else
					printf(" ");
	}
			printf("\n");
}
}

void drawHexagon(int length)
{	
			
for(y=1, lengthd=length, lengthe=(length*2)-1; y<length; y++, lengthd--, lengthe++)
{
	for(c=0; c<3*length; c++)			
	{
			if(c>=lengthd && c<=lengthe)					/*This if else statement creates the spacing for a hexagon. c=row, lengthd=front spacing, lengthe=rear spacing. row 												must be greater than lengthd and less than lengthe to print *. otherwise a space will be printed.*/
			{
					printf("*");
			}
			else
					printf(" ");
	}
			printf("\n");

}




for(y=0, lengthd=1, lengthe=3*length-2; y<length; y++, lengthd++, lengthe--)
{
	for(c=0; c<3*length; c++)
	{
		if(c>=lengthd && c<=lengthe)
				printf("*");
		else
				printf(" ");
	}	
		printf("\n");
}
}
void drawOctagon(int length)
{
for(y=1, lengthd=length, lengthe=(length*2)-1; y<length; y++, lengthd--, lengthe++)
{
	for(c=0; c<3*length; c++)
	{
		if(c>=lengthd && c<=lengthe)
		{
				printf("*");
		}
		else
				printf(" ");
	}				
		printf("\n");
}

for(y=1; y<=length-1; y++)					/*A rectangle was inserted into a hexagon to make an octagon. The printf(" "); creates spacing before the rectangle to center it while 									(length *3)-2 centers the octagon and removes extra rows.*/
{

	printf(" ");

{
	for(c=1; c<=(length*3)-2; c++)
			printf("*");
{
			printf("\n");			
}
}
}

for(y=0, lengthd=1, lengthe=3*length-2; y<length; y++, lengthd++, lengthe--)
{
	for(c=0; c<3*length; c++)
	{
		if(c>=lengthd && c<=lengthe)
				printf("*");
		else
				printf(" ");
	}
		printf("\n");
}
}

void drawPentagon(int length)
{

//triangle
for(y=1, lengthd=length, lengthe=length; y<=length; y++, lengthd--, lengthe++)
{
	for(c=1; c<=length*3; c++)			
	{
			if(c>=lengthd && c<=lengthe)					/*This if else statement creates the spacing for a hexagon. c=row, lengthd=front spacing, lengthe=rear spacing. row 												must be greater than lengthd and less than lengthe to print *. otherwise a space will be printed.*/
			{
					printf("*");
			}
			else
					printf(" ");
	}
			printf("\n");
}


// retangle
for(y=0; y<=length-2; y++)								//assigns the columns based on the user inputted height. 
{
	for(c=0; c<=2*length-2; c++)							//assigns the row based on the user inputted length. 
			printf("*");
{
			printf("\n");			
}
}
}

