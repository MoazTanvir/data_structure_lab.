#include <iostream>
#include <string>
using namespace std;

struct Node
{
    string courseCode;
    string courseName;
    int creditHours;
    Node* next;
};

// Add course at beginning
void addAtBeginning(Node*& head, string code, string name, int credit)
{
    Node* newNode = new Node;

    newNode->courseCode = code;
    newNode->courseName = name;
    newNode->creditHours = credit;
    newNode->next = head;

    head = newNode;
}

// Add course at end
void addAtEnd(Node*& head, string code, string name, int credit)
{
    Node* newNode = new Node;

    newNode->courseCode = code;
    newNode->courseName = name;
    newNode->creditHours = credit;
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

// Search course
void searchCourse(Node* head, string code)
{
    Node* temp = head;

    while (temp != NULL)
    {
        if (temp->courseCode == code)
        {
            cout << "\nCourse Found!\n";
            cout << "Course Code: " << temp->courseCode << endl;
            cout << "Course Name: " << temp->courseName << endl;
            cout << "Credit Hours: " << temp->creditHours << endl;
            return;
        }

        temp = temp->next;
    }

    cout << "\nCourse not found.\n";
}

// Delete course
void deleteCourse(Node*& head, string code)
{
    if (head == NULL)
    {
        cout << "\nCourse not found.\n";
        return;
    }

    if (head->courseCode == code)
    {
        Node* temp = head;
        head = head->next;

        delete temp;

        cout << "\nCourse deleted successfully.\n";
        return;
    }

    Node* temp = head;

    while (temp->next != NULL)
    {
        if (temp->next->courseCode == code)
        {
            Node* deleteNode = temp->next;

            temp->next = temp->next->next;

            delete deleteNode;

            cout << "\nCourse deleted successfully.\n";
            return;
        }

        temp = temp->next;
    }

    cout << "\nCourse not found.\n";
}

// Display courses
void displayCourses(Node* head)
{
    if (head == NULL)
    {
        cout << "\nNo courses available.\n";
        return;
    }

    Node* temp = head;

    cout << "\nCourse List:\n";

    while (temp != NULL)
    {
        cout << temp->courseCode
             << " | " << temp->courseName
             << " | Credit Hours: " << temp->creditHours
             << endl;

        temp = temp->next;
    }
}

// Count courses
int countCourses(Node* head)
{
    int count = 0;

    Node* temp = head;

    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    return count;
}

// Concatenate second list with first list
void concatenate(Node*& head1, Node* head2)
{
    if (head1 == NULL)
    {
        head1 = head2;
        return;
    }

    Node* temp = head1;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = head2;
}

int main()
{
    Node* morning = NULL;
    Node* evening = NULL;

    int choice;
    int listChoice;

    do
    {
        cout << "\n===== University Course Management =====\n";
        cout << "1. Add Course at Beginning\n";
        cout << "2. Add Course at End\n";
        cout << "3. Search Course\n";
        cout << "4. Delete Course\n";
        cout << "5. Display All Courses\n";
        cout << "6. Count Total Courses\n";
        cout << "7. Concatenate Evening List\n";
        cout << "8. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            string code, name;
            int credit;

            cout << "Enter 1 for Morning, 2 for Evening: ";
            cin >> listChoice;

            cout << "Enter Course Code: ";
            cin >> code;

            cout << "Enter Course Name: ";
            cin >> name;

            cout << "Enter Credit Hours: ";
            cin >> credit;

            if (listChoice == 1)
            {
                addAtBeginning(morning, code, name, credit);
            }
            else
            {
                addAtBeginning(evening, code, name, credit);
            }
        }
        else if (choice == 2)
        {
            string code, name;
            int credit;

            cout << "Enter 1 for Morning, 2 for Evening: ";
            cin >> listChoice;

            cout << "Enter Course Code: ";
            cin >> code;

            cout << "Enter Course Name: ";
            cin >> name;

            cout << "Enter Credit Hours: ";
            cin >> credit;

            if (listChoice == 1)
            {
                addAtEnd(morning, code, name, credit);
            }
            else
            {
                addAtEnd(evening, code, name, credit);
            }
        }
        else if (choice == 3)
        {
            string code;

            cout << "Enter Course Code to search: ";
            cin >> code;

            cout << "\nSearching Morning Courses:\n";
            searchCourse(morning, code);

            cout << "\nSearching Evening Courses:\n";
            searchCourse(evening, code);
        }
        else if (choice == 4)
        {
            string code;

            cout << "Enter Course Code to delete: ";
            cin >> code;

            deleteCourse(morning, code);
            deleteCourse(evening, code);
        }
        else if (choice == 5)
        {
            cout << "\nMorning Courses:\n";
            displayCourses(morning);

            cout << "\nEvening Courses:\n";
            displayCourses(evening);
        }
        else if (choice == 6)
        {
            cout << "\nMorning Courses: "
                 << countCourses(morning) << endl;

            cout << "Evening Courses: "
                 << countCourses(evening) << endl;

            cout << "Total Courses: "
                 << countCourses(morning) + countCourses(evening)
                 << endl;
        }
        else if (choice == 7)
        {
            concatenate(morning, evening);

            evening = NULL;

            cout << "\nLists concatenated successfully.\n";

            cout << "\nCombined Course List:\n";
            displayCourses(morning);
        }
        else if (choice == 8)
        {
            cout << "Program ended.\n";
        }
        else
        {
            cout << "Invalid choice.\n";
        }

    } while (choice != 8);

    return 0;
}
