#include <iostream>
#include <vector>

class Node {
public:
    int key;
    Node* p;
};

class Stack {
private:
    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }

    bool isEmpty() {
        return top == nullptr;
    }

    void push(int value) {
        Node* newNode = new Node;
        newNode->key = value;
        newNode->p = top;
        top = newNode;
    }

    void pop() {
        if (!isEmpty()) {
            Node* temp = top;
            top = top->p;
            std::cout << "Popped element: " << temp->key << std::endl;
            delete temp;
        }
        else {
            std::cout << "Stack is empty." << std::endl;
        }
    }

    void remove() {
        while (!isEmpty()) {
            pop();
        }
        std::cout << "Stack removed." << std::endl;
    }

    void copy(Stack& otherStack) {
        Node* temp = top;
        while (temp != nullptr) {
            otherStack.push(temp->key);
            temp = temp->p;
        }
        std::cout << "Stack copied." << std::endl;
    }

    int length() {
        int count = 0;
        Node* temp = top;
        while (temp != nullptr) {
            count++;
            temp = temp->p;
        }
        return count;
    }

    void print() {
        Node* temp = top;
        while (temp != nullptr) {
            std::cout << temp->key << " ";
            temp = temp->p;
        }
        std::cout << std::endl;
    }
};

int main() {
    setlocale(LC_ALL, "RU");
    Stack myStack;

    while (true) {
        std::cout << "Выберите операцию:\n";
        std::cout << "1. Добавить элемент (push)\n";
        std::cout << "2. Удалить элемент и вывести на экран (pop)\n";
        std::cout << "3. Удалить весь стек (remove)\n";
        std::cout << "4. Вывести информацию о длине стека\n";
        std::cout << "5. Вывести стек в терминал (print)\n";
        std::cout << "6. Копировать стек в новый объект\n";
        std::cout << "7. Выйти из программы\n";

        int choice;
        std::cin >> choice;

        if (choice == 1) {
            int element;
            std::cout << "Введите элемент: ";
            std::cin >> element;
            myStack.push(element);
            std::cout << "Элемент добавлен." << std::endl;

        }
        else if (choice == 2) {
            myStack.pop();

        }
        else if (choice == 3) {
            myStack.remove();

        }
        else if (choice == 4) {
            std::cout << "Длина стека: " << myStack.length() << std::endl;

        }
        else if (choice == 5) {
            std::cout << "Содержимое стека: ";
            myStack.print();

        }
        else if (choice == 6) {
            Stack newStack;
            myStack.copy(newStack);
            std::cout << "Новый стек создан." << std::endl;

        }
        else if (choice == 7) {
            break;

        }
        else {
            std::cout << "Неверный выбор. Пожалуйста, попробуйте еще раз." << std::endl;
        }
    }

    return 0;
}