#include <iostream>
using namespace std;

struct my_deque
{
    int size = 5;
    int** map = new int*[size];
    int* head = NULL;
    int* tail = NULL;
    int** head_map = map + (size/2);
    int** tail_map = map + (size/2);

    my_deque(int s)
    {
        size = s;
    }

    void my_push_back(int x)
    {
        if(head == NULL)
        {
            *head_map = new int[size];
            head = (*head_map)+ (size/2);
            tail = head;
        }
        else if(tail+1 == (*tail_map) + size)
        {
            tail_map++;
            *tail_map = new int[size];
            tail = *tail_map;
        }
        else
        {
            tail++;
        }
        *tail = x;
    }
    void my_push_front(int x)
    {
        if(head == NULL)
        {
            *head_map = new int[size];
            head = (*head_map)+ (size/2);
            tail = head;
        }
        else if(head == *head_map)
        {
            head_map--;
            *head_map = new int[size];
            head = (*head_map)+size-1;
        }
        else
        {
            head--;
        }
        *head =x;
    }
    int my_pop_front()
    {
        int retorno = *head;
        if(head == tail)
        {
            head = NULL;
            tail = NULL;
            delete [] *head_map;
        }
        else if (head == *head_map+size-1)
        {
            head_map++;
            head = *head_map;
            delete [] *(head_map-1);
        }
        else
        {
            head++;   
        }
        return retorno;
    }
    int my_pop_back()
    {
        int retorno = *tail;
        if(head == tail)
        {
            head = NULL;
            tail = NULL;
            delete [] *head_map;
        }
        else if (tail == *tail_map)
        {
            tail_map--;
            tail = *tail_map +size-1;
            delete [] *(tail_map+1);
        }
        else
        {
            tail--;   
        }
        return retorno;
    }

    int &operator[] (int indice)
    {

    }
    void print()
    {
        
    }
};

int main()
{
    
}