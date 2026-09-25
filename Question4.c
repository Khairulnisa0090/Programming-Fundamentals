
#include <stdio.h>

// Function 1: Calculate Subtotal
float subtotal(int q, float p)
{
    return q * p;
}

// Function 2: Calculate Discount
float discount(float s, float d)
{
    return s - (s * d) / 100;
}

// Function 3: Calculate Final Bill
float finalBill(float a, float t)
{
    return a + (a * t) / 100;
}

int main()
{
    int q;
    float p, d, t;
    float s, a, bill;

    printf("Enter quantity: ");
    scanf("%d", &q);

    printf("Enter price per item: ");
    scanf("%f", &p);

    printf("Enter discount percentage: ");
    scanf("%f", &d);

    printf("Enter tax percentage: ");
    scanf("%f", &t);

    s = subtotal(q, p);
    a = discount(s, d);
    bill = finalBill(a, t);

    printf("\nSubtotal = %.2f\n", s);
    printf("Discounted Amount = %.2f\n", a);
    printf("Final Bill = %.2f\n", bill);

    return 0;
}
