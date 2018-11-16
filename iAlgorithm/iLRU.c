/*LRU algorithm*/

#include <stdio.h>
#include <stdlib.h>

#define LOG() printf("[%d]\n", __LINE__)
#define LRU_CAPACITY 10

struct nodeSoldier{
    int number; /*the soldier's number*/
    struct nodeSoldier *next; /*point to next soldier*/
}nodeSoldier;

typedef struct nodeSoldier *pNodeSoldier;

/*insert node in the header of the linked list*/
void insertLikedlist(pNodeSoldier *head, int *pdata)
{
    pNodeSoldier pNewSoldier;
    pNodeSoldier probe = *head;
    pNewSoldier =(pNodeSoldier)malloc(sizeof(struct nodeSoldier));

    if (NULL != pNewSoldier)
    {
        pNewSoldier->number = *pdata;
        pNewSoldier->next = probe;
        *head = pNewSoldier;
    }
    else
    {
        printf("malloc error!\n");
    }
}

/*deleted matched node*/
pNodeSoldier deleteLinkedlist(pNodeSoldier head, int data)
{
    pNodeSoldier probe = head;
    pNodeSoldier preProbe = head;
    while(data != probe->number)
    {
        probe = probe->next;
    }
    /*the node probe point to*/
    if (NULL != probe)
    {
        /*delete it*/
        if (probe == head) /*is the first node*/
        {
            head = probe->next;
        }
        else
        {
            /*find the node before it*/
            preProbe = head;
            while(preProbe->next != probe)
            {
                preProbe = preProbe->next;
            }
            preProbe->next = probe->next;
        }
        free(probe);        
    }
    else 
    {
        printf("no found\n");
    }
    return (head);
}

/*Create LRU catch with the single linked list*/
/*soldier is named as 1,2,3,...capacity in turn*/
pNodeSoldier LRUCreate(const int capacity)
{
    pNodeSoldier head = NULL;
    pNodeSoldier probe = NULL;
    int counter = capacity;

    /*if length of the linked list is bigger than 1, then adding one more node*/  
    if (capacity > 1)
    {
        /*initialize the first node firstly*/
        head = (pNodeSoldier)malloc(sizeof(struct nodeSoldier));
        if(NULL != head)
        {
            head->next = NULL;
            head->number = capacity;
        }
        else 
        {
            /*malloc error*/
            printf("malloc error!\n");
        }
        /*insert the remaining nodes in the header of the linked list one by one*/
        for (; counter > 1; counter--)
        {
            probe = (pNodeSoldier)malloc(sizeof(struct nodeSoldier));
            if (NULL != probe)
            {
                probe->next = head;
                probe->number = counter - 1;
                head = probe;
            }
            else
            {
                /*malloc error*/
                 printf("malloc error!\n");
            }
        }
    }
    else if (capacity == 1)
    {
        /*only 1 node in the linked list*/
        head = (pNodeSoldier)malloc(sizeof(struct nodeSoldier));
        if(NULL != head)
        {
            head->next = NULL;
            head->number = 1;
        }
        else 
        {
            /*malloc error*/
            printf("malloc error!\n");
        }
    }
    else
    {
        printf("capacity error! it should be bigger than 0!\n");
        /*capacity error*/
    }
    return (head);
}

/*calculate the length of the catch*/
int LRUCalcuLen(pNodeSoldier const head)
{
    int counter = 0;
    pNodeSoldier probe = head;
    if (NULL != head)
    {
        while(NULL != probe)
        {
            ++counter;
            probe = probe->next;
        }
    }
    else
    {
        printf("input parameters error!\n");
        /*NULL pointer from the input parameters of the function*/
    }
    return (counter); /*cann't return the pointer variable or reference to the stack,but others'variable because the stack will be destroied when the function exit*/
}

/*output the LRU catch*/
void LRUOutput(pNodeSoldier const head)
{
    pNodeSoldier probe = head;
    printf("--------------output the linked list----------\n");
    if (NULL != head)
    {
        for(; probe != NULL; )
        {
           printf("Node's number is %d\n", probe->number);
           probe = probe->next;
        }
    }
    else
    {
         printf("input parameters error!\n");
        /*NULL pointer from the input parameters of the function*/       
    }
}

/*destroy the LRU catch*/
void LRUDestroy(pNodeSoldier head)
{
    pNodeSoldier probe = head;
    pNodeSoldier nextProbe = head;
    if (NULL != head)
    {
        for(; probe != NULL; )
        {
           nextProbe = probe->next;
           free(probe);
           probe = nextProbe;
        }
    }
    else
    {
         printf("input parameters error!\n");
        /*NULL pointer from the input parameters of the function*/       
    }
}

#if 1
pNodeSoldier LRUAlogrithm(pNodeSoldier head, int soldierNumber)
{
    pNodeSoldier preProbe = head;
    pNodeSoldier probe = head;
    pNodeSoldier pNewSoldier = NULL;
    int length = LRUCalcuLen(head);
    if (NULL != head)
    {
        /*find it in the link list*/
        for(; NULL != probe; )
        {
            if (probe->number != soldierNumber)
            {
                /*I don't find it, continue to find it until the last node probe point to*/
                probe = probe->next;
            }
            else
            {
                /*Yes, I find it, I can leave*/
                
                break;
            }
        }
        /*Link list doesn't have it, then add it in the header of the linked list*/
        if (NULL == probe)
        {
            /*Buffer is not full, then put it in the header*/
            if (LRU_CAPACITY > length)
            {
                insertLikedlist(&head, &soldierNumber);
            }
            else/*Buffer is full, then delete the last node, then put it in the header*/
            {
                
                /*find the last node*/
                probe = head;
                while(NULL != probe->next)
                {
                    probe = probe->next;                  
                }
                /*probe point to the last node,find the node before it*/
                preProbe = head;
                while (preProbe->next != probe)
                {
                    preProbe = preProbe->next;
                }
                /*delete the last node*/
                preProbe->next = NULL;
                free(probe);
                insertLikedlist(&head, &soldierNumber);
            }
        }
        else/*move it to the header of the linked list*/
        {
            
            /*find the node before it*/
            while(preProbe->next != probe)
            {
                preProbe = preProbe->next;
            }
            /*connect to the next of the node which probe point to*/
            preProbe->next = probe->next;
            /*head connect to the node which probe point to */
            probe->next = head;
            head = probe;
        }
    }
    else
    {
        /*NULL address access from input parameters of the function*/
    }
    return (head);
}
#endif

void main(void)
{
    pNodeSoldier head = NULL;
	pNodeSoldier pNewNode = NULL;
    int soldierNumber = 14;
    int length = 0;
    printf("-----------------test case 0: node's number can't zero------------------\n");
    head = LRUCreate(0);
    printf("-----------------test case 1: only one node ------------------\n");
    head = LRUCreate(1);
    LRUDestroy(head);
    printf("-----------------test case 2: big enough catch------------------\n");
    head = LRUCreate(13);
    printf("the length of the LRU is %d\n",  LRUCalcuLen(head));
    LRUOutput(head);
    printf("-----------------test case 3: insert node------------------\n");
    insertLikedlist(&head, &soldierNumber);
    LRUOutput(head);
    printf("-----------------test case 4: delete the first node------------------\n");
    head = deleteLinkedlist(head, 14);
    LRUOutput(head);
    printf("-----------------test case 5: the node deleted is the middle node: ------------------\n");
    head = deleteLinkedlist(head, 7);
    LRUOutput(head);
    printf("-----------------test case 6: the node deleted is the last node: ------------------\n");
    head = deleteLinkedlist(head, 13);
    LRUOutput(head);
	printf("-----------------test case 7: put new data in the header after deleting the last node if catch is full ------------------\n");
    head = LRUAlogrithm(head, 15);
	LRUOutput(head);
    printf("-----------------test case 8: put new data in the header if catch is not full ------------------\n");
	head = deleteLinkedlist(head, 8);
	head = deleteLinkedlist(head, 9);
	head = deleteLinkedlist(head, 10);
	head = deleteLinkedlist(head, 11);

    LRUOutput(head);
    head = LRUAlogrithm(head, 16);
    LRUOutput(head);
    printf("-----------------test case 9: move the existent data to the header ------------------\n");
    head = LRUAlogrithm(head, 4);
    LRUOutput(head); 
    LRUDestroy(head);
}
