#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define KNRM  "\x1B[0m"
#define KGRN  "\x1B[32m"
#define KBRW  "\e[38;5;130m"

void    my_putchar(char c) {
    
    write(1, &c, 1);
}

void my_putstr(char *str) {
  
  while (*str != '\0') {
        my_putchar(*str);
        *str++;
    }
}

int my_getnbr(char *char_nb)
{
  int sign = 1;
  int i = 0;
  int digit = 0;
  unsigned long int number = 0;
  int result;
  int max_int = 2147483647;

  while ((*char_nb != '\0' && *char_nb < '0') || *char_nb > '9') {
    if (*char_nb == '+') {
      sign = sign; 
    } else if (*char_nb == '-') {
      sign = -sign;
    }
    char_nb  = char_nb + 1;
  }
  while (*char_nb >= '0' && *char_nb <= '9') {
    digit = *char_nb - 48;
    number = number * 10 + digit;
    char_nb = char_nb + 1;
  }
  if ((number > 2147483647 && sign == 1) || (number > 2147483648 && sign == -1)) {
    return(0);
  } else {
    result = number;
  }

  return(result * sign);
}

int is_number(char *str)
{
  int i = 0;
  int result = 0;

  while (str[i] != '\0') {
    if (str[i] < '0' || str[i] > '9') {
      result = 1;
    }
    i = i + 1;
  }
  return(result);
}
void my_trunk(int size, int star)
{
  int tr_len = 0;
  int tr_wid = 0;
  int space = 0;
  int mid = star/2;
  while (tr_len < size)
    {
      while (space < mid-(size/2))
	{
	  printf("%c", 32);
	  space++;
	}           
      while (tr_wid < size)
	{
	  //my_putstr(KBRW); 
	  printf("|");
	  //my_putchar('|');
	  //my_putstr(KNRM); 
	  tr_wid++;
	}
      printf("\n");
      space = 0;
      tr_wid = 0;
      tr_len++;
    }
}

int max_stars (int size)
{
  int width = 1;
   int length = 1;
   int height = 4;
   int mid = (size*7)/2;
   int base = size*7;
 int space = 0;
 int star = 0;
 int i = 0;
 int j = 0;
  int offset = 4;
 
   if (size == 0)
     {
       printf("[...]");
     }
   else
     {
       while (i < size)
         {
           while (j < height)//Pour cha
  {
              while (space < mid)
                 {
		   // printf("%c", 32);
                  space++;
                }
              star = 0;
             while (star < width)
               {
                 //printf("*");
                 star++;
                }
             width = width + 2;
             //printf("\n");
              space = 0;
             mid = mid -1;
              j++;
         }
          j = 0;
          height++;
          i++;
          if (height%2 == 0 /*&& height != 4*/)
           {
             width = width - offset;
mid = mid + (offset/2)/*+2*/;
             offset = offset +2;
           }
         else
           {
              width = width - offset;
             mid = mid + (offset/2);
           }
       }

     }
   return (star);
}

/*int nb_space(int star)
{
  nb_space = star/2;
    }
*/
void sapin (int size)
{
  int width = 1;
  int length = 1;
  int height = 4;
  int mid = max_stars(size)/2; /*(size*7)/2*/;
  int base = max_stars(size) /*size*7*/;
int space = 0;
int star = 0;
int i = 0;
int j = 0;
 int offset = 4;

  if (size == 0)
    {
      printf("[...]");
    }
  else 
    {
      while (i < size)
	{
	  while (j < height)//Pour chaque bloc
	    {
	       while (space < mid)
		 {
		   printf("%c", 32);
		  space++;
		}
	       star = 0;
	      while (star < width)  
		{
		  printf("*");
		  star++;
		}
       	      width = width + 2;
	      printf("\n");
	      space = 0;
	      mid = mid -1;
	      j++;
	    }
	  j = 0;
	  height++;
	  i++; 
	  if (height%2 == 0 /*&& height != 4*/)
	    {
	      width = width - offset;
	      mid = mid + (offset/2)/*+2*/;
	      offset = offset +2;
	    }
	  else
	    {
	      width = width - offset;
	      mid = mid + (offset/2);
	    }
	}
      my_trunk(size, star);
    }
}  
       


int main(int argc, char *argv[])
{
  /*if (is_number(argv[1]) == 0)
    {
      int size = my_getnbr(argv[1]);
      sapin(size);
    }
    else
      {
	printf("Error");
      }
      sapin(2);*/
  sapin(10);
  //max_stars(5);
  return 0;
}
