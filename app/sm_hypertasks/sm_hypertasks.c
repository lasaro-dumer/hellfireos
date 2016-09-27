#include <hellfire.h>

void task(void){
	int8_t *name = hf_selfname();
    while (1) {
        printf("t%s\n",name);
    }
}

void app_main(void){
    //hf_spawn (void(*task)(), uint16_t period, uint16_t capacity, uint16_t deadline, int8_t *name, uint32_t stack_size)
	hf_spawn(task, 15, 5 , 50, "T1", 1024);
	hf_spawn(task, 10, 10, 35, "T2", 1024);
	hf_spawn(task, 20, 15, 40, "T3", 1024);
	hf_spawn(task, 25, 10, 36, "T4", 1024);
	hf_spawn(task, 15, 8 , 39, "T5", 1024);
}
