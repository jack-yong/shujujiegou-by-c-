#include "queue.h"

void main()
{
	int i = 0;
	struct Queue* q1 = InitQueue();
	int p[10]= {1,2,3,4,5,6,7,8,9,10};
	while(p[i])
	{
		EnQueue(q1,p[i]);
		//printf("%d\n",DeQueue(q1));
		i++;
	}
	printf("%d\n",DeQueue(q1));
	DestoryQueue(q1);
}
