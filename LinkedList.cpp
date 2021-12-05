#include <iostream>
#include <string>
using namespace std;

class node
{
    int Data;
    node *next;
    friend class linkedlist;
};

class linkedlist
{
public:
    linkedlist() { first = NULL; }
    void addelement();
    void deleteelement(int);
    void showlist();
    bool search(int);
    void ReverseList();

private:
    node *first;
    node *last;
};
bool linkedlist::search(int x){
    node *current = first;
    while(current != NULL){
        if(current->Data == x)
            return true;
        current = current->next;
    }
    return false;
}

void linkedlist::ReverseList(){
    node *current = first;
    node *prev = NULL;
    node *next = NULL;
    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    first = prev;
}

void linkedlist::addelement()
{
    int data1;
    if (first == NULL)
    {
        cout << "Enter Data:";
        cin >> data1;
        node *temp = new node;
        temp->next = NULL;
        first = temp;
        first->Data = data1;
        last = first;
    }
    else
    {
        cout << "Enter Data:";
        cin >> data1;
        node *temp = new node;
        temp->next = NULL;
        last->next = temp;
        last = temp;
        last->Data = data1;
    }
}
void linkedlist::deleteelement(int data1)
{
    node *temp;
    node *temp1;
    temp1 = temp = first;
    int not_exit_in_list = 0;
    if (first->Data == data1)
    {
        temp = first;
        first = first->next;
        delete temp;
    }
    else
    {
        while (temp != last)
        {
            temp = temp1->next;
            if (temp->Data == data1)
            {
                if (temp == last)
                {
                    temp1->next = NULL;
                    delete temp;
                    last = temp1;
                    not_exit_in_list = 1;
                    break;
                }
                else
                {
                    temp1->next = temp->next;
                    delete temp;
                    not_exit_in_list = 1;
                    break;
                }
            }
            temp1 = temp1->next;
        }
        if (not_exit_in_list == 0)
        {
            cout << "There is not node with Data= " << data1 << " in linked list." << endl;
        }
    }
}
void linkedlist::showlist()
{
    if (first == NULL)
    {
        cout << "list empty" << endl;
    }
    else
    {
        node *temp;
        temp = first;
        while (temp != NULL)
        {
            cout << temp->Data << endl;
            temp = temp->next;
        }
    }
}
int main()
{
    int x;
    int i;
    linkedlist a;
    cout << "Enter number of node:";
    cin >> x;
    for (i = 0; i < x; i++)
    {
        a.addelement();
    }
    cout << endl
         << "show list:" << endl;
    a.showlist();
    cout << endl;
    cout << "Enter a int number want to delet from list:";
    cin >> x;
    a.deleteelement(x);
    cout << endl;
    cout << endl
         << "show New list:" << endl;
    a.showlist();
    cout << endl 
        << endl;
    cout << "Enter a number search number : ";
    cin >> x;
    if(a.search(x) == true){
        cout << "True";
    } else {
        cout << "False";
    }
    cout << endl << endl;
    cout << "Do you want Reverse List -> 1 = (Yes) AND 2 = (NO) ?";
    cin >> x;
    if(x == 1){
        a.ReverseList();
        a.showlist();
    } else {
        return 0;
    }
    return 0;
}
