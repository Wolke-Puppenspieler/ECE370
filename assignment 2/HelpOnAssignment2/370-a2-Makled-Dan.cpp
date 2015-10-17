#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include <math.h>

using namespace std;

//Infix to Postfix stack/queue and read in linked list
struct lnode
{
    char data;
    lnode *next;
}*opTop,*front,*rear;
//Evaluating
struct enode
{
    float val;
    enode *next;
}*evalTop;

int isempty(lnode *node)
{
    if ((node->data == NULL)&&(node->next == NULL))
        return 1;
    else
        return 0;
}
int isempty(enode *node)
{
    if ((node->val == NULL)&&(node->next == NULL))
        return 1;
    else
        return 0;
}

void empty(lnode *&node)
{
    node->data = NULL;
    node->next = NULL;
}
void empty(enode *&node)
{
    node->val = NULL;
    node->next = NULL;
}

void push(char data, lnode *&top)
{
    lnode *temp = new lnode;
    temp->data = data;
    temp->next = top;
    top = temp;
}
void push(float val, enode *&top)
{
    enode *temp = new enode;
    temp->val = val;
    temp->next = top;
    top = temp;
}

char pop(lnode *&top)
{
    char data = top->data;
    lnode *old_top = top;
    top = old_top->next;
    delete old_top;
    return data;
}
char pop(enode *&top)
{
    float val = top->val;
    enode *old_top = top;
    top = old_top->next;
    delete old_top;
    return val;
}

void enqueue(char data,lnode *&front,lnode *&rear)
{
    lnode *temp = new lnode;
    temp->data = data;
    temp->next = NULL;
    if ((isempty(front) == 1)&&((isempty(rear)) == 1))
    {
        rear = temp;
        front = temp;
    }
    else
    {
        rear->next = temp;
        rear = temp;
    }
}

char dequeue(lnode *&front)
{
    char data = front->data;
    lnode *old_front = front;
    front = old_front->next;
    delete old_front;
    return data;
}

float conv_to_float(char x)
{
    float val = atof(&x);
    return val;
}

int precedence(char x)
{
    if ((x == '(')||(x == ')'))
        return 0;
    if ((x == '+') || (x == '-'))
        return 1;
    if ((x == '*') || (x == '/'))
        return 2;
    if (x == '^')
        return 3;
    else
        return 4;
}

void INFIX_TO_POSTFIX(lnode *inlist,lnode *in)
{
    opTop = new lnode;
    empty(opTop);

    front = new lnode;
    empty(front);
    lnode *rear;

    in = inlist;
    rear = front;

    cout << "Postfix Function: " << endl;
    for (int i = 0; in != NULL; i++)
    {
        if (((in->data) >= '0')&&(in->data <= '9'))
        {
            enqueue(in->data,front,rear);
            cout << rear->data;
        }
        else if (in->data == '(')
            push(in->data,opTop);
        else if (in->data == ')')
        {
            while((isempty(opTop) == 0)&&(opTop->data!='('))
                  {
                      enqueue(pop(opTop),front,rear);
                      cout << rear->data;
                  }
            if ((isempty(opTop) == 0))
                pop(opTop);
        }
        else if ((in->data == '*')||(in->data == '+')||(in->data == '-')||(in->data == '/')||(in->data == '^'))
        {
            while ((isempty(opTop) == 0)&&(opTop->data != '('))
            {
                if (precedence(opTop->data) >= precedence(in->data))
                   {
                       enqueue(pop(opTop),front,rear);
                       cout << rear->data;
                   }
                else
                    break;
            }
            push(in->data,opTop);
        }
        in = in->next;
    }
    while(isempty(opTop) == 0)
    {
       enqueue(pop(opTop),front,rear);
       cout << rear->data;
    }
    cout << endl;
}

float EVALUATE_POSTFIX(lnode *&front, lnode *&rear)
{
    evalTop = new enode;
    empty(evalTop);
    while (front != NULL)
    {
        if (((front->data)>= '0') && (front->data <= '9'))
            push(conv_to_float(dequeue(front)),evalTop);
        else if ((front->data == '*')||(front->data == '+')||(front->data == '-')||(front->data == '/')||(front->data == '^'))
        {
            float result;
            float num = evalTop->val;
            pop(evalTop);
            if (front->data == '*')
            {
                result = evalTop->val * num;
                pop(evalTop);
                push(result,evalTop);
                dequeue(front);
            }
            else if (front->data == '/')
            {
                result = evalTop->val / num;
                pop(evalTop);
                push(result,evalTop);
                dequeue(front);
            }
            else if (front->data == '+')
            {
                result = evalTop->val + num;
                pop(evalTop);
                push(result,evalTop);
                dequeue(front);
            }
            else if (front->data == '-')
            {
                result = evalTop->val - num;
                pop(evalTop);
                push(result,evalTop);
                dequeue(front);
            }
            else if (front->data == '^')
            {
                result = pow(evalTop->val,num);
                pop(evalTop);
                push(result,evalTop);
                dequeue(front);
            }

        }
    }
    cout << "Postfix Evaluation: " << endl << evalTop->val << endl;
}

int main()
{
    lnode *inlist = new lnode;
    empty(inlist);
    lnode *in;

    ifstream infile;
    infile.open("a2.txt");
    in = inlist;
    while(infile.peek() != EOF)
    {
        string temp;
        getline(infile,temp);
        if (temp.length() >= 2)
        {
            cout << "Infix Operation: " << endl;
            for (int i = 0; i < temp.length(); i++)
            {
                /*in->data = temp[i];
                cout << in->data;
                in->next = new lnode;
                in = in->next;
                in->next = NULL;*/
                enqueue(temp[i],inlist,in);
                cout << in->data;
            }
            cout << endl;
            //in->next = new lnode;
            //in = in->next;
            //empty(in);

            INFIX_TO_POSTFIX(inlist,in);
            EVALUATE_POSTFIX(front,rear);
            empty(inlist);
            in = inlist;
        }
        else
            cout << "INVALID ENTRY: There may be a blank line in the text file." << endl;
        cout << endl;
    }
    infile.close();
}
