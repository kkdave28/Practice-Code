#include <bits/stdc++.h>

int Q = 16;
int N = 12;
int x = 5;


int main()
{
    for(int y = 0; y< Q; y++)
    {
        std::cout<<y<<"     "<<(unsigned long long int)pow(x,y)%N<<std::endl;
    }
    return EXIT_SUCCESS;
}