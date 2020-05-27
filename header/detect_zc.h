
//define local variable(s) here.  Use static keyword to keep local, e.g:
//   static int i;  // defines a local int named i
int run = 0;
unsigned char motion;
unsigned char temp = motion;
unsigned char difference = 0x04;
int zc = 0;
unsigned char zcVal = 0x00;

/*complete the state machine*/

void Detect_ZC()
{
    switch(detect_zc_state)
    {
        case DZCInit:
            detect_zc_state = run;
            break;
        case run:
            motion = motionDirection;
            if (run < 2 && (motion == temp + difference)) {
                zc++; //counts consecutive times
                if (zc == 2) {
                    detect_zc_state = posZC;
                }
            }
            else {
                run = 0;
                zc = 0;
                detect_zc_state = run;
            }
            run++; //counts which run it is
            detect_zc_state = run;
            break;
        case posZC:
            detect_zc_state = run;
            break;
        default:
            detect_zc_state = DZCInit;
            break;
    }
    switch(detect_zc_state)
    {
        case DZCInit:
            break;
        case run:
            zcVal = 0x00;
            break;
        case posZC:
            zcVal = 0x04;
            break;
        default:
            break;
    }
}
