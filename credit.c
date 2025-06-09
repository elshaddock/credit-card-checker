#include <cs50.h>
#include <math.h>
#include <stdio.h>

// Function declaration
long get_digit(long num_split);
long get_card_num_split(long card_num, long base, long exponent);
long check_doubled_digits(long digit);
long luhn_algorithm(long card_num);
long digit_num_checker(long card_num);
long first_two_digits(long card_num, long num_digits);
void check_validity(long num);

// Main method
int main(void)
{
    // Prompt the user for the card number
    long card_num = get_long("Number: ");

    // Check if card is real
    check_validity(card_num);
}

// Get the digit from the card number split
long get_digit(long card_num_split)
{
    long digit = card_num_split % 10;
    return digit;
}

// Split the card number
long get_card_num_split(long card_num, long base, long exponent)
{
    long denominator = (long) round(pow(base, exponent));
    long num_split = card_num / denominator;
    return num_split;
}

// Check if the doubled number is a double digit
long check_doubled_digits(long digit)
{
    long tens = 0;
    long ones = 0;
    long sum = 0;

    // Split the double digit and add them together, otherwise just return the digit
    if (digit > 9)
    {
        ones = digit / pow(10, 1);
        tens = digit %= 10;
        sum = ones + tens;
        return sum;
    }
    else
    {
        return digit;
    }
}

// Calculations for determining validity of credit card
long luhn_algorithm(long card_num)
{
    long get_digit_2 = get_card_num_split(card_num, 10, 13);
    long get_digit_3 = get_card_num_split(card_num, 10, 11);
    long get_digit_4 = get_card_num_split(card_num, 10, 9);
    long get_digit_5 = get_card_num_split(card_num, 10, 7);
    long get_digit_6 = get_card_num_split(card_num, 10, 5);
    long get_digit_7 = get_card_num_split(card_num, 10, 3);
    long get_digit_8 = get_card_num_split(card_num, 10, 1);

    long get_digit_9 = get_card_num_split(card_num, 10, 14);
    long get_digit_10 = get_card_num_split(card_num, 10, 12);
    long get_digit_11 = get_card_num_split(card_num, 10, 10);
    long get_digit_12 = get_card_num_split(card_num, 10, 8);
    long get_digit_13 = get_card_num_split(card_num, 10, 6);
    long get_digit_14 = get_card_num_split(card_num, 10, 4);
    long get_digit_15 = get_card_num_split(card_num, 10, 2);
    long get_digit_16 = get_card_num_split(card_num, 10, 0);

    long digit1 = get_card_num_split(card_num, 10, 15);
    long digit2 = get_digit(get_digit_2);
    long digit3 = get_digit(get_digit_3);
    long digit4 = get_digit(get_digit_4);
    long digit5 = get_digit(get_digit_5);
    long digit6 = get_digit(get_digit_6);
    long digit7 = get_digit(get_digit_7);
    long digit8 = get_digit(get_digit_8);
    long digit9 = get_digit(get_digit_16);
    long digit10 = get_digit(get_digit_15);
    long digit11 = get_digit(get_digit_14);
    long digit12 = get_digit(get_digit_13);
    long digit13 = get_digit(get_digit_12);
    long digit14 = get_digit(get_digit_11);
    long digit15 = get_digit(get_digit_10);
    long digit16 = get_digit(get_digit_9);

    // Reverse order and double the digits
    long dbl_digit1 = digit8 * 2;
    long dbl_digit2 = digit7 * 2;
    long dbl_digit3 = digit6 * 2;
    long dbl_digit4 = digit5 * 2;
    long dbl_digit5 = digit4 * 2;
    long dbl_digit6 = digit3 * 2;
    long dbl_digit7 = digit2 * 2;
    long dbl_digit8 = digit1 * 2;

    long product1 = check_doubled_digits(dbl_digit1);
    long product2 = check_doubled_digits(dbl_digit2);
    long product3 = check_doubled_digits(dbl_digit3);
    long product4 = check_doubled_digits(dbl_digit4);
    long product5 = check_doubled_digits(dbl_digit5);
    long product6 = check_doubled_digits(dbl_digit6);
    long product7 = check_doubled_digits(dbl_digit7);
    long product8 = check_doubled_digits(dbl_digit8);

    long sum_product =
        product1 + product2 + product3 + product4 + product5 + product6 + product7 + product8;
    long sum_other_digits =
        digit9 + digit10 + digit11 + digit12 + digit13 + digit14 + digit15 + digit16;
    long total_of_sums = sum_product + sum_other_digits;

    return total_of_sums;
}

// Get the necessary digits prepared to be checked
long id_check(long card_num, long num_digits)
{
    long id_num = 0;
    long first_digit = get_card_num_split(card_num, 10, num_digits - 1);
    if (num_digits == 13)
    {
        id_num = first_digit;
    }
    else if (num_digits == 15)
    {
        id_num = get_card_num_split(card_num, 10, (num_digits - 2));
    }
    else if (num_digits == 16 && first_digit == 4)
    {
        id_num = first_digit;
    }
    else
    {
        id_num = get_card_num_split(card_num, 10, (num_digits - 2));
    }
    return id_num;
}

// Takes the card number and runs it through a series of tests
void check_validity(long card_num)
{
    long num = luhn_algorithm(card_num);
    long result = get_digit(num);
    long number_of_digits = digit_num_checker(card_num);
    long visa_13 = id_check(card_num, number_of_digits);
    long visa_16 = id_check(card_num, number_of_digits);
    long amex = id_check(card_num, number_of_digits);
    long mastercard = id_check(card_num, number_of_digits);

    // Is the result value for the luhn algorithm valid?
    if (result % 10 == 0)
    {
        // Are the number of digits correct? And if so do the first two digits match the correct #?
        if (number_of_digits == 13)
        {
            if (visa_13 == 4)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else if (number_of_digits == 15)
        {
            if (amex == 34 || amex == 37)
            {
                printf("AMEX\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else if (number_of_digits == 16)
        {
            if (visa_16 == 4)
            {
                printf("VISA\n");
            }
            else if (mastercard == 51 || mastercard == 52 || mastercard == 53 || mastercard == 54 ||
                     mastercard == 55)
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

// Counter for amount of digits
long digit_num_checker(long card_num)
{
    long counter = 0;
    for (long i = card_num; i > 0;)
    {
        i /= 10;
        counter++;
    }
    return counter;
}