
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include "/usr/include/mysql/mysql.h"
#include <string.h>
#include "createUser.h"


int main(void)
{
  
  int choice = 0;
  char your_id[20] = "\0";
  char your_pw[20] = "\0";
  printf("환영합니다 \n");
  printf("Workout Program for Novice\n");
 
  printf("1. 로그인   2. 가입하기  \n");
  scanf("%d",&choice);
     fgets(your_id,sizeof(your_id),stdin);//왜 넣어야 되는지 모르겠음
   if(choice == 1)
  {
     //로그인 하는 경우...
     printf("Enter your ID : ");
     fgets(your_id,sizeof(your_id),stdin);
     printf("Enter your PW : ");
     fgets(your_pw,sizeof(your_pw),stdin);

     puts(your_id);
     puts(your_pw);
   }
  else
  {
     createNewUser(); 
  }

  return 0;
}
