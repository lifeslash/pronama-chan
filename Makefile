#==========================================
#	Copyright 1993, 1998, 2014
#                 Toyoda Masashi
#		  (mtoyoda@acm.org)
#==========================================

CC=gcc
CFLAGS=-O
pronama: pronama.c pronama.h
	$(CC) $(CFLAGS) -o pronama pronama.c -lncurses
