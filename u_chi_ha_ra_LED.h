/*
*  encoding:utf-8
*  created by u_chi_ha_ra_@ic151206
*  
*  init_LED(); 呼び出すとLEDが全部消える.
*  lit_LED(n); nに光らせたい場所の数字を入れると光ります.
*  kieru_LED(n); nに消したい場所の数字を入れるとそこが消えます. 1~8以外を入れると全部消えます.
*/

void init_LED(void) {
    LATD0 = 1; //消える
    LATD1 = 1;
    LATD2 = 1;
    LATD3 = 1;
    LATD4 = 1;
    LATD5 = 1;
    LATD6 = 1;
    LATD7 = 1;
}

void lit_LED(const int n) {
    switch(n) {
        case 1:
            LATD0 = 0;
            break;
        case 2:
            LATD1 = 0;
            break;
        case 3:
            LATD2 = 0;
            break;
        case 4:
            LATD3 = 0;
            break;
        case 5:
            LATD4 = 0;
            break;
        case 6:
            LATD5 = 0;
            break;
        case 7:
            LATD6 = 0;
            break;
        case 8:
            LATD7 = 0;
            break;
        default:
            init_LED();
    }
}

void kieru_LED(const int n) { //動作未確認
    switch(n) {
        case 1:
            LATD0 = 1;
            break;
        case 2:
            LATD1 = 1;
            break;
        case 3:
            LATD2 = 1;
            break;
        case 4:
            LATD3 = 1;
            break;
        case 5:
            LATD4 = 1;
            break;
        case 6:
            LATD5 = 1;
            break;
        case 7:
            LATD6 = 1;
            break;
        case 8:
            LATD7 = 1;
            break;
        default:
            init_LED();
    }
}
