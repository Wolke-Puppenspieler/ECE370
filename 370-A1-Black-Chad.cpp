#include <iostream> //file header - provides cout/cin functionality
#include <fstream> // code that provides access to reading and writing from files defined w/ cout/cin
#include <string.h> //accesses string
#include <stdlib.h>

using namespace std;

struct person
{
    int ID;
	string lastName;
    string firstName;
    string address;
};

int populateList(person s[])
{
    ifstream inData;
    inData.open("a1.txt");

    if(!inData) //checks the file to see if correct..//
    {
        cout<<"File could not be found"<<endl;
    }

    cout<<endl<<"Hello there, Welcome to Assignment 1."<<endl;
    cout<<endl<<endl;
    int Npeople=0;
    while(inData.peek()!=EOF)
    {
        string temp, blank;
        getline(inData,temp);
        s[Npeople].ID = atoi(temp.c_str());
        getline(inData,s[Npeople].lastName);
		getline(inData,s[Npeople].firstName);
        getline(inData,s[Npeople].address);
        getline(inData,blank);
        Npeople++;
    }
    inData.close();
    return Npeople;
}

/*void BSORT_ID(person s[],int Npeople)
{
    person temp;
    int x, y;
    cout << "These are the ID Numbers of the people in Ascending order... " <<endl;
    cout <<endl;
    for(x=0; x<Npeople; x++)
    {
        for(y=0; y<Npeople-1; y++)
        {
            if(s[y].ID>s[y+1].ID)
            {
                temp=s[y+1];
                s[y+1]=s[y];
                s[y]=temp;
            }
        }
    }
    for(x=0; x<Npeople; x++)
    {
        cout<<"ID Number: "<<s[x].ID <<endl;
        cout<<"Name: "<<s[x].name <<endl;
        cout<<"Address: "<< s[x].address << endl;
        cout<<endl;
    }
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
*/
int main()
{
    //s represents g through the function//
    int Npeople;
    bool ask;
    person g[20];
    Npeople=READ(g);
    system("pause");
//    BSORT_ID(g, Npeople);
    //Npeople = ADD(g, Npeople);
    cout<<endl;
    cout<<"-----------------SEARCH A PERSON--------------"<<endl;
    cout << endl;
    cout << "Search for a person? 1-Yes 0-No "<<endl;
    cin >> ask;
    string lastname;
    string lastSearch[100]; // array created to store searched people
    int lastcounter = 0;
    while (ask)
    {
        cout<<"Enter Last Name: "<<endl;
        cin>>lastname;
        lastSearch[lastcounter]=lastname; // creates another array that I can store the people that have been searched.
        cin.clear();// allows the program to become aligned and brings the cursor to the appropriate area on the program.
        cin.sync();
        //SEARCH(g, Npeople,lastname);
        cout << "Search for another person? 1-Yes 0-No"<<endl;
        cin >> ask;
        lastcounter++;
    }
    cout<<endl<<"These are the people you have searched for..."<<endl<<endl;
    for (int i = 0; i < lastcounter; i++)
    {
        string temp;
        temp = lastSearch[i];
        //SEARCH(g,Npeople,temp);
    }
    cout<<endl;
    cout<<"End of Program...."<<endl;
    system("pause");
    return 0;
}
