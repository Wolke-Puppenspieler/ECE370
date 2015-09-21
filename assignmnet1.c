#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct person{
	int ID;
	char lastName[25];
	char firstName[25];
	char address[60];
};
int fillStruct(FILE *,struct person []);
void setperson(FILE *,struct person *);
void printStructArray(FILE *,struct person [],int );
int main()
{
	FILE *fp;
	FILE *fout;
    fout=fopen("quiz13.txt","w");
	fp=fopen("MasterpersonList.txt","r");
	int numLines=0;
	struct person personList[20];
	struct person Myperson;
    numLines=fillStruct(fp,personList);
    setperson(fout,&Myperson);
	printStructArray(fout,personList,numLines);
	fclose(fp);
	fclose(fout);
	return 0;
}
int fillStruct(FILE *fp,struct person personList[20])
{
	int i=0;
	char *token;
	char year[5], rating[4], temp[100], comma[2]=",\0";

    for(i=0;i<20;i++)
    {
        //printf("error\n %d",i); - testing

        fgets(temp,sizeof(temp),fp);
		token=strtok(temp,comma);
		strcpy(personList[i].artistName,strdup(token));

        token=strtok(NULL,comma);
        strcpy(personList[i].albumName,strdup(token));

        token=strtok(NULL,comma);
        strcpy(year,strdup(token));
        personList[i].year=atoi(year);

        token=strtok(NULL,comma);
        strcpy(personList[i].genre,strdup(token));

        token=strtok(NULL,comma);
        strcpy(rating,strdup(token));
        personList[i].rating=atof(rating);

        token=strtok(NULL,comma);
        strcpy(personList[i].studentName,strdup(token));

    }

    return(i);
}

void setperson(FILE *fout,struct person *Myperson)
{
    char year[5], rating[4];
	printf("Enter the person's artist: ");
	gets(Myperson->artistName);
	printf("Enter the album name: ");
	gets(Myperson->albumName);
	printf("Enter the year the album was released: ");
	gets(year);
	Myperson->year=atoi(year);
	printf("Enter the album's genre: ");
	gets(Myperson->genre);
	printf("Enter your rating (0.0-5.0): ");
	gets(rating);
	Myperson->rating=atof(rating);
	printf("Enter your name: ");
	gets(Myperson->studentName);
	printf("%s",Myperson->artistName);
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
