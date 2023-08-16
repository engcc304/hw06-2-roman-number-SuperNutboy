/*
    ผู้ใช้กรอกตัวเลขเข้ามาในระบบ และให้คุณแปลงตัวเลขดังกล่าวให้เป็นตัวเลขโรมัน
    (โจทย์ข้อนี้ให้ใช้ For Loop เท่านั้น)

    Test case:
        8
    Output:
        8 = VIII

    Test case:
        4
    Output:
        4 = IV

    Test case:
        514
    Output:
        514 = DXIV

    Test case:
        929
    Output:
        929 = CMXXIX

*/
#include <stdio.h>

void printRoman(int num, char one, char five, char ten) {
    if (num == 9) {
        printf("%c%c", one, ten);
    } else if (num >= 5) {
        printf("%c", five);
        for (int i = 6; i <= num; i++) {
            printf("%c", one);
        }
    } else if (num == 4) {
        printf("%c%c", one, five);
    } else {
        for (int i = 1; i <= num; i++) {
            printf("%c", one);
        }
    }
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    if (num <= 0) {
        printf("Invalid input\n");
        return 1;
    }

    printf("%d = ", num);

    int thousands = num / 1000;
    for (int i = 1; i <= thousands; i++) {
        printf("M");
    }

    num = num % 1000;
    int hundreds = num / 100;
    printRoman(hundreds, 'C', 'D', 'M');

    num = num % 100;
    int tens = num / 10;
    printRoman(tens, 'X', 'L', 'C');

    num = num % 10;
    printRoman(num, 'I', 'V', 'X');

    printf("\n");

    return 0;
}