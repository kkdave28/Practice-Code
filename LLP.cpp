#include <bits/stdc++.h>

struct Node
{
    // key types
    int key;
    Node * next;
    // Functions.
    void AddFront(Node **head, int key)
    {
        Node * temp = new Node;
        temp->key = key;
        temp->next = (*head);
        (*head) = temp;
    }

    void AddBack (Node ** head, int key)
    {
        if(!(*head))
        {
            Node * temp = new Node;
            temp->key = key;
            *head = temp;
            return;
        }
        AddBack(&(*head)->next, key);
    }
    void AddBefore(Node ** head, int key, int fkey)
    {
        if(!(*head))
            return;
        if((*head)->next->key == fkey)
        {
            Node * temp = new Node;
            temp->key = key;
            temp->next = (*head)->next;
            (*head)->next = temp;
            return;
        }
        AddBefore(&(*head)->next, key, fkey);
    }
    void AddAfter(Node ** head, int key, int fkey)
    {
        if(!(*head))
            return;
        if((*head)->key == fkey)
        {
            Node * temp = new Node;
            temp->key = key;
            temp->next = (*head)->next;
            (*head)->next = temp;
            return;
        }
        AddAfter(&(*head)->next, key, fkey);
    }
    void DeleteKey(Node ** head, int key)
    {
        if(!(*head))
            return;
        if((*head)->next->key == key)
        {
            Node * temp = (*head)->next;
            (*head)->next = temp->next;
            temp->next = nullptr;
            delete(temp);
            return;
        }
        DeleteKey(&(*head)->next, key);
    }
    void ReverseIterative(Node **head)
    {
        Node * curr = (*head), *next = nullptr, *prev = nullptr;
        while(curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        (*head) = prev;
    }
    void DetectAndDeleteLoop(Node **head)
    {
        std::set<Node *> loop_map;
        Node * curr = (*head), *prev = nullptr;
        while(curr)
        {
            if(loop_map.find(curr) == loop_map.end())
            {
                loop_map.insert(curr);
                prev = curr;
                curr = curr->next;
            }
            else
            {
                std::cout<<"Loop detected between nodes: "<<prev->key<<" and "<<curr->key<<"."<<std::endl;
                prev->next = nullptr;
                return;
            }
        }
    }
    void FLoydRemoveLoop(Node * loop, Node ** head)
    {
        unsigned int k=1, i;
        Node * pointer_1 = nullptr, *pointer_2 = nullptr;
        pointer_1 = pointer_2 = loop;
        while(pointer_1->next !=pointer_2)
        {
            pointer_1=pointer_1->next;
            k++;
        }
        pointer_1 = pointer_2 = (*head);
        for(i=0; i<k; i++)
            pointer_2 = pointer_2->next;
        while(pointer_2 != pointer_1)
        {
            pointer_1 = pointer_1->next;
            pointer_2 = pointer_2->next;
        }
        pointer_2 = pointer_2->next;
        while(pointer_2->next != pointer_1)
            pointer_2 = pointer_2->next;
        pointer_2->next = nullptr;
    }
    void deleteLooopTest(Node ** loop)
    {
        Node * ptr1 = (*loop), *ptr2 = (*loop);
        while(ptr2->next != ptr1)
            ptr2=ptr2->next;
        ptr2=ptr2->next;
        ptr2->next = nullptr;
    }
    void FindLoop(Node ** head)
    {
        Node * fast = (*head), *slow = (*head);
        while(slow && fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast)
            {
                //deleteLooopTest(&slow);
                FLoydRemoveLoop(slow, head);
                //DetectAndDeleteLoop
            }
        }
    }
    int countloopnodes(Node ** head)
    {
        if(!head)
            return 0;
        Node * slow = *head, *fast = *head;
        int ret = 1;
        while(slow && fast)
        {
            slow = slow->next;
            fast=fast->next->next;
            if(slow == fast)
                break;
        }
        if(!fast || !slow)
            return 0;
        while(fast->next != slow)
        {
            ret++;
            fast = fast->next;
        }
        return ret;
    }
    void PrintLL(Node * temp)
    {
        Node * head = temp;
        while(head->next)
        {
            std::cout<<head->key<<"->";
            head=head->next;
        }
        std::cout<<head->key<<std::endl;
    }
    void DeleteLL(Node * head)
    {
        Node * temp = nullptr;
        while(head)
        {
            Node * temp = head->next;
            delete(head);
            head = temp;
        }
    }
//    bool in_place_palindrome(Node * head);
bool in_place_palindrome(Node * head)
{
    if(!head || !head->next)
        return true;
    int len = 0;
    Node * temp = head;
    while(temp)
    {
        len++;
        temp=temp->next;
    }
    // is it odd or even? two different strategies for two different cases.
    if(len%2)
        return odd_palindrome(head, len);
    return even_palindrome(head, len);
}
bool odd_palindrome(Node * head, int len)
{
    Node * midway = head;
    int halflen = len/2;
    while(halflen--)
    {
        midway = midway->next;
    }
    Node * first_half = head, *prev = nullptr, * next = nullptr, *second_half = midway->next;
    while(first_half !=  midway)
    {
        next = first_half->next;
        first_half->next = prev;
        prev = first_half;
        first_half = next;
    }
    first_half = prev;
    while(first_half && second_half)
    {
        if(first_half->key != second_half->key)
            return false;
        first_half= first_half->next;
        second_half = second_half->next;
    }
    return true;
}

bool even_palindrome(Node * head, int len)
{
    Node *first_half = nullptr, *second_half = head;
    int halflen = len/2;
    while(halflen--)
    {
        first_half = second_half;
        second_half = second_half->next;
    }
    Node * curr = head, *next = nullptr, *prev = nullptr;
    while(curr != second_half)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    while(first_half && second_half)
    {
        if(first_half->key != second_half->key)
            return false;
        first_half = first_half->next;
        second_half = second_half->next;
    }
    return true;
    
}
bool isPalindrome(Node *head)
{
    return in_place_palindrome(head);
}

void REVERSE_RECURSIVE(Node **head, Node * next, Node * prev)
{
    if(!(*head))
    {
        (*head) = prev;
        return;
    }
    next = (*head)->next;
    (*head)->next = prev;
    prev = (*head);
    (*head) = next;
    REVERSE_RECURSIVE(head, next, prev);
}
void rec_rev_helper(Node ** head)
{
    if(!(*head) || !(*head)->next)
        return;
    REVERSE_RECURSIVE(head, (*head)->next, nullptr);
}
};
/*
    Program to check if given Linked List is a Palindrome:
****************************************************************************************
****************************************************************************************
****************************************************************************************
****************************************************************************************
****************************************************************************************

    void AddFront(Node ** head, int key)
{
    Node * temp = new Node;
    temp->key = key;
    temp->next = (*head);
    (*head) = temp;
}
bool in_place_palindrome(Node * head);
bool isPalindrome(Node *head)
{
    return in_place_palindrome(head);
    // Node * copy, *helper = head;
    // while(helper)
    // {
    //     AddFront(&copy, helper->key);
    //     helper= helper->next;
    // }
    // helper = head;
    // while(helper && copy)
    // {
    //     if(helper->key != copy->key)
    //         return false;
    //     helper = helper->next;
    //     copy = copy->next;
    // }
    // return true;
}
bool odd_palindrome(Node * head, int len);
bool even_palindrome(Node * head, int len);
bool in_place_palindrome(Node * head)
{
    if(!head || !head->next)
        return true;
    int len = 0;
    Node * temp = head;
    while(temp)
    {
        len++;
        temp=temp->next;
    }
    // is it odd or even? two different strategies for two different cases.
    if(len%2)
        return odd_palindrome(head, len);
    return even_palindrome(head, len);
}
bool odd_palindrome(Node * head, int len)
{
    Node * midway = head;
    int halflen = len/2;
    while(halflen--)
    {
        midway = midway->next;
    }
    Node * first_half = head, *prev = nullptr, * next = nullptr, *second_half = midway->next;
    while(first_half !=  midway)
    {
        next = first_half->next;
        first_half->next = prev;
        prev = first_half;
        first_half = next;
    }
    first_half = prev;
    while(first_half && second_half)
    {
        if(first_half->key != second_half->key)
            return false;
        first_half= first_half->next;
        second_half = second_half->next;
    }
    return true;
}

bool even_palindrome(Node * head, int len)
{
    Node *first_half = nullptr, *second_half = head;
    int halflen = len/2;
    while(halflen--)
    {
        first_half = second_half;
        second_half = second_half->next;
    }
    Node * curr = head, *next = nullptr, *prev = nullptr;
    while(curr != second_half)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    while(first_half && second_half)
    {
        if(first_half->key != second_half->key)
            return false;
        first_half = first_half->next;
        second_half = second_half->next;
    }
    return true;
    
}
*/
int main(int argc, char const *argv[])
{
    Node * LL = nullptr; //  DOnt forget this or else bad stuff will happen.
    LL->AddFront(&LL,1);
    LL->AddFront(&LL,2);
    LL->AddFront(&LL,3);
    LL->PrintLL(LL);
    LL->rec_rev_helper(&LL);
    // LL->AddFront(&LL,3);
    // LL->AddFront(&LL,2);
    // LL->AddFront(&LL,1);
    //LL->next->next->next->next->next->next = LL;
    //LL->DetectAndDeleteLoop(&LL);
    //int k = LL->countloopnodes(&LL);
    //std::cout<<"Is the given LL a Plaindrome? "<<LL->isPalindrome(LL)<<std::endl;
    //LL->FindLoop(&LL);

    LL->PrintLL(LL);
    // for (int i = 0; i< 6; i++)
    // {
    //     LL->AddBack(&LL,i);
    // }
    // LL->AddBefore(&LL, 180, 4);
    // LL->AddAfter(&LL,360,180);
    // LL->PrintLL(LL);
    // LL->DeleteKey(&LL, 360);
    // LL->PrintLL(LL);
    // LL->ReverseIterative(&LL);
    // LL->PrintLL(LL);
    // LL->DeleteLL(LL);
}
