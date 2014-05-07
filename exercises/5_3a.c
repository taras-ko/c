// задание 5.3, таймеры динамические.
#include <linux/init.h>
#include <linux/module.h>
#include <linux/jiffies.h>
#include <linux/timer.h>
#include <linux/slab.h>
MODULE_LICENSE("Dual BSD/GPL");

static void message(unsigned long);
static void selfmod(unsigned long);

struct timer_list *t, *periodic_t;

static void add(void)
{
	/*выделение памяти, инициализация one_shot таймера*/
	t = kmalloc(sizeof(* t), GFP_KERNEL);
	init_timer(t);
		t -> function = message; //вызывает функцию, которая запускает периодический таймер
		t -> expires = 0;
		t -> data = 0;

	printk(KERN_ALERT "adding oneshot timer\n");

	t ->expires = jiffies + msecs_to_jiffies(1000);
	add_timer(t);
}

//запуск периодического таймера
static void message(unsigned long data)
{
	/* выделение памяти, инициализация периодического таймера */
	periodic_t = kmalloc(sizeof(*periodic_t), GFP_KERNEL);
	init_timer(periodic_t);
		periodic_t->function = selfmod;
		periodic_t->expires = 0;
		periodic_t->data = 0;

	printk(KERN_ALERT "Launching 1Hz timer\n");

	periodic_t->expires = jiffies + msecs_to_jiffies(1000);
	add_timer(periodic_t);
}

//зацилкивание периодического таймера
static void selfmod(unsigned long data)
{
	printk(KERN_ALERT "tick...\n");
	mod_timer(periodic_t, jiffies + msecs_to_jiffies(1000));
}

//удаление таймеров
static void del(void)
{
	printk(KERN_ALERT "del_timers\n");
	del_timer(t);
	del_timer(periodic_t);
}

module_init(add);
module_exit(del);
