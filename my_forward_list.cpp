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


struct my_forward_list
{
    node* head = NULL;

    bool find(int x, node** &p)
    {
        for(p=&head; *p !=NULL && x > (*p)->value ; p = &(*p)->next);
        return *p !=NULL && x == (*p)->value; 
    }
    void push(int x)
    { 
        node ** p = NULL;
        if(!find(x, p)) *p = new node(x,*p);
        return;
    }
    void del(int x)
    {
        node** p = NULL;
        if(find(x,p))
        {
            node* aux = *p;
            *p = aux->next;
            delete aux;
        }
        return;
    }

    void print()
    {
        for(node** aux = &head; *aux != NULL;  aux = &(*aux)->next)
        {
            cout << (*aux)->value << " ";
        }
        cout << endl;
    }
};


int main()
{
    my_forward_list lista;

    cout << "Insertando valores..." << endl;
    lista.push(10);
    lista.print();
    lista.push(5);
    lista.print();
    lista.push(20);
    lista.print();
    lista.push(15);
    lista.print();
    lista.push(5);
    lista.print();

    cout << "Lista despues de modificar: ";
    lista.print();

    cout << "\nEliminando valores..." << endl;
    lista.del(10);
    lista.print();
    lista.del(5);
    lista.print();
    lista.del(10);
    lista.print();
    lista.del(100);


    cout << "Lista final: ";
    lista.print();

    return 0;
}