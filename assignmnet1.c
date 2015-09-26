#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct person{
	int ID;
	char lastName[26];
	char firstName[26];
	char address[61];
};
int fillStruct(FILE *,struct person []);
void addPerson(FILE *,struct person []);
void printStructArray(FILE *,struct person [],int );
int main()
{
	FILE *fp;
	FILE *fout;
    fout=fopen("Assignment1.txt","w");
	fp=fopen("a1.txt","r");
	int numLines=0, numEntries=0;
	struct person personList;
	struct person MyPerson;
	
	printf("How many people are in the file?");
	scanf("%d",&numEntries);
    numLines=fillStruct(fp,personList);
    setPerson(fout,personList);
	printStructArray(fout,personList,numLines);
	fclose(fp);
	fclose(fout);
	return 0;
}
int fillStruct(FILE *fp,struct person personList, numEntries)
{
	int i=0;
	char *token;
	char temp[100], comma[2]=",\0";

    for(i=0;i<numEntries;i++)
    {
        //printf("error\n %d",i); - testing

        fgets(temp,sizeof(temp),fp);

        token=strtok(NULL,comma);
        strcpy(ID,strdup(token));
        personList[i]->ID=atoi(ID);

		token=strtok(temp,comma);
		strcpy(personList[i]->lastName,strdup(token));

        token=strtok(NULL,comma);
        strcpy(personList[i]->firstName,strdup(token));

        token=strtok(NULL,comma);
        strcpy(personList[i]->address,strdup(token));

    }

    return(i);
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
