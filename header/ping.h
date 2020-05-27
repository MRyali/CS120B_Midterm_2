//define local variable(s) here.  Use static keyword to keep local, e.g:
//   static int i;  // defines a local int named i


unsigned char pingVal = 0x00;

/*complete the state machine*/

void Ping()
{
    switch(ping_state)
    {
        case PInit:
            ping_state = pingCheck;
            break;
        case pingCheck:
            motionAmplitude = ~PINA & 0xF8; // (A7 - A3)
            motionDirection = ~PINA & 0x03; // (A2 - A0)
            if (motionAmplitude > 0 ) {
                ping_state = pingOn;
            }
            else {
                ping_state = pingOff;
            }
            break;
        case pingOff:
            ping_state = pingCheck;
            break;
        case pingOn:
            ping_state = pingCheck;
            break;
        default:
            ping_state = PInit;
            break;
    }
    switch(ping_state)
    {
        case PInit:
            break;
        case pingCheck:
            pingVal = 0x00;
            break;
        case pingOff:
            pingVal = 0x00;
            break;
        case pingOn:
            pingVal = 0x01;
            break;
        default:
            break;
    }
}
