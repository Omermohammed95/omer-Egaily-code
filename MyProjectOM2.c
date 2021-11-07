void main() {

int L;

ANSELA=0xFF;
ANSELC =0;
ANSELD=0;
ANSELB = 0;
TRISA=0xFF;
TRISD=0;
TRISB=0;

UART1_Init(9600);

Delay_ms(100);
while(1){
L =ADC_Read(1);
if (L >= 2000)
{
PORTD=0b11111111;
Delay_ms(2000);
UART1_Write(L);
UART1_Write_Text("High Light Intensity");
UART1_Write(13);
UART1_Write(10);
}

else if (L <= 1000)
{
PORTD=0b10101010;
Delay_ms(2000);
UART1_Write(L);
UART1_Write_Text("Moderate Ligth intensity");
UART1_Write(13);
UART1_Write(10);
}
else if (L < 1000 ){
PORTD=0x00;
UART1_Write(L);
UART1_Write_Text("No Light Intensity");
UART1_Write(13);
UART1_Write(10);
}
}
}