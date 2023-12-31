#include <cs50.h>
#include <stdio.h>

bool is_luhns(long number);
int get_card_length(long number);
int get_first_digit(long number);
int get_second_digit(long number);

int main(void)
{
    // Get Card number
    long card_number = get_long("Number: ");

    if (is_luhns(card_number))
    {
        int card_length = get_card_length(card_number);
        int first_digit = get_first_digit(card_number);
        if (first_digit == 3)
        {
            int second_digit = get_second_digit(card_number);
            if ((card_length == 15) && ((second_digit == 4) || (second_digit == 7)))
            {
                printf("AMEX\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else if (((card_length == 13) || (card_length == 16)) && first_digit == 4)
        {
            printf("VISA\n");
        }
        else if (first_digit == 5)
        {
            int second_digit = get_second_digit(card_number);
            if ((card_length == 16) && (second_digit >= 1) && (second_digit <= 5))
            {
                printf("MASTERCARD\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}

bool is_luhns(long number)
{
    int total = 0;
    int current_idx = 0;

    while (number != 0)
    {
        int current_digit = number % 10;
        if ((current_idx % 2) == 0)
        {
            total += current_digit;
        }
        else
        {
            int multiplied_by_two = current_digit * 2;
            if (multiplied_by_two >= 10)
            {
                total += 1 + (multiplied_by_two % 10);
            }
            else
            {
                total += multiplied_by_two;
            }
        }
        number /= 10;
        current_idx++;
    }

    return ((total % 10) == 0);
}

int get_card_length(long number)
{
    int length = 0;
    while (number != 0)
    {
        number /= 10;
        length++;
    }
    return length;
}

int get_first_digit(long number)
{
    while (number >= 10)
    {
        number /= 10;
    }
    return number;
}

int get_second_digit(long number)
{
    while (number >= 100)
    {
        number /= 10;
    }
    return (number % 10);
}
