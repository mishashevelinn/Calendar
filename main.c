#include <stdio.h>
#include <math.h>

int num_days_in_month(int y, int m) {          //returns the number of days in month
    int mo[12] = {1, 3, 5, 7, 8, 10, 12, 4, 6, 9, 11, 2}; //arranging differently long months in array by month number
    for (int i = 0; i < 12; i++) {
        if (m == mo[i]) {
            if (i < 7)                       //according to month position in array, returns an amount of days in month
                return 31;
            if (i < 11)
                return 30;
            if ((y % 4 == 0 && y % 100 != 0) ||  y % 400 == 0)  //with respect to leap year's length of February(located last in array)
                return 29;
            else
                return 28;
        }
    }
}

int calendar(int d, int m, int y, int future) {       //recursion counts days and updates the date till desired date reached
    if (future == 0)                                  //d for day, m for month, y for year, future for days to be added to a present date
        return d * pow(10, 6) + m * pow(10, 4) + y;         // stop if we are in present
    if ((d == num_days_in_month(y, m)) && (m == 12))
        return calendar(1, 1, y + 1, future - 1); //new year
    if (d == num_days_in_month(y, m))
        return calendar(1, m + 1, y, future - 1); // new month
    else
        return calendar(d + 1, m, y, future - 1); //new day

}

void check_and_print(int d, int m, int y, int future) {         //performs needed checks of the input and prints error message or result
    int result;
    if (m > 12 || d <= 0 || d > num_days_in_month(y, m)) {
        printf("Illegal date %d/%d/%d\n", d, m, y);
        return;
    }
    if (future < 0) {
        printf("Illegal number of days %d\n", future);
        return;
    } else
        result = calendar(d, m, y, future);
        printf("%d/%d/%d\n", result / 1000000, (result % 1000000) / 10000, (result % 1000000) % 10000);
}

int main() {
    int d, m, y, future;
    printf("Enter the day:");
    scanf("%d", &d);
    printf("Enter the month:");
    scanf("%d", &m);
    printf("Enter the year:");
    scanf("%d", &y);
    printf("Enter the number of days:");
    scanf("%d", &future);
    check_and_print(d, m, y, future);
    return 0;
}