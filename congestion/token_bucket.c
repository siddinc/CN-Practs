#include <stdio.h>

void main() {
  int i, no_of_machines, no_of_iterations;
  int bucket_size, token_count, input_packet_size, fill_rate;
  int machines[4];

  printf("Enter no. of iterations: ");
  scanf("%d", &no_of_iterations);

  printf("Enter bucket size: ");
  scanf("%d", &bucket_size);

  token_count = bucket_size;

  printf("Enter fill rate: ");
  scanf("%d", &fill_rate);

  printf("Enter no. of machines: ");
  scanf("%d", &no_of_machines);

  for(i=0; i<no_of_machines; i++) {
    printf("Enter packets of machine %d: ", i+1);
    scanf("%d", &machines[i]);
  }

	for(i=0; i<no_of_iterations; i++){
	  input_packet_size = machines[i];
	  
	  printf("\n----------Iteration %d-----------\n", i+1);
	  printf("\nPacket Size: %d\n", input_packet_size);
	  printf("Total Tokens Available: %d\n", token_count);
	  
	  if(input_packet_size <= token_count){
      printf("Enough Tokens available\n");
      token_count -= input_packet_size;
	  }else{
	    printf("Enough Tokens not available\n");
	  }
	  
    if(token_count != bucket_size) {
      printf("Added %d tokens in Bucket\n", fill_rate);
      token_count += fill_rate;
    }
    printf("Total Tokens in Bucket after this iteration: %d\n", token_count);
  }
}