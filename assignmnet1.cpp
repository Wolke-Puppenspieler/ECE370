#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>

using namespace std;

struct person{
	int ID;
	string lastName;
	string firstName;
	string address;
};

int fillStruct(struct person []);
int addPerson(struct person [], int );
void sortID(struct person [], int );
void searchList(struct person []);
void printArray(struct person [],int );

int main()
{

	int counter=0;
	char selection;
	struct person personList[20];
	struct person MyPerson;

	 counter=fillStruct(personList);

    //display menu

    cout << "Please make your selection:\n";
    cout << "Add person: A\t" << "Search list: S\t" << "Print list: P\t" << "Quit: Q\n\n";

	switch(selection)
    {

        case 'A':case 'a':
        {
            system("cls");
            addPerson(personList, counter);

        }
        break;
        case 'S':case 's':
        {

            searchList(personList);

        }
        break;
        case 'P':case 'p':
        {

            printArray(personList, counter);

        }
        break;
        case 'Q':case 'q':
        {

            return 0;

        }


    }

	return 0;
}

int fillStruct(struct person personList[])
{
	ifstream preDefined;
	preDefined.open("a1.txt");

	cout << "Opened file\n Begin data parse\n";

    int counter=0;

	while(preDefined.peek()!=EOF)
    {

        string temp, blank;
        getline(preDefined,temp);
        personList[counter].ID = atoi(temp.c_str());
        getline(preDefined,personList[counter].lastName);
		getline(preDefined,personList[counter].firstName);
        getline(preDefined,personList[counter].address);
        getline(preDefined,blank);
        counter++;

    }

    preDefined.close();

    return counter;
}


int addPerson(person personList[], int counter)
{
    int response=0;
    cout << "Add a person\n";
    cout << "\n";
    cout << "Would you like to add a person? Yes: 1 No: 0\n";
    cin >> response;

    while(response)
    {

        cin.clear();
        cin.sync();
        string tempID;

		cout << "Input ID: ";
        getline(cin,tempID);
		personList[counter].ID = atoi(tempID.c_str());

		cout  << "\nInput last name: ";
		getline(cin,personList[counter].lastName);

		cout  << "\nInput first name: ";
        getline(cin,personList[counter].firstName);

        cout << "\nInput address: ";
        getline(cin,personList[counter].address);

		counter++;

		cout << "\nAdd another person? Yes: 1 No: 0\n";
        cin >> response;

    }
    return counter;
}

void searchLast(person personList[], int counter)
{
	int i;
    size_t found;
    for (int i = 0; i<counter; i++)
    {
        cout << "Enter F to search by first name\nEnter L to search by last name\nEnter I to search by ID #";
        switch(query)

        found = (personList[i].lastName).find(lastname);
        if (found!=string::npos)
        {
            cout << "\n";
            cout << "ID: " << personList[i].ID << "\n";
            cout << "Last Name: " << personList[i].lastName << "\n";
            cout << "First Name: " << personList[i].firstName << "\n";
            cout << "Address: " << personList[i].address << "\n\n";
        }
    }
}

void searchFirst(person personList[], int counter)
{
	int i;
    size_t found;
    for (int i = 0; i<counter; i++)
    {
        found = (personList[i].lastName).find(lastname);
        if (found!=string::npos)
        {
            cout << "\n";
            cout << "ID: " << personList[i].ID << "\n";
            cout << "Last Name: " << personList[i].lastName << "\n";
            cout << "First Name: " << personList[i].firstName << "\n";
            cout << "Address: " << personList[i].address << "\n\n";
        }
    }
}

void searchID(person personList[], int counter)
{
	int i;
    size_t found;
    for (int i = 0; i<counter; i++)
    {
        found = (personList[i].lastName).find(lastname);
        if (found!=string::npos)
        {
            cout << "\n";
            cout << "ID: " << personList[i].ID << "\n";
            cout << "Last Name: " << personList[i].lastName << "\n";
            cout << "First Name: " << personList[i].firstName << "\n";
            cout << "Address: " << personList[i].address << "\n\n";
        }
    }
}

void sortID(struct person personList[], int counter)
{
	struct person temp;

	int i, j;

	for(i=0; i<counter; i++)
    {
        for(j=0; j<counter-1; j++)
        {
            if(personList[j].ID>personList[j+1].ID)
            {
                temp=personList[j+1];
                personList[j+1]=personList[j];
                personList[j]=temp;
            }
        }
    }

    for(i=0; i<counter; i++)
    {

        cout << "ID Number: " << personList[i].ID << "\n";
        cout << "Last Name: " << personList[i].lastName << "\n";
        cout << "First Name: " << personList[i].firstName << "\n";
		cout << "Address: " << personList[i].address << "\n\n";

	}
}


void printArray(struct person personList[],int counter)
{
    int i;

    cout << "\n\tID Number\t \tFirst Name\t \tLast Name\t \tStreet Address\t";

    for(i=0;i<counter;i++)
    {

        cout << personList[i].ID;
        cout << "\t\t" << personList[i].firstName << "\t";
        cout << "\t" << personList[i].lastName;
        cout << "\t" << personList[i].address << "\n";

    }
}
