/*
 * Test banale per DMX
 *
 * Utilizza la libreria DmxSimple https://github.com/PaulStoffregen/DmxSimple
 *
 *
 */

#include <DmxSimple.h>

#define N_CHAN 8
#define DMX_PIN 9

#define LED1_CHAN 6
#define LED2_CHAN 8

unsigned long sequenceTime;

unsigned long nextDeadline = 0;
unsigned long curSeqTime;
unsigned long nextSeqTime;


void setup() {
        Serial.begin(115200);

        while (!Serial) {
                ;
        }

        DmxSimple.usePin(DMX_PIN);

        /* DMX devices typically need to receive a complete set of channels
         ** even if you only need to adjust the first channel. You can
         ** easily change the number of channels sent here. If you don't
         ** do this, DmxSimple will set the maximum channel number to the
         ** highest channel you DmxSimple.write() to. */
        DmxSimple.maxChannel(N_CHAN + 1);
}

void loop() {
        int brightness;

        for (brightness = 0; brightness <= 255; brightness+=5) {
                DmxSimple.write(LED1_CHAN, brightness);
                DmxSimple.write(LED2_CHAN, 255-brightness);

                delay(10);
        }

        for (brightness = 0; brightness <= 255; brightness+=5) {
                DmxSimple.write(LED1_CHAN, 255-brightness);
                DmxSimple.write(LED2_CHAN, brightness);

                delay(10);
        }
}

