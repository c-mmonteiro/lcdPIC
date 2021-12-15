/*
 LCD Library
 Autor: Carlos Monteiro
 carlos.monteiro@ifc.edu.br
 11/2020 - IFC - Blumenau
 */

#define FCY 8000000UL

#include <xc.h>
#include <libpic30.h>


//#define _XTAL_FREQ 8000000

#define DB7_PORT		PORTDbits.RD5
#define	DB6_PORT    	PORTDbits.RD6
#define DB5_PORT		PORTDbits.RD7
#define	DB4_PORT		PORTDbits.RD8

#define	ENABLE_PORT		PORTDbits.RD9 
#define	RS_PORT		   	PORTDbits.RD12   
   

#define DB7_TRIS  		TRISDbits.TRISD5
#define DB6_TRIS  		TRISDbits.TRISD6
#define DB5_TRIS  		TRISDbits.TRISD7
#define DB4_TRIS		TRISDbits.TRISD8

#define ENABLE_TRIS		TRISDbits.TRISD9  
#define RS_TRIS  		TRISDbits.TRISD12

//Funções

#define lcd_linha1()    write_8bit_command(0x80) //Endereço 0x00 + bit para config o addr 0x80
#define lcd_linha2()    write_8bit_command(0xC0) //Endereço 0x40 + bit para config o addr 0x80     


void lcd_inicializa(void);
void lcd_escreveString(char* mensagem);
void lcd_clear(void);

//Internos
void pulsaEnable(void);
void write_4bit_command(unsigned char dado);
void write_8bit(unsigned char dado);
void write_8bit_command(unsigned char value);
void write_msg(unsigned char value);


