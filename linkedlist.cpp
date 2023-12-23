#include<iostream>
#include<string>
using namespace std;

struct node   
{
    string name;
    string discipline;
    int rollNo;
    char section;
    node *next;
}*head = nullptr, *lastptr = nullptr;

void add()    
{
    node *p = new node;
    cout << "Enter name of student:" << endl;
    cin.ignore(); // Clear any previous newline characters in the input buffer
    getline(cin, p->name);
    
    cout << "Enter discipline of student:" << endl;
    getline(cin, p->discipline);

    cout << "Enter Roll Number of student:" << endl;
    cin >> p->rollNo;

    cout << "Enter section of student:" << endl;
    cin >> p->section;
    
    p->next = nullptr;

    if (!head)
    {
        head = p;
        lastptr = p;
    }
    else
    {
        lastptr->next = p;
        lastptr = p;
    }

    cout << endl << "Record Entered" << endl;
}

void modify()   
{
    int roll_no;
    cout << "Enter Roll Number to search:" << endl;
    cin >> roll_no;
    
    node *current = head;

    while (current)
    {
        if (current->rollNo == roll_no)
        {
            cout << "Enter new name of student:" << endl;
            cin.ignore();
            getline(cin, current->name);
            
            cout << "Enter new discipline of student:" << endl;
            getline(cin, current->discipline);
            
            cout << "Enter new Roll Number of student:" << endl;
            cin >> current->rollNo;
            
            cout << "Enter new section of student:" << endl;
            cin >> current->section;
            
            cout << endl << "Record Modified" << endl;
            return;
        }
        current = current->next;
    }

    cout << "Record not found." << endl;
}

void search()   
{
    int roll_no;
    cout << "Enter Roll Number to search:" << endl;
    cin >> roll_no;
    
    node *current = head;

    while (current)
    {
        if (current->rollNo == roll_no)
        {
            cout << "Name: " << current->name << endl;
            cout << "Roll No: " << current->rollNo << endl;
            cout << "Discipline: " << current->discipline << endl;
            cout << "Section: " << current->section << endl;
            return;
        }
        current = current->next;
    }

    cout << "Record not found." << endl;
}

void del()    
{
    int roll_no;
    cout << "Enter Roll Number to Delete:" << endl;
    cin >> roll_no;
    
    node *prev = nullptr;
    node *current = head;

    while (current)
    {
        if (current->rollNo == roll_no)
        {
            if (prev)
                prev->next = current->next;
            else
                head = current->next;

            delete current;
            cout << endl << "Record Deleted" << endl;
            return;
        }
        prev = current;
        current = current->next;
    }

    cout << "Record not found." << endl;
}

int main()
{
    char x;
    cout << "\t\t *********** \t\t\t" << endl;
    cout << "\t\t *STUDENT MANAGEMENT SYSTEM* \t\t\t" << endl;
    cout << "\t\t *********** \t\t\t" << endl;
    cout << "\n\nPress Any Key To Continue . . . ." << endl;
    cin.ignore(); // Clear any newline character from the previous input
    cin.get();

    do
    {
        system("cls");
        cout << "1--->Press '1' to add New record:" << endl;
        cout << "2--->Press '2' to search a record:" << endl;
        cout << "3--->Press '3' to modify a record:" << endl;
        cout << "4--->Press '4' to delete a record:" << endl;
        cout << "5--->Press '5' to exit:" << endl;
        x = cin.get();
        cin.ignore(); // Clear any newline character from the previous input

        switch (x)
        {
            case '1':
                system("cls");
                add();
                break;
            case '2':
                system("cls");
                search();
                break;
            case '3':
                system("cls");
                modify();
                break;
            case '4':
                system("cls");
                del();
                break;
            case '5':
                exit(0);
                break;
            default:
                break;
        }
    } while (x != '5');

    return 0;
}