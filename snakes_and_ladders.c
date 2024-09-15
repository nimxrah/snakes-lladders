#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n); //no of snakes+ladders
    int board[100];
    for (int i=0;i<100; i++){
        board[i] = -1;
    }
    int a, b;
    for(int i =0; i<n; i++){
        scanf("%d %d ", &a, &b);  //start pos, end pos
        board[a] = b;     //ladder/snake
    }
    int seq_no;         //no of chances
    scanf("%d", &seq_no);
    int seq_arr[seq_no];  //chances sequence

    for(int i =0; i<seq_no; i++){
        scanf("%d", &seq_arr[i]);
    }

    int p1 = 0;
    int p2 = 0;

    for (int i=0; i<seq_no; i+=2){
        if(board[seq_arr[i]+p1] == -1 && p1<100){
            p1 = p1 + seq_arr[i];
        }
        else{
            p1 = board[seq_arr[i]+p1];
            while(board[p1]!=-1 && p1<100){
            p1 = board[p1]; //encountered ladder or snake
            }
    }
    }
    for (int i=1; i<seq_no; i+=2){
        if(board[seq_arr[i]+p2] == -1 && p2<100){   //no ladder or snake
            p2 = p2 + seq_arr[i];

        }
        else{
                p2 = board[seq_arr[i]+p2];
            while(board[p2]!=-1 && p2<100){
            p2 = board[p2]; //encountered ladder or snake
            }
    }
    }
    if (p1 == p2){
        if (seq_no%2!=0){
            printf("p2, %d\n", p2);
        }
        else{
            printf("p1, %d\n", p1);
        }
    }
    else if(p1 > p2){
        printf("p1, %d\n", p1);
    }
    else{
        printf("p2, %d\n", p2);
    }
    return 0;
}