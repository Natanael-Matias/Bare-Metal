
obj\main.o:     file format elf32-littlearm


Disassembly of section .text:

00000000 <main>:
   0:	b580      	push	{r7, lr}
   2:	af00      	add	r7, sp, #0
   4:	4802      	ldr	r0, [pc, #8]	; (10 <main+0x10>)
   6:	f7ff fffe 	bl	0 <AppInit>
   a:	f7ff fffe 	bl	0 <AppStart>
   e:	e7fe      	b.n	e <main+0xe>
  10:	00000000 	andeq	r0, r0, r0

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

Disassembly of section .data:

00000000 <tasks>:
   0:	20020000 	andcs	r0, r2, r0
	...
  10:	2001fc00 	andcs	pc, r1, r0, lsl #24
	...
  20:	2001f000 	andcs	pc, r1, r0
	...

Disassembly of section .comment:

00000000 <.comment>:
   0:	43434700 	movtmi	r4, #14080	; 0x3700
   4:	4728203a 			; <UNDEFINED> instruction: 0x4728203a
   8:	4120554e 			; <UNDEFINED> instruction: 0x4120554e
   c:	45206d72 	strmi	r6, [r0, #-3442]!	; 0xfffff28e
  10:	6465626d 	strbtvs	r6, [r5], #-621	; 0xfffffd93
  14:	20646564 	rsbcs	r6, r4, r4, ror #10
  18:	6c6f6f54 	stclvs	15, cr6, [pc], #-336	; fffffed0 <BusFault_Handler+0xfffffe18>
  1c:	69616863 	stmdbvs	r1!, {r0, r1, r5, r6, fp, sp, lr}^
  20:	3031206e 	eorscc	r2, r1, lr, rrx
  24:	322d332e 	eorcc	r3, sp, #-1207959552	; 0xb8000000
  28:	2e313230 	mrccs	2, 1, r3, cr1, cr0, {1}
  2c:	20293031 	eorcs	r3, r9, r1, lsr r0
  30:	332e3031 			; <UNDEFINED> instruction: 0x332e3031
  34:	3220312e 	eorcc	r3, r0, #-2147483637	; 0x8000000b
  38:	30313230 	eorscc	r3, r1, r0, lsr r2
  3c:	20343238 	eorscs	r3, r4, r8, lsr r2
  40:	6c657228 	sfmvs	f7, 2, [r5], #-160	; 0xffffff60
  44:	65736165 	ldrbvs	r6, [r3, #-357]!	; 0xfffffe9b
  48:	Address 0x00000048 is out of bounds.


Disassembly of section .ARM.attributes:

00000000 <.ARM.attributes>:
   0:	00002d41 	andeq	r2, r0, r1, asr #26
   4:	61656100 	cmnvs	r5, r0, lsl #2
   8:	01006962 	tsteq	r0, r2, ror #18
   c:	00000023 	andeq	r0, r0, r3, lsr #32
  10:	2d453705 	stclcs	7, cr3, [r5, #-20]	; 0xffffffec
  14:	0d06004d 	stceq	0, cr0, [r6, #-308]	; 0xfffffecc
  18:	02094d07 	andeq	r4, r9, #448	; 0x1c0
  1c:	01140412 	tsteq	r4, r2, lsl r4
  20:	03170115 	tsteq	r7, #1073741829	; 0x40000005
  24:	01190118 	tsteq	r9, r8, lsl r1
  28:	061e011a 			; <UNDEFINED> instruction: 0x061e011a
  2c:	Address 0x0000002c is out of bounds.

