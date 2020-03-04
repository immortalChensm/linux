#include <stdio.h>
#include <unistd.h>

int main()
{
	long mq_open_max = sysconf(_SC_MQ_OPEN_MAX);
	long mq_prio_max = sysconf(_SC_MQ_PRIO_MAX);

	printf("mq_open_max:%ld\n",mq_open_max);
	printf("mq_prio_mqx:%ld\n",mq_prio_max);

	return 0;
}
