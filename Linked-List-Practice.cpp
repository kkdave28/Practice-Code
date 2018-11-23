#include <iostream>
#include <unordered_map>
#include <bits/stdc++.h>

struct MLNode
{
    int key;
    MLNode * next = nullptr;
    MLNode * child = nullptr;
};

void printMLL(MLNode * head) // Flatten
{
    std::queue<MLNode*> child_queue;
    while(head->next || !child_queue.empty() || head->child)
    {

        if(head->child)
            child_queue.push(head->child);
        std::cout<<head->key<<"->";
        if(!child_queue.empty() && !head->next)
        {
            head->next = child_queue.front();
            child_queue.pop();
            head = head->next;
        }
        else
            head= head->next;
    }
    std::cout<<head->key<<std::endl;
}
void printFMLL(MLNode * head)
{
    while(head->next)
    {
        std::cout<<head->key<<"->";
        head = head->next;
    }
    std::cout<<head->key<<std::endl;
}
void Flatten(MLNode * head)
{
    std::queue<MLNode*> child_queue;
    while(head->next || !child_queue.empty()|| head->child)
    {
        if(head->child)
            child_queue.push(head->child);
        if(!child_queue.empty()&& !head->next)
        {
            head->next = child_queue.front();
            child_queue.pop();
            head = head->next;
        }
        else
        {
            head = head->next;
        }
    }
}
void add_Front(MLNode **head, int key)
{
    MLNode * temp = new MLNode;
    temp->key = key;
    temp->next = *head;
    if((*head))
        temp->child = (*head)->child;
     *head = temp;
}

void add_ChildFront(MLNode** head, int key)
{
    MLNode * temp = new MLNode;
    temp->key = key;
    temp->next = (*head)->child;
    (*head)->child = temp;
}
struct Node
{
    int key;
    Node * next;
    void add_Front(Node** head, int key)
    {
        Node * temp = new Node;
        temp->key = key;
        temp->next = *head;
        *head = temp;
    }
    void add_back(Node ** head, int key)
    {
        if(*head == nullptr)
        {
            Node * temp = new Node;
            temp->key = key;
            *head = temp;
            return;
        }
        add_back(&(*head)->next,key);
    }
    void add_after(Node ** head, int fkey, int key)
    {
        if(*head == nullptr || (*head)->key ==fkey)
        {
            Node * temp = new Node;
            temp->key = key;
            temp->next = (*head)->next;
            (*head)->next = temp;
            return;
        }
        add_after(&(*head)->next, fkey, key);
    }
    void add_before(Node **head, int fkey, int key)
    {
        if(*head == nullptr || (*head)->next->key ==fkey)
        {
            Node * temp = new Node;
            temp->key = key;
            temp->next = (*head)->next;
            (*head)->next = temp;
            return;
        }
        add_before(&(*head)->next, fkey, key);
    }
    void delete_node(Node ** head, int key)
    {
        Node * temp = *head;
        while(temp&& temp->next->key != key)
        {
            temp = temp->next;
        }
        Node * d = temp->next;
        temp->next = d->next;
        d->next = nullptr;
        delete(d);
    }
    void delete_node_recursive(Node ** head, int key)
    {
        if(*head == nullptr)
            return;
        else if ((*head)-> next->key == key)
        {
            Node * temp = (*head)->next;
            (*head)->next = temp->next;
            temp->next = nullptr;
            delete(temp);
            return;
        }
        delete_node_recursive(&(*head)->next, key);

    }
    void printLL(Node * head)
    {
        while(head->next)
        {
            std::cout<<head->key<<" -->  ";
            head=head->next;
        }
        std::cout<<head->key<<std::endl;
    }

};
    void reverse_ITR(Node ** head)
    {
        Node * curr = *(head);
        Node * prev=nullptr, *next=nullptr; 
        while(curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        (*head) = prev;
    }
    void REC_UTIL(Node * curr, Node * prev, Node ** head)
    {
        if(!curr->next)
        {
            *head = curr;
            curr->next = prev;
            return;
        }
        Node * next = curr->next;
        curr->next = prev;
        REC_UTIL(next, curr, head);

    }
    void reverse_REC(Node ** head)
    {
        if(!(*head))
            return;
        REC_UTIL(*head, nullptr, head);
    }
    void iterative_reverse_in_place(Node ** head)
    {
        if(!(*head))
            return;
        Node * next, * prev = nullptr;
        while((*head)->next != nullptr)
        {
            next = (*head)->next;
            (*head)->next = prev;
            prev = *head;
            *head = next;
        }
        (*head)->next = prev;
    }
    void free_LL(Node * head)
    {
        if(head!=nullptr)
        {
            free_LL(head->next);
            delete(head);
            
        }
    }
    void FindAndDeleteRotation(Node * head)
    {
        if(!head || !head->next)
        {
            return;
        }
        Node * prev = nullptr;
        std::unordered_map<Node *, int> node_map;
        while(head)
        {
            if(node_map.find(head) == node_map.end())
            {
                node_map[head]++;
                prev = head;
                head = head->next;
            }
            else
            {
                prev->next = nullptr;
                return;
            }
        }
    }
 Node* removeNthFromEnd(Node* head, int n) {
        Node* temp = head;
        int len = 1;
        while(temp->next && len++)
            temp = temp->next;
        int index = len -n;
        if(index == 0)
        {
            Node * prev = head;
            head = head->next;
            delete(prev);
            return head;
        }
        Node * prev=head, *itr = head;
        while(index--)
        {
            prev = itr;
            itr = itr->next;
        }
        prev->next = itr->next;
        delete(itr);
        return head;
    }
int main(int argc, char const * argv[])
{
    MLNode * LL = nullptr, *LLTemp = nullptr;
    add_Front(&LL,2);
    add_Front(&LL,1);
    add_Front(&LLTemp,4);
    add_Front(&LLTemp,3);
    LL->next->child = LLTemp;
    // add_Front(&LL, 11);
    // add_Front(&LL, 7);
    // add_Front(&LL, 12);
    // add_Front(&LL, 5);
    // add_Front(&LL, 10);
    // add_Front(&LLTemp, 13);
    // add_Front(&LLTemp, 20);
    // add_Front(&LLTemp, 4);
    // LL->child = LLTemp;
    // LLTemp = nullptr;
    // add_Front(&LLTemp, 6);
    // add_Front(&LLTemp, 17);
    // LL->next->next->next->child = LLTemp;
    // LLTemp = nullptr;
    // add_Front(&LLTemp,2);
    // LL->child->next->child = LLTemp;
    // LLTemp = nullptr;
    // add_Front(&LLTemp,16);
    // LL->child->next->next->child = LLTemp;
    // LLTemp = nullptr;
    // add_Front(&LLTemp,3);
    // LL->child->next->next->child->child = LLTemp;
    // LLTemp = nullptr;
    // add_Front(&LLTemp, 8);
    // add_Front(&LLTemp, 9);
    // LL->next->next->next->child->child = LLTemp;
    // LLTemp = nullptr;
    // add_Front(&LLTemp, 15);
    // add_Front(&LLTemp, 19);
    // LL->next->next->next->child->child->child = LLTemp;
    // std::cout<<"Before Flattening the list:"<<std::endl;
    printFMLL(LL);
    Flatten(LL);
    std::cout<<"After Flattening the list:"<<std::endl;
    printFMLL(LL);
    //printMLL(LL);
}