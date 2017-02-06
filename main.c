/* * * * * * * * * * * * * * *
 * 2017/1/31(火)              *
 * * * * * * * * * * * * * * */

#include <stdlib.h>

#include <xc.h>
#include "config.h"

#include "u_chi_ha_ra_7seg.h"
#include "u_chi_ha_ra_LED.h"

#define _XTAL_FREQ 20000000 //delay 20[MHz]


int get_rand() {
    return 0 + (int)(rand() * (9 - 0 + 1.0) / (1.0 + RAND_MAX));
}

void main(void) 
{   
    int right, left; //7segで表示する値
    int cnt = 0;  //正解カウント用の変数
    int frag_SW2 = 0, frag_SW3 = 0; //タクトスイッチが押されているかのフラグ
    
     //7seg LED コモン
    TRISA2 = 0; //出力に設定
    TRISA3 = 0;
    
    //LED
    TRISD = 0x00;
    
    //7seg
    TRISB = 0x00;

            //タクトスイッチ
    TRISC0 = 1; //入力に設定
    TRISC1 = 1;
   
    init_LED();    

    while (1) {
        if (RC1 == 0 && RC0 == 1) { //SW3押されたか(右)
            frag_SW3 = 1;
        }
        else if (RC0 == 0 && RC1 == 1) { //SW2押されたか(左)
            frag_SW2 = 1;
        }
        else if (frag_SW2 == 1 && frag_SW3 == 1) { //両方押されたら
            if (right == left) {  //right == left だったら
                cnt += 1;
                lit_LED(cnt % 9);
                frag_SW2 = 0;
                frag_SW3 = 0;  
            }
            else { //間違いだったら
                frag_SW2 = 0;
                frag_SW3 = 0;     
            }
        }
    
        right = frag_SW2 == 1 ? right : get_rand();
        left  = frag_SW3 == 1 ? left : get_rand();
        
        light_init();
        
        light_right(1);
        lit(right);
        __delay_ms(4);
        dark();
        light_right(0);
        
        light_left(1);
        lit(left);
        __delay_ms(4);
        dark();
        light_right(0);
    }
}
