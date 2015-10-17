#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include <math.h>

using namespace std;

struct cNode
{
    char input;
    cNode *next;
};

struct fNode
{
    float value;
    fNode *next;
};

cNode *TOPptr = new cNode;
cNode *FRONTptr = new cNode;
cNode *REARptr;

int emptyCheck(cNode *ptr)
{
    if(ptr->input == NULL && ptr->next == NULL)
        return 1;
    else
        return 0;
}

void PUSH1(char input, cNode *&TOPptr)
{
    cNode *x = new cNode;
    x->input = input;
    x->next = TOPptr;
    TOPptr = x;
}

void PUSH2(float value, fNode *&TOPevaluate)
{
    fNode *x = new fNode;
    x->value = value;
    x->next = TOPevaluate;
    TOPevaluate = x;
}

void ENQUEUE(char input, cNode *&REARptr, cNode *&FRONTptr)
{
    cNode *x = new cNode;
    x->input = input;
    x->next = NULL;
    if(emptyCheck(FRONTptr) == 1 && emptyCheck(REARptr) == 1)
    {
        REARptr = x;
        FRONTptr = x;
    }
    else
    {
        REARptr->next = x;
        REARptr = x;
    }
}

char DEQUEUE(cNode *&FRONTptr)
{
    char x = FRONTptr->input;
    cNode *old_FRONTptr = FRONTptr;
    FRONTptr = old_FRONTptr->next;
    delete old_FRONTptr;
    return x;
}

char POP(cNode *&TOPptr)
{
    char x = TOPptr->input;
    cNode *old_TOPptr = TOPptr;
    TOPptr = old_TOPptr->next;
    delete old_TOPptr;
    return x;
}

float POP2(fNode *&TOPevaluate)
{
    float y = TOPevaluate->value;
    fNode *old_TOPptr = TOPevaluate;
    TOPevaluate = old_TOPptr->next;
    delete old_TOPptr;
    return y;
}

int precedenceCheck(char z)
{
    if(z == '(' || z == ')')
        return 0;
    if(z == '+' || z == '-')
        return 1;
    if(z == '*' || z == '/')
        return 2;
    if(z == '^')
        return 3;
}

void INFIX_TO_POSTFIX(cNode *header, cNode *cptr)
{
    TOPptr->input = NULL;
    TOPptr->next = NULL;

    FRONTptr->input = NULL;
    FRONTptr->next = NULL;
    REARptr = FRONTptr;

    cptr = header;
    cout << "Postfix: ";

    for(int i = 0; cptr != NULL; i++)
    {
        if(cptr->input >= '0' && cptr->input <= '9')
        {
            ENQUEUE(cptr->input, REARptr, FRONTptr);
            cout << REARptr->input;
        }
        else if(cptr->input == '(')
        {
            PUSH1(cptr->input, TOPptr);
        }
        else if(cptr->input == '+' || cptr->input == '-' || cptr->input == '*' || cptr->input == '/' || cptr->input == '^')
        {
            while(emptyCheck(TOPptr) == 0 && TOPptr->input != '(')
            {
                if(precedenceCheck(TOPptr->input) >= precedenceCheck(cptr->input))
                {
                    ENQUEUE(POP(TOPptr), REARptr, FRONTptr);
                    cout << REARptr->input;
                }
                else
                    break;
            }
            PUSH1(cptr->input, TOPptr);
        }
        else if(cptr->input == ')')
        {
            while(emptyCheck(TOPptr) == 0 && TOPptr->input != '(')
            {
                ENQUEUE(POP(TOPptr), REARptr, FRONTptr);
                cout << REARptr->input;
            }
            if(emptyCheck(TOPptr) == 0)
            {
                POP(TOPptr);
            }
        }
        else
        {
            cout << "Invalid input." << endl;
        }
        cptr = cptr->next;
    }
    while(emptyCheck(TOPptr) == 0)
    {
        ENQUEUE(POP(TOPptr), REARptr, FRONTptr);
        cout << REARptr->input;
    }
    cout << endl;
}

float EVALUATE(fNode *&TOPevaluate, float temp, char input)
{
    if(input == '^')
        return pow(TOPevaluate->value,temp);
    else if(input == '*')
        return ((TOPevaluate->value)*(temp));
    else if(input == '/')
        return ((TOPevaluate->value)/(temp));
    else if(input == '+')
        return ((TOPevaluate->value)+(temp));
    else if(input == '-')
        return ((TOPevaluate->value)-(temp));
}

void EVALUATE_POSTFIX(cNode *REARptr, cNode *FRONTptr)
{
    fNode *TOPevaluate = new fNode;
    TOPevaluate->value = NULL;
    TOPevaluate->next = NULL;

    cout << "Postfix evaluation: ";
    for(int i = 0; FRONTptr != NULL; i++)
    {
        if(FRONTptr->input >= '0' && FRONTptr->input <= '9')
        {
            char temp = (DEQUEUE(FRONTptr));
            float x = atof(&temp);
            PUSH2(x, TOPevaluate);
        }
        else if(FRONTptr->input == '+' || FRONTptr->input == '-' || FRONTptr->input == '*' || FRONTptr->input == '/' || FRONTptr->input == '^')
        {
            float temp2 = TOPevaluate->value;
            POP2(TOPevaluate);
            float temp3 = EVALUATE(TOPevaluate, temp2, FRONTptr->input);
            POP2(TOPevaluate);
            PUSH2(temp3, TOPevaluate);
            DEQUEUE(FRONTptr);
        }
    }
    cout << TOPevaluate->value;
    cout << endl;
}

int main()
{
    cNode *header;
    cNode *cptr;

    header = new cNode;
    header->input = NULL;
    header->next = NULL;
    cptr = header;

    ifstream infile("a2.txt");
    if(infile.is_open())
    {
        while(infile.peek() != EOF)
        {
            cptr = header;
            string temp;
            getline(infile,temp);
            int length = temp.length();
            if(length >= 2)
            {
                cout << "Infix: ";
                for(int i = 0; i < length; i++)
                {
                    ENQUEUE(temp[i], cptr, header);
                    cout << cptr->input;
                }
                cout << endl;
                cptr = header;
                INFIX_TO_POSTFIX(header, cptr);
                EVALUATE_POSTFIX(REARptr, FRONTptr);
                cout << endl;
                header->input = NULL;
                header->next = NULL;
            }
        }
    }
    else
        cout << "File is not open." << endl;
    cout << endl;
    infile.close();
    return 0;
}
