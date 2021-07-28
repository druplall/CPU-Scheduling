#include "oslabs.h"


struct PCB handle_process_arrival_pp(struct PCB ready_queue[QUEUEMAX], int *queue_cnt, struct PCB current_process, struct PCB new_process, int timestamp)
{
    if ((current_process.process_id == 0) && (current_process.arrival_timestamp == 0) && (current_process.total_bursttime == 0) && (current_process.execution_starttime == 0) && (current_process.execution_endtime == 0) && (current_process.remaining_bursttime == 0) && (current_process.process_priority == 0))
    {
        new_process.execution_starttime = timestamp;
        new_process.execution_endtime = timestamp + new_process.total_bursttime;
        new_process.remaining_bursttime = new_process.total_bursttime;
        return new_process;
    }
    else if (new_process.process_priority >= current_process.process_priority)
    {
        new_process.execution_starttime = 0;
        new_process.execution_endtime = 0;
        new_process.remaining_bursttime = new_process.total_bursttime;
        ready_queue[*queue_cnt] = new_process;
        (*queue_cnt)++;
        return current_process;
    }
    else
    {
        new_process.execution_starttime = timestamp;
        new_process.execution_endtime = timestamp + new_process.total_bursttime;
        new_process.remaining_bursttime = new_process.total_bursttime;

        current_process.execution_endtime = 0;
        current_process.remaining_bursttime = current_process.remaining_bursttime - 1;
        ready_queue[*queue_cnt] = current_process;
        (*queue_cnt)++;

        return new_process;
      }
}

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
