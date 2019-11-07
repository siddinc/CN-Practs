#include <stdio.h>

int packets_transmitted(int machines[], int no_of_machines) {
  int i;

  for(i=0; i<no_of_machines; i++) {
    if(machines[i]) {
      return 1;
    }
  }
  return 0;
}

void main() {
  int i, min_capacity, storage, no_of_machines, outgoing, bucket_size;
  int machines[10];

  printf("Enter bucket size: ");
  scanf("%d", &bucket_size);

  storage = bucket_size;

  printf("Enter no. of machines: ");
  scanf("%d", &no_of_machines);

  outgoing = (int)bucket_size/no_of_machines;
  printf("The outgoing rate is: %d\n", outgoing);

  for(i=0; i<no_of_machines; i++) {
    printf("Enter packets for machine %d: ", i+1);
    scanf("%d", &machines[i]);
  }

  printf("------------------------------\n");

  while(packets_transmitted(machines, no_of_machines)) {
    if(storage > 0) {
      for(i=0; i<no_of_machines; i++) {
        if(storage == 0) {
          break;
        }
        min_capacity = (storage > outgoing) ? outgoing : storage;

        if(machines[i]) {
          printf("Machine %d has %d packets\n", i+1, machines[i]);

          min_capacity = (min_capacity > machines[i]) ? machines[i] : min_capacity;

          printf("Outputted %d packets\n", min_capacity);
          printf("Dropped %d packets in machine %d\n", machines[i]-min_capacity, i+1);

          storage -= min_capacity;
          machines[i] -= min_capacity;

          printf("Bucket storage size %d remaining out of %d\n", storage, bucket_size);
          printf("------------------------------\n");
        }
      }
    } else {
      printf("\nWaiting storage is full\n");
      printf("Reinitialising storage\n");
      printf("\n------------------------------\n");

      storage = bucket_size;
    }
  }
  printf("All packets transmitted\n");
}