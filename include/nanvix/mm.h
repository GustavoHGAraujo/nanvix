/*
 * Copyright (C) 2011-2013 Pedro H. Penna <pedrohenriquepenna@gmail.com>
 * 
 * mm.h - Memory management
 */

#ifndef MM_H_
#define MM_H_
	
	#include <i386/i386.h>
	#include <nanvix/const.h>
	#include <sys/types.h>
	
	/* Kernel stack size. */
	#define KSTACK_SIZE 4096

	/* Virtual memory layout. */
	#define UBASE_VIRT  0x00400000 /* User base.        */
	#define KBASE_VIRT  0xc0000000 /* Kernel base.      */
	#define KPOOL_VIRT  0xc0400000 /* Kernel page pool. */
	
	/* Physical memory layout. */
	#define KBASE_PHYS 0x00000000 /* Kernel base.      */
	#define KPOOL_PHYS 0x00400000 /* Kernel page pool. */
	#define UBASE_PHYS 0x00800000 /* User base.        */

	/* Kernel memory size: 4 MB. */
	#define KMEM_SIZE 0x00400000
	
	/* Kernel page pool size: 4 MB. */
	#define KPOOL_SIZE 0x00400000
	
	/* User memory size. */
	#define UMEM_SIZE (MEMORY_SIZE - KMEM_SIZE - KPOOL_SIZE)

	/* chkmem() request types. */
	#define CHKMEM_FUNCTION  0 /* Function.      */
	#define CHKMEM_CHUNK     1 /* Chunk of data. */

#ifndef _ASM_FILE_
	
	EXTERN void mm_init();
	
	/*
	 * Checks a memory area.
	 */
	EXTERN int chkmem(addr_t addr, int type, ...);
	
	EXTERN int fubyte(void *addr);

#endif /* _ASM_FILE_ */
	
#endif /* MM_H_ */
