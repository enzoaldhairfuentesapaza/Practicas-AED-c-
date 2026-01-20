#include <iostream>
using namespace std;


template <class T>
struct node
{
    T value;
    node<T>* next = NULL;
    node<T>* prev = NULL;
    node(T value)
    {
        this->value = value;
        next = this;
        prev = this;
    }
    node()
    {
        value = 0;
        next = NULL;
        prev = NULL;

    }
    node(T v, node<T>* n, node<T>* p )
    {
        value = v;
        next = n;
        prev = p;
    }
};

template <class T>
struct my_list_simple
{
    node<T>* head = NULL;
    void my_push_back(T x)
    {  
        if(!head) // head == NULL
        {
            head = new node<T>(x);
        }
        head->prev = new node<T>(x,head, head->prev); 
        head->prev->prev->next = head->prev;
    }
    void my_push_front(T x)
    {
        if(!head) // head == NULL
        {
            head = new node<T>(x);
        }
        head = new node<T>(x,head,head->prev);
        head->prev->next = head;
        head->next->prev = head;
    }
    void print()
    {
        if (!head) return;
        node<T>* aux = head;
        for(; aux != head->prev;  aux = aux->next)
        {
            cout << aux->value << " ";
        }
        cout << aux->value  << " ";
        cout << endl;
    }
    T my_pop_back()
    {
        if (!head) return T();
        if(head == head->next)
        {
            delete head;
            head = NULL;
        }
        node<T>* aux = head->prev;
        T val = aux->value;
        head->prev = head->prev->prev;
        head->prev->next = head;
        delete aux;
        return val;
    }
    T my_pop_front()
    {
        if (!head) return T();
        if(head == head->next)
        {
            delete head;
            head = NULL;
        }
        node<T>* aux = head;
        T retorno = aux->value;
        head = head->next;
        head->prev = aux->prev;
        head->prev->next = head;
        delete aux;
        return retorno;
    }
    T &operator[] (int indice)
    {
        int i = 0;
        node<T>* aux = head;
        for(; i < indice ; i++, aux = aux->next);
        return aux->value;    
    }

};


int main()
{
    my_list_simple <int> test1;
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