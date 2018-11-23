#include <bits/stdc++.h>

int unique(std::vector<int> arr)
{
    int ret = 0;
    for (auto E : arr)
        ret ^= E;
    return ret;
}
bool oppposite_signs(int a, int b)
{
    return ((a ^ b) < 0);
}

unsigned int revese_bits(unsigned int x)
{
    unsigned int ret = 0, temp = 0;;
    for(unsigned int i= 0; i< sizeof(int)*8; i++)
    {
        temp = x>>(sizeof(int)*8 - 1- i) & 0x01;
        ret |= (temp<<i);
    }
    return ret;
}
unsigned int rev_bits(unsigned int x)
{
    unsigned int ret = 0;
    while(x >0)
    {
        ret << = 1;
        if(x&1 == 1)
        {
            ret ^=1;
        }
        x >>=1;
    }
}
int rotate_left(int x, int n)
{
    return (x<<n) | (x>> (sizeof(int)*8 - n));
}
int rotate_right(int x, int n)
{
    return (x>>n)| (x<< (sizeof(int)*8 - n));
}
int bitwise_add_one(int x)
{
    int m = 1;
    while (x & m)
    {
        x ^= m;
        m <<= 1;
    }
    return x ^ m;
}
int unset_right_bit(int x)
{
    int m = 1;
    while (!(x & m))
        m <<= 1;
    m = ~m;
    x &= m;
    return x;
    //Alternate solution return x& (x-1);
}
int power_of_four(int x)
{
    int m = 1;
    int count = 0;
    while ((x & m) == 0)
    {
        count += 1;
        m <<= 1;
    }
    return (count % 2) == 0;
}
int power_of_two(int x)
{
    int m = 1, count = 0;
    while (x)
    {
        count += x & m;
        x >>= 1;
    }
    return count == 1;
}
int swap_without_temp(int a, int b)
{
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}
int XOR_ultra(int a, int b)
{
    return ((a | b) & (~(a & b)));
}
int count_each_bit(int x)
{
    if (x <= 0)
        return 0;
    return (x % 2 == 0 ? 0 : 1) + count_each_bit(x >> 1);
}
int count_set_bits(int x)
{
    int total = 0;
    for (int i = 1; i <= x; i++)
    {
        total += count_each_bit(i);
    }
    return total;
}
int modulo(int n, int d) // d is a power of 2... constraint: do not use modulo (%) or divisibility(/) operator...
{
    return n&(d-1);
}
std::string Dec_to_Hex(int x)
{
    int i = 0;
    char y = 48;
    std::map<int, char> lookup_table;
    for (; i < 10; i++, y++)
    {
        lookup_table[i] = y;
    }
    lookup_table[10] = 'A';
    lookup_table[11] = 'B';
    lookup_table[12] = 'C';
    lookup_table[13] = 'D';
    lookup_table[14] = 'E';
    lookup_table[15] = 'F';
    std::string ret = "";
    int bitmast = 0xF;
    for (int j = 0; j < sizeof(int) * 8; j += 4)
    {
        ret += std::string(1, lookup_table[(x >> j) & bitmast]);
    }
    std::reverse(ret.begin(), ret.end());
    return ("0x"+ret);
}
void show_mem_rep(char *start, int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf(" %.2x", start[i]);
    printf("\n");
}
int hex_to_dec(std::string x)
{
    int ret = 0;
    for (int i = 2; i < x.length(); i++)
    {
        switch (x[i])
        {
            case '0':
            {
                ret |= 0 << (32 - ((i - 2) * 4 + 4));
                break;
            }
            case '1':
            {
                ret |= 1 << (32 - ((i - 2) * 4 + 4));
                break;
            }
            case '2':
            {
                ret |= 2 << (32 - ((i - 2) * 4 + 4));
                break;
            }
            case '3':
            {
                ret |= 3 << (32 - ((i - 2) * 4 + 4));
                break;
            }
            case '4':
            {
                ret |= 4 << (32 - ((i - 2) * 4 + 4));
                break;
            }
            case '5':
            {
                ret |= 5 << (32 - ((i - 2) * 4 + 4));
                break;
            }
            case '6':
            {
                ret |= 6 << (32 - ((i - 2) * 4 + 4));
                break;
            }
            case '7':
            {
                ret |= 7 << (32 - ((i - 2) * 4 + 4));
                break;
            }
            case '8':
            {
                ret |= 8 << (32 - ((i - 2) * 4 + 4));
                break;
            }
            case '9':
            {
                ret |= 9 << (32 - ((i - 2) * 4 + 4));
                break;
            }
            case 'A':
            {
                ret |= 10 << (32 - ((i - 2) * 4 + 4));
                break;
            }
            case 'B':
            {
                ret |= 11 << (32 - ((i - 2) * 4 + 4));
                break;
            }
            case 'C':
            {
                ret |= 12 << (32 - ((i - 2) * 4 + 4));
                break;
            }
            case 'D':
            {
                ret |= 13 << (32 - ((i - 2) * 4 + 4));
                break;
            }
            case 'E':
            {
                ret |= 14 << (32 - ((i - 2) * 4 + 4));
                break;
            }
            case 'F':
            {
                ret |= 15 << (32 - ((i - 2) * 4 + 4));
                break;
            }
            default:
            {
                continue;
                break;
            }
        }
    }
    return ret;
}
unsigned int number_of_set_bits(unsigned int x)
{
    unsigned int ret = 0;
    for(int i=0; i< sizeof(int)*8; i++)
    {
        ret+= (x>>i)%2;
    }
    //return 0;
    return ret;
}
void prime_numbers_in_range(int n)
{
    bool prime = true;
    int j = 2;
    for(int i = 2; i<=n; i++)
    {
        for(; j<=i/2; j++)
        {
            if(i%j == 0)
            {
                prime = false;
                break;
            }
        }
        if(prime)
            std::cout<<i<<std::endl;
        prime = true;
        j=2;
    }
}
void print_rightmost_set_bit(int x)
{
    int max_pos = 0;
    for(int i=0; i< (sizeof(int)*8); i++)
    {
        if(x%2 == 1)
        {
            max_pos = i;
            break;
        }
        x>>=1;
    }
    std::cout<<max_pos+1<<std::endl;

}
int print_leftmost_set_bit(int x)
{
    int max_pos = 0;
    for(int i=0; i< (sizeof(int)*8); i++)
    {
        if(x%2 == 1 || x%2 == -1)
        {
            max_pos = i;
        }
        x>>=1;
    }
    //std::cout<<max_pos+1<<std::endl;
    return max_pos+1;
}
int main(int argc, char const *argv[])
{
    //int x =8;
    // std::vector<int> arr{12, 1, 12, 3, 12, 1, 1, 2, 3, 3}; //only works when the non unique numbers occur even number of times.
    // std::cout<<"Unique element in array is: "<<unique(arr)<<std::endl;
    //std::cout<<"Opposite signs -17 , 19:    "<< oppposite_signs(17,19)<<std::endl;
    //std::cout<<"Added one to 4: "<<bitwise_add_one(300)<<std::endl;
    //std::cout<<"Unset rightmost bit of 12:  "<<unset_right_bit(12)<<std::endl;
    //std::cout<<"Is power of two "<<x<<":   "<<power_of_two(x)<<std::endl;
    //std::cout<<"XOR of "<<x << " and "<<y<<" = "<<XOR_ultra(x,y)<<std::endl;
    //std::cout<<(5>=3)<<std::endl;
    //unsigned int i = 1;
    //show_mem_rep((char*)&i, sizeof(i));
    //std::string x = Dec_to_Hex(0x01234567);
    //std::string x = "0x01234567";
    //std::cout << revese_bits(1) << std::endl;
    //prime_numbers_in_range(100);
    //std::cout<<print_leftmost_set_bit(-1)<<std::endl;
    // std::cout<<(Dec_to_Hex(-1 >> 31))<<std::endl;
    std::cout<<"Reversal of 10 = "<<revese_bits(10)<<std::endl;
    //std::cout<<"Left rotation of 1 by 31 = "<<rotate_left(12,31)<<std::endl;
    //std::cout<<"Right rotation of 1 by 31 ="<<rotate_right(12,1)<<std::endl;
    //std::cout<<"64\%4 = "<<modulo(64,4)<<std::endl;
    //std::cout<<"63\%4 = "<<modulo(63,4)<<std::endl;
    //print_rightmost_set_bit(673);
    //print_leftmost_set_bit(673);
    return EXIT_SUCCESS;
}
