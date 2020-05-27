//define local variable(s) here.  Use static keyword to keep local, e.g:
//   static int i;  // defines a local int named i

motionAmplitude = ~PINA & 0xF8; // (A7 - A3)
static unsigned char pingVal = 0x00;

/*complete the state machine*/

void Ping()
{
    switch(ping_state)
    {
        case PInit:
            ping_state = pingCheck;
            break;
        case pingCheck:
            if (motionAmplitude == 0) {
                ping_state = pingOff;
            }
            else {
                ping_state = pingOn;
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
            PORTB = PORTB | pingVal;
            break;
        case pingOff:
            pingVal = 0x00;
            PORTB = PORTB | pingVal;
            break;
        case pingOn:
            pingVal = 0x01;
            PORTB = PORTB | pingVal;
            break;
        default:
            break;
    }
}
