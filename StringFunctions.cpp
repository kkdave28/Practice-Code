#include<bits/stdc++.h>

int strtstr(std::string s, std::string x) // could be better
{
    int start = -1;
    int itr1=0, itr2=0;
    if(x.empty() || s.empty())
        return start;
    std::map<char, std::vector<int>> dictionary;

    for(int i = 0; i< s.length(); i++)
    {
        dictionary[s[i]].push_back(i);
    }
    for(auto E: dictionary[x[0]])
    {
        int i = E+1;
        start = E;
        int loop_var = 1;
        itr1++;
        while(1)
        {
            itr2++;
            if(loop_var >= x.length())
              {  
                  std::cout<<"Number of iterations = "<<itr1+itr2<<std::endl;
                  return start;
              }
            if(x[loop_var] != s[i])
            {
                start = -1;
                break;
            }
            loop_var++;
            i++;
        }
    }
    std::cout<<"Number of iterations = "<<itr1+itr2<<std::endl;
    return start;
}
//int itr1=0,it2=0;
int efficient_strstr(std::string haystack, std::string needle)
{
    if(needle.empty())
        return 0;
    int i=0, j=0;
    int sz_hay = (int)haystack.length(), sz_ned = (int)needle.length();
    
    for(; i< sz_hay - sz_ned+1; i++)
    {
        //itr1++;
        if(haystack[i] == needle[0])
        {
            j=1;
            for(;j<sz_ned && needle[j]==haystack[i+j]; j++);
            if(j==sz_ned)
                return i;
        }
    }
    return -1;
}
bool next_permutation(std::string & x)
{
    int i = x.length() - 1;
    while(i>0 && x[i-1]>=x[i]) // find the element right before the start of suffix...
        i--;
    if(i<=0) // Already the last permutation ?...
        return false;
    int j = x.length()-1;
    while(x[j] <= x[i-1]) // Find the least element that is greater than or equal to the element before the suffix.
        j--;
    char temp = x[j]; // swap the two pivots...
    x[j] = x[i-1];
    x[i-1] = temp;
    j = x.length()-1;
    while(i<j) // reverse the suffix.
    {
        temp = x[i];
        x[i] = x[j];
        x[j] = temp;
        i++;
        j--;
    }
    return true;
}
void all_perms(std::string x, std::string y)
{
    std::cout<<y<<std::endl;
    for(int i=0; i< x.length(); i++)
    {
        all_perms(std::string(x).erase(i,1), y+x[i]);
    }
}
void combinatorial_pre_processing(std::string &s, std::map<char, int> & frequency)
{
    std::sort(s.begin(), s.end());
    for(auto E: s)
        frequency[E]++;
}
void print_all_combinations(std::string s, std::map<char, int> freq, std::string output, std::set<std::string> & all_combs)
{
    all_combs.insert(output);
    for(int i=0; i< s.length(); i++)
    {
        if(freq[s[i]]>0)
        {
            freq[s[i]]--;
            std::string temp = s.substr(i+1, s.length()-i-1);
            print_all_combinations(temp, freq, output+std::string(1,s[i]), all_combs);
        }
    }
}
int count_number_of_common_chars(std::string x, std::string y)
{
    int map[256] = {0};
    int result = 0;
    for(auto E: x) map[E]++;
    for(auto E: y) result+= (map[E]-- > 0);
    return result;
}
void find_common_letters(std::string x, std::string y)
{
    int map[256] = {0};
    //int result = 0;
    for(auto E: x) map[E]++;
    for(auto E: y)
    {
        if(map[E] > 0)
        {
            std::cout<<E<<std::endl;
            map[E]--;
        }
    }
    
}
void print_valid_ip_addr(std::string s, std::string output="", int depth = 0)
{
    if(depth == 4)
    {
        std::cout<<output<<std::endl;
    }
    else
    {
        for(int i=0; i<s.length(); i++)
        {
            if(s.length()-i >=3)
            {
                if(std::stoi(s.substr(i,3))<= 255)
                {
                    print_valid_ip_addr(s.substr(i+3),output+s.substr(i,3)+".", depth+1);
                }
                if(std::stoi(s.substr(i,2))>=10)
                    print_valid_ip_addr(s.substr(i+2),output+s.substr(i,2)+".", depth+1);
            }
            if(s.length()-i>=2)
            {
                if(std::stoi(s.substr(i,2))>= 10)
                {
                    print_valid_ip_addr(s.substr(i+2),output+s.substr(i,2)+".", depth+1);
                }
                print_valid_ip_addr(s.substr(i+1),output+s.substr(i,1)+".", depth+1);
            }
            else if (s.length()-i >=1)
            {
                print_valid_ip_addr(s.substr(i+1),output+s.substr(i,1)+".", depth+1);
            }
        }
    }
}
int main(int argc, char const *argv[])
{
    //std::string x = "Good Morning America";
    //std::string y = "Hello World";
    //std::cout<<"Number of common characters between x and y = "<<count_number_of_common_chars(x,y)<<std::endl;
    //find_common_letters(x,y);
    // std::string x = "BACA";
    // std::set<std::string> ret;
    // std::map<char, int> freq_map;
    // combinatorial_pre_processing(x, freq_map);
    // print_all_combinations(x,freq_map, "", ret);
    // for(auto E: ret)
    //     std::cout<<E<<std::endl;
    print_valid_ip_addr(argv[1]);
    return 0;
}
