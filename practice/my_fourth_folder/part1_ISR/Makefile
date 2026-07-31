CC=gcc
CFLAG=-g -Wall
rtos_sim:rtos_sim.c
	$(CC) $(CFLAG) $< -o $@ -pthread
%:%.c
	$(CC) $(CFLAG) $< -o $@
