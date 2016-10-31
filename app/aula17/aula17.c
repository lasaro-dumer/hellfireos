#include <hellfire.h>
#include <noc.h>

int8_t cpuToTask[10];
uint32_t timeout = 500;

void t1(void)
{
	//to: t2 t3 t4 t5 t7
	int8_t bufT2[256];
	int8_t bufT3[64];
	int8_t bufT4[64];
	int8_t bufT5[64];
	int8_t bufT7[1280];
	int32_t cpuid =  hf_cpuid();
	int32_t tid =  hf_selfid();
	uint16_t cpu, task, size, ret;

	if (hf_comm_create(hf_selfid(), 1001, 0))
		panic(0xff);

	hf_delay(tid,4);

	while (1){
		//				1234567890123456789012345678901234567890123456789012345678901234 (64)
		sprintf(bufT2, "T1: cpu %d, thread %d: size: %d to T2",cpuid,tid, sizeof(bufT2));
		ret = hf_sendack(cpuToTask[2], 1002, bufT2, sizeof(bufT2), 0, timeout);
		if (ret)
			printf("[T1>T2]hf_sendack(): error %d\n", ret);

		sprintf(bufT3, "T1: cpu %d, thread %d: size: %d to T3",cpuid,tid, sizeof(bufT3));
		ret = hf_sendack(cpuToTask[3], 1003, bufT3, sizeof(bufT3), 0, timeout);
		if (ret)
			printf("[T1>T3]hf_sendack(): error %d\n", ret);

		sprintf(bufT4, "T1: cpu %d, thread %d: size: %d to T4",cpuid,tid, sizeof(bufT4));
		ret = hf_sendack(cpuToTask[4], 1004, bufT4, sizeof(bufT4), 0, timeout);
		if (ret)
			printf("[T1>T4]hf_sendack(): error %d\n", ret);

		sprintf(bufT5, "T1: cpu %d, thread %d: size: %d to T5",cpuid,tid, sizeof(bufT5));
		ret = hf_sendack(cpuToTask[5], 1005, bufT5, sizeof(bufT5), 0, timeout);
		if (ret)
			printf("[T1>T5]hf_sendack(): error %d\n", ret);

		sprintf(bufT7, "T1: cpu %d, thread %d: size: %d to T7",cpuid,tid, sizeof(bufT7));
		ret = hf_sendack(cpuToTask[7], 1007, bufT7, sizeof(bufT7), 0, timeout);
		if (ret)
			printf("[T1>T7]hf_sendack(): error %d\n", ret);

		// ret = hf_recvack(&cpu, &task, bufT1, &size, 0);
		// if (ret)
		// 	printf("[**>T2]hf_recvack(): error %d\n", ret);
		// else
		// 	printf("[%s] from  task: %u\n", bufT1,task);
	}
}

void t2(void)
{
	int8_t bufT1[256];
	int8_t bufT6[64];
	int8_t bufT7[320];
	int8_t bufT8[320];
	int32_t cpuid =  hf_cpuid();
	int32_t tid =  hf_selfid();
	uint16_t cpu, task, size, ret;

	if (hf_comm_create(hf_selfid(), 1002, 0))
		panic(0xff);

	hf_delay(tid,3);

	while (1){
		ret = hf_recvack(&cpu, &task, bufT1, &size, 0);
		if (ret)
			printf("[**>T2]hf_recvack(): error %d\n", ret);
		else
			printf("[%s] from  task: %u\n", bufT1,task);

		sprintf(bufT6, "T2: cpu %d, thread %d: size: %d to T6",cpuid,tid, sizeof(bufT6));
		ret = hf_sendack(cpuToTask[6], 1006, bufT6, sizeof(bufT6), 0, timeout);
		if (ret)
			printf("[T2>T6]hf_sendack(): error %d\n", ret);

		sprintf(bufT7, "T2: cpu %d, thread %d: size: %d to T7",cpuid,tid, sizeof(bufT7));
		ret = hf_sendack(cpuToTask[7], 1007, bufT7, sizeof(bufT7), 0, timeout);
		if (ret)
			printf("[T2>T7]hf_sendack(): error %d\n", ret);

		sprintf(bufT8, "T2: cpu %d, thread %d: size: %d to T8",cpuid,tid, sizeof(bufT8));
		ret = hf_sendack(cpuToTask[8], 1008, bufT8, sizeof(bufT8), 0, timeout);
		if (ret)
			printf("[T2>T8]hf_sendack(): error %d\n", ret);
	}
}

void t3(void)
{
	int8_t bufT1[64];
	int8_t bufT7[320];
	int8_t bufT8[64];
	int32_t cpuid =  hf_cpuid();
	int32_t tid =  hf_selfid();
	uint16_t cpu, task, size, ret;

	if (hf_comm_create(hf_selfid(), 1003, 0))
		panic(0xff);

	hf_delay(tid,3);

	while (1){
		ret = hf_recvack(&cpu, &task, bufT1, &size, 0);
		if (ret)
			printf("[**>T3]hf_recvack(): error %d\n", ret);
		else
			printf("[%s] from  task: %u\n", bufT1,task);

		sprintf(bufT7, "T3: cpu %d, thread %d: size: %d to T7",cpuid,tid, sizeof(bufT7));
		ret = hf_sendack(cpuToTask[7], 1007, bufT7, sizeof(bufT7), 0, timeout);
		if (ret)
			printf("[T3>T7]hf_sendack(): error %d\n", ret);

		sprintf(bufT8, "T3: cpu %d, thread %d: size: %d to T8",cpuid,tid, sizeof(bufT8));
		ret = hf_sendack(cpuToTask[8], 1008, bufT8, sizeof(bufT8), 0, timeout);
		if (ret)
			printf("[T3>T8]hf_sendack(): error %d\n", ret);
	}
}
void t4(void)
{
	int8_t bufT1[64];
	int8_t bufT8[64];
	int32_t cpuid =  hf_cpuid();
	int32_t tid =  hf_selfid();
	uint16_t cpu, task, size, ret;

	if (hf_comm_create(hf_selfid(), 1004, 0))
		panic(0xff);

	hf_delay(tid,3);

	while (1){
		ret = hf_recvack(&cpu, &task, bufT1, &size, 0);
		if (ret)
			printf("[**>T4]hf_recvack(): error %d\n", ret);
		else
			printf("[%s] from  task: %u\n", bufT1,task);

		sprintf(bufT8, "T4: cpu %d, thread %d: size: %d to T8",cpuid,tid, sizeof(bufT8));
		ret = hf_sendack(cpuToTask[8], 1008, bufT8, sizeof(bufT8), 0, timeout);
		if (ret)
			printf("[T4>T8]hf_sendack(): error %d\n", ret);
	}
}
void t5(void)
{
	int8_t bufT1[64];
	int8_t bufT8[640];
	int32_t cpuid =  hf_cpuid();
	int32_t tid =  hf_selfid();
	uint16_t cpu, task, size, ret;

	if (hf_comm_create(hf_selfid(), 1005, 0))
		panic(0xff);

	hf_delay(tid,3);

	while (1){
		ret = hf_recvack(&cpu, &task, bufT1, &size, 0);
		if (ret)
			printf("[**>T5]hf_recvack(): error %d\n", ret);
		else
			printf("[%s] from  task: %u\n", bufT1,task);

		sprintf(bufT8, "T5: cpu %d, thread %d: size: %d to T8",cpuid,tid, sizeof(bufT8));
		ret = hf_sendack(cpuToTask[8], 1008, bufT8, sizeof(bufT8), 0, timeout);
		if (ret)
			printf("[T5>T8]hf_sendack(): error %d\n", ret);
	}
}
void t6(void)
{
	int8_t bufT2[64];
	int8_t bufT9[640];
	int32_t cpuid =  hf_cpuid();
	int32_t tid =  hf_selfid();
	uint16_t cpu, task, size, ret;

	if (hf_comm_create(hf_selfid(), 1006, 0))
		panic(0xff);

	while (1){
		ret = hf_recvack(&cpu, &task, bufT2, &size, 0);
		if (ret)
			printf("[**>T6]hf_recvack(): error %d\n", ret);
		else
			printf("[%s] from  task: %u\n", bufT2,task);

		sprintf(bufT9, "T6: cpu %d, thread %d: size: %d to T9",cpuid,tid, sizeof(bufT9));
		ret = hf_sendack(cpuToTask[9], 1009, bufT9, sizeof(bufT9), 0, timeout);
		if (ret)
			printf("[T6>T9]hf_sendack(): error %d\n", ret);
	}
}
void t7(void)
{
	int8_t buffRecv[1280];
	int8_t bufT9[640];
	int32_t cpuid =  hf_cpuid();
	int32_t tid =  hf_selfid();
	uint16_t cpu, task, size, ret;
	int8_t recT1=0,recT2=0,recT3=0;
	if (hf_comm_create(hf_selfid(), 1007, 0))
		panic(0xff);

	while (1){
		while (!recT1 || !recT2 || !recT3) {
			ret = hf_recvack(&cpu, &task, buffRecv, &size, 0);
			if (ret)
				printf("[**>T7]hf_recvack(): error %d\n", ret);
			else
				printf("[%s] recv1 from  task: %u\n", buffRecv,task);
			if(!recT1 && task==1001)
				recT1 = 1;
			else if(!recT2 && task == 1002)
				recT2 = 1;
			else if(!recT3 && task == 1003)
				recT3 = 1;
		}
		printf("T7 received all\n");
		recT1=0;
		recT2=0;
		recT3=0;

		sprintf(bufT9, "T7: cpu %d, thread %d: size: %d to T9",cpuid,tid, sizeof(bufT9));
		ret = hf_sendack(cpuToTask[9], 1009, bufT9, sizeof(bufT9), 0, timeout);
		if (ret)
			printf("[T7>T9]hf_sendack(): error %d\n", ret);
	}
}

void t8(void)
{
	int8_t buffRecv[640];
	int8_t bufT9[640];
	int32_t cpuid =  hf_cpuid();
	int32_t tid =  hf_selfid();
	uint16_t cpu, task, size, ret;
	int8_t recT2=0,recT3=0,recT4=0,recT5=0;

	if (hf_comm_create(hf_selfid(), 1008, 0))
		panic(0xff);

	while (1){
		while (!recT2 || !recT3 || !recT4 || !recT5) {
			ret = hf_recvack(&cpu, &task, buffRecv, &size, 0);
			if (ret)
				printf("[**>T8]hf_recvack(): error %d\n", ret);
			else
				printf("[%s] recv1 from  task: %u\n", buffRecv,task);
			if(!recT2 && task == 1002)
				recT2 = 1;
			else if(!recT3 && task == 1003)
				recT3 = 1;
			else if(!recT4 && task == 1004)
				recT4 = 1;
			else if(!recT5 && task == 1005)
				recT5 = 1;
		}
		printf("T8 received all\n");
		recT2=0;
		recT3=0;
		recT4=0;
		recT5=0;

		sprintf(bufT9, "T8: cpu %d, thread %d: size: %d to T9",cpuid,tid, sizeof(bufT9));
		ret = hf_sendack(cpuToTask[9], 1009, bufT9, sizeof(bufT9), 0, timeout);
		if (ret)
			printf("[T8>T9]hf_sendack(): error %d\n", ret);
	}
}

void t9(void)
{
	int8_t buffRecv[640];
	uint16_t cpu, task, size, ret;
	int8_t recT6=0,recT7=0,recT8=0;

	if (hf_comm_create(hf_selfid(), 1009, 0))
		panic(0xff);

	while (1){
		while (!recT6 || !recT7 || !recT8) {
			ret = hf_recvack(&cpu, &task, buffRecv, &size, 0);
			if (ret)
				printf("[**>T9]hf_recvack(): error %d\n", ret);
			else
				printf("[%s] recv1 from  task: %u\n", buffRecv,task);
			if(!recT6 && task==1006)
				recT6 = 1;
			else if(!recT7 && task == 1007)
				recT7 = 1;
			else if(!recT8 && task == 1008)
				recT8 = 1;
		}
		printf("T9 received all\n");
		recT6=0;
		recT7=0;
		recT8=0;
	}
}
void app_main(void)
{
	// cpu 0: 1
	// cpu 1: 2,6,8
	// cpu 2: 3, 9
	// cpu 3:4
	// cpu 4:5
	// cpu 5:7
	cpuToTask[0]=-1;//just to keep index==task number
	cpuToTask[1]=0;
	cpuToTask[2]=1;
	cpuToTask[3]=2;
	cpuToTask[4]=3;
	cpuToTask[5]=4;
	cpuToTask[6]=1;
	cpuToTask[7]=5;
	cpuToTask[8]=1;
	cpuToTask[9]=2;
	if (hf_cpuid() == cpuToTask[1]){
		hf_spawn(t1, 0, 0, 0, "T1", 4096);
	}else if (hf_cpuid() == cpuToTask[2]){
		hf_spawn(t2, 0, 0, 0, "T2", 4096);
	}else if (hf_cpuid() == cpuToTask[3]){
		hf_spawn(t3, 0, 0, 0, "T3", 4096);
	}else if (hf_cpuid() == cpuToTask[4]){
		hf_spawn(t4, 0, 0, 0, "T4", 4096);
	}else if (hf_cpuid() == cpuToTask[5]){
		hf_spawn(t5, 0, 0, 0, "T5", 4096);
	}else if (hf_cpuid() == cpuToTask[6]){
		hf_spawn(t6, 0, 0, 0, "T6", 4096);
	}else if (hf_cpuid() == cpuToTask[7]){
		hf_spawn(t7, 0, 0, 0, "T7", 4096);
	}else if (hf_cpuid() == cpuToTask[8]){
		hf_spawn(t8, 0, 0, 0, "T8", 4096);
	}else if (hf_cpuid() == cpuToTask[9]){
		hf_spawn(t9, 0, 0, 0, "T9", 4096);
	}
}
