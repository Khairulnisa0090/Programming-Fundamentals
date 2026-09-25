#include <stdio.h>

int main()
{
    int N, i, nights;
    int rate;
    float totalPrice, discount;
    float hotelRevenue = 0;

    char season, roomType;

    printf("Enter number of guests: ");
    scanf("%d", &N);

    if (N <= 0)
    {
        printf("Invalid number of guests!\n");
        return 1;
    }

    for (i = 1; i <= N; i++)
    {
        printf("\n--- Guest %d ---\n", i);

        // Input Season
        while (1)
        {
            printf("Enter season (P=Peak, O=Off-Peak): ");
            scanf(" %c", &season);

            if (season == 'P' || season == 'p' ||
                season == 'O' || season == 'o')
            {
                break;
            }

            printf("Invalid season! Try again.\n");
        }

        // Input Room Type
        while (1)
        {
            printf("Enter room type (S=Standard, D=Deluxe, U=Suite): ");
            scanf(" %c", &roomType);

            if (roomType == 'S' || roomType == 's' ||
                roomType == 'D' || roomType == 'd' ||
                roomType == 'U' || roomType == 'u')
            {
                break;
            }

            printf("Invalid room type! Try again.\n");
        }

        // Input Nights
        printf("Enter number of nights: ");
        scanf("%d", &nights);

        if (nights <= 0)
        {
            printf("Invalid number of nights!\n");
            return 1;
        }

        // Nested Pricing Logic
        if (season == 'P' || season == 'p')
        {
            if (roomType == 'S' || roomType == 's')
            {
                rate = 5000;
            }
            else if (roomType == 'D' || roomType == 'd')
            {
                rate = 8000;
            }
            else
            {
                rate = 12000;
            }
        }
        else
        {
            if (roomType == 'S' || roomType == 's')
            {
                rate = 3000;
            }
            else if (roomType == 'D' || roomType == 'd')
            {
                rate = 5000;
            }
            else
            {
                rate = 8000;
            }
        }

        // Calculate Total Price
        totalPrice = rate * nights;
        discount = 0;

        // Long Stay Discount
        if (nights > 7)
        {
            discount = totalPrice * 0.15;
            totalPrice = totalPrice - discount;
        }

        // Display Guest Bill
        printf("\nGuest %d Bill\n", i);
        printf("Rate per night: Rs. %d\n", rate);
        printf("Nights: %d\n", nights);
        printf("Discount: Rs. %.2f\n", discount);
        printf("Final Price: Rs. %.2f\n", totalPrice);

        // Update Hotel Revenue
        hotelRevenue = hotelRevenue + totalPrice;
    }

    // Final Hotel Revenue
    printf("\n==============================\n");
    printf("Total Hotel Revenue: Rs. %.2f\n", hotelRevenue);
    printf("==============================\n");

    return 0;
}