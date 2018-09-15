#include<stdio.h>
#include<stdlib.h>


struct cube
{
  char cube[6][9];
};

struct node{
  struct cube cube;
  struct node *next;
};

struct queue{
  struct node *front;
  struct node *rear;
};

void initialize_q(struct queue *q)
{
  q->front=NULL;
  q->rear=NULL;
}

void enqueue(struct queue *q, struct cube cube)
{
  struct node *ptr;
  ptr = (struct node*)malloc(sizeof(struct node));
  ptr->cube = cube;
  if(q->front == NULL)
  {
    q->front = ptr;
    q->rear = ptr;
    q->front->next=q->rear->next=NULL;
  }
  else{
    q->rear->next=ptr;
    q->rear=ptr;
    q->rear->next=NULL;
  }
}

struct node *dequeue(struct queue *q)
{
  struct node *ptr;
  ptr=q->front;
  q->front=q->front->next;
  return ptr;
}

void delete_node(struct node *ptr)
{
  free(ptr);
}

struct cube initialize_cube()
{
  struct cube cube;

  for(int i=0;i<6;i++)
  {
    for(int j=0;j<9;j++)
    {
      if(i==0)
      {
        cube.cube[i][j]='G';
      }

      if(i==4)
      {
        cube.cube[i][j]='W';
      }

      if(i==2)
      {
        cube.cube[i][j]='R';
      }

      if(i==3)
      {
        cube.cube[i][j]='O';
      }

      if(i==5)
      {
        cube.cube[i][j]='Y';
      }

      if(i==1)
      {
        cube.cube[i][j]='B';
      }
    }
  }
  return cube;
}

int compare_cubes(struct cube cube1,struct cube cube2)
{
  for(int i=0;i<6;i++)
  {
    for(int j=0;j<9;j++)
    {
      if(cube1[i][j]!=cube2[i][j])
      return 0;
    }
  }

  return 1;
}


int check_visited(struct queue* OPEN, struct queue* CLOSED, struct cube c1)
{
  int flag=0;
  struct node *openptr, *closedptr;
  openptr=OPEN->front;
  closedptr=CLOSED->front;
  while(openptr!=NULL || closedptr!=NULL)
  {
    if(openptr!=NULL)
    {
      if(compare_cubes(openptr->cube, c1))
      {
        flag=1;
        break;
      }
      openptr=openptr->next;
    }

    if(closedptr!=NULL)
    {
      if(compare_cubes(closedptr->cube, c1))
      {
        flag=1;
        break;
      }
      closedptr=closedptr->next;
    }
  }
  return flag;
}

void movGen(struct queue* OPEN, struct queue* CLOSED, struct node* picked_node)
{
  int flag;
  struct cube c;
  char str[][] = {"R", "R2", "R\'","L", "L2", "L\'","D", "D2", "D\'","U", "U2", "U\'","F", "F2", "F\'","B", "B2", "B\'","\0"};
  char **s=str;
  while(**s != '\0')
  {
    c=move(picked_node->cube, *s);
    if(check_visited(OPEN,CLOSED,c)==0)
    {
      enqueue(OPEN, c);
    }
    s++;
  }
}

int main()
{

  //Declaration section
  char str[500];
  struct cube cube;
  struct queue OPEN;
  struct queue CLOSED;
  struct node * picked_node;

  initialize_q(OPEN);
  initialize_q(CLOSED);

  cube = initialize_cube();

  printf("Enter the scramble: ");
  gets(str);
  for(int i=0;i<strlen(str);i++)
  {
    if(str[i]=='R')
    {
      if(str[i+1]=='\'')
      {
        cube=move(cube,"R\'");
        i++;
      }
      else if(str[i+1]=='2')
      {
        cube=move(cube,"R2");
        i++;
      }
      else
      {
        cube=move(cube,"R");
      }
    }


    if(str[i]=='U')
    {
      if(str[i+1]=='\'')
      {
        cube=move(cube,"U\'");
        i++;
      }
      else if(str[i+1]=='2')
      {
        cube=move(cube,"U2");
        i++;
      }
      else
      {
        cube=move(cube,"U");
      }
    }


    if(str[i]=='F')
    {
      if(str[i+1]=='\'')
      {
        cube=move(cube,"F\'");
        i++;
      }
      else if(str[i+1]=='2')
      {
        cube=move(cube,"F2");
        i++;
      }
      else
      {
        cube=move(cube,"F");
      }
    }


    if(str[i]=='D')
    {
      if(str[i+1]=='\'')
      {
        cube=move(cube,"D\'");
        i++;
      }
      else if(str[i+1]=='2')
      {
        cube=move(cube,"D2");
        i++;
      }
      else
      {
        cube=move(cube,"D");
      }
    }


    if(str[i]=='L')
    {
      if(str[i+1]=='\'')
      {
        cube=move(cube,"L\'");
        i++;
      }
      else if(str[i+1]=='2')
      {
        cube=move(cube,"L2");
        i++;
      }
      else
      {
        cube=move(cube,"L");
      }
    }


    if(str[i]=='B')
    {
      if(str[i+1]=='\'')
      {
        cube=move(cube,"B\'");
        i++;
      }
      else if(str[i+1]=='2')
      {
        cube=move(cube,"B2");
        i++;
      }
      else
      {
        cube=move(cube,"B");
      }
    }
  }

  enqueue(&OPEN, cube);


  while(!goalstate())
  {
    moveGen(&OPEN, &CLOSED, picked_node);
    picked_node = dequeue(&OPEN);
    check_node(picked_node);
  }
}
