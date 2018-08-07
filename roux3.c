#include<stdio.h>
#include<conio.h>
#include<string.h>


struct cube
{
  char cube[6][9];
  char wg[10];
  char wb[10];
  char wr[10];
  char wo[10];
  char yg[10];
  char yb[10];
  char yr[10];
  char yo[10];
};

typedef struct
{
  struct cube cube_arr[612220032];
  int top;
}stack;

struct cube pop(stack *s)
{
  s->top=s->top-1;
  return s->cube_arr[s->top+1];
}

void push(stack *s, struct cube cube)
{
  s->top++;
  s->cube_arr[s->top]=cube;
}

//Moves
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



struct cube move(struct cube cube, char move[2])
{


  if(move=="R")
  {
    cube=R_move(cube);
    return cube;
  }

  if(move=="R2")
  {
    cube=R_move(cube);
    cube=R_move(cube);
    return cube;
  }

  if(move=="R\'")
  {
    cube=R_move(cube);
    cube=R_move(cube);
    cube=R_move(cube);
    return cube;
  }

  if(move=="F")
  {
    cube=F_move(cube);
    return cube;
  }

  if(move=="F\'")
  {
    cube=F_move(cube);
    cube=F_move(cube);
    cube=F_move(cube);
    return cube;
  }

  if(move=="F2")
  {
    cube=F_move(cube);
    cube=F_move(cube);
    return cube;
  }

  if(move=="U")
  {
    cube=U_move(cube);
    return cube;
  }

  if(move=="U\'")
  {
    cube=U_move(cube);
    cube=U_move(cube);
    cube=U_move(cube);
    return cube;
  }

  if(move=="U2")
  {
    cube=U_move(cube);
    cube=U_move(cube);
    return cube;
  }

  if(move=="L")
  {
    cube=L_move(cube);
    return cube;
  }

  if(move=="L\'")
  {
    cube=L_move(cube);
    cube=L_move(cube);
    cube=L_move(cube);
    return cube;
  }

  if(move=="L2")
  {
    cube=L_move(cube);
    cube=L_move(cube);
    return cube;
  }

  if(move=="D")
  {
    cube=D_move(cube);
    return cube;
  }

  if(move=="D\'")
  {
    cube=D_move(cube);
    cube=D_move(cube);
    cube=D_move(cube);
    return cube;
  }

  if(move=="D2")
  {
    cube=D_move(cube);
    cube=D_move(cube);
    return cube;
  }

  if(move=="B")
  {
    cube=B_move(cube);
    return cube;
  }

  if(move=="B\'")
  {
    cube=B_move(cube);
    cube=B_move(cube);
    cube=B_move(cube);
    return cube;
  }

  if(move=="B2")
  {
    cube=B_move(cube);
    cube=B_move(cube);
    return cube;
  }

}

int main()
{
  char str[500];
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

  stack open;
  open.top=-1;
  struct cube closed[612220032];



  while(GoalNotFount(cube))
  {
    
  }
}
