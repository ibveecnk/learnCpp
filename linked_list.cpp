#include <iostream>
#include <cstdlib>

using namespace std;

class LinkedList
{
private:
    struct Node
    {
        int data;
        Node *next;
    };
    Node *head;
    Node *tail;
    int size;

public:
    LinkedList()
    {
        head = NULL;
        tail = NULL;
        size = 0;
    }
    void push_back(int data)
    {
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->data = data;
        newNode->next = NULL;
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }
    void push_front(int data)
    {
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->data = data;
        newNode->next = head;
        head = newNode;
        size++;
    }
    void pop_back()
    {
        if (head == NULL)
        {
            return;
        }
        Node *temp = head;
        while (temp->next != tail)
        {
            temp = temp->next;
        }
        tail = temp;
        free(temp);
        size--;
    }
    void pop_front()
    {
        if (head == NULL)
        {
            return;
        }
        Node *temp = head;
        head = head->next;
        free(temp);
        size--;
    }
    int front()
    {
        return head->data;
    }
    int back()
    {
        return tail->data;
    }
    int getSize()
    {
        return size;
    }
    bool empty()
    {
        return size == 0;
    }
    void print()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};

int main()
{
    LinkedList list = LinkedList();
    list.push_back(2);
    list.push_back(3);
    list.push_front(1);

    cout << "List debug: " << endl;
    list.print();

    cout << "Size: " << list.getSize() << endl;

    cout << "Printing values starting from the front: " << endl;
    cout << list.front() << endl;
    list.pop_front();

    cout << list.front() << endl;
    list.pop_front();

    cout << list.front() << endl;
    list.pop_front();

    cout << "Is list empty?" << endl;
    cout << list.empty() << endl;
}