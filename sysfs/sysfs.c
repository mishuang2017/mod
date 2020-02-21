#include <linux/init.h>  //包含module_init和module_exit头文件
#include <linux/module.h>
#include <linux/device.h>    //包含device相关定义
#include <linux/kdev_t.h>    //MKDEV

#define dbxiong_major   50
#define dbxiong_minor 8

unsigned char kernel_space_state = 0x01;

MODULE_LICENSE("GPL");


//读取状态信息
static ssize_t dbxiong_show(struct device *dev, struct device_attribute *attr,
                        char *buf)
{
return sprintf(buf,"get_kernel_space_state:%d\n",kernel_space_state);                        
}

//设置
static ssize_t dbxiong_store(struct device *dev, struct device_attribute *attr,
                         const char *buf, size_t count)
{
	kernel_space_state = *buf - 0x30; //0的ASCII码为0x30
	printk("%s:---test\n",__func__);
	/*you can add you want function 
	for example
	switch(kernel_space_state)
	{
	case 1:
	//I2C发送数据
	break;
	case 2:
	//UART发送数据
	break;
	...(所有内核中能操作的动作都可以添加到这里)
	}
	*/
	return count;
}
//填充attr结构体              
static DEVICE_ATTR(dbxiong_device_attr, S_IWUSR | S_IRUGO, dbxiong_show, dbxiong_store);   

static int device_init(void)
{
	struct device *dbxiong_dev;
	dev_t dbxiong_devt = MKDEV(dbxiong_major,dbxiong_minor);//创建设备号
	struct class *dbxiong_class;

	//创建类
	dbxiong_class = class_create(THIS_MODULE,"dbxiong_class");
	//创建devices
	dbxiong_dev = device_create(dbxiong_class,NULL,dbxiong_devt,"dbxiong_drvdata","dbxiong");
	//所有的操作都是为了填充这个接口
	device_create_file(dbxiong_dev,&dev_attr_dbxiong_device_attr);
	return 0;
}

static void device_exit(void)
{
return ;
}

module_init(device_init);
module_exit(device_exit);
