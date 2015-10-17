#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<fstream>
#include<iostream>

struct charNode
{
	char data;
	charNode *nextNode;
}

struct floatNode
{
	float data;
	floatNode *nextNode;
}

charNode *TOP, *FRONT, *REAR;

int isEmpty(struct charNode *); //check if empty
void pushC(char ,struct charNode *); //push char node to stack
void pushF(float ,struct floatNode *); //push float node to stack
char popC(struct charNode *); //pop char node from stack
float popF(struct floatNode *); //pop float node from stack
void toQueue(char ,struct charNode *,struct charNode *); //add to queue
void deQueue(struct charNode *); //remove from queue
int PEMDAS(char );
void INFIX_TO_POSTFIX(struct charNode *,struct charNode *);



int main
{
	
	charNode *infixLL = new charNode;
	charNode *infixLLtop = new charNode;
	
	
	
	
}

int isEmpty(charNode *nodePtr)
{
	if(nodePtr->data==NULL && nodePtr->nextNode==NULL){
		return 1;
	}else{
		return 0;
	}
	
}

void pushC(char in,charNode TOP)
{
	charNode *temp = new charNode;
	temp->data = in;
	temp->nextNode = TOP;
	TOP = temp;
	
}

void pushF(float in,floatNode *)
{
	floatNode *temp = new floatNode;
	temp->data = in;
	temp->next = 
	
	
	
}

char popC(charNode *)
{
	
	
	
}

float popF(floatNode *)
{
	
	
	
}





void toQueue(char , charNode *, charNode *)
{
	
	
	
}

void deQueue(charNode *)
{
	
	
	
}

int PEMDAS(char op)
{
    switch(op)
	{
		case  '(':case ')':
		{
			return 0;
		}break;
		case '+':case '-':
		{
			return 1;
		}break;
		case '*':case '/':
		{
			return 2;
		}break;
		case '^':
		{
			return 3;
		}break;
	}
}

void INFIX_TO_POSTFIX(charNode *header, charNode *cptr)




void INFIX_TO_POSTFIX(charNode *&infixTop,charNode *&infixList)
{

    charNode *StackTopPtr;
    StackTopPtr = new charNode;
    empty(StackTopPtr);

    charNode *QFrontPtr;
    QFrontPtr = new charNode;
    empty(QFrontPtr);

    charNode *QRearPtr;
    QRearPtr = new charNode;
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
            pushC(infixTop->infix,StackTopPtr);
        }
        else if((infixTop->infix == '+')||(infixTop->infix == '-')||(infixTop->infix == '*')||(infixTop->infix == '/')||(infixTop->infix == '^'))
        {
            while(isempty(StackTopPtr) == 0 && StackTopPtr->infix!= '(')
            {
                if(precedence(StackTopPtr->infix) >= precedence(infixTop->infix))
                {
                    enqueue(popC(StackTopPtr),QRearPtr, QFrontPtr);
                    cout<<QRearPtr->infix;
                }
                else
                    break;
            }
            pushC(infixTop->infix, StackTopPtr);
        }

        else if(infixTop->infix == ')')
        {
            while(isempty(StackTopPtr) == 0 && StackTopPtr->infix != '(')
            {
                enqueue(popC(StackTopPtr),QRearPtr, QFrontPtr);
                cout << QRearPtr->infix;
            }
            if(isempty(StackTopPtr) == 0)
            {
                popC(StackTopPtr);
            }
        }
        else
        {
            cout << "Invalid input." << endl;
        }
    }
    while(isempty(StackTopPtr) == 0)
    {
        enqueue(popC(StackTopPtr),QRearPtr, QFrontPtr);
        cout << QRearPtr->infix;
    }
    cout << endl;
    sum += EVALUATE_POSTFIX(QFrontPtr, QRearPtr);
    cout << endl;
}


float EVALUATE_POSTFIX(charNode *QFrontPtr, charNode *QRearPtr)
{
    floatNode *eTopPtr;
    eTopPtr = new floatNode;
    empty(eTopPtr);
    while (QFrontPtr != NULL)
    {
        if((QFrontPtr->infix >='0') && (QFrontPtr->infix<= '9'))
        {
            pushC2(FloatConversion(dequeue(QFrontPtr)),eTopPtr);
        }
        else if((QFrontPtr->infix == '+')||(QFrontPtr->infix == '-')||(QFrontPtr->infix == '*')||(QFrontPtr->infix == '/')||(QFrontPtr->infix == '^'))
        {
            float answer;
            float value = eTopPtr->eval;
            popC2(eTopPtr);
            switch(QFrontPtr->infix)
            {
            case '+':
                answer = eTopPtr-> eval + value;
                popC2(eTopPtr);
                pushC2(answer,eTopPtr);
                dequeue(QFrontPtr);
                break;
            case '-':
                answer = eTopPtr-> eval - value;
                popC2(eTopPtr);
                pushC2(answer,eTopPtr);
                dequeue(QFrontPtr);
                break;
            case '*':
                answer = eTopPtr-> eval * value;
                popC2(eTopPtr);
                pushC2(answer,eTopPtr);
                dequeue(QFrontPtr);
                break;
            case '/':
                answer = eTopPtr-> eval / value;
                popC2(eTopPtr);
                pushC2(answer,eTopPtr);
                dequeue(QFrontPtr);
                break;
            case '^':
                answer = pow(eTopPtr->eval,value);
                popC2(eTopPtr);
                pushC2(answer,eTopPtr);
                dequeue(QFrontPtr);
                break;
            }
        }
    }
    cout<<"Evaluation: "<<eTopPtr->eval<<endl<<endl;
    return eTopPtr->eval;
}