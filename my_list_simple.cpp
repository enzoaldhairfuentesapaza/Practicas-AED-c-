#include <iostream>
using namespace std;

struct node
{
    int value;
    node* next = NULL;
    node()
    {
        value = 0;
        next = NULL;
    }
    node(int v, node* n )
    {
        value = v;
        next = n;
    }
};


struct my_list_simple
{
    node* head = NULL;
    node* tail = NULL;
    void my_push_back(int x)
    {  
        if(!tail)
        {
            tail = new node(x,NULL);
            head = tail;
        }
        else
        {
            node * aux = new node(x,NULL);
            tail->next = aux;
            tail = aux;
        }
    }
    void my_push_front(int x)
    {
        if(head == NULL)
        {
            head = new node(x,NULL);
            tail = head;
        }
        else
        {
            head = new node(x,head);
            /*node * aux = new node(x,NULL);
            aux->next = head;
            head = aux;*/ 
        }
    }
    void print()
    {
        for(node* aux = head; aux != NULL;  aux = aux->next)
        {
            cout << aux->value << " ";
        }
        cout << endl;
    }
    int my_pop_back()
    {
        int retorno = tail->value;
        if(head == tail)
        {
            delete head;
            head = tail = NULL;
            return retorno;
        }
        node* aux = head;
        for(;aux->next != tail; aux = aux->next);
        delete tail;
        tail = aux;
        tail->next = NULL;
        return retorno;
    }
    int my_pop_front()
    {
        int retorno = head->value;
        if(head == tail)
        {
            delete head;
            head = tail = NULL;
            return retorno;
        }
        node *aux = head;
        head = head->next;
        delete aux;
        return retorno;
    }
    int &operator[] (int indice)
    {
        int i = 0;
        node* aux = head;
        for(; i < indice ; i++, aux = aux->next);
        return aux->value;

    }

};


int main()
{
    my_list_simple test1;
    test1.my_push_back(1);
    test1.print();
    test1.my_push_back(2);
    test1.print();
    test1.my_push_front(3);
    test1.print();
    test1.my_push_front(4);
    test1.print();
    test1.my_push_back(5);
    test1.print();

    cout << test1.my_pop_back() << endl;
    test1.print();
    cout << test1.my_pop_front() << endl;
    test1.print();
    test1.my_push_back(5);

    cout << "--------------------------------------" << endl;
    int recibir = test1[2];
    cout << recibir << endl;
    test1[2] = 20;
    
    test1.print();

    return 0;
}