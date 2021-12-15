/*
 LCD Library
 Autor: Carlos Monteiro
 carlos.monteiro@ifc.edu.br
 11/2020 - IFC - Blumenau
 */

#include "lcd.h"


void pulsaEnable()
{
	ENABLE_PORT = 0;
    __delay_us(5);
	ENABLE_PORT = 1;
	__delay_us(50);
	ENABLE_PORT = 0;
	__delay_us(50);	
}

void write_4bit_command(unsigned char dado){
    RS_PORT = 0;
    DB7_PORT = (unsigned char)((dado & 0x08)>>3);	//ACERTA DADO
    DB6_PORT = (unsigned char)((dado & 0x04)>>2);	//NO BARRAMENTO
    DB5_PORT = (unsigned char)((dado & 0x02)>>1);
    DB4_PORT = (unsigned char)(dado & 0x01);

    pulsaEnable();
}


void write_8bit(unsigned char dado){
    
    DB7_PORT = (unsigned char)((dado & 0x80)>>7);	//ACERTA DADO
    DB6_PORT = (unsigned char)((dado & 0x40)>>6);	//NO BARRAMENTO
    DB5_PORT = (unsigned char)((dado & 0x20)>>5);
    DB4_PORT = (unsigned char)((dado & 0x10)>>4);

	pulsaEnable();

    DB7_PORT = (unsigned char)((dado & 0x08)>>3);	//ACERTA DADO
    DB6_PORT = (unsigned char)((dado & 0x04)>>2);	//NO BARRAMENTO
    DB5_PORT = (unsigned char)((dado & 0x02)>>1);
    DB4_PORT = (unsigned char)(dado & 0x01);

   pulsaEnable();	
	__delay_us(50);	
}

void write_8bit_command(unsigned char value){
    RS_PORT = 0;
    write_8bit(value);
}

void write_msg(unsigned char value){
    RS_PORT = 1;
    write_8bit(value);
}

void lcd_escreveString(char* mensagem)
{
   for (;*mensagem != '\0';mensagem++) write_msg(*mensagem);
}

void lcd_clear(void){
    write_8bit_command(0x01);
    __delay_ms(2);
}

void lcd_inicializa()	
{
	__delay_ms(100); 
	
	
	ENABLE_TRIS = 0;
	RS_TRIS = 0;
	DB7_TRIS = 0;
	DB6_TRIS = 0;
    DB5_TRIS = 0;
    DB4_TRIS = 0;

	
	write_4bit_command(0x03);
    __delay_ms(5);
    write_4bit_command(0x03);
    __delay_us(150);
    write_4bit_command(0x03);
    write_4bit_command(0x02);

    write_8bit_command(0x2B); //2 linhas ; 5x8
    //write_8bit_command(0x2C); //2 linhas ; 5x10
    
    write_8bit_command(0x0C); //Liga o display; 
    write_8bit_command(0x01);//Limpa o display
    __delay_ms(2);
    write_8bit_command(0x06); //Configura escrita;incremento

}	
	
