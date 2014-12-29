#include <stdio.h>
#define taken 1
#define empty 0

/**
 * Set all seats to empty
 **/
void initialize(int seats[4][5])
{
	int i, j;
	for (j = 0; j < 5; j++)
		for (i = 0; i < 4; i++)
			seats[i][j] = empty;
}

/**
 * Display seats
 **/
void display(int seats[4][5])
{
	int i, j;
	for (j = 0; j < 5; j++)
	{
		for (i = 0; i < 4; i++)
		{
			if(seats[i][j] == taken)
				printf("XX");
			else
				printf("%d%c", j+1, i+65);
			printf("\t");
		}
		printf("\n\n");
	}
}

/**
 * Requests input from user for seat reservation
 **/
void choose_seat_from(int seats[4][5])
{
	char seat[3];

	printf("\v");
	do
	{
		printf("\033[A");
		printf("Enter seat number you want: __  __\b\b\b\b");
		scanf(" %s", seat);
	}
	while(seat[0] < '1' || seat[0] > '5' || seat[1] < 'A' || seat[1] > 'D');

	int i = seat[1]-65; // ASCII value of 'A' is 65
	int j = seat[0]-49; // ASCII value of '1' is 49

	if(seats[i][j] == taken)
		printf("\"Sorry the seat number %s is already occupied!\"\n", seat);
	else
		seats[i][j] = taken;
}

int main(int argc, char const *argv[])
{
	int i;
	int seats[4][5];
	char main_choice;

	initialize(seats);

	do
	{
		printf("\v\v");
		printf("[1] Display the Seat Arrangement\t[3] Exit the Program\n");
		printf("[2] Input the Passenger's Choice\n");

		for(i = 0; i < 3; i++) // Move up three times
			printf("\033[A");

		printf("Enter your choice from the options below:\t__ __\b\b\b");

		scanf(" %c", &main_choice);
		printf("\v\v\v"); // Move down three times

		switch(main_choice)
		{
			case '1':

				display(seats);
				char reserve;

				printf("\v");

				do
				{
					printf("\033[A");

					printf("Proceed with the reservation/assigning [Y/N]?\t__ __\b\b\b");
					scanf(" %c", &reserve);
				} while(reserve != 'Y' && reserve != 'N');

				if(reserve == 'N')
					break;

				printf("\n");
			case '2':

				choose_seat_from(seats);

			case '3': break;
			default: printf("Invalid command.\n");
		}

	} while(main_choice != '3');

	return 0;
}
