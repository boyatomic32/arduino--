#ifndef ARDUINO_MINUS_MINUS_TIMER16_H
#define ARDUINO_MINUS_MINUS_TIMER16_H

#ifdef ARDUINO_MINUS_MINUS_TIMER32_H
#error "Only one timer resolution can be used"
#endif

/* 
 * Implementation of the timer ISR for 16 bits resolution 
 */
ISR(TIMER0_OVF_vect)
    {
    Arduino16::timer0_overflow_count++;
    // timer 0 prescale factor is 64 and the timer overflows at 256
    Arduino16::timer0_clock_cycles += 64UL * 256UL;
    while (Arduino16::timer0_clock_cycles > F_CPU / 1000L)
        {
        Arduino16::timer0_clock_cycles -=  F_CPU / 1000L;
        Arduino16::timer0_millis++;
        }
    }

#endif
