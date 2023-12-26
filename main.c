#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

/*UI Variables*/
int finish = 0; /*To close the app and end loop*/
int choice; /*For option selection*/
int menu; /*Return to menu*/
int Yes = 89, No = 78, yes = 121, no = 110;
int flag1; /*For input validation*/
int op6 = 0; /*Ensures that values are entered before option 6*/
int count; /*For report loop*/
int back;
char c[10]; /*Prevent infinite loop when entering alphabet*/
int confirm = 0;

/*Values*/
float P, r, B, rate;
float B1, B2;
float n;
double t;
int year1, year2;
int n1, n2;
double t1, t2;
int years, months;

/*Functions Prototypes for Options*/
void option1();
void option2();
void option3();
void option4();
void option5();
void option6();
void option7();
void option8();

/*Main Program*/
int main()
{
	printf("\t\t==============================\n");
	printf("***********     - Welcome To The Banking App -     ***********\n");
	printf("\t\t==============================\n");

	while (finish == 0)
	{
		printf("\n                             MENU\n");
		printf("--------------------------------------------------------------\n");
		printf("1  Find the Balance.\n");
		printf("2  Find the Principal.\n");
		printf("3  Find the Interest Rate.\n");
		printf("4  Find the Number Of Times the interest is compounded a year.\n");
		printf("5  Find the Number Of Years Compounded.\n");
		printf("6  Generate a report for a given year interval.\n");
		printf("7  Compare two accounts.\n");
		printf("8  Speak with an agent and enter a request.\n");
		printf("--------------------------------------------------------------\n");
		printf("\nPlease select an option (1-8): ");
		scanf("%d", &choice);

		if (choice > 0 && choice < 9)
		{
			if (choice == 1)
			{
				option1();
			}
			else if (choice == 2)
			{
				option2();
			}
			else if (choice == 3)
			{
				option3();
			}
			else if (choice == 4)
			{
				option4();
			}
			else if (choice == 5)
			{
				option5();
			}
			else if (choice == 6)
			{
				option6();
			}
			else if (choice == 7)
			{
				option7();
			}
			else if (choice == 8)
			{
				getchar();
				option8();
			}
		}
		else
		{
			printf("Please enter an integer from 1 to 8 only.\n");
			fgets(c, 10, stdin);
			sscanf_s(c, "%d", &choice);
			continue;
		}

	}
}

/*Function List*/
void option1()
{
	printf("\nEnter the Principal: ");
	scanf("%f", &P);
	printf("Enter the Interest Rate in %%: ");
	scanf("%f", &rate);
	r = rate / 100.0;
	printf("Enter the Number Of Times the interest is compounded a year: ");
	scanf("%f", &n);
	printf("Enter the Number Of Years Compounded: ");
	scanf("%lf", &t);
	B = P * pow(1 + (r / n), n * t);
	printf("\nThe Balance is $%.2f.\n", B);
	getchar();
	flag1 = 0;
	while (flag1 == 0)
	{
		printf("\nWould you like to return to Menu?\n");
		printf("Enter [Y] Yes or [N] No: ");
		menu = getchar();
		getchar();
		if (menu == Yes || menu == yes)
		{

			printf("\nReturning to Menu...\n");
			op6 = 1;
			flag1 = 1;
		}
		else if (menu == no || menu == No)
		{
			printf("\n/// Closing app... ///\n");
			flag1 = 1;
			finish = 1;
		}
		else
		{
			printf("\nPlease enter 'Y' or 'N' only.");
		}
	}
}

void option2()
{
	printf("\nEnter the Balance: ");
	scanf("%f", &B);
	printf("Enter the Interest Rate in %%: ");
	scanf("%f", &rate);
	r = rate / 100.0;
	printf("Enter the Number Of Times the interest is compounded a year: ");
	scanf("%f", &n);
	printf("Enter the Number Of Years Compounded: ");
	scanf("%lf", &t);
	P = B / pow(1 + (r / n), n * t);
	printf("\nThe Principal is $%.2f.\n", P);
	getchar();
	flag1 = 0;
	while (flag1 == 0)
	{
		printf("\nWould you like to return to Menu?\n");
		printf("Enter [Y] Yes or [N] No: ");
		menu = getchar();
		getchar();
		if (menu == Yes || menu == yes)
		{

			printf("\nReturning to Menu...\n");
			op6 = 1;
			flag1 = 1;
		}
		else if (menu == no || menu == No)
		{
			printf("\n/// Closing app... ///\n");
			flag1 = 1;
			finish = 1;
		}
		else
		{
			printf("\nPlease enter 'Y' or 'N' only.");
		}
	}
}

void option3()
{
	printf("\nEnter the Principal: ");
	scanf("%f", &P);
	printf("Enter the Number Of Times the interest is compounded a year: ");
	scanf("%f", &n);
	printf("Enter the Number Of Years Compounded: ");
	scanf("%lf", &t);
	printf("Enter the Balance: ");
	scanf("%f", &B);
	r = n * (pow(B / P, 1.0 / (n * t)) - 1.0);
	rate = r * 100.0;
	printf("\nThe Interest Rate is %.2f%%.\n", rate);
	getchar();
	flag1 = 0;
	while (flag1 == 0)
	{
		printf("\nWould you like to return to Menu?\n");
		printf("Enter [Y] Yes or [N] No: ");
		menu = getchar();
		getchar();
		if (menu == Yes || menu == yes)
		{

			printf("\nReturning to Menu...\n");
			op6 = 1;
			flag1 = 1;
		}
		else if (menu == no || menu == No)
		{
			printf("\n/// Closing app... ///\n");
			flag1 = 1;
			finish = 1;
		}
		else
		{
			printf("\nPlease enter 'Y' or 'N' only.");
		}
	}
}

void option4()
{
	printf("\nEnter the Principal: ");
	scanf("%f", &P);
	printf("Enter the Interest Rate in %%: ");
	scanf("%f", &rate);
	r = rate / 100.0;
	printf("Enter the Number Of Years Compounded: ");
	scanf("%lf", &t);
	printf("Enter the Balance: ");
	scanf("%f", &B);
	n = 0;
	B1 = 0;
	B2 = 0;
	while (B2 != B)
	{
		B1 = P * pow(1 + (r / n), n * t);
		B2 = roundf(B1 * 100) / 100;
		n += 0.1;
	}
	n = roundf(n);
	printf("\nThe Number Of Times the interest is compounded a year is %.0f time(s).\n", n);
	printf("This is your compound ratio.\n");
	getchar();
	flag1 = 0;
	while (flag1 == 0)
	{
		printf("\nWould you like to return to Menu?\n");
		printf("Enter [Y] Yes or [N] No: ");
		menu = getchar();
		getchar();
		if (menu == Yes || menu == yes)
		{

			printf("\nReturning to Menu...\n");
			op6 = 1;
			flag1 = 1;
		}
		else if (menu == no || menu == No)
		{
			printf("\n/// Closing app... ///\n");
			flag1 = 1;
			finish = 1;
		}
		else
		{
			printf("\nPlease enter 'Y' or 'N' only.");
		}
	}
}

void option5()
{
	printf("\nEnter the Principal: ");
	scanf("%f", &P);
	printf("Enter the Interest Rate in %%: ");
	scanf("%f", &rate);
	r = rate / 100.0;
	printf("Enter the Number Of Times the interest is compounded a year: ");
	scanf("%f", &n);
	printf("Enter the Balance: ");
	scanf("%f", &B);
	t = ((1.0 / n) * log10(B / P)) / log10(1 + (r / n));
	printf("\nThe Number Of Years compounded is %.0lf Year(s).\n", t);
	getchar();
	flag1 = 0;
	while (flag1 == 0)
	{
		printf("\nWould you like to return to Menu?\n");
		printf("Enter [Y] Yes or [N] No: ");
		menu = getchar();
		getchar();
		if (menu == Yes || menu == yes)
		{

			printf("\nReturning to Menu...\n");
			op6 = 1;
			flag1 = 1;
		}
		else if (menu == no || menu == No)
		{
			printf("\n/// Closing app... ///\n");
			flag1 = 1;
			finish = 1;
		}
		else
		{
			printf("\nPlease enter 'Y' or 'N' only.");
		}
	}
}

void option6()
{
	if (op6 == 1) /*To confirm if op1-5 have been selected beforehand.*/
	{
		printf("\n/// This report will be generated based on the previous input. ///\n");
		while (confirm == 0)
		{
			printf("\nEnter the first year: ");
			scanf("%d", &year1);
			printf("Enter the last year: ");
			scanf("%d", &year2);
			getchar();
			if (year2 > year1)
			{
				double report[50][5]; /*Report Array*/
				int rows = year2 - year1 + 1;
				count = year1;
				printf("\nYear\tPrincipal\tInterest Rate\tCompound Ratio\tBalance\n");
				for (int i = 0; i < rows; i++)
				{
					report[i][4] = P * pow(1 + (r / n), n * count);
					report[i][0] = count;
					report[i][1] = P;
					report[i][2] = r;
					report[i][3] = n;
					printf("%3.0lf\t%.2lf\t\t%.3lf\t\t%3.0lf\t\t%.2lf\n", report[i][0], report[i][1], report[i][2], report[i][3], report[i][4]);
					count += 1;
				}
				confirm = 1;
			}
			else
			{
				printf("\nPlease ensure that the last year is more than the first year!\n");
			}
		}
		flag1 = 0;
		while (flag1 == 0)
		{
			printf("\nWould you like to return to Menu?\n");
			printf("Enter [Y] Yes or [N] No: ");
			menu = getchar();
			getchar();
			if (menu == Yes || menu == yes)
			{

				printf("\nReturning to Menu...\n");
				op6 = 1;
				flag1 = 1;
			}
			else if (menu == no || menu == No)
			{
				printf("\n/// Closing app... ///\n");
				flag1 = 1;
				finish = 1;
			}
			else
			{
				printf("\nPlease enter 'Y' or 'N' only.");
			}
		}
	}
	else
	{
		printf("\nPlease select options 1 - 5 first.\n");
	}
}

void option7()
{
	printf("\nEnter the Principal of the both accounts: ");
	scanf("%f", &P);
	printf("Enter the Interest Rate of both accounts in %%: ");
	scanf("%f", &rate);
	r = rate / 100.0;
	printf("Enter the Number Of Times the interest is compounded a year in the 1st account: ");
	scanf("%d", &n1);
	printf("Enter the Number Of Years Compounded in the 1st account: ");
	scanf("%lf", &t1);
	printf("Enter the Number Of Times the interest is compounded a year in the 2nd account: ");
	scanf("%d", &n2);
	B = P * pow(1 + (r / n1), n1 * t1);
	t2 = ((1.0 / n2) * log10(B / P)) / log10(1 + (r / n2));
	years = floor(t2);
	months = ceil((t2 - years) * 12);
	printf("\nBalance of 1st account is $%.2f.\n", B);
	if (months == 12)
	{
		years += 1;
		printf("It would take %d year(s) for the balance in the second account to be the same as the first account.\n", years);
	}
	else if (months == 0)
	{
		printf("It would take %d year(s) for the balance in the second account to be the same as the first account.\n", years);
	}
	else if (years == 0 && months != 12)
	{
		printf("It would take %d month(s) for the balance in the second account to be the same as the first account.\n", months);
	}
	else
	{
		printf("It would take %d year(s) and %d month(s) for the balance in the second account to be the same as the first account.\n", years, months);
	}
	getchar();
	flag1 = 0;
	while (flag1 == 0)
	{
		printf("\nWould you like to return to Menu?\n");
		printf("Enter [Y] Yes or [N] No: ");
		menu = getchar();
		getchar();
		if (menu == Yes || menu == yes)
		{

			printf("\nReturning to Menu...\n");
			op6 = 0;
			flag1 = 1;
		}
		else if (menu == no || menu == No)
		{
			printf("\n/// Closing app... ///\n");
			flag1 = 1;
			finish = 1;
		}
		else
		{
			printf("\nPlease enter 'Y' or 'N' only.");
		}
	}
}

/*Variables for option 8*/
int settle = 0; /*To end the loop*/
int final = 0; /*To determine which operation to carry out*/
int endOption = 0;
int emptyValues = 5; /*To ensure no missing values*/
char star[10] = { "*" }; /*Value identifier*/
int command = 0;
int count1 = 0;
int exist = 0;
int existReport = 0;
int existCompare = 0;
int reportValues = 0;
char request[500]; /*User input*/
float val; /*Values for B,P,n,r,t*/
int exist1 = 0, exist2 = 0, exist3 = 0, exist4 = 0, exist5 = 0;

/*Dictionary*/
char library[30][100] = { "principal","ratio","interest","balance","duration","period","compounded","report","portfolio","compare",
								"know","enquire","ask","find","how","tell","give" };

/*Prototypes*/
void input_analyzer();
void final_operation();
void error_message();
void compare_accounts();
void value_assign();

void option8()
{
	int endless = 0; /*To loop back to start*/
	/*Welcome Message*/
	printf("\nBONK:\n");
	printf("Hello! I am Bonk, your personal banking assistant. How may I help you today?\n");
	printf("\n[ALERT] Please enclose every number or value with a ' * ' symbol.\n");
	printf("For example: 'I have RM * 5000 * deposited.'\n");

	while (endless == 0)
	{
		/*Variables*/
		settle = 0;
		final = 0;
		endOption = 0;
		emptyValues = 5;
		command = 0;
		count1 = 0;
		exist = 0;
		existReport = 0;
		existCompare = 0;
		reportValues = 0;
		exist1 = 0, exist2 = 0, exist3 = 0, exist4 = 0, exist5 = 0;

		printf("\nEnter a request: ");
		fgets(request, 500, stdin);

		/*Input identifying*/
		input_analyzer();

		printf("\nBONK:");
		/*Operations to be carried out*/
		final_operation();

		/*Error Messages*/
		error_message();

		/*Comparing 2 accounts*/
		compare_accounts();

		/*Decision to end or continue the program*/
		if (settle == 1)
		{
			flag1 = 0;
			while (flag1 == 0)
			{
				printf("\n   Options\n");
				printf(" -----------\n");
				printf("Would you like to...\n");
				printf("\n[1] Return to Menu.\n");
				printf("[2] Close the App.\n");
				printf("[3] Enter a new request.\n");
				printf("\nBONK:");
				printf("\nPlease select an option: ");
				scanf("%d", &menu);
				getchar();
				if (menu == 1)
				{
					printf("\nThanks for joning me today! Have a nice day and stay safe!");
					printf("\nReturning to Menu...\n");
					flag1 = 1;
					endless = 1;
				}
				else if (menu == 2)
				{
					printf("\nThanks for joining me today! Have a nice day and stay safe!");
					printf("\n/// Closing app... ///\n");
					flag1 = 1;
					finish = 1;
					endless = 1;
				}
				else if (menu == 3)
				{
					flag1 = 1;
					printf("\nBONK:\n");
					printf("Hello there! Welcome back!\n");
					printf("How may I help you?\n");
				}
				else
				{
					printf("\nPlease enter a number between 1 - 3 only.\n");
				}
			}
		}
	}
}

void input_analyzer()
{
	char* word;
	word = strtok(request, " ");
	while (word != NULL)
	{
		if (strcmp(word, library[0]) == 0 && final == 0) /*Principal*/
		{
			command = 1;
			exist = 1;
		}
		else if (strcmp(word, library[1]) == 0 && final == 0) /*Compound Ratio*/
		{
			command = 2;
			exist = 1;
		}
		else if (strcmp(word, library[2]) == 0 && final == 0) /*Interest Rate*/
		{
			command = 3;
			exist = 1;
		}
		else if (strcmp(word, library[3]) == 0 && final == 0) /*Balance*/
		{
			command = 4;
			exist = 1;
		}
		else if ((strcmp(word, library[4]) == 0 || strcmp(word, library[5]) == 0 || strcmp(word, library[6]) == 0 || strcmp(word, library[16]) == 0) && final == 0) /*Years*/
		{
			command = 5;
			exist = 1;
		}
		else if (strcmp(word, library[7]) == 0 || strcmp(word, library[8]) == 0) /*Report*/
		{
			command = 6;
			existReport = 1;
		}
		else if (strcmp(word, library[9]) == 0 && final == 0) /*Compare*/
		{
			existCompare = 1;
		}
		else if (strcmp(word, library[10]) == 0 || strcmp(word, library[11]) == 0 || strcmp(word, library[12]) == 0 || strcmp(word, library[13]) == 0 || strcmp(word, library[14]) == 0)
		{
			final = 1;
		}
		else if (strcmp(word, star) == 0)
		{
			word = strtok(NULL, " ");
			val = strtof(word, NULL, 10);
			value_assign();
			word = strtok(NULL, " ");

		}
		else if (strcmp(word, library[0]) == 0 && final == 1)
		{
			endOption = 1;
			final = 0;
		}
		else if (strcmp(word, library[1]) == 0 && final == 1)
		{
			endOption = 2;
			final = 0;
		}
		else if (strcmp(word, library[2]) == 0 && final == 1)
		{
			endOption = 3;
			final = 0;
		}
		else if (strcmp(word, library[3]) == 0 && final == 1)
		{
			endOption = 4;
			final = 0;
		}
		else if ((strcmp(word, library[4]) == 0 || strcmp(word, library[5]) == 0 || strcmp(word, library[6]) == 0) && final == 1)
		{
			endOption = 5;
			final = 0;
		}
		word = strtok(NULL, " ");
	}
}

void final_operation()
{
	if (emptyValues < 2)
	{
		if (endOption == 1)
		{
			P = B / pow(1 + (r / n), n * t);
			printf("\nThe Principal is $%.2f.\n", P);
			emptyValues -= 1;
			settle = 1;
		}
		else if (endOption == 2)
		{
			n = 0;
			B1 = 0;
			B2 = 0;
			while (B2 != B)
			{
				B1 = P * pow(1 + (r / n), n * t);
				B2 = roundf(B1 * 100) / 100;
				n += 0.1;
			}
			n = roundf(n);
			printf("\nThe Number Of Times the interest is compounded a year is %.0f time(s).\n", n);
			printf("This is your compound ratio.\n");
			emptyValues -= 1;
			settle = 1;
		}
		else if (endOption == 3)
		{
			r = n * (pow(B / P, 1.0 / (n * t)) - 1.0);
			rate = r * 100.0;
			printf("\nThe Interest Rate is %.2f%%.\n", rate);
			emptyValues -= 1;
			settle = 1;
		}
		else if (endOption == 4)
		{
			B = P * pow(1 + (r / n), n * t);
			printf("\nThe Balance is $%.2f.\n", B);
			emptyValues -= 1;
			settle = 1;
		}
		else if (endOption == 5)
		{
			t = ((1.0 / n) * log10(B / P)) / log10(1 + (r / n));
			printf("\nThe Number Of Years compounded is %.0lf Year(s).\n", t);
			emptyValues -= 1;
			settle = 1;
		}
	}
	else
	{
		if (exist == 0 && existReport == 0 && existCompare == 0)
		{
			printf("\nI'm sorry! I am not able to do that.\n");
			printf("Please enter another request.\n");
		}
	}

	if (existReport == 1)
	{
		if (existReport == 1 && emptyValues<1 && year2>year1 && reportValues == 0)
		{
			double report[50][5]; /*Report Array*/
			int rows = year2 - year1 + 1;
			count = year1;
			printf("\nReport:");
			printf("\nYear\tPrincipal\tInterest Rate\tCompound Ratio\tBalance\n");
			for (int i = 0; i < rows; i++)
			{
				report[i][4] = P * pow(1 + (r / n), n * count);
				report[i][0] = count;
				report[i][1] = P;
				report[i][2] = r;
				report[i][3] = n;
				printf("%3.0lf\t%.2lf\t\t%.3lf\t\t%3.0lf\t\t%.2lf\n", report[i][0], report[i][1], report[i][2], report[i][3], report[i][4]);
				count += 1;
			}
			settle = 1;
			flag1 = 0;
			while (flag1 == 0)
			{
				printf("\nBONK:");
				printf("\nWould you like to save this report into a file??\n");
				printf("Enter [Y] Yes or [N] No: ");
				menu = getchar();
				getchar();
				if (menu == Yes || menu == yes)
				{
					double values;
					printf("\nBONK:");
					printf("\nThe report is being saved into the file 'report.txt'...\n");
					FILE* reportfile;
					reportfile = fopen("report.txt", "w");
					if (reportfile == NULL)
					{
						printf("\nReport failed to be saved.\n");
					}
					else
					{
						fprintf(reportfile,"Report:");
						fprintf(reportfile,"\r\nYear\tPrincipal\tInterest Rate\tCompound Ratio\tBalance\r\n");
						for (int i = 0; i < rows; i++)
						{
							fprintf(reportfile,"%3.0lf\t%.2lf\t\t%.3lf\t\t%3.0lf\t\t%.2lf\r\n", report[i][0], report[i][1], report[i][2], report[i][3], report[i][4]);
							count += 1;
						}
						fclose(reportfile);
						printf("\nReport saved!\n");
					}
					flag1 = 1;
				}
				else if (menu == no || menu == No)
				{
					printf("\nBONK:");
					printf("\nThe report will not be saved.\n");
					flag1 = 1;
				}
				else
				{
					printf("\nBONK:");
					printf("\nPlease enter 'Y' or 'N' only.");
				}
			}
		}
		else
		{
			printf("\nUnable to a generate report due to insufficient or incorrect information!\n");
			if (exist == 0)
			{
				printf("Please try again with another request.\n");
			}
		}
	}
}

void error_message()
{
	if (emptyValues >= 2 && exist == 1 && existCompare == 0)
	{
		printf("\nInsufficient information!\n");
		printf("You are missing the");
		if (exist1 == 0)
		{
			printf(" Principal,");
		}
		if (exist2 == 0)
		{
			printf(" Compound Ratio,");
		}
		if (exist3 == 0)
		{
			printf(" Interest Rate,");
		}
		if (exist4 == 0)
		{
			printf(" Balance,");
		}
		if (exist5 == 0)
		{
			printf(" Years Compounded,");
		}
		printf(" values.\n");
		printf("Please try again with another request.\n");
	}
	if (emptyValues >= 2 && exist == 1 && existCompare == 1)
	{
		printf("\nInsufficient information!\n");
		printf("You are missing the");
		if (exist1 == 0)
		{
			printf(" Principal,");
		}
		if (exist2 == 0)
		{
			printf(" Compound Ratio,");
		}
		if (exist3 == 0)
		{
			printf(" Interest Rate,");
		}
		if (exist4 == 0)
		{
			printf(" Balance,");
		}
		if (exist5 == 0)
		{
			printf(" Years Compounded,");
		}
		printf(" values.\n");
		printf("I can only carry out the request of comparing accounts.\n");
	}
}

void compare_accounts()
{
	if (existCompare == 1)
	{
		printf("\nComparing Accounts\n");
		printf("------------------\n");
		printf("Enter the Principal of the both accounts: ");
		scanf("%f", &P);
		printf("Enter the Interest Rate of both accounts in %%: ");
		scanf("%f", &rate);
		r = rate / 100.0;
		printf("Enter the Number Of Times the interest is compounded a year in the 1st account: ");
		scanf("%d", &n1);
		printf("Enter the Number Of Years Compounded in the 1st account: ");
		scanf("%lf", &t1);
		printf("Enter the Number Of Times the interest is compounded a year in the 2nd account: ");
		scanf("%d", &n2);
		B = P * pow(1 + (r / n1), n1 * t1);
		t2 = ((1.0 / n2) * log10(B / P)) / log10(1 + (r / n2));
		years = floor(t2);
		months = ceil((t2 - years) * 12);
		printf("\nBalance of 1st account is $%.2f.\n", B);
		if (months == 12)
		{
			years += 1;
			printf("It would take %d year(s) for the balance in the second account to be the same as the first account.\n", years);
		}
		else if (months == 0)
		{
			printf("It would take %d year(s) for the balance in the second account to be the same as the first account.\n", years);
		}
		else if (years == 0 && months != 12)
		{
			printf("It would take %d month(s) for the balance in the second account to be the same as the first account.\n", months);
		}
		else
		{
			printf("It would take %d year(s) and %d month(s) for the balance in the second account to be the same as the first account.\n", years, months);
		}
		getchar();
		settle = 1;
	}
}

void value_assign()
{
	if (command == 1)
	{
		P = val;
		emptyValues -= 1;
		exist1 = 1;
	}
	else if (command == 2)
	{
		n = val;
		emptyValues -= 1;
		exist2 = 1;
	}
	else if (command == 3)
	{
		rate = val;
		r = rate / 100.0;
		emptyValues -= 1;
		exist3 = 1;
	}
	else if (command == 4)
	{
		B = val;
		emptyValues -= 1;
		exist4 = 1;
	}
	else if (command == 5)
	{
		t = val;
		emptyValues -= 1;
		exist5 = 1;
	}
	else if (command == 6)
	{
		if (count1 == 0)
		{
			year1 = val;
			count1 += 1;
			reportValues = 1;
		}
		else if (count1 == 1)
		{
			year2 = val;
			reportValues = 0;
			emptyValues -= 1;
		}
	}
}
