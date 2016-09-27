#include <hellfire.h>

void task1(void){
	int8_t *name = hf_selfname();
	uint16_t *id = hf_selfid();
    while (1) {
        printf("%d-%s\n",id,name);
    }
}

void task2(void){
	int8_t *name = hf_selfname();
	uint16_t *id = hf_selfid();
    while (1) {
        printf("%d-%s\n",id,name);
    }
}

void task3(void){
	int8_t *name = hf_selfname();
	uint16_t *id = hf_selfid();
    while (1) {
        printf("%d-%s\n",id,name);
    }
}

void task4(void){
	int8_t *name = hf_selfname();
	uint16_t *id = hf_selfid();
    while (1) {
        printf("%d-%s\n",id,name);
    }
}

void task5(void){
	int8_t *name = hf_selfname();
	uint16_t *id = hf_selfid();
    while (1) {
        printf("%d-%s\n",id,name);
    }
}

void app_main(void){
    //hf_spawn (void(*task)(), uint16_t period, uint16_t capacity, uint16_t deadline, int8_t *name, uint32_t stack_size)
	hf_spawn(task1, 5, 3, 5, "Task 1", 1024);
	hf_spawn(task2, 6, 3, 6, "Task 2", 1024);
	hf_spawn(task3, 3, 2, 7, "Task 3", 1024);
	hf_spawn(task4, 3, 2, 8, "Task 4", 1024);
	hf_spawn(task5, 3, 1, 9, "Task 5", 1024);/*
	hf_spawn(task1, 5, 3, 5, "Task 1", 1024);
	hf_spawn(task2, 6, 3, 6, "Task 2", 1024);
	hf_spawn(task3, 7, 2, 7, "Task 3", 1024);
	hf_spawn(task4, 8, 2, 8, "Task 4", 1024);
	hf_spawn(task5, 9, 1, 9, "Task 5", 1024);*/
}
