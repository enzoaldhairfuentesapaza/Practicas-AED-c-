#include <iostream>
using namespace std;

struct my_vector
{
    int *ptr_v;
    int size_vector;
    int size_element;
    int n_incremento;
    my_vector(int n)
    {
        n_incremento = n;
        size_vector=0;
        size_element=0;
        ptr_v = NULL;
    }
    void incremento()
    {
        size_vector+=n_incremento;
        int *aux = ptr_v;
        ptr_v = new int[n_incremento];
        for(int i=0; i< size_vector-n_incremento; i++)
        {   
            ptr_v[i] = aux[i];
        }
        delete [] aux;
    }
    void decremento()
    {
        if(size_vector <= 0) return;
        size_vector-=n_incremento;
        int *aux = ptr_v;
        ptr_v = new int[n_incremento];
        for(int i=0; i< size_vector-n_incremento; i++)
        {   
            ptr_v[i] = aux[i];
        }
        delete [] aux;
    }
    void my_push_back(int x)
    {
        if(size_element == size_vector)
        {
            incremento();
        }
        ptr_v[size_element] = x;
        size_element++;
    }
    void my_push_front(int x)
    {
        if(size_element == size_vector)
        {
            incremento();
        }
        for(int i=1; i<=size_element;i++)
        {
            swap(ptr_v[0], ptr_v[i]);
        }
        ptr_v[0] = x;
        size_element++;
    }
    void print()
    {
        for(int i=0; i < size_element; i++) 
        cout<< ptr_v[i] << " ";
        cout << endl;
    }
    int my_pop_back()
    {
        if(size_element <= 0) return -1;
        
        size_element--;
        return ptr_v[size_element];
    }
    int my_pop_front()
    {
        if(size_element <= 0) return -1;
        int retorno = ptr_v[0];
        for(int i=1; i< size_element; i++)
        {
            swap(ptr_v[i], ptr_v[i-1]);
        }
        size_element--;
        return retorno;
    }
    int &operator[] (int indice)
    {
        return ptr_v[indice];
    }
};

int main()
{
    
    my_vector test1(2);
    test1.my_push_back(10);
    test1.print();
    test1.my_push_back(11);
    test1.print();
    test1.my_push_front(9);
    test1.print();
    test1.my_push_front(8);
    test1.print();
    test1.my_push_back(12);
    test1.print();

    int recibir = test1[2];
    cout << recibir << endl;
    test1[2] = 20;
    
    test1.print();
    
    cout << test1.my_pop_back() << endl;
    test1.print();


    cout << test1.my_pop_front() << endl;
    test1.print();
    
    return 0;
}