; ASM for STM32F031K6 MCU bootstrapping.

; Attributes.
.syntax unified
.cpu cortex-m0
.fpu softvfp
.thumb

; Global memory locations.
.global vtable
.global reset_handler


; Vector table.
.type vtable, %object
vtable:
	.word _estack
	.word reset_handler
.size vtable, .-vtable


; Reset handler.
.type reset_handler, %function
reset_handler:
	;
.size reset_handler, .-reset_handler
