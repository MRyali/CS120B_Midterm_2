
//define local variable(s) here.  Use static keyword to keep local, e.g:
//   static int i;  // defines a local int named i
unsigned char max = 0x00;

/* complete the state machine. */
unsigned char motionAmplitudeVal;

void Detect_Max_Amp()
{
    switch(detect_max_amp_state)
    {
        case DMAInit:
            detect_max_amp_state = detectMax;
            break;
        case detectMax:
            motionAmplitudeVal = motionAmplitude;
            motionAmplitudeVal = motionAmplitudeVal >> 3;
            if (motionAmplitudeVal > 0) {
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
            break;
        default:
            break;
    }
}
