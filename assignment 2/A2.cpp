//********************************
//*****Brian Azar*****************
//*****ASSIGNMENT 2***************
//*****ECE 370 *******************


#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <math.h>

//assume there are no more than 50 characters if using an array//
using namespace std;

//global sum variable
float sum = 0;

struct cNode
{
    char infix;
    cNode *next;
};

struct eNode
{
    float eval;
    eNode *next;
};

void empty(cNode *&Node1)
{
    Node1 -> infix = NULL;
    Node1 -> next = NULL;
}

int isempty(cNode *Node1)
{
    if((Node1->infix == NULL)&&(Node1->next==NULL))
        return 1;
    else
        return 0;
}

void empty(eNode *&Node2)
{
    Node2->eval=NULL;
    Node2->next=NULL;
}

int isempty(eNode *Node2)
{
    if((Node2->eval == NULL)&&(Node2->next ==NULL))
        return 1;
    else
        return 0;
}
void PUSHFUNCTION(char infix, cNode *&nTop)
{
    cNode *temp1;
    temp1 = new cNode;
    temp1-> infix = infix;
    temp1-> next = nTop;
    nTop = temp1;
}

char POPFUNCTION(cNode *&aTop)
{
    char infix = aTop -> infix;
    cNode *old_aTop = aTop;
    aTop = old_aTop -> next;
    delete  old_aTop;
    return infix;
}

void PUSHFUNCTION2(float eval, eNode *&nTop)
{
    eNode *temp2;
    temp2 = new eNode;
    temp2 -> eval = eval;
    temp2 -> next = nTop;
    nTop = temp2;
}

char POPFUNCTION2(eNode *&aTop)
{
    float eval = aTop -> eval;
    eNode *old_aTop = aTop;
    aTop = old_aTop -> next;
    delete old_aTop;
    return eval;
}

float FloatConversion(char y)
{
    float number = atof(&y);
    return number;
}

void enqueue(char infix, cNode *&QueueRear, cNode *&QueueFront)
{
    /*cNode *temp3;
    temp3 = new cNode;
    temp3->infix = infix;
    temp3->next = NULL;
    QueueRear->next = temp3;
    QueueRear = temp3;*/

    cNode *temp3;
    temp3 = new cNode;
    temp3-> infix = infix;
    temp3-> next = NULL;
    if(isempty(QueueRear) == 1 && isempty(QueueFront) == 1)
    {
        QueueRear = temp3;
        QueueFront = temp3;
    }
    else
    {
        QueueRear->next = temp3;
        QueueRear = temp3;
    }
}

float dequeue(cNode *&QueueFront)
{
    char infix = QueueFront -> infix;
    cNode *old_QueueFront = QueueFront;
    QueueFront = old_QueueFront -> next;
    delete old_QueueFront;
    return infix;
}
int precedence(char v)
{
    if ((v == '(')||(v == ')'))
        return 0;
    if ((v == '+') || (v == '-'))
        return 1;
    if ((v == '*') || (v == '/'))
        return 2;
    if (v == '^')
        return 3;
    else
        return 4;
}

float EVALUATE_POSTFIX(cNode *QFrontPtr, cNode *QRearPtr)
{
    eNode *eTopPtr;
    eTopPtr = new eNode;
    empty(eTopPtr);
    while (QFrontPtr != NULL)
    {
        if((QFrontPtr->infix >='0') && (QFrontPtr->infix<= '9'))
        {
            PUSHFUNCTION2(FloatConversion(dequeue(QFrontPtr)),eTopPtr);
        }
        else if((QFrontPtr->infix == '+')||(QFrontPtr->infix == '-')||(QFrontPtr->infix == '*')||(QFrontPtr->infix == '/')||(QFrontPtr->infix == '^'))
        {
            float answer;
            float value = eTopPtr->eval;
            POPFUNCTION2(eTopPtr);
            switch(QFrontPtr->infix)
            {
            case '+':
                answer = eTopPtr-> eval + value;
                POPFUNCTION2(eTopPtr);
                PUSHFUNCTION2(answer,eTopPtr);
                dequeue(QFrontPtr);
                break;
            case '-':
                answer = eTopPtr-> eval - value;
                POPFUNCTION2(eTopPtr);
                PUSHFUNCTION2(answer,eTopPtr);
                dequeue(QFrontPtr);
                break;
            case '*':
                answer = eTopPtr-> eval * value;
                POPFUNCTION2(eTopPtr);
                PUSHFUNCTION2(answer,eTopPtr);
                dequeue(QFrontPtr);
                break;
            case '/':
                answer = eTopPtr-> eval / value;
                POPFUNCTION2(eTopPtr);
                PUSHFUNCTION2(answer,eTopPtr);
                dequeue(QFrontPtr);
                break;
            case '^':
                answer = pow(eTopPtr->eval,value);
                POPFUNCTION2(eTopPtr);
                PUSHFUNCTION2(answer,eTopPtr);
                dequeue(QFrontPtr);
                break;
            }
        }
    }
    cout<<"Evaluation: "<<eTopPtr->eval<<endl<<endl;
    return eTopPtr->eval;
}

void INFIX_TO_POSTFIX(cNode *&infixTop,cNode *&infixList)
{

    cNode *StackTopPtr;
    StackTopPtr = new cNode;
    empty(StackTopPtr);

    cNode *QFrontPtr;
    QFrontPtr = new cNode;
    empty(QFrontPtr);

    cNode *QRearPtr;
    QRearPtr = new cNode;
    empty(QRearPtr);

    QFrontPtr = QRearPtr;
    infixTop = infixList;

    cout << endl <<"Postfix: ";
    //infixTop = infixTop->next; // To account for the head of the linked list that is blank
    for (; infixTop != NULL; infixTop = infixTop->next)
    {
        if((infixTop->infix >='0') && (infixTop->infix<= '9'))
        {
            enqueue(infixTop->infix, QRearPtr, QFrontPtr);
            cout << QRearPtr->infix;
        }
        else if(infixTop->infix == '(')
        {
            PUSHFUNCTION(infixTop->infix,StackTopPtr);
        }
        else if((infixTop->infix == '+')||(infixTop->infix == '-')||(infixTop->infix == '*')||(infixTop->infix == '/')||(infixTop->infix == '^'))
        {
            while(isempty(StackTopPtr) == 0 && StackTopPtr->infix!= '(')
            {
                if(precedence(StackTopPtr->infix) >= precedence(infixTop->infix))
                {
                    enqueue(POPFUNCTION(StackTopPtr),QRearPtr, QFrontPtr);
                    cout<<QRearPtr->infix;
                }
                else
                    break;
            }
            PUSHFUNCTION(infixTop->infix, StackTopPtr);
        }

        else if(infixTop->infix == ')')
        {
            while(isempty(StackTopPtr) == 0 && StackTopPtr->infix != '(')
            {
                enqueue(POPFUNCTION(StackTopPtr),QRearPtr, QFrontPtr);
                cout << QRearPtr->infix;
            }
            if(isempty(StackTopPtr) == 0)
            {
                POPFUNCTION(StackTopPtr);
            }
        }
        else
        {
            cout << "Invalid input." << endl;
        }
    }
    while(isempty(StackTopPtr) == 0)
    {
        enqueue(POPFUNCTION(StackTopPtr),QRearPtr, QFrontPtr);
        cout << QRearPtr->infix;
    }
    cout << endl;
    sum += EVALUATE_POSTFIX(QFrontPtr, QRearPtr);
    cout << endl;
}



int main()
{
    //float answer;
    //int counter;
    //float Sum[50];
    cNode *infixList = new cNode;
    cNode *infixTop = new cNode;

    empty(infixList);
    empty(infixTop);

    ifstream inData;
    inData.open("a2.txt");

    if(!inData) //checks the file to see if correct..//
    {
        cout<<"can not open file"<<endl;
    }


    cout<<"Answers: " <<endl<<endl;

    while(inData.peek() !=EOF)
    {
        string line;
        getline(inData,line);
        if (line.length() >= 2)
        {
            cout<<"Infix: ";
            //cout<<line<<endl;
            for (int s=0; s < line.length(); s++)
            {
                enqueue(line[s],infixTop, infixList);
                cout << infixTop->infix;
            }
            INFIX_TO_POSTFIX(infixTop, infixList);
            infixTop=infixList;
            infixList->infix = NULL;
            infixList->next = NULL;
        }
        //Sum[counter]=EVALUATE_POSTFIX(QFrontPtr, QRearPtr);
        else
        {
            cout<<endl;
            cout<<"Incorrect statement..."<<endl;
        }
    }
    //for(int i =0; i<counter; i++)
    //{
    //answer = answer + Sum[i];
    //cout<<"Sum of Postfix Answers: "<<Sum[i]<<endl;
    //counter++;
    //}
    cout<<"*********************"<<endl;
    cout<<"SUM OF POSTFIX EQUATIONS"<<endl;
    cout << sum << endl <<endl;
    inData.close();
    return 0;
    system("pause");
}
