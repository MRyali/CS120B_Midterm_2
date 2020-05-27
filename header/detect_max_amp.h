
//define local variable(s) here.  Use static keyword to keep local, e.g:
//   static int i;  // defines a local int named i
static unsigned char max = 0x00;

/* complete the state machine. */
unsigned char motionAmplitudeVal = motionAmplitude >> 3;

void Detect_Max_Amp()
{
    switch(detect_max_amp_state)
    {
        case DMAInit:
            detect_max_amp_state = detectMax;
            break;
        case detectMax:
            if (motionAmplitude) {
                detect_max_amp_state = maxCheck;
            }
            else {
                detect_max_amp_state = detectMax;
            }
            break;
        case maxCheck:
            detect_max_amp_state = detectMax;
            break;
        default:
            break;
    }
    switch(detect_max_amp_state)
    {
        case DMAInit:
            break;
        case detectMax:
            break;
        case maxCheck:
            if (motionAmplitudeVal > max) {
                max = motionAmplitudeVal;
            }
            PORTB = PORTB | (max << 3)
            break;
        default:
            break;
    }
}
