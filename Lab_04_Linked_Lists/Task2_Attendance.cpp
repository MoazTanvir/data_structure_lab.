#include <iostream>
#include <string>
using namespace std;

struct Node
{
    int rollNumber;
    string studentName;
    string attendance;
    Node* next;
};

// Add student
void addStudent(Node*& head, int roll, string name, string status)
{
    Node* newNode = new Node;

    newNode->rollNumber = roll;
    newNode->studentName = name;
    newNode->attendance = status;
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

// Search student
void searchStudent(Node* head, int roll)
{
    Node* temp = head;

    while (temp != NULL)
    {
        if (temp->rollNumber == roll)
        {
            cout << "\nStudent Found!\n";
            cout << "Roll Number: " << temp->rollNumber << endl;
            cout << "Name: " << temp->studentName << endl;
            cout << "Attendance: " << temp->attendance << endl;
            return;
        }

        temp = temp->next;
    }

    cout << "\nStudent not found.\n";
}

// Delete student
void deleteStudent(Node*& head, int roll)
{
    if (head == NULL)
    {
        cout << "\nStudent not found.\n";
        return;
    }

    if (head->rollNumber == roll)
    {
        Node* temp = head;
        head = head->next;

        delete temp;

        cout << "\nStudent deleted successfully.\n";
        return;
    }

    Node* temp = head;

    while (temp->next != NULL)
    {
        if (temp->next->rollNumber == roll)
        {
            Node* deleteNode = temp->next;
            temp->next = temp->next->next;

            delete deleteNode;

            cout << "\nStudent deleted successfully.\n";
            return;
        }

        temp = temp->next;
    }

    cout << "\nStudent not found.\n";
}

// Display students
void displayStudents(Node* head)
{
    if (head == NULL)
    {
        cout << "\nAttendance list is empty.\n";
        return;
    }

    Node* temp = head;

    cout << "\nAttendance List:\n";

    while (temp != NULL)
    {
        cout << "Roll Number: " << temp->rollNumber
             << " | Name: " << temp->studentName
             << " | Attendance: " << temp->attendance << endl;

        temp = temp->next;
    }
}

// Count present students
int countPresent(Node* head)
{
    int count = 0;

    Node* temp = head;

    while (temp != NULL)
    {
        if (temp->attendance == "Present")
        {
            count++;
        }

        temp = temp->next;
    }

    return count;
}

int main()
{
    Node* head = NULL;

    int choice;

    do
    {
        cout << "\n===== University Attendance System =====\n";
        cout << "1. Add Student\n";
        cout << "2. Search Student\n";
        cout << "3. Delete Student\n";
        cout << "4. Display Students\n";
        cout << "5. Count Present Students\n";
        cout << "6. Display Final Attendance List\n";
        cout << "7. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            int roll;
            string name;
            string status;

            cout << "Enter Roll Number: ";
            cin >> roll;

            cout << "Enter Student Name: ";
            cin >> name;

            cout << "Enter Attendance (Present/Absent): ";
            cin >> status;

            addStudent(head, roll, name, status);
        }
        else if (choice == 2)
        {
            int roll;

            cout << "Enter Roll Number to search: ";
            cin >> roll;

            searchStudent(head, roll);
        }
        else if (choice == 3)
        {
            int roll;

            cout << "Enter Roll Number to delete: ";
            cin >> roll;

            deleteStudent(head, roll);
        }
        else if (choice == 4)
        {
            displayStudents(head);
        }
        else if (choice == 5)
        {
            cout << "\nTotal Students Present: "
                 << countPresent(head) << endl;
        }
        else if (choice == 6)
        {
            displayStudents(head);
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
