
#include <stdio.h>

int main()
{
    int N, i, j, marks, sum;
    float average;
    int deficiency;

    printf("Enter number of students: ");
    scanf("%d", &N);

    for (i = 1; i <= N; i++)
    {
        sum = 0;
        deficiency = 0;

        printf("\nStudent %d\n", i);

        for (j = 1; j <= 5; j++)
        {
            printf("Enter marks of subject %d: ", j);
            scanf("%d", &marks);

            sum = sum + marks;

            if (marks < 33)
            {
                deficiency = 1;
            }
        }

        average = sum / 5.0;

        printf("Total Marks = %d\n", sum);
        printf("Average = %.2f\n", average);

        if (deficiency == 1)
        {
            printf("Result: Fail - Subject Deficiency\n");
        }
        else if (average >= 80)
        {
            printf("Result: Distinction\n");
        }
        else if (average >= 60)
        {
            printf("Result: Pass\n");
        }
        else
        {
            printf("Result: Fail\n");
        }
    }

    return 0;
}
