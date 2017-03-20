// UVa 11926 - Multitasking.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cstdio>
#include <bitset>


using namespace std;

int main()
{
	bitset<1000005> schedule;
	int start, end, interval,
		n_one_time_task, n_repeating_task,
		temp;
	bool conflict;

	while (true)
	{
		scanf("%d %d", &n_one_time_task, &n_repeating_task);
		if (n_one_time_task == 0 && n_repeating_task == 0)
			break;

		schedule.reset();
		conflict = false;

		for (int i = 0; i < n_one_time_task; i++)
		{
			scanf("%d %d", &start, &end);
			for (int i = start; i < end; i++)
			{
				if (schedule.test(i))
				{
					conflict = true;
					break;
				}
				else 
					schedule.set(i);
			}
		}

		for (int i = 0; i < n_repeating_task; i++)
		{
			scanf("%d %d %d", &start, &end, &interval);

			while (start <= 1000000)
			{
				for (int i = start; i < end; i++)
				{
					if (schedule.test(i))
					{
						conflict = true;
						break;
					}
					else
						schedule.set(i);
				}

				start += interval;
				if (end + interval > 1000000)
					end = 1000000;
				else
					end += interval;
			}
		}

		if (conflict)
			printf("CONFLICT\n");
		else
			printf("NO CONFLICT\n");
	}

	return 0;
}

