#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "onewire_library.pio.h"

typedef struct {
    PIO pio;
    uint sm;
    uint jmp_reset;
    int offset;
    int gpio;
} OW;

bool ow_init(OW *ow, PIO pio, uint offset, uint gpio);
void ow_send(OW *ow, uint data);
uint8_t ow_read(OW *ow);
bool ow_reset(OW *ow);
int ow_romsearch(OW *ow, uint64_t *romcodes, int maxdevs, uint command);