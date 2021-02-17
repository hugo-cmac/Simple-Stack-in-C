#include <stdio.h>
#include <stdlib.h>

typedef struct Stack{
    int data;
    struct Stack *next;
}stack;

stack *head = NULL;

stack *newNode(int data){
    stack *temp = malloc(sizeof(stack));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void push(int data){
    stack *temp = newNode(data);

    if (head == NULL){
        head = temp;
    }else{
        temp->next = head;
        head = temp;
    }
}

int pop(){
    if (head == NULL){
        return -1; //meaning that the stack is empty
    }
    stack* temp = head;
    head = head->next;
    int data = temp->data;
    free(temp);
    return data;
}

int main(int argc, char const *argv[]){

    for (int i = 0; i < 10; i++){
        printf("Push %d\n", i);
        push(i);
    }


    int n = 0;
    while (n != -1){
        n = pop();
        if (n == -1){
            printf("Stack empty\n");
        }else{
            printf("Poped %d\n", n);
        }
    }
    return 0;
}
