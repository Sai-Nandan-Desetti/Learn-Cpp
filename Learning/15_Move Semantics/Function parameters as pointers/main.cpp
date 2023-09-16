#include <iostream>

struct Node
{
    int val{ 5 };
};

void print(Node* node)
{
    std::cout << node->val << '\n';
}

int main()
{
    Node* head{ new Node() };

    print(head);
    std::cout << head->val << '\n';
    
    delete head;

    return 0;
}
