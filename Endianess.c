#include <stdio.h>
void show_mem_rep(char *start, int n)  
{ 
    int i; 
    for (i = 0; i < n; i++) 
         printf(" %.2x", start[i]); 
    printf("\n"); 
} 
int change_endian(int x)
{
    return ((x>>24 & 0xFF)| (x<<24 & 0xFF000000)| (x>>8 & 0x0000FF00)| (x<<8 & 0x00FF0000));
}
int main() 
{ 
   int i = 0x01234567; 
   show_mem_rep((char *)&i, sizeof(i)); 
   i = change_endian(i);
   show_mem_rep((char *)&i, sizeof(i)); 
   i = change_endian(i);
   show_mem_rep((char *)&i, sizeof(i)); 
   //getchar(); 
   return 0; 
} 