#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <cctype>
#include <cmath>
#include <stack>
#include <queue>
using namespace std;

struct Node
{
    int Value;
    Node *Next;
    Node *Prev;
    Node(int v) : Value(v), Next(nullptr), Prev(nullptr) {}
};

class LinkedList
{
private:
    Node *Head;
    Node *Tail;
    Node *Current;
    Node *prev;
    Node *Top; // هستخدمها للـStack

public:
    LinkedList() : Head(nullptr), Tail(nullptr), Current(nullptr), prev(nullptr), Top(nullptr) {}

    //! ==================== [ Linked List ] ====================
    void insert_value(int Value)
    {
        Node *Node_1 = new Node(Value);
        if (Head == nullptr)
        {
            Head = Tail = Node_1;
        }
        else
        {
            Tail->Next = Node_1;
            Node_1->Prev = Tail;
            Tail = Node_1;
        }
    }

    void insert_numbers()
    {
        int n, value;
        cout << "-> How many numbers you want to insert ❓: ";
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cout << "Enter number " << i << ": ";
            cin >> value;
            insert_value(value);
        }
    }

    void insert_value_beginning(int Value)
    {
        Node *Node_2 = new Node(Value);
        if (Head == nullptr)
        {
            Head = Tail = Node_2;
        }
        else
        {
            Node_2->Next = Head;
            Head->Prev = Node_2;
            Head = Node_2;
        }
    }

    void display_info_insert_beginning_value()
    {
        int nu;
        cout << "Enter value to insert at beginning: ";
        cin >> nu;
        insert_value_beginning(nu);
    }

    void display()
    {
        if (Head == nullptr)
        {
            cout << "List is empty.\n";
            return;
        }
        Current = Head;
        cout << "Linked List (Head ➡ Tail):\n";
        while (Current != nullptr)
        {
            cout << " [ " << Current->Value << " ] ";
            if (Current->Next) cout << "➡ ";
            Current = Current->Next;
        }
        cout << " NULL\n";
    }

    void ReversDisplay()
    {
        Node *temp = Tail;
        if (Head == nullptr)
        {
            cout << "List is empty.\n";
            return;
        }
        cout << "Linked List (Tail ➡ Head):\n";
        while (temp != nullptr)
        {
            cout << " [ " << temp->Value << " ] ";
            if (temp->Prev) cout << "⬅ ";
            temp = temp->Prev;
        }
        cout << " NULL\n";
    }

    void DeleteFirstNode()
    {
        if (Head == nullptr)
        {
            cout << "List is empty\n";
            return;
        }
        Node *first_node = Head;
        Head = Head->Next;
        if (Head == nullptr)
            Tail = nullptr;
        else
            Head->Prev = nullptr;
        delete first_node;
    }

    void delete_node(int Value)
    {
        if (Head == nullptr)
        {
            cout << "List is empty\n";
            return;
        }

        Current = Head;

        // لو أول نود هي اللي هتتمسح
        if (Current->Value == Value)
        {
            Head = Current->Next;
            if (Head != nullptr)
                Head->Prev = nullptr;
            else
                Tail = nullptr; // لو كانت آخر واحدة
            delete Current;
            return;
        }

        // ندور على النود
        while (Current != nullptr && Current->Value != Value)
        {
            Current = Current->Next;
        }

        if (Current == nullptr)
        {
            cout << "Value not found\n";
            return;
        }

        // ربط النود اللي قبل واللي بعد
        if (Current->Prev) Current->Prev->Next = Current->Next;
        if (Current->Next) Current->Next->Prev = Current->Prev;

        if (Current == Tail) Tail = Current->Prev;

        delete Current;
    }

    void Enter_value_to_delete()
    {
        int nu;
        cout << "Enter value to delete: ";
        cin >> nu;
        delete_node(nu);
    }

    void delete_last_node()
    {
        if (Tail == nullptr)
        {
            cout << "List is empty\n";
            return;
        }
        if (Head == Tail)
        {
            delete Tail;
            Head = Tail = nullptr;
            return;
        }
        Node *last_node = Tail;
        Tail = Tail->Prev;
        Tail->Next = nullptr;
        delete last_node;
    }

    //! ==================== [ Stack Using LinkedList ] ====================
    void push(int Value)
    {
        Node *Node1 = new Node(Value);
        Node1->Next = Top;
        Top = Node1;
    }

    void EnterValuePush()
    {
        int nu, Value;
        cout << "-> How many numbers you want to push ❓: ";
        cin >> nu;
        for (int i = 1; i <= nu; i++)
        {
            cout << "Enter value " << i << ": ";
            cin >> Value;
            push(Value);
        }
    }

    int pop()
    {
        if (Top == nullptr)
        {
            cout << "Stack underflow\n";
            return -1;
        }
        Node *firstNode = Top;
        int value = firstNode->Value;
        Top = firstNode->Next;
        delete firstNode;
        return value;
    }

    void peek()
    {
        if (Top == nullptr)
        {
            cout << "Stack is Empty \n";
        }
        else
        {
            cout << "The peek is ->  " << Top->Value << endl;
        }
    }

    void Display()
    {
        if (Top == nullptr)
        {
            cout << "Stack is Empty \n";
        }
        else
        {
            Current = Top;
            cout << "Stack (Top ➡ Bottom):\n";
            while (Current != nullptr)
            {
                cout << " [ " << Current->Value << " ] ";
                if (Current->Next) cout << "➡ ";
                Current = Current->Next;
            }
            cout << " NULL\n";
        }
    }

    //! ==================== [ Menu ] ====================
    void menu()
    {
        bool running = true;
        while (running)
        {
            int choice;
            cout << "\nChoose operation:\n";
            cout << "1. Insert values\n";
            cout << "2. Insert at beginning\n";
            cout << "3. Delete beginning\n";
            cout << "4. Delete node by value\n";
            cout << "5. Delete end node\n";
            cout << "6. Display list\n";
            cout << "7. Revers Display list\n";
            cout << "============ Stack ==============\n";
            cout << "8. Push Value  \n";
            cout << "9. Pop Value   \n";
            cout << "10. Peek Value \n";
            cout << "11. Display Stack\n";
            cout << "==================================\n";
            cout << "0. Exit\n";
            cout << "===================================\n";
            cout << "Your choice: ";
            cin >> choice;

            switch (choice)
            {
            case 1: insert_numbers(); break;
            case 2: display_info_insert_beginning_value(); break;
            case 3: DeleteFirstNode(); break;
            case 4: Enter_value_to_delete(); break;
            case 5: delete_last_node(); break;
            case 6: display(); break;
            case 7: ReversDisplay(); break;
            case 8: EnterValuePush(); break;
            case 9: cout << "Popped: " << pop() << endl; break;
            case 10: peek(); break;
            case 11: Display(); break;
            case 0: running = false; break;
            default: cout << "Invalid choice!\n";
            }
        }

        cout << "  ======= Program ended ======= .\n";
    }

    ~LinkedList()
    {
        // delete list
        while (Head != nullptr)
        {
            Node *temp = Head;
            Head = Head->Next;
            delete temp;
        }
        // delete stack
        while (Top != nullptr)
        {
            Node *temp = Top;
            Top = Top->Next;
            delete temp;
        }
    }
};

int main()
{
    cout << "=====================================\n";
    cout << "========= The Linked List ============\n";
    cout << "=====================================\n";
    LinkedList li;
    li.menu();
    return 0;
}
