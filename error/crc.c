#include <stdio.h>

void divide(int dividend[50], int dividend_size, int divisor[50], int divisor_size, int remainder[50]) {
  int i, j, temp;
  int quotient[20];

  for(i=0; i<dividend_size; i++){
    temp = i;
    
    if(dividend[i] == 1){
      for(j=0; j<divisor_size; j++) {
          dividend[temp] = dividend[temp]^divisor[j];
          remainder[j] = dividend[temp];
          temp++;
      }
      quotient[i]=1;
    }else {
      quotient[i]=0;
    }
  }

  printf("\nThe quotient is:\n");
  for(i=0; i<dividend_size; i++) {
    printf("%d", quotient[i]);
  }

  printf("\nThe remainder is:\n");
  for(j=1; j<divisor_size; j++) {
    printf("%d", remainder[j]);
  }
}

void main() {
  int i, j, temp, count=0;
  int remainder[50], dividend[50], divisor[50], received_data[50], encoded_data[50];
  int dividend_size, divisor_size;

  printf("Enter the dividend size: ");
  scanf("%d", &dividend_size);

  printf("Enter the dividend:\n");
  for(i=0; i<dividend_size; i++) {
    scanf("%d", &dividend[i]);
  }

  for(i=0; i<dividend_size; i++) {
    encoded_data[i] = dividend[i];
  }

  printf("Enter the divisor size: ");
  scanf("%d", &divisor_size);

  printf("Enter the divisor\n");
  for(i=0; i<divisor_size; i++) {
    scanf("%d", &divisor[i]);
  }

  for(i=dividend_size; i<dividend_size+divisor_size-1; i++) {
    dividend[i] = 0;
  }

  divide(dividend, dividend_size, divisor, divisor_size, remainder);

  for(i=0; i<divisor_size-1; i++) {
    encoded_data[dividend_size+i] = remainder[i+1];
  }

  printf("\nThe encoded data is:\n");
  for(i=0; i<dividend_size+divisor_size-1; i++) {
    printf("%d", encoded_data[i]);
  }

  printf("\nEnter received data:\n");
  for(i=0; i<dividend_size+divisor_size-1; i++) {
    scanf("%d", &received_data[i]);
  }

  divide(received_data, dividend_size+divisor_size-1, divisor, divisor_size, remainder);
  
  for(j=0;j<divisor_size;j++) {
    if(remainder[j]) {
      printf("\nThe received data is incorrect\n");
      break;
    }
    count++;
  }

  if(count == divisor_size) {
    printf("\nThe received data is correct\n");
  }
}