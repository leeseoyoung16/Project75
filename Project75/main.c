#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX_SIZE 20
#define SWAP(x,y,t) ((t)=(x), (x)=(y), (y)=(t))

int list[MAX_SIZE];
int n;
int move, compare;

//����

void print_array(int arr[], int size) { //���� ���
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void insertion(int list[], int n) {
    int i, j, key;
    move = 0;
    compare = 0;

    for (i = 1; i < n; i++) {
        key = list[i];
        for (j = i - 1; j >= 0 && list[j] > key; j--) {
            list[j + 1] = list[j];
            move += 1;
            compare += 1;
        }
        list[j + 1] = key;
        move += 1;
        compare += 1;
        print_array(list, n);
    }

   
}

void insertion2(int list[], int n) {
    int i, j, key;
    move = 0;
    compare = 0;

    for (i = 1; i < n; i++) {
        key = list[i];
        for (j = i - 1; j >= 0 && list[j] > key; j--) {
            list[j + 1] = list[j];
            move += 1;
            compare += 1;
        }
        list[j + 1] = key;
        move += 1;
        compare += 1;
        //print_array(list, n);
    }


}
int main(void) {
    int i, j;
    int move_count = 0;
    int compare_count = 0;
    n = MAX_SIZE;

    srand(time(NULL));
    for (i = 0; i < n; i++)
        list[i] = rand() % 100;

    printf("Original list\n");
    print_array(list, n);

    printf("Insertion Sort\n");
    insertion(list, n);

    printf("Move Count: %d\n", move);
    printf("Compare Count: %d\n\n", compare);

    move_count += move;
    compare_count += compare;

    for (j = 1; j <= 19; j++) {
        for (i = 0; i < n; i++)
            list[i] = rand() % 100;

        printf("Original list\n");
        print_array(list, n);

        printf("Insertion Sort\n");
        insertion2(list, n);
        print_array(list, n);

        move_count += move;
        compare_count += compare;
        printf("\n");

    }
    printf("Average Move Count: %d\n", move_count / 20);
    printf("Average Compare Count: %d\n", compare_count / 20);



    return 0;
}