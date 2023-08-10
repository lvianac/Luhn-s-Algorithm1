#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

string validate_input();
int get_lenght(string credit_card);
void digit_multi(string credit_card, int count, string result);
int card_validation(string digitos);
int rest_of_numb(string credit_card, int count);
int sum_numbers(int sum, int sum1);
void card_type(int card_val, string credit_card, int length);

int main(void)
{
    string credit_card = validate_input();
    int length = get_lenght(credit_card);
    char digitos[30] = "";
    digit_multi(credit_card, length, digitos);
    int sum = card_validation(digitos);
    int sum_1 = rest_of_numb(credit_card, length);
    int card_val = sum_numbers(sum, sum_1);
    card_type(card_val, credit_card, length);
}

string validate_input()
{
    string credit_card;
    // do
    //{
    credit_card = get_string("Introduce credit card: ");
    //}
    // while (get_lenght(credit_card)<13);
    return credit_card;
}

int get_lenght(string credit_card)
{
    int count;
    for (count = 0; credit_card[count] != '\0'; count++)
    {
    }
    return count;
}

void digit_multi(string credit_card, int count, string digitos)
{
    int times2;
    char times2_str[3];

    for (int i = count - 2; i >= 0; i -= 2)
    {
        times2 = (credit_card[i] - '0') * 2;
        snprintf(times2_str, sizeof(times2_str), "%d", times2);
        strcat(digitos, times2_str);
    }
}

int card_validation(string digitos)
{
    int lenght = get_lenght(digitos);
    int sum = 0;

    for (int i = 0; i < lenght; i++)
    {
        sum = sum + (digitos[i] - '0');
    }
    return sum;
}

int rest_of_numb(string credit_card, int count)
{
    int sum1 = 0;
    for (int i = count - 1; i >= 0; i -= 2)
    {
        sum1 = sum1 + (credit_card[i] - '0');
    }
    return sum1;
}

int sum_numbers(int sum, int sum1)
{
    // printf("%d\n%d\n",sum,sum1);
    int card_val = sum + sum1;
    return card_val;
}

void card_type(int card_val, string credit_card, int length)
{
    // printf("%d\n",card_val);
    printf("Number: %s\n", credit_card);

    if (card_val % 10 == 0 && length >= 13)
    {
        if (credit_card[0] == '4')
        {
            printf("VISA\n");
        }

        else if (credit_card[0] == '5' && (credit_card[1] == '1' || credit_card[1] == '2' || credit_card[1] == '3' ||
                                           credit_card[1] == '4' || credit_card[1] == '5'))
        {
            printf("MASTERCARD\n");
        }

        else if (credit_card[0] == '3' && (credit_card[1] == '4' || credit_card[1] == '7'))
        {
            printf("AMEX\n");
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
