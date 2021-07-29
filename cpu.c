#include "oslabs.h"
#include <stdio.h>

int main(){
  struct PCB new_process;
  struct PCB current_process;
  struct PCB ready_queue[QUEUEMAX];
  int queue_cnt = 0;

  current_process.process_id = 1;
  current_process.arrival_timestamp = 1;
  current_process.total_bursttime = 4;
  current_process.execution_starttime = 1;
  current_process.execution_endtime = 5;
  current_process.remaining_bursttime = 4;
  current_process.process_priority = 8;

  new_process.process_id = 2;
  new_process.arrival_timestamp = 2;
  new_process.total_bursttime = 3;
  new_process.execution_starttime = 0;
  new_process.execution_endtime = 0;
  new_process.remaining_bursttime = 3;
  new_process.process_priority = 6;
  struct PCB temp = handle_process_arrival_pp(ready_queue, &queue_cnt, current_process, new_process, 2);

  return 0;
}
