#include <stdio.h>
#include <stdint.h>

//Typical Structure of Playstation 3 Dualshock Controller
//Byte:		1	2	3	4	5	6	7	8	9	10
//Field:	1	0	bitmap1	bitmap2	connect	0	horLJS	vertLJS	horRJS	vertRJS

//Byte:		11	12	13	14	15	16	17	18	19	20
//Field:	0	0	0	0	up	right	down	left	L2	R2

//Byte:		21	22	23	24	25	26	27	28	29	30
//Field:	L1	R1	tiangle	circle	x	square	0	0	0	3

//Byte:		31	32	33	34	35	36	37	38	39	40
//Field:	239	22	0	0	0	0	51	0	119	0

//Byte:		41	42	43	44	45	46	47	48	49
//Field:	94	xaccel	xdir	yaccel	ydir	zaccel	zdir	gyro?	0



//Bitmap1:	1	2	4	8	16	32	64	128
//Button:	select	LJSdown	RJSdown	start	up	right	down	left

//Bitmap2:	1	2	4	8	16	32	64	128
//Button:	L2	R2	L1	R1	tri	circle	x	square

 
struct controller {
	uint8_t buttonBitmap1; // 3
        uint8_t buttonBitmap2; // 4
        uint8_t connectButton; // 5
        uint8_t horizLeftStick; //7
        uint8_t vertLeftStick; // 8
        uint8_t horizRightStick; // 9
        uint8_t vertRightStick; // 10
        uint8_t upButton; // 15
        uint8_t rightButton; // 16
        uint8_t downButton; // 17
        uint8_t leftButton; // 18
        uint8_t L2; // 19
        uint8_t R2; // 20
        uint8_t L1; // 21
        uint8_t R1; // 22
        uint8_t triangle; // 23
        uint8_t circle; // 24
        uint8_t x; // 25
        uint8_t square; // 26
        uint8_t accelX; // 42
        uint8_t accelY; // 44
        uint8_t accelZ; // 46
        uint8_t gyro; // 48       
};

void setController(struct controller *ct,
	uint8_t buttonBitmap1,
        uint8_t buttonBitmap2,
        uint8_t connectButton,
        uint8_t horizLeftStick,
        uint8_t vertLeftStick,
        uint8_t horizRightStick,
        uint8_t vertRightStick,
        uint8_t upButton,
        uint8_t rightButton,
        uint8_t downButton,
        uint8_t leftButton,
        uint8_t L2,
        uint8_t R2,
        uint8_t L1,
        uint8_t R1,
        uint8_t triangle,
        uint8_t circle,
        uint8_t x,
        uint8_t square,
        uint8_t accelX,
        uint8_t accelY,
        uint8_t accelZ,
        uint8_t gyro) {

ct->buttonBitmap1 = buttonBitmap1;
ct->buttonBitmap2 = buttonBitmap2;
ct->connectButton = connectButton;
ct->horizLeftStick = horizLeftStick;
ct->vertLeftStick = vertLeftStick;
ct->horizRightStick = horizRightStick;
ct->vertRightStick = vertRightStick;
ct->upButton = upButton;
ct->rightButton = rightButton;
ct->downButton = downButton;
ct->leftButton = leftButton;
ct->L2 = L2;
ct->R2 = R2;
ct->L1 = L1;
ct->R1 = R1;
ct->triangle = triangle;
ct->circle = circle;
ct->x = x;
ct->square = square;
ct->accelX = accelX;
ct->accelY = accelY;
ct->accelZ = accelZ;
ct->gyro = gyro;
}

int main( void )
{
        FILE *fp;
        uint8_t buff[49];
	struct controller my_controller;
        fp = fopen("/dev/hidraw1", "r");
	fread(buff, 49, 1, fp);
	//my_controller = {
	//	buff[3],buff[4],buff[5],buff[7],buff[8],buff[9],buff[10],
	//	buff[15],buff[16],buff[17],buff[18],buff[19],buff[20],buff[21],buff[22],buff[23],
	//	buff[24],buff[25],buff[26],buff[42],buff[44],buff[46],buff[48]
	//};
	//for (int n=0;n<40;n++) {
	while (1) {
		fread(buff,49,1,fp);
		setController(&my_controller,buff[3-1],buff[4-1],buff[5-1],buff[7-1],buff[8-1],buff[9-1],buff[10-1],
                buff[15-1],buff[16-1],buff[17-1],buff[18-1],buff[19-1],buff[20-1],buff[21-1],buff[22-1],buff[23-1],
                buff[24-1],buff[25-1],buff[26-1],buff[42-1],buff[44-1],buff[46-1],buff[48-1]);
		printf("%3u \n",my_controller.upButton);
		//for (int i=0;i<49;i++) {	
			//printf("%x", buff[i+n*49] );
			//printf("%3u ",my_controller.L2);
		//}
		//printf("\n");
	}
	printf("\n");
	fclose(fp);
}


