#include <stdio.h>
#include <stdlib.h>

int main()
{  int choice;
   float a, b;

   printf("MENU\n");
   printf("1, ADD\n2. SUBTRACT\n3. MULTIPLYING\n4. Divide\n");
   printf("Enter your choice (1-4): ");
   scanf("%d",&choice);

   printf("Enter two numbers: ");
   scanf("%f %f", &a, &b);

   switch (choice) {
   case 1:
     printf(" Result = %.2f", a + b);
     break;
   case 2:
     printf(" Result = %.2f", a - b);
     break;
   case 3:
     printf(" Result = %.2f", a * b);
     break;
   case 4:
     if (b != 0)
     printf("result = %.2f", a / b);
   else
     printf("Error: Division by zero!");
    break;
   default:
     printf("Invalid choice.");
   }
    return 0;
}
