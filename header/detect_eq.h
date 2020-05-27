//define local variable(s) here.  Use static keyword to keep local, e.g:
//   static int i;  // defines a local int named i
unsigned char eqDetection = 0x00;
unsigned char amp = motionAmplitude;
unsigned char detected = 0x00;


/*complete the state machine*/

void Detect_EQ()
{
    switch(detect_eq_state)
    {
        case DEQInit:
            detect_eq_state = detectEq;
            break;
        case detectEq:
            amp = motionAmplitude;
            amp = amp >> 3;
            if (amp > 0) {
                detect_eq_state = posDetection;
            }
            else {
                detect_eq_state = noDetection;
            }
            break;
        case posDetection:
            detect_eq_state = detectEq;
            break;
        case noDetection:
            detect_eq_state = detectEq;
            break;
        default:
            detect_eq_state = DEQInit;
            break;
    }
    switch(detect_eq_state)
    {
        case DEQInit:
            break;
        case detectEq:
            break;
        case posDetection:
            detected = 0x02;
            break;
        case noDetection:
            detected = 0x00;
            break;
        default:
            break;
    }
}
