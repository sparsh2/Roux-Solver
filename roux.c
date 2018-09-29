#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char wg[10]={'\0'};
char wb[10]={'\0'};
char wo[10]={'\0'};
char wr[10]={'\0'};
char yg[10]={'\0'};
char yb[10]={'\0'};
char yo[10]={'\0'};
char yr[10]={'\0'};

struct cube
{
  char cube[6][9];
  char moves[60];
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
  if(ptr==NULL)
  {
    printf("No memory allocated!");
    exit(0);
  }
  ptr->cube = cube;
  if(q->front == NULL)
  {
    q->front = ptr;
    q->rear = ptr;
    q->front->next=NULL;
    q->rear->next=NULL;
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
  if(q->front==NULL && q->rear==NULL)
  {
    ptr=NULL;
    return ptr;
  }
  else if(q->front==q->rear)
  {
    ptr=q->front;
    q->front=q->rear=NULL;
    ptr->next=NULL;
    return ptr;
  }
  else
  {
    ptr=q->front;
    q->front=q->front->next;
    ptr->next=NULL;
    return ptr;
  }
}

void delete_node(struct node *ptr)
{
  free(ptr);
}



struct cube R_move(struct cube cube)
{
  struct cube cube1=cube;

  cube.cube[0][2]=cube1.cube[5][2];
  cube.cube[0][5]=cube1.cube[5][5];
  cube.cube[0][8]=cube1.cube[5][8];

  cube.cube[4][2]=cube1.cube[0][2];
  cube.cube[4][5]=cube1.cube[0][5];
  cube.cube[4][8]=cube1.cube[0][8];

  cube.cube[1][6]=cube1.cube[4][2];
  cube.cube[1][3]=cube1.cube[4][5];
  cube.cube[1][0]=cube1.cube[4][8];

  cube.cube[5][2]=cube1.cube[1][6];
  cube.cube[5][5]=cube1.cube[1][3];
  cube.cube[5][8]=cube1.cube[1][0];

  cube.cube[2][0]=cube1.cube[2][6];
  cube.cube[2][3]=cube1.cube[2][7];
  cube.cube[2][6]=cube1.cube[2][8];

  cube.cube[2][2]=cube1.cube[2][0];
  cube.cube[2][1]=cube1.cube[2][3];
  cube.cube[2][0]=cube1.cube[2][6];

  cube.cube[2][8]=cube1.cube[2][2];
  cube.cube[2][5]=cube1.cube[2][1];
  cube.cube[2][2]=cube1.cube[2][0];

  cube.cube[2][6]=cube1.cube[2][8];
  cube.cube[2][7]=cube1.cube[2][5];
  cube.cube[2][8]=cube1.cube[2][2];

  return cube;
}



struct cube L_move(struct cube cube)
{
  struct cube cube1=cube;

  cube.cube[4][0]=cube1.cube[1][8];
  cube.cube[4][3]=cube1.cube[1][5];
  cube.cube[4][6]=cube1.cube[1][2];

  cube.cube[0][0]=cube1.cube[4][0];
  cube.cube[0][3]=cube1.cube[4][3];
  cube.cube[0][6]=cube1.cube[4][6];

  cube.cube[5][0]=cube1.cube[0][0];
  cube.cube[5][3]=cube1.cube[0][3];
  cube.cube[5][6]=cube1.cube[0][6];

  cube.cube[1][8]=cube1.cube[5][0];
  cube.cube[1][5]=cube1.cube[5][3];
  cube.cube[1][2]=cube1.cube[5][6];

  cube.cube[3][0]=cube1.cube[3][6];
  cube.cube[3][3]=cube1.cube[3][7];
  cube.cube[3][6]=cube1.cube[3][8];

  cube.cube[3][2]=cube1.cube[3][0];
  cube.cube[3][1]=cube1.cube[3][3];
  cube.cube[3][0]=cube1.cube[3][6];

  cube.cube[3][8]=cube1.cube[3][2];
  cube.cube[3][5]=cube1.cube[3][1];
  cube.cube[3][2]=cube1.cube[3][0];

  cube.cube[3][6]=cube1.cube[3][8];
  cube.cube[3][7]=cube1.cube[3][5];
  cube.cube[3][8]=cube1.cube[3][2];

  return cube;
}



struct cube F_move(struct cube cube)
{
  struct cube cube1=cube;

  cube.cube[5][0]=cube1.cube[2][6];
  cube.cube[5][1]=cube1.cube[2][3];
  cube.cube[5][2]=cube1.cube[2][0];

  cube.cube[3][2]=cube1.cube[5][0];
  cube.cube[3][5]=cube1.cube[5][1];
  cube.cube[3][8]=cube1.cube[5][2];

  cube.cube[4][8]=cube1.cube[3][2];
  cube.cube[4][7]=cube1.cube[3][5];
  cube.cube[4][6]=cube1.cube[3][8];

  cube.cube[2][6]=cube1.cube[4][8];
  cube.cube[2][3]=cube1.cube[4][7];
  cube.cube[2][0]=cube1.cube[4][6];

  cube.cube[0][0]=cube1.cube[0][6];
  cube.cube[0][1]=cube1.cube[0][3];
  cube.cube[0][2]=cube1.cube[0][0];

  cube.cube[0][2]=cube1.cube[0][0];
  cube.cube[0][5]=cube1.cube[0][1];
  cube.cube[0][8]=cube1.cube[0][2];

  cube.cube[0][8]=cube1.cube[0][2];
  cube.cube[0][7]=cube1.cube[0][5];
  cube.cube[0][6]=cube1.cube[0][8];

  cube.cube[0][0]=cube1.cube[0][6];
  cube.cube[0][3]=cube1.cube[0][7];
  cube.cube[0][6]=cube1.cube[0][8];

  return cube;
}


struct cube B_move(struct cube cube)
{
  struct cube cube1=cube;

  cube.cube[4][0]=cube1.cube[2][2];
  cube.cube[4][1]=cube1.cube[2][5];
  cube.cube[4][2]=cube1.cube[2][8];

  cube.cube[3][0]=cube1.cube[4][2];
  cube.cube[3][3]=cube1.cube[4][1];
  cube.cube[3][6]=cube1.cube[4][0];

  cube.cube[5][8]=cube1.cube[3][6];
  cube.cube[5][7]=cube1.cube[3][3];
  cube.cube[5][6]=cube1.cube[3][0];

  cube.cube[2][2]=cube1.cube[5][8];
  cube.cube[2][5]=cube1.cube[5][7];
  cube.cube[2][8]=cube1.cube[5][6];

  cube.cube[1][0]=cube1.cube[1][6];
  cube.cube[1][1]=cube1.cube[1][3];
  cube.cube[1][2]=cube1.cube[1][0];

  cube.cube[1][2]=cube1.cube[1][0];
  cube.cube[1][5]=cube1.cube[1][1];
  cube.cube[1][8]=cube1.cube[1][2];

  cube.cube[1][8]=cube1.cube[1][2];
  cube.cube[1][7]=cube1.cube[1][5];
  cube.cube[1][6]=cube1.cube[1][8];

  cube.cube[1][0]=cube1.cube[1][6];
  cube.cube[1][3]=cube1.cube[1][7];
  cube.cube[1][6]=cube1.cube[1][8];

  return cube;
}


struct cube U_move(struct cube cube)
{
  struct cube cube1=cube;

  cube.cube[0][0]=cube1.cube[2][0];
  cube.cube[0][1]=cube1.cube[2][1];
  cube.cube[0][2]=cube1.cube[2][2];

  cube.cube[2][0]=cube1.cube[1][0];
  cube.cube[2][1]=cube1.cube[1][1];
  cube.cube[2][2]=cube1.cube[1][2];

  cube.cube[1][0]=cube1.cube[3][0];
  cube.cube[1][1]=cube1.cube[3][1];
  cube.cube[1][2]=cube1.cube[3][2];

  cube.cube[3][0]=cube1.cube[0][0];
  cube.cube[3][1]=cube1.cube[0][1];
  cube.cube[3][2]=cube1.cube[0][2];

  cube.cube[4][6]=cube1.cube[4][8];
  cube.cube[4][7]=cube1.cube[4][5];
  cube.cube[4][8]=cube1.cube[4][2];

  cube.cube[4][0]=cube1.cube[4][6];
  cube.cube[4][3]=cube1.cube[4][7];
  cube.cube[4][6]=cube1.cube[4][8];

  cube.cube[4][2]=cube1.cube[4][0];
  cube.cube[4][1]=cube1.cube[4][3];
  cube.cube[4][0]=cube1.cube[4][6];

  cube.cube[4][8]=cube1.cube[4][2];
  cube.cube[4][5]=cube1.cube[4][1];
  cube.cube[4][2]=cube1.cube[4][0];

  return cube;
}


struct cube D_move(struct cube cube)
{
  struct cube cube1=cube;

  cube.cube[0][6]=cube1.cube[3][6];
  cube.cube[0][7]=cube1.cube[3][7];
  cube.cube[0][8]=cube1.cube[3][8];

  cube.cube[2][6]=cube1.cube[0][6];
  cube.cube[2][7]=cube1.cube[0][7];
  cube.cube[2][8]=cube1.cube[0][8];

  cube.cube[1][6]=cube1.cube[2][6];
  cube.cube[1][7]=cube1.cube[2][7];
  cube.cube[1][8]=cube1.cube[2][8];

  cube.cube[3][6]=cube1.cube[1][6];
  cube.cube[3][7]=cube1.cube[1][7];
  cube.cube[3][8]=cube1.cube[1][8];

  cube.cube[5][6]=cube1.cube[5][8];
  cube.cube[5][7]=cube1.cube[5][5];
  cube.cube[5][8]=cube1.cube[5][2];

  cube.cube[5][0]=cube1.cube[5][6];
  cube.cube[5][3]=cube1.cube[5][7];
  cube.cube[5][6]=cube1.cube[5][8];

  cube.cube[5][2]=cube1.cube[5][0];
  cube.cube[5][1]=cube1.cube[5][3];
  cube.cube[5][0]=cube1.cube[5][6];

  cube.cube[5][8]=cube1.cube[5][2];
  cube.cube[5][5]=cube1.cube[5][1];
  cube.cube[5][2]=cube1.cube[5][0];

  return cube;
}


void check_node(struct node* ptr, struct queue *CLOSED)
{
  struct cube cube=ptr->cube;
  if
  (
    ((cube.cube[0][0] == 'G' &&
    cube.cube[0][1] == 'G' &&
    cube.cube[0][2] == 'G' &&
    cube.cube[0][3] == 'G' &&
    cube.cube[0][4] == 'G' &&
    cube.cube[0][5] == 'G' &&

    cube.cube[4][6] == 'W' &&
    cube.cube[4][7] == 'W' &&
    cube.cube[4][8] == 'W' &&

    cube.cube[2][0] == 'R' &&
    cube.cube[2][3] == 'R' &&

    cube.cube[3][2] == 'O' &&
    cube.cube[3][5] == 'O') ||

    (cube.cube[0][0] == 'G' &&
    cube.cube[0][1] == 'G' &&
    cube.cube[0][6] == 'G' &&
    cube.cube[0][3] == 'G' &&
    cube.cube[0][4] == 'G' &&
    cube.cube[0][7] == 'G' &&

    cube.cube[3][2] == 'W' &&
    cube.cube[3][5] == 'W' &&
    cube.cube[3][8] == 'W' &&

    cube.cube[4][6] == 'R' &&
    cube.cube[4][7] == 'R' &&

    cube.cube[5][0] == 'O' &&
    cube.cube[5][1] == 'O') ||

    (cube.cube[0][6] == 'G' &&
    cube.cube[0][7] == 'G' &&
    cube.cube[0][8] == 'G' &&
    cube.cube[0][3] == 'G' &&
    cube.cube[0][4] == 'G' &&
    cube.cube[0][5] == 'G' &&

    cube.cube[5][0] == 'W' &&
    cube.cube[5][1] == 'W' &&
    cube.cube[5][2] == 'W' &&

    cube.cube[3][8] == 'R' &&
    cube.cube[3][5] == 'R' &&

    cube.cube[2][6] == 'O' &&
    cube.cube[2][3] == 'O') ||

    (cube.cube[0][7] == 'G' &&
    cube.cube[0][1] == 'G' &&
    cube.cube[0][2] == 'G' &&
    cube.cube[0][8] == 'G' &&
    cube.cube[0][4] == 'G' &&
    cube.cube[0][5] == 'G' &&

    cube.cube[2][6] == 'W' &&
    cube.cube[2][3] == 'W' &&
    cube.cube[2][0] == 'W' &&

    cube.cube[5][1] == 'R' &&
    cube.cube[5][2] == 'R' &&

    cube.cube[4][7] == 'O' &&
    cube.cube[4][8] == 'O'))&&
    wg[0]=='\0'
  )
  {
    strcat(wg,cube.moves);
    printf("\nWhite-Green block: %s", wg);
  }


  if
  (
    ((cube.cube[2][0] == 'R' &&
    cube.cube[2][1] == 'R' &&
    cube.cube[2][2] == 'R' &&
    cube.cube[2][3] == 'R' &&
    cube.cube[2][4] == 'R' &&
    cube.cube[2][5] == 'R' &&

    cube.cube[4][2] == 'W' &&
    cube.cube[4][5] == 'W' &&
    cube.cube[4][8] == 'W' &&

    cube.cube[0][2] == 'G' &&
    cube.cube[0][5] == 'G' &&

    cube.cube[1][3] == 'B' &&
    cube.cube[1][0] == 'B') ||

    (cube.cube[2][7] == 'R' &&
    cube.cube[2][1] == 'R' &&
    cube.cube[2][2] == 'R' &&
    cube.cube[2][8] == 'R' &&
    cube.cube[2][4] == 'R' &&
    cube.cube[2][5] == 'R' &&

    cube.cube[1][6] == 'W' &&
    cube.cube[1][3] == 'W' &&
    cube.cube[1][0] == 'W' &&

    cube.cube[4][2] == 'G' &&
    cube.cube[4][5] == 'G' &&

    cube.cube[5][5] == 'B' &&
    cube.cube[5][8] == 'B') ||

    (cube.cube[2][7] == 'R' &&
    cube.cube[2][3] == 'R' &&
    cube.cube[2][6] == 'R' &&
    cube.cube[2][8] == 'R' &&
    cube.cube[2][4] == 'R' &&
    cube.cube[2][5] == 'R' &&

    cube.cube[5][2] == 'W' &&
    cube.cube[5][5] == 'W' &&
    cube.cube[5][8] == 'W' &&

    cube.cube[1][6] == 'G' &&
    cube.cube[1][3] == 'G' &&

    cube.cube[0][5] == 'B' &&
    cube.cube[0][8] == 'B') ||

    (cube.cube[2][7] == 'R' &&
    cube.cube[2][3] == 'R' &&
    cube.cube[2][6] == 'R' &&
    cube.cube[2][0] == 'R' &&
    cube.cube[2][4] == 'R' &&
    cube.cube[2][1] == 'R' &&

    cube.cube[0][2] == 'W' &&
    cube.cube[0][5] == 'W' &&
    cube.cube[0][8] == 'W' &&

    cube.cube[4][5] == 'B' &&
    cube.cube[4][8] == 'B' &&

    cube.cube[5][2] == 'G' &&
    cube.cube[5][5] == 'G'))&&
    wr[0]=='\0'
  )
  {
    strcat(wr,cube.moves);
    printf("\nWhite-Red block: %s", wr);
  }

  if
  (
    ((cube.cube[3][0] == 'O' &&
    cube.cube[3][1] == 'O' &&
    cube.cube[3][2] == 'O' &&
    cube.cube[3][3] == 'O' &&
    cube.cube[3][4] == 'O' &&
    cube.cube[3][5] == 'O' &&

    cube.cube[4][0] == 'W' &&
    cube.cube[4][3] == 'W' &&
    cube.cube[4][6] == 'W' &&

    cube.cube[1][5] == 'B' &&
    cube.cube[1][2] == 'B' &&

    cube.cube[0][0] == 'G' &&
    cube.cube[0][3] == 'G') ||

    (cube.cube[3][7] == 'O' &&
    cube.cube[3][1] == 'O' &&
    cube.cube[3][2] == 'O' &&
    cube.cube[3][8] == 'O' &&
    cube.cube[3][4] == 'O' &&
    cube.cube[3][5] == 'O' &&

    cube.cube[0][0] == 'W' &&
    cube.cube[0][3] == 'W' &&
    cube.cube[0][6] == 'W' &&

    cube.cube[4][3] == 'B' &&
    cube.cube[4][6] == 'B' &&

    cube.cube[5][0] == 'G' &&
    cube.cube[5][3] == 'G') ||

    (cube.cube[3][7] == 'O' &&
    cube.cube[3][6] == 'O' &&
    cube.cube[3][8] == 'O' &&
    cube.cube[3][3] == 'O' &&
    cube.cube[3][4] == 'O' &&
    cube.cube[3][5] == 'O' &&

    cube.cube[3][0] == 'W' &&
    cube.cube[3][3] == 'W' &&
    cube.cube[3][6] == 'W' &&

    cube.cube[0][3] == 'B' &&
    cube.cube[0][6] == 'B' &&

    cube.cube[1][8] == 'G' &&
    cube.cube[1][5] == 'G') ||

    (cube.cube[3][0] == 'O' &&
    cube.cube[3][1] == 'O' &&
    cube.cube[3][6] == 'O' &&
    cube.cube[3][3] == 'O' &&
    cube.cube[3][4] == 'O' &&
    cube.cube[3][7] == 'O' &&

    cube.cube[1][2] == 'W' &&
    cube.cube[1][5] == 'W' &&
    cube.cube[1][8] == 'W' &&

    cube.cube[5][3] == 'B' &&
    cube.cube[5][6] == 'B' &&

    cube.cube[4][0] == 'G' &&
    cube.cube[4][3] == 'G'))&&
    wo[0]=='\0'
  )
  {
    strcat(wo,cube.moves);
    printf("\nWhite-Orange block: %s", wo);
  }

  if
  (
    ((cube.cube[1][0] == 'B' &&
    cube.cube[1][1] == 'B' &&
    cube.cube[1][6] == 'B' &&
    cube.cube[1][3] == 'B' &&
    cube.cube[1][4] == 'B' &&
    cube.cube[1][7] == 'B' &&

    cube.cube[2][2] == 'W' &&
    cube.cube[2][5] == 'W' &&
    cube.cube[2][8] == 'W' &&

    cube.cube[5][7] == 'R' &&
    cube.cube[5][8] == 'R' &&

    cube.cube[4][1] == 'O' &&
    cube.cube[4][2] == 'O') ||

    (cube.cube[1][0] == 'B' &&
    cube.cube[1][1] == 'B' &&
    cube.cube[1][2] == 'B' &&
    cube.cube[1][3] == 'B' &&
    cube.cube[1][4] == 'B' &&
    cube.cube[1][5] == 'B' &&

    cube.cube[4][0] == 'W' &&
    cube.cube[4][1] == 'W' &&
    cube.cube[4][2] == 'W' &&

    cube.cube[2][2] == 'R' &&
    cube.cube[2][5] == 'R' &&

    cube.cube[3][0] == 'O' &&
    cube.cube[3][3] == 'O') ||

    (cube.cube[1][7] == 'B' &&
    cube.cube[1][1] == 'B' &&
    cube.cube[1][2] == 'B' &&
    cube.cube[1][8] == 'B' &&
    cube.cube[1][4] == 'B' &&
    cube.cube[1][5] == 'B' &&

    cube.cube[3][0] == 'W' &&
    cube.cube[3][3] == 'W' &&
    cube.cube[3][6] == 'W' &&

    cube.cube[4][0] == 'R' &&
    cube.cube[4][1] == 'R' &&

    cube.cube[5][6] == 'O' &&
    cube.cube[5][7] == 'O') ||

    (cube.cube[1][7] == 'B' &&
    cube.cube[1][6] == 'B' &&
    cube.cube[1][3] == 'B' &&
    cube.cube[1][8] == 'B' &&
    cube.cube[1][4] == 'B' &&
    cube.cube[1][5] == 'B' &&

    cube.cube[5][6] == 'W' &&
    cube.cube[5][7] == 'W' &&
    cube.cube[5][8] == 'W' &&

    cube.cube[3][6] == 'R' &&
    cube.cube[3][3] == 'R' &&

    cube.cube[2][8] == 'O' &&
    cube.cube[2][5] == 'O'))&&
    wb[0]=='\0'
  )
  {
    strcat(wb,cube.moves);
    printf("\nWhite-Blue block: %s", wb);
  }


  if
  (
    ((cube.cube[1][0] == 'B' &&
    cube.cube[1][1] == 'B' &&
    cube.cube[1][6] == 'B' &&
    cube.cube[1][3] == 'B' &&
    cube.cube[1][4] == 'B' &&
    cube.cube[1][7] == 'B' &&

    cube.cube[2][2] == 'Y' &&
    cube.cube[2][5] == 'Y' &&
    cube.cube[2][8] == 'Y' &&

    cube.cube[5][7] == 'O' &&
    cube.cube[5][8] == 'O' &&

    cube.cube[4][1] == 'R' &&
    cube.cube[4][2] == 'R') ||

    (cube.cube[1][0] == 'B' &&
    cube.cube[1][1] == 'B' &&
    cube.cube[1][2] == 'B' &&
    cube.cube[1][3] == 'B' &&
    cube.cube[1][4] == 'B' &&
    cube.cube[1][5] == 'B' &&

    cube.cube[4][0] == 'Y' &&
    cube.cube[4][1] == 'Y' &&
    cube.cube[4][2] == 'Y' &&

    cube.cube[2][2] == 'O' &&
    cube.cube[2][5] == 'O' &&

    cube.cube[3][0] == 'R' &&
    cube.cube[3][3] == 'R') ||

    (cube.cube[1][7] == 'B' &&
    cube.cube[1][1] == 'B' &&
    cube.cube[1][2] == 'B' &&
    cube.cube[1][8] == 'B' &&
    cube.cube[1][4] == 'B' &&
    cube.cube[1][5] == 'B' &&

    cube.cube[3][0] == 'Y' &&
    cube.cube[3][3] == 'Y' &&
    cube.cube[3][6] == 'Y' &&

    cube.cube[4][0] == 'O' &&
    cube.cube[4][1] == 'O' &&

    cube.cube[5][6] == 'R' &&
    cube.cube[5][7] == 'R') ||

    (cube.cube[1][7] == 'B' &&
    cube.cube[1][6] == 'B' &&
    cube.cube[1][3] == 'B' &&
    cube.cube[1][8] == 'B' &&
    cube.cube[1][4] == 'B' &&
    cube.cube[1][5] == 'B' &&

    cube.cube[5][6] == 'Y' &&
    cube.cube[5][7] == 'Y' &&
    cube.cube[5][8] == 'Y' &&

    cube.cube[3][6] == 'O' &&
    cube.cube[3][3] == 'O' &&

    cube.cube[2][8] == 'R' &&
    cube.cube[2][5] == 'R'))&&
    yb[0]=='\0'
  )
  {
    strcat(yb,cube.moves);
    printf("\nYellow-Blue block: %s", yb);
  }


  if
  (
    ((cube.cube[3][0] == 'O' &&
    cube.cube[3][1] == 'O' &&
    cube.cube[3][2] == 'O' &&
    cube.cube[3][3] == 'O' &&
    cube.cube[3][4] == 'O' &&
    cube.cube[3][5] == 'O' &&

    cube.cube[4][0] == 'Y' &&
    cube.cube[4][3] == 'Y' &&
    cube.cube[4][6] == 'Y' &&

    cube.cube[1][5] == 'G' &&
    cube.cube[1][2] == 'G' &&

    cube.cube[0][0] == 'B' &&
    cube.cube[0][3] == 'B') ||

    (cube.cube[3][7] == 'O' &&
    cube.cube[3][1] == 'O' &&
    cube.cube[3][2] == 'O' &&
    cube.cube[3][8] == 'O' &&
    cube.cube[3][4] == 'O' &&
    cube.cube[3][5] == 'O' &&

    cube.cube[0][0] == 'Y' &&
    cube.cube[0][3] == 'Y' &&
    cube.cube[0][6] == 'Y' &&

    cube.cube[4][3] == 'G' &&
    cube.cube[4][6] == 'G' &&

    cube.cube[5][0] == 'B' &&
    cube.cube[5][3] == 'B') ||

    (cube.cube[3][7] == 'O' &&
    cube.cube[3][6] == 'O' &&
    cube.cube[3][8] == 'O' &&
    cube.cube[3][3] == 'O' &&
    cube.cube[3][4] == 'O' &&
    cube.cube[3][5] == 'O' &&

    cube.cube[3][0] == 'Y' &&
    cube.cube[3][3] == 'Y' &&
    cube.cube[3][6] == 'Y' &&

    cube.cube[0][3] == 'G' &&
    cube.cube[0][6] == 'G' &&

    cube.cube[1][8] == 'B' &&
    cube.cube[1][5] == 'B') ||

    (cube.cube[3][0] == 'O' &&
    cube.cube[3][1] == 'O' &&
    cube.cube[3][6] == 'O' &&
    cube.cube[3][3] == 'O' &&
    cube.cube[3][4] == 'O' &&
    cube.cube[3][7] == 'O' &&

    cube.cube[1][2] == 'Y' &&
    cube.cube[1][5] == 'Y' &&
    cube.cube[1][8] == 'Y' &&

    cube.cube[5][3] == 'G' &&
    cube.cube[5][6] == 'G' &&

    cube.cube[4][0] == 'B' &&
    cube.cube[4][3] == 'B'))&&
    yo[0]=='\0'
  )
  {
    strcat(yo,cube.moves);
    printf("\nYellow-Orange block: %s", yo);
  }

  if
  (
    ((cube.cube[2][0] == 'R' &&
    cube.cube[2][1] == 'R' &&
    cube.cube[2][2] == 'R' &&
    cube.cube[2][3] == 'R' &&
    cube.cube[2][4] == 'R' &&
    cube.cube[2][5] == 'R' &&

    cube.cube[4][2] == 'Y' &&
    cube.cube[4][5] == 'Y' &&
    cube.cube[4][8] == 'Y' &&

    cube.cube[0][2] == 'B' &&
    cube.cube[0][5] == 'B' &&

    cube.cube[1][3] == 'G' &&
    cube.cube[1][0] == 'G') ||

    (cube.cube[2][7] == 'R' &&
    cube.cube[2][1] == 'R' &&
    cube.cube[2][2] == 'R' &&
    cube.cube[2][8] == 'R' &&
    cube.cube[2][4] == 'R' &&
    cube.cube[2][5] == 'R' &&

    cube.cube[1][6] == 'Y' &&
    cube.cube[1][3] == 'Y' &&
    cube.cube[1][0] == 'Y' &&

    cube.cube[4][2] == 'B' &&
    cube.cube[4][5] == 'B' &&

    cube.cube[5][5] == 'G' &&
    cube.cube[5][8] == 'G') ||

    (cube.cube[2][7] == 'R' &&
    cube.cube[2][3] == 'R' &&
    cube.cube[2][6] == 'R' &&
    cube.cube[2][8] == 'R' &&
    cube.cube[2][4] == 'R' &&
    cube.cube[2][5] == 'R' &&

    cube.cube[5][2] == 'Y' &&
    cube.cube[5][5] == 'Y' &&
    cube.cube[5][8] == 'Y' &&

    cube.cube[1][6] == 'B' &&
    cube.cube[1][3] == 'B' &&

    cube.cube[0][5] == 'G' &&
    cube.cube[0][8] == 'G') ||

    (cube.cube[2][7] == 'R' &&
    cube.cube[2][3] == 'R' &&
    cube.cube[2][6] == 'R' &&
    cube.cube[2][0] == 'R' &&
    cube.cube[2][4] == 'R' &&
    cube.cube[2][1] == 'R' &&

    cube.cube[0][2] == 'Y' &&
    cube.cube[0][5] == 'Y' &&
    cube.cube[0][8] == 'Y' &&

    cube.cube[4][5] == 'G' &&
    cube.cube[4][8] == 'G' &&

    cube.cube[5][2] == 'B' &&
    cube.cube[5][5] == 'B'))&&
    yr[0]=='\0'
  )
  {
    strcat(yr,cube.moves);
    printf("\nYellow-Red block: %s", yr);
  }

  if
  (
    ((cube.cube[0][0] == 'G' &&
    cube.cube[0][1] == 'G' &&
    cube.cube[0][2] == 'G' &&
    cube.cube[0][3] == 'G' &&
    cube.cube[0][4] == 'G' &&
    cube.cube[0][5] == 'G' &&

    cube.cube[4][6] == 'Y' &&
    cube.cube[4][7] == 'Y' &&
    cube.cube[4][8] == 'Y' &&

    cube.cube[2][0] == 'O' &&
    cube.cube[2][3] == 'O' &&

    cube.cube[3][2] == 'R' &&
    cube.cube[3][5] == 'R') ||

    (cube.cube[0][0] == 'G' &&
    cube.cube[0][1] == 'G' &&
    cube.cube[0][6] == 'G' &&
    cube.cube[0][3] == 'G' &&
    cube.cube[0][4] == 'G' &&
    cube.cube[0][7] == 'G' &&

    cube.cube[3][2] == 'Y' &&
    cube.cube[3][5] == 'Y' &&
    cube.cube[3][8] == 'Y' &&

    cube.cube[4][6] == 'O' &&
    cube.cube[4][7] == 'O' &&

    cube.cube[5][0] == 'R' &&
    cube.cube[5][1] == 'R') ||

    (cube.cube[0][6] == 'G' &&
    cube.cube[0][7] == 'G' &&
    cube.cube[0][8] == 'G' &&
    cube.cube[0][3] == 'G' &&
    cube.cube[0][4] == 'G' &&
    cube.cube[0][5] == 'G' &&

    cube.cube[5][0] == 'Y' &&
    cube.cube[5][1] == 'Y' &&
    cube.cube[5][2] == 'Y' &&

    cube.cube[3][8] == 'O' &&
    cube.cube[3][5] == 'O' &&

    cube.cube[2][6] == 'R' &&
    cube.cube[2][3] == 'R') ||

    (cube.cube[0][7] == 'G' &&
    cube.cube[0][1] == 'G' &&
    cube.cube[0][2] == 'G' &&
    cube.cube[0][8] == 'G' &&
    cube.cube[0][4] == 'G' &&
    cube.cube[0][5] == 'G' &&

    cube.cube[2][6] == 'Y' &&
    cube.cube[2][3] == 'Y' &&
    cube.cube[2][0] == 'Y' &&

    cube.cube[5][1] == 'O' &&
    cube.cube[5][2] == 'O' &&

    cube.cube[4][7] == 'R' &&
    cube.cube[4][8] == 'R'))&&
    yg[0]=='\0'
  )
  {
    strcat(yg,cube.moves);
    printf("\nYellow-Green block: %s", yg);
  }

  enqueue(CLOSED, cube);
}

struct cube move(struct cube cube, char move[2])
{

  char ss[2]={' ', '\0'};
  if(move=="R")
  {
    strcat(cube.moves, ss);
    strcat(cube.moves, move);
    cube=R_move(cube);
    return cube;
  }

  else if(move=="R2")
  {
    strcat(cube.moves, ss);
    strcat(cube.moves, move);
    cube=R_move(cube);
    cube=R_move(cube);
    return cube;
  }

  else if(move=="R\'")
  {
    strcat(cube.moves, ss);
    strcat(cube.moves, move);
    cube=R_move(cube);
    cube=R_move(cube);
    cube=R_move(cube);
    return cube;
  }

  else if(move=="F")
  {
    strcat(cube.moves, ss);
    strcat(cube.moves, move);
    cube=F_move(cube);
    return cube;
  }

  else if(move=="F\'")
  {
    strcat(cube.moves, ss);
    strcat(cube.moves, move);
    cube=F_move(cube);
    cube=F_move(cube);
    cube=F_move(cube);
    return cube;
  }

  else if(move=="F2")
  {
    strcat(cube.moves, ss);
    strcat(cube.moves, move);
    cube=F_move(cube);
    cube=F_move(cube);
    return cube;
  }

  else if(move=="U")
  {
    strcat(cube.moves, ss);
    strcat(cube.moves, move);
    cube=U_move(cube);
    return cube;
  }

  else if(move=="U\'")
  {
    strcat(cube.moves, ss);
    strcat(cube.moves, move);
    cube=U_move(cube);
    cube=U_move(cube);
    cube=U_move(cube);
    return cube;
  }

  else if(move=="U2")
  {
    strcat(cube.moves, ss);
    strcat(cube.moves, move);
    cube=U_move(cube);
    cube=U_move(cube);
    return cube;
  }

  else if(move=="L")
  {
    strcat(cube.moves, ss);
    strcat(cube.moves, move);
    cube=L_move(cube);
    return cube;
  }

  else if(move=="L\'")
  {
    strcat(cube.moves, ss);
    strcat(cube.moves, move);
    cube=L_move(cube);
    cube=L_move(cube);
    cube=L_move(cube);
    return cube;
  }

  else if(move=="L2")
  {
    strcat(cube.moves, ss);
    strcat(cube.moves, move);
    cube=L_move(cube);
    cube=L_move(cube);
    return cube;
  }

  else if(move=="D")
  {
    strcat(cube.moves, ss);
    strcat(cube.moves, move);
    cube=D_move(cube);
    return cube;
  }

  else if(move=="D\'")
  {
    strcat(cube.moves, ss);
    strcat(cube.moves, move);
    cube=D_move(cube);
    cube=D_move(cube);
    cube=D_move(cube);
    return cube;
  }

  else if(move=="D2")
  {
    strcat(cube.moves, ss);
    strcat(cube.moves, move);
    cube=D_move(cube);
    cube=D_move(cube);
    return cube;
  }

  else if(move=="B")
  {
    strcat(cube.moves, ss);
    strcat(cube.moves, move);
    cube=B_move(cube);
    return cube;
  }

  else if(move=="B\'")
  {
    strcat(cube.moves, ss);
    strcat(cube.moves, move);
    cube=B_move(cube);
    cube=B_move(cube);
    cube=B_move(cube);
    return cube;
  }

  else if(move=="B2")
  {
    strcat(cube.moves, ss);
    strcat(cube.moves, move);
    cube=B_move(cube);
    cube=B_move(cube);
    return cube;
  }

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
  cube.moves[0]='\0';
  return cube;
}

int compare_cubes(struct cube cube1,struct cube cube2)
{
  for(int i=0;i<6;i++)
  {
    for(int j=0;j<9;j++)
    {
      if(cube1.cube[i][j]!=cube2.cube[i][j])
      return 0;
    }
  }
  return 1;
}

char recheck(char *s)
{
  int i;
  for(i=strlen(s)-1;i>=0;i--)
  {
    if(s[i]!=' ' && s[i]!='\'' && s[i]!='2')
    break;
  }
  return s[i];
}


int check_visited(struct queue* OPEN, struct queue* CLOSED, struct cube c1)
{
  int flag=0;
  struct node *openptr;
  struct node *closedptr;
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

void moveGen(struct queue* OPEN, struct queue* CLOSED, struct node* picked_node)
{
  struct cube c;
  char *str[19] ={
    "R","R2","R\'",
    "L","L2","L\'",
    "F","F2","F\'",
    "B","B2","B\'",
    "U","U2","U\'",
    "D","D2","D\'",
    ""
  };
  char **s=str;

  while(**s != '\0')
  {
    if(**s!=recheck(picked_node->cube.moves))
    {
      c=move(picked_node->cube, *s);
      enqueue(OPEN, c);
    }
    s++;
  }
  delete_node(picked_node);
}



int goalstate()
{
  if
  (
    yr[0]!='\0' ||
    yg[0]!='\0' ||
    yb[0]!='\0' ||
    yo[0]!='\0' ||
    wr[0]!='\0' ||
    wg[0]!='\0' ||
    wb[0]!='\0' ||
    wo[0]!='\0'
  )
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

void delete_all(struct queue *OPEN, struct queue *CLOSED)
{
  struct node *openptr, *closedptr, *temp;
  openptr=OPEN->front;
  closedptr=CLOSED->front;
  while(openptr!=NULL || closedptr!=NULL)
  {
    if(openptr!=NULL)
    {
      temp=openptr->next;
      delete_node(openptr);
      openptr=temp;
    }

    if(closedptr!=NULL)
    {
      temp=closedptr->next;
      delete_node(closedptr);
      closedptr=temp;
    }
  }
}

struct cube getstate(char *str, struct cube cube)
{
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

  return cube;
}

int main()
{
  char str[500];
  struct cube cube;
  struct queue OPEN;
  struct queue CLOSED;
  struct node * picked_node;

  initialize_q(&OPEN);
  initialize_q(&CLOSED);


  cube = initialize_cube();
  printf("Enter the scramble: ");
  gets(str);
  cube=getstate(str,cube);

  cube.moves[0] = '\0';

  enqueue(&OPEN, cube);
  struct node *ptr1 = OPEN.front;

  check_node(ptr1, &CLOSED);
  picked_node=dequeue(&OPEN);

  while(!goalstate())
  {
    moveGen(&OPEN, &CLOSED, picked_node);
    picked_node = dequeue(&OPEN);
    if(picked_node==NULL)
    {
      printf("End");
      return 0;
    }
    check_node(picked_node, &CLOSED);
  }

  delete_all(&OPEN, &CLOSED);
}
