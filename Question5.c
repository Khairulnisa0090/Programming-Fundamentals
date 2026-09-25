#include <stdio.h>

int main()
{
    int N, i;

    char type, category, permit, emergency;

    int zoneA = 0, zoneB = 0, zoneC = 0;
    int accepted = 0, rejected = 0;
    int cars = 0, bikes = 0, vans = 0;

    int space, assigned;
    int totalSpaces;

    int capA = 20, capB = 40, capC = 15;

    printf("Enter number of vehicles: ");
    if (scanf("%d", &N) != 1 || N <= 0)
    {
        printf("Invalid number of vehicles!\n");
        return 1;
    }

    for (i = 1; i <= N; i++)
    {
        assigned = 0;
        space = 1;

        printf("\n--- Vehicle %d ---\n", i);

        // Vehicle Type Validation
        while (1)
        {
            printf("Enter vehicle type (C=Car, B=Bike, V=Van): ");
            scanf(" %c", &type);

            if (type == 'C' || type == 'c' ||
                type == 'B' || type == 'b' ||
                type == 'V' || type == 'v')
            {
                break;
            }

            printf("Invalid vehicle type! Try again.\n");
        }

        // Category Validation
        while (1)
        {
            printf("Enter category (F=Faculty, S=Student, G=Visitor): ");
            scanf(" %c", &category);

            if (category == 'F' || category == 'f' ||
                category == 'S' || category == 's' ||
                category == 'G' || category == 'g')
            {
                break;
            }

            printf("Invalid category! Try again.\n");
        }

        // Permit Validation
        while (1)
        {
            printf("Valid permit? (Y/N): ");
            scanf(" %c", &permit);

            if (permit == 'Y' || permit == 'y' ||
                permit == 'N' || permit == 'n')
            {
                break;
            }

            printf("Invalid permit value! Try again.\n");
        }

        // Emergency Check
        emergency = 'N';

        if (permit == 'N' || permit == 'n')
        {
            while (1)
            {
                printf("Emergency vehicle? (Y/N): ");
                scanf(" %c", &emergency);

                if (emergency == 'Y' || emergency == 'y' ||
                    emergency == 'N' || emergency == 'n')
                {
                    break;
                }

                printf("Invalid value! Enter Y or N.\n");
            }
        }

        // Reject vehicles without permit unless emergency
        if ((permit == 'N' || permit == 'n') &&
            (emergency == 'N' || emergency == 'n'))
        {
            printf("Rejected: Invalid permit.\n");
            rejected++;
            continue;
        }

        // Determine required parking spaces
        if (type == 'V' || type == 'v')
        {
            space = 2;
        }

        // Parking Zone Assignment
        if (category == 'F' || category == 'f')
        {
            // Faculty -> Zone A
            if (zoneA + space <= capA)
            {
                zoneA += space;
                assigned = 1;
                printf("Assigned to Zone A (Faculty).\n");
            }
            else
            {
                printf("Rejected: No available space in Zone A.\n");
            }
        }
        else if (category == 'S' || category == 's')
        {
            // Students -> Zone B
            if (type == 'V' || type == 'v')
            {
                // Student van -> Zone C
                if (zoneC + space <= capC)
                {
                    zoneC += space;
                    assigned = 3;
                    printf("Assigned to Zone C (Visitor Zone).\n");
                }
                else
                {
                    printf("Rejected: No available space in Zone C.\n");
                }
            }
            else
            {
                if (zoneB + space <= capB)
                {
                    zoneB += space;
                    assigned = 2;
                    printf("Assigned to Zone B (Students).\n");
                }
                else
                {
                    printf("Rejected: No available space in Zone B.\n");
                }
            }
        }
        else if (category == 'G' || category == 'g')
        {
            // Visitors -> Zone C
            if (zoneC + space <= capC)
            {
                zoneC += space;
                assigned = 3;
                printf("Assigned to Zone C (Visitors).\n");
            }
            else
            {
                printf("Rejected: No available space in Zone C.\n");
            }
        }

        // Update Counters
        if (assigned != 0)
        {
            accepted++;

            if (type == 'C' || type == 'c')
            {
                cars++;
            }
            else if (type == 'B' || type == 'b')
            {
                bikes++;
            }
            else if (type == 'V' || type == 'v')
            {
                vans++;
            }

            // Display Remaining Capacity
            if (assigned == 1)
            {
                printf("Remaining capacity of Zone A: %d\n",
                       capA - zoneA);
            }
            else if (assigned == 2)
            {
                printf("Remaining capacity of Zone B: %d\n",
                       capB - zoneB);
            }
            else if (assigned == 3)
            {
                printf("Remaining capacity of Zone C: %d\n",
                       capC - zoneC);
            }
        }
        else
        {
            rejected++;
        }
    }

    // Final Parking Summary
    printf("\n========== PARKING SUMMARY ==========\n");

    printf("Total vehicles processed: %d\n", N);
    printf("Accepted vehicles: %d\n", accepted);
    printf("Rejected vehicles: %d\n", rejected);

    printf("Cars parked: %d\n", cars);
    printf("Bikes parked: %d\n", bikes);
    printf("Vans parked: %d\n", vans);

    printf("\n--- Zone Summary ---\n");

    printf("Zone A Occupied: %d / %d\n", zoneA, capA);
    printf("Zone A Remaining: %d\n", capA - zoneA);

    printf("Zone B Occupied: %d / %d\n", zoneB, capB);
    printf("Zone B Remaining: %d\n", capB - zoneB);

    printf("Zone C Occupied: %d / %d\n", zoneC, capC);
    printf("Zone C Remaining: %d\n", capC - zoneC);

    // Highest Occupancy
    if (zoneA >= zoneB && zoneA >= zoneC)
    {
        printf("\nHighest Occupancy: Zone A\n");
    }
    else if (zoneB >= zoneA && zoneB >= zoneC)
    {
        printf("\nHighest Occupancy: Zone B\n");
    }
    else
    {
        printf("\nHighest Occupancy: Zone C\n");
    }

    // Check if Entire Campus is Full
    totalSpaces = zoneA + zoneB + zoneC;

    if (totalSpaces == capA + capB + capC)
    {
        printf("Campus Parking: FULL\n");
    }
    else
    {
        printf("Campus Parking: Spaces Available\n");
    }

    printf("=====================================\n");

    return 0;
}
