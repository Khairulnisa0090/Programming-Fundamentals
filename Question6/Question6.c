#include <stdio.h>

int main()
{
    char type, member, disabled, available;
    int battery, required;
    float hours, chargingUnits;
    int hour;

    float chargingCost = 0;
    float parkingCost = 0;
    float discount = 0;
    float finalBill = 0;

    printf("Enter vehicle type (E=Electric, H=Hybrid): ");
    scanf(" %c", &type);

    printf("Enter current battery percentage: ");
    scanf("%d", &battery);

    printf("Enter required charging percentage: ");
    scanf("%d", &required);

    printf("Enter parking duration in hours: ");
    scanf("%f", &hours);

    printf("Enter current hour (0-23): ");
    scanf("%d", &hour);

    printf("Parking membership? (Y/N): ");
    scanf(" %c", &member);

    printf("Disabled-person priority? (Y/N): ");
    scanf(" %c", &disabled);

    printf("Charging station available? (Y/N): ");
    scanf(" %c", &available);

    // Input Validation
    if (battery < 0 || battery > 100 ||
        required < 0 || required > 100 ||
        hours <= 0 || hour < 0 || hour > 23)
    {
        printf("Error: Invalid input!\n");
        return 1;
    }

    if ((type != 'E' && type != 'e' &&
         type != 'H' && type != 'h') ||
        (member != 'Y' && member != 'y' &&
         member != 'N' && member != 'n') ||
        (disabled != 'Y' && disabled != 'y' &&
         disabled != 'N' && disabled != 'n') ||
        (available != 'Y' && available != 'y' &&
         available != 'N' && available != 'n'))
    {
        printf("Error: Invalid input value!\n");
        return 1;
    }

    // Station Availability
    if (available == 'N' || available == 'n')
    {
        if (type == 'H' || type == 'h')
        {
            printf("Charging unavailable - Parking only.\n");
        }
        else
        {
            printf("No charging slot available.\n");
        }

        return 0;
    }

    // Vehicle Eligibility
    if (type == 'H' || type == 'h')
    {
        if (battery >= 40)
        {
            printf("Vehicle does not qualify for EV charging.\n");
            return 0;
        }
    }

    // Charging Requirement
    if (required <= battery)
    {
        printf("No charging required.\n");
        return 0;
    }

    chargingUnits = required - battery;

    // Charging Priority
    if (battery <= 15 && required >= 80)
    {
        printf("Priority: Emergency Charging Priority\n");
    }
    else if (disabled == 'Y' || disabled == 'y' ||
             ((member == 'Y' || member == 'y') && battery <= 30))
    {
        printf("Priority: Priority Charging\n");
    }
    else
    {
        printf("Priority: Normal Charging\n");
    }

    // Charging Cost
    if (hour < 17 || hour >= 22)
    {
        printf("Time: Off-Peak\n");
        chargingCost = chargingUnits * 35;

        if ((member == 'Y' || member == 'y') &&
            !(battery <= 15 && required >= 80))
        {
            discount = chargingCost * 0.20;
            chargingCost -= discount;
        }
    }
    else
    {
        printf("Time: Peak\n");
        chargingCost = chargingUnits * 50;

        discount = chargingCost * 0.10;
        chargingCost -= discount;
    }

    // Parking Cost
    if (hours <= 2)
    {
        parkingCost = 200;
    }
    else if (hours <= 5)
    {
        parkingCost = 400;
    }
    else
    {
        parkingCost = 700;
    }

    // Parking Discount
    if (disabled == 'Y' || disabled == 'y')
    {
        parkingCost = 0;
    }
    else if (member == 'Y' || member == 'y')
    {
        parkingCost = parkingCost * 0.80;
    }

    finalBill = chargingCost + parkingCost;

    // Long Stay Warning
    if (hours > 8)
    {
        printf("Long-stay warning: Please relocate your vehicle after charging.\n");
    }
    else
    {
        printf("Standard parking duration.\n");
    }

    // Final Bill
    printf("\n========== EV CHARGING BILL ==========\n");
    printf("Vehicle Type: %c\n", type);
    printf("Current Battery: %d%%\n", battery);
    printf("Required Charging: %d%%\n", required);
    printf("Charging Units: %.2f\n", chargingUnits);
    printf("Charging Cost: Rs. %.2f\n", chargingCost);
    printf("Parking Cost: Rs. %.2f\n", parkingCost);
    printf("Discount: Rs. %.2f\n", discount);
    printf("Final Payable Amount: Rs. %.2f\n", finalBill);
    printf("======================================\n");

    return 0;
}