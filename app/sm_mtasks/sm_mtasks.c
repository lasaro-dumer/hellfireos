#include <hellfire.h>

void task(void){
	int8_t *name = hf_selfname();
    while (1) {
        printf("t%s\n",name);
    }
}

void app_main(void){
    //hf_spawn (void(*task)(), uint16_t period, uint16_t capacity, uint16_t deadline, int8_t *name, uint32_t stack_size)
	hf_spawn(task, 5, 4, 10, "T1", 1024);
	hf_spawn(task, 6, 5, 12, "T2", 1024);
	hf_spawn(task, 5, 5, 9, "T3", 1024);
	hf_spawn(task, 5, 4, 11, "T4", 1024);
	hf_spawn(task, 5, 4, 10, "T5", 1024);
}
