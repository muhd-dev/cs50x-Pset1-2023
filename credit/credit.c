 #include <stdio.h>
#include <cs50.h>

int main(void)
{
    int count = 0;
    long card; // Declaring a variable long for the card
    do
    {
        card = get_long("Enter Your Card no: "); // Getting card number
    }
    while (card < 0); // Card must not be less than 0

    long check = card;

    int card1, card2, card3, card4, card5, card6, card7, card8;

    card1 = (((card % 100) / 10) * 2);
    card2 = (((card % 10000) / 1000) * 2);
    card3 = (((card % 1000000) / 100000) * 2);
    card4 = (((card % 100000000) / 10000000) * 2);
    card5 = (((card % 10000000000) / 1000000000) * 2);
    card6 = (((card % 1000000000000) / 100000000000) * 2);
    card7 = (((card % 100000000000000) / 10000000000000) * 2);
    card8 = (((card % 10000000000000000) / 1000000000000000) * 2);

    card1 = (card1 % 100 / 10) + (card1 % 10);
    card2 = (card2 % 100 / 10) + (card2 % 10);
    card3 = (card3 % 100 / 10) + (card3 % 10);
    card4 = (card4 % 100 / 10) + (card4 % 10);
    card5 = (card5 % 100 / 10) + (card5 % 10);
    card6 = (card6 % 100 / 10) + (card6 % 10);
    card7 = (card7 % 100 / 10) + (card7 % 10);
    card8 = (card8 % 100 / 10) + (card8 % 10);

    int card_no = card1 + card2 + card3 + card4 + card5 + card6 + card7 + card8;

    int non_mult = (card % 10) + ((card % 1000) / 100) + ((card % 100000) / 10000) +
                   ((card % 10000000) / 1000000) + ((card % 1000000000) / 100000000) +
                   ((card % 100000000000) / 10000000000) + ((card % 10000000000000) / 1000000000000) +
                   ((card % 1000000000000000) / 100000000000000); // Adding non-multiplied numbers

    int check_sum = card_no + non_mult; // CHECK SUM CALCULATION for validating input

    if ((check_sum % 10) != 0) // If check sum doesn't give a remainder of "0", print invalid and terminate
    {
        printf("INVALID\n");
        return 0;
    }

    while (check > 0) // Check is same as card (check code line 13)
    {
        check = check / 10; // Count the number of digits in card
        count++; // Count until the end
    }

    if (count != 15 && count != 13 && count != 16) // To confirm card length must be 15, 13, or 16
    {
        printf("INVALID\n");
        return 1;
    }

    long MC = card / 100000000000000; // To get the first two numbers of the card to validate MASTERCARD
    long AMEX = card / 10000000000000; // To get the first two numbers of the card to validate AMERICAN EXPRESS
    long Visa = card / 1000000000000000; // To get the first number of the card to validate VISA_CARD

    if (count == 15)
    {
        if (AMEX != 34 && AMEX != 37) // To check if American Express's first two digits are 34 or 37
        {
            printf("INVALID\n");
            return 1;
        }
        else
        {
            printf("AMEX\n");
            return 0;
        }
    }

    if (count == 16)
    {
        if (MC == 51 || MC == 52 || MC == 53 || MC == 54 || MC == 55) // To check if MasterCard's first two digits are 51, 52, 53, 54, or 55.
        {
            printf("MASTERCARD\n");
            return 0;
        }
        else if (Visa == 4) // First validation for Visa card (16) - To check if Visa's first digit is 4
        {
            printf("VISA\n");
            return 0;
        }
        else if (MC != 51 && MC != 52 && MC != 53 && MC != 54 && MC != 55 && Visa == 4)
        {
            printf("INVALID\n");
            return 1;
        }
    }

    if (count == 13 && Visa == 4) // Second validation for Visa card (13) - To check for validation
    {
        printf("VISA\n");
        return 0;
    }
    else if (count != 13 && Visa != 4)
    {
        printf("INVALID\n");
        return 1;
    }
}
