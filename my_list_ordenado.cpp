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

    void push(int x)
    { 
        if(head == NULL)
        {
            head = new node(x,NULL);
            return;
        
        }
        node* aux = head;
        for(; aux->next != NULL && x > aux->next->value; aux = aux->next);

        if(aux == head && aux->value >= x)
        {
            if(aux->value == x) return;
            head = new node(x, head);
        }
        else if( aux->next != NULL && aux->next->value == x)
        {
            return;
        }
        else
        {
            aux->next = new node(x, aux->next);
        }
    }

    void del(int x)
    {
        if(head == NULL) return;

        if(head->next == NULL)
        {
            delete head;
            head = NULL;
            return;
        }

        node* aux = head;
        for(; aux->next != NULL && x > aux->next->value; aux = aux->next);
        
        if(aux == head && aux->value >= x)
        {
            if(aux->value == x)
            {
                node* aux2 = head;
                head = head->next;
                delete aux2;
            }
            return;
        }
        else if( aux->next != NULL && aux->next->value == x)
        {
            node* aux2 = aux->next;
            aux->next = aux2->next;
            delete aux2;
        }
        else 
        {
            return;
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
    my_list_simple lista;

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

    cout << "Lista actual: ";
    lista.print();

    cout << "\nProbando operator[]:" << endl;
    cout << "Elemento en indice 0: " << lista[0] << endl;
    cout << "Elemento en indice 1: " << lista[1] << endl;
    cout << "Elemento en indice 2: " << lista[2] << endl;


    cout << "Lista despues de modificar: ";
    lista.print();

    cout << "\nEliminando valores..." << endl;
    lista.del(20);
    lista.print();
    lista.del(5);
    lista.print();
    lista.del(10);
    lista.print();


    cout << "Lista final: ";
    lista.print();

    return 0;
}