#include <iostream>
#include <string>
using namespace std;

struct Node
{
    int patientID;
    string patientName;
    int patientAge;
    Node* next;
};

// Add patient at the end
void addPatient(Node*& head, int id, string name, int age)
{
    Node* newNode = new Node;

    newNode->patientID = id;
    newNode->patientName = name;
    newNode->patientAge = age;
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

// Add emergency patient at beginning
void addEmergencyPatient(Node*& head, int id, string name, int age)
{
    Node* newNode = new Node;

    newNode->patientID = id;
    newNode->patientName = name;
    newNode->patientAge = age;
    newNode->next = head;

    head = newNode;
}

// Search patient
void searchPatient(Node* head, int id)
{
    Node* temp = head;

    while (temp != NULL)
    {
        if (temp->patientID == id)
        {
            cout << "\nPatient Found!\n";
            cout << "ID: " << temp->patientID << endl;
            cout << "Name: " << temp->patientName << endl;
            cout << "Age: " << temp->patientAge << endl;
            return;
        }

        temp = temp->next;
    }

    cout << "\nPatient does not exist.\n";
}

// Delete patient
void removePatient(Node*& head, int id)
{
    if (head == NULL)
    {
        cout << "\nPatient does not exist.\n";
        return;
    }

    if (head->patientID == id)
    {
        Node* temp = head;
        head = head->next;
        delete temp;

        cout << "\nPatient removed successfully.\n";
        return;
    }

    Node* temp = head;

    while (temp->next != NULL)
    {
        if (temp->next->patientID == id)
        {
            Node* deleteNode = temp->next;
            temp->next = temp->next->next;

            delete deleteNode;

            cout << "\nPatient removed successfully.\n";
            return;
        }

        temp = temp->next;
    }

    cout << "\nPatient does not exist.\n";
}

// Display patients
void displayPatients(Node* head)
{
    if (head == NULL)
    {
        cout << "\nNo patients waiting.\n";
        return;
    }

    Node* temp = head;

    cout << "\nWaiting Patients:\n";

    while (temp != NULL)
    {
        cout << "ID: " << temp->patientID
             << " | Name: " << temp->patientName
             << " | Age: " << temp->patientAge << endl;

        temp = temp->next;
    }
}

int main()
{
    Node* head = NULL;

    int choice;

    do
    {
        cout << "\n===== Hospital Emergency Patient Management =====\n";
        cout << "1. Add New Patient\n";
        cout << "2. Add Emergency Patient\n";
        cout << "3. Search Patient\n";
        cout << "4. Remove Patient\n";
        cout << "5. Display All Patients\n";
        cout << "6. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            int id, age;
            string name;

            cout << "Enter Patient ID: ";
            cin >> id;

            cout << "Enter Patient Name: ";
            cin >> name;

            cout << "Enter Patient Age: ";
            cin >> age;

            addPatient(head, id, name, age);
        }
        else if (choice == 2)
        {
            int id, age;
            string name;

            cout << "Enter Emergency Patient ID: ";
            cin >> id;

            cout << "Enter Patient Name: ";
            cin >> name;

            cout << "Enter Patient Age: ";
            cin >> age;

            addEmergencyPatient(head, id, name, age);
        }
        else if (choice == 3)
        {
            int id;

            cout << "Enter Patient ID to search: ";
            cin >> id;

            searchPatient(head, id);
        }
        else if (choice == 4)
        {
            int id;

            cout << "Enter Patient ID to remove: ";
            cin >> id;

            removePatient(head, id);
        }
        else if (choice == 5)
        {
            displayPatients(head);
        }
        else if (choice == 6)
        {
            cout << "Program ended.\n";
        }
        else
        {
            cout << "Invalid choice.\n";
        }

    } while (choice != 6);

    return 0;
}
