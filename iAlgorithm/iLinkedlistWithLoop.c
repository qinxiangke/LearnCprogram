/*********************************************
1.给一个单链表,判断其中是否有环的存在;
2.如果存在环,找出环的入口点;
3.如果存在环,求出环上节点的个数;
4.如果存在环,求出链表的长度;
5.如果存在环,求出环上距离任意一个节点最远的点(对面节点);
6.(扩展)如何判断两个无环链表是否相交;
7.(扩展)如果相交,求出第一个相交的节点
*********************************************/
#include <stdio.h>
#include <stdlib.h>
#include "iLink.h"

typedef unsigned short bool;

struct node{
    int number;
    struct node *next;
};

typedef struct node tNode;

#define TRUE (bool)1
#define FALSE (bool)0

#define MAX_MEET_COUNTER 2

/*create the circle linked*/
tNode *circleLinkedlistCreate(int data, int n)
{
    tNode *head = NULL;
    tNode *pNode = NULL;
    int nodeNumber = 0;
    /*create the head node of the linked list*/
    if (NULL != (pNode = (tNode *)malloc(sizeof(tNode)))) 
    {
        head = pNode; /*define the head pointer*/
        pNode->number = data;
        pNode->next = NULL;
        for (; nodeNumber < (n-1); nodeNumber++)
        {
            if (NULL != (pNode->next = (tNode *)malloc(sizeof(tNode))))
            {
                pNode = pNode->next;
                pNode->number = data;
                pNode->next = NULL;
            }
            else
            {
                printf("malloc error!");
                return (NULL);
            }
        }

        /*pNode point to the end, head point to the header*/
        /*connect end to header*/
        pNode->next = head;
    }
    else
    {
        printf("malloc error!");
        return (NULL);
    }
    return (head);
}

/*create the single linked*/
tNode *linkedlistCreate(int data, int n)
{   
   tNode *head = NULL;
    tNode *pNode = NULL;
    int nodeNumber = 0;
    /*create the head node of the linked list*/
    if (NULL != (pNode = (tNode *)malloc(sizeof(tNode)))) 
    {
        head = pNode; /*define the head pointer*/
        pNode->number = data;
        pNode->next = NULL;
        for (; nodeNumber < (n -1 ); nodeNumber++)
        {
            if (NULL != (pNode->next = (tNode *)malloc(sizeof(tNode))))
            {
                pNode = pNode->next;
                pNode->number = data;
                pNode->next = NULL;
            }
            else
            {
                printf("malloc error!");
                return (NULL);
            }
        }
    }
    else
    {
        printf("malloc error!");
        return (NULL);
    }
    return (head);
}
/*append the circle linked list to the single linked list*/
tNode *linkedlistAppendCircle(tNode *list, tNode *circle)
{
    tNode *head = NULL;
    tNode *pNode = NULL;
    if (NULL != list)
    {
        pNode = list;
        head = list;
    }
    else
    {
        return NULL;
    }
    /*reach to the end of the list*/
    while(NULL != pNode->next)
    {
        pNode = pNode->next;
    }
    /*pNode->next = NULL, then pNode point to the end of the linked list*/
    pNode->next = circle;
    return (head);
}

bool checkWithloop(tNode *head)
{
    bool flagLoop = TRUE; /*indicate if it has loop*/
	int stepCounter = 0;
    tNode *fast = NULL;
    tNode *slow = NULL;
    fast = slow = head;
    
    do
    { 
        if (NULL == fast || (NULL == fast->next))   /*reach the end of the linked list, it doesn't loop,We can leave*/
        {
            flagLoop = FALSE; 
            break;
        }
        else
        {
            /*do nothing*/
        }
        fast = fast->next->next; /*fast pointer go past two nodes per step*/
        slow = slow->next; /*slow pointer go past one node per step*/
        ++stepCounter; /*calculate how many steps*/
    }while(slow != fast);

    if ((NULL != fast) && (NULL != fast->next)) /*slow == fast, it prove that this linked list has loop */
    {
        flagLoop = TRUE;
    }
    return (flagLoop);
}

int circleLength(tNode *head)
{
    tNode *fast = NULL;
    tNode *slow = NULL;
    int length = 0;
    int stepCounter[MAX_MEET_COUNTER] = {0};
    int meetCounter = 0;    /*count how many times slow and fast meet*/
    fast = slow = head;
    for (; meetCounter < MAX_MEET_COUNTER; meetCounter++)
    {
        do{
            fast = fast->next->next;
            slow = slow->next;
            ++stepCounter[meetCounter];
        }while(slow != fast);        
    }
    length = stepCounter[1];
    return (length);
    
    /*remember the step slow move, continue to move */
  }

void main(void)
{
    tNode *head = NULL;
    tNode *pCircle = NULL;
    /*initialize the circle linked list*/
    if (NULL != ( pCircle = circleLinkedlistCreate(0, 6)))
    {
        printf("circleLinkedlistCreate success!\n");
    }
    else
    {
        printf("circleLinkedlistCreate failure!\n");
    }
    printf("*******************test 1: circle linked list has a loop*****************\nloopIndicator = %d\n", checkWithloop(pCircle));
    /*initialize the single linked list*/
    if (NULL != (head = linkedlistCreate(1, 4)))
    {
        printf("linkedlistCreate success!\n");
    }
    else
    {
        printf("linkedlistCreate failure!\n");
    }
    printf("*******************test 2: single linked list doesn't have a loop*****************\nloopIndicator = %d\n", checkWithloop(head));
    linkedlistAppendCircle(head, pCircle);
    printf("*******************test 3: Append linked list*************************************\nloopIndicator = %d\n", checkWithloop(head));
    printf("***********test 4: the length of the circle is %d\n", circleLength(head));
}
