#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
 .name = KBUILD_MODNAME,
 .init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
 .exit = cleanup_module,
#endif
 .arch = MODULE_ARCH_INIT,
};

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0x74679a8f, "module_layout" },
	{ 0xeac5abd5, "cdev_alloc" },
	{ 0x3a9f40a9, "cdev_del" },
	{ 0xf49d5905, "cdev_init" },
	{ 0x363e731f, "device_destroy" },
	{ 0x7485e15e, "unregister_chrdev_region" },
	{ 0xb72397d5, "printk" },
	{ 0xb4390f9a, "mcount" },
	{ 0xb457a6fd, "device_create" },
	{ 0xbfa2ee2e, "cdev_add" },
	{ 0xcff6d41c, "class_destroy" },
	{ 0x55ca06d9, "__class_create" },
	{ 0x29537c9e, "alloc_chrdev_region" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "938A1B93EAB6026170EC40B");
