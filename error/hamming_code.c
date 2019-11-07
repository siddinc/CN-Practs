#include <stdio.h>

int receiver(int frame[12]) {
  int c1, c2, c4, c8, temp, i;

  for(i=0; i<12/2; i++) {
    temp = frame[i];
    frame[i] = frame[12 - i - 1];
    frame[12 - i - 1] = temp;
  }

  c1 = ((frame[0] + frame[2] + frame[4] + frame[6] + frame[8] + frame[10]) % 2 == 0) ? 0 : 1;
  c2 = ((frame[1] + frame[2] + frame[5] + frame[6] + frame[9] + frame[10]) % 2 == 0) ? 0 : 1;
  c4 = ((frame[3] + frame[4] + frame[5] + frame[6] + frame[11]) % 2 == 0) ? 0 : 1;
  c8 = ((frame[7] + frame[8] + frame[9] + frame[10] + frame[11]) % 2 == 0) ? 0 : 1;
  return ((c8 * 8) + (c4 * 4) + (c2 * 2) + (c1 * 1));
}

void main() {
  int input_stream[8], receiver_stream[12], frame[12];
  int i, temp, ans;

  for(i=0; i<12; i++) {
    frame[i] = 0;
  }

  printf("Enter the input stream: ");
  for(i=0; i<8; i++) {
    scanf("%d", &input_stream[i]);
  }

  for(i=0; i<8/2; i++) {
    temp = input_stream[i];
    input_stream[i] = input_stream[8 - i - 1];
    input_stream[8 - i - 1] = temp;
  }

  frame[2] = input_stream[0];
  frame[4] = input_stream[1];
  frame[5] = input_stream[2];
  frame[6] = input_stream[3];
  frame[8] = input_stream[4];
  frame[9] = input_stream[5];
  frame[10] = input_stream[6];
  frame[11] = input_stream[7];

  frame[0] = ((frame[2] + frame[4] + frame[6] + frame[8] + frame[10]) % 2 == 0) ? 0 : 1;
  frame[1] = ((frame[2] + frame[5] + frame[6] + frame[9] + frame[10]) % 2 == 0) ? 0 : 1;
  frame[3] = ((frame[4] + frame[5] + frame[6] + frame[11]) % 2 == 0) ? 0 : 1;
  frame[7] = ((frame[8] + frame[9] + frame[10] + frame[11]) % 2 == 0) ? 0 : 1;

  printf("The hamming code is:\n");
  for(i=11; i>=0; i--) {
    printf("%d", frame[i]);
  }
  
  printf("\nEnter receiver stream: ");
  for(i=0; i<12; i++) {
    scanf("%d", &receiver_stream[i]);
  }

  ans = receiver(receiver_stream);

  if(ans == 0) {
    printf("No error found\n");
  } else {
    printf("Error found at position %d\n", (12 - ans + 1));
  }
}