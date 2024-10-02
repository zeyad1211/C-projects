   #include <stdio.h>
#include <ctype.h>
#include <math.h>

int power(int num, int power);
void arrOfNum(char UI[], int arraynum[], int operationindex[]);


int main()
{
   char numbers[101][100];
   char operators[100];
   int count=0, y, z, j;
   char UserInput[20];
   printf("Enter an operation: ");
   scanf("%s", UserInput);
   int counter1 = 0;
   int counter2 = 0;
   int i=0;
                           //separation//
   for(i=0;UserInput[i]!='\0';i++)
   {
      if(UserInput[i]>=48)
      {
         numbers[counter2][counter1] = UserInput[i];
        // printf("arraynum: %d\n",numbers[counter1]);
         counter1++;
      }
      else if(UserInput[i]>=42 && UserInput[i]<=47)
      {
         operators[counter2] = UserInput[i];
        // printf("operation index: %d\n",operators[counter2]);
         counter2++;
         counter1=0;
      }
     // printf("operator: %c\n", operators[counter2]);
   }
                           //convertion//
   int temp=0;
   int intnum[counter2+1];
   for(j=0; j < counter2+1; j++){
      for(z=0; numbers[j][z]!='\0'; z++){
         temp = temp*10 + (numbers[j][z]-48);
       //  printf("%d\n", temp);
      }
      intnum[j] = temp;
      // printf("%d\n", intnum[j]);
      temp=0;
   }
                           //calculation//
      int total = intnum[0];
   for(int k=0; k<counter2; k++){
      switch(operators[k]){
         case '+':
            total += intnum[k+1];
            break;
         case '-':
            total -= intnum[k+1];
            break;
      }
   }printf("%d", total);
  
   
}
