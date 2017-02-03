/*
*  encoding:utf-8
*  7セグメントLEDを光らすための関数たち
*
*  created by ic151206@u_chi_ha_ra_
*
*
*  lit(n); nの部分に光らせたい場所の番号を入れると光ります.
*  derk(); 7segを消します.
*  light_init(); 二つのトランジスタをオフ(?)にします,
*  light_right(n);  引数に0を渡すと右の7segが光らなくなり1を渡すと光るようになります.
*  light_left(n); 上と同じ.
*
*/


void seg7_1(void){
    LATB2 = 1;
    LATB3 = 1;
}

void seg7_2(void) {
    LATB1 = 1;
    LATB2 = 1;
    LATB4 = 1;
    LATB5 = 1;
    LATB7 = 1;
}

void seg7_3(void) {
    LATB1 = 1;
    LATB2 = 1;
    LATB3 = 1;
    LATB4 = 1;
    LATB7 = 1;
}

void seg7_4(void) {
    LATB2 = 1;
    LATB3 = 1;
    LATB6 = 1;
    LATB7 = 1;
}

void seg7_5(void) {
    LATB1 = 1;
    LATB3 = 1;
    LATB4 = 1;
    LATB6 = 1;
    LATB7 = 1;
}

void seg7_6(void) {
    LATB1 = 1;
    LATB3 = 1;
    LATB4 = 1;
    LATB5 = 1;
    LATB6 = 1;
    LATB7 = 1;
}

void seg7_7(void) {
    LATB1 = 1;
    LATB2 = 1;
    LATB3 = 1;
}

void seg7_8(void) {
    LATB1 = 1;
    LATB2 = 1;
    LATB3 = 1;
    LATB4 = 1;
    LATB5 = 1;
    LATB6 = 1;
    LATB7 = 1;
}

void seg7_9(void) {
    LATB1 = 1;
    LATB2 = 1;
    LATB3 = 1;
    LATB4 = 1;
    LATB6 = 1;
    LATB7 = 1;
}

void seg7_0(void) {
    LATB1 = 1;
    LATB2 = 1;
    LATB3 = 1;
    LATB4 = 1;
    LATB5 = 1;
    LATB6 = 1;
}

void light_right(const int a) {
    LATA2 = a;
}

void light_left(const int a) {
    LATA3 = a;
}

void dark(void) { 
    LATB1 = 0;
    LATB2 = 0;
    LATB3 = 0;
    LATB4 = 0;
    LATB5 = 0;
    LATB6 = 0;
    LATB7 = 0;
}

void lit(const int n) {
    switch(n) {
        case 0:
            seg7_0();
            break;
        case 1:
            seg7_1();
            break;
        case 2:
            seg7_2();
            break;
        case 3:
            seg7_3();
            break;
        case 4:
            seg7_4();
            break;
        case 5:
            seg7_5();
            break;
        case 6:
            seg7_6();
            break;
        case 7:
            seg7_7();
            break;
        case 8:
            seg7_8();
            break;
        case 9:
            seg7_9();
            break;
        default:
            dark(); 
    } 
}

void light_init(void) {
    light_right(0);
    light_left(0);
    dark();
}
