#include <iostream>
#include <string>
using namespace std;

class Item
{
protected:
    int id;
    string name;
    string description;
    string location;
    string date;
    string status;

public:
    Item() {}

    Item(int i, string n, string d, string l, string dt, string s)
    {
        id = i;
        name = n;
        description = d;
        location = l;
        date = dt;
        status = s;
    }

    virtual void input()
    {
        cout << "Enter ID: ";
        cin >> id;
        cin.ignore();

        cout << "Enter Item Name: ";
        getline(cin, name);

        cout << "Enter Description: ";
        getline(cin, description);

        cout << "Enter Location: ";
        getline(cin, location);

        cout << "Enter Date: ";
        getline(cin, date);
    }

    virtual void display()
    {
        cout << "\nID: " << id;
        cout << "\nName: " << name;
        cout << "\nDescription: " << description;
        cout << "\nLocation: " << location;
        cout << "\nDate: " << date;
        cout << "\nStatus: " << status << endl;
    }

   
    bool operator==(Item &obj)
    {
        return (name == obj.name && location == obj.location);
    }

    friend void showStatus(Item &obj);
};


void showStatus(Item &obj)
{
    cout << "\n[Friend Function] Item Status: " << obj.status << endl;
}


class LostItem : public Item
{
public:
    void input()
    {
        Item::input();
        status = "Lost";
    }
};

class FoundItem : public Item
{
public:
    void input()
    {
        Item::input();
        status = "Found";
    }
};

int main()
{
    Item *items[10];   
    int count = 0;
    int choice;

    do
    {
        cout << "\n===== LOST & FOUND PORTAL =====";
        cout << "\n1. Add Lost Item";
        cout << "\n2. Add Found Item";
        cout << "\n3. Display All Items";
        cout << "\n4. Compare Two Items";
        cout << "\n5. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            items[count] = new LostItem();
            items[count]->input();
            count++;
        }
        else if (choice == 2)
        {
            items[count] = new FoundItem();
            items[count]->input();
            count++;
        }
        else if (choice == 3)
        {
            for (int i = 0; i < count; i++)
            {
                items[i]->display();
                showStatus(*items[i]);
            }
        }
        else if (choice == 4)
        {
            if (count >= 2)
            {
                if (*items[0] == *items[1])
                    cout << "Items Match (Same Name & Location)";
                else
                    cout << "Items Do Not Match";
            }
            else
            {
                cout << "Not enough items to compare.";
            }
        }
        else if (choice == 5)
        {
            cout << "Exiting Program...";
        }
        else
        {
            cout << "Invalid Choice!";
        }

    } while (choice != 5);

    return 0;
}
