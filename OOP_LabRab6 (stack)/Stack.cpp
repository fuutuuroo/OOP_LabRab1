#include "Stack.h"
//конструктор по умолчанию
Stack::Stack()
{
    size = 0;
    top = nullptr;
}
//конструктор с параметрами
Stack::Stack(int s, int d)
{
    size = s;
    top = nullptr;
    for (int i = 0; i < size; i++) {
        Node* addNode = new Node;
        addNode->data = d;
        addNode->pNext = top;
        top = addNode;
    }
}
//конструктор копирования
Stack::Stack(const Stack& s)
{
    size = s.size;
    if (s.top == nullptr) {
        top = nullptr;
        return;
    }
    top = new Node;
    top->data = s.top->data;
    Node* current = s.top->pNext;
    Node* newCurrent = top;
    while (current != nullptr) {
        Node* addNode = new Node;
        addNode->data = current->data;
        newCurrent->pNext = addNode;
        newCurrent = addNode;
        current = current->pNext;
    }
    newCurrent->pNext = nullptr;
}
//деструктор
Stack::~Stack() {
    while (size > 0) {
        pop();
    }
}
//функция для добавления элемента в стек
void Stack::push(int d)
{
    Node* addNode = new Node; 
    addNode->data = d;
    addNode->pNext = top;
    top = addNode;
    size++;
}
//функция для удаления элемента из стека
void Stack::pop()
{
    if (top == nullptr) {
        cout << "Стек пуст!" << endl; 
        return;
    }
    else {
        Node* nodeDelete = top; 
        top = top->pNext; 
        delete nodeDelete;
        size--;
    }
}
//перегрузка оператора присваивания
Stack& Stack::operator = (const Stack& s)
{
    if (this == &s) {
        return *this;
    }
    while (top != nullptr) {
        Node* temp = top;
        top = top->pNext;
        delete temp;
        size--;
    }    
    Node* otherCurrent = s.top;
    while (otherCurrent != nullptr) {
        push(otherCurrent->data);
        otherCurrent = otherCurrent->pNext;
    }
    return *this;
}
//перегрузка оператора присваивания
int& Stack::operator [] (int index) 
{
    if (index >= 0 && index < size) {
        Node* current = top;
        int newSize = size - 1;
        while (newSize != index) {
            current = current->pNext;
            newSize--;
        }
        return current->data;
    }
}
//перегрузка круглых скобок
int Stack::operator () ()
{
    return size;
}
//перегрузка оператора сложения
void Stack::operator + (int add)
{
    Node* current = this->top;
    while (current != nullptr) {
        current->data = current->data + add;
        current = current->pNext;
    }
}
//перегрузка операции ввода
istream& operator >> (istream& in, Stack& s)
{
    int size;
    cout << "Введите размер стека: ";
    in >> size;
    cout << "Введите элементы стека через Enter: ";
    for (int i = 0; i < size; i++) {
        int data;
        in >> data;
        s.push(data);
    }
    return in;
}
//перегрузка операции вывода
ostream& operator << (ostream& out, const Stack& s) {
    Node* current = s.top;
    while (current != nullptr) {
        out << current->data << " ";
        current = current->pNext;
    }
    return out;
}