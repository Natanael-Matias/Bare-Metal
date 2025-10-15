
obj\main.o:     file format elf32-littlearm


Disassembly of section .text:

00000000 <main>:
   0:	b580      	push	{r7, lr}
   2:	af00      	add	r7, sp, #0
   4:	4802      	ldr	r0, [pc, #8]	; (10 <main+0x10>)
   6:	f7ff fffe 	bl	0 <AppInit>
   a:	f7ff fffe 	bl	0 <AppStart>
   e:	e7fe      	b.n	e <main+0xe>
  10:	00000000 	.word	0x00000000

00000014 <Task1Handler>:
  14:	b580      	push	{r7, lr}
  16:	b084      	sub	sp, #16
  18:	af00      	add	r7, sp, #0
  1a:	2306      	movs	r3, #6
  1c:	713b      	strb	r3, [r7, #4]
  1e:	230d      	movs	r3, #13
  20:	717b      	strb	r3, [r7, #5]
  22:	2301      	movs	r3, #1
  24:	71fb      	strb	r3, [r7, #7]
  26:	2301      	movs	r3, #1
  28:	71bb      	strb	r3, [r7, #6]
  2a:	1d3b      	adds	r3, r7, #4
  2c:	4618      	mov	r0, r3
  2e:	f7ff fffe 	bl	0 <LedInit>
  32:	68bb      	ldr	r3, [r7, #8]
  34:	1d3a      	adds	r2, r7, #4
  36:	4610      	mov	r0, r2
  38:	4798      	blx	r3
  3a:	f44f 707a 	mov.w	r0, #1000	; 0x3e8
  3e:	f7ff fffe 	bl	0 <TaskWait>
  42:	68fb      	ldr	r3, [r7, #12]
  44:	1d3a      	adds	r2, r7, #4
  46:	4610      	mov	r0, r2
  48:	4798      	blx	r3
  4a:	f44f 707a 	mov.w	r0, #1000	; 0x3e8
  4e:	f7ff fffe 	bl	0 <TaskWait>
  52:	e7ee      	b.n	32 <Task1Handler+0x1e>

00000054 <Task2Handler>:
  54:	b580      	push	{r7, lr}
  56:	b084      	sub	sp, #16
  58:	af00      	add	r7, sp, #0
  5a:	2306      	movs	r3, #6
  5c:	713b      	strb	r3, [r7, #4]
  5e:	230e      	movs	r3, #14
  60:	717b      	strb	r3, [r7, #5]
  62:	2301      	movs	r3, #1
  64:	71fb      	strb	r3, [r7, #7]
  66:	2301      	movs	r3, #1
  68:	71bb      	strb	r3, [r7, #6]
  6a:	1d3b      	adds	r3, r7, #4
  6c:	4618      	mov	r0, r3
  6e:	f7ff fffe 	bl	0 <LedInit>
  72:	68bb      	ldr	r3, [r7, #8]
  74:	1d3a      	adds	r2, r7, #4
  76:	4610      	mov	r0, r2
  78:	4798      	blx	r3
  7a:	f44f 70fa 	mov.w	r0, #500	; 0x1f4
  7e:	f7ff fffe 	bl	0 <TaskWait>
  82:	68fb      	ldr	r3, [r7, #12]
  84:	1d3a      	adds	r2, r7, #4
  86:	4610      	mov	r0, r2
  88:	4798      	blx	r3
  8a:	f44f 70fa 	mov.w	r0, #500	; 0x1f4
  8e:	f7ff fffe 	bl	0 <TaskWait>
  92:	e7ee      	b.n	72 <Task2Handler+0x1e>

00000094 <Task3Handler>:
  94:	b480      	push	{r7}
  96:	af00      	add	r7, sp, #0
  98:	e7fe      	b.n	98 <Task3Handler+0x4>

0000009a <Task4Handler>:
  9a:	b480      	push	{r7}
  9c:	af00      	add	r7, sp, #0
  9e:	e7fe      	b.n	9e <Task4Handler+0x4>

000000a0 <IdleHandler>:
  a0:	b480      	push	{r7}
  a2:	af00      	add	r7, sp, #0
  a4:	e7fe      	b.n	a4 <IdleHandler+0x4>

000000a6 <HardFault_Handler>:
  a6:	b480      	push	{r7}
  a8:	af00      	add	r7, sp, #0
  aa:	e7fe      	b.n	aa <HardFault_Handler+0x4>

000000ac <UsageFault_Handler>:
  ac:	b480      	push	{r7}
  ae:	af00      	add	r7, sp, #0
  b0:	e7fe      	b.n	b0 <UsageFault_Handler+0x4>

000000b2 <MemManage_Handler>:
  b2:	b480      	push	{r7}
  b4:	af00      	add	r7, sp, #0
  b6:	e7fe      	b.n	b6 <MemManage_Handler+0x4>

000000b8 <BusFault_Handler>:
  b8:	b480      	push	{r7}
  ba:	af00      	add	r7, sp, #0
  bc:	e7fe      	b.n	bc <BusFault_Handler+0x4>
  be:	bf00      	nop
