// задание 5.3, статические таймеры.
#include <linux/init.h>
#include <linux/module.h>
#include <linux/jiffies.h>
#include <linux/timer.h>
MODULE_LICENSE("Dual BSD/GPL");

static void message(unsigned long);
static void selfmod(unsigned long);

// инициализация статических таймеров
static struct timer_list my_t = TIMER_INITIALIZER(message, 5000, 0); 
static struct timer_list periodic_t = TIMER_INITIALIZER(selfmod, 5000, 0); 

// добавление one_shot таймера
static void add(void)
{
	printk(KERN_ALERT "adding oneshot timer\n");

	my_t.expires = jiffies + msecs_to_jiffies(5000);
	add_timer(&my_t);
}

// функция вызываемая one_shot таймером, которая запускает периодический таймер	
static void message(unsigned long data)
{
	printk(KERN_ALERT "Launching 1Hz timer\n");
	
	periodic_t.expires = jiffies + msecs_to_jiffies(1000);
	add_timer(&periodic_t);
}

// зацикливание периодического таймера 
static void selfmod(unsigned long data)
{
	printk(KERN_ALERT "tick...\n");
	mod_timer(&periodic_t, jiffies + msecs_to_jiffies(1000));
}

// удаление таймеров
static void del(void)
{
	printk(KERN_ALERT "del_timers\n");
	del_timer(&my_t);
	del_timer(&periodic_t);
}

module_init(add);
module_exit(del);
