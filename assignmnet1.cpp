#include <iostream>
#include <fstream>
#include<stdlib.h>
#include<string.h>

using namespace std;

struct person{
	int ID;
	char lastName[26];
	char firstName[26];
	char address[61];
};

int fillStruct(struct person []);
void addPerson(struct person []);
void sortID(struct person [], int )
void printStructArray(FILE *,struct person [],int );

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
        s[counter].ID = atoi(temp.c_str());
        getline(preDefined,personList[counter].lastName);
		getline(preDefined,personList[counter].firstName);
        getline(preDefined,personList[counter].address);
        getline(preDefined,blank);
        counter++;
    }

    preDefined.close();

    return counter;
}

void addPerson(FILE *fout,struct person MyPerson)
{
    char ID[11];

	printf("Enter the person's ID number: ");
	gets(ID);
	MyPerson->ID=atoi(ID);
	printf("Enter the person's last name: ");
	gets(MyPerson->lastName);
	printf("Enter the person's first name: ");
	gets(MyPerson->firstName);
	
}

int ADD(person s[], int Npeople)
{
    int ask=0;
    cout<<"-----------------ADD A PERSON-----------------"<<endl;
    cout <<endl;
    cout << "Would you like to add another person? 1-Yes 0-No?"<<endl;
    cin >> ask;
    while(ask)
    {
        cin.clear();// allows the program to become aligned and brings the cursor to the appropriate area on the program.
        cin.sync(); //
        string tempID;
        cout << "Enter ID: ";
        getline(cin,tempID);
        s[Npeople].ID = atoi(tempID.c_str());
        cout << endl << "Enter name: ";
        getline(cin,s[Npeople].name);
        cout << endl << "Enter address: ";
        getline(cin,s[Npeople].address);
        Npeople++;
        cout << "Would you like to add another person? 1-Yes 0-No?"<<endl;
        cin >> ask;
    }
    return Npeople;
}

void SEARCH(person s[], int Npeople, string lastname)
{
    size_t found;
    for (int w = 0; w<Npeople; w++)
    {
        found = (s[w].name).find(lastname);
        if (found!=string::npos)
        {
            cout << endl;
            cout << "ID: "<< s[w].ID << endl;
            cout << "Name: "<< s[w].name << endl;
            cout << "Address: "<< s[w].address << endl << endl;
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
        cout<<"ID Number: "<< personList[i].ID << "\n";
        cout<<"Last Name: "<< personList[i].lastName << "\n";
        cout<<"First Name: "<< personList[i].firstName << "\n";
		cout<<"Address: "<< personList[i].address << "\n\n";
    }
}


void printStructArray(FILE *fout,struct person personList[],int n)
{
    int i;

    printf("\n\tArtist\t \tAlbum\t \tYear\t \tGenre\t \tRating\t \tStudent\t");

    for(i=0;i<20;i++)
    {

        printf("%s",personList[i].artistName);
        printf("\t\t%s\t",personList[i].albumName);
        printf("\t%d",personList[i].year);
        printf("\t%s",personList[i].genre);
        printf("\t%.1f",personList[i].rating);
        printf("\t%s",personList[i].studentName);
        printf("\n");

        fprintf(fout,"%s \t",personList[i].artistName);
        fprintf(fout,"%s \t",personList[i].albumName);
        fprintf(fout,"%d \t",personList[i].year);
        fprintf(fout,"%s \t",personList[i].genre);
        fprintf(fout,"%.1f \t",personList[i].rating);
        fprintf(fout,"%s \t",personList[i].studentName);
        fprintf(fout,"\n");

    }
}
