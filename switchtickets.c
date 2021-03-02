# include <stdio.h>

int main() {
    int choice;
printf("Would you like park tickets for an infant (1), a child (2), or an adult(3).\n ");
scanf("%d", &choice);

switch (choice)
{
	case 1:
		printf("Your total for one infant ticket is $0.00 .\n");
		break;
	case 2:
		printf("Your total for one child ticket is $148.00 .\n");
		break;
	case 3:
		printf("Your total for one adult ticket is $154.00 .\n");
		break;
	default:
		printf("Error. Please make another selection.\n");
	}
return 0;
}
