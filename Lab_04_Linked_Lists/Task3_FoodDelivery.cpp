#include <iostream>
#include <string>
using namespace std;

struct Node
{
    string orderID;
    string customerName;
    string foodItem;
    Node* next;
};

// Add order at end
void addOrder(Node*& head, string id, string customer, string food)
{
    Node* newNode = new Node;

    newNode->orderID = id;
    newNode->customerName = customer;
    newNode->foodItem = food;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node* temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

// Add urgent order at beginning
void addUrgentOrder(Node*& head, string id, string customer, string food)
{
    Node* newNode = new Node;

    newNode->orderID = id;
    newNode->customerName = customer;
    newNode->foodItem = food;

    newNode->next = head;

    head = newNode;
}

// Display orders
void displayOrders(Node* head)
{
    if (head == NULL)
    {
        cout << "\nNo pending orders.\n";
        return;
    }

    Node* temp = head;

    cout << "\nPending Orders:\n";

    while (temp != NULL)
    {
        cout << temp->orderID
             << " | Customer: " << temp->customerName
             << " | Food: " << temp->foodItem << endl;

        temp = temp->next;
    }
}

// Search order
void searchOrder(Node* head, string id)
{
    Node* temp = head;

    while (temp != NULL)
    {
        if (temp->orderID == id)
        {
            cout << "\nOrder Found!\n";
            cout << "Order ID: " << temp->orderID << endl;
            cout << "Customer: " << temp->customerName << endl;
            cout << "Food: " << temp->foodItem << endl;
            return;
        }

        temp = temp->next;
    }

    cout << "\nOrder does not exist.\n";
}

// Remove order
void removeOrder(Node*& head, string id)
{
    if (head == NULL)
    {
        cout << "\nOrder does not exist.\n";
        return;
    }

    if (head->orderID == id)
    {
        Node* temp = head;
        head = head->next;

        delete temp;

        cout << "\nOrder delivered and removed.\n";
        return;
    }

    Node* temp = head;

    while (temp->next != NULL)
    {
        if (temp->next->orderID == id)
        {
            Node* deleteNode = temp->next;

            temp->next = temp->next->next;

            delete deleteNode;

            cout << "\nOrder delivered and removed.\n";
            return;
        }

        temp = temp->next;
    }

    cout << "\nOrder does not exist.\n";
}

int main()
{
    Node* head = NULL;

    int choice;

    do
    {
        cout << "\n===== Online Food Delivery System =====\n";
        cout << "1. Add New Order\n";
        cout << "2. Display Pending Orders\n";
        cout << "3. Search Order\n";
        cout << "4. Remove Delivered Order\n";
        cout << "5. Add Urgent Order\n";
        cout << "6. Display Updated List\n";
        cout << "7. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            string id, customer, food;

            cout << "Enter Order ID: ";
            cin >> id;

            cout << "Enter Customer Name: ";
            cin >> customer;

            cout << "Enter Food Item: ";
            cin >> food;

            addOrder(head, id, customer, food);
        }
        else if (choice == 2)
        {
            displayOrders(head);
        }
        else if (choice == 3)
        {
            string id;

            cout << "Enter Order ID to search: ";
            cin >> id;

            searchOrder(head, id);
        }
        else if (choice == 4)
        {
            string id;

            cout << "Enter Order ID to remove: ";
            cin >> id;

            removeOrder(head, id);
        }
        else if (choice == 5)
        {
            string id, customer, food;

            cout << "Enter Urgent Order ID: ";
            cin >> id;

            cout << "Enter Customer Name: ";
            cin >> customer;

            cout << "Enter Food Item: ";
            cin >> food;

            addUrgentOrder(head, id, customer, food);
        }
        else if (choice == 6)
        {
            displayOrders(head);
        }
        else if (choice == 7)
        {
            cout << "Program ended.\n";
        }
        else
        {
            cout << "Invalid choice.\n";
        }

    } while (choice != 7);

    return 0;
}
