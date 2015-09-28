#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>

using namespace std;

struct person{
	int ID;
	char lastName[26];
	char firstName[26];
	char address[61];
};

int fillStruct(struct person []);
void addPerson(struct person [], int );
void sortID(struct person [], int );
void printStructArray(struct person [],int );

int main()
{

	int numLines=0, counter=0;
	struct person personList[20];
	struct person MyPerson;
	
    counter=fillStruct(personList);
    setPerson(fout,personList);
	printStructArray(fout,personList,numLines);
	fclose(fp);
	fclose(fout);
	return 0;
}

int fillStruct(struct person personList)
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

void addPerson(struct person MyPerson, int* counterPtr)
{
    char ID[11];

	printf("Enter the person's ID number: ");
	gets(ID);
	MyPerson->ID=atoi(ID);
	printf("Enter the person's last name: ") ;
	gets(MyPerson->lastName);
	cout << "Enter the person's first name:";
	gets(MyPerson->firstName);
	counterPtr->++;
	
	
	
}

int addPerson(person personList[], int counter)
{
    int ask=0;
    cout << "Add a person\n";
    cout << "\n";
    cout << "Would you like to add another person? 1-Yes 0-No?\n";
    cin >> ask;
    while(ask)
    {
        cin.clear();// clear input buffer
        cin.sync();
        string tempID;
        cout << "Enter ID: ";
        getline(cin,tempID);
        personList[counter].ID = atoi(tempID.c_str());
        cout << endl << "Enter name: ";
        getline(cin,personList[counter].name);
        cout << endl << "Enter address: ";
        getline(cin,personList[counter].address);
        counter++;
        cout << "Add another person? 1-Yes 0-No? \n";
        cin >> ask;
    }
    return counter;
}

void search(person personList[], int counter, string lastname)
{
	int i;
    size_t found;
    for (int i = 0; i<counter; i++)
    {
        found = (personList[i].name).find(lastname);
        if (found!=string::npos)
        {
            cout << "\n";
            cout << "ID: "<< personList[w].ID << "\n";
            cout << "Name: "<< personList[w].name << "\n";
            cout << "Address: "<< personList[w].address << "\n\n";
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


void printStructArray(struct person personList[],int counter)
{
    int i;

    cout << "\n\tID Number\t \tFirst Name\t \tLast Name\t \tStreet Address\t");

    for(i=0;i<counter;i++)
    {

        cout << personList[i].ID;
        cout << "\t\t" << personList[i].firstName << "\t";
        cout << "\t" << personList[i].lastName;
        cout << "\t" << personList[i].address << "\n";
		
    }
}
