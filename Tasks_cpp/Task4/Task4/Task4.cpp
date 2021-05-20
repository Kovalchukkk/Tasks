#include <iostream>
using namespace std;

struct elements
{
    int data; // ���
    elements* next, * prev;
};

class List
{
    // ������, ����
    elements* Head, * Tail;

    // �-��� ��������
    int size;

public:

    // �����������
    List();

    // ����������
    ~List();

    int getsize();

    // �������� ������� � ������
    elements* getelem(int);

    // ��������� ������ ������ 
    void Delete_All();

    // ��������� �������� �� i-�� �������
    void Delete_Position(int pos = 0);

    // ��������� �������� � ������ ������
    void Delete_Head();

    //��������� �������� � ���� ������
    void Delete_Tail();

    // ������� �������� �� i-�� ������� 
    void Insert_Position(int pos = 0);

    // ��������� �������� � ����� ������
    void Add_Tail(int n);

    // ��������� �������� �� ������� ������
    void Add_Head(int n);

    // ���� ������
    void Print();

    // ���� ������� �������� ������
    int Elem_Position(int pos);

};


List::List()
{
    Head = Tail = NULL;
    size = 0;
}


List::~List()
{
    // ��������� �� ��������
    Delete_All();
}

void List::Add_Head(int n)
{
    elements* temp = new elements;

    temp->prev = 0;
    temp->data = n;
    temp->next = Head;

    if (Head)
        Head->prev = temp;

    // ���� ������� ������ (��������), �� �� � ��������� ������� � �������
    if (size == 0)
        Head = Tail = temp;
    else
        // ������ � �������
        Head = temp;

    size++;
}

void List::Add_Tail(int n)
{
    elements* temp = new elements;
    temp->next = 0;
    temp->data = n;
    temp->prev = Tail;

    if (Tail)
        Tail->next = temp;

    // ���� ������� ������ (��������), �� �� � ��������� ������� � �������
    if (size == 0)
        Head = Tail = temp;
    else
        // ������ � �������
        Tail = temp;

    size++;
}

void List::Insert_Position(int pos)
{
    if (pos == 0)
    {
        cout << "Enter position: ";
        cin >> pos;
    }

    // ���� ������� ������� ���� 
    if (pos < 1 || pos > size + 1)
    {
        cout << "Incorrect position" << endl;
        return;
    }

    // ���������� ������ 
    if (pos == size + 1)
    {
        int data;
        cout << "Enter a number: ";
        cin >> data;
        Add_Tail(data);
        return;
    }
    else if (pos == 1)
    {
        int data;
        cout << "Enter a number: ";
        cin >> data;
        Add_Head(data);
        return;
    }


    int i = 1;

    elements* X = Head;

    while (i < pos)
    {
        // �������� �� ��������, ����� ���� ������ ��������
        X = X->next;
        i++;
    }

    elements* PrevX = X->prev;

    elements* temp = new elements;

    cout << "Enter a number: ";
    cin >> temp->data;

    if (PrevX != 0 && size != 1)
        PrevX->next = temp;

    temp->next = X;
    temp->prev = PrevX;
    X->prev = temp;

    size++;
}

void List::Delete_Position(int pos)
{
    if (pos == 0)
    {
        cout << "Enter position: ";
        cin >> pos;
    }

    if (pos < 1 || pos > size)
    {
        cout << "Incorrect position" << endl;
        return;
    }

    int i = 1;

    elements* Del = Head;

    while (i < pos)
    {
        // �������� �� ��������, ���� �� ������ ��������
        Del = Del->next;
        i++;
    }

    elements* prevDel = Del->prev;
    elements* afterDel = Del->next;

    // ���� ��������� �� ������
    if (prevDel != 0 && size != 1)
        prevDel->next = afterDel;

    // ���� ��������� �� ����
    if (afterDel != 0 && size != 1)
        afterDel->prev = prevDel;

    if (pos == 1)
        Head = afterDel;
    if (pos == size)
        Tail = prevDel;

    delete Del;

    size--;
}

void List::Delete_Head()
{
    Delete_Position(1);
}

void List::Delete_Tail()
{
    Delete_Position(size);
}

int List::Elem_Position(int pos)
{
    if (pos < 1 || pos > size)
    {
        cout << "Incorrect position" << endl;
        return 0;
    }

    elements* temp;

    // �������� ����� ������ ������
    if (pos <= size / 2)
    {
        // � ������
        temp = Head;
        int i = 1;

        while (i < pos)
        {
            // �������� �� ��������� ��������
            temp = temp->next;
            i++;
        }
    }
    else
    {
        // ������ � ������
        temp = Tail;
        int i = 1;

        while (i <= size - pos)
        {
            // �������� �� ��������� ��������
            temp = temp->prev;
            i++;
        }
    }
    // ���� ��������� ��������
    //cout << pos << "Element: ";
    return temp->data;
}

void List::Print()
{
    // ���� ������ �� ������, �� ������� ���� 
    if (size != 0)
    {
        elements* temp = Head;
        cout << "[ ";
        while (temp->next != 0)
        {
            cout << temp->data << ", ";
            temp = temp->next;
        }

        cout << temp->data << " ]" << endl;

    }
}

void List::Delete_All()
{
    // ���� ����������� �������� � ������, ��������� ��-������ � ������
    while (size)
        Delete_Position(1);
}

int List::getsize()
{
    return size;
}

elements* List::getelem(int pos)
{
    elements* temp = Head;

    if (pos < 1 || pos > size)
    {
        cout << "Incorrect position" << endl;
        return 0;
    }

    int i = 1;

    // ������ �������� �������
    while (i < pos && temp != 0)
    {
        temp = temp->next;
        i++;
    }

    if (temp == 0)
        return 0;
    else
        return temp;
}

/*
int check(int a, int b)
{
    if (a < b)
    {
        return a;
    }

    else if (a > b)
    {
        return false;
    }
}*/

void main()
{
    List lst;
    List res_lst;

    const int n = 9;
    int arr[n] = { 1,2,3,8,3,4,5,1,2 };

    for (int i = 0; i < n; i++)
    {
        lst.Add_Head(arr[i]);
    }

    //cout << lst.Print_Position(3) << endl;
    //cout << lst.getsize() << endl;
    /*
    for (int i = lst.getsize(); i > 0; i--)
    {
        res_lst.Add_Head(check(lst.Elem_Position(i), lst.Elem_Position(i - 1)));
    }*/

    cout << "Stack: ";
   
    lst.Print();

    //cout << "Result Stack: ";

    //res_lst.Print();
}