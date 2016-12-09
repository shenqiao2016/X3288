#define AGS04_NAME	"ags04"
#define MAX_KEY_CNT     (4)



struct ags04_key_table{
    	int scanCode;
	int keyCode;		
};

struct ags04_key_table    ags04_key_table_tc[4] = {
	{ 0x01, KEY_HOME },
	{ 0x02, KEY_MENU },
	{ 0x04, KEY_BACK },
	{ 0x08, KEY_MUTE },	
};

struct ags04_data {
	int irq_pin;
	int irq;
	
	char device_id;
	struct i2c_client *client;
	struct input_dev *input_dev;
	//struct ts_event event;
	
	struct work_struct 	pen_event_work;
	struct workqueue_struct *ts_workqueue;
	#ifdef CONFIG_PM
	struct early_suspend *early_suspend;
	#endif
};

static int KeyCode[5]={KEY_1, KEY_2, KEY_4 ,KEY_8, KEY_0};

static int ags04_iic_readbyte(struct i2c_client *client, u8 addr, u8 *pdata);
static int ags04_iic_read(struct i2c_client *client, u8 addr, u8 *pdata, unsigned int datalen);
static int ags04_iic_write(struct i2c_client *client, u8 addr, u8 *pdata, int datalen);
