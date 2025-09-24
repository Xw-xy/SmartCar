#ifndef FREERTOS_CONFIG_H
#define FREERTOS_CONFIG_H

/* Ӳ��������� */
#define configCPU_CLOCK_HZ			( 170000000 )  // STM32G431��Ƶ170MHz
//#define configSYSTICK_CLOCK_HZ		configCPU_CLOCK_HZ  // Systickʱ��Ƶ��

/* FreeRTOS�ں����� */
#define configUSE_PREEMPTION			1
#define configUSE_IDLE_HOOK				0
#define configUSE_TICK_HOOK				0
#define configTICK_RATE_HZ				( ( TickType_t ) 1000 )
#define configMAX_PRIORITIES			( 5 )
#define configMINIMAL_STACK_SIZE		( ( unsigned short ) 128 )
#define configTOTAL_HEAP_SIZE			( ( size_t ) ( 20 * 1024 ) )  // 20KB�ѿռ�
#define configMAX_TASK_NAME_LEN			( 10 )
#define configUSE_TRACE_FACILITY		0
#define configUSE_16_BIT_TICKS			0
#define configIDLE_SHOULD_YIELD			1
#define configUSE_MUTEXES				1
#define configUSE_RECURSIVE_MUTEXES		1
#define configUSE_COUNTING_SEMAPHORES	1
#define configUSE_ALTERNATIVE_API		0
#define configCHECK_FOR_STACK_OVERFLOW	2
#define configQUEUE_REGISTRY_SIZE		0
#define configUSE_QUEUE_SETS			1
#define configUSE_TIME_SLICING			1
#define configUSE_NEWLIB_REENTRANT		0
#define configENABLE_BACKWARD_COMPATIBILITY 0

/* �ڴ������� */
#define configSUPPORT_STATIC_ALLOCATION         0
#define configSUPPORT_DYNAMIC_ALLOCATION        1
#define configAPPLICATION_ALLOCATED_HEAP        0

/* ���Ӻ������ */
#define configUSE_IDLE_HOOK				0
#define configUSE_TICK_HOOK				0
#define configUSE_MALLOC_FAILED_HOOK	1
#define configUSE_DAEMON_TASK_STARTUP_HOOK 0

/* �����ʱ����� */
#define configUSE_TIMERS				1
#define configTIMER_TASK_PRIORITY		( 3 )
#define configTIMER_QUEUE_LENGTH		( 5 )
#define configTIMER_TASK_STACK_DEPTH	( configMINIMAL_STACK_SIZE * 2 )

/* Э����� */
#define configUSE_CO_ROUTINES 			0
#define configMAX_CO_ROUTINE_PRIORITIES ( 2 )

/* ����֪ͨ��� */
#define configUSE_TASK_NOTIFICATIONS    1
#define configTASK_NOTIFICATION_ARRAY_ENTRIES 3

/* �ж����ȼ����� - Cortex-M�ض� */
#ifdef __NVIC_PRIO_BITS
	#define configPRIO_BITS       		__NVIC_PRIO_BITS
#else
	#define configPRIO_BITS       		4
#endif

#define configLIBRARY_LOWEST_INTERRUPT_PRIORITY			15
#define configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY	5
#define configKERNEL_INTERRUPT_PRIORITY 		( configLIBRARY_LOWEST_INTERRUPT_PRIORITY << (8 - configPRIO_BITS) )
#define configMAX_SYSCALL_INTERRUPT_PRIORITY 	( configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY << (8 - configPRIO_BITS) )

#define configASSERT( x ) if( ( x ) == 0 ) { taskDISABLE_INTERRUPTS(); for( ;; ); }

/* ����FreeRTOSͷ�ļ� */
#include <stdint.h>
extern uint32_t SystemCoreClock;
#define xPortSysTickHandler SysTick_Handler
#define vPortSVCHandler SVC_Handler
#define xPortPendSVHandler PendSV_Handler
#define INCLUDE_vTaskDelay   1
#define INCLUDE_vTaskDelayUntil 1
#endif /* FREERTOS_CONFIG_H */