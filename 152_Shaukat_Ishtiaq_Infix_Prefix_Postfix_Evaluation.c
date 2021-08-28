#include <stdio.h>
#include <string.h>

//variables
int operand[20];
char operator[20];
int topOperand = -1;
int topOperator = -1;

// functions
void pushOperator(char);
void pushOperand(int);
int popOperand();
char popOperator();
void process();

void infixEvaluation(char *);
void postfixEvaluation(char *);
void prefixEvaluation(char *);

int main() {
	char input[20];

	int choice;
	do {

        printf("1-Infix Evaluation\n2-Postfix Evaluation\n3-Prefix Evaluation\n0-Exit ");
        scanf("%d",&choice);

        switch(choice) {
            case 1:
                printf("Enter an infix expression: ");
                scanf("%s",input);
                infixEvaluation(input);
                break;
            case 2:
                printf("Enter a postfix expression: ");
                scanf("%s",input);
                postfixEvaluation(input);
                break;
            case 3:
                printf("Enter a prefix expression: ");
                scanf("%s",input);
                prefixEvaluation(input);
                break;
        } //switch
	}while(choice !=0); //doWhile loop.


	return 0;
}
void pushOperator(char x) {
	topOperator++;
	operator[topOperator] = x;
}

void pushOperand(int x) {
	topOperand++;
	operand[topOperand] = x;
}
int popOperand() {
	int number = *(operand+topOperand);
	topOperand--;
	return number;
}

char popOperator() {
	char o = *(operator+topOperator);
	topOperator--;
	return o;
}

void process() {
	char o = popOperator();
	int a,b;
	switch(o) {
		case '+':

				 a = popOperand();
				 b = popOperand();
				pushOperand(a+b);
			break;
		case '-':
				 a = popOperand();
				 b = popOperand();
				pushOperand(b-a);
			break;
		case '*':

				 a = popOperand();
				 b = popOperand();
				pushOperand(a*b);

			break;
		case '/':

				 a = popOperand();
				 b = popOperand();
				pushOperand(b/a);

			break;
		default:
		    printf("\n\n!!!ERROR IN INFIX\n\n");
			break;
	}
}
void infixEvaluation(char input[20]) {
    for(int i=0;input[i] != '\0';i++) {

		if(*(input+i) == '+' || *(input+i) == '-' || *(input+i) == '*' || *(input+i) == '/') {
			if(topOperator == -1) {
				pushOperator(*(input+i));
			}
			else if(*(operator+topOperator) == '/' || *(operator+topOperator) == '*') {
				if(*(input+i) == '/' || *(input+i) == '*') {
                    while(*(operator+topOperator) == '/' || *(operator+topOperator) == '*') {
                        process();
                    }
					pushOperator(*(input+i));
				}
				else {
						// do the process.
						while(*(operator+topOperator) == '/' || *(operator+topOperator) == '*' )
						process();
						pushOperator(*(input+i));

				}
			}
			else if(*(operator+topOperator) == '+' || *(operator+topOperator) == '-') {
					pushOperator(*(input+i));
			}
			else if(*(operator+topOperator) == '(') {
				pushOperator(*(input+i));
			}
		}

		else if(*(input+i) == '(') {
			pushOperator(*(input+i));
		}
		else if(*(input+i) == ')') {
			while(operator[topOperator] != '(') {
				process();
			}
			popOperator();
		}

		else {
			int number = *(input+i) - '0';
			//push when an oprand.
			pushOperand(number);
		}
	}
	if(topOperator != -1) {
			while(topOperator != -1) {
				process();
			}
		}
		printf("Result = %d\n\n",operand[topOperand]);
}

void postfixEvaluation(char input[20]) {

    for(int i = 0;input[i]!='\0';i++) {
        if(input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/') {

            int b = popOperand();

            int a = popOperand();

            switch(input[i]) {
                case '+':
                    pushOperand(a+b);
                    break;
                case '-':
                    pushOperand(a-b);
                    break;
                case '*':
                    pushOperand(a*b);
                    break;
                case '/':
                    pushOperand(a/b);
                    break;
                default:
                    printf("\n\n!!!ERROR IN POSTFIX!!!\n\n");
                    break;

            }
        }
        else {
           pushOperand(input[i] - '0');
        }
    }
    printf("\nResult = %d\n\n",popOperand());
    topOperand = -1;
}

void prefixEvaluation(char input[20]) {
    int length = strlen(input);

    for(int i=length-1;i>=0;i--) {
        if(*(input+i) == '+' || *(input+i) == '-' || *(input+i) == '*' || *(input+i) == '/') {

            int a = popOperand();
            int b = popOperand();
            switch(input[i]) {
                case '+':
                    pushOperand(a+b);
                    break;
                case '-':
                    pushOperand(a-b);
                    break;
                case '*':
                    pushOperand(a*b);
                    break;
                case '/':
                    pushOperand(a/b);
                    break;
                default:
                    printf("\n\n!!!ERROR IN PREFIX!!!\n\n");
                break;

            }
        }
        else {
            pushOperand(input[i] - '0');
        }
    }
    printf("\nResult = %d\n\n",popOperand());
}
