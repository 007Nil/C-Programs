#include<stdio.h>


int height = 20;
int width  = 60;

int snake_X, snake_Y;
int fruit_X , fruit_y; 


void game_setup (){
 
}


void make_game_board(){
 int i,j;
 for (i = 0; i <= height; i++){
  for (j = 0; j <= width; j++){
	  if ( i ==0 || i == height || j == 0 || j == width ){
       	   printf("#");
	  }else{
           printf(" ");
	  }
  }

  printf("\n");

 }

}

int main(){
 
 make_game_board();
 return 0;
}
