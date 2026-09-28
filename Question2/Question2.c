
#include <stdio.h>
int main(){
    int N, currentFloor = 0, requestedFloor, i;

    printf("Enter number of requests: ");
    scanf("%d", &N);

    for (i = 1; i <= N; i++)
    {
        printf("Enter requested floor: ");
        scanf("%d", &requestedFloor);

        if (requestedFloor > currentFloor)
        {
            printf("Moving Up\n");
        }
        else if (requestedFloor < currentFloor)
        {
            printf("Moving Down\n");
        }
        else
        {
            printf("Doors Opening\n");
        }currentFloor = requestedFloor;
    }
     return 0;
}
